#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <math.h>

#include "csvparser.h"
#include "hashtable.h"
#include "utils.h"
#include "stockplotter.h"

int main()
{
    StockPlotter plotter(30, 40, 1, 1);
    plotter.setMaxInputY(320);
    plotter.setMinInputY(214);
    Hashtable table(1000);
    CSVParser *parser = new CSVParser();
    table.useParser(parser);
    table.add("apl", "Apple", "123");
    table.import("apl", "stocks.csv");
    HashItem *item = table.find("apl");
    plotter.plotStockCourse(*item);
    // table.save();
    // std::cout << item->data[0]->date;

    // plotter.printGrid();
    // int vecSize = item->data.size();
    // int counter = 0;
    // for (int i = vecSize - 30; i < vecSize; i++)
    // {
    //     plotter.printPoint(counter, item->data[i]->close);
    //     counter++;
    // }

    /**
     * MENU TEST
     *
     */

    // char userInput = ' ';
    // std::string stockAbbr;
    // std::string stockName;
    // std::string wkn;
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
    //         std::cout << "\nPlot course data? (y/n): ";
    //         std::cin >> userInput;
    //         if (userInput == 'y')
    //         default:
    //             break;
    //     }
    // }

    return 0;
};

// for (int i = 0; i < 160; i++)
// {
//     int a = (1000 * std::sin(angle * 3.141 / 180));
//     // int y = plotter.map(a, 0, 838, -40, 40);
//     plotter.printPoint(i, a);
//     // std::cout << a << "\n";
//     angle += 3;
// }