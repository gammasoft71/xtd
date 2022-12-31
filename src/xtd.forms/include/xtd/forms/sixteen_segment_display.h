/// @file
/// @brief Contains xtd::forms::sixteen_segment_display control.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "fourteen_segment_display.h"

namespace xtd {
  namespace forms {
    /// @brief Represents a sixteen segment display class.
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
    ///     <td>@image html control_sixteen_segment_display_w.png</td>
    ///     <td>@image html control_sixteen_segment_display_m.png</td>
    ///     <td>@image html control_sixteen_segment_display_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html control_sixteen_segment_display_wd.png</td>
    ///     <td>@image html control_sixteen_segment_display_md.png</td>
    ///     <td>@image html control_sixteen_segment_display_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of sixteen segment display control.
    /// @include sixteen_segment_display.cpp
    class sixteen_segment_display : public fourteen_segment_display {
      struct data;
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialize a new instance of nine_segment_display class.
      sixteen_segment_display();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Sets thickness of segment.
      /// @param value A int32 that represent the segment thickness.
      /// @return Current seven_segment_display.
      int32 thickness() const noexcept override;
      /// @brief Sets thickness of segment.
      /// @param value A int32 that represent the segment thickness.
      /// @return Current seven_segment_display.
      seven_segment_display& thickness(int32 value) override;
      /// @}
      
    protected:
      /// @name Protected methods
      
      /// @{
      void draw_back_digit(drawing::graphics& graphics) override;
      
      void draw_segment_a(drawing::graphics& graphics, const drawing::color& color) override;
      
      /// @brief Draw segment a1 on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_a1(drawing::graphics& graphics, const drawing::color& color);
      
      /// @brief Draw segment a2 on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_a2(drawing::graphics& graphics, const drawing::color& color);
      
      void draw_segment_d(drawing::graphics& graphics, const drawing::color& color) override;
      
      /// @brief Draw segment d1 on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_d1(drawing::graphics& graphics, const drawing::color& color);
      
      /// @brief Draw segment d2 on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_d2(drawing::graphics& graphics, const drawing::color& color);
      
      /// @brief Draw segment i on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      void draw_segment_i(drawing::graphics& graphics, const drawing::color& color) override;
      
      /// @brief Draw segment l on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      void draw_segment_l(drawing::graphics& graphics, const drawing::color& color) override;
      
      void on_paint(paint_event_args& e) override;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
