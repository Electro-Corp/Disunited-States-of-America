cmake_minimum_required(VERSION 3.12)

project(DSA)

# Compiler settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SFML
find_package(SFML REQUIRED COMPONENTS graphics window system audio)
# LUA
find_package(Lua51 REQUIRED)
# JSONCPP
find_package(jsoncpp REQUIRED)

# Include directories
include_directories(src)
include_directories(${SFML_INCLUDE_DIR})    
include_directories(/usr/local/include ${LUA_INCLUDE_DIR})
include_directories(${JSONCPP_INCLUDE_DIR})

# Compiler executable
add_executable(DSA
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
    src/gameObjects/county.cpp
    src/gameObjects/boat.cpp
    src/gameObjects/map.cpp
    # ui
    src/gameObjects/ui/text.cpp
    # utils
    src/utils/jsonReader.cpp
    src/utils/stateColor.cpp
    # main
    src/main.cpp
)


# Flags
target_compile_options(DSA PUBLIC -fpermissive -g -O2)

target_link_libraries(DSA ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} sfml-graphics sfml-audio)
target_link_libraries(DSA ${LUA_LIBRARIES} ${LUA_DEPENDENCIES})
TARGET_LINK_LIBRARIES(DSA jsoncpp_lib)