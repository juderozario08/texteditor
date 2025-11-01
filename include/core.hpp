#pragma once
#include <SDL2/SDL.h>
#include <string>

namespace core {
void logError(const std::string &msg);
void ensure(bool status, const std::string &msg);

template <typename T> T ensure(T result, const std::string &msg) {
    if constexpr (std::is_same_v<T, int>) {
        if (result < 0) {
            logError(msg);
            std::exit(EXIT_FAILURE);
        }
    } else if constexpr (std::is_pointer_v<T>) {
        if (result == nullptr) {
            logError(msg);
            std::exit(EXIT_FAILURE);
        }
    }
    return result;
}
} // namespace core
