#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    text("Save file dialog example");
    controls().add(button1);
    auto_scroll(true);
    
    button1.location({10, 10});
    button1.text("Save...");
    button1.click += delegate_ {
      auto dialog = save_file_dialog {};
      dialog.initial_directory(environment::get_folder_path(environment::special_folder::desktop));
      dialog.file_name("MyFile.txt");
      dialog.filter("Text Files (*.txt)|*.txt;*.md|All Files (*.*)|*.*");
      if (dialog.show_sheet_dialog(*this) == dialog_result::ok)
        label1.text(string::format("File = {0}", dialog.file_name()));
    };
    
    label1.parent(*this);
    label1.text("File = ");
    label1.auto_size(true);
    label1.location({10, 50});
  }
  
private:
  button button1;
  label label1;
};

auto main() -> int {
  application::run(form1 {});
}
