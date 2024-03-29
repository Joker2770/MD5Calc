cmake_minimum_required(VERSION 3.5)

project(MD5Calc VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-D_UNICODE -DUNICODE)
# add_definitions(-DQSCINTILLA_MAKE_DLL)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# qscint 关键依赖库
add_subdirectory(${PROJECT_SOURCE_DIR}/qscint)

set(PROJECT_SOURCES
        MD5Calc_export.cpp
        widget.cpp
        widget.h
        instanceobj.cpp
                instanceobj.h
)

include_directories(
	${PROJECT_SOURCE_DIR}
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/qscint/src
	${PROJECT_SOURCE_DIR}/qscint/src/Qsci
	${PROJECT_SOURCE_DIR}/qscint/scintilla/src
	${PROJECT_SOURCE_DIR}/qscint/scintilla/include
	${PROJECT_SOURCE_DIR}/qscint/scintilla/lexlib
	${PROJECT_SOURCE_DIR}/qscint/scintilla/boostregex
)

add_library(${PROJECT_NAME} SHARED
            ${PROJECT_SOURCES}
)

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt${QT_VERSION_MAJOR}::Widgets qscint)

install(
        TARGETS ${PROJECT_NAME}
        DESTINATION "plugin"
)
