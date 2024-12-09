#include <gtest/gtest.h>

#include "basic_node.hpp"
#include "node_as_integer.hpp"

#include <nlohmann/json.hpp>

TEST(node_as_integer_tests, age_from_basic_node_must_be_equal_24)
{
    ojson::BasicNode root_node({{"name", "Andrew"}, {"age", 24}});

    int andrews_age = ojson::NodeAsInteger(root_node.node("age")).value();

    EXPECT_EQ(andrews_age, 24);
}