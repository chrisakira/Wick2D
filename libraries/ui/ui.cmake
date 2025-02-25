# cmake responsible for agregating every ui class into one cmake file
  
set(UI_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/ui/platform/glfwMain.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/ui/platform/platformInput.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/ui/platform/errorReporting.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/ui/platform/opterPlatformFunctions.cpp
)

set(UI_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/ui/platform/platformTools.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/ui/platform/platformInput.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/ui/platform/errorReporting.h  
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/ui/platform/otherPlatformFunctions.h 
)

# Add the include directory so the main code can find the headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libraries/ui/platform)

# Expose to the parent scope
set(UI_HEADERS ${UI_HEADERS} PARENT_SCOPE)
set(UI_SOURCES ${UI_SOURCES} PARENT_SCOPE)
 