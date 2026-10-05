cmake_minimum_required(VERSION 3.16)
project(ZooHotel LANGUAGES CXX)

add_executable(ZooHotel
    ZooHotel/ZooHotel.cpp
    ZooHotel/src/Banch.cpp
    ZooHotel/src/Pet.cpp
    ZooHotel/src/Owner.cpp
    ZooHotel/src/Utilities.cpp
)

target_compile_features(ZooHotel PRIVATE cxx_std_20)
if(MSVC)
    target_compile_options(ZooHotel PRIVATE /utf-8)
endif()
