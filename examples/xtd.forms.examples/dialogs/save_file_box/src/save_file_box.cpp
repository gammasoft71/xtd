#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/message_box>
#include <xtd/forms/save_file_box>
#include <xtd/environment>
#include <xtd/literals>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Save file box example");
    client_size({400, 200});
    controls().push_back(button_save_file);
    
    button_save_file.parent(*this)
    .location({10, 10})
    .size({150, 35})
    .text("Save file")
    .click += [this] {
      auto file_name = "MyFile.txt"_s;
      auto res = save_file_box::show(file_name, *this, "Save file as...", environment::get_folder_path(environment::special_folder::my_documents), "*.txt");
      if (res == dialog_result::ok)
        message_box::show(ustring::format("File will be saved as:\n{}", file_name));
    };
  }
  
private:
  button button_save_file;
};

auto main() -> int {
  application::run(form1 {});
}
