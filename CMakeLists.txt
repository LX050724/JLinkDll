cmake_minimum_required(VERSION 3.6)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING
            "Choose the type of build, options are: Debug Releas." FORCE)
endif ()

set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Release Debug)

project(JLinkDLL)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR YES)

if (WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS YES)
    if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        add_compile_options("/utf-8")
    else ()
        message(FATAL_ERROR "Unsupported Compiler ${CMAKE_CXX_COMPILER_ID}")
    endif ()
else ()
    message(FATAL_ERROR "Linux currently not supported")
endif ()


file(GLOB_RECURSE SRC JLink/*.c)
add_library(${PROJECT_NAME} SHARED ${SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE C)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME_DEBUG "${PROJECT_NAME}_d")

set(DEFAULT_JLINK_DLL "" CACHE PATH "Use custom DLL paths")

if (DEFAULT_JLINK_DLL)
    message(STATUS "Use User Define JLinkDLL ${DEFAULT_JLINK_DLL}")
    target_compile_definitions(${PROJECT_NAME} PRIVATE JLINK_LIB_PATH="${DEFAULT_JLINK_DLL}")
endif ()

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>)

file(GLOB_RECURSE HEADER JLink/*.h)
foreach (f ${HEADER})
    file(RELATIVE_PATH HEADER_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${f})
    get_filename_component(SECOND_FOLDER ${HEADER_PATH} DIRECTORY)
    install(FILES ${f} DESTINATION include/${SECOND_FOLDER})
endforeach ()

if (JLINK_DLL)
    install(FILES ${JLINK_DLL} DESTINATION bin)
endif ()

add_executable(${PROJECT_NAME}_Version version.cpp)
target_link_libraries(${PROJECT_NAME}_Version PUBLIC ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME}_Version PROPERTIES OUTPUT_NAME_DEBUG "${PROJECT_NAME}_Version_d")

find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile_out)
    set(DOCUMENT_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/JLinkDLL_doc)

    if (NOT EXISTS ${DOCUMENT_OUTPUT_DIRECTORY})
        file(MAKE_DIRECTORY ${DOCUMENT_OUTPUT_DIRECTORY})
    endif ()
    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    # note the option ALL which allows to build the docs together with the application
    add_custom_target(${PROJECT_NAME}_document ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)

    install(DIRECTORY ${DOCUMENT_OUTPUT_DIRECTORY}
            TYPE DOC)

else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}-targets
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION include)

install(EXPORT ${PROJECT_NAME}-targets
        FILE ${PROJECT_NAME}Config.cmake
        DESTINATION lib/cmake)

install(TARGETS ${PROJECT_NAME}_Version
        RUNTIME DESTINATION bin)
