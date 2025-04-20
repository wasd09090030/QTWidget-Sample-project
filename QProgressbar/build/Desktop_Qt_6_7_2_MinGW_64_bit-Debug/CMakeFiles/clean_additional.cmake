# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QProgressbar_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QProgressbar_autogen.dir\\ParseCache.txt"
  "QProgressbar_autogen"
  )
endif()
