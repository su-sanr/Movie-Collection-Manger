cmake_minimum_required(VERSION 3.19)
project(Movie_Collection_Manager LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core)

qt_standard_project_setup()

qt_add_executable(Movie_Collection_Manager
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    movie.h
    repository.h
    movie.cpp
    csv_repository.h
    csv_repository.cpp
    json_repository.h
    json_repository.cpp
    command.h
    controller.h
    movie_commands.h
    controller.cpp
    filter.h
    concrete_filters.h
    logical_filters.h
)

target_link_libraries(Movie_Collection_Manager
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS Movie_Collection_Manager
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Movie_Collection_Manager
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
