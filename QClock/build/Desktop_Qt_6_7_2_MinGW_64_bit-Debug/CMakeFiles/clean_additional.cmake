# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QClock_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QClock_autogen.dir\\ParseCache.txt"
  "QClock_autogen"
  )
endif()
