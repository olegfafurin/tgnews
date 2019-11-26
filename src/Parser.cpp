#include <numeric>
#include "Parser.h"
#include "stat.h"

Parser::Parser() : ofs(CSV_PATH, ios::binary) {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    create_empty_csv();
}

template<typename T>
string Parser::join(const T &v, const string &delim) {
    std::ostringstream s;
    for (const auto &i : v) {
        if (&i != &v[0]) {
            s << delim;
        }
        s << i;
    }
    return s.str();
}

void Parser::create_empty_csv() {
    ofs << join(std::vector<string>({"id", "url", "site_name", "published_date",
                                     "irr_letters", "total_letters","irr_words", "total_words", "lang", "title", "description", "content"}), DELIMITER) +
           "\n";
}

void Parser::to_csv(const Parser::Page &page) {
    ofs << join(std::vector<string>({std::to_string(page.id), page.url, page.site_name, page.published_date,
                                     std::to_string(page.irrelevant_symbols), std::to_string(page.total_symbols), std::to_string(page.irrelevant_words), std::to_string(page.total_words),
                                     page.language == 0 ? "en" : page.language == 1 ? "ru" : "undefined", page.title, page.description, page.content}), DELIMITER) + "\n";
}

string Parser::readFile(const string &path) {
    string result;
    ifstream ifs(path.c_str(), ios::binary);
    stringstream ss;
    if (!ifs.is_open()) {
        // Unable to read file
        result.clear();
        ifs.close();
        return result;
    } else if (ifs.eof()) {
        result.clear();
    }
    ss << ifs.rdbuf() << '\0';
    result = ss.str();
    ifs.close();
    return result;
}

string Parser::get_meta(const string &file, const string &pattern) {
    smatch sm;
    if (regex_search(file, sm, regex(pattern))) {
        return sm[1].str();
    }
    return "";
}

int parse_counter = 0;

void Parser::parse(const string &path) {
    string file;
    vector<Page> pages_rus;
    vector<Page> pages_en;
    for (auto &itEntry : fs::recursive_directory_iterator(path)) {
        if (itEntry.is_regular_file()) {
            if (itEntry.path().string().find("html") == string::npos) continue;
            cout << ++parse_counter << " " << itEntry.path() << endl;
            file = readFile(itEntry.path().string());
            Page page;
            page.id = parse_counter;
            if (!(page.url = get_meta(file, "<meta property=\"og:url\" content=\"(http.*)\"/>")).empty()) {
                url_counter++;
            }
            if (!(page.site_name = process(
                    get_meta(file, "<meta property=\"og:site_name\" content=\"(.*)\"/>"))).empty()) {
                site_name_counter++;
            }
            if (!(page.published_date = process(get_meta(file,
                                                         "<meta property=\"article:published_time\" content=\"(.*)\"/>"))).empty()) {
                published_time_counter++;
            }
            if (!(page.title = process(get_meta(file, "<meta property=\"og:title\" content=\"(.*)\"/>"))).empty()) {
                title_counter++;
            }
            if (!(page.description = process(
                    get_meta(file, "<meta property=\"og:description\" content=\"(.*)\"/>"))).empty()) {
                description_counter++;
            }
            page.content = get_body_text(file);
            page.irrelevant_symbols = buf_irrelevant_symbols;
            page.total_symbols = buf_total_symbols;
            page.language = detect_language(page);
            to_csv(page);

        }
    }
}

