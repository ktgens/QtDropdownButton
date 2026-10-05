cmake_minimum_required(VERSION 3.14)
project(Qt5MacApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(Qt5_DIR "/opt/homebrew/opt/qt@5/lib/cmake/Qt5")


find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(Qt5MacApp 
main.cpp
StateButton.cpp
StateButton.h
resources.qrc
)

target_link_libraries(Qt5MacApp PRIVATE Qt5::Widgets)
