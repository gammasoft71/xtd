/// @file
/// @brief Contains xtd::forms::dot_matrix_display control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <array>
#include <xtd/argument_out_of_range_exception.h>
#include <xtd/drawing/solid_brush.h>
#include "control.h"
#include "segments.h"
#include "dot_matrix_style.h"

namespace xtd {
  namespace forms {
    /// @brief represent a dot matrix display class
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of dot matrix display control.
    /// @include dot_matrix_display.cpp
    /// @par Windows
    /// @image html dot_matrix_display_w.png
    /// <br>
    /// @image html dot_matrix_display_wd.png
    /// @par macOS
    /// @image html dot_matrix_display_m.png
    /// <br>
    /// @image html dot_matrix_display_md.png
    /// @par Gnome
    /// @image html dot_matrix_display_g.png
    /// <br>
    /// @image html dot_matrix_display_gd.png
    class dot_matrix_display : public control {
    public:
      /// @brief Represents a dots collection.
      using dots_collection =  std::vector<std::vector<bool>>;
      
      /// @brief Represents a point collection.
      using points_collection =  std::vector<xtd::drawing::point>;
      
      /// @brief Initialize a new instance of dot_matrix_display class.
      dot_matrix_display() {
        auto_size(true);
        double_buffered(true);
        size_ = default_size();
      }

      /// @brief Gets background dot color.
      /// @return A xtd::drawing color that represent the background dot color.
      /// @remarks Do not confuse back_dot_color and back_color. Background dot color is the color when dot is off.
      virtual drawing::color back_dot_color() {return back_dot_color_.value_or(fore_color());}
      /// @brief Sets background dot color.
      /// @param value A xtd::drawing color that represent the background dot color.
      /// @return Current dot_matrix_display.
      /// @remarks Do not confuse back_dot_color and back_color. Background dot color is the color when dot is off.
      virtual dot_matrix_display& back_dot_color(const drawing::color& value) {
        if (!back_dot_color_.has_value() || back_dot_color_.value() != value) {
          back_dot_color_ = value;
          invalidate();
        }
        return *this;
      }

      /// @brief Gets the background dot opacity.
      /// @return A double-precision value between 0.0 and 1.0 that represent the background dot opacity.
      virtual double back_dot_opacity() const {return back_dot_opacity_;}
      /// @brief Sets the background dot opacity.
      /// @param value A double-precision value between 0.0 and 1.0 that represent the background dot opacity.
      /// @exception xtd::argument_out_of_range_exception if value less than 0.0 or greater than 1.0.
      /// @return Current dot_matrix_display.
      virtual dot_matrix_display& back_dot_opacity(double value) {
        if (value < 0.0 || value > 1.0) throw argument_out_of_range_exception("value must be between 0.0 and 1.0."_t, current_stack_frame_);
        if (back_dot_opacity_ != value) {
          back_dot_opacity_ = value;
          if (back_dot_opacity_ < 0.0) back_dot_opacity_ = 0.0;
          if (back_dot_opacity_ > 1.0) back_dot_opacity_ = 1.0;
          invalidate();
        }
        return *this;
      }

      /// @brief Gets dot matrix style.
      /// @return One of xtd::forms::dot_matrix_style values. The default is xtd::forms::dot_matrix_style::standard.
      virtual forms::dot_matrix_style dot_matrix_style() const {return dot_matrix_style_;}
      /// @brief Sets dot matrix style.
      /// @param value One of xtd::forms::dot_matrix_style values. The default is xtd::forms::dot_matrix_style::standard.
      /// @return Current dot_matrix_display.
      virtual dot_matrix_display& dot_matrix_style(forms::dot_matrix_style value) {
        if (dot_matrix_style_ != value) {
          dot_matrix_style_ = value;
          invalidate();
        }
        return *this;
      }

      /// @brief Gets all dots status.
      /// @return A dots_colllection that represent all dots status.
      virtual const dots_collection& dots() const {return dots_;}
      /// @brief Sets all dots status.
      /// @param dots A dots_colllection that represent all dots status.
      /// @return Current dot_matrix_display.
      virtual const dot_matrix_display& dots(const dots_collection& dots) {
        if (dots_ != dots) {
          dots_ = dots;
          matrix_size_ = drawing::size(static_cast<int32_t>(dots_[0].size()), static_cast<int32_t>(dots_.size()));
          invalidate();
        }
        return *this;
      }

      /// @brief Gets the matrix size. Number of height dots.
      /// @return A int32_t represent the height dots of the matrix. The default is 7.
      virtual int32_t matrix_height() const {return matrix_size_.height();}
      /// @brief Sets the matrix size. Number of height dots.
      /// @param value A int32_t represent the height dots of the matrix. The default is 7.
      /// @return Current dot_matrix_display.
      virtual void matrix_height(int32_t value) {matrix_size({matrix_size_.width(), value});}
      
      /// @brief Gets the matrix size. Number height dots.
      /// @return A int32_t that represent the width dots of the matrix. The default is 7.
      virtual int32_t matrix_width() const {return matrix_size_.width();}
      /// @brief Sets the matrix size. Number height dots.
      /// @param value A int32_t that represent the width dots of the matrix. The default is 7.
      /// @return Current dot_matrix_display.
      virtual void matrix_width(int32_t value) {matrix_size({value, matrix_size_.height()});}
      
