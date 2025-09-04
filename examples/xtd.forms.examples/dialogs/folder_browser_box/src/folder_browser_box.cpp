#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    text("Folder browser box example");
    controls().add(button1);
    
    button1.location({10, 10});
    button1.text("Folder...");
    button1.click += delegate_ {
      if (folder_browser_box::show(selected_path, *this) == forms::dialog_result::ok)
        label1.text(string::format("Path = {}", selected_path));
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
