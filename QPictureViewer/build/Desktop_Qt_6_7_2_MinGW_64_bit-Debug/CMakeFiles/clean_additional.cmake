# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QPictureViewer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QPictureViewer_autogen.dir\\ParseCache.txt"
  "QPictureViewer_autogen"
  )
endif()
