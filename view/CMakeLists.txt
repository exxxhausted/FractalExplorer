find_package(Qt6 REQUIRED COMPONENTS Widgets Concurrent)

add_library(view STATIC
    QtFractalExplorerView.cpp
)

target_include_directories(view
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(view PUBLIC
    Qt6::Widgets
    Qt6::Concurrent
    model
)

target_compile_features(view PUBLIC cxx_std_23)
