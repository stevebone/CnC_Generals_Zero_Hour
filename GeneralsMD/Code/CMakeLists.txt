project(cnc-zero-hour C CXX)

cmake_minimum_required(VERSION 3.23)

file(GLOB_RECURSE SOURCES_COMMON
    ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine/Source/Common/*.cpp
)

add_library(cnc-zero-hour-common STATIC ${SOURCES_COMMON})

target_include_directories(cnc-zero-hour-common PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine/Include/Precompiled
    # Used in Thing.h via WWMath
    ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/Source/WWVegas
    # Also pulls WWLib
    ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/Source/WWVegas/WWLib
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/dxvk-native
)