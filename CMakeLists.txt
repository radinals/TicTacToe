cmake_minimum_required(VERSION 3.2)

project(
  TicTacToe
  VERSION 0.0
  DESCRIPTION "Basic TicTacToe Game"
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(TicTacToe
  src/main.cpp

  src/Lib/Color.cpp
  src/Lib/Game.cpp
  src/Lib/Point.cpp
  src/Lib/PointF.cpp
  src/Lib/Rect.cpp
  src/Lib/RectF.cpp
  src/Lib/Renderer.cpp
  src/Lib/Size.cpp
  src/Lib/Window.cpp

  src/TicTacToe/TicTacToe.hpp
  src/TicTacToe/TicTacToe.cpp

)

target_link_libraries(TicTacToe ${SDL2_LIBRARIES})
