#include <xtd/xtd>

using namespace xtd::forms;

auto main() -> int {
  auto main_form = form::create("Hello world (message_box)");
  auto message_button = button::create(main_form, "&Click me", {10, 10});
  message_button.click += [] {message_box::show("Hello, World!");};
  application::run(main_form);
}
