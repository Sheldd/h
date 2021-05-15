# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Neuton_Method_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Neuton_Method_autogen.dir/ParseCache.txt"
  "Neuton_Method_autogen"
  )
endif()
