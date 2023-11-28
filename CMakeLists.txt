cmake_minimum_required(VERSION 3.22)
project(BruteForcePCYB)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(extlibs/elzip) # Path to the 11zip

add_executable(BruteForcePCYB
        main.cpp
)

target_link_libraries(BruteForcePCYB elzip)


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/dictionary.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})