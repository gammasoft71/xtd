#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

int main() {
  form form;
  form.text("Manual tests");
  form.client_size({300, 300});

  /*
  panel panel;
  panel.parent(form);
  panel.dock(dock_style::fill);
  panel.auto_scroll(true);
   */
  
  label label;
  label.parent(form);
  label.text("File = ");
  label.auto_size(true);
  label.location({10, 50});
  
  button button;
  button.parent(form);
  button.text("Click me");
  button.location({10, 10});
  button.click += [&] {
    open_file_dialog ofd;
    ofd.title("Open file");
    ofd.initial_directory(environment::get_folder_path(environment::special_folder::my_documents));
    ofd.filter("Text Files (*.txt)|*.txt|All Files (*.*)|*.*");
    if (ofd.show_dialog() == dialog_result::ok) {
      label.text(strings::format("File = {}", ofd.file_name()));
    }
  };

  
  application::run(form);
}
