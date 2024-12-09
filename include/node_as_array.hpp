#pragma once

#include "node.hpp"
#include "basic_node.hpp"

#include <nlohmann/json.hpp>

#include <vector>
#include <string>
#include <stdint.h>

namespace ojson {

class NodeAsArray final : public Node
{
public:
    explicit NodeAsArray(const Node& node)
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

    size_t size() const
    {
        return nlohmann::json::from_msgpack(_origin.bytes()).get<nlohmann::json::array_t>().size();
    }

    BasicNode operator[](size_t index)
    {
        return BasicNode(nlohmann::json::from_msgpack(_origin.bytes()).get<nlohmann::json::array_t>().at(index));
    }

private:
    const Node& _origin;
};

}  // namespace ojson