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

set(${PROJECT_NAME}_MAJOR_VERSION 1)
set(${PROJECT_NAME}_MINOR_VERSION 0)
set(${PROJECT_NAME}_PATCH_VERSION 1)
set(PROJECT_VERSION_MAJOR ${${PROJECT_NAME}_MAJOR_VERSION})
set(PROJECT_VERSION_MINOR ${${PROJECT_NAME}_MINOR_VERSION})
set(PROJECT_VERSION_MICRO ${${PROJECT_NAME}_PATCH_VERSION})
set(${PROJECT_NAME}_VERSION ${${PROJECT_NAME}_MAJOR_VERSION}.${${PROJECT_NAME}_MINOR_VERSION}.${${PROJECT_NAME}_PATCH_VERSION})


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

string(TOUPPER ${PROJECT_NAME} UPPER_PROJECT_NAME)
string(TOLOWER ${PROJECT_NAME} LOWER_PROJECT_NAME)
string(TOUPPER didactics UPPER_ROOT_INC_NAME)
string(TOLOWER didactics LOWER_ROOT_INC_NAME)

string(SUBSTRING ${PROJECT_NAME} 0 3 NS)
string(TOLOWER ${NS} UPPER_NS)


if(NOT PROJECT_NS)
    string(TOUPPER ${PROJECT_NAME} UPPER_PNAME)
    string(SUBSTRING ${UPPER_PNAME} 0 3 P_NS)
    set(PROJECT_NS ${P_NS})
endif()

set(NAMESPACE ${PROJECT_NS}) #${UPPER_NS} ) #${${UPPER_NS}_NAMESPACE})

set(ROOT_INCLUDE_NAME didactics)
configure_file( "${PROJECT_SOURCE_DIR}/src/main/resources/Defines.hpp.in"
                "${PROJECT_SOURCE_DIR}/core/src/main/cpp/didactics/core/Defines.hpp"
    @ONLY
)

set(PROJECT_VERSION_ABI ${${PROJECT_NAME}_VERSION_ABI})

configure_file(
    "${PROJECT_SOURCE_DIR}/src/main/resources/Api.hpp.in"
    "${PROJECT_SOURCE_DIR}/core/src/main/cpp/didactics/core/Api.hpp" 
    @ONLY
)

configure_file(
    ${PROJECT_SOURCE_DIR}/src/main/resources/Version.hpp.in
    ${PROJECT_SOURCE_DIR}/core/src/main/cpp/didactics/core/Version.hpp 
    @ONLY
)


configure_file(
    ${CMAKE_SOURCE_DIR}/src/main/resources/Version.cpp.in
    ${CMAKE_SOURCE_DIR}/core/src/main/cpp/didactics/core/Version.cpp 
    @ONLY
)


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

if(ENABLE_QA_CHECK)
    if(NOT TARGET qacheck)
        ADD_CUSTOM_TARGET(qacheck
            COMMENT "Software quality assurance: Style -> checkstyle -> CPPCheck -> Cyclomatic -> CPPlint -> Coverage"
        )
        add_dependencies(qacheck cppcheck lint cyclomatic coverage )#style )
    endif(NOT TARGET qacheck)
	
    add_definitions(-DENABLE_CPPLINT=ON 
                    -DENABLE_FORMATING_STYLE=ON  
                    -DENABLE_CPPCHECK=ON 
                    -DENABLE_CYCLOMATIC_COMPLEXITY=ON 
    )
else(ENABLE_QA_CHECK)
    add_custom_target(qacheck 
        COMMAND ${CMAKE_COMMAND} -E echo "Software quality assurance disabled"
    )
endif(ENABLE_QA_CHECK)

include(CTest)
enable_testing ()
add_subdirectory (core)
#add_subdirectory (utils)
#add_subdirectory (src/main/cpp)
#add_subdirectory (src/test/cpp)
