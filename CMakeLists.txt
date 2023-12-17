cmake_minimum_required(VERSION 3.12)

set(PROJECT_EXEC "voxel")

project(voxel_engine)
set(CMAKE_CONFIGURATION_TYPES "Debug" CACHE STRING "" FORCE)
set(LIBNOISE_LIB_PATH "${CMAKE_SOURCE_DIR}/lib/libnoise.dll")
set(CMAKE_GENERATOR_TOOLSET "host=x86" CACHE STRING "Platform toolset" FORCE)
set(CMAKE_GENERATOR_PLATFORM "x86" CACHE STRING "Platform name" FORCE)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
	set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)
endif()

set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

file(GLOB SOURCES "${SOURCE_DIR}/*.cpp" "${SOURCE_DIR}/*.h" "${CMAKE_SOURCE_DIR}/*.c" "${SOURCE_DIR}/shaders/*.glsl")

# Add your source file
add_executable(${PROJECT_EXEC} ${SOURCES})

# Specify the GLFW library file (replace glfw3.lib with the actual library file name)
if (WIN32)
    set(GLFW_LIBRARY "${CMAKE_SOURCE_DIR}/lib/glfw3.lib")
elseif (APPLE)
    set(GLFW_LIBRARY "${CMAKE_SOURCE_DIR}/lib/libglfw.3.dylib")
endif()

if (MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:MSVCRT")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /NODEFAULTLIB:MSVCRT")
    set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /NODEFAULTLIB:MSVCRT")
endif()

# Link against GLFW
target_link_libraries(${PROJECT_EXEC} PRIVATE ${GLFW_LIBRARY})
target_link_libraries(${PROJECT_EXEC} PRIVATE "${CMAKE_SOURCE_DIR}/lib/libnoise.lib")

set_target_properties(${PROJECT_EXEC} PROPERTIES LINK_FLAGS "/SAFESEH:NO")

# Include GLFW headers
target_include_directories(${PROJECT_EXEC} PRIVATE include)

set_target_properties(${PROJECT_EXEC} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

add_custom_command(TARGET ${PROJECT_EXEC} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${LIBNOISE_LIB_PATH}"
        $<TARGET_FILE_DIR:${PROJECT_EXEC}>
)

target_compile_features(${PROJECT_EXEC} PRIVATE cxx_std_17)