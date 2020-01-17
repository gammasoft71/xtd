#include <xtd/xtd.forms>

using namespace xtd::forms;

int main() {
  auto form_main = control::create<form>("Buttons example", {100, 200}, {450, 200});
  auto button_actual_size = buttons::actual_size(*form_main, {10, 10}, {90, 25});
  auto button_zoom_in = buttons::zoom_in(*form_main, {110, 10}, {90, 25});
  auto button_zoom_out = buttons::zoom_out(*form_main, {210, 10}, {90, 25});
  auto button_zoom_to_fit = buttons::zoom_to_fit(*form_main, {310, 10}, {90, 25});
  application::run(*form_main);
}
