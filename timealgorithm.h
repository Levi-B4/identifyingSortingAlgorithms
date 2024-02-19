#ifndef TIMEALGORITHM_H
#define TIMEALGORITHM_H

#include <iostream>
#include <chrono>
#include <functional>
#include <random>

using Sorter = std::function<void(int* array, int size)>;

// test an algorithm and print its average runtime in nanoseconds for random arrays of the given size - params: std::function<void(int* array, int size)> sorter, int dataSize,  int numTrials = 1000
long timeAlgorithm(const Sorter sorter, const int dataSize, const int trialsPerTest = 1000);

// test an algorithm and print its average runtime in nanoseconds for the given array - params: std::function<void(int* array, int size)> sorter, int dataSize, int numTrials = 1000
long timeAlgorithm(const Sorter sorter, int* array, const int dataSize, const int trialsPerTest = 1000);

// creates random array of the specified size at the location of the specified array - params: int* target, int targetSize
void createRandomIntArray(int* target, const int targetSize);

#endif // TIMEALGORITHM_H
