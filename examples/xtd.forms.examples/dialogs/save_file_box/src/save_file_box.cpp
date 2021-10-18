#include <xtd/xtd>

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
        ustring file_name;
        auto res = save_file_box::show(file_name, *this, "Save file as...", environment::get_folder_path(environment::special_folder::my_documents), "*.txt");
        if (res == dialog_result::ok)
          message_box::show(ustring::format("File will be saved as:\n{}", file_name));
      };
  }
  
private:
  button button_save_file;
};

int main() {
  application::run(form1());
}