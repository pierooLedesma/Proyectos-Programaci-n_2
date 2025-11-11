cmake_minimum_required(VERSION 4.0)
project(Parte_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Parte_2 main.cpp
        Bibliotecas/Central.cpp
        Bibliotecas/Central.hpp
        Bibliotecas/Arbol.cpp
        Bibliotecas/Arbol.hpp
        Bibliotecas/Dron.cpp
        Bibliotecas/Dron.hpp
        Bibliotecas/DroneEstacionamiento.cpp
        Bibliotecas/DroneEstacionamiento.hpp
        Bibliotecas/DroneSemaforo.cpp
        Bibliotecas/DroneSemaforo.hpp
        Bibliotecas/DroneVelocidad.cpp
        Bibliotecas/DroneVelocidad.hpp
        Bibliotecas/Nodo.cpp
        Bibliotecas/Nodo.hpp
        Bibliotecas/Utils.hpp)
