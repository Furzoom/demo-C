cmake_minimum_required(VERSION 3.7)
project(unp)

set(CMAKE_C_STANDARD 99)
add_compile_options(-Wall -Werror -g3)
link_directories(lib)
link_libraries(unp)
include_directories(lib)

add_executable(byteorder byteorder/byteorder.c)
add_executable(daytimetcpcli daytimetcpcli/daytimetcpcli.c)
add_executable(daytimetcpsrv daytimetcpsrv/daytimetcpsrv.c)
