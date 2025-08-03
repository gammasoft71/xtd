#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    text("Folder browser dialog example");
    controls().push_back(button1);
    auto_scroll(true);
    
    button1.location({10, 10});
    button1.text("Folder...");
    button1.click += delegate_ {
      auto dialog = folder_browser_dialog {};
      dialog.selected_path(selected_path);
      if (dialog.show_sheet_dialog(*this) == forms::dialog_result::ok) {
        selected_path = dialog.selected_path();
        label1.text(string::format("Path = {}", selected_path));
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
  string selected_path;
};

auto main() -> int {
  application::run(form1 {});
}
