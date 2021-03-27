/// @file
/// @brief Contains xtd::forms::exception_dialog dialog.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <string>
#include <xtd/delegate.h>
#include <xtd/version.h>
#include <xtd/drawing/icon.h>
#include <xtd/system_exception.h>
#include "component.h"
#include "dialog_result.h"
#include "dialog_style.h"
#include "iwin32_window.h"
#include "layout/arranged_element_collection.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays exception box.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Examples
    /// The following code example demonstrate the use of exception_dialog dialog.
    /// @include exception_dialog.cpp
    class forms_export_ exception_dialog final : public component {
    public:
      using creators_collection = xtd::forms::layout::arranged_element_collection<std::string>;
      using designers_collection = xtd::forms::layout::arranged_element_collection<std::string>;
      using doc_writers_collection = xtd::forms::layout::arranged_element_collection<std::string>;
      using translators_collection = xtd::forms::layout::arranged_element_collection<std::string>;

      /// @brief Initializes a new instance of the exception_dialog class.
      exception_dialog() = default;
      
      xtd::forms::dialog_style dialog_style() const {return dialog_style_;}
      exception_dialog& dialog_style(xtd::forms::dialog_style dialog_style) {
        dialog_style_ = dialog_style;
        return *this;
      }
      
      /// @brief Gets the product license.
      /// @return The product license.
      std::optional<std::exception> exception() const {return exception_ ? std::optional<std::exception>(*exception_) : std::optional<std::exception>();}
      /// @brief Sets the product license.
      /// @param name The product license.
      /// @return Current exception_dialog instance.
      exception_dialog& exception(const std::exception& exception) {
        exception_ = &exception;
        return *this;
      }

      /// @brief Resets all properties to empty string.
      void reset();
      
      /// @brief Runs exception dialog box.
      xtd::forms::dialog_result show_dialog();

    private:
      xtd::forms::dialog_style dialog_style_ = xtd::forms::dialog_style::standard;
      const std::exception* exception_ = nullptr;
    };
  }
}
