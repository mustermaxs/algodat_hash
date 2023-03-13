#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <exception>
#include "csvparser.h"

// class Parser;

class StockData
{
public:
    std::string date;
    double open;
    double high;
    double low;
    double close;
    double volume;
    double adj_close;

    StockData();
    StockData(const std::string &date, double open, double high, double low, double close, double adj_close, double volume);
};

// struct course_data
// {
//     std::string date;
//     double high;
//     double low;
//     double close;
//     double adj;
//     double volume;
//     double adj_close;
// } typedef course_data;

class HashItem
{
public:
    std::string abbr;
    std::string name;
    std::string wkn;
    std::vector<StockData *> data;

    HashItem();
    HashItem(std::string abbr, std::string name, std::string wkn) : abbr(abbr), name(name), wkn(wkn){};
};

class Hashtable
{
private:
    std::vector<HashItem *> table;
    int size;
    int probeIndex = 1;
    int elementCount = 0;
    int hashString(const std::string &abbr) const;
    void resetProbeIndex();
    int probe(const std::string &abbr, int index);
    // struct hash_item *createHashItem(std::string *abbr, std::string *value);

public:
    Parser *parser;
    void useParser(Parser *parser);
    // int calcOptimalTableSize(int nrOfEntries);
    Hashtable(int nbrOfEntries);
    ~Hashtable();
    void add(const std::string &abbr, const std::string &name, const std::string &wkn);
    HashItem *get(std::string &abbr);
    void remove(const char &abbr);
    void saveToFile(const std::string &path);
    void loadFromFile(std::string &path);
    void addCourseData(std::string &abbr, StockData &data);
    StockData *createStockData(std::string &date, double high, double low, double close, double adj, double volume, double adj_close);
    // TODO
    HashItem *getIndexFromKey(std::string &abbr);
    HashItem *find(const std::string &abbr);
    bool foundKey(const std::string &abbr, int index);
    bool isEmpty(int index);
    void import(std::string &abbr, const std::string &path);
    bool quit();
};

class KeyNotFound : public std::exception
{
    std::string _msg;

public:
    KeyNotFound(const std::string &abbr) : _msg("[ WARNING ] KEY '" + abbr + "' NOT FOUND"){};

    virtual const char *what() const noexcept override
    {
        return _msg.c_str();
    }
};

#endif