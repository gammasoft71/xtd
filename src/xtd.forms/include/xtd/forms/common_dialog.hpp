/// @file
/// @brief Contains xtd::forms::common_dialog class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "application.hpp"
#include "form.hpp"
#include "component.hpp"
#include "dialog_closed_event_handler.hpp"
#include "dialog_result.hpp"
#include "help_event_handler.hpp"
#include "iwin32_window.hpp"
#include <xtd/any>
#include <xtd/chrono>

/// @cond
struct __xtd_forms_common_dialog_closed_caller__;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the base class used for displaying dialog boxes on the screen.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/common_dialog>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks Inherited classes are required to implement run_dialog by invoking show_dialog to create a specific common dialog box. Inherited classes can optionally override hook_proc to implement specific dialog box hook functionality.
    class common_dialog : public xtd::forms::component {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the common_dialog class.
      common_dialog();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets async dialog_result result after dialog box is closing.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      [[nodiscard]] auto dialog_result() const noexcept -> xtd::forms::dialog_result;
      
      /// @brief Gets an object that contains data about the control.
      /// @return The object that contains data about the common_dialog.
      /// @remarks Use this property to store arbitrary information about the control.
      [[nodiscard]] auto tag() const noexcept -> const xtd::any_object&;
      /// @brief Sets an object that contains data about the control.
      /// @param value The object that contains data about the common_dialog.
      /// @remarks Use this property to store arbitrary information about the control.
      auto tag(const xtd::any_object& value) -> common_dialog&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief When overridden in a derived class, resets the properties of a common dialog box to their default values.
      /// @par Notes to Inheritors
      /// Inheriting classes can override this method to reset their properties.
      virtual auto reset() noexcept -> void = 0;
      
      /// @brief Runs a common dialog box with a default owner.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks This method implements run_dialog.
      [[nodiscard]] auto show_dialog() -> xtd::forms::dialog_result;
      
      /// @brief Runs a common dialog box with the specified owner.
      /// @param owner Any object that implements iwn32_window that represents the top-level window that will own the modal dialog box.
      /// @return ok the user clicks OK in the dialog box; otherwise, cancel.
      /// @remarks This version of the show_dialog method allows you to specify a specific form or control that will own the dialog box that is shown. If you use the version of this method that has no parameters, the dialog box being shown would be owned automatically by the currently active window of your application.
      [[nodiscard]] auto show_dialog(const iwin32_window& owner) -> xtd::forms::dialog_result;
      
      /// @brief Runs a common dialog box with the specified owner.
      /// @param owner Any object that implements iwn32_window that represents the top-level window that will own the modal dialog box.
      /// @remarks This version of the show_dialog method allows you to specify a specific form or control that will own the dialog box that is shown. If you use the version of this method that has no parameters, the dialog box being shown would be owned automatically by the currently active window of your application.
      auto show_sheet(const iwin32_window& owner) -> void;
      
      /// @brief Runs a common dialog box with the specified owner.
      /// @param owner Any object that implements iwn32_window that represents the top-level window that will own the modal dialog box.
      /// @remarks This version of the show_dialog method allows you to specify a specific form or control that will own the dialog box that is shown. If you use the version of this method that has no parameters, the dialog box being shown would be owned automatically by the currently active window of your application.
      [[nodiscard]] auto show_sheet_dialog(const iwin32_window& owner) -> xtd::forms::dialog_result;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the user clicks the Help button on a common dialog box.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<common_dialog, xtd::forms::help_event_handler> help_request;
      
      /// @brief Occurs when the user close a common dialog box with dialog close button or other dialog buttons.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<common_dialog, xtd::forms::dialog_closed_event_handler> dialog_closed;
      /// @}
      
    protected:
      friend struct ::__xtd_forms_common_dialog_closed_caller__;
      
      /// @name Peotected methods
      
      /// @{
      /// @brief Raises the common_dialog::dialog_close event.
      /// @param e An common_dialog_close_event_args that provides the event data.
      /// @remarks This method is invoked when the common dialog box is closed.
      virtual auto on_dialog_closed(const xtd::forms::dialog_closed_event_args& e) -> void;
      
      /// @brief Raises the common_dialog::help_request event.
      /// @param e An xtd::forms::help_event_args that provides the event data.
      /// @remarks This method is invoked when the Help button is clicked. Inheriting classes can override this method to handle the event.
      virtual auto on_help_request(xtd::forms::help_event_args& e) -> void;
      
      /// @brief When overridden in a derived class, specifies a common dialog box.
      /// @param hwnd_owner A value that represents the window handle of the owner window for the common dialog box.
      /// @return `true` if the dialog box was successfully run; otherwise, `false`.
      [[nodiscard]] virtual auto run_dialog(xtd::intptr hwnd_owner) -> bool = 0;
      
      /// @brief When overridden in a derived class, specifies a common dialog box.
      /// @param hwnd_owner A value that represents the window handle of the owner window for the common dialog box.
      /// @return `true` if the dialog box was successfully run; otherwise, `false`.
      /// @remarks The result will done in async. Check result_dialog property after dialog box closed to obtain the result.
      virtual auto run_sheet(xtd::intptr hwnd_owner) -> void = 0;
      
      /// @brief Sets async dialog_result result after dialog box is closing.
      /// @param value ok if the user clicks OK in the dialog box; otherwise, cancel.
      auto set_dialog_result(xtd::forms::dialog_result value) -> void;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
