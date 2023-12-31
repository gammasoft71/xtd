/// @file
/// @brief Contains xtd::forms::progress_box_options control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies options on a xtd::forms::progress_box.
    /// @par Header
    /// @code #include <xtd/forms/progress_box_options> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the xtd::forms::progress_box class.
    enum class progress_box_options {
      /// @brief No options.
      none = 0b0,
      /// @brief Whether cancel button is shown.
      show_cancel_button = 0b1,
      /// @brief Whether skip button is shown.
      show_skip_button = 0b10,
      /// @brief Whether elapsed time is shown.
      show_elapsed_time = 0b100,
      /// @brief Whether estimated time is shown.
      show_estimated_time = 0b1000,
      /// @brief Whether remaining time is shown.
      show_remaining_time = 0b10000,
      /// @brief All flags except none.
      all = show_cancel_button | show_skip_button | show_elapsed_time | show_estimated_time | show_remaining_time
    };
  }
}

/// @cond
flags_attribute_(xtd::forms, progress_box_options);

template<> struct xtd::enum_register<xtd::forms::progress_box_options> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::progress_box_options> {{xtd::forms::progress_box_options::none, "none"}, {xtd::forms::progress_box_options::show_cancel_button, "show_cancel_button"}, {xtd::forms::progress_box_options::show_skip_button, "show_skip_button"}, {xtd::forms::progress_box_options::show_elapsed_time, "show_elapsed_time"}, {xtd::forms::progress_box_options::show_estimated_time, "show_estimated_time"}, {xtd::forms::progress_box_options::show_remaining_time, "show_remaining_time"}, {xtd::forms::progress_box_options::all, "all"}};}
};
/// @endcond
