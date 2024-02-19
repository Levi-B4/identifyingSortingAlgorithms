#ifndef TESTMYSTERYALGORITHMS_H
#define TESTMYSTERYALGORITHMS_H

#include "timealgorithm.h"

#include <iostream>
#include <chrono>
#include <functional>
#include <random>

using Sorter = std::function<void(int* array, int size)>;

// test sorting algorithms and output the results to a csv file - params: std::function<void(int* array, int size)>, int numSorters
void testMysteryAlgorithms(const Sorter* sorters, const int numSorters, const char* outputFilePath);

#endif // TESTMYSTERYALGORITHMS_H
