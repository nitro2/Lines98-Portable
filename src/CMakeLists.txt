
list(APPEND COMMON_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/game.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ball.cpp
)

add_library(CoreGame ${COMMON_SOURCES})

target_include_directories(CoreGame
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
    PUBLIC "${SFML_SOURCE_DIR}/include"
)