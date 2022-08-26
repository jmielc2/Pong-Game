cmake_minimum_required(VERSION 3.0)

set(CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

project(pong VERSION 1.0)

add_executable(${PROJECT_NAME} Main.cpp stdafx.cpp
    Controllers/App.cpp
)

add_subdirectory(external/SFML)

target_include_directories(${PROJECT_NAME} 
    PUBLIC external/SFML/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/external/SFML/lib/
)

target_link_libraries(${PROJECT_NAME}
    sfml-graphics sfml-system sfml-window
)

set(EXECUTABLE_OUTPUT_PATH ../bin)