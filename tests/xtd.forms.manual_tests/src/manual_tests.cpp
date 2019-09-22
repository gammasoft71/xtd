#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

int main() {
  auto form_main = control::create<form>("Form main");
  form_main->client_size({800, 450});
  
  auto panel_left = control::create<panel>(*form_main, "panel_left", {10, 10}, {340, 430});
  panel_left->border_style(forms::border_style::fixed_single);
  panel_left->anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom);

  auto list_box_numbers = control::create<list_box>(*panel_left, "list_box_numbers", {10, 10}, {320, 250});
  list_box_numbers->items().push_back_range({"One", "two", "Three", "Four", "Five", "Six", "Seven"});
  list_box_numbers->anchor(anchor_styles::left | anchor_styles::right);

  auto check = control::create<check_box>(*panel_left, "check", {10, 270});
  
  auto panel_right = control::create<panel>(*form_main, "panel_right", {450, 10}, {340, 430});
  panel_right->border_style(forms::border_style::fixed_single);
  panel_right->anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);

  auto button_move = control::create<button>(*form_main, "Move", {365, 50});
  button_move->click += [&] {
    list_box_numbers->parent(list_box_numbers->parent().value().get() == *panel_left ? *panel_right : *panel_left);
  };
  
  auto button_remove = control::create<button>(*form_main, "Remove", {365, 100});
  button_remove->click += [&] {
    //list_box_numbers->parent(nullptr);
    //message_box::show("Hello");
    application::exit_thread();
  };

  auto button_enable = control::create<button>(*form_main, "Enable", {365, 150});
  button_enable->click += [&] {
    panel_left->enabled(!panel_left->enabled());
  };

  application::run(*form_main);
}
