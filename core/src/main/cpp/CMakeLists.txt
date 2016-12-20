include_directories(SYSTEM .)
set(CORE_SOURCES  
        didactics/core/exple/Turtle.cpp
        didactics/core/exple/Painter.cpp
        didactics/core/log/ColorStdOuputLogMsg.cpp
        didactics/core/log/Helpers.cpp
        didactics/core/log/Logger.cpp
)

include_directories(${LOG4CXX_INCLUDE_DIR})

add_library(${PROJECT_NAME}Core STATIC ${CORE_SOURCES})
target_link_libraries(${PROJECT_NAME}Core ${LOG4CXX_LIBRARIES})
#target_link_libraries(${PROJECT_NAME}Core log4cxx -L${LOG4CXX_LIBS_DIRECTORY})
