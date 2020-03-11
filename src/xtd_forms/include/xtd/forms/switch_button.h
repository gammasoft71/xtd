#include "button_base.h"

namespace xtd {
  namespace forms {
    class switch_button : public button_base {
    public:
      switch_button() = default;
      
      virtual bool auto_check() const {return auto_check_;}
      virtual switch_button& auto_check(bool auto_check) {
        if (auto_check_ != auto_check)
          auto_check_ = auto_check;
        return *this;
      }
      
      virtual bool rounded() const {return rounded_;}
      virtual switch_button& rounded(bool value) {
        if (rounded_ != value) {
          rounded_ = value;
          invalidate();
        }
        return *this;
      }
      
      virtual bool checked() const {return checked_;}
      virtual switch_button& checked(bool checked) {
        if (checked_ != checked) {
          checked_ = checked;
          invalidate();
          on_checked_changed(event_args::empty);
        }
        return *this;
      }

      event<switch_button, event_handler<control&>> checked_changed;

    protected:
      virtual void on_checked_changed(const event_args& e) {checked_changed(*this, e);}

      void on_mouse_down(const mouse_event_args& e) override {
        button_base::on_mouse_down(e);
        if (auto_check_) checked(!checked());
      }
      
      void on_handle_created(const event_args& e) override {
        button_base::on_handle_created(e);
        invalidate();
      }
      
      void on_resize(const event_args& e) override {
        button_base::on_resize(e);
        invalidate();
      }

      void on_paint(paint_event_args& e) override {
        button_base::on_paint(e);

        drawing::color button_back_color = checked_ ? drawing::system_colors::menu_highlight() : drawing::system_colors::gray_text();
        drawing::color text_color = checked_ ? fore_color() : drawing::color::average(fore_color(), button_back_color, .33);
        drawing::color slider_color = back_color();
        
        if (!this->enabled()) {
          button_back_color = drawing::color::average(button_back_color, back_color(), .33);
          text_color = drawing::color::average(text_color, button_back_color, .33);
          slider_color = drawing::color::average(slider_color, button_back_color, .33);
        }

        if (rounded_) {
          float height = static_cast<float>(e.clip_rectangle().height() - e.clip_rectangle().height() % 2);
          float offset = (e.clip_rectangle().width() - height) / 2.0f - 0.5f;
          drawing::point_f slider_location(checked_ ? drawing::point_f(e.clip_rectangle().width() - height - offset / 2.0f + 2.0f, 2.0f) : drawing::point_f(offset / 2.0f + 2.0f, 2.0f));

          e.graphics().fill_pie(drawing::solid_brush(button_back_color), offset / 2.0f, .0f, static_cast<float>(height), static_cast<float>(height), 90.0f, 180.0f);
          e.graphics().fill_pie(drawing::solid_brush(button_back_color), e.clip_rectangle().width() - height - offset / 2.0f - 0.5f, .0f, static_cast<float>(height), static_cast<float>(height), 270.0f, 180.0f);
          e.graphics().fill_rectangle(drawing::solid_brush(button_back_color), height / 2.0f + offset / 2.0f, .0f, static_cast<float>(e.clip_rectangle().width() - height) - offset, static_cast<float>(height));
          e.graphics().fill_ellipse(drawing::solid_brush(slider_color), slider_location.x(), slider_location.y(), static_cast<float>(height - 4), static_cast<float>(height - 4));
        } else {
          drawing::size_f slider_size(static_cast<float>((e.clip_rectangle().width() - 6) / 2), static_cast<float>(e.clip_rectangle().height() - 6));
          drawing::point_f slider_location(checked_ ? drawing::point_f(width() / 2.0f, 3.0f) : drawing::point_f(3.0f, 3.0f));

          std::string text = checked_ ? "ON" : "OFF";
          drawing::size_f string_size = e.graphics().measure_string(text, font());
          drawing::point_f string_location(checked_ ? drawing::point_f((width() / 2 - string_size.width()) / 2, (height() - string_size.height()) / 2) : drawing::point_f(width() / 2 + (width() / 2 - string_size.width()) / 2, (height() - string_size.height()) / 2));

          e.graphics().clear(button_back_color);
          e.graphics().draw_string(text, font(), drawing::solid_brush(text_color), string_location);
          e.graphics().draw_line(drawing::pen(drawing::color::darker(button_back_color), 2), e.clip_rectangle().left(), e.clip_rectangle().top(), e.clip_rectangle().right(), e.clip_rectangle().top());
          e.graphics().draw_line(drawing::pen(drawing::color::darker(button_back_color), 2), e.clip_rectangle().left(), e.clip_rectangle().top(), e.clip_rectangle().left(), e.clip_rectangle().bottom());
          e.graphics().draw_line(drawing::pen(drawing::color::lighter(button_back_color), 2), e.clip_rectangle().left(), e.clip_rectangle().bottom(), e.clip_rectangle().right(), e.clip_rectangle().bottom());
          e.graphics().draw_line(drawing::pen(drawing::color::lighter(button_back_color), 2), e.clip_rectangle().right(), e.clip_rectangle().top() + 2, e.clip_rectangle().right(), e.clip_rectangle().bottom());
          
          e.graphics().fill_rectangle(drawing::solid_brush(slider_color), {slider_location, slider_size});
          e.graphics().draw_line(drawing::pen(drawing::color::lighter(slider_color)), slider_location.x(), slider_location.y(), slider_location.x() + slider_size.width(), slider_location.y());
          e.graphics().draw_line(drawing::pen(drawing::color::lighter(slider_color)), slider_location.x(), slider_location.y(), slider_location.x(), slider_location.y() + slider_size.height() - 2);
          e.graphics().draw_line(drawing::pen(drawing::color::darker(slider_color)), slider_location.x(), slider_location.y() + slider_size.height() - 1, slider_location.x() + slider_size.width(), slider_location.y() + slider_size.height() - 1);
          e.graphics().draw_line(drawing::pen(drawing::color::darker(slider_color)), slider_location.x() + slider_size.width(), slider_location.y(), slider_location.x() + slider_size.width(), slider_location.y() + slider_size.height() - 1);
        }
      }
      
    private:
      bool rounded_ = false;
      bool auto_check_ = true;
      bool checked_ = false;
    };
  }
}
