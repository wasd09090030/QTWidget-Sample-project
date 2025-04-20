# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QGraphic_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QGraphic_autogen.dir\\ParseCache.txt"
  "QGraphic_autogen"
  )
endif()
