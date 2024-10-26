# Examples

## Create json node from nlohmann json

You can create basic json node from nlohmann::json object:

```cpp
#include <nlohmann/json.hpp>
#include <basic_node.hpp>

using json = nlohmann::json;

// ...

json data = {
    {"name", "Andrew"},
    {"age", 24}
};

ojson::BasicNode root_node(data);
```

or you could write shorter:

```cpp
#include <basic_node.hpp>

ojson::BasicNode root_node({
    {"name", "Andrew"},
    {"age", 24}
});
```
and for example print it:

```cpp
std::cout << root_node.content() << std::endl;
```

## Convert node to integer

```cpp
#include <basic_node.hpp>
#include <node_as_integer.hpp>

ojson::BasicNode root_node({
    {"name", "Andrew"},
    {"age", 24}
});

try {
    int age = ojson::NodeAsInteger(root_node.node("age")).value();
} catch(const std::exception& ex) {
    std::cout << "unable to convert node to integer" << std::endl;
}
```
## Convert node to string

```cpp
still in progress...
```