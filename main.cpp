#include <iostream>
#include <chrono>
#include <functional>
#include <random>
#include <string>

#include "include/sorting_library.h"
#include "sortertester.h"

int main(int argc, char* argv[]) {
    std::cout << std::fixed << std::showpoint;
    std::cout.precision(9);
    print_version_number();

    int numSorters = 5;
    std::function<void(int* array, int size)> sorters[numSorters];
    sorters[0] = mystery01; //fast for large large sets and still seems to do many operations for in order sets while still being fast; merge sort
    sorters[1] = mystery02; //showing extremely slow with big unordered sets/ fast with big in order sets; optimized bubble sort
    sorters[2] = mystery03; //second slowest for large unordered sets and second fastest for large ordered sets; insertion sort
    sorters[3] = mystery04; //really slow with large in order sets; quick sort (grabs the maximum which is worst case; working with arrays so should be faster than merge)
    sorters[4] = mystery05; //extremely slow almost constant time with large unordered and ordered sets; selection sort

    SorterTester tester;
    tester.testSorters(sorters, numSorters, argv[1]);

    return 0;
}




