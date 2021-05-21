/// @file
/// @brief Contains console API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/core_native_export.h>
#include <functional>
#include <string>
#include "console_color.h"
#include "console_special_key.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
    /// @brief The xtd::core::native namespace contains internal native API definitions to access underlying oerating system components used by xtd.core library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains console native API.
      /// @par Library
      /// xtd.core.native
      /// @ingroup xtd_core_native native
      /// @warning Internal use only
      class core_native_export_ console final {
      public:
        /// @brief Gets the background color of the console.
        /// @return the background console color.
        /// @warning Internal use only
        static int32_t background_color();
        /// @brief Sets the background color of the console.
        /// @param color the background console color.
        /// @warning Internal use only
        static void background_color(int32_t color);
        /// @brief Plays the sound of a beep of a specified frequency and duration through the console speaker.
        /// @param frequency The frequency of the beep, ranging from 37 to 32767 hertz
        /// @param duration The duration of the beep measured in milliseconds
        /// @warning Internal use only
        static void beep(uint32_t frequency, uint32_t duration);
        /// @brief Gets the height of the buffer area.
        /// @return The current height, in rows, of the buffer area.
        /// @warning Internal use only
        static int32_t buffer_height();
        /// @brief Sets or sets the height of the buffer area.
        /// @param height The current height, in rows, of the buffer area.
        /// @warning Internal use only
        static void buffer_height(int32_t height);
        /// @brief Gets the width of the buffer area.
        /// @return The current width, in columns, of the buffer area.
        /// @warning Internal use only
        static int32_t buffer_width();
        /// @brief Sets the width of the buffer area.
        /// @param width The current width, in columns, of the buffer area.
        /// @warning Internal use only
        static void buffer_width(int32_t width);
        /// @brief Gets a value indicating whether the CAPS LOCK keyboard toggle is turned on or turned off.
        /// @return true if CAPS LOCK is turned on; false if CAPS LOCK is turned off.
        /// @warning Internal use only
        static bool caps_lock();
        /// @brief Clears the console buffer and corresponding console window of display information.
        /// @warning Internal use only
        static void clear();
        /// @brief Gets the column position of the cursor within the buffer area.
        /// @return The current position, in columns, of the cursor.
        /// @warning Internal use only
        static int32_t cursor_left();
        /// @brief Gets or sets the height of the cursor within a character cell.
        /// @return The size of the cursor expressed as a percentage of the height of a character cell. The property value ranges from 1 to 100.
        /// @warning Internal use only
        static int32_t cursor_size();
        /// @brief Sets the height of the cursor within a character cell.
        /// @param size The size of the cursor expressed as a percentage of the height of a character cell. The property value ranges from 1 to 100.
        /// @warning Internal use only
        static void cursor_size(int32_t size);
        /// @brief Gets the row position of the cursor within the buffer area.
        /// @return The current position, in rows, of the cursor.
        /// @warning Internal use only
        static int32_t cursor_top();
        /// @brief Gets a value indicating whether the cursor is visible.
        /// @return  true if the cursor is visible; otherwise, false.
        /// @warning Internal use only
        static bool cursor_visible();
        /// @brief Sets a value indicating whether the cursor is visible.
        /// @param visible true if the cursor is visible; otherwise, false.
        /// @warning Internal use only
        static void cursor_visible(bool visible);
        /// @brief Gets the foreground color of the console.
        /// @return the foreground console color.
        /// @warning Internal use only
        static int32_t foreground_color();
        /// @brief Sets the foreground color of the console.
        /// @param color the foreground console color.
        /// @warning Internal use only
        static void foreground_color(int32_t color);
        /// @brief Gets the code page the console uses to read input.
        /// @return The code page used to read console input.
        /// @warning Internal use only
        static int32_t input_code_page();
        /// @brief Sets the code page the console uses to read input.
        /// @param code_page The code page used to read console input.
        /// @warning Internal use only
        static void input_code_page(int32_t codePage);
        /// @brief Gets a value indicating whether a key press is available in the input stream.
        /// @param true if a key press is available; otherwise, false
        /// @warning Internal use only
        static bool key_available();
        /// @brief Gets the largest possible number of console window rows, based on the current font and screen resolution.
        /// @param The height of the largest possible console window measured in rows.
        /// @warning Internal use only
        static int32_t largest_window_height();
        /// @brief Gets the largest possible number of console window columns, based on the current font and screen resolution.
        /// @param The width of the largest possible console window measured in colomns.
        /// @warning Internal use only
        static int32_t largest_window_width();
        /// @brief Gets a value indicating whether the NUM LOCK keyboard toggle is turned on or turned off.
        /// @param true if NUM LOCK is turned on; false if NUM LOCK is turned off.
        /// @warning Internal use only
        static bool number_lock();
        /// @brief Gets the code page the console uses to write output.
        /// @return The code page used to write console output.
        /// @warning Internal use only
        static int32_t output_code_page();
        /// @brief Sets the code page the console uses to write output.
        /// @param code_page The code page used to write console output.
        /// @warning Internal use only
        static void output_code_page(int32_t codePage);
        /// @brief Register the user cancel callback.
        /// @param user_cancel_callback The user cancel callback method to register.
        /// @remarks This callback is call when when the Control modifier key (Ctrl) and either the ConsoleKey.C console key (C) or the Break key are pressed simultaneously (Ctrl+C or Ctrl+Break).
        /// @remarks By default, the return of callback is false, which causes program execution to terminate when the event handler exits. Changing its return to true specifies that the application should continue to execute.
        /// @warning Internal use only
        static void register_user_cancel_callback(std::function<bool(int32_t)> user_cancel_callback);
        /// @brief Obtains the next character or function key pressed by the user.
        /// @param key_char A bitwise combination of the enumeration values. There is no default value.
        /// @param key_code A value that identifies the console key that was pressed.
        /// @param alt true if alt key modifier is pressed; otherwise false.
        /// @param shift true if shift key modifier is pressed; otherwise false.
        /// @param ctrl true if control key modifier is pressed; otherwise false.
        /// @remarks The five parametrs will contains informations on key pressed.
        /// @warning Internal use only
        static void read_key(int32_t& key_char, int32_t& key_code, bool& alt, bool& shift, bool& ctrl);
        /// @brief Sets the foreground and background console colors to their defaults.
        /// @remarks The foreground and background colors are restored to the colors that existed when the current process began. For more information, see the foreground_color and background_color properties.
        /// @warning Internal use only
        static void reset_color();
        /// @brief Sets the position of the cursor.
        /// @param left The column position of the cursor. Columns are numbered from left to right starting at 0.
        /// @param top The row position of the cursor. Rows are numbered from top to bottom starting at 0.
        /// @warning Internal use only
        static void set_cursor_position(int32_t left, int32_t top);
        /// @brief Gets the title to display in the console title bar.
        /// @return The string to be displayed in the title bar of the console. The maximum length of the title string is 24500 characters.
        /// @warning Internal use only
        static std::string title();
        /// @brief Sets the title to display in the console title bar.
        /// @param title The string to be displayed in the title bar of the console. The maximum length of the title string is 24500 characters.
        /// @warning Internal use only
        static void title(const std::string& title);
        /// @brief Gets a value indicating whether the combination of the Control modifier key and C console key (Ctrl+C) is treated as ordinary input or as an interruption that is handled by the operating system.
        /// @return true if Ctrl+C is treated as ordinary input; otherwise, false.
        /// @warning Internal use only
        static bool treat_control_c_as_input();
        /// @brief Sets a value indicating whether the combination of the Control modifier key and C console key (Ctrl+C) is treated as ordinary input or as an interruption that is handled by the operating system.
        /// @param treat_control_c_as_input true if Ctrl+C is treated as ordinary input; otherwise, false.
        /// @warning Internal use only
        static void treat_control_c_as_input(bool treat_control_c_as_input);
        /// @brief Unregister the user cancel callback previously registered with xtd::native::console::register_user_cancel_callback method.
        /// @warning Internal use only
        static void unregister_user_cancel_callback();
        /// @brief Gets the height of the console window area.
        /// @return The height of the console window measured in rows.
        /// @warning Internal use only
        static int32_t window_height();
        /// @brief Sets the height of the console window area.
        /// @param height The height of the console window measured in rows.
        /// @warning Internal use only
        static void window_height(int32_t height);
        /// @brief Gets the left of the console window area.
        /// @return The left of the console window measured in columns.
        /// @warning Internal use only
        static int32_t window_left();
        /// @brief Sets the left of the console window area.
        /// @param left The left of the console window measured in columns.
        /// @warning Internal use only
        static void window_left(int32_t left);
        /// @brief Gets the top of the console window area.
        /// @return The top of the console window measured in rows.
        /// @warning Internal use only
        static int32_t window_top();
        /// @brief Sets the top of the console window area.
        /// @param top The top of the console window measured in rows.
        /// @warning Internal use only
        static void window_top(int32_t top);
        /// @brief Gets the width of the console window area.
        /// @return The width of the console window measured in columns.
        /// @warning Internal use only
        static int32_t window_width();
        /// @brief Sets the width of the console window area.
        /// @param width The width of the console window measured in columns.
        /// @warning Internal use only
        static void window_width(int32_t width);
      };
    }
}
