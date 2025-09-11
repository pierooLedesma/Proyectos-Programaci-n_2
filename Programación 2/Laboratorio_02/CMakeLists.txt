cmake_minimum_required(VERSION 4.0)
project(Laboratorio_02)

set(CMAKE_CXX_STANDARD 20)

add_executable(Laboratorio_02 main.cpp
        Biblioteca/conductores.hpp
        Biblioteca/infracciones.hpp
        Biblioteca/faltas.hpp
        Biblioteca/Utils.hpp
        Biblioteca/Sobrecargas.cpp
        Biblioteca/Sobrecargas.hpp
        Biblioteca/FuncionesAuxiliares.cpp
        Biblioteca/FuncionesAuxiliares.hpp
        Biblioteca/Funciones.cpp
        Biblioteca/Funciones.hpp)
