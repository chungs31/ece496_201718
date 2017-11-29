cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
find_package( OpenCV REQUIRED )
add_executable( DisplayImage DisplayImage.cpp )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )

SET(CXX_EXTRA_COMPILE_FLAGS "-Wall -g")
add_definitions(${CXX_EXTRA_COMPILE_FLAGS})
