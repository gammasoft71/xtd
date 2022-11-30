/// @file
/// @brief Contains xtd::forms::nine_segment_display control.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "seven_segment_display.h"

namespace xtd {
  namespace forms {
    /// @brief Represents a nine segment display class.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
    ///   <tr>
    ///     <th style="width:100px"></th>
    ///     <th><b>Windows</b></th>
    ///     <th><b>macOS</b></th>
    ///     <th><b>Gnome</b></th>
    ///   </tr>
    ///   <tr>
    ///     <th>Light</th>
    ///     <td>@image html control_nine_segment_display_w.png</td>
    ///     <td>@image html control_nine_segment_display_m.png</td>
    ///     <td>@image html control_nine_segment_display_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html control_nine_segment_display_wd.png</td>
    ///     <td>@image html control_nine_segment_display_md.png</td>
    ///     <td>@image html control_nine_segment_display_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of nine segment display control.
    /// @include nine_segment_display.cpp
    class nine_segment_display : public seven_segment_display {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialize a new instance of nine_segment_display class.
      nine_segment_display() = default;
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Sets thickness of segment.
      /// @param value A int32_t that represent the segment thickness.
      /// @return Current seven_segment_display.
      int32_t thickness() const noexcept override;
      /// @brief Sets thickness of segment.
      /// @param value A int32_t that represent the segment thickness.
      /// @return Current seven_segment_display.
      seven_segment_display& thickness(int32_t value) override;
      /// @}
      
    protected:
      /// @name Protected methods
      
      /// @{
      void draw_back_digit(drawing::graphics& graphics) override;
      
      /// @brief Draw segment h on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_h(drawing::graphics& graphics, const drawing::color& color);
      
      /// @brief Draw segment ion specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_i(drawing::graphics& graphics, const drawing::color& color);

      void on_paint(paint_event_args& e) override;
      /// @}
      
    private:
      struct data {
        std::optional<int32_t> thickness;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}

