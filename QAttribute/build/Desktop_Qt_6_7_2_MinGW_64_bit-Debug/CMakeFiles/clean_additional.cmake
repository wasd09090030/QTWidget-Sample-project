# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QAttribute_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QAttribute_autogen.dir\\ParseCache.txt"
  "QAttribute_autogen"
  )
endif()
