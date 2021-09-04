/// @file
/// @brief Contains xtd::forms::seven_segment_display control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/argument_out_of_range_exception.h>
#include <xtd/drawing/system_colors.h>
#include "control.h"
#include "segments.h"
#include "segment_style.h"

namespace xtd {
  namespace forms {
    /// @brief represent a seven segment display class
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Example
    /// The following code example demonstrate the use of seven segment display control.
    /// @include seven_segment_display.cpp
    class seven_segment_display : public control {
    public:
      /// @brief Initialize a new instance of seven_segment_display class.
      seven_segment_display() {
        double_buffered(true);
        size_ = default_size();
      }

      /// @brief Gets background segment color.
      /// @return A xtd::drawing color that represent the background segment color.
      /// @remarks Do not confuse back_segment_color and back_color. Background segment color is the color when segment is off.
      virtual drawing::color back_segment_color() {return back_segment_color_.value_or(fore_color());}
      /// @brief Sets background segment color.
      /// @param value A xtd::drawing color that represent the background segment color.
      /// @return Current seven_segment_display.
      /// @remarks Do not confuse back_segment_color and back_color. Background segment color is the color when segment is off.
      virtual seven_segment_display& back_segment_color(const drawing::color& value) {
        if (!back_segment_color_.has_value() || back_segment_color_.value() != value) {
          back_segment_color_ = value;
          invalidate();
        }
        return *this;
      }

      /// @brief Gets the background segment opacity.
      /// @return A double-precision value between 0.0 and 1.0 that represent the background segment opacity.
      virtual double back_segment_opacity() const {return back_segment_opacity_;}
      /// @brief Sets the background segment opacity.
      /// @param value A double-precision value between 0.0 and 1.0 that represent the background segment opacity.
      /// @exception xtd::argument_out_of_range_exception if value less than 0.0 or greater than 1.0.
      /// @return Current seven_segment_display.
      virtual seven_segment_display& back_segment_opacity(double value) {
        if (value < 0.0 || value > 1.0) throw argument_out_of_range_exception("value must be between 0.0 and 1.0."_t, current_stack_frame_);
        if (back_segment_opacity_ != value) {
          back_segment_opacity_ = value;
          invalidate();
        }
        return *this;
      }
      
      /// @brief Gets a value indicate if background segments are shown.
      /// @return true if background segments are shown; otherwise false
      virtual bool show_back_segment() const {return show_back_segment_;}
      /// @brief Sets a value indicate if background segments are shown.
      /// @param value true if background segments are shown; otherwise false
      /// @return Current seven_segment_display.
      virtual seven_segment_display& show_back_segment(bool value) {
        if (show_back_segment_ != value) {
          show_back_segment_ = value;
          invalidate();
        }
        return *this;
      }
      
      /// @brief Gets segment style.
      /// @return One of xtd::forms::segment_style values. The default is xtd::forms::segment_style::standard.
      virtual forms::segment_style segment_style() const {return segment_style_;}
      /// @brief Sets segment style.
      /// @param value One of xtd::forms::segment_style values. The default is xtd::forms::segment_style::standard.
      /// @return Current seven_segment_display.
      virtual seven_segment_display& segment_style(forms::segment_style value) {
        if (segment_style_ != value) {
          segment_style_ = value;
          invalidate();
        }
        return *this;
      }
      
      /// @brief Gets thickness of segment.
      /// @return A int32_t that represent the segment tickness.
      virtual int32_t thickness() const {return thickness_.value_or(size_.height() < 10 ? 1 : (size_.height() / 10 + ((size_.height() / 10) % 2 ? 0 : 1)));}
      /// @brief Sets thickness of segment.
      /// @param value A int32_t that represent the segment tickness.
      /// @return Current seven_segment_display.
      virtual seven_segment_display& thickness(int32_t value) {
        if (!thickness_.has_value() || thickness_.value() != value) {
          thickness_ = value;
          invalidate();
        }
        return *this;
      }

