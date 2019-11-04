#ifndef VARIADIC_PACK_H
#define VARIADIC_PACK_H

#include <cstdlib>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

namespace study {

template <typename... Args>
constexpr std::size_t sizeOfPack() {
    return sizeof...(Args);
}

template <typename... Args>
std::string concat(Args&&... args) {
    std::stringstream stream;
    stream << std::boolalpha;
    if constexpr (sizeof...(Args) > 0) { // otherwise it fails
        (..., (stream << args)); // unary left fold
    }
    return stream.str();
}

template <typename... Args, std::size_t... Is>
decltype(auto)
revertTupleImpl(std::tuple<Args...>&& t, std::index_sequence<Is...>) {
    return std::forward_as_tuple(
        std::get<sizeof...(Args) - Is - 1>(t)...);
}

template <typename... Args>
decltype(auto) revertTuple(std::tuple<Args...> t) {
    return revertTupleImpl(std::forward<decltype(t)>(t),
        std::make_index_sequence<sizeof...(Args)>());
};

template <typename... Args>
std::string concatReverse(Args&&... args) {
    std::stringstream stream;
    stream << std::boolalpha;
    auto tuple = revertTuple(std::forward_as_tuple(args...));
    std::apply([&](auto&&... element) {
        ((stream << element), ...); }, tuple);
    return stream.str();
}

} // namespace study

#endif /* VARIADIC_PACK_H */