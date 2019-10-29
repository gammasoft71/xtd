#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class switch_button : public xtd::forms::panel {
public:
  switch_button() {
    this->size_ = this->default_size();
    this->border_style_ = xtd::forms::border_style::fixed_3d;
  }
  
  virtual bool auto_checked() const {return this->auto_checked_;}
  virtual switch_button& auto_checked(bool auto_checked) {
    if (this->auto_checked_ != auto_checked)
      this->auto_checked_ = auto_checked;
    return *this;
  }
  
  virtual bool checked() const {return this->checked_;}
  virtual switch_button& checked(bool checked) {
    if (this->checked_ != checked) {
      this->checked_ = checked;
      this->invalidate();
      this->on_checked_changed(xtd::event_args::empty);
    }
    return *this;
  }

  xtd::event<switch_button, xtd::event_handler<xtd::forms::control&>> checked_changed;

protected:
  xtd::drawing::size default_size() const override {return {75, 25};}
  
  virtual void on_checked_changed(const xtd::event_args& e) {checked_changed(*this, e);}

  void on_click(const xtd::event_args& e) override {
    this->xtd::forms::user_control::on_click(e);
    if (auto_checked_) this->checked(!this->checked());
  }
  
  void on_paint(xtd::forms::paint_event_args& e) override {
    this->xtd::forms::user_control::on_paint(e);

    xtd::drawing::color back_color = this->checked_ ? xtd::drawing::system_colors::menu_highlight() : xtd::drawing::system_colors::gray_text();
    xtd::drawing::color fore_color = this->checked_ ? xtd::drawing::color::white : xtd::drawing::color::black;

    xtd::drawing::size_f slider_size((this->width() - 12) / 2, this->height() - 10);
    xtd::drawing::point_f slider_location(this->checked_ ? xtd::drawing::point_f(this->width() / 2.0, 3.0) : xtd::drawing::point_f(3.0, 3.0));

    xtd::ustring text = this->checked_ ? "ON" : "OFF";
    xtd::drawing::size_f string_size = e.graphics().measure_string(text, this->font());
    xtd::drawing::point_f string_location(this->checked_ ? xtd::drawing::point_f((this->width() / 2 - string_size.width()) / 2 - 2, (this->height() - string_size.height()) / 2 - 2) : xtd::drawing::point_f(this->width() / 2 + (this->width() / 2 - string_size.width()) / 2 - 2, (this->height() - string_size.height()) / 2 - 2));

    e.graphics().clear(back_color);
    e.graphics().fill_rectangle(xtd::drawing::solid_brush(xtd::drawing::system_colors::control()), {slider_location, slider_size});
    e.graphics().draw_string(text, this->font(), xtd::drawing::solid_brush(fore_color), string_location);
  }
  
private:
  bool auto_checked_ = true;
  bool checked_ = false;
};

int main() {
  form form;
  form.text("Switch button example");
  
  switch_button switch_button1;
  switch_button1.parent(form);
  switch_button1.location({10, 10});
  switch_button1.checked_changed += [](control& sender, const event_args& e) {
    cdebug << format("switch: {}", static_cast<switch_button&>(sender).checked() ? "ON" : "OFF") << endl;
  };

  switch_button switch_button2;
  switch_button2.parent(form);
  switch_button2.auto_checked(false);
  switch_button2.checked(true);
  switch_button2.location({10, 50});
  switch_button2.click += [](control& sender, const event_args& e) {
    //static_cast<switch_button&>(sender).checked(!static_cast<switch_button&>(sender).checked());
  };

  application::run(form);
}
