# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/SLAE_Gauss_Method_Major_Component_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/SLAE_Gauss_Method_Major_Component_autogen.dir/ParseCache.txt"
  "SLAE_Gauss_Method_Major_Component_autogen"
  )
endif()
