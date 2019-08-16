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
  
  list_box1.items().push_back_range({"Undo", "Redo", "Cut", "Copy", "Paste", "Delete", "Select All", });
  //list_box1.selected_index(3);
  list_box1.selected_item("Paste");
  
  list_box list_box2;
  list_box2.parent(form);
  list_box2.location({150, 10});
  list_box2.height(200);

  
  list_box1.selected_index_changed += [&](const control& sender, const event_args& e) {
    cdebug << format("list_box1.selected_index_changed = [{} : {}]", (int)list_box1.selected_index(), list_box1.selected_item()) << endl;
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

  cdebug << format("list_box1.back_color = {}", list_box1.back_color()) << endl;
  cdebug << format("list_box1.fore_color = {}", list_box1.fore_color()) << endl;
  cdebug << format("list_box1.size = {}", list_box1.size()) << endl;

  application::run(form);
}
