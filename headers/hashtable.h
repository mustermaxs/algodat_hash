#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>

/**
 * TODO
 * ? hash_item: pointer oder values?
 * list statt double pointer array verwenden?
 * hash_item:
 *      key: Name? WKN?
 *      values: Kursdaten (double/float Array?), oder struct array mit enum
 *      das kennzeichnet ob date, open, high, low, close, volume, ...?

 *      ---> ODER: nested Hashtables???!!! <--- => hashtable von hashtables?
 *
 */

struct course_data
{
    std::string date;
    double high;
    double low;
    double close;
    double adj;
    double volume;
    double adj_close;
} typedef course_data;

struct hash_item
{
    std::string key;
    std::string name;
    std::vector<course_data *> data;
} typedef hash_item;

class Hashtable
{
private:
    std::vector<hash_item *> table;
    int size;
    int probeIndex = 1;
    int elementCount = 0;
    int hashString(const std::string &key) const;
    void resetProbeIndex();
    int probe(std::string &key, int index);
    // struct hash_item *createHashItem(std::string *key, std::string *value);

public:
    Hashtable(int tableSize);
    ~Hashtable();
    void add(const std::string &key);
    hash_item *get(std::string &key);
    void remove(const char &key);
    void saveToFile(const std::string &path);
    void loadFromFile(std::string &path);
    void addCourseData(std::string &key, course_data &data);
    course_data *createCourseDataEl(std::string &date, double high, double low, double close, double adj, double volume, double adj_close);
    // TODO
    struct hash_item *getIndexFromKey(std::string &key);
    hash_item *get(const std::string &key);
    bool foundKey(std::string &key, int index);
    bool isEmpty(int index);
    bool quit();
};

#endif