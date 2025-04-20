# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QDialog_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QDialog_autogen.dir\\ParseCache.txt"
  "QDialog_autogen"
  )
endif()
