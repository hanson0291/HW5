cmake_minimum_required(VERSION 3.10)
project(assignment_5_files)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
include_directories(2ndZIP/assignment_5_files_final)

add_executable(assignment_5_files
        2ndZIP/assignment_5_files_final/dij.cpp
        2ndZIP/assignment_5_files_final/graph.h
        2ndZIP/assignment_5_files_final/list.h
        2ndZIP/assignment_5_files_final/min_heap.h
        2ndZIP/assignment_5_files_final/set.h
        2ndZIP/assignment_5_files_final/stack.h
        dij.cpp
        generic_vector.h
        graph.h
        graph_1_nix.txt
        list.h
        min_heap.h
        set.h
        stack.h)
