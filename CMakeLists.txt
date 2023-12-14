cmake_minimum_required(VERSION 3.26)
project(Elaborato_Prog)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)



add_executable(Elaborato_Prog main.cpp
        Time.cpp
        Time.h
        Date.cpp
        Date.h
        Chrono.cpp
        Chrono.h
        Clock.cpp
        Clock.h
        Timer.cpp
        Timer.h
)


find_package(Qt5 COMPONENTS Widgets REQUIRED)
target_link_libraries(Elaborato_Prog PRIVATE Qt5::Widgets)

