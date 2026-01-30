cmake_minimum_required(VERSION 3.16)

project(FractalExplorer VERSION 0.3 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(model)
add_subdirectory(controller)
add_subdirectory(view)
add_subdirectory(app)
