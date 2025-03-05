add_executable(GeneralsZH-AllStars WIN32)

target_link_directories(GeneralsZH-AllStars PRIVATE
    ../GameEngine
)

target_link_libraries(GeneralsZH-AllStars PRIVATE
    GameEngine
    GameEngineDevice  
    winmm
    imm32
    dbghelp
    vfw32
    d3d8
    d3dx8
    dinput8
    dxguid
    binkstub
    milesstub
    profile
)

# TODO Originally referred to build host and user, replace with git info perhaps?
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/GeneratedVersion.h
"#pragma once

#define VERSION_LOCALBUILDNUM 0
#define VERSION_BUILDUSER \"Someone\"
#define VERSION_BUILDLOC \"Someplace\"
"
)

# Based on original binary values for these variables.
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/BuildVersion.h
"#pragma once

#define VERSION_MAJOR 1
#define VERSION_MINOR 4
#define VERSION_BUILDNUM 601
"
)

target_link_options(GeneralsZH-AllStars PRIVATE "/NODEFAULTLIB:libci.lib")

target_include_directories(GeneralsZH-AllStars PRIVATE
    ../Lib/Include
    ../Lib/Source
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_sources(GeneralsZH-AllStars PRIVATE
    WinMain.cpp
    WinMain.h
)

if(WIN32 OR "${CMAKE_SYSTEM}" MATCHES "Windows")
    target_sources(GeneralsZH-AllStars PRIVATE
        RTS.RC
    )
endif()