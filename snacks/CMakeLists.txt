# --- Code generation for bananas ---
set(BANANAS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bananas)
set(BANANAS_BUILD_DIR ${CMAKE_BINARY_DIR}/snacks/bananas)
set(BANANAS_SPACE_HEADER ${BANANAS_BUILD_DIR}/bananas__space.h)

add_custom_command(
    OUTPUT ${BANANAS_SPACE_HEADER}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${BANANAS_BUILD_DIR}
    # Hash checked-in header before generation
    COMMAND ${CMAKE_COMMAND} -E md5sum ${BANANAS_DIR}/bananas__space.h > ${BANANAS_BUILD_DIR}/bananas__space.h.old_hash
    # Generate
    COMMAND $<TARGET_FILE:enstrange> ${BANANAS_DIR}/bananas__space_prototype.h ${BANANAS_SPACE_HEADER}
    # Copy header to source immediately
    COMMAND ${CMAKE_COMMAND} -E copy ${BANANAS_SPACE_HEADER} ${BANANAS_DIR}/bananas__space.h
    # Hash comparison: fail if header changed from checked-in version
    COMMAND ${CMAKE_COMMAND} -E md5sum ${BANANAS_DIR}/bananas__space.h > ${BANANAS_BUILD_DIR}/bananas__space.h.new_hash
    COMMAND ${CMAKE_COMMAND} -E compare_files ${BANANAS_BUILD_DIR}/bananas__space.h.old_hash ${BANANAS_BUILD_DIR}/bananas__space.h.new_hash
    DEPENDS enstrange ${BANANAS_DIR}/bananas__space_prototype.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/strange.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/space/strange__space.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/meta/strange__transformation.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/comprehension/strange__comprehension__parser.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/comprehension/strange__comprehension__toker.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/reflection/strange__reflection.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/common/strange__common.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/common/strange__hash.h
    WORKING_DIRECTORY ${BANANAS_DIR}
    COMMENT "Generating bananas__space.h"
)

add_executable(bananas ${BANANAS_DIR}/bananas__main.cpp ${BANANAS_SPACE_HEADER})
target_link_libraries(bananas PRIVATE strange dart gsl rapidjson sajson)
target_include_directories(bananas PRIVATE ${BANANAS_BUILD_DIR} ${BANANAS_DIR})
set_target_properties(bananas PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BANANAS_BUILD_DIR})

# --- Code generation for toast ---
set(TOAST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/toast)
set(TOAST_BUILD_DIR ${CMAKE_BINARY_DIR}/snacks/toast)
set(TOAST_SPACE_HEADER ${TOAST_BUILD_DIR}/toast__space_transformation_3.h)

add_custom_command(
    OUTPUT ${TOAST_SPACE_HEADER}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${TOAST_BUILD_DIR}
    # Hash checked-in header before generation
    COMMAND ${CMAKE_COMMAND} -E md5sum ${TOAST_DIR}/toast__space_transformation_3.h > ${TOAST_BUILD_DIR}/toast__space_transformation_3.h.old_hash
    # Generate
    COMMAND $<TARGET_FILE:strangen> ${TOAST_DIR}/toast__space_transformation_1.h ${TOAST_BUILD_DIR}/toast__space_transformation_2.cpp
    COMMAND ${CMAKE_COMMAND} -E copy ${TOAST_BUILD_DIR}/toast__space_transformation_2.cpp ${TOAST_DIR}/toast__space_transformation_2.cpp
    COMMAND ${CMAKE_CXX_COMPILER} -std=c++17 -Wall
        -I${CMAKE_SOURCE_DIR}/sauce/strange
        -I${CMAKE_SOURCE_DIR}/sauce/strange/meta
        -I${TOAST_DIR}
        ${TOAST_BUILD_DIR}/toast__space_transformation_2.cpp
        -o ${TOAST_BUILD_DIR}/toast_gen
    COMMAND ${TOAST_BUILD_DIR}/toast_gen > ${TOAST_SPACE_HEADER}
    # Copy header to source immediately
    COMMAND ${CMAKE_COMMAND} -E copy ${TOAST_SPACE_HEADER} ${TOAST_DIR}/toast__space_transformation_3.h
    # Hash comparison: fail if header changed from checked-in version
    COMMAND ${CMAKE_COMMAND} -E md5sum ${TOAST_DIR}/toast__space_transformation_3.h > ${TOAST_BUILD_DIR}/toast__space_transformation_3.h.new_hash
    COMMAND ${CMAKE_COMMAND} -E compare_files ${TOAST_BUILD_DIR}/toast__space_transformation_3.h.old_hash ${TOAST_BUILD_DIR}/toast__space_transformation_3.h.new_hash
    DEPENDS strangen ${TOAST_DIR}/toast__space_transformation_1.h
        ${TOAST_DIR}/toast__space_definition.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/meta/strange__transformation.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/comprehension/strange__comprehension__parser.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/comprehension/strange__comprehension__toker.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/reflection/strange__reflection.h
        ${CMAKE_SOURCE_DIR}/sauce/strange/common/strange__common.h
    WORKING_DIRECTORY ${TOAST_DIR}
    COMMENT "Generating toast__space_transformation_3.h"
)

add_executable(toast ${TOAST_DIR}/toast__type_erasure_main.cpp ${TOAST_SPACE_HEADER})
target_link_libraries(toast PRIVATE strange)
target_include_directories(toast PRIVATE ${TOAST_BUILD_DIR} ${TOAST_DIR})
set_target_properties(toast PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TOAST_BUILD_DIR})

# --- Cabbage toast ---
add_executable(cabbage ${CMAKE_CURRENT_SOURCE_DIR}/cabbage/cabbage__main.cpp)
target_link_libraries(cabbage PRIVATE strange dart gsl rapidjson sajson)
target_include_directories(cabbage PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/cabbage)
set_target_properties(cabbage PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/snacks/cabbage)

# --- Currants toast (requires stlab) ---
if(STRANGEN_HAS_STLAB)
    add_executable(currants ${CMAKE_CURRENT_SOURCE_DIR}/currants/currants__main.cpp)
    target_link_libraries(currants PRIVATE strange dart gsl rapidjson sajson stlab_lib)
    target_include_directories(currants PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/currants)
    set_target_properties(currants PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/snacks/currants)
endif()
