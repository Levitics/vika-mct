include(CMakeParseArguments)
set(UNCRUSTIFY_EXE "uncrustify")

#set (UNCRUSTIFY_CONFIG "${PROJECT_SOURCE_DIR}/src/main/resources/config/style.cfg")
set (UNCRUSTIFY_CONFIG "${PROJECT_SOURCE_DIR}/src/main/resources/config/uncrustify.cfg")

macro(UNCRUSTIFY_CMD VAR input output)
    set(cmd "${UNCRUSTIFY_PATH}")
    list(APPEND cmd -c ${UNCRUSTIFY_CONFIG})
    list(APPEND cmd -f ${input})
#    list(APPEND cmd -o ${output})
    list(APPEND cmd -L 2)
    display(${VAR})
    set(${VAR} "${cmd}")
endmacro(UNCRUSTIFY_CMD)

add_custom_target(uncrustify
                COMMENT "Prettying source code with uncrustify")

function(UncrustifyDir file_list_var)
    get_filename_component(THIS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/main/cpp" NAME)
    set(THIS_TS "${CMAKE_CURRENT_SOURCE_DIR}/.uncrustify_time")

    add_custom_command(
        OUTPUT "${THIS_TS}"
        COMMAND "${UNCRUSTIFY_EXE}" --replace --no-backup -c "${UNCRUSTIFY_CONFIG}" ${${file_list_var}}
        COMMAND touch "${THIS_TS}"
        DEPENDS ${${file_list_var}} "${UNCRUSTIFY_CONFIG}"
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        COMMENT "Uncrustifying ${THIS_DIR}")

    add_custom_target(
        "uncrustify-${THIS_DIR}"
        DEPENDS "${THIS_TS}")
        add_dependencies(uncrustify "uncrustify-${THIS_DIR}")
endfunction()
