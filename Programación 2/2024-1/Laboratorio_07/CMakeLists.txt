cmake_minimum_required(VERSION 4.0)
project(Laboratorio_07)

set(CMAKE_CXX_STANDARD 20)

add_executable(Laboratorio_07 main.cpp
        Bibliotecas/Libro.cpp
        Bibliotecas/Libro.hpp
        Bibliotecas/Enciclopedia.cpp
        Bibliotecas/Enciclopedia.hpp
        Bibliotecas/Novela.cpp
        Bibliotecas/Novela.hpp
        Bibliotecas/Espacio.cpp
        Bibliotecas/Espacio.hpp
        Bibliotecas/Estante.cpp
        Bibliotecas/Estante.hpp
        Bibliotecas/EstanteVertical.cpp
        Bibliotecas/EstanteVertical.hpp
        Bibliotecas/EstanteHorizontal.cpp
        Bibliotecas/EstanteHorizontal.hpp
        Bibliotecas/Biblioteca.hpp
        Bibliotecas/Biblioteca.cpp)
