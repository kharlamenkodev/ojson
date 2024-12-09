#pragma once

#include "node.hpp"

#include <nlohmann/json.hpp>

#include <vector>
#include <string>
#include <stdint.h>

namespace ojson {

class NodeAsInteger final : public Node
{
public:
    explicit NodeAsInteger(const Node& node)
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
    int value() const
    {
        return nlohmann::json::from_msgpack(_origin.bytes()).get<int>();
    };

private:
    const Node& _origin;
};

}  // namespace ojson