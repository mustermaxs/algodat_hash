#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>

#include "csvparser.h"
#include "hashtable.h"
#include "utils.h"

int main()
{
    char userInput = ' ';
    CSVParser *csvParser = new CSVParser();
    Hashtable table(1000);
    table.useParser(csvParser);

    std::string stockAbbr;
    std::string stockName;
    std::string wkn;
    HashItem *max = new HashItem("m", "max", "123");
    HashItem markus("markus", "roesner", "234");
    std::cout << markus;
    std::cout << *max;

    return 0;

    // while (userInput != 'x')
    // {
    //     printFileContent("./manual.txt");
    //     std::cout << "\nAction: ";
    //     std::cin >> userInput;

    //     switch (userInput)
    //     {
    //     case 'a':

    //         std::cout << "\nStock abbreviation: ";
    //         std::cin >> stockAbbr;
    //         std::cout << "\nStock name: ";
    //         std::cin >> stockName;
    //         std::cout << "\nWKN: ";
    //         std::cin >> wkn;
    //         table.add(stockAbbr, stockName, wkn);
    //         break;
    //     case 's':
    //         std::cout << "\nFind by abbreviation: ";
    //         std::cin >> stockAbbr;
    //         item = table.find(stockAbbr);
    //         std::cout << *item;
    //         std::cout << "\nPrint course data? (y/n): ";
    //     default:
    //         break;
    //     }
    // }

    return 0;
};
