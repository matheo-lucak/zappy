cmake_minimum_required(VERSION 3.11)

project(Zappy VERSION 0.1
                    LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "-Wall -O0 -g")

include(cmake/Findraylib.cmake)
add_subdirectory(deps)
find_package(SFML 2.5.1 COMPONENTS network REQUIRED)

#### Engine Static Library ####

add_library(Engine  STATIC
                    libs/Engine/Core/Exceptions/ArgumentHelpException.cpp
                    libs/Engine/Core/Exceptions/ArgumentParsingError.cpp
                    libs/Engine/Core/Application.cpp
                    libs/Engine/Core/Scene.cpp
                    libs/Engine/Core/SceneManager.cpp
                    libs/Engine/Core/SceneManagerInternal.cpp
                    libs/Engine/Core/Time.cpp
                    libs/Engine/ECS/Components/Animator.cpp
                    libs/Engine/ECS/Components/BoxCollider.cpp
                    libs/Engine/ECS/Components/Button.cpp
                    libs/Engine/ECS/Components/Drawable.cpp
                    libs/Engine/ECS/Components/Image.cpp
                    libs/Engine/ECS/Components/Model.cpp
                    libs/Engine/ECS/Components/MusicPlayer.cpp
                    libs/Engine/ECS/Components/SoundPlayer.cpp
                    libs/Engine/ECS/Components/Text.cpp
                    libs/Engine/ECS/Components/Transform.cpp
                    libs/Engine/ECS/GameObject.cpp
                    libs/Engine/Graphics/Exceptions/ResourceInitialization.cpp
                    libs/Engine/Graphics/AudioContext.cpp
                    libs/Engine/Graphics/Camera.cpp
                    libs/Engine/Graphics/Cube.cpp
                    libs/Engine/Graphics/Font.cpp
                    libs/Engine/Graphics/Image.cpp
                    libs/Engine/Graphics/Input.cpp
                    libs/Engine/Graphics/Line2D.cpp
                    libs/Engine/Graphics/Line3D.cpp
                    libs/Engine/Graphics/Mesh.cpp
                    libs/Engine/Graphics/Model.cpp
                    libs/Engine/Graphics/ModelAnimator.cpp
                    libs/Engine/Graphics/Mouse.cpp
                    libs/Engine/Graphics/Music.cpp
                    libs/Engine/Graphics/Pixel.cpp
                    libs/Engine/Graphics/Plane.cpp
                    libs/Engine/Graphics/RectangularPrism.cpp
                    libs/Engine/Graphics/Sound.cpp
                    libs/Engine/Graphics/Sphere.cpp
                    libs/Engine/Graphics/Text.cpp
                    libs/Engine/Graphics/Texture2D.cpp
                    libs/Engine/Graphics/Touch.cpp
                    libs/Engine/Graphics/Triangle3D.cpp
                    libs/Engine/Graphics/Window.cpp
                    libs/Engine/Graphics/WiredCube.cpp
                    libs/Engine/Graphics/WiredRectangularPrism.cpp
                    libs/Engine/Graphics/WiredSphere.cpp
                    libs/Engine/Utils/deserializer/component.cpp
                    libs/Engine/Utils/deserializer/object.cpp
                    libs/Engine/Utils/deserializer/scene.cpp
                    libs/Engine/Utils/deserializer/sceneConf.cpp
                    libs/Engine/Utils/deserializer/script.cpp
                    libs/Engine/Utils/Clock.cpp
                    libs/Engine/Utils/Color.cpp
                    libs/Engine/Utils/Grid3.cpp
                    libs/Engine/Utils/Grid3Cell.cpp
                    )

target_link_libraries(Engine raylib)
target_link_libraries(Engine nlohmann-json)
target_include_directories(Engine PUBLIC
    libs/Engine
    libs/Engine/Core/Exceptions
    libs/Engine/Core
    libs/Engine/ECS
    libs/Engine/ECS/Components
    libs/Engine/Graphics
    libs/Engine/Graphics/Exceptions
    libs/Engine/Utils
    )

#### Zappy GUI ####

add_executable( zappy_gui src/App.cpp
                          src/zappy/scripts/net/NetworkManager.cpp
                          src/zappy/scripts/net/Request.cpp
                          src/zappy/scripts/net/Response.cpp
                          src/zappy/scripts/resources/Inventory.cpp
                          src/zappy/scripts/Drone.cpp
                          src/zappy/scripts/Egg.cpp
                          src/zappy/scripts/handlers.cpp
                          src/zappy/scripts/Incantation.cpp
                          src/zappy/scripts/Map.cpp
                          src/zappy/scripts/SoundHandler.cpp
                          src/zappy/scripts/Tile.cpp
                          )

target_link_libraries(zappy_gui raylib)
target_link_libraries(zappy_gui Engine)
target_link_libraries(zappy_gui sfml-network)

target_include_directories(zappy_gui PUBLIC src)
target_include_directories(zappy_gui PUBLIC src/zappy/scripts)
target_include_directories(zappy_gui PUBLIC libs/Engine)
