#include <gtest/gtest.h>

#include "basic_node.hpp"

#include <nlohmann/json.hpp>

TEST(basic_node_tests, create_basic_node_from_nlohmann_json)
{
    ojson::BasicNode node({
        {"name", "Andrew"},
        {"age", 24}
    });

    EXPECT_EQ(node.content(), "{\"age\":24,\"name\":\"Andrew\"}");
}