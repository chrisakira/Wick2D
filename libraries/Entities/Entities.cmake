# cmake responsible for agregating every entity class into one cmake file
# entities.cmake

# Adiciona os arquivos de entidade
set(ENTITY_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/Entities/Base_Entity/Base_Entity.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/Entities/Square_Entity/Square_Entity.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/Entities/Main_Entity/Main_Entity.cpp 
)

set(ENTITY_HEADERS 
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/Entities/Base_Entity/Base_Entity.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/Entities/Square_Entity/Square_Entity.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/Entities/Main_Entity/Main_Entity.h
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libraries/Entities/Base_Entity)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libraries/Entities/Square_Entity)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libraries/Entities/Main_Entity)

# Exp�e a vari�vel para o projeto principal
set(ENTITY_SOURCES ${ENTITY_SOURCES} PARENT_SCOPE)
set(ENTITY_HEADERS ${ENTITY_HEADERS} PARENT_SCOPE)