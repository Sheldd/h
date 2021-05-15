cmake_minimum_required(VERSION 3.14)

project(Eigen_Vectors_and_value_forward LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

add_executable(Eigen_Vectors_and_value_forward
  main.cpp
  Matrix.cpp
  Matrix.h
)
target_link_libraries(Eigen_Vectors_and_value_forward Qt${QT_VERSION_MAJOR}::Core)
