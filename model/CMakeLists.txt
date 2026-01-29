find_package(Qt6 REQUIRED COMPONENTS Concurrent)

add_library(model STATIC
    ./fractals/MandelbrotFractal.cpp
    ./render/Camera.cpp
    ./render/GrayScaleColorScheme.cpp
    ./render/Image.cpp
    ./render/Renderer.cpp
    ./fractals/JuliaFractal.cpp
)
target_link_libraries(model PUBLIC
    Qt6::Concurrent
)

target_include_directories(model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(model PUBLIC cxx_std_23)
