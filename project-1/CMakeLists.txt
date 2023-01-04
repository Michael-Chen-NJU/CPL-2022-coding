add_executable(dinasour dinasour.c)
add_executable(calculator calculator.c)

target_link_libraries(dinasour mingw32)
target_link_libraries(dinasour SDL2main)
target_link_libraries(dinasour SDL2)
target_link_libraries(dinasour SDL2_image)
target_link_libraries(dinasour SDL2_ttf)
