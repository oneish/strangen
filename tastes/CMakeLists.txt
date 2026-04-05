# --- Core tests (no external deps beyond doctest) ---
add_executable(test_strange
    ${CMAKE_CURRENT_SOURCE_DIR}/strange/taste__main.cpp)
target_link_libraries(test_strange PRIVATE strange doctest)
add_test(NAME strange COMMAND test_strange)

# --- Baggage tests (serialization) ---
add_executable(test_baggage
    ${CMAKE_CURRENT_SOURCE_DIR}/strange/implementation/baggage/taste__baggage_main.cpp)
target_link_libraries(test_baggage PRIVATE strange doctest dart gsl rapidjson sajson)
add_test(NAME baggage COMMAND test_baggage)

# --- Graph tests (concurrency) ---
add_executable(test_graph
    ${CMAKE_CURRENT_SOURCE_DIR}/strange/implementation/graph/taste__graph_main.cpp)
target_link_libraries(test_graph PRIVATE strange doctest dart gsl rapidjson sajson stlab_lib)
add_test(NAME graph COMMAND test_graph)
