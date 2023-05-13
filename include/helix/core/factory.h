#pragma once
#include <string>
#include <unordered_map>
namespace helix
{
template <typename T, typename Key = std::string> class factory
{
    typedef T* (*create_fun)();
    std::unordered_map<Key, create_fun> _map;

public:
    static factory& instance()
    {
        static factory* _ = new factory;
        return *_;
    }

public:
    factory()
    {
    }
    virtual ~factory()
    {
    }

    void register_class(const Key& key, create_fun&& fun)
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

template <typename Base, typename Derived, typename Key> void register_factory(const Key& key)
{
    factory<Base>::instance().register_class(key, [] { return static_cast<Base*>(new Derived); });
}

} // namespace helix