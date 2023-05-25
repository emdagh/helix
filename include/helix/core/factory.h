#pragma once
#include "singleton.h"
#include <string>
#include <unordered_map>

namespace helix
{
template <typename T, typename Key = std::string> class factory : public singleton<factory<T, Key>>
{
    typedef T* (*create_fun)();
    std::unordered_map<Key, create_fun> _map;

public:
    factory() = default;
    virtual ~factory() = default;
    factory(const factory&) = delete;
    factory& operator=(const factory&) const = delete;

public:
    void register_class(const Key& key, const create_fun&& fun)
    {
        if (!_map.count(key))
        {
            _map[key] = fun;
        }
    }

    T* create(const Key& key)
    {
        _map.count() ? _map[key]() : nullptr;
    }
};

template <typename Base, typename Derived, typename Key = std::string> void register_factory(const Key& key)
{
    factory<Base>::instance().register_class(key, []() -> Base* { return static_cast<Base*>(new Derived); });
}

} // namespace helix