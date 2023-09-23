cmake_minimum_required(VERSION 3.5)

project(test)

add_executable(hello_world 
    test.cpp
)

find_package(OpenCV CONFIG REQUIRED)

set( OpenCV_DIR )

if( NOT CMAKE_CL_64 )
    set( OpenCV_DIR "./vcpkg/installed/x86-windows/share/opencv4" )
else()
    set( OpenCV_DIR "./vcpkg/installed/x64-windows/share/opencv4" )
endif()


if( OpenCV_FOUND )
    # Additional Include Directories
    include_directories( ${OpenCV_INCLUDE_DIRS} )

    # Additional Library Directories
    link_directories( ${OpenCV_LIB_DIR} )

    # Additional Dependencies
    target_link_libraries( hello_world ${OpenCV_LIBS} )

    # target_link_libraries(hello_world PRIVATE opencv_ml opencv_dnn opencv_core opencv_flann)
endif()


set_target_properties(
    hello_world PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

