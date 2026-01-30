find_package(Qt6 REQUIRED COMPONENTS Core Gui)

add_library(controller STATIC
    ./FractalExplorerController.cpp
)

target_link_libraries(model PUBLIC
    Qt6::Core
    Qt6::Gui
)

target_include_directories(controller
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(controller
    PUBLIC model
)

target_compile_features(controller PUBLIC cxx_std_23)
