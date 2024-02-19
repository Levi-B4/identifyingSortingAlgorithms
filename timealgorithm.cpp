#include "timealgorithm.h"

#include <iostream>
#include <chrono>
#include <functional>
#include <random>

// test an algorithm and print its average runtime for the given array - params: std::function<void(int* array, int size)> sorter, int dataSize, int numTrials = 1000
long timeAlgorithm(std::function<void(int* array, int size)> sorter, int* array, int dataSize, int trialsPerTest/*= 1000*/){
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    long currentTrialTime;
    long long totalTime = 0;

    int numTimeTests = 7;
    int tests[numTimeTests];

    int originalArray[dataSize];

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

    sorter(tests, numTimeTests);

    // return tests that is about the median of all tests
    return tests[numTimeTests / 2];
}

// test an algorithm and print its average runtime for the given data size - params: std::function<void(int* array, int size)> sorter, int dataSize,  int numTrials = 100
long timeAlgorithm(std::function<void(int* array, int size)> sorter, int dataSize, int trialsPerTest/*= 1000*/){
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    long currentTrialTime;
    long long totalTime = 0;

    int numTimeTests = 11;
    int tests[numTimeTests];

    int currentArray[dataSize];

    for(int i = 0; i < numTimeTests; i++){
        for(int j = 0; j < trialsPerTest; j++){
            createRandomIntArray(currentArray, dataSize);

            start = std::chrono::high_resolution_clock::now();

            sorter(currentArray, dataSize);

            end = std::chrono::high_resolution_clock::now();

            currentTrialTime = std::chrono::duration_cast<std::chrono::nanoseconds>( end - start ).count();
            totalTime += currentTrialTime;
        }
        tests[i] = totalTime / trialsPerTest;
        totalTime = 0;
    }

    sorter(tests, numTimeTests);

    // return tests that is about the median of all tests
    return tests[numTimeTests / 2];
}

// creates random array of the specified size at the location of the specified array - params: int* target, int targetSize
void createRandomIntArray(int* target, int targetSize){
    // create random device
    std::random_device device;
    // create number generator using random device
    std::mt19937 gen(device());
    // create a distribution between 1 and 1000
    std::uniform_int_distribution<> dist(1, 1000);

    for(int i = 0; i < targetSize; i++){
        // add random number from distribution to target array
        target[i] = dist(gen);
    }
}
