include(CheckCCompilerFlag)
CHECK_C_COMPILER_FLAG("-std=gnu99" C_COMPILER_HAS_C99)
CHECK_C_COMPILER_FLAG("-std=gnu11" C_COMPILER_HAS_C11)
CHECK_C_COMPILER_FLAG("-Wall" C_COMPILER_HAS_WALL)
CHECK_C_COMPILER_FLAG("-Wextra" C_COMPILER_HAS_WEXTRA)
CHECK_C_COMPILER_FLAG("-Wno-unused-parameter" C_COMPILER_HAS_WNO_UNUSED_PARAMETER)
CHECK_C_COMPILER_FLAG("-Wno-missing-field-initializers" C_COMPILER_HAS_WNO_MISSING_FIELD_INITIALIZERS)
CHECK_C_COMPILER_FLAG("-fvisibility=hidden" C_COMPILER_HAS_FVISIBILITY)

#if(CC_COMPILER_HAS_C11)
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
#else()
#        message(FATAL_ERROR "The compiler ${CMAKE_C_COMPILER} has no C11 or later support. Please use a different C compiler.")
#endif()

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)
CHECK_CXX_COMPILER_FLAG("-std=c++1y" COMPILER_SUPPORTS_CXX1Y)
CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)
CHECK_CXX_COMPILER_FLAG("-Wall" CXX_COMPILER_HAS_WALL)
CHECK_CXX_COMPILER_FLAG("-Wextra" CXX_COMPILER_WALL_HAS_WEXTRA)
CHECK_CXX_COMPILER_FLAG("-fvisibility=hidden" CXX_COMPILER_HAS_FVISIBILITY)
CHECK_CXX_COMPILER_FLAG("-fvisibility-inlines-hidden" CXX_COMPILER_HAS_FVISIBILITY_INLINE)

#if(COMPILER_SUPPORTS_CXX17)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
#else
if(COMPILER_SUPPORTS_CXX1Y)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
elseif(COMPILER_SUPPORTS_CXX14)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
elseif(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 or later support. Please use a different C++ compiler.")
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE ON)

add_definitions(-DPROJECT_ARTIFACTID="core")

set(CORE_MODULE_ROOT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})


if(ENABLE_CPPLINT)
    CPPLINT_RECURSIVE(
        ${PROJECT_NAME}Core                                   #target_name.The name of the target to define. Your program should depend on it to invoke cpplint.
        ${CMAKE_CURRENT_SOURCE_DIR}                           #src_folder.The folder to recursively run cpplint.
        ${CORE_MODULE_ROOT_DIRECTORY}                         #root_folder.The root folder used to determine desired include-guard comments.
#        "${TARGET_BUILD_DIRECTORY}/lint/${PROJECT_NAME}Core" #bin_folder.The temporary build folder to store a cpplint history file.
    )
endif(ENABLE_CPPLINT)


if(ENABLE_CPPCHECK)
    ADD_CPPCHECK_ANALYSIS(
        ${PROJECT_NAME}Core
        ${CMAKE_CURRENT_BINARY_DIR}
    )
endif(ENABLE_CPPCHECK)

if(ENABLE_FORMATING_STYLE)
    apply_style_targets(
        ${PROJECT_NAME}Core
        ${CMAKE_CURRENT_BINARY_DIR}
    )
endif(ENABLE_FORMATING_STYLE)


if(ENABLE_CYCLOMATIC_COMPLEXITY)
    CYCLOMATIC_COMPLEXITY_ANALYZER( 
        ${PROJECT_NAME}Core
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif(ENABLE_CYCLOMATIC_COMPLEXITY)


#if(ENABLE_COVERAGE)
#       add_coverage_targets(${PROJECT_NAME}CoreTest.bin ${PROJECT_NAME}CoreTest ${CMAKE_CURRENT_BINARY_DIR})
#        add_coverage_targets(${PROJECT_NAME}CoreTest.bin ${PROJECT_NAME}CoreTestQA ${CORE_MODULE_ROOT_DIRECTORY})
#        add_dependencies(${PROJECT_NAME}CoreTestQA ${PROJECT_NAME}CoreTest.bin)
#endif(ENABLE_COVERAGE)

add_subdirectory (src/main/cpp)
add_subdirectory (src/test/cpp)
