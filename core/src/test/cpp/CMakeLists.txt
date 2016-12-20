include_directories(.)

#include_directories(${CPPUNIT_INCLUDE_DIR} 
#${PROJECT_NAME}Core_INCLUDE_DIRS
#)
add_definitions(-DPROJECT_ARTIFACTID="coreTestSuite")

set(CORE_SOURCES  
        didactics/Test.cpp
        didactics/core/Test.cpp
        didactics/core/exple/DelegateMockTurtle.cpp
        didactics/core/exple/FakeTurtle.cpp
        didactics/core/exple/MockTurtle.cpp
        didactics/core/exple/PainterTest.cpp
        didactics/core/exple/TurtleTest.cpp
        didactics/core/exple/SimpleTurtleTest.cpp
        didactics/core/exple/ExtendedTurtleTest.cpp
#        didactics/core/log/LoggerTest.cpp
#        didactics/core/log/Hierarchy.cpp

)

#add_library(${PROJECT_NAME}CoreTest STATIC ${CORE_SOURCES} )

#add_dependencies(liblog4cxx apr-util libapr-1 expat)
#add_dependencies(
#        ${PROJECT_NAME}CoreTest 
#        ${PROJECT_NAME}Core 
#        gmock 
#        gmock_main 
#        cppunit)
add_executable(${PROJECT_NAME}CoreTest.exe didactics/main.cpp ${CORE_SOURCES})
target_link_libraries (${PROJECT_NAME}CoreTest.exe 
                        ${LOG4CXX_LIBRARIES}
                        ${APU_LIBS}
                        ${APR_LIBS}
                        ${EXPAT_LIBRARY}
                        ${CPPUNIT_LIBRARIES}
                        ${GOOGLEMOCK_LIBRARIES} 
                        gmock_main.d
                        pthread
#                        ${PROJECT_NAME}CoreTest 
                        ${PROJECT_NAME}Core
)
 #${CPPUNIT_LIBRARIES} cppunit.d log4cxx aprutil-1 apr-1 gmock gmock_main
#link_libraries(
    #-lcppunit.d 
    #-llog4cxx 
    #-laprutil-1 
    #-lapr-1  #+1  avoid typeinfo for log4cxx::helpers::ObjectPtrBase ISUES
#)

#find_package(GoogleMock)

include_directories(
    /home/happyman/NetBeansProjects/didactics/core/src/main/cpp/
    /home/happyman/NetBeansProjects/didactics/core/src/main/cpp/didactics
    /home/happyman/NetBeansProjects/didactics/core/src/main/cpp/didactics/core
    /home/happyman/NetBeansProjects/didactics/core/src/main/cpp/didactics/core/callstack
    /home/happyman/NetBeansProjects/didactics/core/src/main/cpp/didactics/core/chronos
    /home/happyman/NetBeansProjects/didactics/core/src/main/cpp/didactics/core/exceptions
    /home/happyman/NetBeansProjects/didactics/core/src/main/cpp/didactics/core/exple
    /home/happyman/NetBeansProjects/didactics/core/src/main/cpp/didactics/core/log
    /home/happyman/NetBeansProjects/didactics/core/src/main/cpp/didactics/core/socket
    /home/happyman/NetBeansProjects/didactics/core/src/main/cpp/didactics/core/utils
    ${GOOGLEMOCK_INCLUDE_DIR}

)
 message(STATUS "TEST_LIBRARIESTEST_LIBRARIESTEST_LIBRARIESTEST_LIBRARIES ${TEST_LIBRARIES}")
#target_include_directories(${PROJECT_NAME}Core PUBLIC didactics)
#target_link_libraries (${PROJECT_NAME}CoreTest ${PROJECT_NAME}Core ${GOOGLEMOCK_LIBRARIES} "/home/happyman/NetBeansProjects/didactics/build/Debug/lib/libcppunit.a")
#link_directories ("/home/happyman/NetBeansProjects/didactics/build/Debug/lib")

#SET_TARGET_PROPERTIES(${PROJECT_NAME}CoreTest PROPERTIES STATIC_LIBRARY_FLAGS ${CPPUNIT_LIBRARIES})

#add_custom_target(combinedTestLib ALL
#   COMMAND ${CMAKE_CXX_ARCHIVE_CREATE} libcombined.a $<TARGET_FILE:${PROJECT_NAME}CoreTest> $<TARGET_FILE:/home/happyman/NetBeansProjects/didactics/build/Debug/lib
#/libcppunit.a>)
