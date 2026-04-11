# --- Core tests (no external deps beyond doctest) ---
add_executable(test_strange
    ${CMAKE_CURRENT_SOURCE_DIR}/strange/taste__main.cpp)
target_link_libraries(test_strange PRIVATE strange doctest)
set_target_properties(test_strange PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/taste/strange)
add_test(NAME strange COMMAND test_strange)

# --- Baggage tests (serialization) ---
add_executable(test_baggage
    ${CMAKE_CURRENT_SOURCE_DIR}/strange/implementation/baggage/taste__baggage_main.cpp)
target_link_libraries(test_baggage PRIVATE strange doctest dart gsl rapidjson sajson)
set_target_properties(test_baggage PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/taste/strange/implementation/baggage)
add_test(NAME baggage COMMAND test_baggage)

# --- Graph tests (concurrency, requires stlab) ---
if(STRANGEN_HAS_STLAB)
    add_executable(test_graph
        ${CMAKE_CURRENT_SOURCE_DIR}/strange/implementation/graph/taste__graph_main.cpp)
    target_link_libraries(test_graph PRIVATE strange doctest dart gsl rapidjson sajson stlab_lib)
    set_target_properties(test_graph PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/taste/strange/implementation/graph)
    add_test(NAME graph COMMAND test_graph)
endif()
