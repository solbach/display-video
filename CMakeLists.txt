cmake_minimum_required(VERSION 2.8)
project( displayVideo )

find_package( OpenCV REQUIRED )

add_executable( displayVideo main.cpp )
target_link_libraries( displayVideo ${OpenCV_LIBS} )