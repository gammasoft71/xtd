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
    folder_browser_dialog dialog;
    dialog.description("Folder browser");
    dialog.root_folder(environment::special_folder::my_documents);
    if (dialog.show_dialog() == dialog_result::ok) {
      label.text(strings::format("Path = {}", dialog.selected_path()));
    }
  };

  
  application::run(form);
}
