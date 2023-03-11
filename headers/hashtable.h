#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <exception>

class StockData
{
public:
    std::string date;
    double high;
    double low;
    double close;
    double adj;
    double volume;
    double adj_close;

    StockData();
    StockData(std::string &date, double high, double low, double close, double adj, double volume, double adj_close)
        : date(date), high(high), low(low), close(close), adj(adj), volume(volume), adj_close(adj_close){};
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
    std::string key;
    std::string name;
    std::string wkn;
    std::vector<StockData *> data;

    HashItem();
    HashItem(std::string key, std::string name, std::string wkn) : key(key), name(name), wkn(wkn){};
};

class Hashtable
{
private:
    std::vector<HashItem *> table;
    int size;
    int probeIndex = 1;
    int elementCount = 0;
    int hashString(const std::string &key) const;
    void resetProbeIndex();
    int probe(const std::string &key, int index);
    // struct hash_item *createHashItem(std::string *key, std::string *value);

public:
    Hashtable(int tableSize);
    ~Hashtable();
    void add(const std::string &key, const std::string &name, const std::string &wkn);
    HashItem *get(std::string &key);
    void remove(const char &key);
    void saveToFile(const std::string &path);
    void loadFromFile(std::string &path);
    void addCourseData(std::string &key, StockData &data);
    StockData *createStockData(std::string &date, double high, double low, double close, double adj, double volume, double adj_close);
    // TODO
    HashItem *getIndexFromKey(std::string &key);
    HashItem *find(const std::string &key);
    bool foundKey(const std::string &key, int index);
    bool isEmpty(int index);
    bool quit();
};

class KeyNotFound : public std::exception
{
    std::string _msg;

public:
    KeyNotFound(const std::string &key) : _msg("[ WARNING ] KEY '" + key + "' NOT FOUND"){};

    virtual const char *what() const noexcept override
    {
        return _msg.c_str();
    }
};

#endif