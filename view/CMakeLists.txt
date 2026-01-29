find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_library(view STATIC
    QtFractalExplorerView.cpp
)

target_include_directories(view
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(view PUBLIC
    Qt6::Widgets
    model
)

target_compile_features(view PUBLIC cxx_std_23)
