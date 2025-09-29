cmake_minimum_required(VERSION 4.0)
project(Laboratorio_05)

set(CMAKE_CXX_STANDARD 20)

add_executable(Laboratorio_05 main.cpp
        Bibliotecas/BibliotecaGenerica.cpp
        Bibliotecas/BibliotecaGenerica.h
        Bibliotecas/ListaConEnteros.cpp
        Bibliotecas/ListaConEnteros.h
        Bibliotecas/ListaConRegistros.cpp
        Bibliotecas/ListaConRegistros.h
        Bibliotecas/Utils.hpp)
