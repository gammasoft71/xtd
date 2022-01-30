/// @file
/// @brief Contains xtd::forms::style_sheets::itext_model class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <xtd/interface.h>
#include <xtd/ustring.h>
#include <xtd/drawing/color.h>
#include <xtd/drawing/font.h>
#include <xtd/drawing/string_format.h>
#include <xtd/drawing/system_fonts.h>
#include <xtd/forms/content_alignment.h>
#include "text_decoration.h"
#include "text_transformation.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The text model allows you to specify the alignment, color, decoration, transformation, and font of a text.
      /// @code
      /// class itext_model interface_
      /// @endcode
      /// @par Inheritance
      /// xtd::interface → xtd::forms::style_sheets::itext_model
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets interfaces
      /// @remarks This class is used by xtd::forms::style_sheets::text_renderer.
      class itext_model interface_ {
      public:
        /// @name Properties
        
        /// @{
        /// @brief Gets the alignment of the text.
        /// @return A combination of xtd::forms::content_alignment values.
        virtual xtd::forms::content_alignment alignment() const noexcept = 0;
        /// @brief Sets the alignment of the text.
        /// @param value A combination of xtd::forms::content_alignment values.
        virtual void alignment(xtd::forms::content_alignment value) noexcept = 0;

        /// @brief Gets the color is used to add foreground effects to the text.
        /// @return The color is used to add foreground effects to the text.
        virtual const xtd::drawing::color& color() const noexcept = 0;
        /// @brief Sets the color is used to add foreground effects to the text.
        /// @param value The color is used to add foreground effects to the text.
        virtual void color(const xtd::drawing::color& value) noexcept = 0;
        
        /// @brief Gets the decoration of the text.
        /// @return One of xtd::forms::style_sheets::text_decoration values.
        virtual xtd::forms::style_sheets::text_decoration decoration() const noexcept = 0;
        /// @brief Sets the decoration of the text.
        /// @param value One of xtd::forms::style_sheets::text_decoration values.
        virtual void decoration(xtd::forms::style_sheets::text_decoration value) noexcept = 0;

        /// @brief Gets the transformation of the text.
        /// @return One of xtd::forms::style_sheets::text_transformation values.
        virtual xtd::forms::style_sheets::text_transformation transformation() const noexcept = 0;
        /// @brief Sets the transformation of the text.
        /// @param value One of xtd::forms::style_sheets::text_transformation values.
        virtual void transformation(xtd::forms::style_sheets::text_transformation value) noexcept = 0;

        /// @brief Gets the font of the text.
        /// @return The font of the text.
        virtual const xtd::drawing::font& font() const noexcept = 0;
        /// @brief Sets the font of the text.
        /// @param value The font of the text.
        virtual void font(const xtd::drawing::font& value) noexcept = 0;

        /// @brief Gets the string format of the text.
        /// @return The string format used by xtd::drawing::graphics::draw_text method to draw a text.
        virtual xtd::drawing::string_format make_string_format() const noexcept = 0;
      };
    }
  }
}
