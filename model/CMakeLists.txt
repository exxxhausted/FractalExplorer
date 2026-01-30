find_package(Qt6 REQUIRED COMPONENTS Concurrent Gui)

add_library(model STATIC
    ./fractals/MandelbrotFractal.cpp
    ./render/Camera.cpp
    ./render/GrayScaleColorScheme.cpp
    ./render/Renderer.cpp
    ./fractals/JuliaFractal.cpp

)
target_link_libraries(model PUBLIC
    Qt6::Concurrent
    Qt6::Gui
)

target_include_directories(model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(model PUBLIC cxx_std_23)
