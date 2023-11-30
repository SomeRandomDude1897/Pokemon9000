cmake_minimum_required(VERSION 3.1)

project(Pokemon9000 LANGUAGES CXX)

file(GLOB SOURCES
    headers/*.h
    headers/*.hpp
    scripts/*.cpp)

add_executable(Pokemon9000 ${SOURCES})