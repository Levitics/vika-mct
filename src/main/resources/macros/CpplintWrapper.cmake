# We use Google's cpplint for style checking.
# This is optional and graceful; meaning we do not quit building even if there are warnings.
# We are not that pedantic. However, we will keep an eye on the count of warnings.
# Related parameters:
#   Setting variable ENABLE_CPPLINT to true will enable cpplint.
set(Python_ADDITIONAL_VERSIONS 2.7 2.6 2.5 2.4) # Prefer Python-2
find_package(PythonInterp)
if(PYTHONINTERP_FOUND)
#    message(STATUS "Found Python. Python version is ${PYTHON_VERSION_STRING}.")
    if(${PYTHON_VERSION_MAJOR} EQUAL 3)
        message(WARNING "OUCH! The Python found is Python 3. Cpplint.py doesn't run on it so far.")
        message(WARNING "Cpplint won't detect errors. Install Python 2 to fix this issue.")
    endif(${PYTHON_VERSION_MAJOR} EQUAL 3)
    if(ENABLE_CPPLINT)
        set(RUN_CPPLINT true)
    else(ENABLE_CPPLINT)
        message(STATUS "ENABLE_CPPLINT was not given. Skipped running cpplint")
        set(RUN_CPPLINT false)
    endif(ENABLE_CPPLINT)
else(PYTHONINTERP_FOUND)
    message(STATUS "python executable not found. Skipped running cpplint")
    set(RUN_CPPLINT false)
endif(PYTHONINTERP_FOUND)

# Followings are our coding convention.
set(LINT_FILTER) # basically everything Google C++ Style recommends. Except...

# This the only rule cpplint.py disables by default. Enable it.
# However, the default implementation of build/include_alpha in cpplint.py is a bit sloppy.
# It doesn't correctly take care of "/" in include.
# Thus we changed cpplint.py for this.
#set(LINT_FILTER ${LINT_FILTER},+build/include_alpha)

# for logging and debug printing, we do need streams
#set(LINT_FILTER ${LINT_FILTER},-readability/streams)

# We use C++11 with some restrictions.
# set(LINT_FILTER ${LINT_FILTER},-build/c++11)
# 

# Consider disabling them if they cause too many false positives.
# set(LINT_FILTER ${LINT_FILTER},-build/include_what_you_use)
# set(LINT_FILTER ${LINT_FILTER},-build/include_order)

# disable unwanted filters
#set(LINT_FILTER ${LINT_FILTER}-whitespace/braces,)
#set(LINT_FILTER ${LINT_FILTER}-whitespace/semicolon,)
#set(LINT_FILTER ${LINT_FILTER}-whitespace/blank_line,)
#set(LINT_FILTER ${LINT_FILTER}-whitespace/comma,)
#set(LINT_FILTER ${LINT_FILTER}-whitespace/operators,)
#set(LINT_FILTER ${LINT_FILTER}-whitespace/parens,)
#set(LINT_FILTER ${LINT_FILTER}-whitespace/indent,)
#set(LINT_FILTER ${LINT_FILTER}-whitespace/comments,)
#set(LINT_FILTER ${LINT_FILTER}-whitespace/newline,)
#set(LINT_FILTER ${LINT_FILTER}-whitespace/tab,)
#
#set(LINT_FILTER ${LINT_FILTER}-build/include_order,)
#set(LINT_FILTER ${LINT_FILTER}-build/namespaces,)
#set(LINT_FILTER ${LINT_FILTER}-build/include_what_you_use,)
#
#set(LINT_FILTER ${LINT_FILTER}-readability/streams,)
#set(LINT_FILTER ${LINT_FILTER}-readability/todo,)
#
#set(LINT_FILTER ${LINT_FILTER}-runtime/references,)
#set(LINT_FILTER ${LINT_FILTER}-runtime/int,)
#set(LINT_FILTER ${LINT_FILTER}-runtime/explicit,)
#set(LINT_FILTER ${LINT_FILTER}-runtime/printf,)

mark_as_advanced(LINT_FILTER)

#set(LINT_SCRIPT "${CMAKE_CURRENT_LIST_DIR}/cpplint.py")
#set(LINT_SCRIPT "${PROJECT_SOURCE_DIR}/src/main/resources/scripts/stylecheck/cpplint.py")
set(LINT_SCRIPT "${PROJECT_SOURCE_DIR}/src/main/resources/scripts/cpplint-1.3.0/cpplint.py")
mark_as_advanced(LINT_SCRIPT)
#set(LINT_WRAPPER "${CMAKE_CURRENT_LIST_DIR}/cpplint-wrapper.py")
set(LINT_WRAPPER "${PROJECT_SOURCE_DIR}/src/main/resources/scripts/stylecheck/cpplint-wrapper.py")
mark_as_advanced(LINT_WRAPPER)
#message(STATUS "LINT_SCRIPT ${LINT_SCRIPT}")
#message(STATUS "LINT_WRAPPER ${LINT_WRAPPER}")
# 100 chars per line, which is suggested as an option in the style guide
set(LINT_LINELENGTH 120)
mark_as_advanced(LINT_LINELENGTH)

# Registers a CMake target to run cpplint over all files in the given folder.
# Parameters:
#  target_name:
#    The name of the target to define. Your program should depend on it to invoke cpplint.
#  src_folder:
#    The folder to recursively run cpplint.
#  root_folder:
#    The root folder used to determine desired include-guard comments.
#  bin_folder:
#    The temporary build folder to store a cpplint history file.
function(CPPLINT_RECURSIVE target_name src_folder root_folder)
    if(RUN_CPPLINT)
#        message(STATUS "${target_name}: src=${src_folder}, root=${root_folder}, bin=${bin_folder}")
        if(NOT TARGET ${target_name}-lint)
            set(WORKING_DIR "${TARGET_BUILD_DIRECTORY}/qa/cpplint/${target_name}")
            file(MAKE_DIRECTORY ${WORKING_DIR})
            add_custom_target(${target_name}-lint
                         COMMAND
                            ${PYTHON_EXECUTABLE} ${LINT_WRAPPER}
                            --cpplint-file=${LINT_SCRIPT}
                            --history-file=${WORKING_DIR}/.lint_history
                            --linelength=${LINT_LINELENGTH}
#                            --extensions=cpp,hpp
                            --filter=${LINT_FILTER}
                            --root=${root_folder}
                            --verbose=5
                            --root==DIDACTICS
                            ${src_folder}
                         WORKING_DIRECTORY ${WORKING_DIR}
                         COMMENT "[CPPLINT-Target:${target_name}] ${src_folder}"
            )
        endif()
    else(RUN_CPPLINT)
        add_custom_target(${target_name} COMMAND ${CMAKE_COMMAND} -E echo NoLint)
    endif(RUN_CPPLINT)

    if(NOT TARGET lint)
        add_custom_target(lint
            COMMENT "Check the C++ source code to analyze it for syntax errors and other faults."
        )
    endif()

    add_dependencies(lint ${target_name}-lint)

endfunction(CPPLINT_RECURSIVE)

