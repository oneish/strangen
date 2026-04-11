# --- Code generation for demo ---
set(DEMO_DIR ${CMAKE_CURRENT_SOURCE_DIR}/demo)
set(DEMO_BUILD_DIR ${CMAKE_BINARY_DIR}/snacks/demo)
set(DEMO_SPACE_HEADER ${DEMO_BUILD_DIR}/demo__space.h)

add_custom_command(
    OUTPUT ${DEMO_SPACE_HEADER}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${DEMO_BUILD_DIR}
    # Hash checked-in header before generation
    COMMAND ${CMAKE_COMMAND} -E md5sum ${DEMO_DIR}/demo__space.h > ${DEMO_BUILD_DIR}/demo__space.h.old_hash
    # Generate
    COMMAND $<TARGET_FILE:strangen> ${DEMO_DIR}/demo__space_meta.h ${DEMO_BUILD_DIR}/demo__space_meta.cpp
    COMMAND ${CMAKE_COMMAND} -E copy ${DEMO_BUILD_DIR}/demo__space_meta.cpp ${DEMO_DIR}/demo__space_meta.cpp
    COMMAND ${CMAKE_CXX_COMPILER} -std=c++17 -Wall
        -I${CMAKE_SOURCE_DIR}/sauce/strange
        -I${CMAKE_SOURCE_DIR}/sauce/strange/meta
        ${DEMO_BUILD_DIR}/demo__space_meta.cpp
        -o ${DEMO_BUILD_DIR}/demo_gen
    COMMAND ${DEMO_BUILD_DIR}/demo_gen > ${DEMO_SPACE_HEADER}
    # Copy header to source immediately
    COMMAND ${CMAKE_COMMAND} -E copy ${DEMO_SPACE_HEADER} ${DEMO_DIR}/demo__space.h
    # Hash comparison: fail if header changed from checked-in version
    COMMAND ${CMAKE_COMMAND} -E md5sum ${DEMO_DIR}/demo__space.h > ${DEMO_BUILD_DIR}/demo__space.h.new_hash
    COMMAND ${CMAKE_COMMAND} -E compare_files ${DEMO_BUILD_DIR}/demo__space.h.old_hash ${DEMO_BUILD_DIR}/demo__space.h.new_hash
    DEPENDS strangen ${DEMO_DIR}/demo__space_meta.h ${DEMO_DIR}/demo__space_prototype.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/strange.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/meta/strange__transformation.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/comprehension/strange__comprehension__parser.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/comprehension/strange__comprehension__toker.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/reflection/strange__reflection.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/common/strange__common.h
    WORKING_DIRECTORY ${DEMO_DIR}
    COMMENT "Generating demo__space.h"
)

add_executable(demo ${DEMO_DIR}/demo__main.cpp ${DEMO_SPACE_HEADER})
target_link_libraries(demo PRIVATE strange dart gsl rapidjson sajson)
target_include_directories(demo PRIVATE ${DEMO_BUILD_DIR} ${DEMO_DIR})
set_target_properties(demo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${DEMO_BUILD_DIR})

# --- Code generation for example ---
set(EXAMPLE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/example)
set(EXAMPLE_BUILD_DIR ${CMAKE_BINARY_DIR}/snacks/example)
set(EXAMPLE_SPACE_HEADER ${EXAMPLE_BUILD_DIR}/example__space_transformation_3.h)

add_custom_command(
    OUTPUT ${EXAMPLE_SPACE_HEADER}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${EXAMPLE_BUILD_DIR}
    # Hash checked-in header before generation
    COMMAND ${CMAKE_COMMAND} -E md5sum ${EXAMPLE_DIR}/example__space_transformation_3.h > ${EXAMPLE_BUILD_DIR}/example__space_transformation_3.h.old_hash
    # Generate
    COMMAND $<TARGET_FILE:strangen> ${EXAMPLE_DIR}/example__space_transformation_1.h ${EXAMPLE_BUILD_DIR}/example__space_transformation_2.cpp
    COMMAND ${CMAKE_COMMAND} -E copy ${EXAMPLE_BUILD_DIR}/example__space_transformation_2.cpp ${EXAMPLE_DIR}/example__space_transformation_2.cpp
    COMMAND ${CMAKE_CXX_COMPILER} -std=c++17 -Wall
        -I${CMAKE_SOURCE_DIR}/sauce/strange
        -I${CMAKE_SOURCE_DIR}/sauce/strange/meta
        -I${EXAMPLE_DIR}
        ${EXAMPLE_BUILD_DIR}/example__space_transformation_2.cpp
        -o ${EXAMPLE_BUILD_DIR}/example_gen
    COMMAND ${EXAMPLE_BUILD_DIR}/example_gen > ${EXAMPLE_SPACE_HEADER}
    # Copy header to source immediately
    COMMAND ${CMAKE_COMMAND} -E copy ${EXAMPLE_SPACE_HEADER} ${EXAMPLE_DIR}/example__space_transformation_3.h
    # Hash comparison: fail if header changed from checked-in version
    COMMAND ${CMAKE_COMMAND} -E md5sum ${EXAMPLE_DIR}/example__space_transformation_3.h > ${EXAMPLE_BUILD_DIR}/example__space_transformation_3.h.new_hash
    COMMAND ${CMAKE_COMMAND} -E compare_files ${EXAMPLE_BUILD_DIR}/example__space_transformation_3.h.old_hash ${EXAMPLE_BUILD_DIR}/example__space_transformation_3.h.new_hash
    DEPENDS strangen ${EXAMPLE_DIR}/example__space_transformation_1.h
        ${EXAMPLE_DIR}/example__space_definition.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/meta/strange__transformation.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/comprehension/strange__comprehension__parser.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/comprehension/strange__comprehension__toker.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/reflection/strange__reflection.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/common/strange__common.h
    WORKING_DIRECTORY ${EXAMPLE_DIR}
    COMMENT "Generating example__space_transformation_3.h"
)

add_executable(example ${EXAMPLE_DIR}/example__type_erasure_main.cpp ${EXAMPLE_SPACE_HEADER})
target_link_libraries(example PRIVATE strange)
target_include_directories(example PRIVATE ${EXAMPLE_BUILD_DIR} ${EXAMPLE_DIR})
set_target_properties(example PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXAMPLE_BUILD_DIR})

# --- Baggage example ---
add_executable(baggage ${CMAKE_CURRENT_SOURCE_DIR}/baggage/baggage__main.cpp)
target_link_libraries(baggage PRIVATE strange dart gsl rapidjson sajson)
target_include_directories(baggage PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/baggage)
set_target_properties(baggage PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/snacks/baggage)

# --- Currants example (requires stlab) ---
if(STRANGEN_HAS_STLAB)
    add_executable(currants ${CMAKE_CURRENT_SOURCE_DIR}/currants/currants__main.cpp)
    target_link_libraries(currants PRIVATE strange dart gsl rapidjson sajson stlab_lib)
    target_include_directories(currants PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/currants)
    set_target_properties(currants PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/snacks/currants)
endif()
