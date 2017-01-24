# Module to enable hyper pedantic warning
# if defines the function :
#   super_pedantic_warning() - tests and enable super pedantic warning

#if (CMAKE_SYSTEM_NAME STREQUAL GNU)
#    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pthread")
#    set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -pthread")
#endif()


include(CMakeParseArguments)
include(CheckCXXCompilerFlag)

#set(COVERAGE_FLAGS "-g -O0 --coverage -Wall -ftime-report -fmem-report -fvar-tracking -fvar-tracking-assignments")
#set(COVERAGE_FLAGS "-g -O0 --coverage -Wall -Q ftime-report -fmem-report")

set(GCC_COMMON_WARNING_FLAGS "-Wall -Wextra -Wcast-align -Wchar-subscripts 
                                  -Wformat-security -Wno-long-long 
                                  -Wpointer-arith -Wundef -Wdelete-non-virtual-dtor -Wzero-as-null-pointer-constant 
                                  -W -Wshadow -Wunused-variable  -Wunused-parameter 
                                  -Wunused-function -Wunused -Wno-system-headers 
                                  -Wno-deprecated -Woverloaded-virtual -Wwrite-strings"
)

if(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COMMON_WARNING_FLAGS} -Wmissing-format-attribute -Wwrite-strings")
    # Make some warnings errors
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror=implicit-function-declaration")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COMMON_WARNING_FLAGS} -Wnon-virtual-dtor -Woverloaded-virtual")
    # Make some warnings errors
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=return-type")
endif()

set(COVERAGE_FLAGS "-g -O0 --coverage -Wall")
set(COVERAGE_LINK_FLAGS "--coverage") #-lgcov 

set(COMMON_CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} 
    -Wall -Wextra -Wall -Wextra -Wpedantic 
)

set(PARANO_CMAKE_CXX_FLAGS "${COMMON_CMAKE_CXX_FLAGS} 
    -Werror -pedantic 
)

## support building for coverage analysis
SET(CMAKE_C_FLAGS_COVERAGE          "${CMAKE_C_FLAGS_DEBUG} -O0 --coverage")
SET(CMAKE_CXX_FLAGS_COVERAGE        "${CMAKE_CXX_FLAGS_DEBUG} -O0 --coverage")
SET(CMAKE_EXE_LINKER_FLAGS_COVERAGE "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --coverage")
set(CMAKE_CXX_FLAGS                 "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libstdc++")

## turn on some more warnings
SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Werror -Wall -Wextra")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Werror -Wall -Wextra")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Werror -Wall -Wextra")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Werror -Wall -Wextra")


set(CMAKE_CXX_FLAGS                 "${COMMON_CMAKE_CXX_FLAGS} 
                    -fno-strict-aliasing 
#                    -std=c++14 -O3 
                    -Wno-missing-braces -Wconversion -Wsign-conversion 
                    -Wctor-dtor-privacy -Wshadow -Wnon-virtual-dtor 
                    -Wold-style-cast -Wcast-align -Woverloaded-virtual
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
                    -Wcast-qual
                    -Waggregate-return
                    -Wdisabled-optimization 
#                    -Wformat=2 
                    -Wformat-nonliteral -Wformat-security -Wformat-y2k
                    -Wimport  -Winit-self  -Winline -Winvalid-pch -Wlong-long 
                    -Wmissing-field-initializers -Wmissing-format-attribute
                    -Wpointer-arith -Wredundant-decls -Wshadow
                    -Wswitch-default -Wswitch-enum
                    -Wunused-parameter -Wvariadic-macros -Wwrite-strings
                    -Wstack-protector -Wunreachable-code -Wunused
"
)

set(HAHAHA_CXX_FLAGS "${COMMON_CMAKE_CXX_FLAGS}
    -Wno-error=shadow
    -Wno-error=long-long
    -Wno-error=aggregate-return
    -Wno-error=unused-variable
    -Wno-error=unused-parameter
    -Wno-error=deprecated-declarations
    -Wno-error=missing-include-dirs
    -Wno-error=packed
    -Wno-error=switch-default
    -Wno-error=float-equal
    -Wno-error=invalid-pch
    -Wno-error=cast-qual
    -Wno-error=conversion
    -Wno-error=switch-enum
    -Wno-error=redundant-decls
    -Wno-error=stack-protector
    -Wno-error=extra
    -Wno-error=unused-result
    -Wno-error=sign-compare
    -Wno-error=address
    -Wno-error=cast-qual
    -Wno-error=missing-field-initializers
    -Wno-error=write-strings
    -Wno-error=format-nonliteral
    -Wno-error=sign-conversion
    -Wno-error=suggest-attribute=format
    -Wno-error=suggest-attribute=noreturn
    -Wno-aggregate-return
    -Wno-long-long
    -Wno-shadow
    -Wno-strict-aliasing
    -Wno-error=inline
    -Wno-error=maybe-uninitialized
    -Wno-error=unused-but-set-variable
    -Wno-error=unused-local-typedefs"
)
# add_definitions(-Wno-error=float-conversion)




