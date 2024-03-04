cmake_minimum_required(VERSION 3.15)
project(MysterySorters LANGUAGES CXX)
set(EXE_NAME MysterySorters)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the executable for sorting
add_executable(${EXE_NAME} main.cpp
    sortertester.h sortertester.cpp
)

# Make sure you're using linux (or wsl2)
message("Identified Linux platform.  Linking to mystery_sorting lib")
find_library(MYSTERY_LIBRARY mystery_sorting lib)
target_link_libraries(MysterySorters LINK_PUBLIC ${MYSTERY_LIBRARY})

include(GNUInstallDirs)
install(TARGETS ${EXE_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
