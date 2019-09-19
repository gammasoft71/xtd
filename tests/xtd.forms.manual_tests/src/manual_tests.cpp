#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

int main() {
  auto form_main = control::create<form>("Form main");
  form_main->client_size({800, 450});
  
  auto panel_left = control::create<panel>(*form_main, "panel_left", {10, 10}, {340, 430});
  panel_left->border_style(forms::border_style::fixed_single);
  
  auto list_box_numbers = control::create<list_box>(*panel_left, "list_box_numbers", {10, 10}, {150, 250});
  list_box_numbers->items().push_back_range({"One", "two", "Three", "Four", "Five", "Six", "Seven"});
  
  auto panel_right = control::create<panel>(*form_main, "panel_right", {450, 10}, {340, 430});
  panel_right->border_style(forms::border_style::fixed_single);
  
  auto button_move = control::create<button>(*form_main, "Move", {365, 50});
  button_move->click += [&] {
    list_box_numbers->parent(list_box_numbers->parent().handle() == panel_left->handle() ? *panel_right : *panel_left);
  };
  
  application::run(*form_main);
}
