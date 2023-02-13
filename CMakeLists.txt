option(USE_SDL "USE SDL" OFF)

if(USE_SDL)
  add_definitions(-DUSE_SDL)
  message(STATUS "SDL")
endif()

cmake_minimum_required(VERSION 3.4...3.18)
project(fastsim)

find_package(pybind11)
find_library(LIB_FASTSIM libfastsim.a)
set (PYBIND11_PYTHON_VERSION "3.10")
pybind11_add_module(fastsim src/python/fastsim.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_FASTSIM})
