#include "core.hpp"
#include "editor/window.hpp"
#include <SDL3/SDL.h>

const unsigned int vWidth = 800;
const unsigned int vHeight = 600;

int main(int argc, char **argv) {
    editor::SDLContext ctx =
        editor::createWindow("TextEditor", vWidth, vHeight);

    SDL_Event events;
    bool running = true;
    while (running) {
        if (SDL_PollEvent(&events) != 0) {
            switch (events.type) {
            case SDL_EVENT_QUIT:
                running = false;
                break;
            }
        }
        core::ensure(SDL_SetRenderDrawColor(ctx.renderer, 0, 0, 0, 255) == 0,
                     "Failed to set draw color");
        core::ensure(SDL_RenderClear(ctx.renderer), "Failed to clear renderer");

        SDL_FRect rects[] = {{0, 0, 400, 300}, {200, 200, 300, 150}};
        SDL_SetRenderDrawColor(ctx.renderer, 255, 255, 255, 100);
        SDL_RenderFillRect(ctx.renderer, &rects[0]);
        SDL_SetRenderDrawColor(ctx.renderer, 33, 33, 33, 100);
        SDL_RenderFillRect(ctx.renderer, &rects[1]);
        SDL_RenderPresent(ctx.renderer);
        SDL_Delay(16);
    }

    editor::destroyWindow(ctx);
    return 0;
}
