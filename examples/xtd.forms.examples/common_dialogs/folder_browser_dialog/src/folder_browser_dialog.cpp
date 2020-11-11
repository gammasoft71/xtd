#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Folder browser dialog example");
    controls().push_back(button1);

    button1.location({10, 10});
    button1.text("Folder...");
    button1.click += [&] {
      folder_browser_dialog dialog;
      dialog.root_folder(environment::special_folder::desktop);
      if (dialog.show_sheet_dialog(*this) == forms::dialog_result::ok)
        label1.text(strings::format("Path = {}", dialog.selected_path()));
    };

    label1.parent(*this);
    label1.text("Path = ");
    label1.auto_size(true);
    label1.location({10, 40});
  }
  
private:
  button button1;
  label label1;
};

int main() {
  application::run(form1());
}
