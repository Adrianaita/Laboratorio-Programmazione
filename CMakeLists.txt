cmake_minimum_required(VERSION 3.10)

project(MyNewToDoList)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GoogleTest 
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(myToDoList 
    main.cpp
    Date.cpp
    ToDo.cpp
    ToDoList.cpp
)


enable_testing()


add_executable(todo_tests
    test/test_date.cpp
    test/test_todo.cpp
    test/test_todolist.cpp
    
    Date.cpp
    ToDo.cpp
    ToDoList.cpp
)

# Dico ai test dove trovare i file .h
target_include_directories(todo_tests PRIVATE ${CMAKE_SOURCE_DIR})

# Collego GoogleTest
target_link_libraries(todo_tests gtest_main)

# Aggiungo il comando per eseguire i test
add_test(NAME AllTests COMMAND todo_tests)