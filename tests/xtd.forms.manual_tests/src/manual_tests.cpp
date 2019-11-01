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
  label.text("Path = ");
  label.auto_size(true);
  label.location({10, 50});
  
  button button;
  button.parent(form);
  button.text("Click me");
  button.location({10, 10});
  button.click += [&] {
    save_file_dialog sfd;
    sfd.title("Save file");
    sfd.initial_directory(environment::get_folder_path(environment::special_folder::my_documents));
    sfd.filter("Text Files (*.txt)|*.txt|All Files (*.*)|*.*");
    if (sfd.show_dialog() == dialog_result::ok) {
      label.text(strings::format("Path = {}", sfd.file_name()));
    }
  };

  
  application::run(form);
}
