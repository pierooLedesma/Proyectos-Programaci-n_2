cmake_minimum_required(VERSION 4.0)
project(Fuentes_Biblioteca_2024_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Fuentes_Biblioteca_2024_1 main.cpp
        Biblioteca/AperturaDeArchivos.hpp
        Biblioteca/Utils.h
        Biblioteca/Sobrecargas.cpp
        Biblioteca/Sobrecargas.hpp
        Biblioteca/Estructuras.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Biblioteca")

target_link_libraries(Fuentes_Biblioteca_2024_1 PRIVATE AperturaDeArchivos)
