# CMake responsible for aggregating every game layer class into one cmake file

set(GAME_LAYER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/Game_Layers/Base/Base.cpp
)

set(GAME_LAYER_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/Game_Layers/Base/Base.h
)

# Add the include directory so the main code can find the headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libraries/Game_Layers/Base)

# Expose to the parent scope
set(GAME_LAYER_SOURCES ${GAME_LAYER_SOURCES} PARENT_SCOPE)
set(GAME_LAYER_HEADERS ${GAME_LAYER_HEADERS} PARENT_SCOPE)
