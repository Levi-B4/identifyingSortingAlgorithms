cmake_minimum_required(VERSION 3.15)
project(PA03_template)
set(CMAKE_CXX_STANDARD 14)

# Create the executable for sorting
add_executable(PA03_sorting_mystery main.cpp)

# Make sure you're using linux (or wsl2)!!!
message("  Identified Linux platform.  Linking to mystery_sorting lib")
find_library(MYSTERY_LIBRARY mystery_sorting lib)
target_link_libraries(PA03_sorting_mystery LINK_PUBLIC ${MYSTERY_LIBRARY})
