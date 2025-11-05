#include "core.hpp"
#include <cstdlib>

namespace core {
void logError(const char *msg) { SDL_Log("%s: %s", SDL_GetError(), msg); }

void ensure(bool status, const char *msg) {
    if (!status) {
        logError(msg);
        std::exit(EXIT_FAILURE);
    }
}
} // namespace core