      /// @brief Gets the matrix size. Number of width and height dots.
      /// @return A xtd::drawing::point that represent the width and height dots of the matrix. The default is {7, 7}.
      virtual const drawing::size& matrix_size() const {return matrix_size_;}
      /// @brief Gets the matrix size. Number of width and height dots.
      /// @param value A xtd::drawing::point that represent the width and height dots of the matrix. The default is {7, 7}. The default is {7, 7}.
      /// @return Current dot_matrix_display.
      virtual void matrix_size(const drawing::size& value) {
        if (matrix_size_ != value) {
          matrix_size_ = value;
          dots_ = dots_collection(matrix_size_.height(), std::vector<bool>(matrix_size_.width(), false));
          invalidate();
        }
      }

      /// @brief Gets a value indicate if background dots are shown.
      /// @return true if background dots are shown; otherwise false
      virtual bool show_back_dot() const {return show_back_dot_;}
      /// @brief Sets a value indicate if background dots are shown.
      /// @param value true if background dots arrer shown; otherwise false
      /// @return Current dot_matrix_display.
      virtual dot_matrix_display& show_back_dot(bool value) {
        if (show_back_dot_ != value) {
          show_back_dot_ = value;
          invalidate();
        }
        return *this;
      }

      /// @brief Gets thickness of dot.
      /// @return A int32_t that represent the dot tickness.
      virtual int32_t thickness() const {return thickness_.value_or(size_.height() < (matrix_size_.height() * 2) ? 1 : (size_.height() - matrix_size_.height()) / matrix_size_.height());}
      /// @brief Sets thickness of dot.
      /// @param value A int32_t that represent the dot tickness.
      /// @return Current dot_matrix_display.
      virtual dot_matrix_display& thickness(int32_t value) {
        if (!thickness_.has_value() || thickness_.value() != value) {
          thickness_ = value;
          invalidate();
        }
        return *this;
      }

      /// @brief Sets all dots with specified boolean.
      /// @param on true to set all dots to on; otherwise false.
      virtual void set_all_dots(bool on) {
        for (int32_t y = 0; y < static_cast<int32_t>(dots_.size()); y++)
          for (int32_t x = 0; x < static_cast<int32_t>(dots_[y].size()); x++)
            dots_[y][x] = on;
      }
      
      /// @brief Gets specified dot point status.
      /// @param point dot point location in the matrix.
      /// @return true if specified dot point is on; otherwise false.
      virtual bool get_dot(const drawing::point& point) const {return dots_[point.y()][point.x()];}
      
      /// @brief Sets specified dot point status.
      /// @param point dot point location in the matrix.
      /// @param on true if specified dot point is on; otherwise false.
      virtual void set_dot(const drawing::point& point, bool on) {
        if (dots_[point.y()][point.x()] != on) {
          dots_[point.y()][point.x()] = on;
          invalidate();
        }
      }

      /// @brief Sets specified dots to on.
      /// @param points Dot points collection tha contains locations in the matrix.
      virtual void set_dots(const points_collection& points) {
        set_all_dots(false);
        set_dots(points, true);
      }
      /// @brief Sets specified dots with specified boolean.
      /// @param points Dot points collection tha contains locations in the matrix.
      /// @param on true to set pecified dots points to on; otherwise false.
      virtual void set_dots(const points_collection& points, bool on) {
        for (auto point : points)
          set_dot(point, on);
      }

    protected:
      drawing::size default_size() const override {return {25, 25};}
      
      void on_back_color_changed(const event_args& e) override {
        control::on_back_color_changed(e);
        invalidate();
      }
      
      void on_fore_color_changed(const event_args& e) override {
        control::on_fore_color_changed(e);
        invalidate();
      }

      void on_paint(paint_event_args& e) override {
        if (back_color() != default_back_color()) e.graphics().clear(back_color());
        for (int32_t y = 0; y < static_cast<int32_t>(dots_.size()); y++) {
          for (int32_t x = 0; x < static_cast<int32_t>(dots_[y].size()); x++) {
            if (dots_[y][x]) draw_dot(e.graphics(), fore_color(), {x, y});
            else if (show_back_dot_) draw_dot(e.graphics(), drawing::color::average(back_dot_color(), back_color(), back_dot_opacity_), {x, y});
          }
        }
        control::on_paint(e);
      }
      
      drawing::size measure_control() const override {
        int32_t width = static_cast<int32_t>(static_cast<double>(height()) / matrix_height() * matrix_width());
        return drawing::size(width, height());
      }

      /// @brief Draw specified dot point with specified color on specified graphics.
      /// @param graphics DEfine the conrol graphics where draw the specified dot point.
      /// @param color The dot color to draw.
      /// @param point The dot point location in the matrix.
      virtual void draw_dot(drawing::graphics& graphics, const drawing::color& color, const drawing::point& point) {
        int32_t y = (height() - static_cast<int32_t>(dots_.size())) / static_cast<int32_t>(dots_.size());
        int32_t x = (width() - static_cast<int32_t>(dots_[point.y()].size()))  / static_cast<int32_t>(dots_[point.y()].size());
        if (dot_matrix_style_ == dot_matrix_style::standard)
          graphics.fill_pie(drawing::solid_brush(color), (1 + x) * point.x(), (1 + y) * point.y(), thickness(), thickness(), 0, 360);
        else if (dot_matrix_style_ == dot_matrix_style::square)
          graphics.fill_rectangle(drawing::solid_brush(color), (1 + x) * point.x(), (1 + y) * point.y(), thickness(), thickness());
      }

      /// @cond
      drawing::size matrix_size_ = {7, 7};
      dots_collection dots_ = dots_collection(matrix_size_.width(), std::vector<bool>(matrix_size_.height(), false));
      bool show_back_dot_ = true;
      std::optional<drawing::color> back_dot_color_;
      double back_dot_opacity_ = 0.95;
      forms::dot_matrix_style dot_matrix_style_ = forms::dot_matrix_style::standard;
      std::optional<int32_t> thickness_;
      /// @endcond
    };
  }
}
