cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(StoneServer VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Include guards ----
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

set(STONESERVER_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_INSTALL_PREFIX "${STONESERVER_ROOT_DIR}/bin")
set(BINARY_ROOT_DIR "${CMAKE_INSTALL_PREFIX}/")
# static library output dir
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${STONESERVER_ROOT_DIR}/out/lib)
# dynamic library output dir
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${STONESERVER_ROOT_DIR}/out/lib)
# executalbe dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${STONESERVER_ROOT_DIR}/out/bin)

add_subdirectory(StoneServer)