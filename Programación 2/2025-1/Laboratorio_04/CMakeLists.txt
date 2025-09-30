cmake_minimum_required(VERSION 4.0)
project(Laboratorio_04)

set(CMAKE_CXX_STANDARD 20)

add_executable(Laboratorio_04 main.cpp
        Bibliotecas/Utils.hpp
        Bibliotecas/BibliotecaGenerica.cpp
        Bibliotecas/BibliotecaGenerica.h
        Bibliotecas/BibliotecaRegistros.cpp
        Bibliotecas/BibliotecaRegistros.h
        Bibliotecas/BibliotecaEnteros.cpp
        Bibliotecas/BibliotecaEnteros.h)
