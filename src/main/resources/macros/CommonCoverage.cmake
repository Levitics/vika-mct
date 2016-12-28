if(ENABLE_COVERAGE)
    if(NOT COVERAGE_LIMITS)
        set(COVERAGE_LIMITS --rc genhtml_med_limit=40 --rc genhtml_hi_limit=80)
    endif(NOT COVERAGE_LIMITS)

    set(LCOV_OPTIONS "--quiet")
    set(LCOV_GENTHML_OPTIONS "--demangle-cpp")

    if(LCOV_BRANCH_COVERAGE)
        list(APPEND LCOV_OPTIONS "--rc" "lcov_branch_coverage=1")
        list(APPEND LCOV_GENTHML_OPTIONS "--branch-coverage")
    else()
        list(APPEND LCOV_OPTIONS "--rc" "lcov_branch_coverage=0")
        list(APPEND LCOV_GENTHML_OPTIONS "--no-branch-coverage")
    endif()

    if(LCOV_FUNCTION_COVERAGE)
        list(APPEND LCOV_OPTIONS "--rc" "lcov_function_coverage=1")
        list(APPEND LCOV_GENTHML_OPTIONS "--function-coverage" "--demangle-cpp")
    else()
        list(APPEND LCOV_OPTIONS "--rc" "lcov_function_coverage=0")
        list(APPEND LCOV_GENTHML_OPTIONS "--no-function-coverage")
    endif()

    set(LCOV_EXTRA_ARGS --base-directory "${CPP_SOURCE_DIR}" 
            --directory "${OUTPUT_DIR}"
            --no-external
            --gcov-tool "${COVERAGE_COMMAND}"
            --rc lcov_branch_coverage=1
            --rc geninfo_all_blocks=true)
    set(GENHTML_EXTRA_ARGS --show-details --frames --legend
            --branch-coverage --function-coverage --sort
            --demangle-cpp
            --title "${PROJECT_NAME}")

    set(COVERAGE_FLAGS "-g -O0 --coverage -Wall -Wextra -Wpedantic")
    set(COVERAGE_LINK_FLAGS "--coverage -fprofile-arcs -ftest-coverage ") # -lgcov

    set(CMAKE_CXX_FLAGS_COVERAGE
        "${COVERAGE_FLAGS} -fprofile-arcs -ftest-coverage"
        CACHE STRING "Flags used by the C++ compiler during coverage builds."
        FORCE 
    )

    set(CMAKE_C_FLAGS_COVERAGE
        "${COVERAGE_FLAGS} -fprofile-arcs -ftest-coverage"
        CACHE STRING "Flags used by the C compiler during coverage builds."
        FORCE 
    )

    set(CMAKE_EXE_LINKER_FLAGS_COVERAGE
        "${COVERAGE_LINK_FLAGS}"
        CACHE STRING "Flags used for linking binaries during coverage builds."
        FORCE 
    )

    set(CMAKE_SHARED_LINKER_FLAGS_COVERAGE
        "${COVERAGE_LINK_FLAGS}"
        CACHE STRING "Flags used by the shared libraries linker during coverage builds."
        FORCE 
    )

    mark_as_advanced(
        CMAKE_CXX_FLAGS_COVERAGE
        CMAKE_C_FLAGS_COVERAGE
        CMAKE_EXE_LINKER_FLAGS_COVERAGE
        CMAKE_SHARED_LINKER_FLAGS_COVERAGE
    )

    if(CMAKE_COMPILER_IS_GNUCXX)
        find_program(GCOVR gcovr)
        find_program(GENHTML genhtml)
        find_program(LCOV lcov)
        find_program(GENINFO geninfo)
        mark_as_advanced(LCOV GENINFO GENHTML GCOVR)

        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${CMAKE_CXX_FLAGS_COVERAGE}")
        set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${CMAKE_CXX_FLAGS_COVERAGE}")

    else(CMAKE_COMPILER_IS_GNUCXX)
            message(FATAL_ERROR "No code coverage report, unsupported compiler")
    endif(CMAKE_COMPILER_IS_GNUCXX)

else(ENABLE_COVERAGE)
    message(STATUS "Code coverage skipped.")
endif(ENABLE_COVERAGE)

function(add_coverage_targets TEST_TARGET MODULE_NAME MODULE_DIRECTORY) 

    set(COVERAGE_WORKING_DIR "${TARGET_BUILD_DIRECTORY}/qa/coverage/${MODULE_NAME}")
    set(COVERAGE_RAW_FILE "${COVERAGE_WORKING_DIR}/coverage.raw.info")
    set(COVERAGE_FILTERED_FILE "${COVERAGE_WORKING_DIR}/coverage.info")
    set(COVERAGE_REPORT_DIR "${COVERAGE_WORKING_DIR}/coveragereport")
    file(MAKE_DIRECTORY ${COVERAGE_WORKING_DIR})

    if(NOT TARGET coverage)
        add_custom_target(coverage
            COMMENT "Running ${MODULE_NAME} coverage report."
        )
    endif()

    add_custom_command(TARGET coverage
        COMMAND lcov --directory ${MODULE_DIRECTORY} --zerocounters
        WORKING_DIRECTORY ${COVERAGE_WORKING_DIR}
    )

    add_custom_command(TARGET coverage
        COMMAND make test
        WORKING_DIRECTORY ${COVERAGE_WORKING_DIR}
    )

    add_custom_command(TARGET coverage
        COMMAND lcov --directory ${MODULE_DIRECTORY} --capture --output-file ${COVERAGE_WORKING_DIR}/${MODULE_NAME}.info
        WORKING_DIRECTORY ${COVERAGE_WORKING_DIR}
    )

    add_custom_command(TARGET coverage
        COMMAND genhtml -o ${COVERAGE_WORKING_DIR} ${COVERAGE_WORKING_DIR}/${MODULE_NAME}.info
        WORKING_DIRECTORY ${COVERAGE_WORKING_DIR}
    )

    add_custom_command(TARGET coverage
        COMMAND echo "Open ${COVERAGE_WORKING_DIR}/index.html to view the coverage analysis results."
        WORKING_DIRECTORY ${COVERAGE_WORKING_DIR}
    )

#    add_dependencies(coverage ${MODULE_NAME}-coverage)

endfunction()
