cmake_minimum_required(VERSION 3.8)
project(3d_solid)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL REQUIRED)
include_directories(${SDL_INCLUDE_DIR})

set(SOURCE_FILES main.cpp main.h
        triangleBoundingBox.cpp triangleBoundingBox.h
        mesh.h
        vec3f.h color.h
        cfg.h
        perVertexLighting.cpp perVertexLighting.h)
add_executable(3d_solid ${SOURCE_FILES})
target_link_libraries(3d_solid  -lmingw32 ${SDL_LIBRARY})
