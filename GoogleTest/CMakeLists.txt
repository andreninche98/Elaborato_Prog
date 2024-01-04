cmake_minimum_required(VERSION 3.20)
project(GoogleTest)

add_subdirectory(lib/googletest-1.14.0)
set(gtest_SOURCE_DIR, ./lib/googletest-1.14.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(SOURCE_FILES AllTests.cpp
        ClockTest.cpp
        TimerTest.cpp
        ChronoTest.cpp
        DateTest.cpp)
add_executable(Google_Tests_run ${SOURCE_FILES})
target_link_libraries(Google_Tests_run gtest gtest_main gmock core)



