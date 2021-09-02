/// @file
/// @brief Contains xtd::forms::progress_bar_style enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the progress_bar_style of controls or elements of controls.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks You can use the marquee style when you need to indicate progress is being made, but you cannot indicate the quantity of progress. The marquee style is valid only when visual styles are enabled. The Continuous style is valid only when visual styles are not enabled.
    enum class progress_bar_style {
      /// @brief Indicates progress by increasing the number of segmented blocks in a progress_bar.
      blocks = 0,
      /// @brief Indicates progress by increasing the size of a smooth, continuous bar in a progress_bar.
      continuous = 1,
      /// @brief Indicates progress by continuously scrolling a block across a progress_bar in a marquee fashion.
      marquee = 2,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, progress_bar_style value) {return os << to_string(value, {{progress_bar_style::blocks, "blocks"}, {progress_bar_style::continuous, "continuous"}, {progress_bar_style::marquee, "marquee"}});}
    inline std::wostream& operator<<(std::wostream& os, progress_bar_style value) {return os << to_string(value, {{progress_bar_style::blocks, L"blocks"}, {progress_bar_style::continuous, L"continuous"}, {progress_bar_style::marquee, L"marquee"}});}
    /// @endcond
  }
}
