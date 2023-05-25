#pragma once

#include <cstdint>
#include <tuple>
#include <type_traits>

namespace helix
{
template <typename T, std::size_t... I>
std::size_t hash_tuple(const T&, const std::index_sequence<I...>&);

template <typename T>
std::size_t hash(const T& t)
{
    // all values except std::tuple
    std::hash<T> hasher;
    return hasher(t);
}

// std::tuple version
template <typename... Args>
std::size_t hash(const std::tuple<Args...>& value)
{
    return hash_tuple(value, std::make_index_sequence<sizeof...(Args)>());
}

// empty tuple case
std::size_t hash(const std::tuple<>& t)
{
    return -1;
}

template <typename T, std::size_t... I>
std::size_t hash_tuple(const T& t, const std::index_sequence<I...>&)
{
    std::size_t res = 0;
    for (auto val : {hash(std::get<I>(t))...})
    {
        res ^= val + 0x9e3779b9 + (res << 6) + (res >> 2);
    }
    return res;
}

} // namespace helix