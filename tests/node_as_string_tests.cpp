#include <gtest/gtest.h>

#include "basic_node.hpp"
#include "node_as_string.hpp"

#include <nlohmann/json.hpp>

TEST(node_as_string_tests, name_from_basic_node_must_be_equal_to_andrew)
{
    ojson::BasicNode root_node({
        {"name", "Andrew"},
        {"age", 24}
    });

    std::string name = ojson::NodeAsString(root_node.node("name")).value();

    EXPECT_EQ(name, "Andrew");
}