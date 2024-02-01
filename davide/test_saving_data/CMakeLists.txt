cmake_minimum_required(VERSION 3.5)

project(testcmake2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_HOME_PATH $ENV{QT_PATH})
set(CMAKE_PREFIX_PATH "${QT_HOME_PATH}")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Quick QuickControls2)
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        view/mainview/SideBarWidget.cpp
        view/mainview/SideBarWidget.h
        view/mainview/MainContentWidget.cpp
        view/mainview/MainContentWidget.h
        view/mainview/ModifyView.cpp
        view/mainview/ModifyView.h
        view/mainview/CreateView.cpp
        view/mainview/CreateView.h
        view/mainview/ViewAbstract.cpp
        view/mainview/ViewAbstract.h
        view/mainview/ContainerManagerAbstract.cpp
        view/mainview/ContainerManagerAbstract.h
        myclass.cpp
        myclass.h
        myclass2.cpp
        myclass2.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(testcmake2
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET testcmake2 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(testcmake2 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(testcmake2
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(testcmake2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.testcmake2)
endif()
set_target_properties(testcmake2 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS testcmake2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(testcmake2)
endif()
