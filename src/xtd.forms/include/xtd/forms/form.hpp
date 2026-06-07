/// @file
/// @brief Contains xtd::forms::form container.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "const_form_ref.hpp"
#include "form_border_style.hpp"
#include "form_closed_event_handler.hpp"
#include "form_closing_event_handler.hpp"
#include "form_ref.hpp"
#include "form_start_position.hpp"
#include "form_window_state.hpp"
#include "container_control.hpp"
#include "dialog_result.hpp"
#include "ibutton_control.hpp"
#include "main_menu.hpp"
#include "screen.hpp"
#include "status_bar.hpp"
#include "tool_bar.hpp"
#include <xtd/drawing/icon>
#include <xtd/io/path>
#include <cstddef>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class application;
    class application_context;
    class form;
    /// @endcond
    
    /// @brief Represents a window or dialog box that makes up an application's user interface.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/form>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms forms
    /// @remarks A form is a representation of any window displayed in your application. The Form class can be used to create standard, tool, borderless, and floating windows. You can also use the form class to create modal windows such as a dialog box. A special kind of form, the multiple-document interface (MDI) form, can contain other forms called MDI child forms. An MDI form is created by setting the is_mdi_container property to `true`. MDI child forms are created by setting the mdi_parent property to the MDI parent form that will contain the child form.
    /// @remarks Using the properties available in the form class, you can determine the appearance, size, color, and window management features of the window or dialog box you are creating. The text property allows you to specify the caption of the window in the title bar. The size and desktop_location properties allow you to define the size and position of the window when it is displayed. You can use the fore_color color property to change the default foreground color of all controls placed on the form. The form_border_style, minimize_box, and maximize_box properties allow you to control whether the form can be minimized, maximized, or resized at run time.
    /// @remarks In addition to properties, you can use the methods of the class to manipulate a form. For example, you can use the show_dialog method to show a form as a modal dialog box. You can use the set_desktop_location method to position the form on the desktop.
    /// @par Appearance
    /// |       | Windows                        | macOS                          | Gnome                          |
    /// | ----- | ------------------------------ | ------------------------------ | ------------------------------ |
    /// | Light |  @image html form_form_w.png   |  @image html form_form_m.png   |  @image html form_form_g.png   |
    /// | Dark  |  @image html form_form_wd.png  |  @image html form_form_md.png  |  @image html form_form_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of form control.
    /// @include form.cpp
    class forms_export_ form : public xtd::forms::container_control {
      struct data;
      
    public:
      /// @name Public Aliases
      
      /// @{
      /// @brief Represent an xtd::forms::ibutton_control reference.
      using ibutton_control_ref = xtd::ref<xtd::forms::ibutton_control>;
      
      /// @brief Represent an xtd::forms::main_menu reference.
      using main_menu_ref = xtd::ref<xtd::forms::main_menu>;
      
      /// @brief Represent an xtd::forms::status_bar reference.
      using status_bar_ref = xtd::ref<xtd::forms::status_bar>;
      
      /// @brief Represent an xtd::forms::tool_bar reference.
      using tool_bar_ref = xtd::ref<xtd::forms::tool_bar>;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the Form class.
      /// @remarks The default size of a form is 300 pixels in height and 300 pixels in width.
      form();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the button on the form that is clicked when the user presses the ENTER key.
      /// @return An ibutton_control that represents the button to use as the accept button for the form.
      [[nodiscard]] auto accept_button() const noexcept -> std::optional<ibutton_control_ref>;
      /// @brief Sets the button on the form that is clicked when the user presses the ENTER key.
      /// @param value An ibutton_control that represents the button to use as the accept button for the form.
      /// @return Current form.
      auto accept_button(const xtd::forms::ibutton_control& value) -> form&;
      /// @brief Sets the button on the form that is clicked when the user presses the ENTER key.
      /// @param value An ibutton_control that represents the button to use as the accept button for the form.
      /// @return Current form.
      auto accept_button(xtd::null_ptr) -> form&;
      
      /// @brief Gets the mode by which the form automatically resizes itself.
      /// @return An auto_size_mode enumerated value. The default is grow_only.
      [[nodiscard]] virtual auto auto_size_mode() const noexcept -> xtd::forms::auto_size_mode;
      /// @brief Sets the mode by which the form automatically resizes itself.
      /// @param value An auto_size_mode enumerated value. The default is grow_only.
      /// @return Current form.
      virtual auto auto_size_mode(xtd::forms::auto_size_mode value) -> form&;
      
      /// @brief Gets the button control that is clicked when the user presses the ESC key.
      /// @return An ibutton_control that represents the cancel button for the form.
      [[nodiscard]] auto cancel_button() const noexcept -> std::optional<ibutton_control_ref>;
      /// @brief Gets the button control that is clicked when the user presses the ESC key.
      /// @param value  An ibutton_control that represents the cancel button for the form.
      /// @return Current form.
      auto cancel_button(const xtd::forms::ibutton_control& value) -> form&;
      /// @brief Gets the button control that is clicked when the user presses the ESC key.
      /// @param value  An ibutton_control that represents the cancel button for the form.
      /// @return Current form.
      auto cancel_button(xtd::null_ptr) -> form&;
      
      /// @brief Gets a value indicating whether a close box is displayed in the caption bar of the form.
      /// @return `true` if the form displays a close box in the upper-left corner of the form; otherwise, `false`. The default is `true`.
      [[nodiscard]] virtual auto close_box() const noexcept -> bool;
      /// @brief Sets a value indicating whether a close box is displayed in the caption bar of the form.
      /// @param value `true` if the form displays a close box in the upper-left corner of the form; otherwise, `false`. The default is `true`.
      /// @return Current form.
      virtual auto close_box(bool value) -> form&;
      
      /// @brief Gets a value indicating whether a control box is displayed in the caption bar of the form.
      /// @return `true` if the form displays a control box in the upper-right corner of the form; otherwise, `false`. The default is `true`.
      [[nodiscard]] virtual auto control_box() const noexcept -> bool;
      /// @brief Sets a value indicating whether a control box is displayed in the caption bar of the form.
      /// @param value `true` if the form displays a control box in the upper-right corner of the form; otherwise, `false`. The default is `true`.
      /// @return Current form.
      virtual auto control_box(bool value) -> form&;
      
      /// @brief Gets the dialog result for the form.
      /// @return A dialog_result that represents the result of the form when used as a dialog box.
      [[nodiscard]] virtual auto dialog_result() const noexcept -> xtd::forms::dialog_result;
      /// @brief Sets the dialog result for the form.
      /// @param value A dialog_result that represents the result of the form when used as a dialog box.
      /// @return Current form.
      virtual auto dialog_result(xtd::forms::dialog_result value) -> form&;
      
      using xtd::forms::container_control::font;
      /// @brief Resets the font of the text displayed by the control.
      /// @param xtd::null.
      /// @return Current control.
      auto font(xtd::null_ptr) -> control& override;
      
      /// @brief Gets the border style of the form.
      /// @return A form_border_style that represents the style of border to display for the form. The default is form_border_style::sizable.
      [[nodiscard]] virtual auto form_border_style() const noexcept -> xtd::forms::form_border_style;
      /// @brief Gets the border style of the form.
      /// @param value A form_border_style that represents the style of border to display for the form. The default is form_border_style::sizable.
      /// @return Current form.
      virtual auto form_border_style(xtd::forms::form_border_style value) -> form&;
      
      /// @brief Gets a value indicating whether a Help button should be displayed in the caption box of the form.
      /// @return `true` to display a Help button in the form's caption bar; otherwise, `false`. The default is `false`.
      [[nodiscard]] virtual auto help_button() const -> bool;
      /// @brief Sets a value indicating whether a Help button should be displayed in the caption box of the form.
      /// @param value `true` to display a Help button in the form's caption bar; otherwise, `false`. The default is `false`.
      /// @return Current form.
      virtual auto help_button(bool value) -> form&;
      
      /// @brief Gets the icon for the form.
      /// @return An icon that represents the icon for the form.
      [[nodiscard]] virtual auto icon() const noexcept -> const xtd::drawing::icon&;
      /// @brief Sets the icon for the form.
      /// @param value An icon that represents the icon for the form.
      /// @return Current form.
      virtual auto icon(const xtd::drawing::icon& value) -> form&;
      
      /// @brief Gets a value indicating whether the Maximize button is displayed in the caption bar of the form.
      /// @return `true` to display a Maximize button for the form; otherwise, `false`. The default is `true`.
      [[nodiscard]] virtual auto maximize_box() const noexcept -> bool;
      /// @brief Sets a value indicating whether the Maximize button is displayed in the caption bar of the form.
      /// @param value `true` to display a Maximize button for the form; otherwise, `false`. The default is `true`.
      /// @return Current form.
      virtual auto maximize_box(bool value) -> form&;
      
      /// @brief Gets the main_menu that is displayed in the form.
      /// @return A main_menu that represents the menu to display in the form.
      [[nodiscard]] virtual auto menu() const noexcept -> std::optional<main_menu_ref>;
      /// @brief Sets the main_menu that is displayed in the form.
      /// @param value A main_menu that represents the menu to display in the form.
      /// @return Current form.
      virtual auto menu(const xtd::forms::main_menu& value) -> form&;
      /// @brief Sets the main_menu that is displayed in the form.
      /// @param value A main_menu that represents the menu to display in the form.
      /// @return Current form.
      virtual auto menu(xtd::null_ptr) -> form&;
      
      /// @brief Gets a value indicating whether the Minimize button is displayed in the caption bar of the form.
      /// @return `true` to display a Minimize button for the form; otherwise, `false`. The default is `true`.
      [[nodiscard]] virtual auto minimize_box() const noexcept -> bool;
      /// @brief Sets a value indicating whether the Minimize button is displayed in the caption bar of the form.
      /// @param value `true` to display a Minimize button for the form; otherwise, `false`. The default is `true`.
      /// @return Current form.
      virtual auto minimize_box(bool value) -> form&;
      
      /// @brief Gets a value indicating whether this form is displayed modally.
      /// @return `true` if the form is displayed modally; otherwise, `false`.
      [[nodiscard]] auto modal() const noexcept -> bool;
      
      /// @brief Gets form opacity.
      /// @return A double-precision value between 0.0 and 1.0 that represent the form opacity.
      [[nodiscard]] virtual auto opacity() const noexcept -> double;
      /// @brief Sets form opacity.
      /// @param opacity A double-precision value between 0.0 and 1.0 that represent the form opacity.
      virtual auto opacity(double opacity) -> form&;
      
      /// @brief Gets the form that owns this form.
      /// @return A form that represents the form that is the owner of this form.
      [[nodiscard]] virtual auto owner() const noexcept -> std::optional<xtd::forms::control_ref>;
      /// @brief Sets the form that owns this form.
      /// @param value A form that represents the form that is the owner of this form.
      /// @return Current form.
      virtual auto owner(const xtd::forms::control& value) -> form&;
      /// @brief Resets the form that owns this form.
      /// @param nullptr
      /// @return Current form.
      virtual auto owner(xtd::null_ptr) -> form&;
      
      using xtd::forms::container_control::parent;
      /// @brief Sets the parent container of the control.
      /// @param parent A control that represents the parent or container control of the control  or nullptr for none.
      auto parent(const xtd::forms::control& value) -> xtd::forms::control& override;
      
      /// @brief Gets a value indicating whether an icon is displayed in the caption bar of the form.
      /// @return `true` if the form displays an icon in the caption bar; otherwise, `false`. The default is `true`.
      [[nodiscard]] virtual auto show_icon() const noexcept -> bool;
      /// @brief Sets a value indicating whether an icon is displayed in the caption bar of the form.
      /// @param value `true` if the form displays an icon in the caption bar; otherwise, `false`. The default is `true`.
      /// @return Current form.
      virtual auto show_icon(bool value) -> form&;
      
      /// @brief Gets a value indicating whether the form is displayed in the Windows taskbar.
      /// @return `true` to display the form in the Windows taskbar at run time; otherwise, `false`. The default is `true`.
      /// @remarks If a form is parented within another form, the parented form is not displayed in the Windows taskbar.
      /// @remarks You can use this property to prevent users from selecting your form through the Windows taskbar. For example, if you display a Find and Replace tool window in your application, you might want to prevent that window from being selected through the Windows taskbar because you would need both the application's main window and the Find and Replace tool window displayed in order to process searches appropriately.
      /// @remarks You will often wish to use this property when creating a form with the xtd::forms::form_border_style::fixed_tool_window style. Setting the xtd::forms::form_border_style::fixed_tool_window style does not alone guarantee that a window will not appear in the taskbar.
      [[nodiscard]] virtual auto show_in_taskbar() const noexcept -> bool;
      /// @brief Sets a value indicating whether the form is displayed in the Windows taskbar.
      /// @param value `true` to display the form in the Windows taskbar at run time; otherwise, `false`. The default is `true`.
      /// @return Current form.
      /// @remarks If a form is parented within another form, the parented form is not displayed in the Windows taskbar.
      /// @remarks You can use this property to prevent users from selecting your form through the Windows taskbar. For example, if you display a Find and Replace tool window in your application, you might want to prevent that window from being selected through the Windows taskbar because you would need both the application's main window and the Find and Replace tool window displayed in order to process searches appropriately.
      /// @remarks You will often wish to use this property when creating a form with the xtd::forms::form_border_style::fixed_tool_window style. Setting the xtd::forms::form_border_style::fixed_tool_window style does not alone guarantee that a window will not appear in the taskbar.
      virtual auto show_in_taskbar(bool value) -> form&;
      
      /// @brief Gets the starting position of the form at run time.
      /// @return A form_start_position that represents the starting position of the form.
      [[nodiscard]] virtual auto start_position() const noexcept -> xtd::forms::form_start_position;
      /// @brief Sets the starting position of the form at run time.
      /// @param value A form_start_position that represents the starting position of the form.
      /// @return Current form.
      virtual auto start_position(xtd::forms::form_start_position value) -> form&;
      
      /// @brief Gets the status_bar that is displayed in the form.
      /// @return A status_bar that represents the status bar to display in the form.
      [[nodiscard]] virtual auto status_bar() const noexcept -> std::optional<status_bar_ref>;
      /// @brief Sets the status_bar that is displayed in the form.
      /// @param value A status_bar that represents the status bar to display in the form.
      /// @return Current form.
      virtual auto status_bar(const xtd::forms::status_bar& value) -> form&;
      /// @brief Resets the status_bar that is displayed in the form.
      /// @param value A status_bar that represents the status bar to display in the form.
      /// @return Current form.
      virtual auto status_bar(xtd::null_ptr) -> form&;
      
      /// @brief Gets the tool_bar that is displayed in the form.
      /// @return A tool_bar that represents the tool bar to display in the form.
      [[nodiscard]] virtual auto tool_bar() const noexcept -> std::optional<tool_bar_ref>;
      /// @brief Sets the tool_bar that is displayed in the form.
      /// @param value A tool_bar that represents the tool bar to display in the form.
      /// @return Current form.
      virtual auto tool_bar(const xtd::forms::tool_bar& value) -> form&;
      /// @brief Resets the tool_bar that is displayed in the form.
      /// @param value A tool_bar that represents the tool bar to display in the form.
      /// @return Current form.
      virtual auto tool_bar(xtd::null_ptr) -> form&;
      
      /// @brief Gets a value indicating whether to display the form as a top-level window.
      /// @return `true` to display the form as a top-level window; otherwise, `false`. The default is `true`.
      /// @remarks A Multiple-document interface (MDI) parent form must be a top-level window. So set to `false` has no effect.
      /// @remarks A top-level form is a window that has no parent form, or whose parent form is the desktop window. Top-level windows are typically used as the main form in an application.
      [[nodiscard]] virtual auto top_level() const noexcept -> bool;
      /// @brief Sets a value indicating whether to display the form as a top-level window.
      /// @return `true` to display the form as a top-level window; otherwise, `false`. The default is `true`.
      /// @remarks A Multiple-document interface (MDI) parent form must be a top-level window. So set to `false` has no effect.
      /// @remarks A top-level form is a window that has no parent form, or whose parent form is the desktop window. Top-level windows are typically used as the main form in an application.
      virtual auto top_level(bool top_level) -> form&;
      
      /// @brief Gets a value indicating whether the form should be displayed as a topmost form.
      /// @return `true` to display the form as a topmost form; otherwise, `false`. The default is `false`.
      [[nodiscard]] virtual auto top_most() const noexcept -> bool;
      /// @brief Sets a value indicating whether the form should be displayed as a topmost form.
      /// @param value `true` to display the form as a topmost form; otherwise, `false`. The default is `false`.
      /// @return Current form.
      virtual auto top_most(bool value) -> form&;
      
      using xtd::forms::container_control::visible;
      /// @brief Sets a value indicating whether the control and all its child controls are displayed.
      /// @param visible `true` if the control and all its child controls are displayed; otherwise, `false`. The default is `true`.
      /// @return Current control.
      auto visible(bool visible) -> xtd::forms::control& override;
      
      /// @brief Gets a value that indicates whether form is minimized, maximized, or normal.
      /// @return A form_window_state that represents whether form is minimized, maximized, full_screen, or normal. The default is form_window_state::normal.
      [[nodiscard]] virtual auto window_state() const noexcept -> xtd::forms::form_window_state;
      /// @brief Sets a value that indicates whether form is minimized, maximized, or normal.
      /// @param value A form_window_state that represents whether form is minimized, maximized, full_screen, or normal. The default is form_window_state::normal.
      /// @return Current form.
      virtual auto window_state(xtd::forms::form_window_state value) -> form&;
      /// @}
      
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets the currently active form for this application.
      /// @return A form that represents the currently active form, or std::optional with no value if there is no active form.
      [[nodiscard]] static auto active_form() noexcept -> std::optional<xtd::forms::form_ref>;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Activates the form and gives it focus.
      /// @remarks Activating a form brings it to the front if this is the active application, or it flashes the window caption if this is not the active application. The form must be visible for this method to have any effect. To determine the active form in an application, use the active_form property or the active_mdi_child property if your forms are in a Multiple-document interface (MDI) application.
      auto activate() -> void;
      
      auto bring_to_front() -> void override;
      
      /// @brief Centers the position of the form within the bounds of the parent form.
      /// @remarks Do not call the center_to_screen method directly from your code. Instead, set the start_position property to center_parent.
      /// @remarks If the form or dialog is top-level, then center_to_parent centers the form with respect to the screen or desktop.
      auto center_to_screen() -> void;
      
      /// @brief Closes the form.
      /// @remarks When a form is closed, all resources created within the object are closed and the form is disposed. You can prevent the closing of a form at run time by handling the closing event and setting the cancel property of the cancel_event_args passed as a parameter to your event handler. If the form you are closing is the startup form of your application, your application ends.
      auto close() -> void;
      
      auto pre_process_message(const xtd::forms::message& message) -> bool override;
      
      /// @brief Shows the form as a modal dialog box.
      /// @return One of the dialog_result values.
      virtual auto show_dialog() -> xtd::forms::dialog_result;
      /// @brief Shows the form as a modal dialog box with the specified owner.
      /// @parm owner Any object that implements iwin32_window that represents the top-level window that will own the modal dialog box.
      /// @return One of the dialog_result values.
      virtual auto show_dialog(const xtd::forms::iwin32_window& owner) -> xtd::forms::dialog_result;
      
      /// @brief Shows the form as a sheet dialog box.
      /// @remarks dialog_result property contains the result when the form will closed.
      /// @remarks Sheet mode is only available on macOS. For other platform show_dialog is underlying called.
      virtual auto show_sheet(const xtd::forms::iwin32_window& owner) -> void;
      
      /// @brief Shows the form as a modal sheet dialog box.
      /// @return One of the dialog_result values.
      /// @remarks Sheet mode is only available on macOS. For other platform show_dialog is underlying called.
      virtual auto show_sheet_dialog(const xtd::forms::iwin32_window& owner) -> xtd::forms::dialog_result;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::form.
      /// @return New xtd::forms::form created.
      [[nodiscard]] static auto create() -> form;
      /// @brief A factory to create an xtd::forms::form with specified text.
      /// @param text A string that represent text of the xtd::forms::form.
      /// @return New xtd::forms::form created.
      [[nodiscard]] static auto create(const xtd::string& text) -> form;
      /// @brief A factory to create an xtd::forms::form with specified text, and location.
      /// @param text A string that represent text of the xtd::forms::form.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::form.
      /// @return New xtd::forms::form created.
      [[nodiscard]] static auto create(const xtd::string& text, const xtd::drawing::point& location) -> form;
      /// @brief A factory to create an xtd::forms::form with specified text, location, and size.
      /// @param text A string that represent text of the xtd::forms::form.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::form.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::form.
      /// @return New xtd::forms::form created.
      [[nodiscard]] static auto create(const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size) -> form;
      /// @brief A factory to create an xtd::forms::form with specified text, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::form.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::form.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::form.
      /// @param name The name of the xtd::forms::form.
      /// @return New xtd::forms::form created.
      [[nodiscard]] static auto create(const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> form;
      /// @brief A factory to create an xtd::forms::form with specified text, and size.
      /// @param text A string that represent text of the xtd::forms::form.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::form.
      /// @return New xtd::forms::form created.
      [[nodiscard]] static auto create(const xtd::string& text, const xtd::drawing::size& size) -> form;
      /// @brief A factory to create an xtd::forms::form with specified text, size, and name.
      /// @param text A string that represent text of the xtd::forms::form.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::form.
      /// @param name The name of the xtd::forms::form.
      /// @return New xtd::forms::form created.
      [[nodiscard]] static auto create(const xtd::string& text, const xtd::drawing::size& size, const xtd::string& name) -> form;
      /// @brief A factory to create an xtd::forms::form with specified text, and form start position.
      /// @param text A string that represent text of the xtd::forms::form.
      /// @param start_position A form_start_position that represents the starting position of the form.
      /// @return New xtd::forms::form created.
      [[nodiscard]] static auto create(const xtd::string& text, xtd::forms::form_start_position start_position) -> form;
      /// @brief A factory to create an xtd::forms::form with specified text, form start position, and location.
      /// @param text A string that represent text of the xtd::forms::form.
      /// @param start_position A form_start_position that represents the starting position of the form.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::form.
      /// @return New xtd::forms::form created.
      [[nodiscard]] static auto create(const xtd::string& text, xtd::forms::form_start_position start_position, const xtd::drawing::point& location) -> form;
      /// @brief A factory to create an xtd::forms::form with specified text, form start position, location, and size.
      /// @param text A string that represent text of the xtd::forms::form.
      /// @param start_position A form_start_position that represents the starting position of the form.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::form.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::form.
      /// @return New xtd::forms::form created.
      [[nodiscard]] static auto create(const xtd::string& text, xtd::forms::form_start_position start_position, const xtd::drawing::point& location, const xtd::drawing::size& size) -> form;
      /// @brief A factory to create an xtd::forms::form with specified text, form start position, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::form.
      /// @param start_position A form_start_position that represents the starting position of the form.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::form.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::form.
      /// @param name The name of the xtd::forms::form.
      /// @return New xtd::forms::form created.
      [[nodiscard]] static auto create(const xtd::string& text, xtd::forms::form_start_position start_position, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> form;
      /// @brief A factory to create an xtd::forms::form with specified text, form start position, and size.
      /// @param text A string that represent text of the xtd::forms::form.
      /// @param start_position A form_start_position that represents the starting position of the form.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::form.
      /// @return New xtd::forms::form created.
      [[nodiscard]] static auto create(const xtd::string& text, xtd::forms::form_start_position start_position, const xtd::drawing::size& size) -> form;
      /// @brief A factory to create an xtd::forms::form with specified text, form start position, size, and name.
      /// @param text A string that represent text of the xtd::forms::form.
      /// @param start_position A form_start_position that represents the starting position of the form.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::form.
      /// @param name The name of the xtd::forms::form.
      /// @return New xtd::forms::form created.
      [[nodiscard]] static auto create(const xtd::string& text, xtd::forms::form_start_position start_position, const xtd::drawing::size& size, const xtd::string& name) -> form;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the form is activated in code or by the user.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<form, xtd::event_handler> activated;
      
      /// @brief Occurs when the form loses focus and is no longer the active form.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<form, xtd::event_handler> deactivate;
      
      /// @brief Occurs after the form is closed.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<form, xtd::forms::form_closed_event_handler> form_closed;
      
      /// @brief Occurs before the form is closed.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<form, xtd::forms::form_closing_event_handler> form_closing;
      /// @}
      
    protected:
      friend class application;
      
      /// @name Protected Properties
      
      /// @{
      auto create_params() const noexcept -> xtd::forms::create_params override;
      auto default_size() const noexcept -> xtd::drawing::size override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      /// @brief Raises the form::activated event.
      /// @param e An event_args that contains the event data.
      virtual auto on_activated(const xtd::event_args& e) -> void;
      
      /// @brief Raises the form::deactivate event.
      /// @param e An event_args that contains the event data.
      virtual auto on_deactivate(const xtd::event_args& e) -> void;
      
      auto on_handle_created(const xtd::event_args& e) -> void override;
      auto on_handle_destroyed(const xtd::event_args& e) -> void override;
      
      /// @brief Raises the form::form_closed event.
      /// @param e A form_closed_event_args that contains the event data.
      virtual auto on_form_closed(const xtd::forms::form_closed_event_args& e) -> void;
      
      /// @brief Raises the form::form_closing event.
      /// @param e A form_closing_event_args that contains the event data.
      virtual auto on_form_closing(xtd::forms::form_closing_event_args& e) -> void;
      
      auto on_layout(const xtd::event_args& e) -> void override;
      auto on_location_changed(const xtd::event_args& e) -> void override;
      auto on_paint(xtd::forms::paint_event_args& e) -> void override;
      auto on_region_changed(const xtd::event_args& e) -> void override;
      
      auto on_resize(const xtd::event_args& e) -> void override;
      auto wnd_proc(xtd::forms::message& message) -> void override;
      /// @}
      
    private:
      friend class xtd::forms::application_context;
      [[nodiscard]] auto closed_() const noexcept -> bool;
      auto internal_set_window_state() -> void;
      
      auto create_system_menu() -> void;
      auto destroy_system_menu() -> void;
      
      auto fill_in_create_params_border_icons(xtd::forms::create_params& cp) const -> void;
      auto fill_in_create_params_border_styles(xtd::forms::create_params& cp) const -> void;
      auto fill_in_create_params_start_position(xtd::forms::create_params& cp) const -> void;
      auto fill_in_create_params_window_state(xtd::forms::create_params& cp) const -> void;
      
      auto wm_activate(xtd::forms::message& message) -> void;
      auto wm_close(xtd::forms::message& message) -> void;
      auto wm_recreate(xtd::forms::message& message) -> void;
      auto wm_syscolor_change(xtd::forms::message& message) -> void;
      
      xtd::sptr<data> data_;
      static std::optional<xtd::forms::form_ref> active_form_;
    };
  }
}
