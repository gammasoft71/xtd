/// @file
/// @brief Contains xtd::forms::exception_dialog dialog.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "component.hpp"
#include "dialog_result.hpp"
#include "dialog_appearance.hpp"
#include "dialog_closed_event_handler.hpp"
#include "iwin32_window.hpp"
#include "layout/arranged_element_collection.hpp"
#include <xtd/version>
#include <xtd/drawing/icon>
#include <xtd/exception>
#include <functional>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays exception dialog.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/exception_dialog>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                      | macOS                                        | Gnome                                        |
    /// | ----- | -------------------------------------------- | -------------------------------------------- | -------------------------------------------- |
    /// | Light |  @image html dialog_exception_dialog_w.png   |  @image html dialog_exception_dialog_m.png   |  @image html dialog_exception_dialog_g.png   |
    /// | Dark  |  @image html dialog_exception_dialog_wd.png  |  @image html dialog_exception_dialog_md.png  |  @image html dialog_exception_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of exception_dialog dialog.
    /// @include exception_dialog.cpp
    class forms_export_ exception_dialog final : public xtd::forms::component {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the exception_dialog class.
      exception_dialog();
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
      /// @return Current exception_dialog instance.
      auto dialog_appearance(xtd::forms::dialog_appearance dialog_appearance) -> exception_dialog&;
      
      /// @brief Gets exception reference.
      /// @return A exception reference.
      [[nodiscard]] auto exception() const noexcept -> xtd::ref<const std::exception>;
      /// @brief Sets exception.
      /// @param exception The exception.
      /// @return Current exception_dialog instance.
      /// @warning Contains only a reference on the parameter exception. Do not delete exception before closing dialog.
      auto exception(const std::exception& exception) -> exception_dialog&;
      
      /// @brief Gets the dialog caption text.
      /// @return The current dialog caption text.
      [[nodiscard]] auto text() const noexcept -> xtd::string;
      /// @brief Sets the dialog caption text.
      /// @param text The new dialog caption text.
      /// @return Current input_dialog instance.
      auto text(const xtd::string& text) -> exception_dialog&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Resets all properties to empty string.
      auto reset() noexcept -> void;
      
      /// @brief Runs exception dialog box.
      auto show_dialog() -> xtd::forms::dialog_result;
      /// @brief Runs exception dialog box.
      auto show_dialog(const xtd::forms::iwin32_window& owner) -> xtd::forms::dialog_result;
      /// @brief Runs exception dialog box.
      /// @remarks The result will done in async. Check result_dialog property after dialog box closed to obtain the result.
      auto show_sheet(const xtd::forms::iwin32_window& owner) -> void;
      /// @brief Runs exception dialog box.
      auto show_sheet_dialog(const xtd::forms::iwin32_window& owner) -> xtd::forms::dialog_result;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the user close an exception dialog box with dialog close button or other dialog buttons.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<exception_dialog, xtd::forms::dialog_closed_event_handler> dialog_closed;
      /// @}
      
    protected:
      /// @name Protected Methods
      
      /// @{
      /// @brief Raises the close event.
      /// @param e An exception_dialog_closed_event_args that provides the event data.
      /// @remarks This method is invoked when the exception dialog box is closed.
      auto on_dialog_closed(const xtd::forms::dialog_closed_event_args& e) -> void;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
