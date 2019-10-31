#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class switch_button : public user_control {
public:
  switch_button() {
    size_ = default_size();
  }
  
  virtual bool auto_check() const {return auto_check_;}
  virtual switch_button& auto_check(bool auto_check) {
    if (auto_check_ != auto_check)
      auto_check_ = auto_check;
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
  drawing::size default_size() const override {return {75, 25};}
  
  virtual void on_checked_changed(const event_args& e) {checked_changed(*this, e);}

  void on_click(const event_args& e) override {
    user_control::on_click(e);
    if (auto_check_) checked(!checked());
  }
  
  void on_paint(paint_event_args& e) override {
    user_control::on_paint(e);

    color button_back_color = checked_ ? system_colors::menu_highlight() : system_colors::gray_text();
    color text_color = checked_ ? color::white : color::black;

    size_f slider_size((width() - 6) / 2, height() - 6);
    point_f slider_location(checked_ ? point_f(width() / 2.0, 3.0) : point_f(3.0, 3.0));

    ustring text = checked_ ? "ON" : "OFF";
    size_f string_size = e.graphics().measure_string(text, font());
    point_f string_location(checked_ ? point_f((width() / 2 - string_size.width()) / 2, (height() - string_size.height()) / 2) : point_f(width() / 2 + (width() / 2 - string_size.width()) / 2, (height() - string_size.height()) / 2));

    e.graphics().clear(button_back_color);
    e.graphics().draw_string(text, font(), solid_brush(text_color), string_location);
    e.graphics().draw_line(pen(color::darker(button_back_color), 2), e.clip_rectangle().left(), e.clip_rectangle().top(), e.clip_rectangle().right(), e.clip_rectangle().top());
    e.graphics().draw_line(pen(color::darker(button_back_color), 2), e.clip_rectangle().left(), e.clip_rectangle().top(), e.clip_rectangle().left(), e.clip_rectangle().bottom());
    e.graphics().draw_line(pen(color::lighter(button_back_color), 2), e.clip_rectangle().left(), e.clip_rectangle().bottom(), e.clip_rectangle().right(), e.clip_rectangle().bottom());
    e.graphics().draw_line(pen(color::lighter(button_back_color), 2), e.clip_rectangle().right(), e.clip_rectangle().top() + 2, e.clip_rectangle().right(), e.clip_rectangle().bottom());
    
    e.graphics().fill_rectangle(solid_brush(back_color()), {slider_location, slider_size});
    e.graphics().draw_line(pen(color::lighter(back_color())), slider_location.x(), slider_location.y(), slider_location.x() + slider_size.width(), slider_location.y());
    e.graphics().draw_line(pen(color::lighter(back_color())), slider_location.x(), slider_location.y(), slider_location.x(), slider_location.y() + slider_size.height() - 2);
    e.graphics().draw_line(pen(color::darker(back_color())), slider_location.x(), slider_location.y() + slider_size.height() - 1, slider_location.x() + slider_size.width(), slider_location.y() + slider_size.height() - 1);
    e.graphics().draw_line(pen(color::darker(back_color())), slider_location.x() + slider_size.width(), slider_location.y(), slider_location.x() + slider_size.width(), slider_location.y() + slider_size.height() - 1);
  }
  
private:
  bool auto_check_ = true;
  bool checked_ = false;
};

int main() {
  form form;
  form.text("Switch button example");
  
  label label1;
  label1.parent(form);
  label1.location({10, 90});
  label1.auto_size(true);
  label1.text("switch: OFF");

  switch_button switch_button1;
  switch_button1.parent(form);
  switch_button1.location({10, 10});
  switch_button1.checked_changed += [&](control& sender, const event_args& e) {
    label1.text(strings::format("switch: {}", static_cast<switch_button&>(sender).checked() ? "ON" : "OFF"));
  };

  switch_button switch_button2;
  switch_button2.parent(form);
  switch_button2.auto_check(false);
  switch_button2.checked(true);
  switch_button2.location({10, 50});
  switch_button2.click += [](control& sender, const event_args& e) {
    //static_cast<switch_button&>(sender).checked(!static_cast<switch_button&>(sender).checked());
  };

  application::run(form);
}
