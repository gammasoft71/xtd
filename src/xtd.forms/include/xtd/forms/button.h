/// @file
/// @brief Contains xtd::forms::button control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "button_base.h"
#include "dialog_result.h"
#include "ibutton_control.h"
#include "timer.h"
#include "visual_styles/push_button_state.h"
#include <xtd/environment>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows button control.
    /// @code
    /// class forms_export_ button : public xtd::forms::ibutton_control, public xtd::forms::button_base
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::forms::component → xtd::forms::control → xtd::forms::button_base → xtd::forms::button
    /// @par Implements
    /// xtd::forms::ibutton_control
    /// @par Header
    /// @code #include <xtd/forms/button> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks A Button can be clicked by using the mouse, ENTER key, or SPACEBAR if the button has focus.
    /// @remarks Set the accept_button or cancel_button property of a form to allow users to click a button by pressing the ENTER or ESC keys even if the button does not have focus. This gives the form the behavior of a dialog box.
    /// @remarks When you display a form using the show_dialog method, you can use the dialog_result property of a button to specify the return value of show_dialog.
    /// @remarks You can change the button's appearance. For example, to make it appear flat for a Web look, set the flat_style property to flat_style::flat. The flat_style property can also be set to flat_style::popup, which appears flat until the mouse pointer passes over the button; then the button takes on the standard Windows button appearance.
    /// @note If the control that has focus accepts and processes the ENTER key press, the button does not process it. For example, if a multiline text_box or another button has focus, that control processes the ENTER key press instead of the accept button.
    /// @par Appearance
    /// |       | Windows                             | macOS                               | Gnome                               |
    /// | ----- | ----------------------------------- | ----------------------------------- | ----------------------------------- |
    /// | Light |  @image html control_button_w.png   |  @image html control_button_m.png   |  @image html control_button_g.png   |
    /// | Dark  |  @image html control_button_wd.png  |  @image html control_button_md.png  |  @image html control_button_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of button control.
    /// @include button.cpp
    /// @par Examples
    /// The following code example demonstrates the use of button control with bitmap.
    /// @include bitmap_button.cpp
    class forms_export_ button : public ibutton_control, public button_base {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the button class.
      /// @remarks By default the button displays no caption. To specify the caption text, set the text property.
      button();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets if this button instance is auto repeat.
      /// @return true, if is auto repeat; otherwise false. Default is false.
      virtual bool auto_repeat() const noexcept;
      /// @brief Sets if this button instance is auto repeat.
      /// @param auto_repeat true, if is auto repeat; otherwise false. Default is false.
      /// @return This button.
      virtual button& auto_repeat(bool auto_repeat);
      
      /// @brief Gets the auto repeat delay.
      /// @return Auto repeat delay in milliseconds. Default is 300 ms.
      virtual int32 auto_repeat_delay() const noexcept;
      /// @brief Gets the auto repeat delay.
      /// @param auto_repeat_delay Auto repeat delay in milliseconds. Default is 300 ms.
      /// @return This button.
      virtual button& auto_repeat_delay(int32 auto_repeat_delay);
      
      /// @brief Gets the auto repeat interval.
      /// @return Auto repeat interval in milliseconds. Default is 100 ms.
      virtual int32 auto_repeat_interval() const noexcept;
      /// @brief Gets the auto repeat interval.
      /// @param auto_repeat_delay Auto repeat interval in milliseconds. Default is 100 ms.
      /// @return This button.
      virtual button& auto_repeat_interval(int32 auto_repeat_interval);
      
      /// @brief Gets the mode by which the button automatically resizes itself.
      /// @return One of the AutoSizeMode values. The default value is grow_only.
      virtual forms::auto_size_mode auto_size_mode() const noexcept;
      /// @brief Sets the mode by which the button automatically resizes itself.
      /// @param value One of the AutoSizeMode values. The default value is grow only.
      virtual button& auto_size_mode(forms::auto_size_mode value);
      
      forms::dialog_result dialog_result() const noexcept override;
      control& dialog_result(forms::dialog_result dialog_result) override;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      void notify_default(bool value) override;
      
      void perform_click() override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::button.
      /// @return New xtd::forms::button created.
      static button create();
      /// @brief A factory to create an xtd::forms::button with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      static button create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::button with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      static button create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::button with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::button.
      /// @param name The name of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      static button create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::button with specified text.
      /// @param text A string that represent text of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      static button create(const xtd::ustring& text);
      /// @brief A factory to create an xtd::forms::button with specified text, and location.
      /// @param text A string that represent text of the xtd::forms::button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      static button create(const xtd::ustring& text, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::button with specified text, location, and size.
      /// @param text A string that represent text of the xtd::forms::button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      static button create(const xtd::ustring& text, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::button with specified text, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::button.
      /// @param name The name of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      static button create(const xtd::ustring& text, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::button with specified parent,.
      /// @param parent The parent that contains the new created xtd::forms::button.
      /// @return New xtd::forms::button created.
      static button create(const control& parent);
      /// @brief A factory to create an xtd::forms::button with specified parent, location.
      /// @param parent The parent that contains the new created xtd::forms::button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      static button create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::button with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      static button create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::button with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::button.
      /// @param name The name of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      static button create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::button with specified parent, and text.
      /// @param parent The parent that contains the new created xtd::forms::button.
      /// @param text A string that represent text of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      static button create(const control& parent, const xtd::ustring& text);
      /// @brief A factory to create an xtd::forms::button with specified parent, text, and location.
      /// @param parent The parent that contains the new created xtd::forms::button.
      /// @param text A string that represent text of the xtd::forms::button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      static button create(const control& parent, const xtd::ustring& text, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::button with specified parent, text, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::button.
      /// @param text A string that represent text of the xtd::forms::button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      static button create(const control& parent, const xtd::ustring& text, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::button with specified parent, text, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::button.
      /// @param text A string that represent text of the xtd::forms::button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::button.
      /// @param name The name of the xtd::forms::button.
      /// @return New xtd::forms::button created.
      static button create(const control& parent, const xtd::ustring& text, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

    protected:
      /// @name Protected properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      
      /// @brief Gets state.
      /// @return One of xtd::forms::visual_styles::push_button_state values.
      xtd::forms::visual_styles::push_button_state state() const noexcept;
      /// @}
      
      /// @name Protected methods
      
      /// @{
      drawing::size measure_control() const noexcept override;
      
      void on_click(const event_args& e) override;
      void on_enabled_changed(const event_args& e) override;
      void on_handle_created(const event_args& e) override;
      void on_image_changed(const xtd::event_args& e) override;
      void on_mouse_down(const mouse_event_args& e) override;
      void on_mouse_enter(const event_args& e) override;
      void on_mouse_leave(const event_args& e) override;
      void on_mouse_up(const mouse_event_args& e) override;
      void on_paint(paint_event_args& e) override;
      /// @}

    private:
      void on_auto_repeat_timer_tick(object& sender, const event_args& e);
      
      std::shared_ptr<data> data_;
    };
  }
}
