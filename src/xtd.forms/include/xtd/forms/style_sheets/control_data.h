/// @file
/// @brief Contains xtd::forms::style_sheets::control_data class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "box_data.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The control data allow you to specify the box and color of a control.
      /// @code
      /// class forms_export_ control_data : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::control_data
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ control_data : public xtd::object {
      public:
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::control_data class.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        control_data() = default;
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::control_data class with specified box and color.
        /// @param box The box of the control.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        explicit control_data(const xtd::forms::style_sheets::box_data& box);
        
        /// @cond
        control_data(const control_data&) = default;
        control_data(control_data&&) = default;
        control_data& operator=(const control_data&) = default;
        /// @endcond
        
        /// @brief Gets the box of the control.
        /// @return The box of the control.
        virtual const xtd::forms::style_sheets::box_data& box() const noexcept;

        /// @brief Gets the color is used to add text effects to the control.
        /// @return The color is used to add text effects to the control.
        const xtd::forms::style_sheets::color_data& color() const noexcept;

      private:
        xtd::forms::style_sheets::box_data box_;
        xtd::forms::style_sheets::color_data color_ {xtd::drawing::color::black};
      };
    }
  }
}
