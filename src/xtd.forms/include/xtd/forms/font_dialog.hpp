/// @file
/// @brief Contains xtd::forms::font_dialog dialog.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "common_dialog.hpp"
#include <xtd/drawing/color>
#include <xtd/drawing/font>
#include <xtd/drawing/system_colors>
#include <xtd/drawing/system_fonts>
#include <xtd/forms/choose_font_flags>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Prompts the user to choose a font from among those installed on the local computer.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/font_dialog>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @remarks The inherited member show_dialog must be invoked to create this specific common dialog box. hook_proc can be overridden to implement specific dialog box hook functionality.
    /// @remarks When you create an instance of font_dialog, some of the read/write properties are set to initial values. For a list of these values, see the font_dialog constructor.
    /// @par Appearance
    /// |       | Windows                                 | macOS                                   | Gnome                                   |
    /// | ----- | --------------------------------------- | --------------------------------------- | --------------------------------------- |
    /// | Light |  @image html dialog_font_dialog_w.png   |  @image html dialog_font_dialog_m.png   |  @image html dialog_font_dialog_g.png   |
    /// | Dark  |  @image html dialog_font_dialog_wd.png  |  @image html dialog_font_dialog_md.png  |  @image html dialog_font_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of font_dialog dialog.
    /// @include font_dialog.cpp
    class forms_export_ font_dialog : public xtd::forms::common_dialog {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the font_dialog class.
      /// @remarks When you create an instance of font_dialog, the following read/write properties are initialized.
      /// | Property             | Initial value |
      /// | -------------------- | ------------- |
      /// | allow_simulations    | `true`        |
      /// | allow_vector_fonts   | `true`        |
      /// | allow_vertical_fonts | `true`        |
      /// | allow_script_change  | `true`        |
      /// | color                | color::black  |
      /// | fixed_pitch_only     | `false`       |
      /// | max_size             | 0             |
      /// | min_size             | 0             |
      /// | scripts_only         | `false`       |
      /// | show_apply           | `false`       |
      /// | show_color           | `false`       |
      /// | show_effects         | `true`        |
      /// | show_help            | `false`       |
      /// @remarks You can change the value for any of these properties through a separate call to the property.
      font_dialog();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value indicating whether the user can change the character set specified in the Script combo box to display a character set other than the one currently displayed.
      /// @return `true` if the user can change the character set specified in the Script combo box; otherwise, `false`. The default value is `true`.
      /// @remarks The Script combo box found on the Font dialog box contains character sets associated with the selected font.
      [[nodiscard]] auto allow_script_change() const noexcept -> bool;
      /// @brief Sets a value indicating whether the user can change the character set specified in the Script combo box to display a character set other than the one currently displayed.
      /// @param value `true` if the user can change the character set specified in the Script combo box; otherwise, `false`. The default value is `true`.
      /// @return Current font_dialog.
      /// @remarks The Script combo box found on the Font dialog box contains character sets associated with the selected font.
      auto allow_script_change(bool value) -> font_dialog&;
      
      /// @brief Gets a value indicating whether the dialog box allows graphics device interface (GDI) font simulations.
      /// @return `true` if font simulations are allowed; otherwise, `false`. The default value is `true`.
      [[nodiscard]] auto allow_simulation() const noexcept -> bool;
      /// @brief Sets a value indicating whether the dialog box allows graphics device interface (GDI) font simulations.
      /// @param value `true` if font simulations are allowed; otherwise, `false`. The default value is `true`.
      /// @return Current font_dialog.
      auto allow_simulation(bool value) -> font_dialog&;
      
      /// @brief Gets a value indicating whether the dialog box allows vector font selections.
      /// @return `true` if vector fonts are allowed; otherwise, `false`. The default value is `true`.
      [[nodiscard]] auto allow_vector_fonts() const noexcept -> bool;
      /// @brief Sets a value indicating whether the dialog box allows vector font selections.
      /// @param value `true` if vector fonts are allowed; otherwise, `false`. The default value is `true`.
      /// @return Current font_dialog.
      auto allow_vector_fonts(bool value) -> font_dialog&;
      
      /// @brief Gets a value indicating whether the dialog box displays both vertical and horizontal fonts or only horizontal fonts.
      /// @return `true` if both vertical and horizontal fonts are allowed; otherwise, `false`. The default value is `true`.
      [[nodiscard]] auto allow_vertical_fonts() const noexcept -> bool;
      /// @brief Sets a value indicating whether the dialog box displays both vertical and horizontal fonts or only horizontal fonts.
      /// @param value `true` if both vertical and horizontal fonts are allowed; otherwise, `false`. The default value is `true`.
      /// @return Current font_dialog.
      auto allow_vertical_fonts(bool value) -> font_dialog&;
      
      /// @brief Gets the selected font color.
      /// @return The color of the selected font. The default value is Black.
      [[nodiscard]] auto color() const noexcept -> xtd::drawing::color;
      /// @brief Sets the selected font color.
      /// @param value The color of the selected font. The default value is Black.
      /// @return Current font_dialog.
      auto color(const xtd::drawing::color& value) -> font_dialog&;
      
      /// @brief Gets a value indicating whether the dialog box allows only the selection of fixed-pitch fonts.
      /// @return `true` if only fixed-pitch fonts can be selected; otherwise, `false`. The default value is `false`.
      [[nodiscard]] auto fixed_pitch_only() const noexcept -> bool;
      /// @brief Sets a value indicating whether the dialog box allows only the selection of fixed-pitch fonts.
      /// @param value `true` if only fixed-pitch fonts can be selected; otherwise, `false`. The default value is `false`.
      /// @return Current font_dialog.
      auto fixed_pitch_only(bool value) -> font_dialog&;
      
      /// @brief Gets the selected font.
      /// @return The selected font.
      [[nodiscard]] auto font() const noexcept -> xtd::drawing::font;
      /// @brief Sets the selected font.
      /// @param value The selected font.
      /// @return Current font_dialog.
      auto font(const xtd::drawing::font& value) -> font_dialog&;
      
      /// @brief Gets a value indicating whether the dialog box specifies an error condition if the user attempts to select a font or style that does not exist.
      /// @return `true` if the dialog box specifies an error condition when the user tries to select a font or style that does not exist; otherwise, `false`. The default is `false`.
      [[nodiscard]] auto font_must_exist() const noexcept -> bool;
      /// @brief Sets a value indicating whether the dialog box specifies an error condition if the user attempts to select a font or style that does not exist.
      /// @param value `true` if the dialog box specifies an error condition when the user tries to select a font or style that does not exist; otherwise, `false`. The default is `false`.
      /// @return Current font_dialog.
      auto font_must_exist(bool value) -> font_dialog&;
      
      /// @brief Gets the maximum point size a user can select.
      /// @return The maximum point size a user can select. The default is 0.
      [[nodiscard]] auto max_size() const noexcept -> xtd::usize;
      /// @brief Sets the maximum point size a user can select.
      /// @param value The maximum point size a user can select. The default is 0.
      /// @return Current font_dialog.
      auto max_size(xtd::usize value) -> font_dialog&;
      
      /// @brief Gets the minimum point size a user can select.
      /// @return The minimum point size a user can select. The default is 0.
      [[nodiscard]] auto min_size() const noexcept -> xtd::usize;
      /// @brief Sets the minimum point size a user can select.
      /// @param value The minimum point size a user can select. The default is 0.
      /// @return Current font_dialog.
      auto min_size(xtd::usize value) -> font_dialog&;
      
      /// @brief Gets values to initialize the font_dialog.
      /// @return A bitwise combination of internal values that initializes the font_dialog.
      /// @remarks The options property corresponds to the flags used to initialize a color dialog box using Win32. Use the properties of the font_dialog class to get and set the options.
      [[nodiscard]] auto options() const noexcept -> xtd::usize;
      
      /// @brief Gets a value indicating whether the dialog box allows selection of fonts for all non-OEM and Symbol character sets, as well as the ANSI character set.
      /// @return `true` if selection of fonts for all non-OEM and Symbol character sets, as well as the ANSI character set, is allowed; otherwise, `false`. The default value is `false`.
      [[nodiscard]] auto script_only() const noexcept -> bool;
      /// @brief Sets a value indicating whether the dialog box allows selection of fonts for all non-OEM and Symbol character sets, as well as the ANSI character set.
      /// @param value = `true` if selection of fonts for all non-OEM and Symbol character sets, as well as the ANSI character set, is allowed; otherwise, `false`. The default value is `false`.
      /// @return Current font_dialog.
      auto script_only(bool value) -> font_dialog&;
      
      /// @brief Gets a value indicating whether the dialog box contains an Apply button.
      /// @return `true` if the dialog box contains an Apply button; otherwise, `false`. The default value is `false`.
      [[nodiscard]] auto show_apply() const noexcept -> bool;
      /// @brief Sets a value indicating whether the dialog box contains an Apply button.
      /// @param value `true` if the dialog box contains an Apply button; otherwise, `false`. The default value is `false`.
      /// @return Current font_dialog.
      auto show_apply(bool value) -> font_dialog&;
      
      /// @brief Gets a value indicating whether the dialog box displays the color choice.
      /// @return `true` if the dialog box displays the color choice; otherwise, `false`. The default value is `false`.
      [[nodiscard]] auto show_color() const noexcept -> bool;
      /// @brief Sets a value indicating whether the dialog box displays the color choice.
      /// @param value `true` if the dialog box displays the color choice; otherwise, `false`. The default value is `false`.
      /// @return Current font_dialog.
      auto show_color(bool value) -> font_dialog&;
      
      /// @brief Gets a value indicating whether the dialog box contains controls that allow the user to specify strikethrough, underline, and text color options.
      /// @return `true` if the dialog box contains controls to set strikethrough, underline, and text color options; otherwise, `false`. The default value is `true`.
      [[nodiscard]] auto show_effect() const noexcept -> bool;
      /// @brief Sets a value indicating whether the dialog box contains controls that allow the user to specify strikethrough, underline, and text color options.
      /// @param value `true` if the dialog box contains controls to set strikethrough, underline, and text color options; otherwise, `false`. The default value is `true`.
      /// @return Current font_dialog.
      auto show_effect(bool value) -> font_dialog&;
      
      /// @brief Gets a value indicating whether the dialog box displays a Help button.
      /// @return `true` if the dialog box displays a Help button; otherwise, `false`. The default value is `false`.
      [[nodiscard]] auto show_help() const noexcept -> bool;
      /// @brief Sets a value indicating whether the dialog box displays a Help button.
      /// @param value `true` if the dialog box displays a Help button; otherwise, `false`. The default value is `false`.
      /// @return Current font_dialog.
      auto show_help(bool value) -> font_dialog&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Resets all dialog box options to their default values.
      /// @remarks When the options are reset, the strikethrough, underline, and color effects are enabled. The fonts listed include only the screen fonts supported by the system.
      auto reset() noexcept -> void override;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the user clicks the Apply button in the font dialog box.
      /// @remarks Every time the Apply button is clicked, another apply event is raised.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<font_dialog, xtd::event_handler> apply;
      /// @}
      
    protected:
      /// @name Protected Methods
      
      /// @{
      /// @brief Raises the font_dialog::apply event.
      /// @param e An event_args that contains the data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @par Notes to Inheritors
      /// When overriding on_apply(const event_args&) in a derived class, be sure to call the base class's on_apply(const event_args&) method.
      virtual auto on_apply(const xtd::event_args& e) -> void;
      
      /// @return Specifies a file dialog box.
      /// @param owner The window handle of the owner window for the common dialog box.
      /// @return `true` if the dialog box was successfully run; otherwise, `false`.
      /// @remarks The run_dialog method is invoked when the user of a font dialog box calls the show_dialog method.
      auto run_dialog(xtd::intptr owner) -> bool override;
      
      /// @brief When overridden in a derived class, specifies a common dialog box.
      /// @param owner A value that represents the window handle of the owner window for the common dialog box.
      auto run_sheet(xtd::intptr owner) -> void override;
      /// @}
      
    private:
      [[nodiscard]] auto get_option(xtd::usize flag) const noexcept -> bool;
      auto set_option(xtd::usize flag, bool value) -> void;
      
      xtd::sptr<data> data_;
    };
  }
}
