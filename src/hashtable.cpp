#include "hashtable.h"

HashItem::HashItem()
{
    throw std::invalid_argument("[ WARNING ] HashItem must be instantiated with arguments!");
};

Hashtable::Hashtable(int size) : table(size), size(size){};

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

int Hashtable::hashString(const std::string &key) const
{
    int hashValue = 0;
    int keyLen = key.length();

    for (int index = 0; index < keyLen; index++)
    {
        int intVal = (int)key[index];
        hashValue += intVal * index;
    }

    hashValue = hashValue % this->size;

    return hashValue;
};

void Hashtable::add(const std::string &key, const std::string &name, const std::string &wkn)
{
    HashItem *newItem = new HashItem(key, name, wkn);
    newItem->key = std::string(key);

    int hashIndex = this->hashString(key);
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

void Hashtable::addCourseData(std::string &key, StockData &data)
{
    int index = this->hashString(key);
    index = this->probe(key, index);

    this->table[index]->data.push_back(&data);
};

bool Hashtable::isEmpty(int index)
{
    return this->table[index] == NULL;
}

int Hashtable::probe(const std::string &key, int index)
{
    this->probeIndex = 1;
    while (!this->isEmpty(index) && !this->foundKey(key, index))
        index += (probeIndex * probeIndex++);
    return index;
};

// unnötig
void Hashtable::resetProbeIndex()
{
    this->probeIndex = 1;
}

bool Hashtable::foundKey(const std::string &key, int index)
{
    if (this->table[index] == NULL)
        return false;

    return this->table[index]->key == key;
};

//? was wenn index größer als table?
HashItem *Hashtable::find(const std::string &key)
{
    int index = this->hashString(key);

    if (this->isEmpty(index))
        throw KeyNotFound(key);

    index = this->probe(key, index);

    return this->table[index];
}
