# --- Code generation for demo ---
set(DEMO_DIR ${CMAKE_CURRENT_SOURCE_DIR}/demo)
set(DEMO_SPACE_HEADER ${DEMO_DIR}/demo__space.h)

add_custom_command(
    OUTPUT ${DEMO_SPACE_HEADER}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/demo
    COMMAND $<TARGET_FILE:strangen> ${DEMO_DIR}/demo__space_meta.h ${CMAKE_BINARY_DIR}/demo/demo__space_meta.cpp
    COMMAND ${CMAKE_CXX_COMPILER} -std=c++17 -Wall
        -I${CMAKE_SOURCE_DIR}/sauce/strange
        -I${CMAKE_SOURCE_DIR}/sauce/strange/meta
        ${CMAKE_BINARY_DIR}/demo/demo__space_meta.cpp
        -o ${CMAKE_BINARY_DIR}/demo/demo_gen
    COMMAND ${CMAKE_BINARY_DIR}/demo/demo_gen > ${DEMO_SPACE_HEADER}
    DEPENDS strangen ${DEMO_DIR}/demo__space_meta.h ${DEMO_DIR}/demo__space_prototype.h
    WORKING_DIRECTORY ${DEMO_DIR}
    COMMENT "Generating demo__space.h"
)

add_executable(demo ${DEMO_DIR}/demo__main.cpp ${DEMO_SPACE_HEADER})
target_link_libraries(demo PRIVATE strange dart gsl rapidjson sajson)
target_include_directories(demo PRIVATE ${DEMO_DIR})

# --- Code generation for example ---
set(EXAMPLE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/example)
set(EXAMPLE_SPACE_HEADER ${EXAMPLE_DIR}/example__space_transformation_3.h)

add_custom_command(
    OUTPUT ${EXAMPLE_SPACE_HEADER}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/example
    COMMAND $<TARGET_FILE:strangen> ${EXAMPLE_DIR}/example__space_transformation_1.h ${CMAKE_BINARY_DIR}/example/example__space_transformation_2.cpp
    COMMAND ${CMAKE_CXX_COMPILER} -std=c++17 -Wall
        -I${CMAKE_SOURCE_DIR}/sauce/strange
        -I${CMAKE_SOURCE_DIR}/sauce/strange/meta
        -I${EXAMPLE_DIR}
        ${CMAKE_BINARY_DIR}/example/example__space_transformation_2.cpp
        -o ${CMAKE_BINARY_DIR}/example/example_gen
    COMMAND ${CMAKE_BINARY_DIR}/example/example_gen > ${EXAMPLE_SPACE_HEADER}
    DEPENDS strangen ${EXAMPLE_DIR}/example__space_transformation_1.h
    WORKING_DIRECTORY ${EXAMPLE_DIR}
    COMMENT "Generating example__space_transformation_3.h"
)

add_executable(example ${EXAMPLE_DIR}/example__type_erasure_main.cpp ${EXAMPLE_SPACE_HEADER})
target_link_libraries(example PRIVATE strange)
target_include_directories(example PRIVATE ${EXAMPLE_DIR})

# --- Baggage example ---
add_executable(baggage_example ${CMAKE_CURRENT_SOURCE_DIR}/baggage/baggage__main.cpp)
target_link_libraries(baggage_example PRIVATE strange dart gsl rapidjson sajson)
target_include_directories(baggage_example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/baggage)

# --- Currants example ---
add_executable(currants_example ${CMAKE_CURRENT_SOURCE_DIR}/currants/currants__main.cpp)
target_link_libraries(currants_example PRIVATE strange dart gsl rapidjson sajson stlab_lib)
target_include_directories(currants_example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/currants)
