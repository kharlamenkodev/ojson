#pragma once

#include "node.hpp"

#include <nlohmann/json.hpp>

#include <vector>
#include <string>
#include <cstdint>

namespace ojson {

class NodeAsString final : public Node
{
public:
    explicit NodeAsString(const Node& node)
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
    std::string value() const
    {
        return nlohmann::json::from_msgpack(_origin.bytes()).get<std::string>();
    };

private:
    const Node& _origin;
};

}  // namespace ojson