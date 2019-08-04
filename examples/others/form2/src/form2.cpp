#include <xtd/xtd.forms>

int main() {
  auto form1 = xtd::forms::control::create<xtd::forms::form>("form1");
  form1->form_closing += [](const control& sender, form_closing_event_args& e) {e.cancel(message_box::show("Are you sure you want exit?", "Close Form", message_box_buttons::yes_no, message_box_icon::question) == dialog_result::no);};
  xtd::forms::application::run(*form1);
}
