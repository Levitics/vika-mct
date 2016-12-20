cmake_minimum_required(VERSION 3.7)
project (${PROJECT_NAME})

#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE ON)
#set(CMAKE_RULE_MESSAGES ON)

option(BUILD_COVERAGE "Build the project with GCOV support" OFF)
option(BULLS_EYE_COVERAGE "Build the project with BULLSEYE" OFF)
option(COVERITY_COVERAGE "Build the project with COVERITY" OFF)

if((NOT PROJECT_NAME))
    message(FATAL_ERROR "Project name must be specified!")
endif ((NOT PROJECT_NAME))

if(${PROJECT_NAME} MATCHES " ")
    message(FATAL_ERROR "Project name cannot contain spaces!")
endif(${PROJECT_NAME} MATCHES " ")

list(APPEND CMAKE_MODULE_PATH 
    "${CMAKE_SOURCE_DIR}/src/main/resources/modules"
    "${CMAKE_SOURCE_DIR}/src/main/resources/toolChains"
    "${CMAKE_SOURCE_DIR}/src/main/resources/macros"
    "${CMAKE_SOURCE_DIR}/src/main/resources/config"
    "${CMAKE_SOURCE_DIR}/src/test/resources/moduleTest")

#set(CMAKE_CXX_FLAGS_SHARED "-Wall -Wpedantic -fPIC -DPIC -std=c++1y -fno-strict-aliasing -funroll-loops -I${CMAKE_CURRENT_SOURCE_DIR}")
#include(aol)

#add_custom_command(TARGET ${target_name} 
#    PRE_BUILD 
#    COMMAND ${CMAKE_COMMAND} -E make_directory ${directory}
#)
message( STATUS " TRIPLETE(AOL) ${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_CXX_COMPILER_ID}-${CMAKE_HOST_SYSTEM_NAME}-GCC_${CMAKE_CXX_COMPILER_VERSION}-${CMAKE_BUILD_TYPE}")
#set(CMAKE_BINARY_DIR ${AOL})
set(TARGET_BUILD_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_INSTALL_PREFIX ${TARGET_BUILD_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#To create a directory when CMake generates the build system,
#file(MAKE_DIRECTORY ${AOL})

include(DefinePlatformSpecifc)
include(PreventInSourceBuilds) 

include_directories(SYSTEM  ${TARGET_BUILD_DIRECTORY}/include)
include_directories (SYSTEM ${CMAKE_BINARY_DIR}/include)
link_directories(${TARGET_BUILD_DIRECTORY}/lib)

#message( STATUS " link lib ${TARGET_BUILD_DIRECTORY}/lib")
#message( STATUS "CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}")

ADD_CUSTOM_TARGET(${PROJECT_NAME}-debug
  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
  COMMENT "Switch CMAKE_BUILD_TYPE to Debug"
)

ADD_CUSTOM_TARGET(${PROJECT_NAME}-release
  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
  COMMENT "Switch CMAKE_BUILD_TYPE to Release"
)

#file(MAKE_DIRECTORY
#  ${TARGET_BUILD_DIRECTORY}${CONIFG_DIR}
#)
 
#install(FILES /home/happyman/NetBeansProjects/didactics/src/main/resources/config/log4cxx.xml
#        DESTINATION ${TARGET_BUILD_DIRECTORY}${CONIFG_DIR}
#)

include(ProcessorCount)
ProcessorCount(Ncpu)
if(NOT Ncpu EQUAL 0)
    #set(MAKECOMMAND -j${N} ${MAKECOMMAND_DEFAULT_VALUE})
    #set(MAKEFLAGS  -j${N})
    #set(CTEST_BUILD_FLAGS -j${N}) 
    #set (CMAKE_MAKE_PROGRAM "${CMAKE_MAKE_PROGRAM} -j${N}") 
    message(STATUS "CMAKE_MAKE_PROGRAM Building with Processor Count: ${CMAKE_MAKE_PROGRAM} -j${Ncpu}")
endif()

add_subdirectory (external)

add_definitions(-DCONIFG_DIR="/etc/cfg")

find_package(Lcov)
find_package(CPPUNIT)
find_package(GoogleMock)
find_package(EXPAT)
find_package(APR)
find_package(APR-UTIL)
find_package(Log4cxx)

set(MAIN_LIBRARIES "")
set(TEST_LIBRARIES "")

#list(APPEND MAIN_LIBRARIES log4cxx -L${LOG4CXX_LIBS_DIRECTORY})
#list(APPEND MAIN_LIBRARIES apr-1 -L${APR_LIBS_DIRECTORY})
#list(APPEND MAIN_LIBRARIES aprutil-1 -L${APR_UTIL_LIBS_DIRECTORY})
#list(APPEND MAIN_LIBRARIES expat -L${EXPAT_LIBS_DIRECTORY})
#list(APPEND TEST_LIBRARIES ${MAIN_LIBRARIES} ${GOOGLEMOCK_LIBRARIES} -L${GOOGLEMOCK_INCLUDE_DIR})
#list(APPEND TEST_LIBRARIES ${CPPUNIT_LIBRARIE} -L${CPPUNIT_INCLUDE_DIR})
list(APPEND MAIN_LIBRARIES log4cxx )
list(APPEND MAIN_LIBRARIES apr-1 )
list(APPEND MAIN_LIBRARIES aprutil-1)
list(APPEND MAIN_LIBRARIES expat )
list(APPEND TEST_LIBRARIES ${MAIN_LIBRARIES} ${GOOGLEMOCK_LIBRARIES})
list(APPEND TEST_LIBRARIES ${CPPUNIT_LIBRARIES})
#message (STATUS "TEST_LIBRARIES ${TEST_LIBRARIES} -- ${CPPUNIT_LIBRARIES} // ${APR_LIBS}")

#
add_subdirectory (core)
#add_subdirectory (utils)
#add_subdirectory (src/main/cpp)
#add_subdirectory (src/test/cpp)
