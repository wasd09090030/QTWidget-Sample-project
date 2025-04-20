# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QuiDesign_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QuiDesign_autogen.dir\\ParseCache.txt"
  "QuiDesign_autogen"
  )
endif()
