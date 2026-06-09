/// @file
/// @brief Contains xtd::forms::progress_box control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
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
      [[nodiscard]] static auto cancelled() -> bool;
      /// @brief Check if the progress dialog is skipped
      /// @return `true` if the progress dialog is skipped
      [[nodiscard]] static auto skipped() -> bool;
      /// @brief Gets the minimum value of the range of the progress dialog.
      /// @return The minimum value of the range. The default is 0.
      [[nodiscard]] static auto minimum() -> xtd::int32;
      /// @brief Gets the maximum value of the range of the progress dialog.
      /// @return The maximum value of the range. The default is 100.
      [[nodiscard]] static auto maximum() -> xtd::int32;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Hides a progress box in front.
      static auto hide() -> void;
      
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      static auto show(const xtd::string& title) -> void;
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static auto show(const xtd::string& title, xtd::forms::progress_box_options options) -> void;
      
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      static auto show(const xtd::string& title, const xtd::string& message) -> void;
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static auto show(const xtd::string& title, const xtd::string& message, xtd::forms::progress_box_options options) -> void;
      
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      static auto show(const xtd::string& title, const xtd::string& message, xtd::int32 initial_value) -> void;
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static auto show(const xtd::string& title, const xtd::string& message, xtd::int32 initial_value, xtd::forms::progress_box_options options) -> void;
      
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      static auto show(const xtd::string& title, const xtd::string& message, xtd::int32 initial_value, xtd::int32 minimum) -> void;
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static auto show(const xtd::string& title, const xtd::string& message, xtd::int32 initial_value, xtd::int32 minimum, xtd::forms::progress_box_options options) -> void;
      
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      static auto show(const xtd::string& title, const xtd::string& message, xtd::int32 initial_value, xtd::int32 minimum, xtd::int32 maximum) -> void;
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static auto show(const xtd::string& title, const xtd::string& message, xtd::int32 initial_value, xtd::int32 minimum, xtd::int32 maximum, xtd::forms::progress_box_options options) -> void;
      
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      static auto show(const xtd::string& title, const xtd::string& message, xtd::int32 initial_value, xtd::int32 minimum, xtd::int32 maximum, bool marquee, xtd::usize marquee_animation_speed) -> void;
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static auto show(const xtd::string& title, const xtd::string& message, xtd::int32 initial_value, xtd::int32 minimum, xtd::int32 maximum, bool marquee, xtd::usize marquee_animation_speed, xtd::forms::progress_box_options options) -> void;
      
      /// @brief Displays a progress box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param marquee_animation_speed An integer that indicates the time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @param informations An xtd::array of xtd::string that specifies the information texts of the progress dialog.
      static auto show(const xtd::string& title, const xtd::string& message, xtd::int32 initial_value, xtd::int32 minimum, xtd::int32 maximum, bool marquee, xtd::usize marquee_animation_speed, const xtd::array<xtd::string>& informations) -> void;
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
      static auto show(const xtd::string& title, const xtd::string& message, xtd::int32 initial_value, xtd::int32 minimum, xtd::int32 maximum, bool marquee, xtd::usize marquee_animation_speed, const xtd::array<xtd::string>& informations, xtd::forms::progress_box_options options) -> void;
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& title) -> void;
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& title, xtd::forms::progress_box_options options) -> void;
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& message) -> void;
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& message, xtd::forms::progress_box_options options) -> void;
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& message, xtd::int32 initial_value) -> void;
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& message, xtd::int32 initial_value, xtd::forms::progress_box_options options) -> void;
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& message, xtd::int32 initial_value, xtd::int32 minimum) -> void;
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& message, xtd::int32 initial_value, xtd::int32 minimum, xtd::forms::progress_box_options options) -> void;
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& message, xtd::int32 initial_value, xtd::int32 minimum, xtd::int32 maximum) -> void;
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& message, xtd::int32 initial_value, xtd::int32 minimum, xtd::int32 maximum, xtd::forms::progress_box_options options) -> void;
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& message, xtd::int32 initial_value, xtd::int32 minimum, xtd::int32 maximum, bool marquee, xtd::usize marquee_animation_speed) -> void;
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& message, xtd::int32 initial_value, xtd::int32 minimum, xtd::int32 maximum, bool marquee, xtd::usize marquee_animation_speed, xtd::forms::progress_box_options options) -> void;
      
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
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& message, xtd::int32 initial_value, xtd::int32 minimum, xtd::int32 maximum, bool marquee, xtd::usize marquee_animation_speed, const xtd::array<xtd::string>& informations) -> void;
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
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& message, xtd::int32 initial_value, xtd::int32 minimum, xtd::int32 maximum, bool marquee, xtd::usize marquee_animation_speed, const xtd::array<xtd::string>& informations, xtd::forms::progress_box_options options) -> void;
      
      /// @brief Updates progress box
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static auto update(xtd::forms::progress_box_options options) -> void;
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      static auto update(xtd::int32 value) -> void;
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      static auto update(xtd::int32 value, const xtd::string& title) -> void;
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      static auto update(xtd::int32 value, const xtd::string& title, const xtd::string& message) -> void;
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      static auto update(xtd::int32 value, const xtd::string& title, const xtd::string& message, xtd::int32 minimum) -> void;
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      static auto update(xtd::int32 value, const xtd::string& title, const xtd::string& message, xtd::int32 minimum, xtd::int32 maximum) -> void;
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      static auto update(xtd::int32 value, const xtd::string& title, const xtd::string& message, xtd::int32 minimum, xtd::int32 maximum, bool marquee) -> void;
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param marquee_animation_speed An integer that indicates the time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      static auto update(xtd::int32 value, const xtd::string& title, const xtd::string& message, xtd::int32 minimum, xtd::int32 maximum, bool marquee, xtd::usize marquee_animation_speed) -> void;
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::string that specifies the title of the progress dialog.
      /// @param message An xtd::string that specifies the message of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param marquee_animation_speed An integer that indicates the time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @param informations An xtd::array of xtd::string that specifies the information texts of the progress dialog.
      static auto update(xtd::int32 value, const xtd::string& title, const xtd::string& message, xtd::int32 minimum, xtd::int32 maximum, bool marquee, xtd::usize marquee_animation_speed, const xtd::array<xtd::string>& informations) -> void;
      /// @}
      
    private:
      static auto show_progress_box(const xtd::forms::iwin32_window* owner = nullptr, xtd::forms::progress_box_options options = progress_box_options::none, const xtd::string& title = "Please wait..."_t, const xtd::string& message = ""_t, int32 initial_value = 0, int32 minimum = 0, int32 maximum = 100, bool marquee = false, xtd::usize marquee_animation_speed = 100, const xtd::array<xtd::string>& informations = {}) -> void;
      
      static xtd::uptr<progress_dialog> dialog_;
    };
  }
}
