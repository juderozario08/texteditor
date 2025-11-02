#pragma once
#include <SDL3/SDL.h>

namespace editor {
#if defined(_WIN32)
#define RENDER_DRIVER "vulkan"
#elif defined(__APPLE__)
#define RENDER_DRIVER "metal"
#elif defined(__linux__)
#define RENDER_DRIVER "vulkan"
#else
#define RENDER_DRIVER "unknown"
#endif

struct SDLContext {
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
};
SDLContext createWindowAndRenderer(const char *title, int width, int height);
void destroyWindow(SDLContext &ctx);
} // namespace editor
