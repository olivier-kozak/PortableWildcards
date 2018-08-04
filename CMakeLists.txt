cmake_minimum_required(VERSION 3.9)

project(PortableWildcards)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

include(CMake/PortableWildcards/PortableWildcardsConfig.cmake)

install(DIRECTORY CMake/PortableWildcards DESTINATION lib/cmake)

add_subdirectory(Lib)
