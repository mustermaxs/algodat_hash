#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fstream>

bool isPrime(int nr);
int getPrimeBiggerThan(int maxNr);
void printFileContent(const std::string &filePath);

#endif