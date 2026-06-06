/// @file
/// @brief Contains xtd::forms::color_dialog dialog.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.hpp"
#include "common_dialog.hpp"
#include <xtd/forms/choose_color_flags>
#include <xtd/drawing/color>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays available colors along with controls that enable the user to define custom colors.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/color_dialog>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @remarks The inherited member show_dialog must be invoked to create this specific common dialog box. hook_proc can be overridden to implement specific dialog box hook functionality. Use color to retrieve the color selected by the user.
    /// @remarks When you create an instance of color_dialog, some of the read/write properties are set to initial values. For a list of these values, see the color_dialog constructor.
    /// @par Appearance
    /// |       | Windows                                  | macOS                                    | Gnome                                    |
    /// | ----- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
    /// | Light |  @image html dialog_color_dialog_w.png   |  @image html dialog_color_dialog_m.png   |  @image html dialog_color_dialog_g.png   |
    /// | Dark  |  @image html dialog_color_dialog_wd.png  |  @image html dialog_color_dialog_md.png  |  @image html dialog_color_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of color_dialog dialog.
    /// @include color_dialog.cpp
    class forms_export_ color_dialog : public xtd::forms::common_dialog {
      struct data;
      
    public:
      /// @brief Represents an xtd::drawing::color array.
      using colors = xtd::array<xtd::drawing::color>;
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the color_dialog class.
      /// @remarks When you create an instance of ColorDialog, the following read/write properties are set to initial values.
      /// | Property         | Initial Value           |
      /// | ---------------- | ----------------------- |
      /// | alpha_color      | `true`                  |
      /// | allow_full_open  | `true`                  |
      /// | any_color        | `false`                 |
      /// | color            | xtd::drawing::color::black   |
      /// | custom_colors    | has no value            |
      /// | full_open        | `false`                 |
      /// | show_help        | `false`                 |
      /// | solid_color_only | `false`                 |
      /// @remarks You can change the value for any of these properties through a separate call to the property.
      color_dialog();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value indicating whether the dialog box shows alpha values and an opacity selector (slider).
      /// @return `true` if the dialog box  shows alpha values and an opacity selector (slider); otherwise, `false`. The default is `true`.
      [[nodiscard]] auto alpha_color() const noexcept -> bool;
      /// @brief Sets a value indicating whether the user can use the dialog box to define custom colors.
      /// @param alpha_color `true` if the dialog box  shows alpha values and an opacity selector (slider); otherwise, `false`.
      auto alpha_color(bool alpha_color) -> color_dialog&;
      
      /// @brief Gets a value indicating whether the user can use the dialog box to define custom colors.
      /// @return `true` if the user can define custom colors; otherwise, `false`. The default is `true`.
      [[nodiscard]] auto allow_full_open() const noexcept -> bool;
      /// @brief Sets a value indicating whether the user can use the dialog box to define custom colors.
      /// @param allow_full_open `true` if the user can define custom colors; otherwise, `false`. The default is `true`.
      auto allow_full_open(bool allow_full_open) -> color_dialog&;
      
      /// @brief Gets a value indicating whether the dialog box displays all available colors in the set of basic colors.
      /// @return `true` if the dialog box displays all available colors in the set of basic colors; otherwise, `false`. The default value is `false`.
      [[nodiscard]] auto any_color() const noexcept -> bool;
      /// @brief Sets a value indicating whether the dialog box displays all available colors in the set of basic colors.
      /// @param any_color `true` if the dialog box displays all available colors in the set of basic colors; otherwise, `false`. The default value is `false`.
      auto any_color(bool any_color) -> color_dialog&;
      
      /// @brief Gets the color selected by the user.
      /// @return The color selected by the user. If a color is not selected, the default value is black.
      /// @remarks The color selected by the user in the dialog box at run time, as defined in color structure.
      [[nodiscard]] auto color() const noexcept -> xtd::drawing::color;
      /// @brief Sets the color selected by the user.
      /// @param color The color selected by the user. If a color is not selected.
      /// @remarks The color selected by the user in the dialog box at run time, as defined in color structure.
      auto color(const xtd::drawing::color& color) -> color_dialog&;
      
      /// @brief Gets the set of custom colors shown in the dialog box.
      /// @return A set of custom colors shown by the dialog box. The default value is empty.
      /// @remarks Users can create their own set of custom colors. These colors are contained in an int32 composed of the BGR (blue, green, red) values necessary to create the color.
      /// @remarks Custom colors can only be defined if allow_full_open is set to `true`.
      [[nodiscard]] auto custom_colors() const noexcept -> const colors&;
      /// @brief Sets the set of custom colors shown in the dialog box.
      /// @param custom_color A set of custom colors shown by the dialog box.
      /// @remarks Users can create their own set of custom colors. These colors are contained in an int32 composed of the BGR (blue, green, red) values necessary to create the color.
      /// @remarks Custom colors can only be defined if allow_full_open is set to `true`.
      auto custom_colors(const colors& custom_colors) -> color_dialog&;
      
      /// @brief Gets a value indicating whether the controls used to create custom colors are visible when the dialog box is opened
      /// @return `true` if the custom color controls are available when the dialog box is opened; otherwise, `false`. The default value is `false`.
      /// @remarks By default, the custom color controls are not visible when the dialog box is first opened. You must click the Custom Colors button to display them.
      /// @note If allow_full_open is `false`, then full_open has no effect.
      [[nodiscard]] auto full_open() const noexcept -> bool;
      /// @brief Sets a value indicating whether the controls used to create custom colors are visible when the dialog box is opened
      /// @param full_open `true` if the custom color controls are available when the dialog box is opened; otherwise, `false`. The default value is `false`.
      /// @remarks By default, the custom color controls are not visible when the dialog box is first opened. You must click the Custom Colors button to display them.
      /// @note If allow_full_open is `false`, then full_open has no effect.
      auto full_open(bool full_open) -> color_dialog&;
      
      /// @brief Gets values to initialize the color_dialog.
      /// @return A bitwise combination of internal values that initializes the color_dialog.
      /// @remarks The options property corresponds to the flags used to initialize a color dialog box using Win32. Use the properties of the color_dialog class to get and set the options.
      [[nodiscard]] auto options() const noexcept -> xtd::usize;
      
      /// @brief Gets a value indicating whether a Help button appears in the color dialog box.
      /// @return `true` if the Help button is shown in the dialog box; otherwise, `false`. The default value is `false`.
      [[nodiscard]] auto show_help() const noexcept -> bool;
      /// @brief Sets a value indicating whether a Help button appears in the color dialog box.
      /// @param show_help `true` if the Help button is shown in the dialog box; otherwise, `false`.
      auto show_help(bool show_help) -> color_dialog&;
      
      /// @brief Gets a value indicating whether the dialog box will restrict users to selecting solid colors only.
      /// @return `true` if users can select only solid colors; otherwise, `false`. The default value is `false`.
      /// @remarks This property is applicable to systems with 256 or fewer colors. On these types of systems, some colors are composites of others.
      [[nodiscard]] auto solid_color_only() const noexcept -> bool;
      /// @brief Sets a value indicating whether the dialog box will restrict users to selecting solid colors only.
      /// @param solid_color_only `true` if users can select only solid colors; otherwise, `false`.
      /// @remarks This property is applicable to systems with 256 or fewer colors. On these types of systems, some colors are composites of others.
      auto solid_color_only(bool solid_color_only) -> color_dialog&;
      
      /// @brief Gets the color dialog box title.
      /// @return The color dialog box title. The default value is an empty string ("").
      /// @remarks The string is placed in the title bar of the dialog box. If the title is an empty string, the system uses a default title, which is "Color".
      [[nodiscard]] virtual auto title() const noexcept -> const xtd::string&;
      /// @brief Sets the color dialog box title.
      /// @param value The file dialog box title. The default value is an empty string ("").
      /// @return Current file_dialog.
      /// @remarks The string is placed in the title bar of the dialog box. If the title is an empty string, the system uses a default title, which is "Color".
      virtual auto title(const xtd::string& value) -> color_dialog&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Resets all options to their default values, the last selected color to black, and the custom colors to their default values.
      auto reset() noexcept -> void override;
      /// @}
      
    protected:
      /// @name Protected Methods
      
      /// @{
      /// @brief When overridden in a derived class, specifies a common dialog box.
      /// @param owner A value that represents the window handle of the owner window for the common dialog box.
      /// @return `true` if the dialog box was successfully run; otherwise, `false`.
      [[nodiscard]] auto run_dialog(intptr owner) -> bool override;
      
      /// @brief When overridden in a derived class, specifies a common dialog box.
      /// @param owner A value that represents the window handle of the owner window for the common dialog box.
      auto run_sheet(intptr owner) -> void override;
      /// @}
      
    private:
      [[nodiscard]] auto get_option(xtd::usize flag) const noexcept -> bool;
      auto set_option(xtd::usize flag, bool value) -> void;
      
      xtd::sptr<data> data_;
    };
  }
}
