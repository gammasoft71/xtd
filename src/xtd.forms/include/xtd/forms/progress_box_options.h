/// @file
/// @brief Contains xtd::forms::progress_box_options control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies options on a xtd::forms::progress_box.
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

    /// @cond
    inline progress_box_options& operator +=(progress_box_options& lhs, progress_box_options rhs) noexcept { lhs = static_cast<progress_box_options>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs; }
    inline progress_box_options& operator -=(progress_box_options& lhs, progress_box_options rhs) noexcept { lhs = static_cast<progress_box_options>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs; }
    inline progress_box_options& operator &=(progress_box_options& lhs, progress_box_options rhs) noexcept { lhs = static_cast<progress_box_options>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs; }
    inline progress_box_options& operator |=(progress_box_options& lhs, progress_box_options rhs) noexcept { lhs = static_cast<progress_box_options>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs; }
    inline progress_box_options& operator ^=(progress_box_options& lhs, progress_box_options rhs) noexcept { lhs = static_cast<progress_box_options>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs; }
    inline progress_box_options operator +(progress_box_options lhs, progress_box_options rhs) noexcept { return static_cast<progress_box_options>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); }
    inline progress_box_options operator -(progress_box_options lhs, progress_box_options rhs) noexcept { return static_cast<progress_box_options>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); }
    inline progress_box_options operator ~(progress_box_options rhs) noexcept { return static_cast<progress_box_options>(~static_cast<long long>(rhs)); }
    inline bool operator &(progress_box_options lhs, progress_box_options rhs) noexcept { return static_cast<bool>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); }
    inline progress_box_options operator |(progress_box_options lhs, progress_box_options rhs) noexcept { return static_cast<progress_box_options>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); }
    inline progress_box_options operator ^(progress_box_options lhs, progress_box_options rhs) noexcept { return static_cast<progress_box_options>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); }

    inline std::ostream& operator<<(std::ostream& os, progress_box_options value) { return os << to_string(value, { {progress_box_options::none, "none"}, {progress_box_options::show_cancel_button, "show_cancel_button"}, {progress_box_options::show_skip_button, "show_skip_button"}, {progress_box_options::show_elapsed_time, "show_elapsed_time"}, {progress_box_options::show_estimated_time, "show_estimated_time"}, {progress_box_options::show_remaining_time, "show_remaining_time"}, {progress_box_options::all, "all"} }); }
    inline std::wostream& operator<<(std::wostream& os, progress_box_options value) { return os << to_string(value, { {progress_box_options::none, L"none"}, {progress_box_options::show_cancel_button, L"show_cancel_button"}, {progress_box_options::show_skip_button, L"show_skip_button"}, {progress_box_options::show_elapsed_time, L"show_elapsed_time"}, {progress_box_options::show_estimated_time, L"show_estimated_time"}, {progress_box_options::show_remaining_time, L"show_remaining_time"}, {progress_box_options::all, L"all"} }); }
    /// @endcond
  }
}