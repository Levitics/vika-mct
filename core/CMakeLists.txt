include(CheckCCompilerFlag)
CHECK_C_COMPILER_FLAG("-std=gnu99" C_COMPILER_HAS_C99)
CHECK_C_COMPILER_FLAG("-std=gnu11" C_COMPILER_HAS_C11)
CHECK_C_COMPILER_FLAG("-Wall" C_COMPILER_HAS_WALL)
CHECK_C_COMPILER_FLAG("-Wextra" C_COMPILER_HAS_WEXTRA)
CHECK_C_COMPILER_FLAG("-Wno-unused-parameter" C_COMPILER_HAS_WNO_UNUSED_PARAMETER)
CHECK_C_COMPILER_FLAG("-Wno-missing-field-initializers" C_COMPILER_HAS_WNO_MISSING_FIELD_INITIALIZERS)
CHECK_C_COMPILER_FLAG("-fvisibility=hidden" C_COMPILER_HAS_FVISIBILITY)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)
CHECK_CXX_COMPILER_FLAG("-std=c++1y" COMPILER_SUPPORTS_CXX1Y)
CHECK_CXX_COMPILER_FLAG("-Wall" CXX_COMPILER_HAS_WALL)
CHECK_CXX_COMPILER_FLAG("-Wextra" CXX_COMPILER_WALL_HAS_WEXTRA)
CHECK_CXX_COMPILER_FLAG("-fvisibility=hidden" CXX_COMPILER_HAS_FVISIBILITY)
CHECK_CXX_COMPILER_FLAG("-fvisibility-inlines-hidden" CXX_COMPILER_HAS_FVISIBILITY_INLINE)

if(COMPILER_SUPPORTS_CXX1Y)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
elseif(COMPILER_SUPPORTS_CXX14)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
elseif(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 or later support. Please use a different C++ compiler.")
endif()
message( STATUS "Defaul CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE ON)
#if (CMAKE_SYSTEM_NAME STREQUAL GNU)
#    # Enable multithreading with the pthread library
#    # FIXME: Is this actually necessary to have here?
#    #        Can CMakeLists.txt files that require it use FindThreads.cmake
#    #        instead?
#    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pthread")
#    set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -pthread")
#endif()

#set(${PROJECT_NAME}Core_INCLUDE_DIRS /home/happyman/NetBeansProjects/didactics/core/src/main/cpp/didactics
#   CACHE INTERNAL "${PROJECT_NAME} Core: Include Directories" FORCE)
#
#set(${PROJECT_NAME}Core_INCLUDE_DIRS /home/happyman/NetBeansProjects/didactics/core/src/main/cpp/didactics
#   CACHE INTERNAL "${PROJECT_NAME} Core: Include Directories" FORCE)

#include_directories(SYSTEM
#        /home/happyman/NetBeansProjects/didactics/core/src/main/cpp/didactics
#        /home/happyman/NetBeansProjects/didactics/core/src/main/cpp/didactics/core
#        /home/happyman/NetBeansProjects/didactics/core/src/main/cpp/didactics/core/utils
#        /home/happyman/NetBeansProjects/didactics/core/src/test/cpp/didactics
#)

if(BUILD_COVERAGE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgcov")
endif()

add_subdirectory (src/main/cpp)
add_subdirectory (src/test/cpp)


