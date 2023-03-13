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
#include "plotter.h"

int main()
{
    Plotter plotter(40, 160, 1, 2);
    plotter.setMinInputY(-1000);
    plotter.setMaxInputY(1000);
    // char userInput = ' ';
    // CSVParser *csvParser = new CSVParser();
    // Hashtable table(1000);
    // table.useParser(csvParser);

    // std::string stockAbbr;
    // std::string stockName;
    // std::string wkn;
    // HashItem *max = new HashItem("m", "max", "123");
    // HashItem markus("markus", "roesner", "234");
    // std::cout << markus;
    // std::cout << *max;
    // plotter.clear();
    // plotter.printAt(2, 2, "°");
    // plotter.printAt(1, 1, "°");
    // plotter.printAt(3, 3, "°");
    // plotter.printAt(2, 4, "°");
    plotter.printGrid();
    const double pi = 3.14159;
    int angle = 0;

    for (int i = 0; i < 160; i++)
    {
        int a = (1000 * std::sin(angle * 3.141 / 180));
        // int y = plotter.map(a, 0, 838, -40, 40);
        plotter.printPoint(i, a);
        // std::cout << a << "\n";
        angle += 3;
    }

    // std::cout << plotter.map(0, 0, 100, 0, 10) << std::endl;
    // std::cout << plotter.map(25, 0, 100, 0, 10) << std::endl;
    // std::cout << plotter.map(50, 0, 100, 0, 10) << std::endl;
    // std::cout << plotter.map(75, 0, 100, 0, 10) << std::endl;
    // std::cout << plotter.map(100, 0, 100, 0, 10) << std::endl;
    std::getchar();
    // plotter.printPoint(0, );
    // std::cout << "±";

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
