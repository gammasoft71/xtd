/// @file
/// @brief Contains xtd::drawing::drawing2d::hatch_brush class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <array>
#include "../../drawing_export.h"
#include "../brush.h"
#include "../color.h"
#include "../image.h"
#include "../point.h"
#include "../rectangle.h"
#include "hatch_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::.drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      /// @brief Encapsulates a xtd::drawing::brush with a linear gradient. This class cannot be inherited.
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing drawing
      class drawing_export_ hatch_brush final : public brush {
      public:
        hatch_brush();
        hatch_brush(xtd::drawing::drawing2d::hatch_style hatch_style, const xtd::drawing::color& fore_color) : hatch_brush(hatch_style, fore_color, xtd::drawing::color::black) {}
        hatch_brush(xtd::drawing::drawing2d::hatch_style hatch_style, const xtd::drawing::color& fore_color, const xtd::drawing::color& back_color);

        /// @cond
        hatch_brush(const hatch_brush& value);
        hatch_brush& operator=(const hatch_brush& value);
        bool operator==(const hatch_brush& value) const {return data_->hatch_style_ == value.data_->hatch_style_ && data_->fore_color_ == value.data_->fore_color_ && data_->back_color_ == value.data_->back_color_;}
        bool operator!=(const hatch_brush& value) const {return !operator==(value);}
        /// @endcond
        
        xtd::drawing::drawing2d::hatch_style hatch_style() const {return data_->hatch_style_;}
        hatch_brush& hatch_style(xtd::drawing::drawing2d::hatch_style hatch_style);
        
        xtd::drawing::color back_color() const {return data_->back_color_;}
        hatch_brush& back_color(xtd::drawing::color back_color);
        
        xtd::drawing::color fore_color() const {return data_->fore_color_;}
        hatch_brush& fore_color(xtd::drawing::color fore_color);

        private:
        void recreate_handle();
        struct data {
          xtd::drawing::drawing2d::hatch_style hatch_style_ = xtd::drawing::drawing2d::hatch_style::horizontal;
          xtd::drawing::color fore_color_;
          xtd::drawing::color back_color_;
        };
        std::shared_ptr<data> data_ = std::make_shared<data>();
      };
    }
  }
}
