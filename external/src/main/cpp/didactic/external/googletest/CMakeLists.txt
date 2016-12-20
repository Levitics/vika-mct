cmake_minimum_required(VERSION 2.6.2)

project( googletest-distribution )

enable_testing()

option(BUILD_GTEST "Builds the googletest subproject" OFF)

#Note that googlemock target already builds googletest
option(BUILD_GMOCK "Builds the googlemock subproject" ON)

if(BUILD_GMOCK)
  add_subdirectory( googlemock )
elseif(BUILD_GTEST)
  add_subdirectory( googletest )
endif()

#COMMAND ${CMAKE_COMMAND} -E copy_directory googlemock/include/gmock ${TARGET_BUILD_DIRECTORY}/include
#COMMAND ${CMAKE_COMMAND} -E copy /libgtest.a ${TARGET_BUILD_DIRECTORY}/lib
#COMMAND ${CMAKE_COMMAND} -E copy /libgtest_main.a ${TARGET_BUILD_DIRECTORY}/lib



#ExternalProject_Add(external_gtest
#  GIT_REPOSITORY git@github.com:svn2github/googletest.git
#  PREFIX         ${CMAKE_CURRENT_BINARY_DIR}/external/gtest
#  INSTALL_DIR    ${CMAKE_CURRENT_BINARY_DIR}
#  CMAKE_ARGS     -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}
#  INSTALL_COMMAND
#    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_BINARY_DIR}/external/gtest/src/external_gtest/include ${CMAKE_CURRENT_BINARY_DIR}/include
#    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/external/gtest/src/external_gtest-build/libgtest.a ${CMAKE_CURRENT_BINARY_DIR}/lib
#    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/external/gtest/src/external_gtest-build/libgtest_main.a ${CMAKE_CURRENT_BINARY_DIR}/lib
#)

