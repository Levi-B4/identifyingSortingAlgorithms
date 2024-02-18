cmake_minimum_required(VERSION 3.15)
project(MysterySorters)
set(CMAKE_CXX_STANDARD 14)

# Create the executable for sorting
add_executable(MysterySorters main.cpp
    timealgorithm.h timealgorithm.cpp
)

# Make sure you're using linux (or wsl2)
message("Identified Linux platform.  Linking to mystery_sorting lib")
find_library(MYSTERY_LIBRARY mystery_sorting lib)
target_link_libraries(MysterySorters LINK_PUBLIC ${MYSTERY_LIBRARY})
