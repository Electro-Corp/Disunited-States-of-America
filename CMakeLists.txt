cmake_minimum_required(VERSION 3.12)

project(nunticle)

# Compiler settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#SFML
find_package(SFML REQUIRED COMPONENTS graphics window system)

# Include directories
include_directories(src)
include_directories(${SFML_INCLUDE_DIR})

# Compiler executable
add_executable(nunticle
    src/main.cpp
    src/graphics/renderer.cpp
    src/game.cpp
)

target_link_libraries(nunticle ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} sfml-graphics)