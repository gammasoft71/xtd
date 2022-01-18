/// @file
/// @brief Contains xtd::forms::style_sheets::button_data class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "box_data.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The buttton data allow you to specify the box and color of a button.
      /// @code
      /// class forms_export_ button_data : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::button_data
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ button_data : public xtd::object {
      public:
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::buttton_data class.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        /// @remarks The following table shows the default values for the properties :
        /// | Property                                  | Default value                                               |
        /// |-------------------------------------------|-------------------------------------------------------------|
        /// | xtd::forms::style_sheets::box_data::box   | A xtd::forms::style_sheets::box_data initialized by default |
        /// | xtd::forms::style_sheets::box_data::color | xtd::drawing::solid_brush(xtd::drawing::color::white)       |
        button_data() = default;
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::button_data class with specified box and color.
        /// @param box The box of the button.
        /// @param color The fore color is used to add fore effects to the button.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        button_data(const xtd::forms::style_sheets::box_data& box, const std::shared_ptr<xtd::drawing::brush>& color);
        
        /// @cond
        button_data(const button_data&) = default;
        button_data(button_data&&) = default;
        button_data& operator=(const button_data&) = default;
        /// @endcond

        /// @brief Gets the box of the button.
        /// @return The box of the button.
        const xtd::forms::style_sheets::box_data& box() const noexcept;

        /// @brief Gets the fore color is used to add fore effects to the button.
        /// @return The fore color is used to add fore effects to the button.
        const std::shared_ptr<xtd::drawing::brush>& color() const noexcept;

      private:
        xtd::forms::style_sheets::box_data box_;
        std::shared_ptr<xtd::drawing::brush> color_ = std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::color::black);
      };
    }
  }
}
