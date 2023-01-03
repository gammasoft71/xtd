/// @file
/// @brief Contains xtd::forms::tab_page_ref typedef.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/object.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class tab_page;
    /// @endcond
    
    /// @brief Represents a tab_page reference.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    using tab_page_ref = std::reference_wrapper<tab_page>;
    
    /// @brief Represents a const tab_page reference.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    using const_tab_page_ref = std::reference_wrapper<const tab_page>;
    
    /// @brief Represents less comparator for tab_page_ref.
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
    
    /// @brief Represents less comparator for const const_tab_page_ref.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    struct const_tab_page_ref_less {
      /// @name Operators
      
      /// @{
      /// @brief Compare two specified const_tab_page_ref.
      /// @param value1 The first value to compare.
      /// @param value2 The second value to compare.
      /// @return true if value1 < value2; otherwise false.
      bool operator()(const const_tab_page_ref& value1, const const_tab_page_ref& value2) const {
        return &value1.get() < &value2.get();
      }
      /// @}
    };
  }
}
