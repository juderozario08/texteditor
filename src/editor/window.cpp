#include "editor/window.hpp"
#include "core.hpp"

namespace editor {
SDLContext createWindowAndRenderer(const char *title, int width, int height) {
    SDLContext ctx = {
        .window = core::ensure(SDL_CreateWindow("TextEditor", width, height, SDL_WINDOW_RESIZABLE), "Window creation failed"),
        .renderer = core::ensure(SDL_CreateRenderer(ctx.window, RENDER_DRIVER), "Renderer creation failed")};
    return ctx;
}
void destroyWindowAndRenderer(SDLContext &ctx) {
    SDL_DestroyRenderer(ctx.renderer);
    SDL_DestroyWindow(ctx.window);
    SDL_Quit();
}
} // namespace editor
