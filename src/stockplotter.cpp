#include "stockplotter.h"

StockPlotter::StockPlotter(int height, int width, int offsetX, int offsetY)
    : Plotter(height, width, offsetX, offsetY){};

void StockPlotter::plotStockCourse(const HashItem &item)
{
    this->printGrid();
    int vecSize = item.data.size();
    int counter = 0;
    for (int i = vecSize - 30; i < vecSize; i++)
    {
        this->printPoint(counter, item.data[i]->close);
        counter++;
    }
};