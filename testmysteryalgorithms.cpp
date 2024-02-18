#include "testmysteryalgorithms.h"
#include "timealgorithm.h"

#include <iostream>
#include <chrono>
#include <functional>
#include <random>

void testMysteryAlgorithms(std::function<void(int* array, int size)>* sorters, int numSorters){
    int inOrderSize = 1000;
    int inOrderArray[inOrderSize];
    for(int i = 0; i < inOrderSize; i++){
        inOrderArray[i] = i;
    }

    // big unordered vs big in order
    for(int i = 0; i < 5; i++){
        timeAlgorithm(sorters[i], 1000);
        timeAlgorithm(sorters[i], inOrderArray, inOrderSize);
        std::cout << std::endl;
    }
}
