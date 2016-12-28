#ifndef API_HPP
#define API_HPP
#ifndef @NAME@_API_HPP
#define @NAME@_API_HPP

#include <@PROJECT_INCLUDE_NAME@/defines.hpp>

#if defined(_MSC_VER) || defined(__declspec)
#  define @NAMESPACE@_DLLEXPORT __declspec(dllexport)
#  define @NAMESPACE@_DLLIMPORT __declspec(dllimport)
#else 
#  define @NAMESPACE@_DLLEXPORT
#  define @NAMESPACE@_DLLIMPORT
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

