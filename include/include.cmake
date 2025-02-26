# cmake responsible for agregating auxiliar functions and data structures to be used into one cmake file
 
set(INCLUDE_SOURCES      
    ${CMAKE_SOURCE_DIR}/include/structs.cpp 
    ${CMAKE_SOURCE_DIR}/include/vector_math.cpp 
    ${CMAKE_SOURCE_DIR}/include/extra_functions.cpp
)

set(INCLUDE_HEADERS    
    ${CMAKE_SOURCE_DIR}/include/structs.h  
    ${CMAKE_SOURCE_DIR}/include/vector_math.h  
    ${CMAKE_SOURCE_DIR}/include/extra_functions.h 
)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(INCLUDE_SOURCES ${INCLUDE_SOURCES} PARENT_SCOPE)
set(INCLUDE_HEADERS ${INCLUDE_HEADERS} PARENT_SCOPE)