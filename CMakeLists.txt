cmake_minimum_required(VERSION 3.26)
project(Elaborato_Prog)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_subdirectory(GoogleTest)

find_package(Qt5Widgets REQUIRED)

set(SOURCE_FILES main.cpp
        Time.cpp
        Time.h
        Date.cpp
        Date.h
        Chrono.cpp
        Chrono.h
        Clock.cpp
        Clock.h
        Timer.cpp
        Timer.h)

add_executable(Elaborato_Prog main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(core Qt5::Widgets)
target_link_libraries(Elaborato_Prog core)




