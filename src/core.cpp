#include "core.hpp"
#include <cstdlib>
#include <iostream>

namespace core {
void logError(const std::string &msg) {
    std::cerr << msg << ": " << SDL_GetError() << std::endl;
}

void ensure(bool success, const std::string &msg) {
    if (!success) {
        logError(msg);
        std::exit(EXIT_FAILURE);
    }
}
} // namespace core