      /// @brief Gets seven_segment_display value.
      /// @return A xtd::forms::segments cominaison that represent seven_segment_display.
      virtual forms::segments value() const {return value_;}
      /// @brief Sets seven_segment_display value.
      /// @param value A xtd::forms::segments cominaison that represent seven_segment_display.
      /// @return Current seven_segment_display.
      virtual seven_segment_display& value(forms::segments value) {
        if (value_ != value) {
          value_ = value;
          invalidate();
        }
        return *this;
      }

      /// @brief Gets if specified xtd::forms::segments combinaison is on.
      /// @return true if xtd::forms::segments combinaison is on; otherwise false.
      virtual bool get_segments(forms::segments segment) const {return (value_ & segment) == segment;}
      /// @brief Sets specified xtd::forms::segments combinaison to on.
      /// @param segment A xtd::forms::segments combinaison to set.
      /// @param on true to set to on; otherwise false.
      virtual void set_segments(forms::segments segment, bool value) { value_ = value ? (value_ | segment) : (value_ & ~segment); }

    protected:
      drawing::size default_size() const override {return {13, 25};}

      void on_back_color_changed(const event_args& e) override {
        control::on_back_color_changed(e);
        invalidate();
      }
      
      void on_enabled_changed(const event_args& e) override {
        control::on_enabled_changed(e);
        invalidate();
      }
      
      void on_fore_color_changed(const event_args& e) override {
        control::on_fore_color_changed(e);
        invalidate();
      }
      
      void on_paint(paint_event_args& e) override {
        control::on_paint(e);
        if (back_color() != default_back_color()) e.graphics().clear(back_color());
        if (show_back_segment_) draw_back_digit(e.graphics());
        auto color = enabled() ? fore_color() : drawing::system_colors::gray_text();
        if ((value_ & forms::segments::dp) == forms::segments::dp) draw_dp(e.graphics(), color);
        if ((value_ & forms::segments::pc) == forms::segments::pc) draw_pc(e.graphics(), color);
        if ((value_ & forms::segments::a) == forms::segments::a) draw_segment_a(e.graphics(), color);
        if ((value_ & forms::segments::b) == forms::segments::b) draw_segment_b(e.graphics(), color);
        if ((value_ & forms::segments::c) == forms::segments::c) draw_segment_c(e.graphics(), color);
        if ((value_ & forms::segments::d) == forms::segments::d) draw_segment_d(e.graphics(), color);
        if ((value_ & forms::segments::e) == forms::segments::e) draw_segment_e(e.graphics(), color);
        if ((value_ & forms::segments::f) == forms::segments::f) draw_segment_f(e.graphics(), color);
        if ((value_ & forms::segments::g) == forms::segments::g) draw_segment_g(e.graphics(), color);
      }
      
      void on_parent_enabled_changed(const event_args& e) override {
        control::on_parent_enabled_changed(e);
        invalidate();
      }

      drawing::size measure_control() const override {
        return drawing::size((height() - 3) / 2 + 2, height());
      }
    
      void set_bounds_core(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified) override {
        if ((specified & bounds_specified::width) == forms::bounds_specified::width && (specified & bounds_specified::height) != forms::bounds_specified::height) {
          height = (width - 2) * 2 + 3;
          specified |= bounds_specified::height;
        }
        if ((specified & bounds_specified::height) == forms::bounds_specified::height) {
          width = (height - 3) / 2 + 2;
          specified |= bounds_specified::width;
        }
        control::set_bounds_core(x, y, width, height, specified);
      }
            
      void set_client_size_core(int32_t width, int32_t height) override {
        if (client_size_.height() != height)
          width = (height - 3) / 2 + 2;
        if (client_size_.width() != width)
          height = (width - 2) * 2 + 3;
        control::set_client_size_core(width, height);
      }

      /// @brief Draw all background digit on specified graphics.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      virtual void draw_back_digit(drawing::graphics& graphics) {
        auto color = enabled() ? drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()) : back_color();
        draw_segment_a(graphics, color);
        draw_segment_b(graphics, color);
        draw_segment_c(graphics, color);
        draw_segment_d(graphics, color);
        draw_segment_e(graphics, color);
        draw_segment_f(graphics, color);
        draw_segment_g(graphics, color);
      }

