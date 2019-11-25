#include "Parser.h"

Parser::Parser() : ofs(CSV_PATH, ios::binary) {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    create_empty_csv();
}

void Parser::create_empty_csv() {
    ofs << "id,url,site_name,published_date,irr_letters,total_letters,title,description,content,\n";
}

void Parser::to_csv(const Parser::Page &page) {

    ofs << page.id << "," << page.url << "," <<
        page.site_name << "," << page.published_date << "," << page.irrelevant_symbols << "," << page.total_symbols << "," <<
        page.title << "," << process(page.description) << "," << page.content << "\n";
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
            if (!(page.site_name = get_meta(file, "<meta property=\"og:site_name\" content=\"(.*)\"/>")).empty()) {
                site_name_counter++;
            }
            if (!(page.published_date = get_meta(file,
                                                 "<meta property=\"article:published_time\" content=\"(.*)\"/>")).empty()) {
                published_time_counter++;
            }
            if (!(page.title = get_meta(file, "<meta property=\"og:title\" content=\"(.*)\"/>")).empty()) {
                title_counter++;
            }
            if (!(page.description = get_meta(file, "<meta property=\"og:description\" content=\"(.*)\"/>")).empty()) {
                description_counter++;
            }
            page.content = get_body_text(file);
            page.irrelevant_symbols = buf_irrelevant_symbols;
            page.total_symbols = buf_total_symbols;
            to_csv(page);
        }
    }
}

string Parser::get_body_text(const string &file) { // TODO: remove parts of DATETIME in article (many "nov" in content in .csv)
    int body_tag_start_index = file.find("<body>");
    int body_tag_end_index = file.find("</body>");
    string body(file.begin() + body_tag_start_index + 6, file.begin() + body_tag_end_index);
    return process(body);
}

string Parser::process(const string &content) { // TODO: words are assembling or repeating sometimes, check generated .csv
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
            if (symbol == '>') inside_of_tag = false;
            ++i;
            continue;
        }
        if (symbol == '<') {
            inside_of_tag = true;
            ++i;
            continue;
        }
        if (symbol == ' ' || symbol == '\t' || symbol == '\r' || symbol == '\n') {
            if (space_added) {
                ++i;
                continue;
            }
            result.emplace_back(' ');
            space_added = true;
            ++i;
            continue;
        }
        std::bitset<11> cur_byte(symbol);
        unsigned long code;
        if (u_buf[7] == 1 && u_buf[6] == 1 && u_buf[5] == 0) {
            std::bitset<11> b = (u_buf & std::bitset<11>(31)) << 6;
            if (cur_byte[7] != 1 || cur_byte[6] != 0) throw std::runtime_error("wrong unicode");
            b |= (cur_byte & std::bitset<11>(63));
            u_buf = 0;
            code = b.to_ulong();
        } else if (cur_byte[7] == 0) {
            u_buf = 0;
            code = cur_byte.to_ulong();
        } else if (cur_byte[7] == 1 && cur_byte[6] == 1 && cur_byte[5] == 0) {
            u_buf = cur_byte;
            i++;
            continue;
        } else if (cur_byte[7] == 1 && cur_byte[6] == 1 && cur_byte[5] == 1 && cur_byte[4] == 0) {
            i += 3;
            ++buf_irrelevant_symbols;
            ++buf_total_symbols;
            continue;
        } else if (cur_byte[7] == 1 && cur_byte[6] == 1 && cur_byte[5] == 1 && cur_byte[4] == 1 && cur_byte[3] == 0) {
            i += 4;
            ++buf_irrelevant_symbols;
            ++buf_total_symbols;
            continue;
        } else throw std::runtime_error("wrong unicode");
        if (isLetter(code)) {
            result.emplace_back(char(to_lower(code)));
            space_added = false;
        }
        else ++buf_irrelevant_symbols;
        ++buf_total_symbols;
        ++i;
    }
    return string(result.begin(), result.end());
}

char Parser::to_lower(unsigned long code) {
    if (code < 128) {
        return (char) (code | (unsigned long) 32);
    } else if (1040 <= code && code <= 1071) return code - 1040 + 224;
    else if (1072 <= code && code <= 1103) return code - 1072 + 224;
    else if (code == 1025 || code == 1105) return 184;
    else throw std::invalid_argument("non-letter passed to to_lower");
}

bool Parser::isLetter(unsigned long code) {
    if (65 <= code && code <= 90) return true;
    if (97 <= code && code <= 122) return true;
    if (1040 <= code && code <= 1103) return true;
    return (code == 1025 || code == 1105);
}
