# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Eigen_Vectors_and_value_forward_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Eigen_Vectors_and_value_forward_autogen.dir/ParseCache.txt"
  "Eigen_Vectors_and_value_forward_autogen"
  )
endif()
