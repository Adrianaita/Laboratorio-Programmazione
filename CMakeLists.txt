cmake_minimum_required(VERSION 3.10)

project(MyNewToDoList)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ELENCO SOLO I FILE CHE ESISTONO ORA
add_executable(myToDoList 
    main.cpp
    Date.cpp
    #ToDo.cpp
)