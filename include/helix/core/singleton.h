#pragma once

namespace helix
{
template <typename T> class singleton
{
protected:
    singleton() = default;
    virtual ~singleton() = default;

public:
    static T& instance()
    {
        static T* _ = new T;
        return *_;
    }
};
} // namespace helix