int Parser::detect_language(Page &p) { // returns 0 for english, 1 for russian, -1 for others
    int letters = 0, english_letters = 0, russian_letters = 0;
    for (char &v : p.content) {
        if (is_english_letter(v)) {
            ++english_letters;
            ++letters;
        } else if (is_russian_letter(v)) {
            ++russian_letters;
            ++letters;
        }
    }
    double share_cyr_letters = (double) russian_letters / letters;
    double share_eng_letters = (double) english_letters / letters;
    int words_broken = 0;
    int words = 0;
    bool broken = false;
    for (char &v : p.content) {
        if (v == '_') {
            broken = true;
        } else if (v == ' ') {
            if (broken) ++words_broken;
            ++words;
            broken = false;
        }

    }
    p.irrelevant_words = words_broken;
    p.total_words = words;
    if ((double) words_broken / words > IRR_WORD_RELATIVE_THRESHOLD && words >= IRR_WORD_ABSOLUTE_THRESHOLD) return -1;

    const std::map<std::string, int> *right_stat;
    if (english_letters > russian_letters) {
        std::map<string, int> observed_stat({});
        for (const auto& entry: BISTAT_ENG)  observed_stat[entry.first] = 0;
        right_stat = &BISTAT_ENG;
        for (int i = 0; i < p.content.size() - 1; ++i) {
            string bi = p.content.substr(i, 2);
            if (observed_stat.find(bi) != observed_stat.end()) observed_stat[bi] += 1;
            else if (bi[0] == '_' || bi[1] == '_') observed_stat["__"] += 1;
        }
        long lhs_sum = std::accumulate(std::begin(*right_stat), std::end(*right_stat), 0, [](const std::size_t previous, const auto& element){ return previous + element.second; });
        long rhs_sum = std::accumulate(std::begin(observed_stat), std::end(observed_stat), 0, [](const std::size_t previous, const auto& element){ return previous + element.second; });
        double chi_squared = 0.0;
        for (const auto& entry : *right_stat) {
            string key = entry.first;
            chi_squared += ((double) observed_stat[key] / rhs_sum - (double) (*right_stat).at(key) / lhs_sum) * ((double) observed_stat[key] / rhs_sum - (double) (*right_stat).at(key) / lhs_sum) / ((double) (*right_stat).at(key) / lhs_sum);
        }
        if (chi_squared < CHI_ENGLISH_THRESHOLD) return 0;
        else return -1;
    }
    else {
        std::map<std::pair<int,int>, int> observed_stat({});
        for (const auto& entry: BISTAT_RUS)  observed_stat[entry.first] = 0;
        for (int i = 0; i < p.content.size() - 1; ++i) {
            unsigned char f_letter = p.content[i];
            unsigned char s_letter = p.content[i + 1];
            auto bi = std::pair{f_letter, s_letter};
            if (observed_stat.find(bi) != observed_stat.end()) observed_stat[bi] += 1;
            else if (bi.first == 95 || bi.second == 95) observed_stat[{95,95}] += 1;
        }
        long lhs_sum = std::accumulate(std::begin(BISTAT_RUS), std::end(BISTAT_RUS), 0, [](const std::size_t previous, const auto& element){ return previous + element.second; });
        long rhs_sum = std::accumulate(std::begin(observed_stat), std::end(observed_stat), 0, [](const std::size_t previous, const auto& element){ return previous + element.second; });
        double chi_squared = 0.0;
        for (const auto& entry : BISTAT_RUS) {
            auto key = entry.first;
            chi_squared += ((double) observed_stat[key] / rhs_sum - (double) (BISTAT_RUS).at(key) / lhs_sum) * ((double) observed_stat[key] / rhs_sum - (double) (BISTAT_RUS).at(key) / lhs_sum) / ((double) (BISTAT_RUS).at(key) / lhs_sum);
        }
        if (chi_squared < CHI_RUSSIAN_THRESHOLD) return 1;
        else return -1;
    }
}


string Parser::get_body_text(const string &file) {
    int body_tag_start_index = file.find("<body>");
    int body_tag_end_index = file.find("</body>");
    string body(file.begin() + body_tag_start_index + 6, file.begin() + body_tag_end_index);
    return process(body);
}

