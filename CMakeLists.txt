cmake_minimum_required(VERSION 3.12)

project(nunticle)

# Compiler settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SFML
find_package(SFML REQUIRED COMPONENTS graphics window system)
# LUA
find_package(Lua51 REQUIRED)

# Include directories
include_directories(src)
include_directories(${SFML_INCLUDE_DIR})    
include_directories(/usr/local/include ${LUA_INCLUDE_DIR})

# Compiler executable
add_executable(nunticle
    # Sprite
    src/graphics/sprite.h
    src/graphics/sprite.cpp
    # scripting
    src/scripting/scriptmanager.cpp
    # engine
    src/transform.cpp
    src/gameobject.cpp
    src/scene.cpp
    # nunticle  
    src/game.cpp
    # graphics
    src/graphics/renderer.cpp
    # objects
    src/gameObjects/boat.cpp
    src/gameObjects/map.cpp
    # main
    src/main.cpp
)


# Flags
target_compile_options(nunticle PUBLIC -fpermissive -g)

target_link_libraries(nunticle ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} sfml-graphics)
target_link_libraries(nunticle ${LUA_LIBRARIES} ${LUA_DEPENDENCIES})