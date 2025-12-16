cmake_minimum_required(VERSION 3.10)
project(Lab_7-8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(prog
  src/main.cpp
  src/PCB.cpp
  src/ListNode.cpp
  src/ProcessList.cpp
)

include_directories(src)