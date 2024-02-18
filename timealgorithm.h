#ifndef TIMEALGORITHM_H
#define TIMEALGORITHM_H

#include <iostream>
#include <chrono>
#include <functional>
#include <random>

// test an algorithm and print its average runtime for the given array - params: std::function<void(int* array, int size)> sorter, int dataSize, int numTrials = 1000
//int timeAlgorithm(std::function<void(int* array, int size)> sorter, int* array, int dataSize, int numTrials = 1000)

// test an algorithm and print its average runtime for the given data size - params: std::function<void(int* array, int size)> sorter, int dataSize,  int numTrials = 1000
int timeAlgorithm(std::function<void(int* array, int size)> sorter, int dataSize, int numTrials = 1000);

// creates random array of the specified size at the location of the specified array - params: int* target, int targetSize
void createRandomIntArray(int* target, int targetSize);

#endif // TIMEALGORITHM_H
