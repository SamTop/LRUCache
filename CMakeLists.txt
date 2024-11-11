cmake_minimum_required(VERSION 3.27)
project(xm_task)

set(CMAKE_CXX_STANDARD 20)

add_executable(xm_task
    main.cpp
    LRUCache.h
    Product.h
    ProductDatabase.h
    ProductService.h
)
