#pragma once
#include <array>
#include "control.hpp"
#include "segments.hpp"
#include "dot_matrix_style.hpp"

namespace xtd {
  namespace forms {
    /// @brief represent a dot matrix display class
    class dot_matrix_display : public control {
    public:
      using dot = drawing::point;
      using dot_collection =  std::vector<dot>;

      dot_matrix_display() {
        size_ = default_size();
      }

      virtual drawing::color background_dot_color() {return background_dot_color_.value_or(drawing::color::average(fore_color(), back_color(), background_dot_transparency_));}
      virtual dot_matrix_display& background_dot_color(const drawing::color& value) {
        if (!background_dot_color_.has_value() || background_dot_color_.value() != value) {
          background_dot_color_ = value;
          invalidate();
        }
        return *this;
      }

      virtual double background_dot_transparency() const {return background_dot_transparency_;}
      virtual dot_matrix_display& background_dot_transparency(double value) {
        if (background_dot_transparency_ != value) {
          background_dot_transparency_ = value;
          invalidate();
        }
        return *this;
      }

      virtual const std::vector<std::vector<bool>>& dots() const {return dots_;}

      virtual int32_t dot_count() const {return dot_count_;}
      virtual void dot_count(int32_t dot_count) {
        if (dot_count_ != dot_count) {
          dot_count_ = dot_count;
          dots_ = std::vector<std::vector<bool>>(dot_count_, std::vector<bool>(dot_count_, false));
          invalidate();
        }
      }
      
      virtual void dots(const dot_collection& dots) {
        set_all_dots(false);
        this->dots(dots, true);
      }
      
      virtual void dots(const dot_collection& dots, bool on) {
        for (auto dot : dots)
          this->set_dot(dot, on);
      }
      
      virtual forms::dot_matrix_style dot_matrix_style() const {return dot_matrix_style_;}
      virtual dot_matrix_display& dot_matrix_style(forms::dot_matrix_style value) {
        if (dot_matrix_style_ != value) {
          dot_matrix_style_ = value;
          invalidate();
        }
        return *this;
      }
      
      virtual bool show_background_dot() const {return show_background_dot_;}
      virtual dot_matrix_display& show_background_dot(bool value) {
        if (show_background_dot_ != value) {
          show_background_dot_ = value;
          invalidate();
        }
        return *this;
      }

      virtual int32_t thickness() const {return thickness_.value_or(size_.height() < (dot_count_ * 2) ? 1 : (size_.height() - dot_count_) / dot_count_);}
      virtual dot_matrix_display& thickness(int32_t value) {
        if (!thickness_.has_value() || thickness_.value() != value) {
          thickness_ = value;
          invalidate();
        }
        return *this;
      }

      virtual void set_all_dots(bool on) {
        for (int32_t x = 0; x < dots_.size(); x++)
          for (int32_t y = 0; y < dots_[x].size(); y++)
            dots_[x][y] = on;
      }
      
      virtual bool get_dot(const dot& dot) const {return dots_[dot.x()][dot.y()];}
      virtual void set_dot(const dot& dot, bool on) {
        if (dots_[dot.x()][dot.y()] != on) {
          dots_[dot.x()][dot.y()] = on;
          invalidate();
        }
      }

    protected:
      drawing::size default_size() const override {return {25, 25};}

      void on_paint(paint_event_args& e) override {
        drawing::graphics graphics = e.graphics();
        if (show_background_dot_) draw_background_dot(graphics);
        for (int32_t x = 0; x < dots_.size(); x++)
          for (int32_t y = 0; y < dots_[x].size(); y++)
            if (dots_[x][y]) draw_dot(graphics, fore_color(), {x, y});
      }
      
      drawing::size measure_control() const override {
        return drawing::size(width(), height());
      }
    
      void set_bounds_core(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified) override {
        if ((specified & bounds_specified::width) == forms::bounds_specified::width && (specified & bounds_specified::height) != forms::bounds_specified::height) {
          height = width;
          specified |= bounds_specified::height;
        }
        if ((specified & bounds_specified::height) == forms::bounds_specified::height) {
          width = height;
          specified |= bounds_specified::width;
        }
        control::set_bounds_core(x, y, width, height, specified);
      }
            
      void set_client_size_core(int32_t width, int32_t height) override {
        if (client_size_.height() != height)
          width = height;
        if (client_size_.width() != width)
          height = width;
        control::set_client_size_core(width, height);
      }

      virtual void draw_background_dot(drawing::graphics& graphics) {
        for (int32_t x = 0; x < dots_.size(); x++)
          for (int32_t y = 0; y < dots_[x].size(); y++)
            draw_dot(graphics, background_dot_color(), {x, y});
      }

      virtual void draw_dot(drawing::graphics& graphics, const drawing::color& color,const dot& dot) {
        int32_t y = (height() - dots_.size())  / dots_.size();
        int32_t x = (width() - dots_[dot.y()].size()) / dots_[dot.y()].size();
        if (dot_matrix_style_ == dot_matrix_style::standard)
          graphics.fill_pie(drawing::solid_brush(color), (1 + x) * dot.x(), (1 + y) * dot.y(), thickness(), thickness(), 0, 360);
        else if (dot_matrix_style_ == dot_matrix_style::square)
          graphics.fill_rectangle(drawing::solid_brush(color), (1 + x) * dot.x(), (1 + y) * dot.y(), thickness(), thickness());
      }

      /// @cond
      int32_t dot_count_ = 7;
      std::vector<std::vector<bool>> dots_ = std::vector<std::vector<bool>>(dot_count_, std::vector<bool>(dot_count_, false));
      bool show_background_dot_ = true;
      std::optional<drawing::color> background_dot_color_;
      double background_dot_transparency_ = 0.05;
      forms::dot_matrix_style dot_matrix_style_ = forms::dot_matrix_style::standard;
      std::optional<int32_t> thickness_;
      /// @endcond
    };
  }
}
