#define TRACE
#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class numeric_text_box : public text_box {
  public:
    numeric_text_box() = default;

    double value() const {
      double result = 0;
      try_parse(this->text(), result);
      return result;
    }
    
    void value(double value) {this->text(xtd::to_string(value, "G"));}
    
    event<numeric_text_box, event_handler<const control&>> value_changed;

  protected:
    void on_key_press(key_press_event_args& e) override {
      this->text_box::on_key_press(e);
      e.handled((!isdigit(e.key_char()) && e.key_char() != '.') || (e.key_char() == '.' && strings::index_of(this->text(), '.') != string::npos));
    }
    
    void on_text_changed(const event_args& e) override {
      this->text_box::on_text_changed(e);
      this->on_value_changed(e);
    }
    
    void on_value_changed(const event_args& e) {
      this->value_changed(*this, e);
    }
    
  private:
    using text_box::text;
  };
  
  class form1 : public form {
  public:
    form1() {
      this->text("Numeric text box example");
      
      this->numeric_text_box1.parent(*this);
      this->numeric_text_box1.value(42);
      this->numeric_text_box1.location({10, 10});
      this->numeric_text_box1.value_changed += [&](const control& sender, const event_args& e) {
        ctrace << format("value_changed [value={}]", this->numeric_text_box1.value()) << endl;
      };
    }
    
  private:
    numeric_text_box numeric_text_box1;
  };
}

int main() {
  application::run(examples::form1());
}
