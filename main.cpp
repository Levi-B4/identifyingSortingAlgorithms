#include <iostream>
#include <chrono>
#include <functional>
#include <random>

#include "include/sorting_library.h"
#include "timealgorithm.h"

int main() {
    std::cout << std::fixed << std::showpoint;
    std::cout.precision(9);
    print_version_number();

    std::function<void(int* array, int size)> sorters[5];
    sorters[0] = mystery01;
    sorters[1] = mystery02; //showing extremely slow with big sets
    sorters[2] = mystery03;
    sorters[3] = mystery04;
    sorters[4] = mystery05;
    for(int i = 0; i < 5; i++){
        timeAlgorithm(sorters[i], 200, 1000);
    }

    return 0;
}




