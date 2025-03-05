# WW common libraries decended from earliest C&C games
add_subdirectory(Source/WWVegas)

# EA Compression library
add_subdirectory(Source/Compression)

# profiling library
#add_subdirectory(Source/profile)

target_include_directories(wwshade PRIVATE
#    ../Dep/DX90SDK/Include
)