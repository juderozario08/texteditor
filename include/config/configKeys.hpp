namespace configKeys {
namespace color {
inline constexpr const char *RGB = "color";
inline constexpr const char *Alpha = "alpha";
}

namespace editor {
inline constexpr const char *Theme = "Theme";
inline constexpr const char *Font = "Font";
inline constexpr const char *UI = "UI";
inline constexpr const char *Input = "Input";
inline constexpr const char *Preference = "Preference";
inline constexpr const char *Plugins = "Plugins";
inline constexpr const char *File = "File";
}

namespace theme {
inline constexpr const char *Background = "background";
inline constexpr const char *Foreground = "foreground";
inline constexpr const char *Cursor = "cursor";
inline constexpr const char *Selection = "selection";
inline constexpr const char *LineHighlight = "line_highlight";
inline constexpr const char *LineNumber = "line_number";
inline constexpr const char *Gutter = "gutter";
inline constexpr const char *Whitespace = "whitespace";
inline constexpr const char *Keyword = "keyword";
inline constexpr const char *String = "string";
inline constexpr const char *Comment = "comment";
inline constexpr const char *Function = "function_";
inline constexpr const char *Type = "type";
inline constexpr const char *Operator = "operator";
inline constexpr const char *Constant = "constant";
inline constexpr const char *Error = "error";
inline constexpr const char *Warning = "warning";
inline constexpr const char *Info = "info";
inline constexpr const char *DiffAdd = "diff_add";
inline constexpr const char *DiffRemove = "diff_remove";
inline constexpr const char *DiffChange = "diff_change";
inline constexpr const char *DiagnosticError = "diagnostic_error";
inline constexpr const char *DiagnosticWarning = "diagnostic_warning";
inline constexpr const char *DiagnosticInfo = "diagnostic_info";
inline constexpr const char *PopupBackground = "popup_background";
inline constexpr const char *TooltipBorder = "tooltip_border";
inline constexpr const char *CompletionBackground = "completion_background";
inline constexpr const char *InactiveWindowBackground = "inactive_window_background";
inline constexpr const char *ActiveTabBackground = "active_tab_background";
inline constexpr const char *HoverTabBackground = "hover_tab_background";
}

namespace font {
inline constexpr const char *Family = "family";
inline constexpr const char *Ligatures = "ligatures";
inline constexpr const char *Color = "color";
inline constexpr const char *Size = "size";
inline constexpr const char *LineHeight = "line_height";
}

namespace ui {
inline constexpr const char *Theme = "theme";
inline constexpr const char *CursorStyle = "cursor_style";
inline constexpr const char *LineNumbers = "line_numbers";
inline constexpr const char *StatusBarVisible = "status_bar_visible";
inline constexpr const char *TabBarVisible = "tab_bar_visible";
inline constexpr const char *HighlightCurrentLine = "highlight_current_line";
inline constexpr const char *ShowWhitespace = "show_whitespace";
inline constexpr const char *ShowIndentGuides = "show_indent_guides";
inline constexpr const char *ScalePercent = "ui_scale_percent";
}

namespace input {
inline constexpr const char *ShortcutSave = "shortcut_save";
inline constexpr const char *ShortcutSearch = "shortcut_search";
inline constexpr const char *ShortcutSplitVertical = "shortcut_split_vertical";
inline constexpr const char *ShortcutSplitHorizontal = "shortcut_split_horizontal";
inline constexpr const char *VimMode = "vim_mode";
inline constexpr const char *Autocomplete = "autocomplete";
inline constexpr const char *ClipboardIntegration = "clipboard_integration";
inline constexpr const char *KeyRepeatDelayMS = "key_repeat_delay_ms";
inline constexpr const char *KeyRepeatRateMS = "key_repeat_rate_ms";
inline constexpr const char *MouseSelection = "mouse_selection";
inline constexpr const char *DragAndDrop = "drag_and_drop";
}

namespace preference {
inline constexpr const char *TabWidth = "tab_width";
inline constexpr const char *AutoFormat = "auto_format";
inline constexpr const char *BracketMatching = "bracket_matching";
inline constexpr const char *AutoCloseBrackets = "auto_close_brackets";
inline constexpr const char *WordWrap = "word_wrap";
inline constexpr const char *TrimTrailingWhitespaceOnSave = "trim_trailing_whitespace_on_save";
inline constexpr const char *InsertFinalNewlineOnSave = "insert_final_newline_on_save";
inline constexpr const char *HighlightActiveScope = "highlight_active_scope";
inline constexpr const char *AutoIndent = "auto_indent";
}

namespace plugins {
inline constexpr const char *Lsp = "lsp";
inline constexpr const char *Snippets = "snippets";
inline constexpr const char *Git = "git";
inline constexpr const char *Linter = "linter";
// inline constexpr const char *Debugger = "debugger";
inline constexpr const char *FileExplorer = "file_explorer";
// inline constexpr const char *BuildTasks = "build_tasks";
inline constexpr const char *HotReload = "hot_reload";
// inline constexpr const char *Sandboxing = "sandboxing";
}

namespace file {
inline constexpr const char *AutosaveMode = "autosave_mode";
inline constexpr const char *Delay = "delay";
inline constexpr const char *ExcludePatterns = "exclude_patterns";
inline constexpr const char *ShowHiddenFiles = "show_hidden_files";
inline constexpr const char *FileWatcher = "file_watcher";
}
}
