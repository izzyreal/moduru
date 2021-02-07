#pragma once
#include <string>
#include <thirdp/any.hpp>

namespace moduru::observer
{
class Observable;
}

namespace moduru::observer
{
class Observer
{
public:
    virtual void update(nonstd::any) {}
    virtual void update(Observable*, nonstd::any) {}
    virtual ~Observer() {}
};
}
