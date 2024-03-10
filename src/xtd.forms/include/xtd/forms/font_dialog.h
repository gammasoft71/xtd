/// @file
/// @brief Contains xtd::forms::font_dialog dialog.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "common_dialog.h"
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
    /// @code #include <xtd/forms/font_dialog> @endcode
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
    /// | Light |  @image html dialog_font_dialog_w.png   |  @image html dialog_font_dialog_m.png   |  @image html dialog_font_dialog_g.png   |
    /// | Dark  |  @image html dialog_font_dialog_wd.png  |  @image html dialog_font_dialog_md.png  |  @image html dialog_font_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of font_dialog dialog.
    /// @include font_dialog.cpp
    class forms_export_ font_dialog : public common_dialog {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the font_dialog class.
      /// @remarks When you create an instance of font_dialog, the following read/write properties are initialized.
      /// | Property             | Initial value |
      /// | -------------------- | ------------- |
      /// | allow_simulations    | true          |
      /// | allow_vector_fonts   | true          |
      /// | allow_vertical_fonts | true          |
      /// | allow_script_change  | true          |
      /// | color                | color::black  |
      /// | fixed_pitch_only     | false         |
      /// | max_size             | 0             |
      /// | min_size             | 0             |
      /// | scripts_only         | false         |
      /// | show_apply           | false         |
      /// | show_color           | false         |
      /// | show_effects         | true          |
      /// | show_help            | false         |
      /// @remarks You can change the value for any of these properties through a separate call to the property.
      font_dialog();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value indicating whether the user can change the character set specified in the Script combo box to display a character set other than the one currently displayed.
      /// @return true if the user can change the character set specified in the Script combo box; otherwise, false. The default value is true.
      /// @remarks The Script combo box found on the Font dialog box contains character sets associated with the selected font.
      bool allow_script_change() const noexcept;
      /// @brief Sets a value indicating whether the user can change the character set specified in the Script combo box to display a character set other than the one currently displayed.
      /// @param allow_script_change true if the user can change the character set specified in the Script combo box; otherwise, false. The default value is true.
      /// @return Current font_dialog.
      /// @remarks The Script combo box found on the Font dialog box contains character sets associated with the selected font.
      font_dialog& allow_script_change(bool allow_script_change);
      
      /// @brief Gets a value indicating whether the dialog box allows graphics device interface (GDI) font simulations.
      /// @return true if font simulations are allowed; otherwise, false. The default value is true.
      bool allow_simulation() const noexcept;
      /// @brief Sets a value indicating whether the dialog box allows graphics device interface (GDI) font simulations.
      /// @param allow_simulation true if font simulations are allowed; otherwise, false. The default value is true.
      /// @return Current font_dialog.
      font_dialog& allow_simulation(bool allow_simulation);
      
      /// @brief Gets a value indicating whether the dialog box allows vector font selections.
      /// @return true if vector fonts are allowed; otherwise, false. The default value is true.
      bool allow_vector_fonts() const noexcept;
      /// @brief Sets a value indicating whether the dialog box allows vector font selections.
      /// @param allow_vector_fonts true if vector fonts are allowed; otherwise, false. The default value is true.
      /// @return Current font_dialog.
      font_dialog& allow_vector_fonts(bool allow_vector_fonts);
      
      /// @brief Gets a value indicating whether the dialog box displays both vertical and horizontal fonts or only horizontal fonts.
      /// @return true if both vertical and horizontal fonts are allowed; otherwise, false. The default value is true.
      bool allow_vertical_fonts() const noexcept;
      /// @brief Sets a value indicating whether the dialog box displays both vertical and horizontal fonts or only horizontal fonts.
      /// @param allow_vertical_fonts true if both vertical and horizontal fonts are allowed; otherwise, false. The default value is true.
      /// @return Current font_dialog.
      font_dialog& allow_vertical_fonts(bool allow_vertical_fonts);
      
      /// @brief Gets the selected font color.
      /// @return The color of the selected font. The default value is Black.
      drawing::color color() const noexcept;
      /// @brief Sets the selected font color.
      /// @param color The color of the selected font. The default value is Black.
      /// @return Current font_dialog.
      font_dialog& color(const drawing::color& color);
      
      /// @brief Gets a value indicating whether the dialog box allows only the selection of fixed-pitch fonts.
      /// @return true if only fixed-pitch fonts can be selected; otherwise, false. The default value is false.
      bool fixed_pitch_only() const noexcept;
      /// @brief Sets a value indicating whether the dialog box allows only the selection of fixed-pitch fonts.
      /// @param fixed_pitch_only true if only fixed-pitch fonts can be selected; otherwise, false. The default value is false.
      /// @return Current font_dialog.
      font_dialog& fixed_pitch_only(bool fixed_pitch_only);
      
      /// @brief Gets the selected font.
      /// @return The selected font.
      drawing::font font() const noexcept;
      /// @brief Sets the selected font.
      /// @param font The selected font.
      /// @return Current font_dialog.
      font_dialog& font(const drawing::font& font);
      
      /// @brief Gets a value indicating whether the dialog box specifies an error condition if the user attempts to select a font or style that does not exist.
      /// @return true if the dialog box specifies an error condition when the user tries to select a font or style that does not exist; otherwise, false. The default is false.
      bool font_must_exist() const noexcept;
      /// @brief Sets a value indicating whether the dialog box specifies an error condition if the user attempts to select a font or style that does not exist.
      /// @param font_must_exist true if the dialog box specifies an error condition when the user tries to select a font or style that does not exist; otherwise, false. The default is false.
      /// @return Current font_dialog.
      font_dialog& font_must_exist(bool font_must_exist);
      
      /// @brief Gets the maximum point size a user can select.
      /// @return The maximum point size a user can select. The default is 0.
      size_t max_size() const noexcept;
      /// @brief Sets the maximum point size a user can select.
      /// @param max_size The maximum point size a user can select. The default is 0.
      /// @return Current font_dialog.
      font_dialog& max_size(size_t max_size);
      
      /// @brief Gets the minimum point size a user can select.
      /// @return The minimum point size a user can select. The default is 0.
      size_t min_size() const noexcept;
      /// @brief Sets the minimum point size a user can select.
      /// @param min_size The minimum point size a user can select. The default is 0.
      /// @return Current font_dialog.
      font_dialog& min_size(size_t min_size);
      
      /// @brief Gets values to initialize the font_dialog.
      /// @return A bitwise combination of internal values that initializes the font_dialog.
      /// @remarks The options property corresponds to the flags used to initialize a color dialog box using Win32. Use the properties of the font_dialog class to get and set the options.
      size_t options() const noexcept;
      
      /// @brief Gets a value indicating whether the dialog box allows selection of fonts for all non-OEM and Symbol character sets, as well as the ANSI character set.
      /// @return true if selection of fonts for all non-OEM and Symbol character sets, as well as the ANSI character set, is allowed; otherwise, false. The default value is false.
      bool script_only() const noexcept;
      /// @brief Sets a value indicating whether the dialog box allows selection of fonts for all non-OEM and Symbol character sets, as well as the ANSI character set.
      /// @param script_script = true if selection of fonts for all non-OEM and Symbol character sets, as well as the ANSI character set, is allowed; otherwise, false. The default value is false.
      /// @return Current font_dialog.
      font_dialog& script_only(bool script_only);
      
      /// @brief Gets a value indicating whether the dialog box contains an Apply button.
      /// @return true if the dialog box contains an Apply button; otherwise, false. The default value is false.
      bool show_apply() const noexcept;
      /// @brief Sets a value indicating whether the dialog box contains an Apply button.
      /// @param show_apply true if the dialog box contains an Apply button; otherwise, false. The default value is false.
      /// @return Current font_dialog.
      font_dialog& show_apply(bool show_apply);
      
      /// @brief Gets a value indicating whether the dialog box displays the color choice.
      /// @return true if the dialog box displays the color choice; otherwise, false. The default value is false.
      bool show_color() const noexcept;
      /// @brief Sets a value indicating whether the dialog box displays the color choice.
      /// @param show_color true if the dialog box displays the color choice; otherwise, false. The default value is false.
      /// @return Current font_dialog.
      font_dialog& show_color(bool show_color);
      
      /// @brief Gets a value indicating whether the dialog box contains controls that allow the user to specify strikethrough, underline, and text color options.
      /// @return true if the dialog box contains controls to set strikethrough, underline, and text color options; otherwise, false. The default value is true.
      bool show_effect() const noexcept;
      /// @brief Sets a value indicating whether the dialog box contains controls that allow the user to specify strikethrough, underline, and text color options.
      /// @param show_effect true if the dialog box contains controls to set strikethrough, underline, and text color options; otherwise, false. The default value is true.
      /// @return Current font_dialog.
      font_dialog& show_effect(bool show_effect);
      
      /// @brief Gets a value indicating whether the dialog box displays a Help button.
      /// @return true if the dialog box displays a Help button; otherwise, false. The default value is false.
      bool show_help() const noexcept;
      /// @brief Sets a value indicating whether the dialog box displays a Help button.
      /// @param show_help true if the dialog box displays a Help button; otherwise, false. The default value is false.
      /// @return Current font_dialog.
      font_dialog& show_help(bool show_help);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Resets all dialog box options to their default values.
      /// @remarks When the options are reset, the strikethrough, underline, and color effects are enabled. The fonts listed include only the screen fonts supported by the system.
      void reset() noexcept override;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the user clicks the Apply button in the font dialog box.
      /// @remarks Every time the Apply button is clicked, another apply event is raised.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<font_dialog, event_handler> apply;
      /// @}
      
    protected:
      /// @name Protected methods
      
      /// @{
      /// @brief Raises the font_dialog::apply event.
      /// @param e An event_args that contains the data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @par Notes to Inheritors
      /// When overriding on_apply(const event_args&) in a derived class, be sure to call the base class's on_apply(const event_args&) method.
      virtual void on_apply(const event_args& e);
      
      /// @return Specifies a file dialog box.
      /// @param owner The window handle of the owner window for the common dialog box.
      /// @return true if the dialog box was successfully run; otherwise, false.
      /// @remarks The run_dialog method is invoked when the user of a font dialog box calls the show_dialog method.
      bool run_dialog(intptr owner) override;
      
      /// @brief When overridden in a derived class, specifies a common dialog box.
      /// @param owner A value that represents the window handle of the owner window for the common dialog box.
      void run_sheet(intptr owner) override;
      /// @}
      
    private:
      bool get_option(size_t flag) const noexcept;
      void set_option(size_t flag, bool value);
      
      std::shared_ptr<data> data_;
    };
  }
}
