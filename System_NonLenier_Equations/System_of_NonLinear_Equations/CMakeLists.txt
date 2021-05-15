cmake_minimum_required(VERSION 3.14)

project(System_of_NonLinear_Equations LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

add_executable(System_of_NonLinear_Equations
  main.cpp
  Matrix.cpp
  Matrix.h
)
target_link_libraries(System_of_NonLinear_Equations Qt${QT_VERSION_MAJOR}::Core)
