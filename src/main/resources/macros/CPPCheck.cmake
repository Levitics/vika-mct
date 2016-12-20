#     add_cppcheck(<target>
#                  [ALL]
#                  [IGNORE_WARNINGS]
#                  [IGNORE_STYLE]
#                  [IGNORE_PERFORMANCE]
#                  [IGNORE_PORTABILITY]
#                  [IGNORE_INFORMATION]
#                  [IGNORE_UNUSED_FUNC]
#                  [IGNORE_MISSING_INCLUDE]
#                  [WARNINGS]
#                  [STYLE]
#                  [PERFORMANCE]
#                  [PORTABILITY]
#                  [INFORMATION]
#                  [UNUSED_FUNC]
#                  [MISSING_INCLUDE]
#                  [FORCE_CHECK]
#                  [INCLUDES])

set(CPPCHECK_EXE "cppcheck")
find_program(CPPCHECK_EXECUTABLE
        NAMES cppcheck
        PATHS  
        NO_DEFAULT_PATH
)

file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp) 
file(GLOB_RECURSE ALL_HEADER_FILES *.hpp)

set(CPPCHECK_TEMPLATE_ARG --template gcc)

foreach (SOURCE_FILE ${ALL_SOURCE_FILES}) 
    string(FIND ${SOURCE_FILE} ${PROJECT_TRDPARTY_DIR} PROJECT_TRDPARTY_DIR_FOUND) 
    if (NOT ${PROJECT_TRDPARTY_DIR_FOUND} EQUAL -1) 
        list(REMOVE_ITEM ALL_SOURCE_FILES ${SOURCE_FILE}) 
    endif () 
endforeach () 

add_custom_target( cppcheck 
    COMMAND ${CPPCHECK_EXE} --enable=warning,performance,portability,information,missingInclude,unusedFunction 
            --std=c++11 
            --library=qt.cfg 
            --template="[{severity}][{id}] {message} {callstack} \(On {file}:{line}\)" 
#"{file}:{line}: {severity} {id}: {message}"
            --verbose 
            --quiet 
             ${ALL_SOURCE_FILES} ${ALL_HEADER_FILES} 
)
