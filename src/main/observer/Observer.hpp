#pragma once
#include <string>
#include <utility>

namespace moduru::observer
{
class Observable;
}

namespace moduru::observer
{
using Message = std::variant<std::string, int, std::pair<float, float>>;
class Observer
{
public:
    virtual void update(Observable*, Message) {}
};
}
