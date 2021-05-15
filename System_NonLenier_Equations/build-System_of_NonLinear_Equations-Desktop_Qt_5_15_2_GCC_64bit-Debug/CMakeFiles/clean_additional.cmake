# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/System_of_NonLinear_Equations_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/System_of_NonLinear_Equations_autogen.dir/ParseCache.txt"
  "System_of_NonLinear_Equations_autogen"
  )
endif()
