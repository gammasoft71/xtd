/// @file
/// @brief Contains xtd::forms::assert_dialog dialog.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "component.hpp"
#include "dialog_result.hpp"
#include "dialog_appearance.hpp"
#include "dialog_closed_event_handler.hpp"
#include "iwin32_window.hpp"
#include <xtd/diagnostics/stack_frame>
#include <xtd/event>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays assert dialog.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/assert_dialog>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                   | macOS                                     | Gnome                                     |
    /// | ----- | ----------------------------------------- | ----------------------------------------- | ----------------------------------------- |
    /// | Light |  @image html dialog_assert_dialog_w.png   |  @image html dialog_assert_dialog_m.png   |  @image html dialog_assert_dialog_g.png   |
    /// | Dark  |  @image html dialog_assert_dialog_wd.png  |  @image html dialog_assert_dialog_md.png  |  @image html dialog_assert_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of assert_dialog dialog.
    /// @include assert_dialog.cpp
    class forms_export_ assert_dialog final : public component {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the assert_dialog class.
      assert_dialog();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets async dialog_result result after dialog box is closing.
      /// @return ok if the user clicks OK in the dialog box; otherwise, cancel.
      [[nodiscard]] auto dialog_result() const noexcept -> xtd::forms::dialog_result;
      
      /// @brief Gets the dialog appearance.
      /// @return One of the xtd::forms::dialog_appearance values. The default value is xtd::forms::dialog_appearance::standard.
      [[nodiscard]] auto dialog_appearance() const noexcept -> xtd::forms::dialog_appearance;
      /// @brief Sets the dialog appearance.
      /// @param dialog_appearance One of the xtd::forms::dialog_appearance values. The default value is xtd::forms::dialog_appearance::standard.
      /// @return Current assert_dialog instance.
      auto dialog_appearance(xtd::forms::dialog_appearance dialog_appearance) -> assert_dialog&;
      
      /// @brief Gets the dialog message text.
      /// @return The current dialog message text.
      [[nodiscard]] auto message() const noexcept -> xtd::string;
      /// @brief Sets the dialog message text.
      /// @param value The new dialog message text.
      /// @return Current input_dialog instance.
      auto message(const xtd::string& value) -> assert_dialog&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Resets all properties to empty string.
      auto reset() noexcept -> void;
      
      /// @brief Runs assert dialog box.
      auto show_dialog(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) -> xtd::forms::dialog_result;
      /// @brief Runs assert dialog box.
      auto show_dialog(const iwin32_window& owner, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) -> xtd::forms::dialog_result;
      
      /// @brief Runs assert dialog box.
      /// @remarks The result will done in async. Check result_dialog property after dialog box closed to obtain the result.
      auto show_sheet(const iwin32_window& owner, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) -> void;
      
      /// @brief Runs assert dialog box.
      auto show_sheet_dialog(const iwin32_window& owner, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) -> xtd::forms::dialog_result;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the user close an assert dialog box with dialog close button or other dialog buttons.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      event<assert_dialog, dialog_closed_event_handler> dialog_closed;
      /// @}
      
      /// @name Public Deprecated Properties
      
      /// @{
      /// @brief Gets stack frame.
      /// @return The stack frame.
      /// @deprecated Will be removed in version 1.2.0.
      [[deprecated("Will be removed in version 1.2.0.")]]
      [[nodiscard]] auto stack_frame() const noexcept -> xtd::diagnostics::stack_frame;
      /// @brief Sets stack frame.
      /// @param value The stack frame.
      /// @return Current assert_dialog instance.
      /// @deprecated Use "Use xtd::forms::assert_dialog::show_dialog ([owner,] stack_frame) or xtd::forms::assert_dialog::show_sheet (owner, stack_frame) - Will be removed in version 1.2.0.
      [[deprecated("Use xtd::forms::assert_dialog::show_dialog ([owner,] stack_frame) or xtd::forms::assert_dialog::show_sheet (owner, stack_frame) - Will be removed in version 1.2.0.")]]
      [[nodiscard]] auto stack_frame(const xtd::diagnostics::stack_frame& value) -> assert_dialog&;
      /// @}
      
    protected:
      /// @name Protected Methods
      
      /// @{
      /// @brief Raises the close event.
      /// @param e An assert_dialog_closed_event_args that provides the event data.
      /// @remarks This method is invoked when the assert dialog box is closed.
      auto on_dialog_closed(const dialog_closed_event_args& e) -> void;
      /// @}
      
    private:
      auto set_message() noexcept -> void;
      xtd::sptr<data> data_;
    };
  }
}
