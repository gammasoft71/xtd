#include <xtd/xtd.forms>

using namespace xtd::forms;

class form_test : public form {
public:
  form_test() {
    this->text("xtd.forms.manual_tests");
    
    this->button1.parent(*this);
    this->button1.text("Click me");
    this->button1.location({ 10, 10 });
    this->button1.paint += [&](const control& sender, paint_event_args& e) {
      e.graphics().fill_rectangle(xtd::drawing::solid_brush(xtd::drawing::color::red), 0, 0, e.clip_rectangle().width(), e.clip_rectangle().height());
    };
  }
  
private:
  button button1;
};

int main() {
  application::run(form_test());
}
