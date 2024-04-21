cmake_minimum_required(VERSION 3.26)
project(algorithm)

set(CMAKE_CXX_STANDARD 17)



add_executable(algorithm main.c
        src/implementation/SingleLinkedList/SingleListSample.c
        src/implementation/SingleLinkedList/SingleList.c
        src/implementation/stack/StackPractice.c
)
