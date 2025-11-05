#include "config/config.hpp"
#include "config/configKeys.hpp"
#include "core.hpp"
#include <filesystem>
#include <fmt/core.h>
#include <lua.hpp>
#include <vector>

namespace config {

static std::filesystem::file_time_type lastModified;
static Editor config;

std::optional<std::filesystem::path> findConfigFile() {
    std::vector<std::filesystem::path> candidates;
    candidates.push_back("/Users/juderozario/Projects/texteditor/src/config.lua");
    candidates.push_back("/home/juderozario/Projects/texteditor/src/config.lua");
    if (const char *home = std::getenv("HOME")) {
        candidates.push_back(std::filesystem::path(home) / ".editor.lua");
        candidates.push_back(std::filesystem::path(home) / ".config" / "editor" / "editor.lua");
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

    if (luaL_loadfile(L, path) || lua_pcall(L, 0, 1, 0) != 0) {
        core::logError(fmt::format("Lua error: {}", lua_tostring(L, -1)).c_str());
        lua_close(L);
        return;
    }

    if (!lua_istable(L, -1)) {
        SDL_Log("Lua config did not return a table");
        lua_close(L);
        return;
    }

    getThemeConfig(L);
    lua_pop(L, 1); // Pop config table
    lua_close(L);
    lastModified = std::filesystem::last_write_time(path);
}

Color getBackgroundColor() { return config.colors.background; }

bool configChanged(const char *path) {
    auto current = std::filesystem::last_write_time(path);
    return current != lastModified;
}

ColorRGB parseHexToString(const char *color) {
    std::string clean = color;

    if (!clean.empty() && clean[0] == '#') {
        clean = clean.substr(1);
    }

    if (clean.length() != 6) {
        return ColorRGB{.r = 255, .g = 255, .b = 255};
    }

    ColorRGB c;
    c.r = std::stoi(clean.substr(0, 2), nullptr, 16);
    c.g = std::stoi(clean.substr(2, 2), nullptr, 16);
    c.b = std::stoi(clean.substr(4, 2), nullptr, 16);
    return c;
}

void getConfigColorValue(lua_State *L, const char *key, Color *value) {
    lua_getfield(L, -1, key);
    if (lua_istable(L, -1)) {
        const char *color_rgb;
        unsigned int alpha;
        getConfigValue(L, configKeys::color::RGB, &color_rgb);
        getConfigValue(L, configKeys::color::Alpha, &alpha);
        value->color = parseHexToString(color_rgb);
        value->alpha = alpha;
    } else {
        value->color = ColorRGB{.r = 0, .g = 0, .b = 0};
        value->alpha = 255;
    }
    lua_pop(L, 1);
}

void getThemeConfig(lua_State *L) {
    lua_getfield(L, -1, configKeys::editor::Theme); // Push theme config
    if (lua_istable(L, -1)) {
        struct ColorBinding {
            const char *key;
            Color *target;
        };

        static const std::vector<ColorBinding> bindings = {
            {configKeys::theme::Background, &config.colors.background},
            {configKeys::theme::Foreground, &config.colors.foreground},
            {configKeys::theme::Cursor, &config.colors.cursor},
            {configKeys::theme::Selection, &config.colors.selection},
            {configKeys::theme::LineHighlight, &config.colors.line_highlight},
            {configKeys::theme::LineNumber, &config.colors.line_number},
            {configKeys::theme::Gutter, &config.colors.gutter},
            {configKeys::theme::Whitespace, &config.colors.whitespace},
            {configKeys::theme::Keyword, &config.colors.keyword},
            {configKeys::theme::String, &config.colors.string},
            {configKeys::theme::Comment, &config.colors.comment},
            {configKeys::theme::Function, &config.colors.function},
            {configKeys::theme::Type, &config.colors.type},
            {configKeys::theme::Operator, &config.colors.operator_},
            {configKeys::theme::Constant, &config.colors.constant},
            {configKeys::theme::Error, &config.colors.error},
            {configKeys::theme::Warning, &config.colors.warning},
            {configKeys::theme::Info, &config.colors.info},
            {configKeys::theme::DiffAdd, &config.colors.diff_add},
            {configKeys::theme::DiffChange, &config.colors.diff_change},
            {configKeys::theme::DiffRemove, &config.colors.diff_remove},
            {configKeys::theme::DiagnosticError, &config.colors.diagnostic_error},
            {configKeys::theme::DiagnosticInfo, &config.colors.diagnostic_info},
            {configKeys::theme::DiagnosticWarning, &config.colors.diagnostic_warning},
            {configKeys::theme::PopupBackground, &config.colors.popup_background},
            {configKeys::theme::TooltipBorder, &config.colors.tooltip_border},
            {configKeys::theme::CompletionBackground, &config.colors.completion_background},
            {configKeys::theme::InactiveWindowBackground, &config.colors.inactive_window_background},
            {configKeys::theme::ActiveTabBackground, &config.colors.active_tab_background},
            {configKeys::theme::HoverTabBackground, &config.colors.hover_tab_background}};

        for (const auto &binding : bindings) {
            getConfigColorValue(L, binding.key, binding.target);
        }
    }
    lua_pop(L, 1); // Pop theme config
}
}
