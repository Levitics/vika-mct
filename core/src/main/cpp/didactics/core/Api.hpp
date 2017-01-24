
#ifndef SPHYNX_CORE_API_HPP
#define SPHYNX_CORE_API_HPP

// #include </defines.hpp>
#include <didactics/core/Defines.hpp>

#if defined (_MSC_VER) || defined (__declspec)
  # define SPH_DLLEXPORT __declspec(dllexport)
  # define SPH_DLLIMPORT __declspec(dllimport)
#else
  # if __GNUC__ >= 4
    #  define SPH_EXPORT      __attribute__ ((visibility ("default")))
    #  define SPH_IMPORT      __attribute__ ((visibility ("default")))
    #  define SPH_DLL_PUBLIC  __attribute__ ((visibility("default")))
    #  define SPH_DLL_LOCAL   __attribute__ ((visibility("hidden")))
  # else
    #  define SPH_EXPORT
    #  define SPH_IMPORT
    #  define SPH_DLL_PUBLIC
    #  define SPH_DLL_LOCAL
  # endif
#endif

#if defined (SPH_STATIC)
  # define SPH_API
#elif defined (SPH_SHARED)
  # define SPH_API SPH_EXPORT
#else
  # define SPH_API SPH_IMPORT
#endif

#define NS SPH

#ifndef NS
  # define PREPEND_NAMESPACE(name) ::name
  # define USE_NAMESPACE
  # define BEGIN_NAMESPACE
  # define END_NAMESPACE
  # define FORWARD_DECLARE_CLASS(name) class name;
  # define FORWARD_DECLARE_STRUCT(name) struct name;
  # define NULLPTR NULL
  # define DECL_EQ_DEFAULT
  # define DECL_EQ_DELETE
  # define  DECL_OVERRIDE
  # define  DECL_FINAL
#else
  # define PREPEND_NAMESPACE(name) ::NS::name
  # define USE_NAMESPACE using namespace ::NS;
  # define BEGIN_NAMESPACE namespace NS {
  # define END_NAMESPACE }
  # define NULLPTR nullptr
  # define DECL_EQ_DEFAULT = default
  # define DECL_EQ_DELETE = delete
  # define DECL_OVERRIDE override
  # define DECL_FINAL final

  # define FORWARD_DECLARE_CLASS(name) \
    BEGIN_NAMESPACE class name;END_NAMESPACE

  # define FORWARD_DECLARE_STRUCT(name) \
    BEGIN_NAMESPACE struct name;END_NAMESPACE

    namespace SPH_NAMESPACE
    { }
#endif


#define DISABLE_COPY(Class) \
    Class(const Class &) DECL_EQ_DELETE; \
    Class &operator = (const Class &) DECL_EQ_DELETE;


#define NS_UNUSED(x) (void)(x)
#define NOOP(x) do { } while (0) // ((void)0)

#endif
