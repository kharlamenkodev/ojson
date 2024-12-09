#pragma once

#include <vector>
#include <string>
#include <stdint.h>

namespace ojson {

class Node
{
public:
    virtual ~Node(){};
    virtual const std::vector<uint8_t>& bytes() const = 0;
    virtual std::string content() const = 0;
};

};  // namespace ojson