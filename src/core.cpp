#include "core.hpp"
#include <cstdlib>
#include <iostream>

namespace core {
void logError(const char *msg) {
    std::cerr << msg << ": " << SDL_GetError() << std::endl;
    SDL_Log("%s: %s", msg, SDL_GetError());
}

void ensure(bool status, const char *msg) {
    if (!status) {
        logError(msg);
        std::exit(EXIT_FAILURE);
    }
}
} // namespace core
