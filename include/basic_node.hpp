#pragma once

#include "node.hpp"

#include <nlohmann/json.hpp>

#include <vector>
#include <string>
#include <stdint.h>

namespace ojson {

class BasicNode final : public Node
{
public:
    explicit BasicNode(const nlohmann::json &json) 
    : BasicNode(nlohmann::json::basic_json::to_msgpack(json))
    {}

    explicit BasicNode(nlohmann::json::initializer_list_t json_list)
    : BasicNode(nlohmann::json::basic_json::to_msgpack(nlohmann::json(json_list)))
    {}

    explicit BasicNode(const std::vector<uint8_t>& bytes)
    : Node()
    , _bytes{bytes}
    {}
    
    const std::vector<uint8_t>& bytes() const override { return _bytes; }
    std::string content() const override { return nlohmann::json::from_msgpack(_bytes).dump(); }
    BasicNode node(std::string path) const { return BasicNode(nlohmann::json::from_msgpack(_bytes)[path]); };

private:
    std::vector<uint8_t> _bytes;
};

} // namespace ojson

