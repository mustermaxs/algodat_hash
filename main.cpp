#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>

#include "csvparser.h"
#include "hashtable.h"
// #include "utils.h"

int main()
{
    CSVParser *p = new CSVParser();
    // p.parseFile("stocks.csv");
    Hashtable h(1000);
    h.useParser(p);
    h.import("stocks.csv");
    return 0;
};