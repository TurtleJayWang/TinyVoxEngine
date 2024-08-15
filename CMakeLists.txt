cmake_minimum_required(VERSION 3.8)

project(TinyVoxEngine)

file(GLOB SRC_FILE src/*.cpp src/Scene/*.cpp Editor/*.cpp)
file(GLOB HEADER_FILE include/*.hpp include/Scene/*.hpp include/Voxel/*.hpp)

add_executable(TinyVoxelEngine ${SRC_FILE} ${HEADER_FILE})

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(OpenCL REQUIRED)
find_package(GLM REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(include)

target_link_libraries(TinyVoxelEngine ${SDL2_LIBRARIES})
target_link_libraries(TinyVoxelEngine GLEW::GLEW)
target_link_libraries(TinyVoxelEngine OpenCL::OpenCL)
