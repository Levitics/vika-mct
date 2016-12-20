#ifndef @UPPER_PROJECT_NAME@_DEFINES_H
#define @UPPER_PROJECT_NAME@_DEFINES_H

#ifdef __APPLE__
    #  include <@PROJECT_INCLUDE_NAME@/definesDarwin.hpp>
    #define @NAMESPACE@_PLATFORM_APPLE
#elif defined (__linux__)
    #  include <@PROJECT_INCLUDE_NAME@/definesLinux.hpp>
    #define @NAMESPACE@_PLATFORM_LINUX
#elif defined (_WIN32) || defined(_WIN64)
    #  include <@PROJECT_INCLUDE_NAME@/definesWin32.hpp>
    #define @NAMESPACE@_PLATFORM_WINDOWS
#else
    #error Unknown OS
    #define @NAMESPACE@_PLATFORM_POSIX
#endif

#define NS @NAMESPACE@
#ifndef NS
    # define PREPEND_NAMESPACE(name) ::name
    # define USE_NAMESPACE
    # define BEGIN_NAMESPACE
    # define END_NAMESPACE
    # define FORWARD_DECLARE_CLASS(name) class name;
    # define FORWARD_DECLARE_STRUCT(name) struct name;
#else
    # define PREPEND_NAMESPACE(name) ::NS::name
    # define USE_NAMESPACE using namespace ::NS;
    # define BEGIN_NAMESPACE namespace NS {
    # define END_NAMESPACE }

    # define FORWARD_DECLARE_CLASS(name) \
            BEGIN_NAMESPACE class name; END_NAMESPACE

    # define FORWARD_DECLARE_STRUCT(name) \
            BEGIN_NAMESPACE struct name; END_NAMESPACE
    namespace US_NAMESPACE {}
#endif

#ifdef COMPILER_NULLPTR
    # define NULLPTR    nullptr
#else
    # define NULLPTR    NULL
#endif

#ifdef COMPILER_DEFAULT_MEMBERS
    #  define DECL_EQ_DEFAULT = default
#else
    #  define DECL_EQ_DEFAULT
#endif

#ifdef COMPILER_DELETE_MEMBERS
    # define DECL_EQ_DELETE = delete
#else
    # define DECL_EQ_DELETE
#endif

#ifdef COMPILER_EXPLICIT_OVERRIDES
    #define    DECL_OVERRIDE override
    #define    DECL_FINAL final
#else
    #ifndef    DECL_OVERRIDE
        #define    DECL_OVERRIDE
    #endif
    #ifndef    DECL_FINAL
        #define    DECL_FINAL
    #endif
#endif
    
#define DISABLE_COPY(Class) \
    Class(const Class &) DECL_EQ_DELETE;\
    Class &operator=(const Class &) DECL_EQ_DELETE;
 
#ifdef NOOP      
    #define NS_UNUSED(x) (void)(x)
    #define NOOP(x) do {} while(0) //((void)0)

    static inline void conditional_noop() do{} while(0)
#else       
    #define conditional_noop(x) NS_UNUSED(x)   
#endif

#endif