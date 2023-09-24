cmake_minimum_required(VERSION 3.5)

project(test)

add_executable(hello_world 

    # src/test.cpp
    
    # src/examples/shapesearch.cpp
    # src/examples/straighten.cpp

    # src/basics/image_processing.cpp
    # src/basics/image_resize.cpp
    # src/basics/shapes_n_text.cpp 
    # src/basics/warp_perspective.cpp
    # src/basics/video_capture.cpp 
    # src/simple_projects/color_detection.cpp
    # src/simple_projects/shape_detection.cpp
    # src/simple_projects/face_detection.cpp
    src/simple_projects/camera_face_detection.cpp

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

