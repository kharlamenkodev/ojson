find_package(GTest REQUIRED)

enable_testing()

set(BASIC_NODE_TESTS basic_node_tests)

add_executable(${BASIC_NODE_TESTS}
                basic_node_tests.cpp
                node_as_integer_tests.cpp)

target_link_libraries(
    ${BASIC_NODE_TESTS}
    GTest::gtest_main
)

target_include_directories(${BASIC_NODE_TESTS} PUBLIC ${PROJECT_SOURCE_DIR}/include)