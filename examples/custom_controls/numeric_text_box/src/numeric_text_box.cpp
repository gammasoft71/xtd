#include <xtd/xtd.forms>

using namespace xtd::forms;

namespace examples {
  class numeric_text_box : public xtd::forms::text_box {
  public:
    double value() const {
      double result = 0;
      xtd::strings::try_parse(this->text(), result);
      return result;
    }
    
    void value(double value) {this->text(xtd::to_string(value, "G"));}
    
    xtd::event<numeric_text_box, xtd::event_handler<const xtd::forms::control&>> value_changed;

  protected:
    void on_key_press(xtd::forms::key_press_event_args& e) override {
      this->text_box::on_key_press(e);
      e.handled((!std::isdigit(e.key_char()) && e.key_char() != '.') || (e.key_char() == '.' && xtd::strings::index_of(this->text(), '.') != -1));
    }
    
    void on_text_changed(const xtd::event_args& e) override {
      this->text_box::on_text_changed(e);
      this->on_value_changed(e);
    }
    
    void on_value_changed(const xtd::event_args& e) {
      this->value_changed(*this, e);
    }
    
  private:
    using text_box::text;
  };
  
  class form1 : public form {
  public:
    form1() {
      this->text("numeric_text_box example");
      
      this->numeric_text_box1.parent(*this);
      this->numeric_text_box1.value(42);
      this->numeric_text_box1.location({10, 10});
      this->numeric_text_box1.value_changed += [&](const control& sender, const xtd::event_args& e) {
        xtd::diagnostics::debug::write_line(xtd::strings::format("value_changed [value={}]", this->numeric_text_box1.value()));
      };
      
      //this->numeric_text_box1.value_changed.xtd::event_handler<const xtd::forms::control&>::invoke(this->numeric_text_box1, xtd::event_args::empty);
    }
    
  private:
    numeric_text_box numeric_text_box1;
  };
}

int main() {
  application::enable_visual_styles();
  application::run(examples::form1());
}
