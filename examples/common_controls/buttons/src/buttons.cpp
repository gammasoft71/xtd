#include <xtd/xtd.forms>

using namespace xtd::forms;

int main() {
  auto main_form = control::create<form>("Buttons example", {100, 200}, {450, 200});
  auto actual_size_button = buttons::actual_size(*main_form, {10, 10}, {90, 25});
  auto zoom_in_button = buttons::zoom_in(*main_form, {110, 10}, {90, 25});
  auto zoom_out_button = buttons::zoom_out(*main_form, {210, 10}, {90, 25});
  auto zoom_to_fit_button = buttons::zoom_to_fit(*main_form, {310, 10}, {90, 25});
  application::run(*main_form);
}
