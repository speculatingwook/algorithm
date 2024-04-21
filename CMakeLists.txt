cmake_minimum_required(VERSION 3.26)
project(algorithm)

set(CMAKE_CXX_STANDARD 17)



add_executable(algorithm main.c
        src/implementation/datastructure/SingleListSample.c
        src/implementation/datastructure/SingleList.c
        src/implementation/datastructure/stack.c
        src/implementation/datastructure/queue.c
)
