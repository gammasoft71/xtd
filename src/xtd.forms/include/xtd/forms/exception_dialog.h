/// @file
/// @brief Contains xtd::forms::exception_dialog dialog.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <functional>
#include <string>
#include <xtd/version.h>
#include <xtd/drawing/icon.h>
#include <xtd/system_exception.h>
#include "component.h"
#include "dialog_result.h"
#include "dialog_style.h"
#include "dialog_closed_event_handler.h"
#include "iwin32_window.h"
#include "layout/arranged_element_collection.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays exception box.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Examples
    /// The following code example demonstrate the use of exception_dialog dialog.
    /// @include exception_dialog.cpp
    /// @par Windows
    /// @image html exception_dialog_w.png
    /// <br>
    /// @image html exception_dialog_wd.png
    /// @par macOS
    /// @image html exception_dialog_m.png
    /// <br>
    /// @image html exception_dialog_md.png
    /// @par Gnome
    /// @image html exception_dialog_g.png
    /// <br>
    /// @image html exception_dialog_gd.png
    class forms_export_ exception_dialog final : public component {
    public:
      /// @brief Initializes a new instance of the exception_dialog class.
      exception_dialog() = default;
      
      /// @brief Get assync dialog_result result after dialog box is closing.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      xtd::forms::dialog_result dialog_result() const {return dialog_result_;}
      
      /// @brief Gets the dialog style.
      /// @return One of the xtd::forms::dialog_style values. The default value is xtd::forms::dialog_style::standard.
      xtd::forms::dialog_style dialog_style() const {return dialog_style_;}
      /// @brief Sets the dialog style.
      /// @param dialog_style One of the xtd::forms::dialog_style values. The default value is xtd::forms::dialog_style::standard.
      /// @return Current exception_dialog instance.
      exception_dialog& dialog_style(xtd::forms::dialog_style dialog_style) {
        dialog_style_ = dialog_style;
        return *this;
      }
      
      /// @brief Gets exception referecne.
      /// @return A exception referecne.
      std::reference_wrapper<const std::exception> exception() const {return std::reference_wrapper<const std::exception>(*exception_);}
      /// @brief Sets exception.
      /// @param exception The exception.
      /// @return Current exception_dialog instance.
      /// @warning Contains only a reference on the parameter exception. Do not delete exception before closing dialog.
      exception_dialog& exception(const std::exception& exception) {
        exception_ = &exception;
        return *this;
      }

      /// @brief Gets the dialog caption text.
      /// @return The current dialog caption text.
      xtd::ustring text() const {return text_;}
      /// @brief Sets the dialog caption text.
      /// @param text The new dialog caption text.
      /// @return Current input_dialog instance.
      exception_dialog& text(const xtd::ustring& text) {
        if (text_ != text)
          text_ = text;
        return *this;
      }
      
      /// @brief Resets all properties to empty string.
      void reset();
      
      /// @brief Runs exception dialog box.
      xtd::forms::dialog_result show_dialog();
      /// @brief Runs exception dialog box.
      xtd::forms::dialog_result show_dialog(const iwin32_window& owner);
      /// @brief Runs exception dialog box.
      /// @remarks The result will done in asynch. Check result_dialog property aftter dialog box closed to obtain the result.
      void show_sheet(const iwin32_window& owner);
      /// @brief Runs exception dialog box.
      xtd::forms::dialog_result show_sheet_dialog(const iwin32_window& owner);
      
      /// @brief Occurs when the user close an exception dialog box with dialog close button or other dialog buttons.
      /// @ingroup events
      event<exception_dialog, dialog_closed_event_handler> dialog_closed;

    protected:
      /// @brief Raises the close event.
      /// @param e An exception_dialog_closed_event_args that provides the event data.
      /// @remarks This method is invoked when the exception dialog box is closed.
      void on_dialog_closed(const dialog_closed_event_args& e) {
        dialog_result_ = e.dialog_result();
        dialog_closed(*this, e);
      }
      
    private:
      xtd::forms::dialog_result dialog_result_ = xtd::forms::dialog_result::none;
      xtd::forms::dialog_style dialog_style_ = xtd::forms::dialog_style::standard;
      const std::exception* exception_ = nullptr;
      xtd::ustring text_;
    };
  }
}
