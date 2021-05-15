# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/lagrange_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/lagrange_autogen.dir/ParseCache.txt"
  "lagrange_autogen"
  )
endif()
