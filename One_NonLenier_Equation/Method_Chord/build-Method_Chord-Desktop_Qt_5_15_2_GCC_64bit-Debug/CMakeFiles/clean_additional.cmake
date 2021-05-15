# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Method_Chord_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Method_Chord_autogen.dir/ParseCache.txt"
  "Method_Chord_autogen"
  )
endif()
