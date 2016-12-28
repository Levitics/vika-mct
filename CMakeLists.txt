cmake_minimum_required(VERSION 3.7)

project (${PROJECT_NAME})

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
    "${CMAKE_SOURCE_DIR}/src/test/resources/moduleTest"
)

set(TARGET_BUILD_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_INSTALL_PREFIX ${TARGET_BUILD_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(ENABLE_QA_CHECK              "Software quality. Conformance to one or more standards"    OFF)
option(ENABLE_COVERAGE              "Build the project with coverage support"                   OFF)
option(ENABLE_CPPLINT               "Ensure that code conforms to Google's coding style guides" OFF)
option(ENABLE_FORMATING_STYLE       "Code Beautifier using Uncrustify"                          OFF)
option(ENABLE_CYCLOMATIC_COMPLEXITY "Cyclomatic Complexity Analyzer"                            OFF)
option(ENABLE_CPPCHECK              "Static code analysis tool "                                OFF)


#include(aol)


#add_custom_command(TARGET ${target_name} 
#    PRE_BUILD 
#    COMMAND ${CMAKE_COMMAND} -E make_directory ${directory}
#)



#To create a directory when CMake generates the build system,
#file(MAKE_DIRECTORY ${AOL})

include(DefinePlatformSpecifc)
include(PreventInSourceBuilds) 

include_directories(SYSTEM  ${TARGET_BUILD_DIRECTORY}/include)
include_directories (SYSTEM ${CMAKE_BINARY_DIR}/include)
link_directories(${TARGET_BUILD_DIRECTORY}/lib)

#if (CMAKE_BUILD_TYPE EQUAL "COVERAGE_BUILD")
#    if(NOT TARGET ${PROJECT_NAME}-coverage-debug)
#        ADD_CUSTOM_TARGET(${PROJECT_NAME}-coverage-debug
#            COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
#            COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
#            COMMENT "Switch CMAKE_BUILD_TYPE to Coverage Debug"
#        )
#    endif(NOT TARGET ${PROJECT_NAME}-coverage-debug)
#
#    if(NOT TARGET ${PROJECT_NAME}-coverage-release)
#        ADD_CUSTOM_TARGET(${PROJECT_NAME}-coverage-release
#            COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
#            COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
#            COMMENT "Switch CMAKE_BUILD_TYPE to Release"
#        )
#    endif(NOT TARGET ${PROJECT_NAME}-coverage-release)
#
#else(CMAKE_BUILD_TYPE EQUAL "COVERAGE_BUILD")
#
#    if(NOT TARGET ${PROJECT_NAME}-debug)
#        ADD_CUSTOM_TARGET(${PROJECT_NAME}-debug
#            COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
#            COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
#            COMMENT "Switch CMAKE_BUILD_TYPE to Debug"
#        )
#    endif(NOT TARGET ${PROJECT_NAME}-debug)
#
#    if(NOT TARGET ${PROJECT_NAME}-release)
#        ADD_CUSTOM_TARGET(${PROJECT_NAME}-release
#            COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
#            COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
#            COMMENT "Switch CMAKE_BUILD_TYPE to Release"
#        )
#    endif(NOT TARGET ${PROJECT_NAME}-release)
#
#endif(CMAKE_BUILD_TYPE EQUAL "COVERAGE_BUILD")

include(ProcessorCount)
ProcessorCount(Ncpu)
if(NOT Ncpu EQUAL 0)
    #set(MAKECOMMAND -j${N} ${MAKECOMMAND_DEFAULT_VALUE})
    #set(MAKEFLAGS  -j${N})
    #set(CTEST_BUILD_FLAGS -j${N}) 
#    set (CMAKE_MAKE_PROGRAM "${CMAKE_MAKE_PROGRAM} -j${N}") 
    #message(STATUS "CMAKE_MAKE_PROGRAM Building with Processor Count: ${CMAKE_MAKE_PROGRAM} -j${Ncpu}")
endif()

add_subdirectory (external)

find_package(CPPUNIT)
find_package(GoogleMock)
find_package(EXPAT)
find_package(APR)
find_package(APR-UTIL)
find_package(Log4cxx)

include(CodingStyle)
include(CpplintWrapper)
include(lizard)
include(CPPCheck)
include(CommonCoverage)


#if(NOT TARGET distclean)
#    SET(cmake_generated ${CMAKE_BINARY_DIR}/CMakeCache.txt
#        ${CMAKE_BINARY_DIR}/cmake_install.cmake
#        ${CMAKE_BINARY_DIR}/Makefile
#        ${CMAKE_BINARY_DIR}/CMakeFiles
#        ${CMAKE_BINARY_DIR}/build)
#
#    add_custom_target(distclean
#        COMMAND ${CMAKE_COMMAND} -E rm -Rvf "${cmake_generated}"
#        COMMENT "Delete build output and cmake files"
#    )
#endif()
#
#if(NOT TARGET style)
#    add_custom_target(style
#        COMMENT "Prettying source code with uncrustify"
#    )
#endif()
#
#if(NOT TARGET cyclomatic)
#    add_custom_target(cyclomatic
#        COMMENT "Cyclomatic Complexity Analyzer."
#    )
#endif()
#
#if(NOT TARGET cppcheck)
#    add_custom_target(cppcheck
#        COMMENT "Static code analysis."
#    )
#endif()
#
#if(NOT TARGET lint)
#    add_custom_target(lint
#        COMMENT "Check the C++ source code to analyze it for syntax errors and other faults."
#    )
#endif()

#if(NOT TARGET coverage)
#    add_custom_target(coverage
#        COMMENT "Running coverage report."
#    )
#endif()

#if(ENABLE_QA_CHECK)
#    if(NOT TARGET qa-check)
#        ADD_CUSTOM_TARGET(qa-check
#            COMMENT "Software quality assurance: Style -> CPPCheck -> Cyclomatic -> CPPlint -> Coverage"
#        )
#        add_dependencies(qa-check coverage style cppcheck cyclomatic lint)
#    endif(NOT TARGET qa-check)
#else(ENABLE_QA_CHECK)
#    add_custom_target(qa-check 
#        COMMAND ${CMAKE_COMMAND} -E echo "Software quality assurance disabled"
#    )
#endif(ENABLE_QA_CHECK)

add_subdirectory (core)
#add_subdirectory (utils)
#add_subdirectory (src/main/cpp)
#add_subdirectory (src/test/cpp)
