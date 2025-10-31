cmake_minimum_required(VERSION 4.0)
project(Laboratorio_06)

set(CMAKE_CXX_STANDARD 20)

add_executable(Laboratorio_06 main.cpp
        Bibliotecas/Empresa.cpp
        Bibliotecas/Empresa.hpp
        Bibliotecas/Infraccion.cpp
        Bibliotecas/Infraccion.hpp
        Bibliotecas/Multa.cpp
        Bibliotecas/Multa.hpp
        Bibliotecas/MinisterioDeTransporte.cpp
        Bibliotecas/MinisterioDeTransporte.hpp)
