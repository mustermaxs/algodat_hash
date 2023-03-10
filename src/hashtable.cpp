#include "hashtable.h"
// TODO table pointer in vector
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

void Hashtable::add(const std::string &key)
{
    hash_item *newItem = new hash_item;
    newItem->key = std::string(key);

    int hashIndex = this->hashString(key);
    this->table[hashIndex] = newItem;
    // check for collision
};

void Hashtable::add

    course_data *
    Hashtable::createCourseDataEl(std::string &date, double high, double low, double close, double adj, double volume, double adj_close)
{
    course_data *courseData = new course_data;
    courseData->date = std::string(date);
    courseData->high = high;
    courseData->low = low;
    courseData->close = close;
    courseData->adj = adj;
    courseData->volume = volume;
    courseData->adj_close = adj_close;

    return courseData;
};

void Hashtable::addCourseData(std::string &key, course_data &data)
{
    int index = this->hashString(key);
    index = this->probe(key, index);

    this->table[index]->data.push_back(&data);
};

bool Hashtable::isEmpty(int index)
{
    return this->table[index] == NULL;
}

int Hashtable::probe(std::string &key, int index)
{
    this->probeIndex = 1;
    while (!this->isEmpty(index) || !this->foundKey(key, index))
        index += (probeIndex * probeIndex++);
    return index;
};

// unnötig
void Hashtable::resetProbeIndex()
{
    this->probeIndex = 1;
}

bool Hashtable::foundKey(std::string &key, int index)
{
    if (this->table[index] == NULL)
        return false;

    return key.compare(this->table[index]->key);
};

//? was wenn index größer als table?
hash_item *Hashtable::get(std::string &key)
{
    int index = this->hashString(key);

    if (this->isEmpty(index))
        return NULL;

    index = this->probe(key, index);

    return this->table[index];
}
