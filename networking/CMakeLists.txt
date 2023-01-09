add_executable(uc-server uppercase/uc-server.c)
add_executable(uc-client uppercase/uc-client.c)
link_libraries(ws2_32)