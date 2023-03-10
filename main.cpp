/**
 * ???
 * ADD: Aktie mit Namen, WKN und Kürzel
 *      was davon ist Key?
 *      Array von Keys?
 *
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>

#include "csvparser.h"
#include "hashtable.h"

int main()
{
    Hashtable h(1000);
    h.add("test");
    // Parser *parser = new CSVParser();
    // parser->parseFile("./test.csv");
    // std::vector<std::string> ps = parser->getParsedData();

    return 0;
};