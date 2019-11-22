#ifndef TELEGRAM_ARTICLE_PARSER_H
#define TELEGRAM_ARTICLE_PARSER_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <string>
#include <utility>
#include <cassert>

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

    inline static const string DEFAULT_PATH = R"(/Users/konstantin.rybkin/projects/tg-contest-data)";
    inline static const string CSV_PATH = "../pages.csv";

    Parser();

    string readFile(const string& path);

    string get_meta(const string &file, const string &pattern);

    string get_body_text(const string& file);

    static void to_lower(string& s);

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
    };

    void create_empty_csv();
    void to_csv(const Page& page);

private:
    string base_path;
    ofstream ofs;
};


#endif //TELEGRAM_ARTICLE_PARSER_H
