cmake_minimum_required(VERSION 3.7)
project(unp)

set(CMAKE_C_STANDARD 99)
add_compile_options(-Wall -Werror -g3)

include(CheckSymbolExists)

# Check for function bzero
check_symbol_exists(bzero "strings.h" HAVE_BZERO)
if (HAVE_BZERO)
  add_definitions(-DHAVE_BZERO)
endif()
# Check for function vsnprintf
check_symbol_exists(vsnprintf "stdio.h" HAVE_VSNPRINTF)
if (HAVE_VSNPRINTF)
  add_definitions(-DHAVE_VSNPRINTF)
endif()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(lib)

link_libraries(unp)
include_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(byteorder byteorder/byteorder.c)
add_executable(daytimetcpcli daytimetcpcli/daytimetcpcli.c)
add_executable(daytimetcpsrv daytimetcpsrv/daytimetcpsrv.c)
