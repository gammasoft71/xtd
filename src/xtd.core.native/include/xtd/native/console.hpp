/// @file
/// @brief Contains console API.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "console_color.hpp"
#include "console_special_key.hpp"
#include <xtd/core_native_export>
#include <functional>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  class console;
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains console native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ console final {
      console() = delete;
      friend xtd::console;
    protected:
      /// @name Protected Static Methods
      
      /// @{
      /// @brief Gets the background color of the console.
      /// @return the background console color.
      /// @warning Internal use only
      [[nodiscard]] static auto background_color() -> std::int32_t;
      /// @brief Sets the background color of the console.
      /// @param color the background console color.
      /// @return `true` if successfull; otherwise `false`.
      /// @warning Internal use only
      static auto background_color(std::int32_t color) -> bool;
      
      /// @brief Plays the sound of a beep of a specified frequency and duration through the console speaker.
      /// @param frequency The frequency of the beep, ranging from 37 to 32767 hertz
      /// @param duration The duration of the beep measured in milliseconds
      /// @return `true` if successfull; otherwise `false`.
      /// @warning Internal use only
      static auto beep(uint32_t frequency, std::uint32_t duration) -> bool;
      
      /// @brief Gets the height of the buffer area.
      /// @return The current height, in rows, of the buffer area.
      /// @warning Internal use only
      [[nodiscard]] static auto buffer_height() -> std::int32_t;
      /// @brief Sets or sets the height of the buffer area.
      /// @param height The current height, in rows, of the buffer area.
      /// @return `true` if successfull; otherwise `false`.
      /// @warning Internal use only
      static auto buffer_height(std::int32_t height) -> bool;
      /// @brief Gets the width of the buffer area.
      /// @return The current width, in columns, of the buffer area.
      /// @warning Internal use only
      
      [[nodiscard]] static auto buffer_width() -> std::int32_t;
      /// @brief Sets the width of the buffer area.
      /// @param width The current width, in columns, of the buffer area.
      /// @return `true` if successfull; otherwise `false`.
      /// @warning Internal use only
      static auto buffer_width(std::int32_t width) -> bool;
      
      /// @brief Gets a value indicating whether the CAPS LOCK keyboard toggle is turned on or turned off.
      /// @return `true` if CAPS LOCK is turned on; `false` if CAPS LOCK is turned off.
      /// @warning Internal use only
      [[nodiscard]] static auto caps_lock() -> bool;
      
      /// @brief Clears the console buffer and corresponding console window of display information.
      /// @return `true` if successfull; otherwise `false`.
      /// @warning Internal use only
      static auto clear() -> bool;
      
      /// @brief Gets the column position of the cursor within the buffer area.
      /// @return The current position, in columns, of the cursor.
      /// @warning Internal use only
      [[nodiscard]] static auto cursor_left() -> std::int32_t;
      
      /// @brief Gets or sets the height of the cursor within a character cell.
      /// @return The size of the cursor expressed as a percentage of the height of a character cell. The property value ranges from 1 to 100.
      /// @warning Internal use only
      [[nodiscard]] static auto cursor_size() -> std::int32_t;
      /// @brief Sets the height of the cursor within a character cell.
      /// @param size The size of the cursor expressed as a percentage of the height of a character cell. The property value ranges from 1 to 100.
      /// @return `true` if successfull; otherwise `false`.
      /// @warning Internal use only
      static auto cursor_size(std::int32_t size) -> bool;
      
      /// @brief Gets the row position of the cursor within the buffer area.
      /// @return The current position, in rows, of the cursor.
      /// @warning Internal use only
      [[nodiscard]] static auto cursor_top() -> std::int32_t;
      
      /// @brief Gets a value indicating whether the cursor is visible.
      /// @return `true` if the cursor is visible; otherwise, `false`.
      /// @warning Internal use only
      [[nodiscard]] static auto cursor_visible() -> bool;
      /// @brief Sets a value indicating whether the cursor is visible.
      /// @param visible `true` if the cursor is visible; otherwise, `false`.
      /// @return `true` if successfull; otherwise `false`.
      /// @warning Internal use only
      static auto cursor_visible(bool visible) -> bool;
      
      /// @brief Sets the echo of the console on or off.
      /// @param on if `true` the echo is on; otherwise is off.
      /// @warning Internal use only
      static auto echo(bool on) -> bool;
      
      /// @brief Gets the foreground color of the console.
      /// @return the foreground console color.
      /// @warning Internal use only
      [[nodiscard]] static auto foreground_color() -> std::int32_t;
      /// @brief Sets the foreground color of the console.
      /// @param color the foreground console color.
      /// @return `true` if successfull; otherwise `false`.
      /// @warning Internal use only
      static auto foreground_color(std::int32_t color) -> bool;
      
      /// @brief Gets the code page the console uses to read input.
      /// @return The code page used to read console input.
      /// @warning Internal use only
      [[nodiscard]] static auto input_code_page() -> std::int32_t;
      /// @brief Sets the code page the console uses to read input.
      /// @param code_page The code page used to read console input.
      /// @return `true` if successfull; otherwise `false`.
      /// @warning Internal use only
      static auto input_code_page(std::int32_t codePage) -> bool;
      
      /// @brief Gets a value indicating whether a key press is available in the input stream.
      /// @return `true` if a key press is available; otherwise, `false`
      /// @warning Internal use only
      [[nodiscard]] static auto key_available() -> bool;
      
      /// @brief Gets the largest possible number of console window rows, based on the current font and screen resolution.
      /// @param The height of the largest possible console window measured in rows.
      /// @warning Internal use only
      [[nodiscard]] static auto largest_window_height() -> std::int32_t;
      /// @brief Gets the largest possible number of console window columns, based on the current font and screen resolution.
      /// @param The width of the largest possible console window measured in columns.
      /// @warning Internal use only
      [[nodiscard]] static auto largest_window_width() -> std::int32_t;
      
      /// @brief Gets a value indicating whether the NUM LOCK keyboard toggle is turned on or turned off.
      /// @return `true` if NUM LOCK is turned on; `false` if NUM LOCK is turned off.
      /// @warning Internal use only
      [[nodiscard]] static auto number_lock() -> bool;
      
      /// @brief Gets the code page the console uses to write output.
      /// @return The code page used to write console output.
      /// @warning Internal use only
      [[nodiscard]] static auto output_code_page() -> std::int32_t;
      /// @brief Sets the code page the console uses to write output.
      /// @param code_page The code page used to write console output.
      /// @return `true` if successfull; otherwise `false`.
      /// @warning Internal use only
      [[nodiscard]] static auto output_code_page(std::int32_t codePage) -> bool;
      
      /// @brief Obtains the next character or function key pressed by the user.
      /// @param key_char A bitwise combination of the enumeration values. There is no default value.
      /// @param key_code A value that identifies the console key that was pressed.
      /// @param alt `true` if alt key modifier is pressed; otherwise `false`.
      /// @param shift `true` if shift key modifier is pressed; otherwise `false`.
      /// @param ctrl `true` if control key modifier is pressed; otherwise `false`.
      /// @remarks The five parameters will contains informations on key pressed.
      /// @warning Internal use only
      static auto read_key(char32_t& key_char, char32_t& key_code, bool& alt, bool& shift, bool& ctrl) -> void;
      
      /// @brief Register the user cancel callback.
      /// @param user_cancel_callback The user cancel callback method to register.
      /// @remarks This callback is call when when the Control modifier key (Ctrl) and either the ConsoleKey.C console key (C) or the Break key are pressed simultaneously (Ctrl+C or Ctrl+Break).
      /// @remarks By default, the return of callback is `false`, which causes program execution to terminate when the event handler exits. Changing its return to `true` specifies that the application should continue to execute.
      /// @warning Internal use only
      static auto register_user_cancel_callback(std::function<bool(std::int32_t)> user_cancel_callback) -> void;
      
      /// @brief Sets the foreground and background console colors to their defaults.
      /// @remarks The foreground and background colors are restored to the colors that existed when the current process began. For more information, see the foreground_color and background_color properties.
      /// @return `true` if successfull; otherwise `false`.
      /// @warning Internal use only
      static auto reset_color() -> bool;
      
      /// @brief Resets terminale mode and sets the foreground and background console colors to their defaults.
      /// @remarks The foreground and background colors are restored to the colors that existed when the current process began. For more information, see the foreground_color and background_color properties.
      /// @return `true` if successfull; otherwise `false`.
      /// @warning Internal use only
      static auto reset_console() -> bool;
      
      /// @brief Sets the position of the cursor.
      /// @param left The column position of the cursor. Columns are numbered from left to right starting at 0.
      /// @param top The row position of the cursor. Rows are numbered from top to bottom starting at 0.
      /// @return `true` if successfull; otherwise `false`.
      /// @warning Internal use only
      static auto set_cursor_position(std::int32_t left, std::int32_t top) -> bool;
      
      /// @brief Gets the title to display in the console title bar.
      /// @return The string to be displayed in the title bar of the console. The maximum length of the title string is 24500 characters.
      /// @warning Internal use only
      [[nodiscard]] static auto title() -> std::string;
      /// @brief Sets the title to display in the console title bar.
      /// @param title The string to be displayed in the title bar of the console. The maximum length of the title string is 24500 characters.
      /// @return `true` if successfull; otherwise `false`.
      /// @warning Internal use only
      static auto title(const std::string& title) -> bool;
      
      /// @brief Gets a value indicating whether the combination of the Control modifier key and C console key (Ctrl+C) is treated as ordinary input or as an interruption that is handled by the operating system.
      /// @return `true` if Ctrl+C is treated as ordinary input; otherwise, `false`.
      /// @warning Internal use only
      [[nodiscard]] static auto treat_control_c_as_input() -> bool;
      /// @brief Sets a value indicating whether the combination of the Control modifier key and C console key (Ctrl+C) is treated as ordinary input or as an interruption that is handled by the operating system.
      /// @param treat_control_c_as_input `true` if Ctrl+C is treated as ordinary input; otherwise, `false`.
      /// @return `true` if successfull; otherwise `false`.
      /// @warning Internal use only
      static auto treat_control_c_as_input(bool treat_control_c_as_input) -> bool;
      
      /// @brief Gets the height of the console window area.
      /// @return The height of the console window measured in rows.
      /// @warning Internal use only
      [[nodiscard]] static auto window_height() -> std::int32_t;
      /// @brief Sets the height of the console window area.
      /// @param height The height of the console window measured in rows.
      /// @return `true` if successfull; otherwise `false`.
      /// @warning Internal use only
      static auto window_height(std::int32_t height) -> bool;
      
      /// @brief Gets the left of the console window area.
      /// @return The left of the console window measured in columns.
      /// @warning Internal use only
      [[nodiscard]] static auto window_left() -> std::int32_t;
      /// @brief Sets the left of the console window area.
      /// @param left The left of the console window measured in columns.
      /// @return `true` if successfull; otherwise `false`.
      /// @warning Internal use only
      static auto window_left(std::int32_t left) -> bool;
      
      /// @brief Gets the top of the console window area.
      /// @return The top of the console window measured in rows.
      /// @warning Internal use only
      [[nodiscard]] static auto window_top() -> std::int32_t;
      /// @brief Sets the top of the console window area.
      /// @param top The top of the console window measured in rows.
      /// @return `true` if successfull; otherwise `false`.
      /// @warning Internal use only
      static auto window_top(std::int32_t top) -> bool;
      
      /// @brief Gets the width of the console window area.
      /// @return The width of the console window measured in columns.
      /// @warning Internal use only
      [[nodiscard]] static auto window_width() -> std::int32_t;
      /// @brief Sets the width of the console window area.
      /// @param width The width of the console window measured in columns.
      /// @return `true` if successfull; otherwise `false`.
      /// @warning Internal use only
      static auto window_width(std::int32_t width) -> bool;
      /// @}
    };
  }
}
