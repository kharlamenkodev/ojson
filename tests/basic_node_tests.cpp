#include <gtest/gtest.h>

#include "basic_node.hpp"

#include <nlohmann/json.hpp>

TEST(basic_node_tests, empty_json_must_contain_valid_content)
{
    ojson::BasicNode node({});

    EXPECT_EQ(node.content(), "{}");
}

TEST(basic_node_tests, json_with_string_value_must_contain_valid_content)
{
    ojson::BasicNode node({{"key", "Andrew"}});

    EXPECT_EQ(node.content(), "{\"key\":\"Andrew\"}");
}

TEST(basic_node_tests, json_with_integer_value_must_contain_valid_content)
{
    ojson::BasicNode node({{"key", 24}});

    EXPECT_EQ(node.content(), "{\"key\":24}");
}

TEST(basic_node_tests, json_with_double_value_must_contain_valid_content)
{
    ojson::BasicNode node({{"key", 1.1}});

    EXPECT_EQ(node.content(), "{\"key\":1.1}");
}

TEST(basic_node_tests, json_with_float_value_must_contain_valid_content)
{
    ojson::BasicNode node({{"key", 1.1F}});

    EXPECT_EQ(node.content().substr(0UL, 10), "{\"key\":1.1");
}

TEST(basic_node_tests, json_with_boolean_values_must_contain_valid_content)
{
    ojson::BasicNode node({{"positive", true}, {"negative", false}});

    EXPECT_EQ(node.content(), "{\"negative\":false,\"positive\":true}");
}

TEST(basic_node_tests, json_with_array_of_strings_must_contain_valid_content)
{
    ojson::BasicNode node({{"key", {"a", "b", "c", "d", "e"}}});

    EXPECT_EQ(node.content(), "{\"key\":[\"a\",\"b\",\"c\",\"d\",\"e\"]}");
}

TEST(basic_node_tests, json_with_array_of_integers_must_contain_valid_content)
{
    ojson::BasicNode node({{"key", {0, 1, 2, 3, 4}}});

    EXPECT_EQ(node.content(), "{\"key\":[0,1,2,3,4]}");
}

TEST(basic_node_tests, json_with_array_of_doubles_must_contain_valid_content)
{
    ojson::BasicNode node({{"key", {0.4, 1.4, 2.4, 3.4, 4.4}}});

    EXPECT_EQ(node.content(), "{\"key\":[0.4,1.4,2.4,3.4,4.4]}");
}

TEST(basic_node_tests, json_with_array_of_booleans_must_contain_valid_content)
{
    ojson::BasicNode node({{"key", {false, true, false, true, true}}});

    EXPECT_EQ(node.content(), "{\"key\":[false,true,false,true,true]}");
}

TEST(basic_node_tests, json_with_array_of_arrays_must_contain_valid_content)
{
    ojson::BasicNode node({{"key", {{0, 1, 2, 3, 4}, {5, 6, 7, 8, 9}, {10, 11, 12, 13, 14}}}});

    EXPECT_EQ(node.content(), "{\"key\":[[0,1,2,3,4],[5,6,7,8,9],[10,11,12,13,14]]}");
}