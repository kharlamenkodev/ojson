find_package(GTest REQUIRED)

set(BASIC_NODE_TESTS basic_node_tests)

add_executable(${BASIC_NODE_TESTS}
                basic_node_tests.cpp
                node_as_array_tests.cpp
                node_as_string_tests.cpp
                node_as_double_tests.cpp
                node_as_integer_tests.cpp
                node_as_boolean_tests.cpp)

target_link_libraries(
    ${BASIC_NODE_TESTS}
    GTest::gtest_main
)

target_include_directories(${BASIC_NODE_TESTS} PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_test(${BASIC_NODE_TESTS} ${BASIC_NODE_TESTS})