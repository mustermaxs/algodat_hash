#include "csvparser.h"

Parser::~Parser(){};

CSVParser::CSVParser(){};
CSVParser::~CSVParser(){};

void CSVParser::parseFile(std::string filePath)
{
    this->reset();

    std::string line, cell;

    std::ifstream file;
    file.open(filePath);

    if (!file.is_open())
        std::cerr << "\nDatei konnte nicht geöffnet werden!" << std::endl;

    while (file >> line)
    {
        std::stringstream tempLine(line);

        while (std::getline(tempLine, cell, ','))
            this->parsedData.push_back(cell);
    }

    if (!file.eof())
        std::cerr << "Fehler beim Lesen!";

    file.close();
};

std::vector<std::string> CSVParser::parseString(std::string s)
{
    std::vector<std::string> parsedString;

    std::string cell;

    std::stringstream tempLine(s);

    while (std::getline(tempLine, cell, ','))
        parsedString.push_back(cell);

    return parsedString;
};

std::vector<std::string> CSVParser::getParsedData()
{
    return this->parsedData;
};

void CSVParser::print()
{
    int vecSize = parsedData.size();

    for (int index = 0; index < vecSize; index++)
        std::cout << parsedData[index] << "\n";
};

void CSVParser::reset()
{
    fileContent = "";
};

// bool CSVParser::read(std::string &path)
// {
//     this->reset();
//     std::string line;

//     std::ifstream file;
//     file.open(path);

//     if (!file.is_open())
//     {
//         std::cerr << "\nDatei konnte nicht geöffnet werden!" << std::endl;
//         return false;
//     }

//     while (std::getline(file, line))
//         fileContent += line;

//     file.close();

//     return true;
// }