#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

// The main entry point for the application.
int main() {
  form form;
  //form.back_color(color::dodger_blue);
  //form.fore_color(color::yellow);
  cdebug << format("form.back_color = {}", form.back_color()) << endl;
  cdebug << format("form.fore_color = {}", form.fore_color()) << endl;
  cdebug << format("form.size = {}", form.size()) << endl;

  list_box list_box1;
  list_box1.parent(form);
  list_box1.location({10, 10});
  list_box1.height(200);
  
  list_box1.items().push_back_range({"Undo", "Redo", "Cut", "Copy", "Paste", "Delete", "Select All"});
  //list_box1.selected_index(3);
  list_box1.selected_item("Paste");
  
  list_box list_box2;
  list_box2.parent(form);
  list_box2.location({150, 10});
  list_box2.height(200);
  list_box2.border_style(forms::border_style::none);
  
  list_box1.selected_index_changed += [&](const control& sender, const event_args& e) {
    cdebug << format("list_box1.selected_index_changed = [{} : {}]", (int)list_box1.selected_index(), list_box1.selected_item()) << endl;
    cdebug << format("list_box1.selected_items = {{{}}}", strings::join(", ", list_box1.selected_items())) << endl;
  };
  
  list_box1.text_changed += [&](const control& sender, const event_args& e) {
    cdebug << format("list_box1.text_changed = {}", list_box1.text()) << endl;
  };
  
  list_box1.double_click += [&](const control& sender, const event_args& e) {
    size_t index = list_box1.selected_index();
    if (index != -1) {
      list_box2.items().push_back(list_box1.selected_item());
      list_box1.items().erase_at(index);
      list_box1.selected_index(index >= list_box1.items().size() ? list_box1.items().size() - 1 : index);
    }
  };

  list_box2.double_click += [&](const control& sender, const event_args& e) {
    size_t index = list_box2.selected_index();
    if (index != -1) {
      list_box1.items().push_back(list_box2.selected_item());
      list_box2.items().erase_at(index);
      list_box2.selected_index(index >= list_box2.items().size() ? list_box2.items().size() - 1 : index);
    }
  };

  button button_mode;
  button_mode.parent(form);
  button_mode.text("Mode...");
  button_mode.location({10, 230});
  button_mode.click += [&](const control& sender, const event_args& e) {
    switch (list_box1.selection_mode()) {
      case selection_mode::none: list_box1.selection_mode(selection_mode::one); break;
      case selection_mode::one: list_box1.selection_mode(selection_mode::multi_simple); break;
      case selection_mode::multi_simple: list_box1.selection_mode(selection_mode::multi_extended); break;
      case selection_mode::multi_extended: list_box1.selection_mode(selection_mode::none); break;
      default: break;
    }
    cdebug << format("list_box1.selection_mode = {}", list_box1.selection_mode()) << endl;
  };

  button button_sorted;
  button_sorted.parent(form);
  button_sorted.text("Sorted...");
  button_sorted.location({100, 230});
  button_sorted.click += [&](const control& sender, const event_args& e) {
    list_box1.sorted(!list_box1.sorted());
    button_sorted.text(list_box1.sorted() ? "Unsorted" : "Sorted");
  };

  cdebug << format("list_box1.back_color = {}", list_box1.back_color()) << endl;
  cdebug << format("list_box1.fore_color = {}", list_box1.fore_color()) << endl;
  cdebug << format("list_box1.size = {}", list_box1.size()) << endl;

  application::run(form);
}
