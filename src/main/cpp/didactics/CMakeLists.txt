set (EXEMPLE_SRCS abst/Shape.cpp)
add_executable (${PROJECT_NAME} main.cpp
    ${EXEMPLE_SRCS}
)

include(CodingStyle)

file(GLOB_RECURSE headers "abst/*.hpp" "abst/*.cpp")
#set(headers /home/happyman/NetBeansProjects/didactics/src/main/cpp/didactics/abst/Shape.hpp)
UncrustifyDir(headers)
add_library(${PROJECT_NAME}-exemple STATIC  ${EXEMPLE_SRCS})
