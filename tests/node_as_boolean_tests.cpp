#include <gtest/gtest.h>

#include "basic_node.hpp"
#include "node_as_boolean.hpp"

#include <nlohmann/json.hpp>

TEST(node_as_boolean_tests, positive_negative_values_must_be_valid)
{
    ojson::BasicNode root_node({
        {"positive", true},
        {"negative", false},
    });

    bool positive = ojson::NodeAsBoolean(root_node.node("positive")).value();
    bool negative = ojson::NodeAsBoolean(root_node.node("negative")).value();

    EXPECT_EQ(positive, true);
    EXPECT_EQ(negative, false);
}