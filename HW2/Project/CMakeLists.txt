cmake_minimum_required(VERSION 3.12)
project(Project)

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_HEADERS
        NgramTree.h
        BinarySearchTree.h
        KeyedItem.h
        TreeNode.h
        )
set(PROJECT_SOURCES
        main.cpp
        BinarySearchTree.cpp
        KeyedItem.cpp
        NgramTree.cpp
        TreeNode.cpp
        )

add_executable(hw2 ${PROJECT_SOURCES} ${PROJECT_HEADERS})