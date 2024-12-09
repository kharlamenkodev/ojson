#include <gtest/gtest.h>

#include "basic_node.hpp"
#include "node_as_array.hpp"
#include "node_as_integer.hpp"

#include <nlohmann/json.hpp>

TEST(node_as_array_tests, array_from_basic_node_must_have_size_4)
{
    ojson::BasicNode root_node({{"name", "Andrew"}, {"numbers", {1, 2, 3, 4}}});

    auto node = root_node.node("numbers");
    auto as_array_node = ojson::NodeAsArray(node);

    EXPECT_EQ(as_array_node.size(), 4);
}

TEST(node_as_array_tests, by_square_brackets_operator_accessed_elements_must_be_valid)
{
    ojson::BasicNode root_node({{"name", "Andrew"}, {"numbers", {0, 1, 2, 3}}});

    auto node = root_node.node("numbers");
    auto as_array_node = ojson::NodeAsArray(node);

    for (size_t i = 0; i < as_array_node.size(); i++) {
        int number = ojson::NodeAsInteger(as_array_node[i]).value();
        EXPECT_EQ(number, i);
    }
}