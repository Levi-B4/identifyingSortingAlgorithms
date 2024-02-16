#include <iostream>
#include <chrono>
#include "include/sorting_library.h"


int main() {

    // Make some data to sort
    int data[50];
    for (int i = 0; i < 50; i++)
        data[i] = i;

    std::cout << std::fixed << std::showpoint;
    std::cout.precision(9);
    print_version_number();

    // Create a start and end time_point object
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    // 1. Get the current time (start)
    start = std::chrono::high_resolution_clock::now();

    // 2. Run the algorithm
    mystery03(data, 50);

    // 3. Get current time again (end)
    end = std::chrono::high_resolution_clock::now();

    //calculate the duration between start and end and print to the terminal
    std::chrono::duration<double> time_in_seconds = end - start;
    std::cout << std::fixed << "Duration: " << time_in_seconds.count() << std::endl;
    return 0;
}
