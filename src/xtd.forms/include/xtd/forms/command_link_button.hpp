/// @file
/// @brief Contains xtd::forms::command_link_button control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "button_base.hpp"
#include "dialog_result.hpp"
#include "ibutton_control.hpp"
#include "timer.hpp"
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
    /// | Light |  @image html control_command_link_button_w.png   |  @image html control_command_link_button_m.png   |  @image html control_command_link_button_g.png   |
    /// | Dark  |  @image html control_command_link_button_wd.png  |  @image html control_command_link_button_md.png  |  @image html control_command_link_button_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of command link button control.
    /// @include command_link_button.cpp
    class forms_export_ command_link_button : public xtd::forms::button_base {
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
      [[nodiscard]] virtual auto auto_size_mode() const noexcept -> xtd::forms::auto_size_mode;
      /// @brief Sets the mode by which the button automatically resizes itself.
      /// @param value One of the AutoSizeMode values. The default value is grow_only.
      virtual auto auto_size_mode(forms::auto_size_mode value) -> command_link_button&;
      
      /// @brief Gets the main text associated with this control.
      /// @return The main text associated with this control.
      [[nodiscard]] virtual auto main_text() const noexcept -> const xtd::string&;
      /// @brief Sets the main text associated with this control.
      /// @param value The main text associated with this control.
      /// @return Current control.
      virtual auto main_text(const xtd::string& value) -> command_link_button&;
      
      /// @brief Gets the supplementary text associated with this control.
      /// @return The supplementary text associated with this control.
      [[nodiscard]] virtual auto supplementary_text() const noexcept -> const xtd::string&;
      /// @brief Sets the supplementary text associated with this control.
      /// @param value The supplementary text associated with this control.
      /// @return Current control.
      virtual auto supplementary_text(const xtd::string& value) -> command_link_button&;
      
      /// @brief Gets the text associated with this control.
      /// @return The text associated with this control.
      [[nodiscard]] auto text() const noexcept -> const xtd::string& override;
      /// @brief Sets the text associated with this control.
      /// @param value The text associated with this control.
      /// @return Current control.
      /// @remarks Is equivalent to calling the texts property with what's before first "\n" as text and after first "\n" as supplementary_text.
      auto text(const xtd::string& value) -> xtd::forms::control& override;
      
      /// @brief Gets text and supplementary text.
      /// @return A tuple of two strings that represent main text and supplementary text.
      [[nodiscard]] virtual auto texts() const noexcept -> std::tuple<xtd::string, xtd::string>;
      /// @brief Sets text and supplementary text.
      /// @param value A tuple of two strings that represent main text and supplementary text.
      /// @return Current control.
      /// @remarks Is equivalent to calling text property with main text and supplementary text separated by "\n".
      virtual auto texts(const std::tuple<xtd::string, xtd::string>& value) -> command_link_button&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Sets text and supplementary text.
      /// @param text A string that represent control text
      /// @param supplementary_text A string that represent supplementary text.
      /// @return Current control.
      /// @remarks Is equivalent to calling text property with main text and supplementary text separated by "\n".
      auto set_texts(const xtd::string& text, const xtd::string& supplementary_text) -> void;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      [[nodiscard]] static auto create() -> command_link_button;
      /// @brief A factory to create an xtd::forms::command_link_button with specified text.
      /// @param text A string that represent text of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      [[nodiscard]] static auto create(const xtd::string& text) -> command_link_button;
      /// @brief A factory to create an xtd::forms::command_link_button with specified text, and location.
      /// @param text A string that represent text of the xtd::forms::command_link_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      [[nodiscard]] static auto create(const xtd::string& text, const xtd::drawing::point& location) -> command_link_button;
      /// @brief A factory to create an xtd::forms::command_link_button with specified text, location, and size.
      /// @param text A string that represent text of the xtd::forms::command_link_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      [[nodiscard]] static auto create(const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size) -> command_link_button;
      /// @brief A factory to create an xtd::forms::command_link_button with specified text, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::command_link_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::command_link_button.
      /// @param name The name of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      [[nodiscard]] static auto create(const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief A factory to create an xtd::forms::command_link_button with specified text, and supplementary_text.
      /// @param texts A tuple of two strings that represent main text and supplementary text.
      /// @return New xtd::forms::command_link_button created.
      [[nodiscard]] static auto create(const std::tuple<xtd::string, xtd::string>& texts) -> command_link_button;
      /// @brief A factory to create an xtd::forms::command_link_button with specified text, supplementary_text, and location.
      /// @param texts A tuple of two strings that represent main text and supplementary text.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      [[nodiscard]] static auto create(const std::tuple<xtd::string, xtd::string>& texts, const xtd::drawing::point& location) -> command_link_button;
      /// @brief A factory to create an xtd::forms::command_link_button with specified text, supplementary_text, location, and size.
      /// @param texts A tuple of two strings that represent main text and supplementary text.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      [[nodiscard]] static auto create(const std::tuple<xtd::string, xtd::string>& texts, const xtd::drawing::point& location, const xtd::drawing::size& size) -> command_link_button;
      /// @brief A factory to create an xtd::forms::command_link_button with specified text, supplementary_text, location, size, and name.
      /// @param texts A tuple of two strings that represent main text and supplementary text.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::command_link_button.
      /// @param name The name of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      [[nodiscard]] static auto create(const std::tuple<xtd::string, xtd::string>& texts, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief A factory to create an xtd::forms::command_link_button with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent) -> command_link_button;
      /// @brief A factory to create an xtd::forms::command_link_button with specified parent, and text.
      /// @param parent The parent that contains the new created xtd::forms::command_link_button.
      /// @param text A string that represent text of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::string& text) -> command_link_button;
      /// @brief A factory to create an xtd::forms::command_link_button with specified parent, text, and location.
      /// @param parent The parent that contains the new created xtd::forms::command_link_button.
      /// @param text A string that represent text of the xtd::forms::command_link_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::string& text, const xtd::drawing::point& location) -> command_link_button;
      /// @brief A factory to create an xtd::forms::command_link_button with specified parent, text, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::command_link_button.
      /// @param text A string that represent text of the xtd::forms::command_link_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size) -> command_link_button;
      /// @brief A factory to create an xtd::forms::command_link_button with specified parent, text, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::command_link_button.
      /// @param text A string that represent text of the xtd::forms::command_link_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::command_link_button.
      /// @param name The name of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief A factory to create an xtd::forms::command_link_button with specified parent, text, and supplementary_text.
      /// @param parent The parent that contains the new created xtd::forms::command_link_button.
      /// @param texts A tuple of two strings that represent main text and supplementary text.
      /// @return New xtd::forms::command_link_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const std::tuple<xtd::string, xtd::string>& texts) -> command_link_button;
      /// @brief A factory to create an xtd::forms::command_link_button with specified parent, text, supplementary_text, and location.
      /// @param parent The parent that contains the new created xtd::forms::command_link_button.
      /// @param texts A tuple of two strings that represent main text and supplementary text.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const std::tuple<xtd::string, xtd::string>& texts, const xtd::drawing::point& location) -> command_link_button;
      /// @brief A factory to create an xtd::forms::command_link_button with specified parent, text, supplementary_text, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::command_link_button.
      /// @param texts A tuple of two strings that represent main text and supplementary text.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const std::tuple<xtd::string, xtd::string>& texts, const xtd::drawing::point& location, const xtd::drawing::size& size) -> command_link_button;
      /// @brief A factory to create an xtd::forms::command_link_button with specified parent, text, supplementary_text, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::command_link_button.
      /// @param texts A tuple of two strings that represent main text and supplementary text.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::command_link_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::command_link_button.
      /// @param name The name of the xtd::forms::command_link_button.
      /// @return New xtd::forms::command_link_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const std::tuple<xtd::string, xtd::string>& texts, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @}
      
      /// @name Public Deprecated Methods
      
      /// @{
      /// @brief Sets text and supplementary text.
      /// @param text A string that represent control text
      /// @param supplementary_text A string that represent supplementary text.
      /// @return Current control.
      /// @remarks Is equivalent to calling text property with main text and supplementary text separated by "\n".
      /// @deprecated Replaced by xtd::forms::command_link_button::set_texts - Will be removed in version 1.2.0.
      [[deprecated("Replaced by xtd::forms::command_link_button::set_texts - Will be removed in version 1.2.0.")]]
      [[nodiscard]] auto texts(const xtd::string& text, const xtd::string& supplementary_text) -> xtd::forms::control&;
      /// @}
      
    protected:
      /// @name Protected Properties
      
      /// @{
      [[nodiscard]] auto create_params() const noexcept -> xtd::forms::create_params override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      [[nodiscard]] auto measure_control() const noexcept -> xtd::drawing::size override;
      auto on_handle_created(const event_args& e) -> void override;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
