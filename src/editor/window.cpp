#include "editor/window.hpp"
#include "core.hpp"

namespace editor {
SDLContext createWindowAndRenderer(const char *title, int width, int height) {
    SDLContext ctx;
    ctx.window = core::ensure(SDL_CreateWindow("TextEditor", 0, 0, width,
                                               height, SDL_WINDOW_RESIZABLE),
                              "Window creation failed");
    ctx.renderer = core::ensure(
        SDL_CreateRenderer(ctx.window, -1, SDL_RENDERER_ACCELERATED),
        "Renderer creation failed");
    return ctx;
}
void destroyWindow(SDLContext &ctx) {
    SDL_DestroyRenderer(ctx.renderer);
    SDL_DestroyWindow(ctx.window);
    SDL_Quit();
}
} // namespace editor
