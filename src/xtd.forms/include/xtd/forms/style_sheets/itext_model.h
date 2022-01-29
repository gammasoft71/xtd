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
      class itext_model interface_ {
      public:
        virtual xtd::forms::content_alignment alignment() const noexcept = 0;
        virtual void alignment(xtd::forms::content_alignment value) noexcept = 0;

        virtual const xtd::drawing::color& color() const noexcept = 0;
        virtual void color(const xtd::drawing::color& value) noexcept = 0;
        
        virtual xtd::forms::style_sheets::text_decoration decoration() const noexcept = 0;
        virtual void decoration(xtd::forms::style_sheets::text_decoration value) noexcept = 0;

        virtual xtd::forms::style_sheets::text_transformation transformation() const noexcept = 0;
        virtual void transformation(xtd::forms::style_sheets::text_transformation value) noexcept = 0;

        virtual const xtd::drawing::font& font() const noexcept = 0;
        virtual void font(const xtd::drawing::font& value) noexcept = 0;

        virtual xtd::drawing::string_format make_string_format() const noexcept = 0;
      };
    }
  }
}
