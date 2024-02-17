cmake_minimum_required(VERSION 3.16)
project(Arkanoid LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Arkanoid
    src/Main.cpp
    src/Game.cpp
    src/Window.cpp
    src/World.cpp
    src/Player.cpp
    src/Hud.cpp
    src/Textbox.cpp
)

target_link_libraries(Arkanoid PRIVATE sfml-graphics)
target_compile_features(Arkanoid PRIVATE cxx_std_17)

install(TARGETS Arkanoid)
