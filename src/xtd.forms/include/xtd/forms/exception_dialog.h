/// @file
/// @brief Contains xtd::forms::exception_dialog dialog.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
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
    /// @brief Represents a common dialog box that displays exception dialog.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
    ///   <tr>
    ///     <th style="width:100px"></th>
    ///     <th><b>Windows</b></th>
    ///     <th><b>macOS</b></th>
    ///     <th><b>Gnome</b></th>
    ///   </tr>
    ///   <tr>
    ///     <th>Light</th>
    ///     <td>@image html dialog_exception_dialog_w.png</td>
    ///     <td>@image html dialog_exception_dialog_m.png</td>
    ///     <td>@image html dialog_exception_dialog_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html dialog_exception_dialog_wd.png</td>
    ///     <td>@image html dialog_exception_dialog_md.png</td>
    ///     <td>@image html dialog_exception_dialog_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of exception_dialog dialog.
    /// @include exception_dialog.cpp
    class forms_export_ exception_dialog final : public component {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the exception_dialog class.
      exception_dialog();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets async dialog_result result after dialog box is closing.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      xtd::forms::dialog_result dialog_result() const noexcept;
      
      /// @brief Gets the dialog style.
      /// @return One of the xtd::forms::dialog_style values. The default value is xtd::forms::dialog_style::standard.
      xtd::forms::dialog_style dialog_style() const noexcept;
      /// @brief Sets the dialog style.
      /// @param dialog_style One of the xtd::forms::dialog_style values. The default value is xtd::forms::dialog_style::standard.
      /// @return Current exception_dialog instance.
      exception_dialog& dialog_style(xtd::forms::dialog_style dialog_style);
      
      /// @brief Gets exception reference.
      /// @return A exception reference.
      std::reference_wrapper<const std::exception> exception() const noexcept;
      /// @brief Sets exception.
      /// @param exception The exception.
      /// @return Current exception_dialog instance.
      /// @warning Contains only a reference on the parameter exception. Do not delete exception before closing dialog.
      exception_dialog& exception(const std::exception& exception);
      
      /// @brief Gets the dialog caption text.
      /// @return The current dialog caption text.
      xtd::ustring text() const noexcept;
      /// @brief Sets the dialog caption text.
      /// @param text The new dialog caption text.
      /// @return Current input_dialog instance.
      exception_dialog& text(const xtd::ustring& text);
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Resets all properties to empty string.
      void reset() noexcept;
      
      /// @brief Runs exception dialog box.
      xtd::forms::dialog_result show_dialog();
      /// @brief Runs exception dialog box.
      xtd::forms::dialog_result show_dialog(const iwin32_window& owner);
      /// @brief Runs exception dialog box.
      /// @remarks The result will done in async. Check result_dialog property after dialog box closed to obtain the result.
      void show_sheet(const iwin32_window& owner);
      /// @brief Runs exception dialog box.
      xtd::forms::dialog_result show_sheet_dialog(const iwin32_window& owner);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the user close an exception dialog box with dialog close button or other dialog buttons.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<exception_dialog, dialog_closed_event_handler> dialog_closed;
      /// @}
      
    protected:
      /// @name Protected methods
      
      /// @{
      /// @brief Raises the close event.
      /// @param e An exception_dialog_closed_event_args that provides the event data.
      /// @remarks This method is invoked when the exception dialog box is closed.
      void on_dialog_closed(const dialog_closed_event_args& e);
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
