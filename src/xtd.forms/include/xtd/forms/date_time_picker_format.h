/// @file
/// @brief Contains xtd::forms::date_time_picker_format enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the date and time format the date_time_picker control displays.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by members such as date_time_picker::format.
    enum class date_time_picker_format {
      /// @brief The date_time_picker control displays the date/time value in the long date format set by the user's operating system.
      long_format = 1,
      /// @brief The date_time_picker control displays the date/time value in the short date format set by the user's operating system.
      short_format = 2,
      /// @brief The date_time_picker control displays the date/time value in the time format set by the user's operating system.
      time = 4,
      /// @brief The date_time_picker control displays the date/time value in a custom format.
      custom = 8,
    };

  /// @cond
    inline std::ostream& operator<<(std::ostream& os, date_time_picker_format value) {return os << to_string(value, {{date_time_picker_format::long_format, "long_format"}, {date_time_picker_format::short_format, "short_format"}, {date_time_picker_format::time, "time"}, {date_time_picker_format::custom, "custom"}});}
    inline std::wostream& operator<<(std::wostream& os, date_time_picker_format value) {return os << to_string(value, {{date_time_picker_format::long_format, L"long_format"}, {date_time_picker_format::short_format, L"short_format"}, {date_time_picker_format::time, L"time"}, {date_time_picker_format::custom, L"custom"}});}
    /// @endcond
  }
}
