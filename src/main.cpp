#include "Parser.h"


int main() {
    Parser parser;
    parser.parse(Parser::DEFAULT_PATH);
    cout << parser.url_counter << " " << parser.url_counter / parser.total_number_of_html << endl;
    cout << parser.site_name_counter << " " << parser.site_name_counter / parser.total_number_of_html << endl;
    cout << parser.published_time_counter << " " << parser.published_time_counter / parser.total_number_of_html << endl;
    cout << parser.title_counter << " " << parser.title_counter / parser.total_number_of_html << endl;
    cout << parser.description_counter << " " << parser.description_counter / parser.total_number_of_html << endl;
    cout << parser.errors_counter << endl;
    return 0;
}