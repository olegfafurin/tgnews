#ifndef TELEGRAM_ARTICLE_PARSER_H
#define TELEGRAM_ARTICLE_PARSER_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <string>
#include <utility>
#include <cassert>
#include <vector>

using std::string;
using std::ios_base;
using std::cin;
using std::cout;
using std::endl;
using std::regex;
using std::wregex;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::stringstream;
using std::smatch;
using std::regex_replace;
using std::locale;

namespace fs = std::filesystem;

class Parser {
public:
    const double total_number_of_html = 467511;
    int url_counter = 0;
    int site_name_counter = 0;
    int published_time_counter = 0;
    int title_counter = 0;
    int description_counter = 0;
    int errors_counter = 0;

    inline static const string DEFAULT_PATH = R"(H:\Docs\data\DataClusteringSample0107\20191101)";
    inline static const string CSV_PATH = "pages.csv";

    Parser();

    string readFile(const string& path);

    string get_meta(const string &file, const string &pattern);

    string get_body_text(const string& file);

    static char to_lower(unsigned long code);

    string process(const string &body);

    static bool isLetter(unsigned long code);

    void parse(const string& path);

    class Page {
    public:
        int id;
        string url;
        string site_name;
        string published_date;
        string title;
        string description;
        string content;

        int irrelevant_symbols; // utf-8 symbols, non-space, non-latin, non-cyrillic in BODY, excluding tags
        int total_symbols; // total non-space symbols in BODY, excluding tags
    };

    void create_empty_csv();
    void to_csv(const Page& page);

private:
    string base_path;
    ofstream ofs;

    int buf_total_symbols;
    int buf_irrelevant_symbols;
};


#endif //TELEGRAM_ARTICLE_PARSER_H
