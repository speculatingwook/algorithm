cmake_minimum_required(VERSION 3.26)
project(algorithm)

set(CMAKE_CXX_STANDARD 17)



add_executable(algorithm main.c
        src/implementation/datastructure/linked_list/SingleListSample.c
        src/implementation/datastructure/linked_list/single_linked_list.c
        src/implementation/datastructure/stack/stack.c
        src/implementation/datastructure/queue/queue.c
        src/implementation/datastructure/linked_list/linked_list_from_class.cpp
        src/implementation/datastructure/stack/stack_from_class.c
        src/implementation/datastructure/queue/queue_from_class.c
)
