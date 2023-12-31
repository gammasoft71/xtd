/// @file
/// @brief Contains xtd::forms::menu_item_ref alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class menu_item;
    /// @endcond
    
    /// @brief Represents a menu item reference.
    /// @par Header
    /// @code #include <xtd/forms/menu_item_ref> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    using menu_item_ref = std::reference_wrapper<menu_item>;
  }
}
