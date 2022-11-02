/// @file
/// @brief Contains xtd::forms::sixteen_segment_display control.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
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
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialize a new instance of nine_segment_display class.
      sixteen_segment_display() = default;
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Sets thickness of segment.
      /// @param value A int32_t that represent the segment thickness.
      /// @return Current seven_segment_display.
      int32_t thickness() const override {return thickness_.value_or(size().height() < 20 ? 1 : (size().height() / 20 + ((size().height() / 20) % 2 ? 0 : 1)));}
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
        fourteen_segment_display::on_paint(e);
        if ((value() & forms::segments::a1) == forms::segments::a1) draw_segment_a1(e.graphics(), fore_color());
        if ((value() & forms::segments::a2) == forms::segments::a2) draw_segment_a2(e.graphics(), fore_color());
        if ((value() & forms::segments::d1) == forms::segments::d1) draw_segment_d1(e.graphics(), fore_color());
        if ((value() & forms::segments::d2) == forms::segments::d2) draw_segment_d2(e.graphics(), fore_color());
      }
      
      void draw_back_digit(drawing::graphics& graphics) override {
        fourteen_segment_display::draw_back_digit(graphics);
        draw_segment_a1(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
        draw_segment_a2(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
        draw_segment_d1(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
        draw_segment_d2(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
      }
      
      /// @brief Draw segment a1 on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_a1(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style() == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), 1 + thickness() / 2 + offset, size().width() / 2 - 1 - abs(offset), 1 + thickness() / 2 + offset);
        } else if (segment_style() == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, 1 + offset, size().width() / 2 - 1 - abs(offset / 2), 1 + offset);
        } else if (segment_style() == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset + thickness() / 2, 1 + thickness() / 2 + offset, size().width() / 2 - 1 - abs(offset), 1 + thickness() / 2 + offset);
        } else if (segment_style() == segment_style::expanded) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, 1 + offset, size().width() / 2 + thickness() / 2 - 1 - (offset > thickness() / 2 ? offset : thickness() / 2), 1 + offset);
        } else if (segment_style() == segment_style::design) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness(), 1 + offset, size().width() / 2 + thickness() / 2 - 1 - (offset > thickness() / 2 ? offset : thickness() / 2), 1 + offset);
        } else if (segment_style() == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness(), 1 + offset, size().width() / 2 - 1, 1 + offset);
        }
      }
      
      /// @brief Draw segment a2 on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_a2(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style() == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), 1 + thickness() / 2 + offset, size().width() - 3 - thickness() / 2 - abs(offset), 1 + thickness() / 2 + offset);
        } else if (segment_style() == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset / 2), 1 + offset, size().width() - 3 - offset, 1 + offset);
        } else if (segment_style() == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), 1 + thickness() / 2 + offset, size().width() - 3 - thickness() / 2 - offset, 1 + thickness() / 2 + offset);
        } else if (segment_style() == segment_style::expanded) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 - thickness() / 2 + (offset > thickness() / 2 ? offset : thickness() / 2), 1 + offset, size().width() - 3 - offset, 1 + offset);
        } else if (segment_style() == segment_style::design) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 - thickness() / 2 + (offset > thickness() / 2 ? offset : thickness() / 2), 1 + offset, size().width() - 3 - thickness(), 1 + offset);
        } else if (segment_style() == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 + 1, 1 + offset, size().width() - 3 - thickness(), 1 + offset);
        }
      }
      
      /// @brief Draw segment d1 on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_d1(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style() == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size().height() - 2 - thickness() / 2 - offset, size().width() / 2 - 1 - abs(offset), size().height() - 2 - thickness() / 2 - offset);
        } else if (segment_style() == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, size().height() - 2 - offset, size().width() / 2 - 1 - abs(offset / 2), size().height() - 2 - offset);
        } else if (segment_style() == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + offset, size().height() - 2 - thickness() / 2 - offset, size().width() / 2 - 1 - abs(offset), size().height() - 2 - thickness() / 2 - offset);
        } else if (segment_style() == segment_style::expanded) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, size().height() - 2 - offset, size().width() / 2 + thickness() / 2 - 1 - (offset > thickness() / 2 ? offset : thickness() / 2), size().height() - 2 - offset);
        } else if (segment_style() == segment_style::design) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness(), size().height() - 2 - offset, size().width() / 2 + thickness() / 2 - 1 - (offset > thickness() / 2 ? offset : thickness() / 2), size().height() - 2 - offset);
        } else if (segment_style() == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness(), size().height() - 2 - offset, size().width() / 2 - 1, size().height() - 2 - offset);
        }
      }
      
      /// @brief Draw segment d2 on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_d2(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style() == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), size().height() - 2 - thickness() / 2 - offset, size().width() - 3 - thickness() / 2 - abs(offset), size().height() - 2 - thickness() / 2 - offset);
        } else if (segment_style() == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset / 2), size().height() - 2 - offset, size().width() - 3 - offset, size().height() - 2 - offset);
        } else if (segment_style() == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), size().height() - 2 - thickness() / 2 - offset, size().width() - 3 - thickness() / 2 - offset, size().height() - 2 - thickness() / 2 - offset);
        } else if (segment_style() == segment_style::expanded) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 - thickness() / 2 + (offset > thickness() / 2 ? offset : thickness() / 2), size().height() - 2 - offset, size().width() - 3 - offset, size().height() - 2 - offset);
        } else if (segment_style() == segment_style::design) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 - thickness() / 2 + (offset > thickness() / 2 ? offset : thickness() / 2), size().height() - 2 - offset, size().width() - 3 - thickness(), size().height() - 2 - offset);
        } else if (segment_style() == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 + 1, size().height() - 2 - offset, size().width() - 3 - thickness(), size().height() - 2 - offset);
        }
      }
      
      /// @brief Draw segment i on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      void draw_segment_i(drawing::graphics& graphics, const drawing::color& color) override {
        if (segment_style() == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() / 2 - 1 - abs(offset));
        } else if (segment_style() == segment_style::modern) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, 2 + abs(2 * offset), size().width() / 2 - offset, size().height() / 2 - 1 - abs(offset));
        } else if (segment_style() == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() / 2 - 1 - abs(offset));
        } else if (segment_style() == segment_style::expanded) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() / 2 - 1 - abs(offset));
        } else if (segment_style() == segment_style::design) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() / 2 - 1 - abs(offset));
        } else if (segment_style() == segment_style::stick) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, 2 + thickness(), size().width() / 2 - offset, size().height() / 2 - 1 - abs(offset));
        }
      }
      
      /// @brief Draw segment l on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      void draw_segment_l(drawing::graphics& graphics, const drawing::color& color) override {
        if (segment_style() == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() - 3 - thickness() / 2 - abs(offset));
        } else if (segment_style() == segment_style::modern) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() - 3 - abs(2 * offset));
        } else if (segment_style() == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() - 3 - thickness() / 2 - abs(offset));
        } else if (segment_style() == segment_style::expanded) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() - 3 - thickness() / 2 - abs(offset));
        } else if (segment_style() == segment_style::design) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() - 3 - thickness() / 2 - abs(offset));
        } else if (segment_style() == segment_style::stick) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() - 3 - thickness());
        }
      }
      /// @}
      
    protected:
      /// @name Protected methods
      
      /// @{
      void draw_segment_a(drawing::graphics& graphics, const drawing::color& color) override {}
      void draw_segment_d(drawing::graphics& graphics, const drawing::color& color) override {}
      /// @}
      
    private:
      std::optional<int32_t> thickness_;
    };
  }
}
