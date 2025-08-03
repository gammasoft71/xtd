#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/message_box>

auto main() -> int {
  auto form = xtd::forms::form::create("form1");
  form.form_closing += delegate_(auto & sender, auto & event) {event.cancel(xtd::forms::message_box::show("Are you sure you want exit?", "Close Form", xtd::forms::message_box_buttons::yes_no, xtd::forms::message_box_icon::question) == xtd::forms::dialog_result::no);};
  auto button_close = xtd::forms::button::create(form, "Close", {10, 10});
  button_close.click += {form, &xtd::forms::form::close};
  xtd::forms::application::run(form);
}
