#ifndef TESTMYSTERYALGORITHMS_H
#define TESTMYSTERYALGORITHMS_H

#include "timealgorithm.h"

#include <iostream>
#include <chrono>
#include <functional>
#include <random>

void testMysteryAlgorithms(std::function<void(int* array, int size)>* sorters, int numSorters);

#endif // TESTMYSTERYALGORITHMS_H
