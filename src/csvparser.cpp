#include "csvparser.h"

Parser::~Parser(){};

CSVParser::CSVParser(){};
CSVParser::~CSVParser(){};

std::vector<std::vector<std::string>> CSVParser::parseFile(std::string filePath)
{
    this->clearParsedData();

    std::string line, cell;
    std::vector<std::string> content;

    std::ifstream file;
    file.open(filePath);

    if (!file.is_open())
        std::cerr << "\nDatei konnte nicht geöffnet werden!" << std::endl;

    // skip first line containing column names
    std::getline(file, line);

    while (file >> line)
    {
        content.clear();
        int lineCounter = 0;
        std::stringstream tempLine(line);
        // in nächsten vektor gehen?
        while (std::getline(tempLine, cell, ','))
            content.push_back(cell);
        this->parsedData.push_back(content);
    }

    if (!file.eof())
        std::cerr << "Fehler beim Lesen!";

    file.close();
    return this->parsedData;
};

void CSVParser::print()
{
    int vecSize = parsedData.size();

    for (int index = 0; index < vecSize; index++)
        for (int line = 0; line < parsedData[index].size(); line++)
        {
            std::cout << parsedData[index][line] << "\n";
        }
};

void Parser::clearParsedData()
{
    this->parsedData.clear();
};
