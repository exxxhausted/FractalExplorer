find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_executable(fractal-explorer
    main.cpp

)

target_link_libraries(fractal-explorer PRIVATE
            Qt6::Widgets
            Qt6::Core
            model
            controller
            view
)

target_compile_features(fractal-explorer PRIVATE cxx_std_20)
