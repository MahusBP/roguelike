cmake_minimum_required(VERSION 3.7)
project(roguelike)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/Game/header/IScene.h src/Game/source/Button.cpp src/Game/header/Button.h src/Game/source/scene/MainMenu.cpp src/Game/header/scene/MainMenu.h src/Game/source/Settings.cpp src/Game/header/Settings.h src/MhsFloat.h src/Game/source/System.cpp src/Game/header/System.h src/Game/EventManager.cpp src/Game/EventManager.h src/Game/header/IEventListener.h src/Game/GameScene.cpp src/Game/GameScene.h src/Game/Player.cpp src/Game/Player.h src/Game/LevelObject.cpp src/Game/LevelObject.h src/Game/ObjectType.h)
add_executable(roguelike ${SOURCE_FILES})

# SFML
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(roguelike ${SFML_LIBRARIES})
endif()