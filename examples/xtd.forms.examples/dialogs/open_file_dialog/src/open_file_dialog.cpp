#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/open_file_dialog>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Open file dialog example");
    controls().push_back(button1);
    auto_scroll(true);
    
    button1.location({10, 10});
    button1.text("Open...");
    button1.click += [&] {
      auto dialog = open_file_dialog {};
      dialog.initial_directory(file_name.empty() ? environment::get_folder_path(environment::special_folder::desktop) : io::path::get_directory_name(file_name));
      dialog.file_name(io::path::get_file_name(file_name));
      dialog.filter("Text Files (*.txt)|*.txt|All Files (*.*)|*.*");
      if (dialog.show_sheet_dialog(*this) == forms::dialog_result::ok) {
        file_name = dialog.file_name();
        label1.text(ustring::format("File = {}", file_name));
      }
    };
    
    label1.parent(*this);
    label1.text("File = ");
    label1.auto_size(true);
    label1.location({10, 50});
  }
  
private:
  button button1;
  label label1;
  ustring file_name;
};

auto main() -> int {
  application::run(form1 {});
}
