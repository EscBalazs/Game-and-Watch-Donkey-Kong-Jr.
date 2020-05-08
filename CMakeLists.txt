cmake_minimum_required(VERSION 3.10)
project(Qt-CMake-HelloWorld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "D:\\Qt\\5.14.2\\mingw73_64")

find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(dkj main.cpp game.cpp monkey.cpp monkeyfallevent.cpp monkeymovehandler.cpp bird.cpp birdevent.cpp)
target_link_libraries(dkj Qt5::Widgets)
