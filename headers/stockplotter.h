#ifndef STOCKPLOTTER_H
#define STOCKPLOTTER_H

#include "plotter.h"
#include "hashtable.h"

class StockPlotter : public Plotter
{
public:
    StockPlotter(int height, int width, int offsetX, int offsetY);
    void plotStockCourse(const HashItem &item);
};

#endif