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
    text("Mouse events example");

    click += [&] {
      log_form_.append("click");
    };
    
    double_click += [&] {
      log_form_.append("double_click");
    };
    
    mouse_click += [&](control& sender, const mouse_event_args& e) {
      log_form_.append(strings::format("mouse_click={{button={}, clicks={}, delta={}, location=[{}]}}", e.button(), e.clicks(), e.delta(), e.location()));
    };
    
    mouse_double_click += [&](control& sender, const mouse_event_args& e) {
      log_form_.append(strings::format("mouse_double_click={{button={}, clicks={}, delta={}, location=[{}]}}", e.button(), e.clicks(), e.delta(), e.location()));
    };
    
    mouse_down += [&](control& sender, const mouse_event_args& e) {
      log_form_.append(strings::format("mouse_down={{button={}, clicks={}, delta={}, location=[{}]}}", e.button(), e.clicks(), e.delta(), e.location()));
    };

    mouse_enter += [&] {
      log_form_.append("mouse_enter");
    };
    
    mouse_horizontal_wheel += [&](control& sender, const mouse_event_args& e) {
      log_form_.append(strings::format("mouse_horizontal_wheel={{button={}, clicks={}, delta={}, location=[{}]}}", e.button(), e.clicks(), e.delta(), e.location()));
    };

    mouse_leave += [&] {
      log_form_.append("mouse_leave");
    };
    
    mouse_move += [&](control& sender, const mouse_event_args& e) {
      log_form_.append(strings::format("mouse_move={{button={}, clicks={}, delta={}, location=[{}]}}", e.button(), e.clicks(), e.delta(), e.location()));
    };
    
    mouse_up += [&](control& sender, const mouse_event_args& e) {
      log_form_.append(strings::format("mouse_up={{button={}, clicks={}, delta={}, location=[{}]}}", e.button(), e.clicks(), e.delta(), e.location()));
    };
    
    mouse_wheel += [&](control& sender, const mouse_event_args& e) {
      log_form_.append(strings::format("mouse_wheel={{button={}, clicks={}, delta={}, location=[{}]}}", e.button(), e.clicks(), e.delta(), e.location()));
    };
  }
  
private:
  log_form log_form_;
};

int main() {
  application::run(form1());
}
