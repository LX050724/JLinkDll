cmake_minimum_required(VERSION 3.21)
project(JLinkDll)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR YES)


if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS YES)
    if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        add_compile_options("/utf-8")
    else()
        message(FATAL_ERROR "Unsupported Compiler ${CMAKE_CXX_COMPILER_ID}")
    endif()
else()
    message(FATAL_ERROR "Linux currently not supported")
endif()


file(GLOB_RECURSE SRC JLink/*.*)
add_library(JLinkDLL SHARED ${SRC})
set_target_properties(JLinkDLL PROPERTIES LINKER_LANGUAGE C)

if(WIN32)
    if(CMAKE_SIZEOF_VOID_P EQUAL 4)
        set(JLINK_DLL JLinkARM.dll)
    else()
        set(JLINK_DLL JLink_x64.dll)
    endif()
    find_file(JLINK_X64_DLL_PATH ${JLINK_DLL} ${CMAKE_CURRENT_SOURCE_DIR} $ENV{Path})
    if (JLINK_X64_DLL_PATH)
        message(STATUS "Found ${JLINK_DLL} ${JLINK_X64_DLL_PATH}")
        target_compile_definitions(JLinkDLL PUBLIC JLINK_LIB_PATH="${JLINK_X64_DLL_PATH}")
    else()
        message(WARNING "Not Found ${JLINK_DLL}")
    endif()
endif()

add_executable(Test main.cpp)
target_link_libraries(Test JLinkDLL)

