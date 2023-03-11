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
    CSVParser p;
    p.parseFile("stocks.csv");
    Hashtable h(1000);
    h.add("markus", "roesner", "m");
    try
    {
        HashItem *m = h.find("markus");
        std::cout << m->name;
    }
    catch (const KeyNotFound &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
};