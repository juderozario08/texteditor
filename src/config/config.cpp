#include "config/config.hpp"
#include <filesystem>
#include <lua.hpp>

namespace config {
constexpr const char *BACKGROUND = "background";
constexpr const char *FONTSIZE = "font_size";
constexpr const char *FONTFAMILY = "font_family";
constexpr const char *THEME = "theme";

static Color backgroundColor = {0, 0, 0, 255};
static unsigned int fontSize = 14; // Default size
static std::filesystem::file_time_type lastModified;

std::optional<std::filesystem::path> findConfigFile() {
    std::vector<std::filesystem::path> candidates;
    candidates.push_back(
        "/Users/juderozario/Projects/texteditor/src/config.lua");
    candidates.push_back(
        "/home/juderozario/Projects/texteditor/src/config.lua");
    if (const char *home = std::getenv("HOME")) {
        candidates.push_back(std::filesystem::path(home) / ".editor.lua");
        candidates.push_back(std::filesystem::path(home) / ".config" /
                             "editor" / "editor.lua");
    }
    for (const auto &path : candidates) {
        if (std::filesystem::exists(path)) {
            return path;
        }
    }
    return std::nullopt;
}

void load(const char *path) {
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    if (luaL_loadfile(L, path) || lua_pcall(L, 0, 1, 0)) {
        SDL_Log("Lua error: %s", lua_tostring(L, -1));
        lua_close(L);
        return;
    }

    if (!lua_istable(L, -1)) {
        SDL_Log("Lua config did not return a table");
        lua_close(L);
        return;
    }

    lua_getfield(L, -1, BACKGROUND);
    if (lua_istable(L, -1)) {
        getConfigValue(L, "r", &backgroundColor.r);
        getConfigValue(L, "g", &backgroundColor.g);
        getConfigValue(L, "b", &backgroundColor.b);
        getConfigValue(L, "a", &backgroundColor.a);
    }
    lua_pop(L, 1); // pop background

    getConfigValue(L, FONTSIZE, &fontSize);

    lua_pop(L, 1); // pop config table
    lua_close(L);
    lastModified = std::filesystem::last_write_time(path);
}

Color getBackgroundColor() { return backgroundColor; }
unsigned int getFontSize() { return fontSize; }

bool configChanged(const char *path) {
    auto current = std::filesystem::last_write_time(path);
    return current != lastModified;
}
} // namespace config
