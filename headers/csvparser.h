#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>

class Parser
{
private:
    std::string fileContent;
    std::vector<std::string> parsedData;

public:
    virtual ~Parser() = 0;
    virtual void parseFile(std::string path) = 0;
    virtual std::vector<std::string> parseString(std::string s) = 0;
    virtual void print() = 0;
    virtual std::vector<std::string> getParsedData() = 0;

    // virtual bool read(std::string &path) = 0;
};

class CSVParser : public Parser
{
private:
    std::vector<std::string> parsedData;
    std::string fileContent;
    std::string filePath;
    void reset();

public:
    CSVParser();
    ~CSVParser() override;
    void parseFile(std::string path) override;
    std::vector<std::string> parseString(std::string s);
    void print() override;
    std::vector<std::string> getParsedData();
    // bool read(std::string &path);
    // void readFromFile(std::string filePath);
};

#endif