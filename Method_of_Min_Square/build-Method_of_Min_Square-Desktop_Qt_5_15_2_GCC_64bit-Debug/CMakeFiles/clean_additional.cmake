# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Method_of_Min_Square_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Method_of_Min_Square_autogen.dir/ParseCache.txt"
  "Method_of_Min_Square_autogen"
  )
endif()
