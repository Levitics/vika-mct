set(EXPAT_SOURCE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/expat-2.1.1)
set(EXPAT_BUILD_DIRECTORY ${TARGET_BUILD_DIRECTORY}/EXPAT-build)

set(EXPAT_INCLUDE_DIRECTORY ${EXPAT_SOURCE_DIRECTORY}/lib)
set(EXPAT_LIBS_DIRECTORY ${EXPAT_SOURCE_DIRECTORY})



option(BUILD_tools "build the xmlwf tool for expat library" ON)

# configuration options
set(XML_CONTEXT_BYTES 1024 CACHE STRING "Define to specify how much context to retain around the current parse point")
option(XML_DTD "Define to make parameter entity parsing functionality available" ON)
option(XML_NS "Define to make XML Namespaces functionality available" ON)


#set(EXPAT_BUILD_DIRECTORY ${TARGET_BUILD_DIRECTORY}/expat-build)
#file(MAKE_DIRECTORY
#  ${EXPAT_BUILD_DIRECTORY}
#)

if(XML_DTD)
    set(XML_DTD 1)
else(XML_DTD)
    set(XML_DTD 0)
endif(XML_DTD)
if(XML_NS)
    set(XML_NS 1)
else(XML_NS)
    set(XML_NS 0)
endif(XML_NS)

if(BUILD_tests)
    enable_testing()
endif(BUILD_tests)

include(expat-2.1.1/ConfigureChecks.cmake)