string Parser::process(string content) {
    buf_irrelevant_symbols = 0;
    buf_total_symbols = 0;
    std::vector<char> result;
    bool space_added = true;
    bool inside_of_tag = false;
    std::bitset<11> u_buf = 0;
    int i = 0;
    while (i < content.size()) {
        unsigned char symbol = content[i];
        if (inside_of_tag) {
            if (symbol == '>') {
                inside_of_tag = false;
                if (!space_added) {
                    result.emplace_back(' ');
                    space_added = true;
                }
            }
            ++i;
            continue;
        }
        if (symbol == '<') {
            inside_of_tag = true;
            ++i;
            continue;
        }
        if (symbol == ' ' || symbol == '\t' || symbol == '\r' || symbol == '\n') {
            if (!space_added) {
                result.emplace_back(' ');
                space_added = true;
            }
            ++i;
            continue;
        }
        std::bitset<11> cur_byte(symbol);
        unsigned long code;
        if (cur_byte[7] == 0) {
            u_buf = 0;
            code = cur_byte.to_ulong();
        } else if (u_buf[7] == 1 && u_buf[6] == 1 && u_buf[5] == 0) {
            std::bitset<11> b = (u_buf & std::bitset<11>(31)) << 6;
            if (cur_byte[7] != 1 || cur_byte[6] != 0) throw std::runtime_error("wrong unicode");
            b |= (cur_byte & std::bitset<11>(63));
            u_buf = 0;
            code = b.to_ulong();
        } else if (cur_byte[7] == 1 && cur_byte[6] == 1 && cur_byte[5] == 0) {
            u_buf = cur_byte;
            i++;
            continue;
        } else if (cur_byte[7] == 1 && cur_byte[6] == 1 && cur_byte[5] == 1 && cur_byte[4] == 0) {
            ++buf_irrelevant_symbols;
            ++buf_total_symbols;
            if (!space_added) {
                result.emplace_back(' ');
                space_added = true;
            }
            i += 3;
            continue;
        } else if (cur_byte[7] == 1 && cur_byte[6] == 1 && cur_byte[5] == 1 && cur_byte[4] == 1 && cur_byte[3] == 0) {
            ++buf_irrelevant_symbols;
            ++buf_total_symbols;
            if (!space_added) {
                result.emplace_back(' ');
                space_added = true;
            }
            i += 4;
            continue;
        } else throw std::runtime_error("wrong unicode");
        if (isAlphaNum(code)) {
            result.emplace_back(char(to_lower(code)));
            space_added = false;
        } else if (isPunct(code)) {
            if (!space_added) {
                result.emplace_back(' ');
                space_added = true;
            }
        } else {
            result.emplace_back('_');
            space_added = false;
            ++buf_irrelevant_symbols;
        }
        ++buf_total_symbols;
        ++i;
    }
    return string(result.begin(), result.end());
}

char Parser::to_lower(unsigned long code) {
    if (48 <= code && code <= 57) return code;
    if (code < 128) return (char) (code | (unsigned long) 32);
    else if (1040 <= code && code <= 1071) return code - 1040 + 224;
    else if (1072 <= code && code <= 1103) return code - 1072 + 224;
    else if (code == 1025 || code == 1105) return 184;
    else throw std::invalid_argument("non-letter passed to to_lower");
}

bool Parser::isAlphaNum(unsigned long code) {
    if (48 <= code && code <= 57) return true;
    if (65 <= code && code <= 90) return true;
    if (97 <= code && code <= 122) return true;
    if (1040 <= code && code <= 1103) return true;
    return (code == 1025 || code == 1105);
}

bool Parser::isPunct(unsigned long code) {
    if (code >= 32 && code <= 47) return true;
    if (code >= 58 && code <= 64) return true;
    if (code >= 91 && code <= 96) return true;
    if (code >= 122 && code <= 126) return true;
    return (code >= 160 && code <= 191) || code == 215 || code == 247;
}

bool Parser::is_russian_letter(char &c) {
    unsigned char cu = c;
    return (cu > 191 || cu == 168 || cu == 184);
}

bool Parser::is_english_letter(char &c) {
    unsigned char cu(c);
    cu |= (unsigned char) 32;
    return (97 <= cu && cu <= 122);
}

