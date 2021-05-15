# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Method_of_Simple_Iterations_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Method_of_Simple_Iterations_autogen.dir/ParseCache.txt"
  "Method_of_Simple_Iterations_autogen"
  )
endif()
