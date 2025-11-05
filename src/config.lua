---@alias Color { color:string, alpha:integer }

---@class Theme
---@field background Color
---@field foreground Color
---@field cursor Color
---@field selection Color
---@field line_highlight Color
---@field line_number Color
---@field gutter Color
---@field whitespace Color
---@field keyword Color
---@field string Color
---@field comment Color
---@field function_ Color
---@field type Color
---@field operator Color
---@field constant Color
---@field error Color
---@field warning Color
---@field info Color
---@field diff_add Color
---@field diff_remove Color
---@field diff_change Color
---@field diagnostic_error Color
---@field diagnostic_warning Color
---@field diagnostic_info Color
---@field popup_background Color
---@field tooltip_border Color
---@field completion_background Color
---@field inactive_window_background Color
---@field active_tab_background Color
---@field hover_tab_background Color

---@class Font
---@field family table<string>
---@field color Color
---@field ligatures boolean
---@field size integer
---@field line_height number

---@class UI
---@field theme string
---@field cursor_style string
---@field line_numbers string
---@field status_bar_visible boolean
---@field tab_bar_visible boolean
---@field highlight_current_line boolean
---@field show_whitespace boolean
---@field show_indent_guides boolean
---@field ui_scale_percent integer

---@class Input
---@field shortcut_save table<string>
---@field shortcut_search table<string>
---@field shortcut_split_vertical table<string>
---@field shortcut_split_horizontal table<string>
---@field vim_mode boolean
---@field autocomplete boolean
---@field clipboard_integration boolean
---@field key_repeat_delay_ms integer
---@field key_repeat_rate_ms integer
---@field mouse_selection boolean
---@field drag_and_drop boolean

---@class Editor
---@field tab_width integer
---@field auto_format string
---@field bracket_matching boolean
---@field auto_close_brackets boolean
---@field word_wrap boolean
---@field trim_trailing_whitespace_on_save boolean
---@field insert_final_newline_on_save boolean
---@field highlight_active_scope boolean
---@field auto_indent boolean

---@class Plugins
---@field lsp boolean
---@field snippets boolean
---@field plugin_git boolean
---@field plugin_linter boolean
---@field plugin_debugger boolean
---@field plugin_file_explorer boolean
---@field build_tasks boolean
---@field plugin_hot_reload boolean
---@field plugin_sandboxing boolean

---@class File
---@field autosave_mode string
---@field delay integer
---@field exclude_patterns table<string>
---@field show_hidden_files boolean
---@field file_watcher boolean

---@class ConfigType
---@field Theme Theme
---@field Font Font
---@field UI UI
---@field Input Input
---@field Editor Editor
---@field Plugins Plugins
---@field File File

---@type ConfigType
Config = {}

Config.Theme = {
    background = {
        color = "#23332f",
        alpha = 255,
    },
    foreground = {
        color = "#000000",
        alpha = 1,
    },
    cursor = {
        color = "#000000",
        alpha = 1,
    },
    selection = {
        color = "#000000",
        alpha = 1,
    },
    line_highlight = {
        color = "#000000",
        alpha = 1,
    },
    line_number = {
        color = "#000000",
        alpha = 1,
    },
    gutter = {
        color = "#000000",
        alpha = 1,
    },
    whitespace = {
        color = "#000000",
        alpha = 1,
    },
    keyword = {
        color = "#000000",
        alpha = 1,
    },
    string = {
        color = "#000000",
        alpha = 1,
    },
    comment = {
        color = "#000000",
        alpha = 1,
    },
    function_ = {
        color = "#000000",
        alpha = 1,
    },
    type = {
        color = "#000000",
        alpha = 1,
    },
    operator = {
        color = "#000000",
        alpha = 1,
    },
    constant = {
        color = "#000000",
        alpha = 1,
    },
    error = {
        color = "#000000",
        alpha = 1,
    },
    warning = {
        color = "#000000",
        alpha = 1,
    },
    info = {
        color = "#000000",
        alpha = 1,
    },
    diff_add = {
        color = "#000000",
        alpha = 1,
    },
    diff_remove = {
        color = "#000000",
        alpha = 1,
    },
    diff_change = {
        color = "#000000",
        alpha = 1,
    },
    diagnostic_error = {
        color = "#000000",
        alpha = 1,
    },
    diagnostic_warning = {
        color = "#000000",
        alpha = 1,
    },
    diagnostic_info = {
        color = "#000000",
        alpha = 1,
    },
    popup_background = {
        color = "#000000",
        alpha = 1,
    },
    tooltip_border = {
        color = "#000000",
        alpha = 1,
    },
    completion_background = {
        color = "#000000",
        alpha = 1,
    },
    inactive_window_background = {
        color = "#000000",
        alpha = 1,
    },
    active_tab_background = {
        color = "#000000",
        alpha = 1,
    },
    hover_tab_background = {
        color = "#000000",
        alpha = 1,
    }
}

Config.Font = {
    family = {},
    color = "#ffffffff",
    ligatures = true,
    size = 14,
    line_height = 1.5
}

Config.UI = {
    theme = "Catppuccin Mocha",
    cursor_style = "block",
    line_numbers = "relative",
    status_bar_visible = true,
    tab_bar_visible = true,
    highlight_current_line = true,
    show_whitespace = true,
    show_indent_guides = true,
    ui_scale_percent = 100
}

Config.Input = {
    shortcut_save = { "<C-s>" },
    shortcut_search = { "<C-f>" },
    shortcut_split_vertical = { "<C-w><C-v>" },
    shortcut_split_horizontal = { "<C-w><C-s>" },
    vim_mode = true,
    autocomplete = true,
    clipboard_integration = true,
    key_repeat_delay_ms = 200,
    key_repeat_rate_ms = 50,
    mouse_selection = true,
    drag_and_drop = true
}

Config.Editor = {
    tab_width = 4,
    auto_format = "on_save",
    bracket_matching = true,
    auto_close_brackets = true,
    word_wrap = false,
    trim_trailing_whitespace_on_save = true,
    insert_final_newline_on_save = true,
    highlight_active_scope = true,
    auto_indent = true
}

Config.Plugins = {
    lsp = true,
    snippets = true,
    git = true,
    linter = true,
    debugger = true,
    file_explorer = true,
    build_tasks = true,
    hot_reload = true,
    sandboxing = true
}


Config.File = {
    autosave_mode = "on_focus",
    delay = 50,
    exclude_patterns = {},
    show_hidden_files = true,
    file_watcher = true,
}

return Config
