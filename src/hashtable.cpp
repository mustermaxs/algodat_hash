#include "hashtable.h"
#include "utils.h"

HashItem::HashItem()
{
    throw std::invalid_argument("[ WARNING ] HashItem must be instantiated with arguments!");
};

Hashtable::Hashtable(int nbrOfEntries)
{
    this->size = getPrimeBiggerThan(nbrOfEntries * 1.3);
    this->table.resize(this->size, NULL);
    // std::cout << this->table.size();
};

void Hashtable::import(const std::string &path)
{
    this->parser->parseFile(path);
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

void Hashtable::add(const std::string &abbr, const std::string &name, const std::string &wkn)
{
    HashItem *newItem = new HashItem(abbr, name, wkn);
    newItem->abbr = std::string(abbr);

    int hashIndex = this->hashString(abbr);
    this->table[hashIndex] = newItem;
    // check for collision
};

// void Hashtable::add

StockData *
Hashtable::createStockData(std::string &date, double high, double low, double close, double adj, double volume, double adj_close)
{
    StockData *newData = new StockData(date, high, low, close, adj, volume, adj_close);

    return newData;
};

void Hashtable::addCourseData(std::string &abbr, StockData &data)
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
