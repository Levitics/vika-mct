# Remove 'lib' prefix for shared libraries
#set(CMAKE_SHARED_LIBRARY_PREFIX "")
#set(CMAKE_STATIC_LIBRARY_PREFIX "")
# Add a d postfix to the debug libraries
if(BLD_STATIC)
        set(CMAKE_DEBUG_POSTFIX "${STATIC_POSTFIX}d" CACHE STRING "Set Debug library postfix" FORCE)
        set(CMAKE_RELEASE_POSTFIX "${STATIC_POSTFIX}" CACHE STRING "Set Release library postfix" FORCE)
        set(CMAKE_MINSIZEREL_POSTFIX "${STATIC_POSTFIX}" CACHE STRING "Set MinSizeRel library postfix" FORCE)
        set(CMAKE_RELWITHDEBINFO_POSTFIX "${STATIC_POSTFIX}" CACHE STRING "Set RelWithDebInfo library postfix" FORCE)
        set(CMAKE_FIND_LIBRARY_SUFFIXES "${STATIC_POSTFIX}a" CACHE STRING "Set RelWithDebInfo library postfix" FORCE)
        set(CMAKE_FIND_LIBRARY_PREFIXES "${STATIC_POSTFIX}lib" CACHE STRING "Set RelWithDebInfo library postfix" FORCE)
else(BLD_STATIC)
        set(CMAKE_DEBUG_POSTFIX ".d" CACHE STRING "Set Debug library postfix" FORCE)
        set(CMAKE_RELEASE_POSTFIX "" CACHE STRING "Set Release library postfix" FORCE)
        set(CMAKE_MINSIZEREL_POSTFIX "" CACHE STRING "Set MinSizeRel library postfix" FORCE)
        set(CMAKE_RELWITHDEBINFO_POSTFIX "" CACHE STRING "Set RelWithDebInfo library postfix" FORCE)
        set(CMAKE_FIND_LIBRARY_SUFFIXES ".a"  CACHE STRING "Set RelWithDebInfo library postfix" FORCE)
        set(CMAKE_FIND_LIBRARY_PREFIXES "lib"  CACHE STRING "Set RelWithDebInfo library postfix" FORCE)
endif(BLD_STATIC)

#if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug" )
#    set(CMAKE_DEBUG_POSTFIX "d")
#    set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
#    set(CMAKE_FIND_LIBRARY_PREFIXES "lib")
#elseif("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
#    set(CMAKE_FIND_LIBRARY_SUFFIXES ".so")
#    set(CMAKE_FIND_LIBRARY_PREFIXES "lib")
#else()
