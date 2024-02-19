#include "testmysteryalgorithms.h"
#include "timealgorithm.h"

#include <iostream>
#include <chrono>
#include <functional>
#include <random>

void testMysteryAlgorithms(std::function<void(int* array, int size)>* sorters, int numSorters){
    int maxArraySize = 1000;
    int inOrderArray[maxArraySize];
    int backwardsArray[maxArraySize];

    for(int i = 0; i < maxArraySize; i++){
        inOrderArray[i] = i;
        backwardsArray[maxArraySize - 1 - i] = i;
    }

    // 10, 100, 1000, 10000 random
    std::cout << std::endl << "==========Random==========" << std::endl;
    for(int i = 0; i < numSorters; i++){
        std::cout << "sorter " << i+1 << ": " << std::endl;
        for(int j = 10; j <= maxArraySize; j *= 10){
            std::cout << "r" << j << "-" << timeAlgorithm(sorters[i], j) << std::endl;
        }
        std::cout << std::endl;
    }

    // 0, 10, 100, 1000, 10000 already ordered
    std::cout << std::endl << "==========ordered==========" << std::endl;
    for(int i = 0; i < numSorters; i++){
        std::cout << "sorter " << i+1 << ": " << std::endl;
        for(int j = 10; j <= maxArraySize; j *= 10){
            std::cout << "o" << j << "-" << timeAlgorithm(sorters[i], inOrderArray, j) << std::endl;
        }
        std::cout << std::endl;
    }

    // 0, 10, 100, 1000, 10000 ordered backwards
    std::cout << std::endl << "==========backwards==========" << std::endl;
    for(int i = 0; i < numSorters; i++){
        std::cout << "sorter " << i+1 << ": " << std::endl;
        for(int j = 10; j <= maxArraySize; j *= 10){
            std::cout << "b" << j << "-" << timeAlgorithm(sorters[i], backwardsArray, j) << std::endl;
        }
        std::cout << std::endl;
    }
}
