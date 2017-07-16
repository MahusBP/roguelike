cmake_minimum_required(VERSION 3.7)
project(roguelike)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/header/IScene.h src/source/Button.cpp src/header/Button.h src/source/scene/MainMenu.cpp src/header/scene/MainMenu.h src/source/Settings.cpp src/header/Settings.h)
add_executable(roguelike ${SOURCE_FILES})

# SFML
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(roguelike ${SFML_LIBRARIES})
endif()