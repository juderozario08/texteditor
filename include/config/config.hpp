#pragma once
#include <SDL3/SDL.h>
#include <filesystem>
#include <lua.hpp>
#include <optional>
#include <type_traits>

namespace config {

constexpr const char *NO_CONFIG_FOUND = "No config file found";

enum class CursorStyleOpts { Block = 0, Line, Underline };
enum class LineNumbersOpts { Absolute = 0, Relative, Hidden };
enum class AutoFormatOpts { OnSave = 0, OnPaste, Manual };
enum class AutosaveModeOpts { OnFocus = 0, Delay, Manual };

typedef struct {
    unsigned int r, g, b;
} ColorRGB;

typedef struct {
    ColorRGB color;
    float alpha;
} Color;

typedef struct {
    Color background, foreground, cursor, selection, line_highlight, line_number, gutter, whitespace, keyword, string, comment,
        function, type, operator_, constant, error, warning, info, diff_add, diff_remove, diff_change, diagnostic_error,
        diagnostic_warning, diagnostic_info, popup_background, tooltip_border, completion_background, inactive_window_background,
        active_tab_background, hover_tab_background;
} ThemeColors;

// Font configuration
typedef struct {
    std::vector<const char *> family;
    Color color;
    bool ligatures;
    unsigned int size;
    float line_height;
} Font;

typedef struct {
    const char *theme;
    CursorStyleOpts cursor_style; // "block", "line", "underline"
    LineNumbersOpts line_numbers; // "absolute", "relative", "hidden"
    bool status_bar_visible;
    bool tab_bar_visible;
    bool highlight_current_line;
    bool show_whitespace;
    bool show_indent_guides;
    // bool animate_cursor_blink;
    int ui_scale_percent;
} UI;

// Keybindings and Input
typedef struct {
    const char *shortcut_save;
    const char *shortcut_search;
    const char *shortcut_split_vertical;
    const char *shortcut_split_horizontal;
    bool vim_mode;
    bool autocomplete;
    bool clipboard_integration;
    int key_repeat_delay_ms;
    int key_repeat_rate_ms;
    bool mouse_selection;
    bool drag_and_drop;
} Input;

typedef struct {
    int use_spaces; // What is this
    int tab_width;
    AutoFormatOpts auto_format; // "on_save", "on_paste", "manual"
    bool bracket_matching;
    bool auto_close_brackets;
    bool word_wrap;
    // bool smooth_scroll;
    // bool scroll_offset;
    bool trim_trailing_whitespace_on_save;
    bool insert_final_newline_on_save;
    bool highlight_active_scope;
    bool auto_indent;
    // bool smart_home_end;
} Preference;

typedef struct {
    bool lsp;
    bool snippets;
    bool git;
    bool linter;
    // bool debugger;
    bool file_explorer;
    // bool build_tasks;
    bool hot_reload;
    // bool sandboxing;
} Plugins;

// File & Project Settings
typedef struct {
    AutosaveModeOpts autosave_mode;             // "on_focus", "delay"
    unsigned int delay;                         // if autosave_mode is delay
    std::vector<const char *> exclude_patterns; // array of strings (null-terminated)
    // bool restore_last_session;
    bool show_hidden_files;
    // bool follow_symlinks;
    // const char *default_project_path;
    bool file_watcher;
} File;

// Think of devtools later on
// Developer Tools
// typedef struct {
//     bool terminal;
//     bool debug;
//     bool show_fps_overlay;
//     bool enable_profiler;
//     unsigned int log_level; // 0=none, 1=error, 2=warn, 3=info, 4=debug
//     const char *log_output_path;
// } DevTools;

typedef struct {
    UI ui;
    Font font;
    Input input;
    Preference preference;
    Plugins plugins;
    File file;
    ThemeColors colors;
    // DevTools devtools;
} Editor;

std::optional<std::filesystem::path> findConfigFile();
void load(const char *path);
Color getBackgroundColor();
bool configChanged(const char *path);
void getConfigColorValue(lua_State *L, const char *key, Color *value);
void getThemeConfig(lua_State *L);
void getFontConfig(lua_State *L);
void getUIConfig(lua_State *L);
void getInputConfig(lua_State *L);
void getPreferenceConfig(lua_State *L);
void getPluginsConfig(lua_State *L);
void getFileConfig(lua_State *L);

template <typename T> void getConfigValue(lua_State *L, const char *key, T *value) {
    lua_getfield(L, -1, key);
    if (lua_isnumber(L, -1)) {
        if constexpr (std::is_same_v<int, T> || std::is_same_v<unsigned int, T>) {
            *value = static_cast<T>(lua_tointeger(L, -1));
        } else if constexpr (std::is_same_v<float, T> || std::is_same_v<double, T>) {
            *value = static_cast<T>(lua_tonumber(L, -1));
        }
    } else if (lua_isstring(L, -1)) {
        if constexpr (std::is_same_v<char *, T> || std::is_same_v<const char *, T>) {
            *value = lua_tostring(L, -1);
        } else if constexpr (std::is_same_v<std::remove_cv_t<T>, std::string>) {
            *value = std::string(lua_tostring(L, -1));
        }
    } else if (lua_isboolean(L, -1)) {
        if constexpr (std::is_same_v<bool, T> || std::is_same_v<const bool, T>) {
            *value = lua_toboolean(L, -1);
        }
    }
    lua_pop(L, 1);
}
} // namespace config
