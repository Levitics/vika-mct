set(LOG4CXX_SOURCE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/apache-log4cxx-0.11.0)
set(LOG4CXX_BUILD_DIRECTORY ${TARGET_BUILD_DIRECTORY}/apache-log4cxx-build)

set(LOG4CXX_SOURCE_INCLUDE_DIRECTORY ${LOG4CXX_SOURCE_DIRECTORY}/src/main/include)
set(LOG4CXX_BUILD_INCLUDE_DIRECTORY ${LOG4CXX_BUILD_DIRECTORY}/src/main/include)

set(LOG4CXX_LIBS_DIRECTORY ${LOG4CXX_BUILD_DIRECTORY}/src/main/cpp/.libs)

file(MAKE_DIRECTORY
  ${LOG4CXX_BUILD_DIRECTORY}
)

add_definitions(-Wno-narrowing -std=gnu++14)

set(COMMON_CONFIGURE_FLAGS
  "--with-apr=../apr-build"
  "--with-apr-util=../apr-util-build"
  "LDFLAGS=-L${EXPAT_LIBS_DIRECTORY}"
)

set(CONFIGURE_FLAGS ${COMMON_CONFIGURE_FLAGS})

add_custom_command(OUTPUT ${LOG4CXX_BUILD_DIRECTORY}/Makefile
    COMMAND CC=${CMAKE_C_COMPILER} CXX=${CMAKE_CXX_COMPILER} ${LOG4CXX_SOURCE_DIRECTORY}/configure ${CONFIGURE_FLAGS}
    DEPENDS libapr-1
    DEPENDS apr-util
    WORKING_DIRECTORY ${LOG4CXX_BUILD_DIRECTORY}
)

add_custom_target(liblog4cxx ALL make
#  COMMAND /bin/bash -c \"
#	cd ${CMAKE_CURRENT_SOURCE_DIR}\;
#	git log . 1>/dev/null 2>&1\;
#        if [ \\$$? == 0 ]; then
#          grep \\".commit_hash\\" ${LOG4CXX_LIBS_DIRECTORY}/liblog4cxx.so 1>/dev/null 2>&1\;
#          if [ ! \\\$$? == 0 ]\; then
#            cd ${CMAKE_CURRENT_SOURCE_DIR} &&
#            git log --pretty=\\"format:%H\\" -1 ${LOG4CXX_SOURCE_DIRECTORY} > /tmp/commit_hash 2>/dev/null &&
#            echo \\"Adding .commit_hash section\\" &&
#            ${objcopy} --add-section .commit_hash=/tmp/commit_hash ${LOG4CXX_LIBS_DIRECTORY}/liblog4cxx.so ${LOG4CXX_LIBS_DIRECTORY}/liblog4cxx.so 1>/dev/null 2>&1\;
#          fi;
#        fi\"
  DEPENDS ${LOG4CXX_BUILD_DIRECTORY}/Makefile
  WORKING_DIRECTORY ${LOG4CXX_BUILD_DIRECTORY}
)

#add_dependencies(liblog4cxx apr-util libapr-1 expat)
install(
  DIRECTORY ${LOG4CXX_LIBS_DIRECTORY}/
  DESTINATION ${TARGET_BUILD_DIRECTORY}/lib
  USE_SOURCE_PERMISSIONS
  FILES_MATCHING PATTERN liblog4cxx.*
)

install(
  DIRECTORY ${LOG4CXX_SOURCE_INCLUDE_DIRECTORY}/
  DESTINATION ${TARGET_BUILD_DIRECTORY}/include
  USE_SOURCE_PERMISSIONS
  FILES_MATCHING PATTERN *.h
)

install(
  DIRECTORY ${LOG4CXX_BUILD_INCLUDE_DIRECTORY}/
  DESTINATION ${TARGET_BUILD_DIRECTORY}/include
  USE_SOURCE_PERMISSIONS
  FILES_MATCHING PATTERN *.h
)
