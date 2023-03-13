#include "utils.h"

bool isPrime(int nr)
{
    for (int i = 2; i <= nr / 2; ++i)
    {
        if (nr % i == 0)
        {
            return false;
        }
    }

    return true;
};

int getPrimeBiggerThan(int maxNr)
{
    int biggestPrimeInRange = 2;
    int index = 0;

    while (biggestPrimeInRange < maxNr)
    {
        biggestPrimeInRange = isPrime(index) ? index : biggestPrimeInRange;
        index++;
    }

    return biggestPrimeInRange;
};