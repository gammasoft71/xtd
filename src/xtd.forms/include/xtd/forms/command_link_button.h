/// @file
/// @brief Contains xtd::forms::command_link_button control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "button_base.h"
#include "dialog_result.h"
#include "ibutton_control.h"
#include "timer.h"
#include <xtd/environment>
#include <tuple>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows command link button control.
    /// ```cpp
    /// class forms_export_ command_link_button : public xtd::forms::button_base
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::forms::component → xtd::forms::control → xtd::forms::button_base → xtd::forms::command_link_button
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/command_link_button>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                          | macOS                                            | Gnome                                            |
    /// | ----- | ------------------------------------------------ | ------------------------------------------------ | ------------------------------------------------ |
    /// | Light |  @image html control_command_link_button_w.png   |  @image html control_command_link_button_m.png   |  @image html control_command_link_button_g.png   |
    /// | Dark  |  @image html control_command_link_button_wd.png  |  @image html control_command_link_button_md.png  |  @image html control_command_link_button_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of command link button control.
    /// @include command_link_button.cpp
    class forms_export_ command_link_button : public button_base {
      struct data;

    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the button class.
      /// @remarks By default the button displays no caption. To specify the caption text, set the text property.
      command_link_button();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the mode by which the button automatically resizes itself.
      /// @return One of the AutoSizeMode values. The default value is grow_only.
      virtual forms::auto_size_mode auto_size_mode() const noexcept;
      /// @brief Sets the mode by which the button automatically resizes itself.
      /// @param value One of the AutoSizeMode values. The default value is grow_only.
      virtual command_link_button& auto_size_mode(forms::auto_size_mode value);

      /// @brief Gets the main text associated with this control.
      /// @return The main text associated with this control.
      virtual xtd::string& main_text() const noexcept;
      /// @brief Sets the main text associated with this control.
      /// @param text The main text associated with this control.
      /// @return Current control.
      virtual command_link_button& main_text(const xtd::string& value);

      /// @brief Gets the supplementary text associated with this control.
      /// @return The supplementary text associated with this control.
      virtual xtd::string& supplementary_text() const noexcept;
      /// @brief Sets the supplementary text associated with this control.
      /// @param text The supplementary text associated with this control.
      /// @return Current control.
      virtual command_link_button& supplementary_text(const xtd::string& value);

      /// @brief Gets the text associated with this control.
      /// @return The text associated with this control.
      xtd::string& text() const noexcept override;
      /// @brief Sets the text associated with this control.
      /// @param text The text associated with this control.
      /// @return Current control.
      /// @remarks Is equivalent to calling the texts property with what's before first "\n" as text and after first "\n" as supplementary_text.
      xtd::forms::control& text(const xtd::string& value) override;

      /// @brief Gets text and supplementary text.
      /// @return A tuple of two strings that represent main text and supplementary text.
      virtual std::tuple<xtd::string, xtd::string> texts() const noexcept;
      /// @brief Sets text and supplementary text.
      /// @param texts A tuple of two strings that represent main text and supplementary text.
      /// @return Current control.
      /// @remarks Is equivalent to calling text property with main text and supplementary text separated by "\n".
      virtual command_link_button& texts(const std::tuple<xtd::string, xtd::string>& texts);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Sets text and supplementary text.
      /// @param text A string that represent control text
      /// @param supplementary_text A string that represent supplementary text.
      /// @return Current control.
      /// @remarks Is equivalent to calling text property with main text and supplementary text separated by "\n".
      void set_texts(const xtd::string& text, const xtd::string& supplementary_text);
      
      /// @brief Sets text and supplementary text.
      /// @param text A string that represent control text
      /// @param supplementary_text A string that represent supplementary text.
      /// @return Current control.
      /// @remarks Is equivalent to calling text property with main text and supplementary text separated by "\n".
      /// @deprecated Replaced by xtd::forms::command_link_button::set_texts - Will be removed in version 0.4.0.
      [[deprecated("Replaced by xtd::forms::command_link_button::set_texts - Will be removed in version 0.4.0.")]]
      control& texts(const xtd::string& text, const xtd::string& supplementary_text);
      /// @}

      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      static command_link_button create();
      /// @brief A factory to create an xtd::forms::command_link_button with specified text.
      /// @param text A string that represent text of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      static command_link_button create(const xtd::string& text);
      /// @brief A factory to create an xtd::forms::command_link_button with specified text, and location.
      /// @param text A string that represent text of the xtd::forms::command_link_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      static command_link_button create(const xtd::string& text, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::command_link_button with specified text, location, and size.
      /// @param text A string that represent text of the xtd::forms::command_link_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      static command_link_button create(const xtd::string& text, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::command_link_button with specified text, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::command_link_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::command_link_button.
      /// @param name The name of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      static command_link_button create(const xtd::string& text, const drawing::point& location, const drawing::size& size, const xtd::string& name);
      /// @brief A factory to create an xtd::forms::command_link_button with specified text, and supplementary_text.
      /// @param texts A tuple of two strings that represent main text and supplementary text.
      /// @return New xtd::forms::command_link_button created.
      static command_link_button create(const std::tuple<xtd::string, xtd::string>& texts);
      /// @brief A factory to create an xtd::forms::command_link_button with specified text, supplementary_text, and location.
      /// @param texts A tuple of two strings that represent main text and supplementary text.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      static command_link_button create(const std::tuple<xtd::string, xtd::string>& texts, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::command_link_button with specified text, supplementary_text, location, and size.
      /// @param texts A tuple of two strings that represent main text and supplementary text.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      static command_link_button create(const std::tuple<xtd::string, xtd::string>& texts, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::command_link_button with specified text, supplementary_text, location, size, and name.
      /// @param texts A tuple of two strings that represent main text and supplementary text.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::command_link_button.
      /// @param name The name of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      static command_link_button create(const std::tuple<xtd::string, xtd::string>& texts, const drawing::point& location, const drawing::size& size, const xtd::string& name);
      /// @brief A factory to create an xtd::forms::command_link_button with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      static command_link_button create(const control& parent);
      /// @brief A factory to create an xtd::forms::command_link_button with specified parent, and text.
      /// @param parent The parent that contains the new created xtd::forms::command_link_button.
      /// @param text A string that represent text of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      static command_link_button create(const control& parent, const xtd::string& text);
      /// @brief A factory to create an xtd::forms::command_link_button with specified parent, text, and location.
      /// @param parent The parent that contains the new created xtd::forms::command_link_button.
      /// @param text A string that represent text of the xtd::forms::command_link_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      static command_link_button create(const control& parent, const xtd::string& text, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::command_link_button with specified parent, text, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::command_link_button.
      /// @param text A string that represent text of the xtd::forms::command_link_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      static command_link_button create(const control& parent, const xtd::string& text, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::command_link_button with specified parent, text, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::command_link_button.
      /// @param text A string that represent text of the xtd::forms::command_link_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::command_link_button.
      /// @param name The name of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      static command_link_button create(const control& parent, const xtd::string& text, const drawing::point& location, const drawing::size& size, const xtd::string& name);
      /// @brief A factory to create an xtd::forms::command_link_button with specified parent, text, and supplementary_text.
      /// @param parent The parent that contains the new created xtd::forms::command_link_button.
      /// @param texts A tuple of two strings that represent main text and supplementary text.
      /// @return New xtd::forms::command_link_button created.
      static command_link_button create(const control& parent, const std::tuple<xtd::string, xtd::string>& texts);
      /// @brief A factory to create an xtd::forms::command_link_button with specified parent, text, supplementary_text, and location.
      /// @param parent The parent that contains the new created xtd::forms::command_link_button.
      /// @param texts A tuple of two strings that represent main text and supplementary text.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      static command_link_button create(const control& parent, const std::tuple<xtd::string, xtd::string>& texts, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::command_link_button with specified parent, text, supplementary_text, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::command_link_button.
      /// @param texts A tuple of two strings that represent main text and supplementary text.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      static command_link_button create(const control& parent, const std::tuple<xtd::string, xtd::string>& texts, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::command_link_button with specified parent, text, supplementary_text, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::command_link_button.
      /// @param texts A tuple of two strings that represent main text and supplementary text.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::command_link_button.
      /// @param name The name of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      static command_link_button create(const control& parent, const std::tuple<xtd::string, xtd::string>& texts, const drawing::point& location, const drawing::size& size, const xtd::string& name);
      /// @}
      
    protected:
      /// @name Protected Properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      /// @brief Creates a new object that is a copy of the current instance.
      /// @return A new object that is a copy of this instance.
      /// @par Notes to Implementers
      /// All controls must be override the clone method.
      xtd::uptr<xtd::object> clone() const override;
      
      drawing::size measure_control() const noexcept override;
      void on_handle_created(const event_args& e) override;
      /// @}

    private:
      xtd::sptr<data> data_;
    };
  }
}
