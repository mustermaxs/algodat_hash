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
protected:
    std::vector<std::vector<std::string>> parsedData;
    void clearParsedData();

public:
    virtual ~Parser() = 0;
    virtual void parseFile(std::string path) = 0;
    virtual void print() = 0;
    virtual std::vector<std::vector<std::string>> getParsedData() = 0;
};

class CSVParser : public Parser
{
private:
public:
    CSVParser();
    ~CSVParser() override;
    void parseFile(std::string path) override;
    void print() override;
    std::vector<std::vector<std::string>> getParsedData() override;
};

#endif