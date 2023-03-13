#include "plotter.h"

Plotter::Plotter(int height, int width, int offsetX, int offsetY)
    : height(height), width(width), offsetX(offsetX), offsetY(offsetY){};

void Plotter::printAt(int x, int y, const std::string &s)
{
    LOCATE(y, x);
    std::cout << s;
};

void Plotter::printAt(int x, int y, const char &s)
{
    LOCATE(y, x);
    std::cout << s;
};

int Plotter::map(double input, double min_0, double max_0, double min_1, double max_1)
{
    return floor((input - min_0) * (max_1 - min_1) / (max_0 - min_0) + min_1);
};

void Plotter::printPoint(int _x, int _y)
{
    int x = _x + offsetX;
    int y = (height + offsetY) - this->map(_y, minInputY, maxInputY, 0, height);
    this->printAt(x, y, '+');
};

void Plotter::setMaxInputY(double yMax)
{
    this->maxInputYWasSet = true;
    this->maxInputY = yMax;
};

void Plotter::setMinInputY(double yMin)
{
    this->minInputYWasSet = true;
    this->minInputY = yMin;
};

void Plotter::printGrid()
{
    if (!minInputYWasSet || !maxInputYWasSet)
        throw std::invalid_argument("At Plotter: maxInputY or minInputY values not set!");
    // print Y-Axis
    for (int y = 0; y < height; y++)
    {
        this->printAt(offsetX, y + offsetY, "|");
    }
    // print X-Axis
    this->printAt(offsetX, height + offsetY, "└ ");
    for (int x = 0; x < width; x++)
    {
        this->printAt(x + offsetX + 1, offsetY + height, "————————————");
    }
    // this->printAt(0, offsetY + 10, ' ');
    std::cout << "\n";
};

void Plotter::clear()
{
    CLS;
};