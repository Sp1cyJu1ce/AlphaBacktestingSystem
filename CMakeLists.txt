cmake_minimum_required(VERSION 3.10)

project(Backtester)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# List all the .cpp files with the correct path
add_executable(backtester
    src/dataProcessing.cpp
    src/MomentumStrategy.cpp
    src/Portfolio.cpp
    src/Metrics.cpp
    src/Backtester.cpp
    src/main.cpp
)

# Optional: Include the directory where the header files are located
include_directories(src)