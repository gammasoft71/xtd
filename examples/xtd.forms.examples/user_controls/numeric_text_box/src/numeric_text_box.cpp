#define TRACE
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/text_box>
#include <xtd/ctrace>
#include <xtd/environment>

using namespace xtd;
using namespace xtd::forms;

namespace numeric_tex_box_example {
  class numeric_text_box : public text_box {
  public:
    numeric_text_box() = default;
    
    double value() const {
      auto result = .0;
      try_parse(text(), result);
      return result;
    }
    
    void value(double value) {text(xtd::to_string(value, "G"));}
    
    event<numeric_text_box, event_handler> value_changed;
    
  protected:
    void on_key_press(key_press_event_args& e) override {
      text_box::on_key_press(e);
      e.handled((!isdigit(e.key_char()) && e.key_char() != '.') || (e.key_char() == '.' && as<ustring>(text()).index_of('.') != ustring::npos));
    }
    
    void on_text_changed(const event_args& e) override {
      text_box::on_text_changed(e);
      on_value_changed(e);
    }
    
    void on_value_changed(const event_args& e) {
      value_changed(*this, e);
    }
    
  private:
    using text_box::text;
  };
  
  class form1 : public form {
  public:
    form1() {
      text("Numeric text box example");
      
      numeric_text_box1.parent(*this);
      numeric_text_box1.value(42);
      numeric_text_box1.location({10, 10});
      numeric_text_box1.value_changed += [&] {
        ctrace << ustring::format("value_changed [value={}]", numeric_text_box1.value()) << environment::new_line;
      };
    }
    
  private:
    numeric_text_box numeric_text_box1;
  };
}

auto main() -> int {
  application::run(numeric_tex_box_example::form1 {});
}
