cmake_minimum_required(VERSION 3.14)
project(strangen VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wno-missing-field-initializers -Wno-unused-parameter)

# --- External dependencies ---

# doctest (header-only, needed for tests)
find_path(DOCTEST_INCLUDE_DIR doctest.h
    HINTS ${CMAKE_SOURCE_DIR}/../doctest/doctest)
if(NOT DOCTEST_INCLUDE_DIR)
    message(FATAL_ERROR "doctest not found. Clone it to ${CMAKE_SOURCE_DIR}/../doctest")
endif()
add_library(doctest INTERFACE)
target_include_directories(doctest SYSTEM INTERFACE ${DOCTEST_INCLUDE_DIR})

# libdart (header-only, needed for baggage)
find_path(DART_INCLUDE_DIR dart.h
    HINTS ${CMAKE_SOURCE_DIR}/../libdart/include)
if(NOT DART_INCLUDE_DIR)
    message(FATAL_ERROR "libdart not found. Clone it to ${CMAKE_SOURCE_DIR}/../libdart")
endif()
add_library(dart INTERFACE)
target_include_directories(dart SYSTEM INTERFACE ${DART_INCLUDE_DIR})

# GSL (header-only, needed for baggage)
find_path(GSL_INCLUDE_DIR gsl/gsl
    HINTS ${CMAKE_SOURCE_DIR}/../GSL/include)
if(NOT GSL_INCLUDE_DIR)
    message(FATAL_ERROR "GSL not found. Clone it to ${CMAKE_SOURCE_DIR}/../GSL")
endif()
add_library(gsl INTERFACE)
target_include_directories(gsl SYSTEM INTERFACE ${GSL_INCLUDE_DIR})

# rapidjson (header-only, needed for baggage)
find_path(RAPIDJSON_INCLUDE_DIR rapidjson/rapidjson.h
    HINTS ${CMAKE_SOURCE_DIR}/../rapidjson/include)
if(NOT RAPIDJSON_INCLUDE_DIR)
    message(FATAL_ERROR "rapidjson not found. Clone it to ${CMAKE_SOURCE_DIR}/../rapidjson")
endif()
add_library(rapidjson INTERFACE)
target_include_directories(rapidjson SYSTEM INTERFACE ${RAPIDJSON_INCLUDE_DIR})

# sajson (header-only, needed for baggage)
find_path(SAJSON_INCLUDE_DIR sajson.h
    HINTS ${CMAKE_SOURCE_DIR}/../sajson/include)
if(NOT SAJSON_INCLUDE_DIR)
    message(FATAL_ERROR "sajson not found. Clone it to ${CMAKE_SOURCE_DIR}/../sajson")
endif()
add_library(sajson INTERFACE)
target_include_directories(sajson SYSTEM INTERFACE ${SAJSON_INCLUDE_DIR})

# stlab (library + headers, needed for graph/concurrency targets)
# Not working with clang for some reason — use -DSTRANGEN_ENABLE_STLAB=OFF to skip
option(STRANGEN_ENABLE_STLAB "Enable stlab-dependent targets (graph/concurrency)" ON)
set(STRANGEN_HAS_STLAB OFF)
if(STRANGEN_ENABLE_STLAB)
    find_path(STLAB_INCLUDE_DIR stlab/concurrency/concurrency.hpp
        HINTS ${CMAKE_SOURCE_DIR}/../stlab/include)
    find_path(STLAB_CONFIG_DIR stlab/config.hpp
        HINTS ${CMAKE_SOURCE_DIR}/../stlab-build/include
              ${CMAKE_SOURCE_DIR}/../BUILD/include)
    find_library(STLAB_LIBRARY stlab
        HINTS ${CMAKE_SOURCE_DIR}/../stlab-build
              ${CMAKE_SOURCE_DIR}/../BUILD)
    if(STLAB_INCLUDE_DIR AND STLAB_LIBRARY)
        find_package(Threads REQUIRED)
        add_library(stlab_lib INTERFACE)
        target_include_directories(stlab_lib SYSTEM INTERFACE ${STLAB_INCLUDE_DIR})
        if(STLAB_CONFIG_DIR)
            target_include_directories(stlab_lib SYSTEM INTERFACE ${STLAB_CONFIG_DIR})
        endif()
        target_link_libraries(stlab_lib INTERFACE ${STLAB_LIBRARY} Threads::Threads)
        set(STRANGEN_HAS_STLAB ON)
        message(STATUS "stlab found — graph/concurrency targets enabled")
    else()
        message(WARNING "stlab not found — graph/concurrency targets disabled. Build stlab first (see dogs/BAKE.md)")
    endif()
else()
    message(STATUS "stlab disabled — graph/concurrency targets skipped")
endif()

# --- Subdirectories ---

add_subdirectory(sauce)
add_subdirectory(snacks)

enable_testing()
add_subdirectory(taste)
