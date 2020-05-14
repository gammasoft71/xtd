#include <xtd/xtd.forms>

int main() {
  auto form = xtd::forms::control::create<xtd::forms::form>("form1");
  form->form_closing += [](const xtd::forms::control& sender, xtd::forms::form_closing_event_args& e) {e.cancel(xtd::forms::message_box::show("Are you sure you want exit?", "Close Form", xtd::forms::message_box_buttons::yes_no, xtd::forms::message_box_icon::question) == xtd::forms::dialog_result::no);};
  auto button_close = xtd::forms::control::create<xtd::forms::button>(*form, "Close", {10, 10});
  button_close->click += {*form, &xtd::forms::form::close};
  xtd::forms::application::run(*form);
}
