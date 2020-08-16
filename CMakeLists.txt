cmake_minimum_required(VERSION 2.8)

project(leetcode)

set(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_CXX_FLAGS_DEGUG "$ENV{CXXFLAGS} -o0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -o3 -Wall")

aux_source_directory(. DIR_SRCS)

include_directories("${PROJECT_SOURCE_DIR}/solution")

add_subdirectory(solution)

add_executable(demo ${DIR_SRCS})

target_link_libraries(demo solution)