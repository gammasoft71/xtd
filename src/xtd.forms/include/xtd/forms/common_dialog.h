/// @file
/// @brief Contains xtd::forms::common_dialog class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <any>
#include <chrono>
#include <thread>
#include "application.h"
#include "form.h"
#include "component.h"
#include "dialog_closed_event_handler.h"
#include "dialog_result.h"
#include "help_event_handler.h"
#include "iwin32_window.h"

/// @cond
struct __xtd_forms_common_dialog_closed_caller__;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the base class used for displaying dialog boxes on the screen.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks Inherited classes are required to implement run_dialog by invoking show_dialog to create a specific common dialog box. Inherited classes can optionally override hook_proc to implement specific dialog box hook functionality.
    class common_dialog : public component {
    public:
      /// @brief Initializes a new instance of the common_dialog class.
      common_dialog() = default;
      
      /// @brief Get assync dialog_result result after dialog box is closing.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      xtd::forms::dialog_result dialog_result() const {return dialog_result_;}

      /// @brief Gets an object that contains data about the control.
      /// @return The object that contains data about the common_dialog.
      /// @remarks Use this property to store arbitrary information about the control.
      std::any tag() const {return tag_;}
      /// @brief Sets an object that contains data about the control.
      /// @param tag The object that contains data about the common_dialog.
      /// @remarks Use this property to store arbitrary information about the control.
      common_dialog& tag(const std::any& tag) {
        tag_ = tag;
        return*this;
      }
      
      /// @brief When overridden in a derived class, resets the properties of a common dialog box to their default values.
      /// @par Notes to Inheritors
      /// Inheriting classes can override this method to reset their properties.
      virtual void reset() = 0;

      /// @brief Runs a common dialog box with a default owner.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks This method implements run_dialog.
      xtd::forms::dialog_result show_dialog() {
        auto form = form::active_form();
        dialog_result_ = run_dialog(0) ? dialog_result::ok : dialog_result::cancel;
        on_dialog_closed(dialog_closed_event_args(dialog_result_));
        if (form.has_value()) form.value().get().activate();
        return dialog_result_;
      }
      
      /// @brief Runs a common dialog box with the specified owner.
      /// @param owner Any object that implements iwn32_window that represents the top-level window that will own the modal dialog box.
      /// @return ok the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks This version of the show_dialog method allows you to specify a specific form or control that will own the dialog box that is shown. If you use the version of this method that has no parameters, the dialog box being shown would be owned automatically by the currently active window of your application.
      xtd::forms::dialog_result show_dialog(const iwin32_window& owner) {
        auto form = form::active_form();
        dialog_result_ = run_dialog(owner.handle()) ? dialog_result::ok : dialog_result::cancel;
        on_dialog_closed(dialog_closed_event_args(dialog_result_));
        if (form.has_value()) form.value().get().activate();
        return dialog_result_;
      }
      
      /// @brief Runs a common dialog box with the specified owner.
      /// @param owner Any object that implements iwn32_window that represents the top-level window that will own the modal dialog box.
      /// @remarks This version of the show_dialog method allows you to specify a specific form or control that will own the dialog box that is shown. If you use the version of this method that has no parameters, the dialog box being shown would be owned automatically by the currently active window of your application.
      void show_sheet(const iwin32_window& owner) {
        dialog_result_ = xtd::forms::dialog_result::none;
        run_sheet(owner.handle());
      }
      
      /// @brief Runs a common dialog box with the specified owner.
      /// @param owner Any object that implements iwn32_window that represents the top-level window that will own the modal dialog box.
      /// @remarks This version of the show_dialog method allows you to specify a specific form or control that will own the dialog box that is shown. If you use the version of this method that has no parameters, the dialog box being shown would be owned automatically by the currently active window of your application.
      xtd::forms::dialog_result show_sheet_dialog(const iwin32_window& owner) {
        show_sheet(owner);
        while (dialog_result_ == xtd::forms::dialog_result::none) {
          application::do_events();
          std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        return dialog_result_;
      }

      /// @brief Occurs when the user clicks the Help button on a common dialog box.
      /// @ingroup events
      event<common_dialog, help_event_handler> help_request;

      /// @brief Occurs when the user close a common dialog box with dialog close button or other dialog buttons.
      /// @ingroup events
      event<common_dialog, dialog_closed_event_handler> dialog_closed;
      
    protected:
      /// @cond
      friend struct ::__xtd_forms_common_dialog_closed_caller__;
      /// @endcond
      
      /// @brief Raises the common_dialog::dialog_close event.
      /// @param e An common_dialog_close_event_args that provides the event data.
      /// @remarks This method is invoked when the common dialog box is closed.
      virtual void on_dialog_closed(const dialog_closed_event_args& e) {
        dialog_result_ = e.dialog_result();
        dialog_closed(*this, e);
      }

      /// @brief Raises the common_dialog::help_request event.
      /// @param e An help_event_args that provides the event data.
      /// @remarks This method is invoked when the Help button is clicked. Inheriting classes can override this method to handle the event.
      virtual void on_help_request(help_event_args& e) {help_request(*this, e);}
      
      /// @brief When overridden in a derived class, specifies a common dialog box.
      /// @param hwnd_owner A value that represents the window handle of the owner window for the common dialog box.
      /// @return true if the dialog box was successfully run; otherwise, false.
      virtual bool run_dialog(intptr_t hwnd_owner) = 0;
      
      /// @brief When overridden in a derived class, specifies a common dialog box.
      /// @param hwnd_owner A value that represents the window handle of the owner window for the common dialog box.
      /// @return true if the dialog box was successfully run; otherwise, false.
      /// @remarks The result will done in asynch. Check result_dialog property aftter dialog box closed to obtain the result.
      virtual void run_sheet(intptr_t hwnd_owner) = 0;

      /// @cond
      std::any tag_;
      xtd::forms::dialog_result dialog_result_ = xtd::forms::dialog_result::none;
      /// @endcond
    };
  }
}
