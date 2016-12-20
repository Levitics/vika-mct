#ifndef @NAME@_API_HPP
#define @NAME@_API_HPP

#ifndef @NAME@_API_HPP
#define @NAME@_API_HPP

//#include <@PROJECT_INCLUDE_NAME@/defines.hpp>
#include <@NAMESPACE@/@NAME@/defines.hpp>

#if defined(_MSC_VER) || defined(__declspec)
#  define @NAMESPACE@_DLLEXPORT __declspec(dllexport)
#  define @NAMESPACE@_DLLIMPORT __declspec(dllimport)
#  define @NAMESPACE@_DLLLOCAL
#else
    #if __GNUC__ >= 4
        #define @NAMESPACE@_DLLEXPORT __attribute__ ((visibility ("default")))
        #define @NAMESPACE@_DLLIMPORT __attribute__ ((visibility ("default")))
        #define @NAMESPACE@_DLLLOCAL  __attribute__ ((visibility ("hidden")))
    #else
        #  define @NAMESPACE@_DLLEXPORT
        #  define @NAMESPACE@_DLLIMPORT
        #  define @NAMESPACE@_DLLLOCAL
#endif

#if defined(@NAME@_STATIC)
#  define @NAMESPACE@_API
#elif defined(@NAME@_SHARED)
#  define @NAMESPACE@_API @NAMESPACE@_DLLEXPORT
#else
#  define @NAMESPACE@_API @NAMESPACE@_DLLIMPORT
#endif

#if defined(@NAME@_SHARED_INL)
#  define @NAMESPACE@_INL @NAMESPACE@_DLLEXPORT
#else
#  define @NAMESPACE@_INL @NAMESPACE@_DLLIMPORT
#endif

#endif

