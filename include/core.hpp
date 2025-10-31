#pragma once
#include <SDL3/SDL.h>
#include <string>

namespace core {
    void logError(const std::string &msg);
    void ensure(bool success, const std::string &msg);
} // namespace core
