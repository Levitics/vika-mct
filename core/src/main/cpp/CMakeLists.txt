include_directories(SYSTEM .)
set(CORE_SOURCES  
        didactics/core/Version.cpp
        didactics/core/exple/Turtle.cpp
        didactics/core/exple/Painter.cpp
        didactics/core/exple/Timer.cpp
        didactics/core/exple/BaseOfFiveDefaults.cpp
        didactics/core/exple/BaseOfFiveDelete.cpp
        didactics/core/exple/CallbackHandler.cpp
        didactics/core/log/ColorStdOuputLogMsg.cpp
        didactics/core/log/Helpers.cpp
        didactics/core/log/Logger.cpp
        didactics/core/osal/Semaphore.cpp
        didactics/core/osal/ScopeGuard.cpp
        didactics/core/errorhandling/Expected.cpp
        didactics/core/errorhandling/ErrnoMapper.cpp
        didactics/core/errorhandling/Exceptions.cpp
        didactics/core/chronos/Timestamp.cpp
        didactics/core/chronos/Clocker.cpp
        didactics/core/chronos/Timerseries.cpp
        didactics/core/chronos/ClockerStatistics.cpp
        didactics/core/chronos/HighResolutionTimer.cpp
        didactics/core/chronos/Time.cpp
        didactics/core/utils/Object.cpp
        didactics/core/utils/Singleton.cpp
        didactics/core/utils/AsyncTasks.cpp
        didactics/core/utils/SpinLock.cpp
#        didactics/core/platform/linux/SystemInfo.cpp
        didactics/core/platform/linux/ResourceUsage.cpp
        didactics/core/platform/linux/ResourceManager.cpp
        didactics/core/platform/linux/ResourceLimit.cpp
        didactics/core/utils/observable/Collection.cpp
        didactics/core/utils/observable/SharedSubscription.cpp
        didactics/core/utils/observable/UniqueSubscription.cpp
#        didactics/core/utils/observable/Subject.cpp
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

