#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class my_message_filter : public imessage_filter {
public:
  explicit my_message_filter(const control& value) : control_(const_cast<control&>(value)) {}
  
  bool pre_filter_message(const message& m) const override {
    if (m.msg() == WM_REFLECT + WM_COMMAND && m.lparam() == control_.get().handle())
      return true;
    return false;
  }
  
private:
  std::reference_wrapper<control> control_;
};

int main() {
  auto form_main = control::create<form>("Form main");
  form_main->client_size({800, 450});
  
  auto panel_left = control::create<panel>(*form_main, "panel_left", {10, 10}, {340, 430});
  panel_left->border_style(forms::border_style::fixed_single);
  
  auto list_box_numbers = control::create<list_box>(*panel_left, "list_box_numbers", {10, 10}, {150, 250});
  list_box_numbers->items().push_back_range({"One", "two", "Three", "Four", "Five", "Six", "Seven"});
  
  auto check = control::create<check_box>(*panel_left, "check", {10, 270});
  
  auto panel_right = control::create<panel>(*form_main, "panel_right", {450, 10}, {340, 430});
  panel_right->border_style(forms::border_style::fixed_single);
  
  auto button_move = control::create<button>(*form_main, "Move", {365, 50});
  button_move->click += [&] {
    list_box_numbers->parent(list_box_numbers->parent().value().get() == *panel_left ? *panel_right : *panel_left);
  };
  
  auto button_remove = control::create<button>(*form_main, "Remove", {365, 100});
  button_remove->click += [&] {
    //list_box_numbers->parent(nullptr);
    message_box::show("Hello");
  };

  auto button_enable = control::create<button>(*form_main, "Enable", {365, 150});
  button_enable->click += [&] {
    panel_left->enabled(!panel_left->enabled());
  };
  
  cdebug << format("form_main.back_color = {}", form_main->back_color()) << endl;
  cdebug << format("form_main.fore_color = {}", form_main->fore_color()) << endl;

  application::application_exit += [&] {
    cdebug << format("Application exit") << endl;
  };
  
  application::enter_thread_modal += [&] {
    cdebug << format("enter thread modal") << endl;
  };
  
  my_message_filter message_filer(*button_remove);
  application::add_message_filter(message_filer);
  application::remove_message_filter(message_filer);
  application::run(*form_main);
  cdebug << format("Application exitied") << endl;
}
