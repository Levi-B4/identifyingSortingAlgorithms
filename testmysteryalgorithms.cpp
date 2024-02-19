#include "testmysteryalgorithms.h"
#include "timealgorithm.h"

#include <iostream>
#include <chrono>
#include <functional>
#include <random>
#include <fstream>

// define types
using Sorter = std::function<void(int* array, int size)>;

// test sorting algorithms and output the results to a csv file - params: std::function<void(int* array, int size)>, int numSorters
void testMysteryAlgorithms(const Sorter* sorters, const int numSorters, const char* outputFilePath){
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
            outputFile << ',' << timeAlgorithm(sorters[i], j);
        }
        std::cout << "Calculated random tests for sorter " << i+1 << std::endl;

        outputFile << std::endl << "Sorter" << i+1 << ",Ascending";
        for(int j = 10; j <= maxArraySize; j *= 10){
            outputFile << ',' << timeAlgorithm(sorters[i], ascendingArray, j);
        }
        std::cout << "Calculated ascending tests for sorter " << i+1 << std::endl;

        outputFile << std::endl << "Sorter" << i+1 << ",Descending";
        for(int j = 10; j <= maxArraySize; j *= 10){
            outputFile << ',' << timeAlgorithm(sorters[i], descendingArray, j);
        }
        std::cout << "Calculated descending tests for sorter " << i+1 << std::endl;
    }

    outputFile.close();
}
