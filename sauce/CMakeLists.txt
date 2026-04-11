# --- strangen code generator tool ---
add_executable(strangen generation/strange__generation.cpp)
set_target_properties(strangen PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/sauce/generation)

# --- strange interface library (header-only) ---
add_library(strange INTERFACE)
target_include_directories(strange INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/strange)

# --- Meta regeneration (self-hosting bootstrap) ---
# Two-pass verification: regenerate strange__space.h twice and compare outputs.
# If they differ, the generated code doesn't faithfully reproduce itself.

set(META_DIR ${CMAKE_CURRENT_SOURCE_DIR}/strange/meta)
set(META_BUILD_DIR ${CMAKE_BINARY_DIR}/sauce/strange/meta)
set(SPACE_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/strange/space/strange__space.h)
set(PASS1_OUTPUT ${META_BUILD_DIR}/pass1_strange__space.h)
set(PASS2_OUTPUT ${META_BUILD_DIR}/pass2_strange__space.h)

add_custom_target(regenerate_space ALL
    DEPENDS strangen
        ${META_DIR}/strange__space_meta.h
        ${META_DIR}/strange__space_prototype.h
        ${CMAKE_CURRENT_SOURCE_DIR}/strange/meta/strange__transformation.h
        ${CMAKE_CURRENT_SOURCE_DIR}/strange/comprehension/strange__comprehension__parser.h
        ${CMAKE_CURRENT_SOURCE_DIR}/strange/comprehension/strange__comprehension__toker.h
        ${CMAKE_CURRENT_SOURCE_DIR}/strange/reflection/strange__reflection.h
        ${CMAKE_CURRENT_SOURCE_DIR}/strange/common/strange__common.h
    COMMAND ${CMAKE_COMMAND} -E make_directory ${META_BUILD_DIR}
    # Pass 1: generate using the checked-in header
    COMMAND $<TARGET_FILE:strangen> ${META_DIR}/strange__space_meta.h ${META_BUILD_DIR}/strange__space_meta.cpp
    COMMAND ${CMAKE_COMMAND} -E copy ${META_BUILD_DIR}/strange__space_meta.cpp ${META_DIR}/strange__space_meta.cpp
    COMMAND ${CMAKE_CXX_COMPILER} -std=c++17 -Wall -I${META_DIR}/.. -I${META_DIR} ${META_BUILD_DIR}/strange__space_meta.cpp -o ${META_BUILD_DIR}/meta_gen
    COMMAND ${META_BUILD_DIR}/meta_gen > ${PASS1_OUTPUT}
    # Pass 2: regenerate using the pass 1 output
    COMMAND ${CMAKE_COMMAND} -E copy ${PASS1_OUTPUT} ${SPACE_HEADER}
    COMMAND $<TARGET_FILE:strangen> ${META_DIR}/strange__space_meta.h ${META_BUILD_DIR}/strange__space_meta_p2.cpp
    COMMAND ${CMAKE_CXX_COMPILER} -std=c++17 -Wall -I${META_DIR}/.. -I${META_DIR} ${META_BUILD_DIR}/strange__space_meta_p2.cpp -o ${META_BUILD_DIR}/meta_gen_p2
    COMMAND ${META_BUILD_DIR}/meta_gen_p2 > ${PASS2_OUTPUT}
    # Compare: pass 1 and pass 2 must be identical
    COMMAND ${CMAKE_COMMAND} -E compare_files ${PASS1_OUTPUT} ${PASS2_OUTPUT}
    # Install final output
    COMMAND ${CMAKE_COMMAND} -E copy ${PASS2_OUTPUT} ${SPACE_HEADER}
    WORKING_DIRECTORY ${META_DIR}
    COMMENT "Regenerating strange__space.h (two-pass bootstrap verification)"
)
