cmake_minimum_required(VERSION 3.0)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING
            "Choose the type of build, options are: Debug Releas." FORCE)
endif()

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

if (WIN32)
    if (CMAKE_SIZEOF_VOID_P EQUAL 4)
        set(JLINK_DLL JLinkARM.dll)
    else ()
        set(JLINK_DLL JLink_x64.dll)
    endif ()
    find_file(JLINK_DLL_PATH ${JLINK_DLL} ${CMAKE_CURRENT_SOURCE_DIR} $ENV{Path})
    if (JLINK_DLL_PATH)
        message(STATUS "Found ${JLINK_DLL} ${JLINK_DLL_PATH}")
        message(STATUS "JLINK_LIB_PATH=${CMAKE_INSTALL_PREFIX}/bin/${JLINK_DLL}")
        target_compile_definitions(${PROJECT_NAME} PRIVATE JLINK_LIB_PATH="${CMAKE_INSTALL_PREFIX}/bin/${JLINK_DLL}")
    else ()
        message(WARNING "Not Found ${JLINK_DLL}")
    endif ()
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
