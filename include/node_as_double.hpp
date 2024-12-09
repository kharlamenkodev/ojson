#pragma once

#include "node.hpp"

#include <nlohmann/json.hpp>

#include <vector>
#include <string>
#include <cstdint>

namespace ojson {

class NodeAsDouble final : public Node
{
public:
    explicit NodeAsDouble(const Node& node)
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
    double value() const
    {
        return nlohmann::json::from_msgpack(_origin.bytes()).get<double>();
    };

private:
    const Node& _origin;
};

}  // namespace ojson