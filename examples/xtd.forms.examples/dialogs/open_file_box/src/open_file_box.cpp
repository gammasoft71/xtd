#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;
using namespace std;

class form1 : public form {
public:
  form1() {
    text("Open file box example");
    client_size({400, 200});
    
    button_open_single_file.parent(*this)
      .location({ 10, 10 })
      .size({ 150, 35 })
      .text("Select single file")
      .click += [this] {
        xtd::ustring file_name;
        auto res = open_file_box::show(file_name, *this, "Please select a file...", ".", "Text Files (*.txt)|*.txt|All Files (*.*)|*.*");
        if (res == dialog_result::ok) {
          message_box::show(xtd::ustring::format("Selected file is:\n{}", file_name));
        }
      };

    

    button_open_multiple_files.parent(*this)
      .location({ 10, 40 })
      .size({ 150, 35 })
      .text("Select multiple files")
      .click += [this] {
        std::vector<xtd::ustring> file_names;
        auto res = open_file_box::show(file_names, "Please select multiple files...", open_file_box_options::check_file_exists | open_file_box_options::show_hidden_files);
        if (res == dialog_result::ok) {
          xtd::ustring txt;
          for (auto& filename : file_names) txt += filename + '\n';
          message_box::show(xtd::ustring::format("Selected files are:\n{}", txt));
        }
      };

    controls().push_back_range({ button_open_single_file, button_open_multiple_files });
  }
  
private:
  button button_open_single_file;
  button button_open_multiple_files;
};

int main() {
  application::run(form1());
}
