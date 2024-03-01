#ifndef SORTERTESTER_H
#define SORTERTESTER_H

#include <functional>

// define types
using Sorter = std::function<void(int* array, int size)>;

class SorterTester
{
public:
    /**
     * default constructor
     */
    SorterTester();

    /**
     * tests sorting algorithms and outputs the results to a csv file
     * params: const std::function<void(int* array, int size)>* sorter, const int numSorters, const char* outputFilePath
     */
    void testSorters(const Sorter* sorters, const int numSorters, const char* outputFilePath);

private:
    /**
     * creates a random array at the given target
     * params: int* target, const int targetSize
     */
    void createRandomArray(int* target, const int targetSize);
    /**
     * returns average runtime of the given sorter for a random array of the given size.
     * params: std::function<void(int* array, int size)> sorter, int dataSize
     */
    long timeSorter(const Sorter sorter, const int dataSize);
    /**
     * returns average runtime of the given sorter for the given array
     * params: const std::function<void(int* array, int size)> sorter, int* array, const int dataSize
     */
    long timeSorter(const Sorter sorter, int* array, const int dataSize);
};

#endif // SORTERTESTER_H
