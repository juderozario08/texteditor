#include "editor/window.hpp"
#include "core.hpp"

namespace editor {
SDLContext createWindowAndRenderer(const char *title, int width, int height) {
    SDLContext ctx;
    core::ensure(SDL_CreateWindowAndRenderer(title, width, height,
                                             SDL_WINDOW_RESIZABLE, &ctx.window,
                                             &ctx.renderer),
                 "Failed to create window and renderer");
    core::ensure(SDL_ShowWindow(ctx.window), "Failed to show window");
    return ctx;
}
void destroyWindow(SDLContext &ctx) {
    SDL_DestroyRenderer(ctx.renderer);
    SDL_DestroyWindow(ctx.window);
    SDL_Quit();
}
} // namespace editor
