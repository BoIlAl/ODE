cmake_minimum_required(VERSION 3.5)

project(ODE LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

file(GLOB CODE_SRC "./src/*.cpp")
file(GLOB UI_SRC "./ui/*.ui")


qt5_wrap_ui(UI_HEADERS ${UI_SRC})

add_executable(ODE
  ${UI_HEADERS}
  ${CODE_SRC}
)

target_link_libraries(ODE PRIVATE Qt5::Widgets)
 