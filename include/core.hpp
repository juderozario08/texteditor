#pragma once
#include <SDL3/SDL.h>
#include <cstdlib>
#include <type_traits>

namespace core {
void logError(const char *msg);
void ensure(bool status, const char *msg);

constexpr const char *INIT_ERROR = "Failed to initialize SDL";
constexpr const char *CLEAR_RENDER_ERROR = "Failed to clear renderer";
constexpr const char *SET_DRAW_COLOR_ERROR = "Failed to set draw color";
constexpr const char *FILL_RECT_ERROR = "Failed to fill rectangle";
constexpr const char *DRAW_COLOR_ERROR = "Failed to draw color";
constexpr const char *UPDATE_SCREEN_ERROR = "Failed to render update screen";
constexpr const char *EVENT_POLLING_ERROR = "Failed to Poll Events";

template <typename T> T ensure(T result, const char *msg) {
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
