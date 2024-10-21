cmake_minimum_required(VERSION 3.29)
project(PL1)

set(CMAKE_CXX_STANDARD 20)

add_executable(PL1 main.cpp
        "Planificador de procesos/Proceso.cpp"
        "Planificador de procesos/Pila.cpp"
        "Planificador de procesos/NodoPila.cpp"
        "Planificador de procesos/Nucleo.cpp"
        "Planificador de procesos/NodoCola.cpp"
        "Planificador de procesos/global.cpp"
        "Planificador de procesos/Cola.cpp")
