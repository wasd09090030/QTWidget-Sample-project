# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Qslider_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Qslider_autogen.dir\\ParseCache.txt"
  "Qslider_autogen"
  )
endif()
