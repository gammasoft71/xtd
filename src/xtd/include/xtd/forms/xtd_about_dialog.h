/// @file
/// @brief Contains xtd::forms::xtd_about_dialog dialog.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/forms/layout/arranged_element_collection>
#include <xtd/forms/component.h>
#include <xtd/forms/dialog_appearance>
#include <xtd/forms/iwin32_window>
#include <xtd/drawing/icon>
#include <xtd/delegate>
#include <xtd/ustring>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a dialog box that displays about dialog.
    /// @par Header
    /// @code #include <xtd/forms/xtd_about_dialog> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd
    /// @ingroup xtd_forms dialogs
    /// @par Examples
    /// The following code example demonstrates the use of xtd_about_dialog dialog.
    /// @include xtd_about_dialog.cpp
    class forms_export_ xtd_about_dialog final : public component {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd_about_dialog class.
      xtd_about_dialog();
      /// @}
     
      /// @name Public Methods
      
      /// @{
      /// @brief Runs xtd about dialog box.
      void show();
      /// @brief Runs xtd about dialog box.
      void show(const iwin32_window& owner);
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
