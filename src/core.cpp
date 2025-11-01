#include "core.hpp"
#include <cstdlib>
#include <iostream>

namespace core {
void logError(const std::string &msg) {
    std::cerr << msg << ": " << SDL_GetError() << std::endl;
}

void ensure(bool status, const std::string &msg) {
    if (!status) {
        logError(msg);
        std::exit(EXIT_FAILURE);
    }
}
} // namespace core
