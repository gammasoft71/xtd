#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Save file dialog example");
    controls().push_back(button1);

    button1.location({10, 10});
    button1.text("Save...");
    button1.click += [&] {
      save_file_dialog dialog;
      dialog.initial_directory(environment::get_folder_path(environment::special_folder::desktop));
      dialog.file_name("MyFile.txt");
      dialog.filter("Text Files (*.txt)|*.txt;*.md|All Files (*.*)|*.*");
      if (dialog.show_sheet_dialog(*this) == dialog_result::ok)
        label1.text(ustring::format("File = {0}", dialog.file_name()));
    };

    label1.parent(*this);
    label1.text("File = ");
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