      /// @brief Draw segment a on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segemnt.
      virtual void draw_segment_a(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), 1 + thickness() / 2 + offset, size_.width() - 3 - thickness() / 2 - abs(offset), 1 + thickness() / 2 + offset);
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, 1 + offset, size_.width() - 3 - offset, 1 + offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, 1 + offset, size_.width() - 3 - offset, 1 + offset);
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, 1 + offset, size_.width() - 3 - offset, 1 + offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness(), 1 + offset, size_.width() - 3 - thickness(), 1 + offset);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness(), 1 + offset, size_.width() - 3 - thickness(), 1 + offset);
        }
      }
      
      /// @brief Draw segment b on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segemnt.
      virtual void draw_segment_b(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, 2 + thickness() / 2 + abs(offset), size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 - 1 - abs(offset));
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - offset, 2 + offset, size_.width() - 2 - offset, size_.height() / 2 - 1 - offset / 2);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, 2 + offset + thickness() / 2, size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 - 1 - abs(offset));
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, 2 + offset + thickness() / 2, size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 - 1 - (offset > 0 ? offset : 0));
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, 1, size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 - 1 - (offset > 0 ? offset : 0));
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, 1, size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 - 1);
        }
      }
      
      /// @brief Draw segment c on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segemnt.
      virtual void draw_segment_c(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size_.width() - 2 - thickness() / 2 - offset, size_.height() - 3 - thickness() / 2 - abs(offset));
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - offset, size_.height() / 2 + 1 + offset / 2,  size_.width() - 2 - offset, size_.height() - 3 - offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size_.width() - 2 - thickness() / 2 - offset, size_.height() - 3 - thickness() / 2 - offset);
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + (offset > 0 ? offset : 0), size_.width() - 2 - thickness() / 2 - offset, size_.height() - 3 - thickness() / 2 - offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + (offset > 0 ? offset : 0), size_.width() - 2 - thickness() / 2 - offset, size_.height() - 2);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 + 1, size_.width() - 2 - thickness() / 2 - offset, size_.height() - 2);
        }
      }
      
      /// @brief Draw segment d on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segemnt.
      virtual void draw_segment_d(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size_.height() - 2 - thickness() / 2 - offset, size_.width() - 3 - thickness() / 2 - abs(offset), size_.height() - 2 - thickness() / 2 - offset);
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, size_.height() - 2 - offset, size_.width() - 3 - offset, size_.height() - 2 - offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, size_.height() - 2 - offset, size_.width() - 3 - offset, size_.height() - 2 - offset);
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, size_.height() - 2 - offset, size_.width() - 3 - offset, size_.height() - 2 - offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness(), size_.height() - 2 - offset, size_.width() - 3 - thickness(), size_.height() - 2 - offset);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness(), size_.height() - 2 - offset, size_.width() - 3 - thickness(), size_.height() - 2 - offset);
        }
      }

      /// @brief Draw segment e on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segemnt.
      virtual void draw_segment_e(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), 1 + thickness() / 2 + offset, size_.height() - 3 - thickness() / 2 - abs(offset));
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 1 + offset, size_.height() / 2 + 1 + offset / 2, 1 + offset, size_.height() - 3 - offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), 1 + thickness() / 2 + offset, size_.height() - 3 - thickness() / 2 - offset);
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + (offset > 0 ? offset : 0), 1 + thickness() / 2 + offset, size_.height() - 3 - thickness() / 2 - offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + (offset > 0 ? offset : 0), 1 + thickness() / 2 + offset, size_.height() - 2);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, size_.height() / 2 + 1, 1 + thickness() / 2 + offset, size_.height() - 2);
        }
      }

      /// @brief Draw segment f on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segemnt.
      virtual void draw_segment_f(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, 2 + thickness() / 2 + abs(offset), 1 + thickness() / 2 + offset, size_.height() / 2 - 1 - abs(offset));
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 1 + offset, 2 + offset, 1 + offset, size_.height() / 2 - 1 - offset / 2);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, 2 + thickness() / 2 + offset, 1 + thickness() / 2 + offset, size_.height() / 2 - 1 - abs(offset));
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, 2 + thickness() / 2 + offset, 1 + thickness() / 2 + offset, size_.height() / 2 - 1 - (offset > 0 ? offset : 0));
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, 1, 1 + thickness() / 2 + offset, size_.height() / 2 - 1 - (offset > 0 ? offset : 0));
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, 1, 1 + thickness() / 2 + offset, size_.height() / 2 - 1);
        }
      }

      /// @brief Draw segment g on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segemnt.
      virtual void draw_segment_g(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size_.height() / 2 + offset, size_.width() - 3 - thickness() / 2 - abs(offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + abs(2 * offset), size_.height() / 2 + offset, size_.width() - 3 - abs(2 * offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size_.height() / 2 + offset, size_.width() - 3 - thickness() / 2 - abs(offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size_.height() / 2 + offset, size_.width() - 3 - thickness() / 2 - abs(offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size_.height() / 2 + offset, size_.width() - 3 - thickness() / 2 - abs(offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness(), size_.height() / 2 + offset, size_.width() - 3 - thickness(), size_.height() / 2 + offset);
        }
      }

      /// @brief Draw segment dot point on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segemnt.
      virtual void draw_dp(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() - 1 - thickness(), thickness(), thickness());
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - thickness() / 2, size_.height() - 2 - offset, size_.width() / 2 + thickness() / 2, size_.height() - 2 - offset);
        } else if (segment_style_ == segment_style::mixed) {
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() - 1 - thickness(), thickness(), thickness());
        } else if (segment_style_ == segment_style::expanded) {
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() - 1 - thickness(), thickness(), thickness());
        } else if (segment_style_ == segment_style::design) {
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() - 1 - thickness(), thickness(), thickness());
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - thickness() / 2, size_.height() - 2 - offset, size_.width() / 2 + thickness() / 2, size_.height() - 2 - offset);
        }
      }
      
      /// @brief Draw segment punctuation colon on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segemnt.
      virtual void draw_pc(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 - thickness() / 2, thickness(), thickness());
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 * 2 - thickness() / 2, thickness(), thickness());
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++) {
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 - thickness() / 2 + offset, size_.width() / 2 + thickness() / 2, size_.height() / 3 - thickness() / 2 + offset);
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - thickness() / 2, size_.height() /3 * 2 - thickness() / 2 + offset, size_.width() / 2 + thickness() / 2, size_.height() / 3 * 2 - thickness() / 2 + offset);
          }
        } else if (segment_style_ == segment_style::mixed) {
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 - thickness() / 2, thickness(), thickness());
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 * 2 - thickness() / 2, thickness(), thickness());
        } else if (segment_style_ == segment_style::expanded) {
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 - thickness() / 2, thickness(), thickness());
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 * 2 - thickness() / 2, thickness(), thickness());
        } else if (segment_style_ == segment_style::design) {
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 - thickness() / 2, thickness(), thickness());
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 * 2 - thickness() / 2, thickness(), thickness());
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness(); offset++) {
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 - thickness() / 2 + offset, size_.width() / 2 + thickness() / 2, size_.height() / 3 - thickness() / 2 + offset);
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - thickness() / 2, size_.height() /3 * 2 - thickness() / 2 + offset, size_.width() / 2 + thickness() / 2, size_.height() / 3 * 2 - thickness() / 2 + offset);
          }
        }
      }

      /// @cond
      forms::segments value_ = forms::segments::none;
      bool show_back_segment_ = true;
      std::optional<drawing::color> back_segment_color_;
      double back_segment_opacity_ = 0.95;
      forms::segment_style segment_style_ = forms::segment_style::standard;
      std::optional<int32_t> thickness_;
      /// @endcond
    };
  }
}
