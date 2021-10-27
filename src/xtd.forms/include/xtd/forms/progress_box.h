/// @file
/// @brief Contains xtd::forms::progress_box control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/static.h>
#include <functional>
#include "progress_dialog.h"
#include "progress_box_options.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays a file save dialog to the user to select a location for saving a file.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Examples
    /// The following code example demonstrate the use of xtd::forms::progress_box dialog.
    /// @include progress_box.cpp
    class progress_box final static_ {
    public:
      /// @brief Hides a progress box in front.
     static void hide() {
        delete dialog_;
        dialog_ = nullptr;
     }

     static void show(const xtd::ustring& title) { show_progress_box(nullptr, title); }
     static void show(const xtd::ustring& title, const progress_box_options options) { show_progress_box(nullptr, title, ""_t, 0, 0, 100, false, 100, std::vector<xtd::ustring>(), options); }
     static void show(const xtd::ustring& title, const xtd::ustring& message) { show_progress_box(nullptr, title, message, 0, 0, 100, false, 100, std::vector<xtd::ustring>(), progress_box_options::none); }
     static void show(const xtd::ustring& title, const xtd::ustring& message, const progress_box_options options) { show_progress_box(nullptr, title, message, 0, 0, 100, false, 100, std::vector<xtd::ustring>(), options); }
     static void show(const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value) { show_progress_box(nullptr, title, message, initial_value, 0, 100, false, 100, std::vector<xtd::ustring>(), progress_box_options::none); }
     static void show(const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value, const progress_box_options options) { show_progress_box(nullptr, title, message, initial_value, 0, 100, false, 100, std::vector<xtd::ustring>(), options); }
     static void show(const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value, const int32_t minimum) { show_progress_box(nullptr, title, message, initial_value, minimum, 100, false, 100, std::vector<xtd::ustring>(), progress_box_options::none); }
     static void show(const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value, const int32_t minimum, const progress_box_options options) { show_progress_box(nullptr, title, message, initial_value, minimum, 100, false, 100, std::vector<xtd::ustring>(), options); }
     static void show(const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value, const int32_t minimum, const int32_t maximum) { show_progress_box(nullptr, title, message, initial_value, minimum, maximum, false, 100, std::vector<xtd::ustring>(), progress_box_options::none); }
     static void show(const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value, const int32_t minimum, const int32_t maximum, const progress_box_options options) { show_progress_box(nullptr, title, message, initial_value, minimum, maximum, false, 100, std::vector<xtd::ustring>(), options); }
     static void show(const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value, const int32_t minimum, const int32_t maximum, const bool marquee, const size_t marquee_animation_speed) { show_progress_box(nullptr, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, std::vector<xtd::ustring>(), progress_box_options::none); }
     static void show(const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value, const int32_t minimum, const int32_t maximum, const bool marquee, const size_t marquee_animation_speed, const progress_box_options options) { show_progress_box(nullptr, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, std::vector<xtd::ustring>(), options); }
     static void show(const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value, const int32_t minimum, const int32_t maximum, const bool marquee, const size_t marquee_animation_speed, const std::vector<xtd::ustring>& informations) { show_progress_box(nullptr, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, informations, progress_box_options::none); }
     static void show(const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value, const int32_t minimum, const int32_t maximum, const bool marquee, const size_t marquee_animation_speed, const std::vector<xtd::ustring>& informations, const progress_box_options options) { show_progress_box(nullptr, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, informations, options); }

     static void show(const iwin32_window& owner, const xtd::ustring& title) { show_progress_box(&owner, title); }
     static void show(const iwin32_window& owner, const xtd::ustring& title, const progress_box_options options) { show_progress_box(&owner, title, ""_t, 0, 0, 100, false, 100, std::vector<xtd::ustring>(), options); }
     static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message) { show_progress_box(&owner, title, message, 0, 0, 100, false, 100, std::vector<xtd::ustring>(), progress_box_options::none); }
     static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const progress_box_options options) { show_progress_box(&owner, title, message, 0, 0, 100, false, 100, std::vector<xtd::ustring>(), options); }
     static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value) { show_progress_box(&owner, title, message, initial_value, 0, 100, false, 100, std::vector<xtd::ustring>(), progress_box_options::none); }
     static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value, const progress_box_options options) { show_progress_box(&owner, title, message, initial_value, 0, 100, false, 100, std::vector<xtd::ustring>(), options); }
     static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value, const int32_t minimum) { show_progress_box(&owner, title, message, initial_value, minimum, 100, false, 100, std::vector<xtd::ustring>(), progress_box_options::none); }
     static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value, const int32_t minimum, const progress_box_options options) { show_progress_box(&owner, title, message, initial_value, minimum, 100, false, 100, std::vector<xtd::ustring>(), options); }
     static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value, const int32_t minimum, const int32_t maximum) { show_progress_box(&owner, title, message, initial_value, minimum, maximum, false, 100, std::vector<xtd::ustring>(), progress_box_options::none); }
     static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value, const int32_t minimum, const int32_t maximum, const progress_box_options options) { show_progress_box(&owner, title, message, initial_value, minimum, maximum, false, 100, std::vector<xtd::ustring>(), options); }
     static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value, const int32_t minimum, const int32_t maximum, const bool marquee, const size_t marquee_animation_speed) { show_progress_box(&owner, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, std::vector<xtd::ustring>(), progress_box_options::none); }
     static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value, const int32_t minimum, const int32_t maximum, const bool marquee, const size_t marquee_animation_speed, const progress_box_options options) { show_progress_box(&owner, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, std::vector<xtd::ustring>(), options); }
     static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value, const int32_t minimum, const int32_t maximum, const bool marquee, const size_t marquee_animation_speed, const std::vector<xtd::ustring>& informations) { show_progress_box(&owner, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, informations, progress_box_options::none); }
     static void show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32_t initial_value, const int32_t minimum, const int32_t maximum, const bool marquee, const size_t marquee_animation_speed, const std::vector<xtd::ustring>& informations, const progress_box_options options) { show_progress_box(&owner, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, informations, options); }

     static void update(const progress_box_options options) { if (dialog_) dialog_->show_cancel_button(options & progress_box_options::show_cancel_button).show_skip_button(options & progress_box_options::show_skip_button).show_elapsed_time(options & progress_box_options::show_elapsed_time).show_estimated_time(options & progress_box_options::show_estimated_time).show_remaining_time(options & progress_box_options::show_remaining_time);; }
     static void update(const int32_t value) { if (dialog_) dialog_->value(value); }
     static void update(const int32_t value, const xtd::ustring& title) { if (dialog_) dialog_->value(value).text(title); }
     static void update(const int32_t value, const xtd::ustring& title, const xtd::ustring& message) { if (dialog_) dialog_->value(value).text(title).message(message); }
     static void update(const int32_t value, const xtd::ustring& title, const xtd::ustring& message, const int32_t minimum) { if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum); }
     static void update(const int32_t value, const xtd::ustring& title, const xtd::ustring& message, const int32_t minimum, const int32_t maximum) { if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum).maximum(maximum); }
     static void update(const int32_t value, const xtd::ustring& title, const xtd::ustring& message, const int32_t minimum, const int32_t maximum, const bool marquee) { if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum).maximum(maximum).marquee(marquee); }
     static void update(const int32_t value, const xtd::ustring& title, const xtd::ustring& message, const int32_t minimum, const int32_t maximum, const bool marquee, const size_t marquee_animation_speed) { if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum).maximum(maximum).marquee(marquee).marquee_animation_speed(marquee_animation_speed); }
     static void update(const int32_t value, const xtd::ustring& title, const xtd::ustring& message, const int32_t minimum, const int32_t maximum, const bool marquee, const size_t marquee_animation_speed, const std::vector<xtd::ustring>& informations) { if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum).maximum(maximum).marquee(marquee).marquee_animation_speed(marquee_animation_speed).informations(informations); }

     static bool cancelled() { return dialog_ && dialog_->cancelled(); }
     static bool skipped() { return dialog_ && dialog_->skipped(); }
     static int32_t minimum() { return dialog_ ? dialog_->minimum() : 0; }
     static int32_t maximum() { return dialog_ ? dialog_->maximum() : 100; }

    private:
      inline static progress_dialog* dialog_;
      static void show_progress_box(const iwin32_window* owner = nullptr, const xtd::ustring& title = "Please wait..."_t, const xtd::ustring& message = ""_t, int32_t initial_value = 0, int32_t minimum = 0, int32_t maximum = 100, const bool marquee = false, size_t marquee_animation_speed = 100, const std::vector<xtd::ustring>& informations = std::vector<xtd::ustring>(), const progress_box_options options = progress_box_options::none) {
        if (dialog_) return;
        dialog_ = new progress_dialog();
        dialog_->text(title)
          .value(initial_value)
          .message(message)
          .maximum(maximum)
          .minimum(minimum)
          .marquee(marquee)
          .marquee_animation_speed(marquee_animation_speed)
          .informations(informations)
          .show_cancel_button(options & progress_box_options::show_cancel_button)
          .show_skip_button(options & progress_box_options::show_skip_button)
          .show_elapsed_time(options & progress_box_options::show_elapsed_time)
          .show_estimated_time(options & progress_box_options::show_estimated_time)
          .show_remaining_time(options & progress_box_options::show_remaining_time);
        owner ? dialog_->show(*owner) : dialog_->show();
      }
    };
  }
}