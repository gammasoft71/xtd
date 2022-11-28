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
      int32_t thickness() const noexcept override {return thickness_.value_or(size().height() < 20 ? 1 : (size().height() / 20 + ((size().height() / 20) % 2 ? 0 : 1)));}
      /// @brief Sets thickness of segment.
      /// @param value A int32_t that represent the segment thickness.
      /// @return Current seven_segment_display.
      seven_segment_display& thickness(int32_t value) override {
        if (!thickness_.has_value() || thickness_.value() != value) {
          thickness_ = value;
          invalidate();
        }
        return *this;
      }
      /// @}
      
    protected:
      /// @name Protected methods
      
      /// @{
      void on_paint(paint_event_args& e) override {
        seven_segment_display::on_paint(e);
        if ((value() & forms::segments::h) == forms::segments::h) draw_segment_h(e.graphics(), fore_color());
        if ((value() & forms::segments::i) == forms::segments::i) draw_segment_i(e.graphics(), fore_color());
      }
      
      void draw_back_digit(drawing::graphics& graphics) override {
        seven_segment_display::draw_back_digit(graphics);
        draw_segment_h(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
        draw_segment_i(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
      }
      
      /// @brief Draw segment h on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_h(drawing::graphics& graphics, const drawing::color& color) {
        for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
          graphics.draw_line(drawing::pen(color), size().width() - 3 - thickness() - abs(offset), 2 + thickness(), 2 + thickness(), size().height() / 2 - 2 - thickness() / 2 - abs(offset));
          graphics.draw_line(drawing::pen(color), size().width() - 3 - thickness(), 2 + thickness() + abs(offset), 2 + thickness() + abs(offset), size().height() / 2 - 2 - thickness() / 2);
        }
      }
      
      /// @brief Draw segment ion specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_i(drawing::graphics& graphics, const drawing::color& color) {
        for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
          graphics.draw_line(drawing::pen(color), size().width() - 3 - thickness() - abs(offset), size().height() / 2 + 2 + thickness() / 2, 2 + thickness(), size().height() - 3 - thickness() - abs(offset));
          graphics.draw_line(drawing::pen(color), size().width() - 3 - thickness(), size().height() / 2 + 2 + thickness() / 2 + abs(offset), 2 + thickness() + abs(offset), size().height() - 3 - thickness());
        }
      }
      /// @}
      
    private:
      std::optional<int32_t> thickness_;
    };
  }
}

