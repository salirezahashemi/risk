cmake_minimum_required(VERSION 3.23)
project(risk C)

set(CMAKE_C_STANDARD 99)

add_executable (risk main.c)

INCLUDE_DIRECTORIES( c:/mingw32/include)
LINK_DIRECTORIES( c:/mingw32/lib)

TARGET_LINK_LIBRARIES(risk allegro allegro_primitives allegro_font allegro_ttf)

file(GLOB LIBRARIES "C:/mingw32/lib/*.a")
message("LIBRARIES = ${LIBRARIES}")

TARGET_LINK_LIBRARIES(risk  ${LIBRARIES})
