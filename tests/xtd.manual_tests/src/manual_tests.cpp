#include <xtd/xtd.forms>
#include "error_m.xpm"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  panel panel_cursor;
  panel_cursor.border_style(forms::border_style::fixed_3d).location({10, 50}).size({100, 100}).back_color(system_colors::window());
  
  button button_run;
  button_run.text("Run").location({10, 10});
  button_run.click += [&] {
    open_file_dialog dialog;
    dialog.filter("Image file|*.icns;*.ico;*.bmp;*.png");
    if (dialog.show_dialog() == dialog_result::ok) {
      panel_cursor.cursor(cursor::from_bitmap(bitmap(dialog.file_name()), {0, 15}));
    }
  };

  form form_main;
  form_main.text("Manual tests");
  form_main.controls().push_back_range({button_run, panel_cursor});
  
  application::run(form_main);
}
