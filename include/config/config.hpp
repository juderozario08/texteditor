#pragma once
#include <SDL3/SDL.h>
#include <filesystem>
#include <lua.hpp>
#include <optional>
#include <type_traits>

namespace config {
struct Color {
    unsigned int r, g, b, a;
};

std::optional<std::filesystem::path> findConfigFile();
void load(const char *path);
Color getBackgroundColor();
bool configChanged(const char *path);

template <typename T>
void getConfigValue(lua_State *L, const char *key, T *value) {
    lua_getfield(L, -1, key);
    if constexpr (std::is_same_v<int, T> || std::is_same_v<unsigned int, T>) {
        if (lua_isnumber(L, -1)) {
            *value = lua_tointeger(L, -1);
        }
    } else if constexpr (std::is_same_v<char *, T>) {
        if (lua_isstring(L, -1)) {
            *value = lua_tostring(L, -1);
        }
    }
    lua_pop(L, 1);
}
} // namespace config
