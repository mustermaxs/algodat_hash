#ifndef PLOTTER_H
#define PLOTTER_H

#include <iostream>
#include <math.h>

class Plotter
{
protected:
    int offsetX;
    int offsetY;
    int height;
    int width;
    int maxInputY;
    int minInputY;
    bool maxInputYWasSet = false;
    bool minInputYWasSet = false;
#define LOCATE(z, s) (std::cout << "\033[" << (z) << ';' << (s) << 'H')
#define CLS (std::cout << "\033[2J")

public:
    Plotter(int height, int width, int offsetX, int offsetY);
    void printGrid();
    void printAt(int x, int y, const std::string &s);
    void printAt(int x, int y, const char &s);
    void printPoint(int x, int y);
    void setMaxInputY(double yMax);
    void setMinInputY(double yMin);
    void setMinX(double xMin);
    void setMaxX(double xMax);
    int map(double input, double min_0, double max_0, double min_1, double max_1);
    void clear();
};

#endif