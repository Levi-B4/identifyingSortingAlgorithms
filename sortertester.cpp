#include "sortertester.h"

#include <iostream>
#include <chrono>
#include <functional>
#include <random>
#include <fstream>

// define types
using Sorter = std::function<void(int* array, int size)>;

/**
 * default constructor
 */
SorterTester::SorterTester() {}


/**
 * Runs multiple time tests of each sorting algorithm with a random array, ordered ascending array, and ordered descending array.
 * Outputs the results to a csv file.
 * params: std::function<void(int* array, int size)>, int numSorters
 */
void SorterTester::testSorters(const Sorter* sorters, const int numSorters, const char* outputFilePath){
    int maxArraySize = 1000;
    int ascendingArray[maxArraySize];
    int descendingArray[maxArraySize];

    for(int i = 0; i < maxArraySize; i++){
        ascendingArray[i] = i;
        descendingArray[maxArraySize - 1 - i] = i;
    }


    std::ofstream outputFile(outputFilePath);

    outputFile << "Sorter,Array Order,size 10,size 100,size 1000";

    std::cout << "beginning tests..." << std::endl;
    // iterate through each sorter and test with random, ascending, and descending arrays of size 10, 100, 1000
    for(int i = 0; i < numSorters; i++){
        outputFile << std::endl << "Sorter" << i+1 << ",Random";
        for(int j = 10; j <= maxArraySize; j *= 10){
            outputFile << ',' << timeSorter(sorters[i], j);
        }
        std::cout << "Calculated random tests for sorter " << i+1 << std::endl;

        outputFile << std::endl << "Sorter" << i+1 << ",Ascending";
        for(int j = 10; j <= maxArraySize; j *= 10){
            outputFile << ',' << timeSorter(sorters[i], ascendingArray, j);
        }
        std::cout << "Calculated ascending tests for sorter " << i+1 << std::endl;

        outputFile << std::endl << "Sorter" << i+1 << ",Descending";
        for(int j = 10; j <= maxArraySize; j *= 10){
            outputFile << ',' << timeSorter(sorters[i], descendingArray, j);
        }
        std::cout << "Calculated descending tests for sorter " << i+1 << std::endl;
    }
    outputFile << std::endl;

    outputFile.close();
}

/**
 *  Creates random array of the specified size at the location of the specified array
 *  params: int* target, int targetSize
 */
void SorterTester::createRandomArray(int* target, const int targetSize){
    // create random number generator for numbers between 1 and 1000
    std::random_device device;
    std::mt19937 gen(device());
    std::uniform_int_distribution<> dist(1, 1000);

    for(int i = 0; i < targetSize; i++){
        target[i] = dist(gen);
    }
}

/**
 *  Tests an algorithm and takes its average runtime in nanoseconds for a random array of the given size, multiple times.
 *  Then takes and returns the median of all average runtimes to account for outliers.
 *  params: std::function<void(int* array, int size)> sorter, int dataSize
 */
long SorterTester::timeSorter(const Sorter sorter, const int dataSize){
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    long currentTrialTime;
    long long totalTime = 0;

    int numTimeTests = 6;
    int tests[numTimeTests];
    int trialsPerTest = 1000;

    int currentArray[dataSize];

    // run specified amount of trials saving the average, repeating *numTimeTests* times
    for(int i = 0; i < numTimeTests; i++){
        for(int j = 0; j < trialsPerTest; j++){
            createRandomArray(currentArray, dataSize);

            start = std::chrono::high_resolution_clock::now();

            sorter(currentArray, dataSize);

            end = std::chrono::high_resolution_clock::now();

            currentTrialTime = std::chrono::duration_cast<std::chrono::nanoseconds>( end - start ).count();
            totalTime += currentTrialTime;
        }
        tests[i] = totalTime / trialsPerTest;
        totalTime = 0;
    }

    // return test average that is about the median of all test averages
    sorter(tests, numTimeTests);
    return tests[numTimeTests / 2];
}

/**
 * Tests an algorithm and takes its average runtime for the given array, multiple times.
 * Then takes and returns the median of all average runtimes to account for outliers
 * params: std::function<void(int* array, int size)> sorter, int dataSize
 */
long SorterTester::timeSorter(const Sorter sorter, int* array, const int dataSize){
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    long currentTrialTime;
    long long totalTime = 0;

    int numTimeTests = 7;
    int tests[numTimeTests];
    int trialsPerTest = 1000;

    int originalArray[dataSize];

    // run specified amount of trials saving the average, repeating *numTimeTests* times
    for(int i = 0; i < numTimeTests; i++){
        for(int j = 0; j < trialsPerTest; j++){
            std::copy(array, array + dataSize - 1, originalArray);

            start = std::chrono::high_resolution_clock::now();

            sorter(originalArray, dataSize);

            end = std::chrono::high_resolution_clock::now();

            currentTrialTime = std::chrono::duration_cast<std::chrono::nanoseconds>( end - start ).count();
            totalTime += currentTrialTime;
        }

        tests[i] = totalTime / trialsPerTest;
        totalTime = 0;
    }

    // return tests that is about the median of all tests
    sorter(tests, numTimeTests);
    return tests[numTimeTests / 2];
}
