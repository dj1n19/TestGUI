cmake_minimum_required(VERSION 3.25.1)
project(TestGUI VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# project(TestGUI)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(HEADER_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/includes)

include_directories(${HEADER_DIRS})

qt_wrap_cpp(INCLUDES
    includes/ability.hpp
    includes/astat.hpp
    includes/characterbuilderform.hpp
    includes/character.hpp
    includes/charactersheetwidget.hpp
    includes/characterlistwidget.hpp
    includes/characterlistitem.hpp
    includes/player.hpp
    includes/savingthrow.hpp
    includes/skill.hpp
    includes/mainwindow.hpp
)

qt_add_executable(TestGUI
    srcs/main.cpp
    srcs/ability.cpp
    srcs/astat.cpp
    srcs/character.cpp
    srcs/characterbuilderform.cpp
    srcs/charactersheetwidget.cpp
    srcs/characterlistwidget.cpp
    srcs/characterlistitem.cpp
    srcs/player.cpp
    srcs/savingthrow.cpp
    srcs/skill.cpp
    srcs/mainwindow.cpp
    ${INCLUDES}
)

target_link_libraries(TestGUI PRIVATE Qt6::Widgets)
    