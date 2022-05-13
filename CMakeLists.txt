cmake_minimum_required(VERSION 3.21)
project(File_directory_system)

set(CMAKE_CXX_STANDARD 14)

add_executable(File_directory_system main.cpp
        kernel/FCB/FCB.cpp kernel/FCB/FCB.h
        kernel/Directory_Tree/Directory_Tree.cpp kernel/Directory_Tree/Directory_Tree.h
        kernel/Indexing_Node/Indexing_Node.cpp kernel/Indexing_Node/Indexing_Node.h
        Interface/Interface.cpp Interface/Interface.h)
