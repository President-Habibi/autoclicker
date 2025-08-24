cmake_minimum_required(VERSION 3.10)
project(autoclicker)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(MC_Autoclicker
	src/main.cpp
	src/mc_autoclicker.cpp)

# SDL headers
target_include_directories(MC_Autoclicker PRIVATE "C:\\C++ Libraries\\SDL3-3.2.16\\include")

# SDL libraries
target_link_directories(MC_Autoclicker PRIVATE "C:\\C++ Libraries\\SDL3-3.2.16\\lib\\x64")
target_link_libraries(MC_Autoclicker PRIVATE SDL3)
