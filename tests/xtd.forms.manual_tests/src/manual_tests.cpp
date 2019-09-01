#include <xtd/xtd.forms>

using namespace xtd::forms;

class form_test : public form {
public:
  form_test() {
    this->text("xtd.forms.manual_tests");
    
    this->radio1.parent(*this);
    this->radio1.text("radio 1");
    this->radio1.location({ 10, 10 });
    this->radio1.paint += [&](const control& sender, paint_event_args& e) {
      e.graphics().draw_line(xtd::drawing::pen(xtd::drawing::color::red, 2), 0, 0, e.clip_rectangle().width(), e.clip_rectangle().height());
    };
  }
  
private:
  radio_button radio1;
};

int main() {
  application::run(form_test());
}
