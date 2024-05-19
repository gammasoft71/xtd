#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/message_box>

using namespace xtd;
using namespace xtd::forms;

auto main() -> int {
  form form;
  form.text("Click anywhere on the form");
  form.mouse_click += [&](object& sender, const mouse_event_args& e) {
    if (e.button() == mouse_buttons::left)
      message_box::show(form, ustring::format("The form is clicked at {}", e.location()), "form_click");
  };
  application::run(form);
}
