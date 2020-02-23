#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class log_form : public form {
  text_box text_;
public:
  log_form() {
    start_position(form_start_position::manual).location({screen::get_working_area(handle_).left() + screen::get_working_area(handle_).width() - screen::get_working_area(handle_).width() / 4, screen::get_working_area(handle_).top()}).size({screen::get_working_area(handle_).width() / 4, screen::get_working_area(handle_).height()}).visible(true);
    text_.multiline(true).read_only(true).word_wrap(false).parent(*this).dock(dock_style::fill);
  }
  
  void append(const std::string& log_str) {text_.append_text(log_str + "\n");}
};

class form1 : public form {
public:
  form1() {
    log_form_.text("Debug form");
    text("Key events example");
    key_down += [&](control& sender, key_event_args& e) {
      log_form_.append(strings::format("key_down={{key_code={}, key_data=[{}], value={}, modifiers=[{}]}}", e.key_code(), e.key_data(), e.key_value(), e.modifiers()));
    };

    key_press += [&](control& sender, key_press_event_args& e) {
      log_form_.append(strings::format("key_press={{key_char={}}}", e.key_char() == 0 ? "[None]" : strings::format("{}", e.key_char())));
    };

    key_up += [&](control& sender, key_event_args& e) {
      log_form_.append(strings::format("key_up={{key_code={}, key_data=[{}], value={}, modifiers=[{}]}}{}", e.key_code(), e.key_data(), e.key_value(), e.modifiers(), e.modifiers() == keys::none ? "\n" : ""));
    };
  }
  
private:
  log_form log_form_;
};

int main() {
  application::run(form1());
}
