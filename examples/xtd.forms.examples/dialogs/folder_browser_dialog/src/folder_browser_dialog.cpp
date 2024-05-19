#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/folder_browser_dialog>
#include <xtd/forms/form>
#include <xtd/forms/label>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Folder browser dialog example");
    controls().push_back(button1);
    auto_scroll(true);
    
    button1.location({10, 10});
    button1.text("Folder...");
    button1.click += [&] {
      auto dialog = folder_browser_dialog {};
      dialog.selected_path(selected_path);
      if (dialog.show_sheet_dialog(*this) == forms::dialog_result::ok) {
        selected_path = dialog.selected_path();
        label1.text(ustring::format("Path = {}", selected_path));
      }
    };
    
    label1.parent(*this);
    label1.text("Path = ");
    label1.auto_size(true);
    label1.location({10, 50});
  }
  
private:
  button button1;
  label label1;
  ustring selected_path;
};

auto main() -> int {
  application::run(form1 {});
}
