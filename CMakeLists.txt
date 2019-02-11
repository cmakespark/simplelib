cmake_minimum_required(VERSION 3.4.3 FATAL_ERROR)
project(simplelib)

# Download build system
set(CMAKESPARK_VERSION "v2.1.0-T3" CACHE STRING "Version of cmakespark")
if(DEFINED ENV{CMAKESPARK})
    list(APPEND CMAKE_MODULE_PATH "$ENV{CMAKESPARK}")
    message(STATUS "Using cmakespark from $ENV{CMAKESPARK}")
elseif(DEFINED CMAKESPARK)
    list(APPEND CMAKE_MODULE_PATH "${CMAKESPARK}")
    message(STATUS "Using cmakespark from ${CMAKESPARK}")
else()
    if(NOT EXISTS "${CMAKE_BINARY_DIR}/cmakespark/${CMAKESPARK_VERSION}")
        message(STATUS "Downloading cmakespark...")

        file(DOWNLOAD https://github.com/cmakespark/cmake/releases/download/${CMAKESPARK_VERSION}/cmakespark.zip "${CMAKE_BINARY_DIR}/cmakespark.zip")
        file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/cmakespark/${CMAKESPARK_VERSION})
        execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${CMAKE_BINARY_DIR}/cmakespark.zip
                        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/cmakespark/${CMAKESPARK_VERSION})
    endif()
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}/cmakespark/${CMAKESPARK_VERSION}")
endif()

# Include common cmake modules
include(CommonConfig)

add_subdirectory(src)
add_subdirectory(example)
