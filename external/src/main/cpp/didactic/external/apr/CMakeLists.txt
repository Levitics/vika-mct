#message ("Builidng APR in ${TARGET_BUILD_DIRECTORY}")

set(APR_SOURCE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/apr-1.5.2)
set(APR_BUILD_DIRECTORY ${TARGET_BUILD_DIRECTORY}/apr-build)

set(APR_INCLUDE_DIRECTORY ${APR_SOURCE_DIRECTORY}/include)

set(APR_LIBS_DIRECTORY ${APR_BUILD_DIRECTORY}/.libs)

file(MAKE_DIRECTORY
    ${APR_BUILD_DIRECTORY}/include/private
    ${APR_SOURCE_DIRECTORY}/include/private
)

file(COPY ${APR_SOURCE_DIRECTORY}/tools/gen_test_char.c
    DESTINATION ${APR_BUILD_DIRECTORY}/tools
)

set(CONFIGURE_FLAGS "")

#add_custom_command(OUTPUT apr-configure 
#                   POST_BUILD
#                   COMMAND ${CMAKE_COMMAND} ARGS -E copy "${APR_BUILD_DIRECTORY}/apr-1-config" "${TARGET_BUILD_DIRECTORY}/bin"
#)

add_custom_command(OUTPUT ${APR_BUILD_DIRECTORY}/Makefile
    COMMAND CC=${CMAKE_C_COMPILER} ${APR_SOURCE_DIRECTORY}/configure ${CONFIGURE_FLAGS}
    COMMAND ${CMAKE_COMMAND} -E copy include/apr.h ${APR_SOURCE_DIRECTORY}/include
    WORKING_DIRECTORY ${APR_BUILD_DIRECTORY}
)

add_custom_command(OUTPUT ${APR_BUILD_DIRECTORY}/include/private/apr_escape_test_char.h
    DEPENDS ${APR_BUILD_DIRECTORY}/Makefile
    COMMAND make include/private/apr_escape_test_char.h
    COMMAND ${CMAKE_COMMAND} -E copy include/private/apr_escape_test_char.h ${APR_SOURCE_DIRECTORY}/include/private
    WORKING_DIRECTORY ${APR_BUILD_DIRECTORY}
)

add_custom_target(libapr-1 ALL make
    DEPENDS ${APR_BUILD_DIRECTORY}/include/private/apr_escape_test_char.h
    WORKING_DIRECTORY ${APR_BUILD_DIRECTORY}
    COMMENT "Building APR librarry"
)

#add_custom_target(apr-1 ALL make
#    DEPENDS ${APR_BUILD_DIRECTORY}/include/private/apr_escape_test_char.h
#    WORKING_DIRECTORY ${APR_BUILD_DIRECTORY}
#)

INSTALL( FILES ${APR_BUILD_DIRECTORY}/apr-1-config 
         PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
                     GROUP_READ GROUP_EXECUTE
                     WORLD_READ WORLD_EXECUTE
         DESTINATION ${TARGET_BUILD_DIRECTORY}/bin
)

install(
    DIRECTORY ${APR_BUILD_DIRECTORY}/.libs/
    DESTINATION ${TARGET_BUILD_DIRECTORY}/lib
    USE_SOURCE_PERMISSIONS
    #FILES_MATCHING PATTERN libapr-1.so*
    FILES_MATCHING PATTERN libapr-1.*
)

install(
  DIRECTORY ${APR_INCLUDE_DIRECTORY}/
  DESTINATION ${TARGET_BUILD_DIRECTORY}/include
  USE_SOURCE_PERMISSIONS
  FILES_MATCHING PATTERN *.h
)

mark_as_advanced( FORCE APR_LIBS_DIRECTORY APR_INCLUDE_DIRECTORY APR_BUILD_DIRECTORY)

#add_custom_command(
#        TARGET ${PROJECT_NAME}
#        POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory ${APR_INCLUDE_DIRECTORY}/include ${TARGET_BUILD_DIRECTORY}/lib
##        COMMAND ${CMAKE_COMMAND} -E copy ${APR_BUILD_DIRECTORY}/*.a ${TARGET_BUILD_DIRECTORY}/lib)

#http://stackoverflow.com/questions/13429656/cmake-how-to-copy-contents-of-a-directory-into-build-directory-after-make

#message( STATUS " HAPPPYMMAAAAANNNN   ${CMAKE_CURRENT_SOURCE_DIR}")
#add_custom_command(TARGET libapr-1 PRE_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${APR_INCLUDE_DIRECTORY} $<TARGET_FILE_DIR:libapr-1>)

# Copy all matching file
#INSTALL(DIRECTORY ${APR_INCLUDE_DIRECTORY} DESTINATION ${TARGET_BUILD_DIRECTORY}/apr
#          FILES_MATCHING PATTERN "*.dae"  PATTERN "*.jpg")

#install(DIRECTORY ${APR_INCLUDE_DIRECTORY}
#    #DESTINATION ${TARGET_BUILD_DIRECTORY}/include/apr
#    DESTINATION ${TARGET_BUILD_DIRECTORY}
#    FILES_MATCHING
#    PATTERN "*.h"
#    PATTERN ".svn" EXCLUDE
#    PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
#)
