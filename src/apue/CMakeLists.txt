cmake_minimum_required(VERSION 3.8)
project(apue)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Werror")

include_directories(lib)
link_directories(lib)
link_libraries(unp)

add_executable(list_files list_files/list_files.c)
add_executable(ls ls/ls.c)
add_executable(getcwd getcwd/getcwd.c)
add_executable(getpid getpid/getpid.c)
add_executable(process_control process_control/process_control.c)
add_executable(error_process error_process/error_process.c)
add_executable(open_file open_file/open_file.c)
add_executable(creat creat/creat.c)
add_executable(seek_stdin seek_stdin/seek_stdin.c)
add_executable(seek_long seek_long/seek_long.c)
add_executable(read_stdin_write_stdout read_stdin_write_stdout/read_stdin_write_stdout.c)
add_executable(read_stdin_write_stdout2 read_stdin_write_stdout2/read_stdin_write_stdout2.c)
add_executable(write2files write2files/write2files.c)
add_executable(dup dup/dup.c)
add_executable(fcntl_getfl fcntl_getfl/fcntl_getfl.c)
add_executable(fcntl_setfl fcntl_setfl/fcntl_setfl.c)
add_executable(fcntl_fd fcntl_fd/fcntl_fd.c)
add_executable(stat_file_mode stat_file_mode/stat_file_mode.c)
add_executable(stat_demo stat_demo/stat_demo.c)



add_executable(demo demo/demo.c)


