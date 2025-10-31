#pragma once
#include <SDL3/SDL.h>

namespace editor {
struct SDLContext {
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
};
SDLContext createWindow(const char *title, int width, int height);
void destroyWindow(SDLContext &ctx);
} // namespace editor
