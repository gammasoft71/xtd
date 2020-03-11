#pragma once
#include <xtd/drawing/color.h>
#include <xtd/forms/color_dialog_flags.h>
#include "common_dialog.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays available colors along with controls that enable the user to define custom colors.
    /// @remarks The inherited member show_dialog must be invoked to create this specific common dialog box. hook_proc can be overridden to implement specific dialog box hook functionality. Use color to retrieve the color selected by the user.
    /// @remarks When you create an instance of color_dialog, some of the read/write properties are set to initial values. For a list of these values, see the color_dialog constructor.
    /// @par Example
    /// The following code example demonstrate the use of color_dialog dialog.
    /// @include color_dialog.cpp
    class color_dialog : public common_dialog {
    public:
      /// @brief Initializes a new instance of the color_dialog class.
      /// @remarks When you create an instance of ColorDialog, the following read/write properties are set to initial values.
      /// | Property         | Initial Value         |
      /// |------------------|-----------------------|
      /// | alpha_color      | true                  |
      /// | allow_full_open  | true                  |
      /// | any_color        | false                 |
      /// | color            | drawing::color::black |
      /// | custom_colors    | has no value          |
      /// | full_open        | false                 |
      /// | show_help        | false                 |
      /// | solid_color_only | false                 |
      /// @remarks You can change the value for any of these properties through a separate call to the property.
      color_dialog() = default;
      
      /// @brief Gets a value indicating whether the dialog box  shows alpha values and an opacity selector (slider).
      /// @return true if the dialog box  shows alpha values and an opacity selector (slider); otherwise, false. The default is true.
      bool alpha_color() const {return this->get_option(CC_ALPHACOLOR);}
      /// @brief Sets a value indicating whether the user can use the dialog box to define custom colors.
      /// @param alpha_color true if the dialog box  shows alpha values and an opacity selector (slider); otherwise, false.
      color_dialog& alpha_color(bool alpha_color) {
        this->set_option(CC_ALPHACOLOR, alpha_color);
        return *this;
      }
      
      /// @brief Gets a value indicating whether the user can use the dialog box to define custom colors.
      /// @return true if the user can define custom colors; otherwise, false. The default is true.
      bool allow_full_open() const {return this->get_option(CC_PREVENTFULLOPEN);}
      /// @brief Sets a value indicating whether the user can use the dialog box to define custom colors.
      /// @param allow_full_open true if the user can define custom colors; otherwise, false. The default is true.
      color_dialog& allow_full_open(bool allow_full_open) {
        this->set_option(CC_PREVENTFULLOPEN, allow_full_open);
        return *this;
      }

      /// @brief Gets a value indicating whether the dialog box displays all available colors in the set of basic colors.
      /// @return true if the dialog box displays all available colors in the set of basic colors; otherwise, false. The default value is false.
      bool any_color() const {return this->get_option(CC_ANYCOLOR);}
      /// @breif Sets a value indicating whether the dialog box displays all available colors in the set of basic colors.
      /// @param any_color true if the dialog box displays all available colors in the set of basic colors; otherwise, false. The default value is false.
      color_dialog& any_color(bool any_color) {
        this->set_option(CC_ANYCOLOR, any_color);
        return *this;
      }

      /// @brief Gets the color selected by the user.
      /// @return The color selected by the user. If a color is not selected, the default value is black.
      /// @remarks The color selected by the user in the dialog box at run time, as defined in color structure.
      drawing::color color() const {return this->color_;}
      /// @brief Sets the color selected by the user.
      /// @param color The color selected by the user. If a color is not selected.
      /// @remarks The color selected by the user in the dialog box at run time, as defined in color structure.
      color_dialog& color(const drawing::color& color) {
        this->color_ = color;
        return *this;
      }
      
      /// @brief Gets the set of custom colors shown in the dialog box.
      /// @return A set of custom colors shown by the dialog box. The default value is empty.
      /// @remarks Users can create their own set of custom colors. These colors are contained in an int32_t composed of the BGR (blue, green, red) values necessary to create the color.
      /// @remarks Custom colors can only be defined if allow_full_open is set to true.
      const std::optional<std::vector<int32_t>>& custom_colors() const  {return this->custom_colors_;}
      /// @brief Sets the set of custom colors shown in the dialog box.
      /// @param custom_color A set of custom colors shown by the dialog box.
      /// @remarks Users can create their own set of custom colors. These colors are contained in an int32_t composed of the BGR (blue, green, red) values necessary to create the color.
      /// @remarks Custom colors can only be defined if allow_full_open is set to true.
      color_dialog& custom_colors(const std::vector<int32_t>& custom_colors)  {
        this->custom_colors_ = custom_colors;
        return *this;
      }

      /// @brief Gets a value indicating whether the controls used to create custom colors are visible when the dialog box is opened
      /// @return true if the custom color controls are available when the dialog box is opened; otherwise, false. The default value is false.
      /// @remarks By default, the custom color controls are not visible when the dialog box is first opened. You must click the Custom Colors button to display them.
      /// @note If allow_full_open is false, then full_open has no effect.
      bool full_open() const {return this->get_option(CC_FULLOPEN);}
      /// @brief Sets a value indicating whether the controls used to create custom colors are visible when the dialog box is opened
      /// @param full_open true if the custom color controls are available when the dialog box is opened; otherwise, false. The default value is false.
      /// @remarks By default, the custom color controls are not visible when the dialog box is first opened. You must click the Custom Colors button to display them.
      /// @note If allow_full_open is false, then full_open has no effect.
      color_dialog& full_open(bool full_open) {
        this->set_option(CC_FULLOPEN, full_open);
        return *this;
      }
      
      /// @return Gets values to initialize the color_dialog.
      /// @return A bitwise combination of internal values that initializes the color_dialog.
      /// @return The options property corresponds to the flags used to initialize a color dialog box using Win32. Use the properties of the color_dialog class to get and set the options.
      size_t options() const {return this->options_;}
      
      /// @brief Gets a value indicating whether a Help button appears in the color dialog box.
      /// @return true if the Help button is shown in the dialog box; otherwise, false. The default value is false.
      bool show_help() const {return this->get_option(CC_SHOWHELP);}
      /// @brief Sets a value indicating whether a Help button appears in the color dialog box.
      /// @param show_help true if the Help button is shown in the dialog box; otherwise, false.
      color_dialog& show_help(bool show_help) {
        this->set_option(CC_SHOWHELP, show_help);
        return *this;
      }
      
      /// @brief Gets a value indicating whether the dialog box will restrict users to selecting solid colors only.
      /// @return true if users can select only solid colors; otherwise, false. The default value is false.
      /// @remarks This property is applicable to systems with 256 or fewer colors. On these types of systems, some colors are composites of others.
      bool solid_color_only() const {return this->get_option(CC_SOLIDCOLOR);}
      /// @brief Sets a value indicating whether the dialog box will restrict users to selecting solid colors only.
      /// @param solid_color_only true if users can select only solid colors; otherwise, false.
      /// @remarks This property is applicable to systems with 256 or fewer colors. On these types of systems, some colors are composites of others.
      color_dialog& solid_color_only(bool solid_color_only) {
        this->set_option(CC_SOLIDCOLOR, solid_color_only);
        return *this;
      }

      /// @brief Resets all options to their default values, the last selected color to black, and the custom colors to their default values.
      void reset() override;
      
    protected:
      /// @brief When overridden in a derived class, specifies a common dialog box.
      /// @param owner A value that represents the window handle of the owner window for the common dialog box.
      /// @return true if the dialog box was successfully run; otherwise, false.
      bool run_dialog(intptr_t owner) override;

    private:
      bool get_option(size_t flag) const {return (this->options_ & flag) == flag;}
      void set_option(size_t flag, bool value) {this->options_ = value ? this->options_ | flag : this->options_ & ~flag;}

      drawing::color color_ = drawing::color::black;
      std::optional<std::vector<int32_t>> custom_colors_;
      size_t options_ = CC_ALPHACOLOR | CC_PREVENTFULLOPEN;
    };
  }
}
