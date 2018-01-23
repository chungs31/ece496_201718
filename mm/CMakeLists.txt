cmake_minimum_required(VERSION 2.8)
project( mm )
find_package( OpenCV REQUIRED )
add_executable( mm mm.cpp )
target_link_libraries( mm ${OpenCV_LIBS} )

SET(CXX_DEBUG_COMPILE_FLAGS "-Wall -g")
SET(CXX_PROD_COMPILE_FLAGS "-Wall -O2")
add_definitions(${CXX_PROD_COMPILE_FLAGS})
