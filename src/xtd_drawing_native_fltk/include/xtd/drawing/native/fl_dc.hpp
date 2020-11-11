#pragma once
#include <string>
#include <FL/fl_draw.H>
#include <FL/Fl_Widget.H>

namespace xtd::drawing::native {
  class fl_dc {
    class context {
    public:
      context() {
        current_color_ = fl_color();
        current_font_ = fl_font();
        current_size_ = fl_size();
      }
      
      virtual ~context() {
        fl_color(current_color_);
        fl_font(current_font_, current_size_);
        fl_line_style(0);
      }
      
    private:
      Fl_Color current_color_ = FL_BLACK;
      Fl_Font current_font_ = FL_HELVETICA;
      Fl_Fontsize current_size_ = FL_NORMAL_SIZE;
    };
    
  protected:
    fl_dc() = default;
    
  public:
    virtual ~fl_dc() {}

    int32_t ascent(Fl_Font font, Fl_Fontsize font_size) {
      context c;
      fl_font(font, font_size);
      return font_size - fl_descent();
    }

    void clear(Fl_Color color) {
      fl_draw_box(Fl_Boxtype::FL_FLAT_BOX, x_, y_, w_, h_, color);
    }
    
    int32_t descent(Fl_Font font, Fl_Fontsize font_size) {
      context c;
      fl_font(font, font_size);
      return fl_descent();
    }

    void draw_arc(Fl_Color color, int thick, int style, int32_t x, int32_t y, int32_t w, int32_t h, int32_t start_angle, int32_t sweep_angle) {
      context c;
      fl_color(color);
      fl_line_style(style, thick);
      fl_arc(x_ + x, y_ + y, w, h, start_angle, start_angle + sweep_angle);
    }

    void draw_bezier(Fl_Color color, int thick, int style, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, int32_t x4, int32_t y4) {
      context c;
      fl_color(color);
      fl_line_style(style, thick);
      fl_curve(x_ + x1, y_ + y1, x_ + x2, y_ + y2, x_ + x3, y_ + y3, x_ + x4, y_ + y4);
    }
    
    void draw_ellipse(Fl_Color color, int thick, int style, int32_t x, int32_t y, int32_t w, int32_t h) {
      context c;
      fl_color(color);
      fl_line_style(style, thick);
      fl_arc(x_ + x, y_ + y, w, h, 0, 360);
    }
    
    void draw_line(Fl_Color color, int thick, int style, int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
      context c;
      fl_color(color);
      fl_line_style(style, thick);
      fl_line(x_ + x1, y_ + y1, x_ + x2, y_ + y2);
    }
    
    void draw_rectangle(Fl_Color color, int thick, int style, int32_t x, int32_t y, int32_t w, int32_t h) {
      context c;
      fl_color(color);
      fl_line_style(style, thick);
      fl_rect(x_ + x, y_ + y, w, h);
    }

    void draw_string(const std::string& text, int32_t x, int32_t y, Fl_Font font, Fl_Fontsize font_size, Fl_Color color) {
      context c;
      fl_color(color);
      fl_font(font, font_size);
      fl_draw(text.c_str(), x_ + x, y_ + y + font_size);
    }
    
    void draw_string(const std::string& text, int32_t x1, int32_t y1, int32_t x2, int32_t y2, Fl_Font font, Fl_Fontsize font_size, Fl_Color color) {
      context c;
      fl_push_clip(x_ + x1, y_ + y2, x_ + x2, y_ + y2);
      fl_color(color);
      fl_font(font, font_size);
      fl_draw(text.c_str(), x_ + x1, y_ + y1 + font_size);
      fl_pop_clip();
    }
    
    void fill_ellipse(Fl_Color color, int32_t x, int32_t y, int32_t w, int32_t h) {
      context c;
      fl_color(color);
      fl_pie(x_ + x, y_ + y, w, h, 0, 360);
    }

    void fill_pie(Fl_Color color, int32_t x, int32_t y, int32_t w, int32_t h, int32_t start_angle, int32_t sweep_angle) {
      context c;
      fl_color(color);
      fl_pie(x_ + x, y_ + y, w, h, start_angle, start_angle + sweep_angle);
    }
    
    void fill_rectangle(Fl_Color color, int32_t x, int32_t y, int32_t w, int32_t h) {
      fl_draw_box(Fl_Boxtype::FL_FLAT_BOX, x_ + x, y_ + x, w, h, color);
    }
    
    void measure_string(const std::string& text, Fl_Font font, Fl_Fontsize font_size, int32_t& width, int32_t& height) {
      context c;
      fl_font(font, font_size);
      fl_measure(text.c_str(), width, height);
    }

  protected:
    int32_t x_ = 0;
    int32_t y_ = 0;
    int32_t w_ = 0;
    int32_t h_ = 0;
  };

  class fl_paint_dc : public fl_dc {
  public:
    explicit fl_paint_dc(Fl_Widget& control) : control_(&control) {
      Fl_Widget* top_window = control_;
      while (top_window->parent()) top_window = top_window->parent();
      top_window_ = dynamic_cast<Fl_Window*>(top_window);
      x_ = control_ != top_window_ ? control_->x() : 0;
      y_ = control_ != top_window_ ? control_->y() : 0;
      w_ = control_->w();
      h_ = control_->h();
      fl_push_clip(x_, y_, w_, h_);
    }
    
    ~fl_paint_dc() {
      fl_pop_clip();
    }

  protected:
    Fl_Widget* control_ = nullptr;
    Fl_Window* top_window_ = nullptr;
  };

  class fl_client_dc : public fl_paint_dc {
  public:
    explicit fl_client_dc(Fl_Widget& control) : fl_paint_dc(control) {
      top_window_->make_current();
    }
  };

  class fl_screen_dc : public fl_dc {
  public:
    fl_screen_dc() {
      current_device_ = Fl_Surface_Device::surface();
      Fl_Display_Device::display_device()->set_current();
    }
    
    ~fl_screen_dc() {
      current_device_->set_current();
    }
    
  protected:
    Fl_Surface_Device* current_device_ =nullptr;
  };
}
