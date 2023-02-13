/// @file
/// @brief Contains xtd::forms::progress_box control.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/static.h>
#include <functional>
#include "progress_dialog.h"
#include "progress_box_options.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays a progress dialog.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
    ///   <tr>
    ///     <th style="width:100px"></th>
    ///     <th><b>Windows</b></th>
    ///     <th><b>macOS</b></th>
    ///     <th><b>Gnome</b></th>
    ///   </tr>
    ///   <tr>
    ///     <th>Light</th>
    ///     <td>@image html dialog_progress_dialog_w.png</td>
    ///     <td>@image html dialog_progress_dialog_m.png</td>
    ///     <td>@image html dialog_progress_dialog_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html dialog_progress_dialog_wd.png</td>
    ///     <td>@image html dialog_progress_dialog_md.png</td>
    ///     <td>@image html dialog_progress_dialog_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of xtd::forms::progress_box dialog.
    /// @include progress_box.cpp
    class progress_box final static_ {
    public:
      /// @name Properties
      
      /// @{
      /// @brief Check if the progress dialog is canceled
      /// @return true if the progress dialog is canceled
      static bool cancelled() { return dialog_ && dialog_->cancelled(); }
      /// @brief Check if the progress dialog is skipped
      /// @return true if the progress dialog is skipped
      static bool skipped() { return dialog_ && dialog_->skipped(); }
      /// @brief Gets the minimum value of the range of the progress dialog.
      /// @return The minimum value of the range. The default is 0.
      static int32 minimum() { return dialog_ ? dialog_->minimum() : 0; }
      /// @brief Gets the maximum value of the range of the progress dialog.
      /// @return The maximum value of the range. The default is 100.
      static int32 maximum() { return dialog_ ? dialog_->maximum() : 100; }
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Hides a progress box in front.
      static void hide() {dialog_.reset();}
      
      /// @brief Displays a progress box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      static void show(const xtd::ustring& title) { show_progress_box(nullptr, progress_box_options::none, title); }
      /// @brief Displays a progress box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const xtd::ustring& title, const progress_box_options options) { show_progress_box(nullptr, options, title); }
      
      /// @brief Displays a progress box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      static void show(const xtd::ustring& title, const xtd::ustring& message) { show_progress_box(nullptr, progress_box_options::none, title, message); }
      /// @brief Displays a progress box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const xtd::ustring& title, const xtd::ustring& message, const progress_box_options options) { show_progress_box(nullptr, options, title, message); }
      
      /// @brief Displays a progress box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      static void show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value) { show_progress_box(nullptr, progress_box_options::none, title, message, initial_value); }
      /// @brief Displays a progress box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const progress_box_options options) { show_progress_box(nullptr, options, title, message, initial_value); }
      
      /// @brief Displays a progress box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      static void show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum) { show_progress_box(nullptr, progress_box_options::none, title, message, initial_value, minimum); }
      /// @brief Displays a progress box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const progress_box_options options) { show_progress_box(nullptr, options, title, message, initial_value, minimum); }
      
      /// @brief Displays a progress box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      static void show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum) { show_progress_box(nullptr, progress_box_options::none, title, message, initial_value, minimum, maximum); }
      /// @brief Displays a progress box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const progress_box_options options) { show_progress_box(nullptr, options, title, message, initial_value, minimum, maximum); }
      
      /// @brief Displays a progress box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      static void show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed) { show_progress_box(nullptr, progress_box_options::none, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed); }
      /// @brief Displays a progress box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const progress_box_options options) { show_progress_box(nullptr, options, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed); }
      
      /// @brief Displays a progress box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param marquee_animation_speed An integer that indicates the time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @param informations An std::vector of xtd::ustring that specifies the information texts of the progress dialog.
      static void show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const std::vector<xtd::ustring>& informations) { show_progress_box(nullptr, progress_box_options::none, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, informations); }
      /// @brief Displays a progress box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param marquee_animation_speed An integer that indicates the time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @param informations An std::vector of xtd::ustring that specifies the information texts of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const std::vector<xtd::ustring>& informations, const progress_box_options options) { show_progress_box(nullptr, options, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, informations); }
      
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      static void show(const iwin32_window& owner, const xtd::ustring& title) { show_progress_box(&owner, progress_box_options::none, title); }
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const iwin32_window& owner, const xtd::ustring& title, const progress_box_options options) { show_progress_box(&owner, options, title); }
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message) { show_progress_box(&owner, progress_box_options::none, title, message); }
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const progress_box_options options) { show_progress_box(&owner, options, title, message); }
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value) { show_progress_box(&owner, progress_box_options::none, title, message, initial_value); }
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const progress_box_options options) { show_progress_box(&owner, options, title, message, initial_value); }
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum) { show_progress_box(&owner, progress_box_options::none, title, message, initial_value, minimum); }
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const progress_box_options options) { show_progress_box(&owner, options, title, message, initial_value, minimum); }
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum) { show_progress_box(&owner, progress_box_options::none, title, message, initial_value, minimum, maximum); }
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const progress_box_options options) { show_progress_box(&owner, options, title, message, initial_value, minimum, maximum); }
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed) { show_progress_box(&owner, progress_box_options::none, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed); }
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const progress_box_options options) { show_progress_box(&owner, options, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed); }
      
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param marquee_animation_speed An integer that indicates the time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @param informations An std::vector of xtd::ustring that specifies the information texts of the progress dialog.
      static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const std::vector<xtd::ustring>& informations) { show_progress_box(&owner, progress_box_options::none, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, informations); }
      /// @brief Displays a progress dialog box in front of a specified window.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the progress dialog box.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param initial_value An integer that indicates the initial value of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param marquee_animation_speed An integer that indicates the time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @param informations An std::vector of xtd::ustring that specifies the information texts of the progress dialog.
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const std::vector<xtd::ustring>& informations, const progress_box_options options) { show_progress_box(&owner, options, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, informations); }
      
      /// @brief Updates progress box
      /// @param options A bitwise combination of enum xtd::forms::progress_box_options to specify additional options to the progress dialog box.
      static void update(const progress_box_options options) {if (dialog_) dialog_->show_cancel_button((options & progress_box_options::show_cancel_button) == progress_box_options::show_cancel_button).show_skip_button((options & progress_box_options::show_skip_button) == progress_box_options::show_skip_button).show_elapsed_time((options & progress_box_options::show_elapsed_time) == progress_box_options::show_elapsed_time).show_estimated_time((options & progress_box_options::show_estimated_time) == progress_box_options::show_estimated_time).show_remaining_time((options & progress_box_options::show_remaining_time) == progress_box_options::show_remaining_time);}
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      static void update(const int32 value) { if (dialog_) dialog_->value(value); }
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      static void update(const int32 value, const xtd::ustring& title) { if (dialog_) dialog_->value(value).text(title); }
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      static void update(const int32 value, const xtd::ustring& title, const xtd::ustring& message) { if (dialog_) dialog_->value(value).text(title).message(message); }
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      static void update(const int32 value, const xtd::ustring& title, const xtd::ustring& message, const int32 minimum) { if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum); }
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      static void update(const int32 value, const xtd::ustring& title, const xtd::ustring& message, const int32 minimum, const int32 maximum) { if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum).maximum(maximum); }
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      static void update(const int32 value, const xtd::ustring& title, const xtd::ustring& message, const int32 minimum, const int32 maximum, const bool marquee) { if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum).maximum(maximum).marquee(marquee); }
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param marquee_animation_speed An integer that indicates the time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      static void update(const int32 value, const xtd::ustring& title, const xtd::ustring& message, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed) { if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum).maximum(maximum).marquee(marquee).marquee_animation_speed(marquee_animation_speed); }
      /// @brief Updates progress box
      /// @param value An integer that indicates the value of the progress dialog.
      /// @param title An xtd::ustring that specifies the title of the progress dialog.
      /// @param message An xtd::ustring that specifies the message of the progress dialog.
      /// @param minimum An integer that indicates the minimum value of the progress dialog.
      /// @param maximum An integer that indicates the maximum value of the progress dialog.
      /// @param marquee A boolean that Indicates progress by continuously scrolling a block across a xtd::forms::progress_bar in a marquee fashion.
      /// @param marquee_animation_speed An integer that indicates the time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @param informations An std::vector of xtd::ustring that specifies the information texts of the progress dialog.
      static void update(const int32 value, const xtd::ustring& title, const xtd::ustring& message, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const std::vector<xtd::ustring>& informations) { if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum).maximum(maximum).marquee(marquee).marquee_animation_speed(marquee_animation_speed).informations(informations); }
      /// @}
      
    private:
      inline static std::unique_ptr<progress_dialog> dialog_;
      static void show_progress_box(const iwin32_window* owner = nullptr, const progress_box_options options = progress_box_options::none, const xtd::ustring& title = "Please wait..."_t, const xtd::ustring& message = ""_t, int32 initial_value = 0, int32 minimum = 0, int32 maximum = 100, const bool marquee = false, size_t marquee_animation_speed = 100, const std::vector<xtd::ustring>& informations = std::vector<xtd::ustring>()) {
        if (dialog_) return;
        dialog_ = std::make_unique<progress_dialog>();
        dialog_->text(title)
        .value(initial_value)
        .message(message)
        .maximum(maximum)
        .minimum(minimum)
        .marquee(marquee)
        .marquee_animation_speed(marquee_animation_speed)
        .informations(informations)
        .show_cancel_button((options & progress_box_options::show_cancel_button) == progress_box_options::show_cancel_button)
        .show_skip_button((options & progress_box_options::show_skip_button) == progress_box_options::show_skip_button)
        .show_elapsed_time((options & progress_box_options::show_elapsed_time) == progress_box_options::show_elapsed_time)
        .show_estimated_time((options & progress_box_options::show_estimated_time) == progress_box_options::show_estimated_time)
        .show_remaining_time((options & progress_box_options::show_remaining_time) == progress_box_options::show_remaining_time);
        owner ? dialog_->show(*owner) : dialog_->show();
      }
    };
  }
}
