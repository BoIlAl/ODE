cmake_minimum_required(VERSION 3.0.0)
project(test VERSION 0.1.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

file(GLOB CODE_SRC "./app/*.cpp" "./app/project/*.cpp" "./app/grammar/*.cpp")
file(GLOB UI_SRC "./ui/*.ui")

qt5_wrap_ui(UI_HEADERS ${UI_SRC})

include_directories(
  ${PROJECT_SOURCE_DIR}/app
  ${PROJECT_SOURCE_DIR}/app/grammar
  ${PROJECT_SOURCE_DIR}/app/project
  ${PROJECT_SOURCE_DIR}/ui

  ${PROJECT_SOURCE_DIR}/runtime/runtime/src
  ${PROJECT_SOURCE_DIR}/runtime/runtime/src/atn
  ${PROJECT_SOURCE_DIR}/runtime/runtime/src/dfa
  ${PROJECT_SOURCE_DIR}/runtime/runtime/src/misc
  ${PROJECT_SOURCE_DIR}/runtime/runtime/src/support
  ${PROJECT_SOURCE_DIR}/runtime/runtime/src/tree
  ${PROJECT_SOURCE_DIR}/runtime/runtime/src/tree/pattern
  ${PROJECT_SOURCE_DIR}/runtime/runtime/src/tree/xpath
)

add_executable(test ${CODE_SRC} ${UI_HEADERS})

add_definitions(-DQT_NO_KEYWORDS)

target_link_libraries(test PRIVATE Qt5::Widgets)
target_link_libraries(test PRIVATE Qt5::Core)
target_link_libraries(test PRIVATE ${PROJECT_SOURCE_DIR}/runtime/dist/libantlr4-runtime.dll.a)