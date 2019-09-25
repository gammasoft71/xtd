#include <xtd/xtd.forms>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::forms;


int main() {
  form form1;
  
  combo_box list_box1;
  list_box1.parent(form1);
  list_box1.location({20, 20});
  //list_box1.sorted(true);

  list_box1.items().push_back("Item 1");
  list_box1.items().push_back("Item 3");
  list_box1.items().push_back("Item 2");

  list_box1.value_member("Hello");
  
  list_box1.selected_index(1);
  
  list_box1.selected_item("Item 4");
  
  list_box1.items()[0] = "My Item 1";
  
  list_box1.text("New text");
  
  cdebug << format("list_box1.selected_index = {}", list_box1.selected_index()) << endl;
  cdebug << format("list_box1.selected_item = {}", list_box1.selected_item()) << endl;
  cdebug << format("list_box1.value_member = {}", list_box1.value_member()) << endl;
  cdebug << format("list_box1.text = {}", list_box1.text()) << endl;

  button button1;
  button1.parent(form1);
  button1.location({20, 240});
  button1.text("Add");
  button1.click += [&] {
    //list_box1.items()[2] = {list_box1.items()[2].value(), !list_box1.items()[2].checked()};
    list_box1.items()[2] = "42";
  };
  
  application::run(form1);
}
