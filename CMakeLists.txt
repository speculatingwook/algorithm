cmake_minimum_required(VERSION 3.26)
project(algorithm)

set(CMAKE_CXX_STANDARD 17)


# 링커 옵션 설정
set(LINKER_FLAGS "-Wl,-image_base,0x16f8a7238")  # 원하는 시작 주소로 변경

add_executable(algorithm main.c
        src/implementation/SingleLinkedList/SingleListSample.c)

# 링커 옵션 적용
target_link_options(algorithm PRIVATE ${LINKER_FLAGS})