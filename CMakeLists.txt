cmake_minimum_required(VERSION 3.13)
project(Race C)

set(CMAKE_C_STANDARD 11)

add_executable(Race main.c driver.h driver.c raceScore.h raceScore.c file.h file.c)

#--------------------------copy pattern files to build folder---------------------------------

#add_custom_command(TARGET Race POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/*txt ${CMAKE_SOURCE_DIR}/cmake-build-*)