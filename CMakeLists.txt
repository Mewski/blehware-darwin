cmake_minimum_required(VERSION 3.25)

project(blehware-darwin)

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 23)
set(BUILD_SHARED_LIBS OFF)

add_subdirectory(blehware-injector)
add_subdirectory(blehware-module)
add_subdirectory(blehware-terminal)

add_dependencies(blehware-injector blehware-module)

add_subdirectory(dependencies)