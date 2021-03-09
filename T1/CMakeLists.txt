cmake_minimum_required (VERSION 3.10)
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set (EXECUTABLE_OUTPUT_PATH "..")

# Project name
project (sim-camada-fisica)

set (SOURCE_DIR src)
set (INCLUDE_DIR include)

set (HEADER_FILES 
    ${INCLUDE_DIR}/pilha.h
)   
set (SOURCE_FILES 
    ${SOURCE_DIR}/pilha.cpp
    ${SOURCE_DIR}/testa_pilha.cpp
)
# Executable name
add_executable (T1-MP ${DOMAINS_SOURCE_FILES}
                            ${SOURCE_FILES}
)
target_include_directories(T1-MP PUBLIC ${INCLUDE_DIR})