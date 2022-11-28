cmake_minimum_required(VERSION 3.10)

set(ProjectName Lines98)
# set the project name and version
project("${ProjectName}" VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(BUILD_SHARED_LIBS OFF)
# configure a header file to pass some of the CMake settings
# to the source code
configure_file(Config.h.in Config.h)


# add the SFML library

add_subdirectory(SFML)

list(APPEND EXTRA_LIBS
        sfml-window
        sfml-system
        sfml-graphics
    )
list(APPEND EXTRA_INCLUDES 
    "${PROJECT_SOURCE_DIR}/SFML" 
    "${PROJECT_SOURCE_DIR}/SFML/include"
    )


# add the executable
add_executable("${ProjectName}" main.cpp)

target_link_libraries("${ProjectName}" PUBLIC ${EXTRA_LIBS})

target_include_directories("${ProjectName}" 
    PUBLIC "${PROJECT_SOURCE_DIR}"
    PUBLIC ${EXTRA_INCLUDES}
    )
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories("${ProjectName}" 
                            PUBLIC "${PROJECT_BINARY_DIR}"
                           )
