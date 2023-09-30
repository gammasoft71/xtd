/// @file
/// @brief Contains xtd::forms::style_sheets::iimage_model class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "text_decoration.h"
#include "text_transformation.h"
#include <xtd/drawing/color>
#include <xtd/drawing/font>
#include <xtd/drawing/string_format>
#include <xtd/drawing/system_fonts>
#include <xtd/forms/content_alignment>
#include <xtd/interface>
#include <xtd/ustring>
#include <memory>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The image model allows you to specify the alignment  of an image.
      /// @code
      /// class iimage_model interface_
      /// @endcode
      /// @par Inheritance
      /// xtd::interface → xtd::forms::style_sheets::iimage_model
      /// @par Header
      /// @code #include <xtd/forms/style_sheets/iimage_model> @endcode
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets interfaces
      /// @remarks This class is used by xtd::forms::style_sheets::text_renderer.
      class iimage_model interface_ {
      public:
        /// @name Properties
        
        /// @{
        /// @brief Gets the alignment of the image.
        /// @return A combination of xtd::forms::content_alignment values.
        virtual xtd::forms::content_alignment image_alignment() const noexcept = 0;
      };
    }
  }
}
