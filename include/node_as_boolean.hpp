#pragma once

#include "node.hpp"

#include <nlohmann/json.hpp>

#include <vector>
#include <string>
#include <stdint.h>

namespace ojson {

class NodeAsBoolean final : public Node
{
public:
    explicit NodeAsBoolean(const Node& node)
        : _origin{node}
    {}

    std::string content() const override
    {
        return _origin.content();
    }
    const std::vector<uint8_t>& bytes() const override
    {
        return _origin.bytes();
    }
    bool value() const
    {
        return nlohmann::json::from_msgpack(_origin.bytes()).get<bool>();
    };

private:
    const Node& _origin;
};

}  // namespace ojson