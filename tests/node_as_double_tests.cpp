#include <gtest/gtest.h>

#include "basic_node.hpp"
#include "node_as_double.hpp"

#include <nlohmann/json.hpp>

TEST(node_as_double_tests, factor_from_basic_node_must_be_equal_0_243)
{
    ojson::BasicNode root_node({{"salary", 200}, {"factor", 0.243}});

    double factor = ojson::NodeAsDouble(root_node.node("factor")).value();

    EXPECT_EQ(factor, 0.243);
}