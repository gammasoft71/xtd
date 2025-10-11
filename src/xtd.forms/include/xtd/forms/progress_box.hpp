/// @file
/// @brief Contains xtd::forms::progress_box control.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "progress_box_options.hpp"
#include "progress_dialog.hpp"
#include <xtd/globalization/translator>
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays a progress dialog.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/progress_box>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                     | macOS                                       | Gnome                                       |
    /// | ----- | ------------------------------------------- | ------------------------------------------- | ------------------------------------------- |
    /// | Light |  @image html dialog_progress_dialog_w.png   |  @image html dialog_progress_dialog_m.png   |  @image html dialog_progress_dialog_g.png   |
    /// | Dark  |  @image html dialog_progress_dialog_wd.png  |  @image html dialog_progress_dialog_md.png  |  @image html dialog_progress_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of xtd::forms::progress_box dialog.
    /// @include progress_box.cpp
    class forms_export_ progress_box final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Check if the progress dialog is canceled
      /// @return `true` if the progress dialog is canceled
      static bool cancelled();
      /// @brief Check if the progress dialog is skipped
      /// @return `true` if the progress dialog is skipped
      static bool skipped();
      /// @brief Gets the minimum value of the range of the progress dialog.
      /// @return The minimum value of the range. The default is 0.
      static int32 minimum();
      /// @brief Gets the maximum value of the range of the progress dialog.
      /// @return The maximum value of the range. The default is 100.
      static int32 maximum();
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Hides a progress box in front.
      static void hide();
      
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      static void show(const xtd::string& title);
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const xtd::string& title, const progress_box_options options);
      
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      static void show(const xtd::string& title, const xtd::string& message);
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const xtd::string& title, const xtd::string& message, const progress_box_options options);
      
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      static void show(const xtd::string& title, const xtd::string& message, const int32 initial_value);
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const xtd::string& title, const xtd::string& message, const int32 initial_value, const progress_box_options options);
      
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      static void show(const xtd::string& title, const xtd::string& message, const int32 initial_value, const int32 minimum);
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const xtd::string& title, const xtd::string& message, const int32 initial_value, const int32 minimum, const progress_box_options options);
      
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      static void show(const xtd::string& title, const xtd::string& message, const int32 initial_value, const int32 minimum, const int32 maximum);
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const xtd::string& title, const xtd::string& message, const int32 initial_value, const int32 minimum, const int32 maximum, const progress_box_options options);
      
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      static void show(const xtd::string& title, const xtd::string& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed);
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const xtd::string& title, const xtd::string& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const progress_box_options options);
      
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param marquee_animation_speed An integer that indicates the time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @param informations An xtd::array of xtd::string that specifies the information texts of the progress dialog.
      static void show(const xtd::string& title, const xtd::string& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const xtd::array<xtd::string>& informations);
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param marquee_animation_speed An integer that indicates the time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @param informations An xtd::array of xtd::string that specifies the information texts of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const xtd::string& title, const xtd::string& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const xtd::array<xtd::string>& informations, const progress_box_options options);
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      static void show(const iwin32_window& owner, const xtd::string& title);
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const iwin32_window& owner, const xtd::string& title, const progress_box_options options);
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      static void show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message);
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, const progress_box_options options);
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      static void show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, const int32 initial_value);
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, const int32 initial_value, const progress_box_options options);
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      static void show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, const int32 initial_value, const int32 minimum);
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, const int32 initial_value, const int32 minimum, const progress_box_options options);
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      static void show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, const int32 initial_value, const int32 minimum, const int32 maximum);
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, const int32 initial_value, const int32 minimum, const int32 maximum, const progress_box_options options);
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      static void show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed);
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const progress_box_options options);
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param marquee_animation_speed An integer that indicates the time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @param informations An xtd::array of xtd::string that specifies the information texts of the progress dialog.
      static void show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const xtd::array<xtd::string>& informations);
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param marquee_animation_speed An integer that indicates the time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @param informations An xtd::array of xtd::string that specifies the information texts of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const xtd::array<xtd::string>& informations, const progress_box_options options);
      
      /// @brief Updates progress box
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void update(const progress_box_options options);
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      static void update(const int32 value);
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      static void update(const int32 value, const xtd::string& title);
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      static void update(const int32 value, const xtd::string& title, const xtd::string& message);
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      static void update(const int32 value, const xtd::string& title, const xtd::string& message, const int32 minimum);
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      static void update(const int32 value, const xtd::string& title, const xtd::string& message, const int32 minimum, const int32 maximum);
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      static void update(const int32 value, const xtd::string& title, const xtd::string& message, const int32 minimum, const int32 maximum, const bool marquee);
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param marquee_animation_speed An integer that indicates the time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      static void update(const int32 value, const xtd::string& title, const xtd::string& message, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed);
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param marquee_animation_speed An integer that indicates the time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @param informations An xtd::array of xtd::string that specifies the information texts of the progress dialog.
      static void update(const int32 value, const xtd::string& title, const xtd::string& message, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const xtd::array<xtd::string>& informations);
      /// @}
      
    private:
      static void show_progress_box(const iwin32_window* owner = nullptr, const progress_box_options options = progress_box_options::none, const xtd::string& title = "Please wait..."_t, const xtd::string& message = ""_t, int32 initial_value = 0, int32 minimum = 0, int32 maximum = 100, const bool marquee = false, size_t marquee_animation_speed = 100, const xtd::array<xtd::string>& informations = {});
      
      static xtd::uptr<progress_dialog> dialog_;
    };
  }
}
