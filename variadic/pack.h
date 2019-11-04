#ifndef VARIADIC_PACK_H
#define VARIADIC_PACK_H

#include <cstdlib>
#include <sstream>
#include <string>
#include <type_traits>

namespace study {

template <typename... Args>
constexpr std::size_t sizeOfPack() {
    return sizeof...(Args);
}

template <typename... Args>
std::string concat(Args&&... args) {
    std::stringstream stream;
    if constexpr (sizeof...(Args) > 0) { // otherwise it fails
        (..., (stream << args)); // unary left fold
    }
    return stream.str();
}

} // namespace study

#endif /* VARIADIC_PACK_H */
