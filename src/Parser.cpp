#include "Parser.h"

Parser::Parser() : ofs(CSV_PATH, ios::binary) {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    create_empty_csv();
}

void Parser::create_empty_csv() {
    ofs << "id,url,site_name,published_date,title,description,content\n";
}

void Parser::to_csv(const Parser::Page &page) {
    ofs << page.id << "," << page.url << "," <<
        page.site_name << "," << page.published_date << "," <<
        page.title << "," << page.description << "," << page.content << "\n";
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
    for (auto &itEntry : fs::directory_iterator(path)) {
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
            to_csv(page);
        } else if (itEntry.is_directory()) {
            parse(itEntry.path());
        }
    }
}

string Parser::get_body_text(const string &file) {
    regex tag_pattern = regex(R"((<.+?>)|(</.+?>))");
    wregex alphabet_pattern = wregex(
            L"([^a-zA-Z0-9(йцукенгшщзхъфывапролджэёячсмитьбюЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЁЯЧСМИТЬБЮ')])");
    regex whitespace_pattern = regex("(\\s\\s+)");

    typedef std::codecvt_utf8<wchar_t> convert_type;
    std::wstring_convert<convert_type, wchar_t> converter;
    int body_tag_start_index = file.find("<body>");
    int body_tag_end_index = file.find("</body>");
    string content(file.begin() + body_tag_start_index + 6, file.begin() + body_tag_end_index);
    string text = regex_replace(content, tag_pattern, "");
    std::wstring alphabet_text = regex_replace(converter.from_bytes(text), alphabet_pattern,
                                               converter.from_bytes(" "));
    text = regex_replace(converter.to_bytes(alphabet_text), whitespace_pattern, " ");
    to_lower(text);
    return text;
}

void Parser::to_lower(string &s) {
    for (auto &c: s) {
        c = tolower(c);
    }
}
