#include "hashtable.h"
#include "utils.h"

HashItem::HashItem()
{
    throw std::invalid_argument("[ WARNING ] HashItem must be instantiated with arguments!");
};

// std::ostream &operator<<(std::ostream &stream, const StockData &data)
// {
//     stream << "\nDate: " << data.date;
//     stream << "\nOpen: " << data.open;
//     stream << "\nHigh: " << data.high;
//     stream << "\nLow: " << data.low;
//     stream << "\nClose: " << data.close;
//     stream << "\nVolume: " << data.volume;
//     stream << "\nAdj. Close: " << data.adj_close << std::endl;
//     return stream;
// };

std::ostream &operator<<(std::ostream &stream, const StockData &data)
{
    stream << data.date << ",";
    stream << data.open << ",";
    stream << data.high << ",";
    stream << data.low << ",";
    stream << data.close << ",";
    stream << data.adj_close << ",";
    stream << data.volume << ",";
    return stream;
};

std::ostream &operator<<(std::ostream &stream, const HashItem &item)
{
    stream << item.abbr << ",";
    stream << item.name << ",";
    stream << item.wkn << ",";
    return stream;
};

// std::fstream &operator<<(std::fstream &stream, const HashItem &item)
// {
//     stream << item.abbr << ",";
//     stream << item.name << ",";
//     stream << item.wkn << ",";
//     return stream;
// };

Hashtable::Hashtable(int nbrOfEntries)
{
    this->size = getPrimeBiggerThan(nbrOfEntries * 1.3);
    this->table.resize(this->size, NULL);
    // std::cout << this->table.size();
};

void Hashtable::import(const std::string &abbr, const std::string &path)
{
    std::vector<std::vector<std::string>> parseData = this->parser->parseFile(path);

    for (const auto &row : parseData)
    {
        if (row.size() != 7)
        {
            std::cerr << "Invalid data in CSV file!" << std::endl;
            continue;
        }
        std::string date = row[0];
        double open = std::stod(row[1]);
        double high = std::stod(row[2]);
        double low = std::stod(row[3]);
        double close = std::stod(row[4]);
        double adj_close = std::stod(row[5]);
        double volume = std::stod(row[6]);

        StockData *data = new StockData(date, open, high, low, close, adj_close, volume);

        this->addCourseData(abbr, *data);
    }
};

void Hashtable::useParser(Parser *parser)
{
    this->parser = parser;
};

// int Hashtable::calcOptimalTableSize(int nrOfEntries){

// };
Hashtable::~Hashtable()
{
    for (int index = 0; index < this->size; index++)
    {
        if (table[index] != NULL)
        {
            delete this->table[index];
        }
    }
};

int Hashtable::hashString(const std::string &abbr) const
{
    int hashValue = 0;
    int keyLen = abbr.length();

    for (int index = 0; index < keyLen; index++)
    {
        int intVal = (int)abbr[index];
        hashValue += intVal * index;
    }

    hashValue = hashValue % this->table.size();

    return hashValue;
};

// void Hashtable::remove(const std::string &abbr)
// {
//     int index = this->hashString(abbr);
//     // TODO
// };

void Hashtable::add(const std::string &abbr, const std::string &name, const std::string &wkn)
{
    HashItem *newItem = new HashItem(abbr, name, wkn);
    newItem->abbr = std::string(abbr);

    int hashIndex = this->hashString(abbr);
    this->table[hashIndex] = newItem;
    // check for collision
};

// void Hashtable::add
StockData::StockData()
{
    throw std::invalid_argument("[ WARNING ] StockData must be instantiated with arguments!");
};

StockData::StockData(std::string date, double open, double high, double low, double close, double adj_close, double volume)
    : date(date), open(open), high(high), low(low), close(close), adj_close(adj_close), volume(volume){};

StockData *Hashtable(std::string &date, double high, double low, double close, double adj, double volume, double adj_close)
{
    StockData *newData = new StockData(date, high, low, close, adj, volume, adj_close);

    return newData;
};

void Hashtable::save()
{
    std::ofstream file("saved_hashtable.txt");

    for (int itemIndex = 0; itemIndex < this->size; itemIndex++)
    {
        if (this->table[itemIndex] == NULL)
            continue;
        file << "#," << itemIndex << "," << *(this->table[itemIndex]) << std::endl;

        for (const auto &data : this->table[itemIndex]->data)
        {
            file << *data << std::endl;
        }
    }
};

void Hashtable::addCourseData(const std::string &abbr, StockData &data)
{
    int index = this->hashString(abbr);
    index = this->probe(abbr, index);

    this->table[index]->data.push_back(&data);
};

bool Hashtable::isEmpty(int index)
{
    return this->table[index] == NULL;
}

int Hashtable::probe(const std::string &abbr, int index)
{
    this->probeIndex = 1;
    while (!this->isEmpty(index) && !this->foundKey(abbr, index))
    {
        index += (this->probeIndex * this->probeIndex);
        this->probeIndex++;
    }
    return index;
};

// unnötig
void Hashtable::resetProbeIndex()
{
    this->probeIndex = 1;
}

bool Hashtable::foundKey(const std::string &abbr, int index)
{
    if (this->table[index] == NULL)
        return false;

    return this->table[index]->abbr == abbr;
};

//? was wenn index größer als table?
HashItem *Hashtable::find(const std::string &abbr)
{
    int index = this->hashString(abbr);

    if (this->isEmpty(index))
        throw KeyNotFound(abbr);

    index = this->probe(abbr, index);

    return this->table[index];
}
