cmake_minimum_required (VERSION 3.10)
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)


# Project name
project (sim-camada-fisica)

set (SOURCE_DIR src)
set (INCLUDE_DIR include)

set (HEADER_FILES 
    ${INCLUDE_DIR}/romano.hpp
)   
set (SOURCE_FILES 
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/romano.cpp
)

# Executable name
add_executable (T2-MP ${DOMAINS_SOURCE_FILES}
                            ${SOURCE_FILES}
)
target_include_directories(T2-MP PUBLIC ${INCLUDE_DIR})

# build tests
set(testing_sources ${SOURCE_FILES} ${SOURCE_DIR}/testa_romano.cpp)

# remove main from sources
list(REMOVE_ITEM testing_sources src/main.cpp)


# Executable tester 
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
add_executable (t2-mp-test ${testing_sources} ${test_files})
target_include_directories(t2-mp-test 
                           PRIVATE
                           Catch2::Catch2
                           ${INCLUDE_DIR}
)
include(CTest)
include(Catch)
catch_discover_tests(t2-mp-test)
