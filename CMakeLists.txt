# version
cmake_minimum_required(VERSION 3.2)

# project name
project( rayTracer )

set (CMAKE_CXX_STANDARD 11)


# Package required to compilation
find_package( OpenCV REQUIRED )

# bring headers
include_directories( include )


set(SOURCES app/main.cpp)

file(GLOB SOURCES "app/*.cpp")


add_executable( rayTracer ${SOURCES} )
target_link_libraries( rayTracer ${OpenCV_LIBS} )
