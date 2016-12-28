include_directories(SYSTEM .)
set(CORE_SOURCES  
        didactics/core/exple/Turtle.cpp
        didactics/core/exple/Painter.cpp
        didactics/core/exple/Timer.cpp
        didactics/core/log/ColorStdOuputLogMsg.cpp
        didactics/core/log/Helpers.cpp
        didactics/core/log/Logger.cpp
        didactics/core/osal/Semaphore.cpp
        didactics/core/errorhandling/Expected.cpp
)

include_directories(${LOG4CXX_INCLUDE_DIR})

add_library(${PROJECT_NAME}Core STATIC ${CORE_SOURCES})
target_link_libraries(${PROJECT_NAME}Core ${LOG4CXX_LIBRARIES})

#if(ENABLE_CPPLINT)
#    CPPLINT_RECURSIVE(
#        ${PROJECT_NAME}CoreLint                              #target_name.The name of the target to define. Your program should depend on it to invoke cpplint.
#        ${CMAKE_CURRENT_SOURCE_DIR}/didactics/core           #src_folder.The folder to recursively run cpplint.
#        ${CORE_MODULE_ROOT_DIRECTORY}                        #root_folder.The root folder used to determine desired include-guard comments.
#        "${TARGET_BUILD_DIRECTORY}/lint/${PROJECT_NAME}Core" #bin_folder.The temporary build folder to store a cpplint history file.
#    )
#endif(ENABLE_CPPLINT)

#target_link_libraries(${PROJECT_NAME}Core log4cxx -L${LOG4CXX_LIBS_DIRECTORY})

