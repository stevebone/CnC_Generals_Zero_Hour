cmake_minimum_required(VERSION 3.10)  # Use a lower version since 3.30 is too new
project(GeneralsZH-AllStars)

# Directories for game components
add_subdirectory(Code)

# Set output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Run")

# Set DirectX include and library directories
set(DX_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Code/Dep/DX90SDK/Include")  # Adjust path as needed
set(DX_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Code/Dep/DX90SDK/Lib/x86")      # Use "x64" for 64-bit builds

include_directories(${DX_INCLUDE_DIR})
link_directories(${DX_LIB_DIR})