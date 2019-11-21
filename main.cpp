#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <string>

namespace fs = std::filesystem;
using namespace std;


regex url_regex;
regex source_regex;
regex title_regex;
regex line_regex;
regex word_regex("\\w+");


string readFile(string path)
{
    string result;
    ifstream ifs(path.c_str(), ios::binary);
    stringstream ss;
    if (!ifs.is_open()) {
        // Unable to read file
        result.clear();
        return result;
    }
    else if (ifs.eof()) {
        result.clear();
    }
    ss << ifs.rdbuf() << '\0';
    result = ss.str();
    return result;
}

string get_url(string &file) {
    smatch sm;
    if (regex_search(file, sm, url_regex)) {
        return sm[1].str();
    }
    return "";
}

string get_source(string &file) {
    smatch sm;
    if (regex_search(file, sm, source_regex)) {
        return sm[1].str();
    }
    return "";
}

string get_title(string &file) {
    smatch sm;
    if (regex_search(file, sm, title_regex)) {
        return sm[1].str();
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    string line;
    url_regex = regex("<meta property=\"og:url\" content=\"(http.*)\"/>");
    source_regex = ("<meta property=\"og:site_name\" content=\"(.*)\"/>");
    title_regex = regex("<meta property=\"og:url\" content=\"(http.*)\"/>");
    line_regex = regex("<p>(.*)</p>");
    string path = R"(H:\Docs\data\DataClusteringSample0817\20191111\00)"; // change
    for (auto &itEntry : fs::directory_iterator(path)) {
        if (itEntry.is_regular_file()) {
            ifstream fin(itEntry.path());
            smatch sm;
            line = readFile(itEntry.path().string());
            string temp;
            if (!(temp = get_url(line)).empty()) cout << temp << '\n';
            if (!(temp = get_source(line)).empty()) cout << temp << '\n';
            if (!(temp = get_title(line)).empty()) cout << temp << '\n';
            regex_search(line, sm, line_regex);
            for(auto &it : sm) {
                cout << it.str() << '\n';
            }
            cout << "_______\n";
        }
    }
}