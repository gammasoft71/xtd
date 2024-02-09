/// @file
/// @brief Contains xtd::forms::xtd_about_box dialog.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/static>
#include <xtd/forms/iwin32_window>
#include "../export.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a dialog box that displays about box.
    /// @par Header
    /// @code #include <xtd/forms/xtd_about_box> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd
    /// @ingroup xtd_forms dialogs
    /// @par Examples
    /// The following code example demonstrates the use of xtd_about_box dialog.
    /// @include xtd_about_box.cpp
    class export_ xtd_about_box final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Displays the xtd about box in front of the specified window.
      /// @param owner A iwin32_window that represents the owner window of the xtd about box.
      static void show(const iwin32_window& owner);
      
      /// @brief Displays the xtd about box.
      static void show();
      /// @}      
    };
  }
}
