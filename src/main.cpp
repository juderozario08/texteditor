#include "config/config.hpp"
#include "core.hpp"
#include "editor/window.hpp"

constexpr const unsigned int WIDTH = 800;
constexpr const unsigned int HEIGHT = 600;
constexpr const char *TITLE = "TextEditor";

int main(int argc, char **argv) {
    core::ensure(SDL_Init(SDL_INIT_VIDEO), core::INIT_ERROR);
    editor::SDLContext ctx =
        editor::createWindowAndRenderer(TITLE, WIDTH, HEIGHT);

    auto configPath = config::findConfigFile();
    if (configPath) {
        config::load(configPath->c_str());
    } else {
        SDL_Log("No config file found");
    }

    SDL_Event event;
    bool running = true;
    while (running) {
        if (core::ensure<bool>(SDL_PollEvent(&event),
                               core::EVENT_POLLING_ERROR)) {
            switch (event.type) {
            case SDL_EVENT_QUIT:
            case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
                running = false;
                break;
            default:
                break;
            }
        }
        if (configPath && config::configChanged(configPath->c_str())) {
            config::load(configPath->c_str());
        }

        config::Color bg = config::getBackgroundColor();

        core::ensure(
            SDL_SetRenderDrawColor(ctx.renderer, bg.r, bg.g, bg.b, bg.a),
            core::SET_DRAW_COLOR_ERROR);
        core::ensure(SDL_RenderClear(ctx.renderer), core::CLEAR_RENDER_ERROR);

        SDL_FRect rects[] = {{0, 0, 400, 300}, {200, 200, 300, 150}};
        core::ensure(SDL_SetRenderDrawColor(ctx.renderer, 0, 0, 0, 100),
                     core::DRAW_COLOR_ERROR);
        core::ensure(SDL_RenderFillRect(ctx.renderer, &rects[0]),
                     core::FILL_RECT_ERROR);
        core::ensure(SDL_SetRenderDrawColor(ctx.renderer, 33, 33, 33, 100),
                     core::DRAW_COLOR_ERROR);

        core::ensure(SDL_RenderFillRect(ctx.renderer, &rects[1]),
                     core::FILL_RECT_ERROR);

        core::ensure(SDL_RenderPresent(ctx.renderer),
                     core::UPDATE_SCREEN_ERROR);
        SDL_Delay(16);
    }

    editor::destroyWindow(ctx);
    return 0;
}
