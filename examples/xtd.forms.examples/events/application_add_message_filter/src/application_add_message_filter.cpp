#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/check_box>
#include <xtd/forms/debug_form>
#include <xtd/forms/window_messages>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;

namespace application_add_message_filter_example {
  class main_form : public form, public imessage_filter {
  public:
    main_form() {
      xtd::forms::application::add_message_filter(*this);
      text("Application add message filter example");
      panel_.border_style(forms::border_style::groove);
      skip_button_click_check_box_.auto_size(true);
      click += [&] {debug::write_line(ustring::format("(form.click) x={}, y={}", mouse_position().x(), mouse_position().y()));};
      button_.click += [&] {debug::write_line(ustring::format("(button.click) x={}, y={}", mouse_position().x(), mouse_position().y()));};
      skip_button_click_check_box_.click += [&] {debug::write_line(ustring::format("(check_box.click) x={}, y={}", mouse_position().x(), mouse_position().y()));};
      panel_.click += [&] {debug::write_line(ustring::format("(panel.click) x={}, y={}", mouse_position().x(), mouse_position().y()));};
    }
    
  private:
    bool pre_filter_message(const message& message) {
      // Uncomment following line to see all messages.
      //debug::write_line(ustring::format("message=[{}], control=[{}]", message.to_string(), from_handle(message.hwnd()).has_value() ? from_handle(message.hwnd()).value().get().to_string() : "(null)"));
      return skip_button_click_check_box_.checked() && message.msg() == WM_LBUTTONDOWN && message.hwnd() == button_.handle();
    }
    
    debug_form debug_form_;
    panel panel_ = panel::create(*this, {10, 10}, {200, 100});
    button button_ = button::create(panel_, "Click me", {10, 10});
    check_box skip_button_click_check_box_ = check_box::create(panel_, "Skip button click event", check_state::unchecked, {10, 40});
  };
}

int main() {
  xtd::forms::application::run(application_add_message_filter_example::main_form {});
}
