/// @file
/// @brief Contains xtd::forms::tab_page_ref_less typedef.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "tab_page_ref.h"
#include <xtd/object>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents less comparator for tab_page_ref.
    /// @par Header
    /// @code #include <xtd/forms/tab_page_ref_less> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    struct tab_page_ref_less : public object {
      /// @name Operators
      
      /// @{
      /// @brief Compare two specified tab_page_ref.
      /// @param value1 The first value to compare.
      /// @param value2 The second value to compare.
      /// @return true if value1 < value2; otherwise false.
      bool operator()(const tab_page_ref& value1, const tab_page_ref& value2) const {
        return &value1.get() < &value2.get();
      }
      /// @}
    };
  }
}
