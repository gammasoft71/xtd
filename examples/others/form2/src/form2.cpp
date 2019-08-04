#include <xtd/xtd.forms>

int main() {
  auto form1 = xtd::forms::control::create<xtd::forms::form>("form1");
  form1->form_closing += [](const xtd::forms::control& sender, xtd::forms::form_closing_event_args& e) {e.cancel(xtd::forms::message_box::show("Are you sure you want exit?", "Close Form", xtd::forms::message_box_buttons::yes_no, xtd::forms::message_box_icon::question) == xtd::forms::dialog_result::no);};
  auto button1 = xtd::forms::control::create<xtd::forms::button>(*form1, "Close", {10, 10});
  button1->click += [&](const xtd::forms::control& sender, const xtd::event_args& e) {form1->close();};
  xtd::forms::application::run(*form1);
}
