cmake_minimum_required(VERSION 3.14)

project(Method_Rotation_Jacobi_Eigen_Vectors_and_Values LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

add_executable(Method_Rotation_Jacobi_Eigen_Vectors_and_Values
  main.cpp
  Matrix.cpp
  Matrix.h
)
target_link_libraries(Method_Rotation_Jacobi_Eigen_Vectors_and_Values Qt${QT_VERSION_MAJOR}::Core)
