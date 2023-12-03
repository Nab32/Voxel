cmake_minimum_required(VERSION 3.12)

set(PROJECT_EXEC "voxel")

project(voxel_engine )

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

file(GLOB SOURCES "${SOURCE_DIR}/*.cpp" "${SOURCE_DIR}/*.h" "${CMAKE_SOURCE_DIR}/*.c")

# Add your source file
add_executable(${PROJECT_EXEC} ${SOURCES})

# Specify the GLFW library file (replace glfw3.lib with the actual library file name)
if (WIN32)
    set(GLFW_LIBRARY "${CMAKE_SOURCE_DIR}/lib/glfw3.lib")
elseif (APPLE)
    set(GLFW_LIBRARY "${CMAKE_SOURCE_DIR}/lib/libglfw.3.dylib")
endif()

# Link against GLFW
target_link_libraries(${PROJECT_EXEC} PRIVATE ${GLFW_LIBRARY})

# Include GLFW headers
target_include_directories(${PROJECT_EXEC} PRIVATE include)

target_compile_features(${PROJECT_EXEC} PRIVATE cxx_std_11)