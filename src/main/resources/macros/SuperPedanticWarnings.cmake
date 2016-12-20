# Module to enable hyper pedantic warning
# if defines the function :
#   super_pedantic_warning() - tests and enable super pedantic warning


include(CMakeParseArguments)
include(CheckCXXCompilerFlag)

function(SUPER_PEDANTIC_WARNINGS)
    set(multiValueArgs ADDITIONAL_FLAGS)
    cmake_parse_arguments(ARGS "" "" "${multiValueArgs}" ${ARGN})
    set(FLAGS -pipe
        -Wall
        -Wextra
        -fdiagnostics-show-option
        -Wchar-subscripts
        -Winit-self
        -Wswitch-enum
        -Wstrict-aliasing=3
        -Wstrict-overflow=5
        -Wundef
        -Wno-endif-labels
        -Wshadow
        -Wno-system-headers
        -Wno-builtin-macro-redefined
        -Wmissing-declarations
        -Wsign-conversion
    )

    foreach(F ${ARGS_ADDITIONAL_FLAGS})
        list(APPEND FLAGS ${F})
    endforeach(F ${ARGS_ADDITIONAL_FLAGS})

    set(ENABLED_FLAGS )

    foreach(F ${FLAGS})
        string(REGEX REPLACE "[-+=]" "_" F_CHECK_NAME ${F})
        set(F_CHECK_NAME CHECK_CXX_FLAG${F_CHECK_NAME})
            #now we do the check
            check_cxx_compiler_flag(${F} ${F_CHECK_NAME})
            #if the check pass, lets add the definition
        if(${F_CHECK_NAME})
            list(APPEND ENABLED_FLAGS ${F})
        endif(${F_CHECK_NAME})
    endforeach(F ${FLAGS})

    foreach(F ${ENABLED_FLAGS})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${F}")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${F}" PARENT_SCOPE)
    endforeach(F ${ENABLED_FLAGS})
endfunction(SUPER_PEDANTIC_WARNINGS)

macro(buildx_enable_diagnostics)
	if(${CMAKE_C_COMPILER_ID} MATCHES "GNU|Clang")
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wconversion -Wsign-conversion -Werror -pedantic")
	endif()
	if(${CMAKE_CXX_COMPILER_ID} MATCHES "GNU|Clang")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wsign-conversion -Werror -pedantic")
	endif()
endmacro(buildx_enable_diagnostics)

add_definitions(-Wall -Wextra -Waggregate-return -Wcast-align -Wcast-qual -Wconversion)
add_definitions(-Wdisabled-optimization -Wformat=2 -Wformat-nonliteral -Wformat-security -Wformat-y2k)
add_definitions(-Wimport  -Winit-self  -Winline -Winvalid-pch -Wlong-long -Wmissing-field-initializers -Wmissing-format-attribute)
add_definitions(-Wpointer-arith -Wredundant-decls -Wshadow)
add_definitions(-Wstack-protector -Wunreachable-code -Wunused)
add_definitions(-Wunused-parameter -Wvariadic-macros -Wwrite-strings)
add_definitions(-Wswitch-default -Wswitch-enum)
add_definitions(-Wno-error=shadow)
add_definitions(-Wno-error=long-long)
add_definitions(-Wno-error=aggregate-return)
add_definitions(-Wno-error=unused-variable)
add_definitions(-Wno-error=unused-parameter)
add_definitions(-Wno-error=deprecated-declarations)
add_definitions(-Wno-error=missing-include-dirs)
add_definitions(-Wno-error=packed)
add_definitions(-Wno-error=switch-default)
add_definitions(-Wno-error=float-equal)
add_definitions(-Wno-error=invalid-pch)
add_definitions(-Wno-error=cast-qual)
add_definitions(-Wno-error=conversion)
add_definitions(-Wno-error=switch-enum)
add_definitions(-Wno-error=redundant-decls)
add_definitions(-Wno-error=stack-protector)
add_definitions(-Wno-error=extra)
add_definitions(-Wno-error=unused-result)
add_definitions(-Wno-error=sign-compare)

add_definitions(-Wno-error=address)
add_definitions(-Wno-error=cast-qual)
add_definitions(-Wno-error=missing-field-initializers)
add_definitions(-Wno-error=write-strings)
add_definitions(-Wno-error=format-nonliteral)
add_definitions(-Wno-error=sign-conversion)

add_definitions(-Wno-error=suggest-attribute=format)
add_definitions(-Wno-error=suggest-attribute=noreturn)
add_definitions(-Wno-aggregate-return)
add_definitions(-Wno-long-long)
add_definitions(-Wno-shadow)
add_definitions(-Wno-strict-aliasing)
add_definitions(-Wno-error=inline)
add_definitions(-Wno-error=maybe-uninitialized)
add_definitions(-Wno-error=unused-but-set-variable)
add_definitions(-Wno-error=unused-local-typedefs)
# add_definitions(-Wno-error=float-conversion)

#set(_KDE_GCC_COMMON_WARNING_FLAGS "-Wall -Wextra -Wcast-align -Wchar-subscripts -Wformat-security -Wno-long-long -Wpointer-arith -Wundef")
#if(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${_KDE_GCC_COMMON_WARNING_FLAGS} -Wmissing-format-attribute -Wwrite-strings")
#    # Make some warnings errors
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror=implicit-function-declaration")
#endif()
#if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${_KDE_GCC_COMMON_WARNING_FLAGS} -Wnon-virtual-dtor -Woverloaded-virtual")
#    # Make some warnings errors
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=return-type")
#endif()

## turn on some more warnings
#SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Werror -Wall -Wextra")
#SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Werror -Wall -Wextra")
#
#SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Werror -Wall -Wextra")
#SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Werror -Wall -Wextra")
#
#SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror -Wall -Wextra")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra")
#
## support building for coverage analysis
#SET(CMAKE_C_FLAGS_COVERAGE "${CMAKE_C_FLAGS_DEBUG} -O0 --coverage")
#SET(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_DEBUG} -O0 --coverage")
#SET(CMAKE_EXE_LINKER_FLAGS_COVERAGE "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --coverage")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libstdc++")
