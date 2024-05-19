#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/message_box>
#include <xtd/forms/open_file_box>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Open file box example");
    client_size({400, 200});
    controls().push_back_range({button_open_single_file, button_open_multiple_files});
    
    button_open_single_file.parent(*this)
    .location({10, 10})
    .size({150, 35})
    .text("Select single file")
    .click += [this] {
      ustring file_name;
      auto res = open_file_box::show(file_name, *this, "Please select a file...", ".", "Text Files (*.txt)|*.txt|All Files (*.*)|*.*");
      if (res == dialog_result::ok)
        message_box::show(ustring::format("Selected file is:\n{}", file_name));
    };
    
    button_open_multiple_files.parent(*this)
    .location({10, 45})
    .size({150, 35})
    .text("Select multiple files")
    .click += [] {
      auto file_names = std::vector<ustring> {};
      auto res = open_file_box::show(file_names, "Please select multiple files...", open_file_box_options::check_file_exists | open_file_box_options::show_hidden_files);
      if (res == dialog_result::ok)
        message_box::show(ustring::format("Selected files are:\n{}", ustring::join("\n", file_names)));
    };
  }
  
private:
  button button_open_single_file;
  button button_open_multiple_files;
};

auto main() -> int {
  application::run(form1 {});
}
