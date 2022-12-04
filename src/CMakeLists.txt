
list(APPEND COMMON_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/game.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ball.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/map.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/a_star.cpp
)

add_library(CoreGame ${COMMON_SOURCES})

target_include_directories(CoreGame
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
    PUBLIC "${SFML_SOURCE_DIR}/include"
    PUBLIC "${SFML_BIN_DIR}"
)

message("nngodebug ${SFML_SOURCE_DIR}/include")