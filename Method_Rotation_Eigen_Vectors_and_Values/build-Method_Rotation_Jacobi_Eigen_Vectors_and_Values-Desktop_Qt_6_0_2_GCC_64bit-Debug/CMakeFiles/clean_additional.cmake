# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Method_Rotation_Jacobi_Eigen_Vectors_and_Values_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Method_Rotation_Jacobi_Eigen_Vectors_and_Values_autogen.dir/ParseCache.txt"
  "Method_Rotation_Jacobi_Eigen_Vectors_and_Values_autogen"
  )
endif()
