#include <xtd/xtd.forms>
#include "error_m.xpm"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

/*
int main() {
  picture_box picture_box_icon;
  picture_box_icon.image(icon(error_m_icon).to_bitmap()).size_mode(picture_box_size_mode::center_image).border_style(forms::border_style::fixed_3d).location({10, 50}).size({100, 100}).back_color(system_colors::window());
  
  button button_run;
  button_run.text("Run").location({10, 10});
  button_run.click += [&] {
    open_file_dialog dialog;
    dialog.filter("Icon file (*.ico)|*.icns;*.ico;*.bmp;*.png");
    if (dialog.show_dialog() == dialog_result::ok) {
      picture_box_icon.image(icon(dialog.file_name()).to_bitmap());
    }
  };

  form form_main;
  form_main.text("Manual tests");
  form_main.controls().push_back_range({button_run, picture_box_icon});
  
  application::run(form_main);
}
*/

int main() {
  panel panel_cursor_w;
  panel_cursor_w.border_style(forms::border_style::fixed_3d).location({10, 50}).size({100, 100}).back_color(system_colors::window_text());
  
  panel panel_cursor_m;
  panel_cursor_m.border_style(forms::border_style::fixed_3d).location({120, 50}).size({100, 100}).back_color(system_colors::window());
  
  panel panel_cursor_g;
  panel_cursor_g.border_style(forms::border_style::fixed_3d).location({230, 50}).size({100, 100}).back_color(system_colors::window());

  button button_run;
  button_run.text("Cursor...").location({10, 10});
  button_run.click += [&] {
    open_file_dialog dialog;
    dialog.filter("Image file|*.icns;*.ico;*.bmp;*.png");
    if (dialog.show_dialog() == dialog_result::ok) {
      auto file_name_w = dialog.file_name();
      auto file_name_m = dialog.file_name();
      auto file_name_g = dialog.file_name();

      if (file_name_w[file_name_w.size() - 5] != 'w') file_name_w[file_name_w.size() - 5] = 'w';
      if (file_name_m[file_name_m.size() - 5] != 'm') file_name_m[file_name_m.size() - 5] = 'm';
      if (file_name_m[file_name_g.size() - 5] != 'g') file_name_g[file_name_g.size() - 5] = 'g';

      if (xtd::io::file::exists(file_name_w)) panel_cursor_w.cursor(cursor::from_bitmap(bitmap(file_name_w)));
      if (xtd::io::file::exists(file_name_m)) panel_cursor_m.cursor(cursor::from_bitmap(bitmap(file_name_m)));
      if (xtd::io::file::exists(file_name_g)) panel_cursor_g.cursor(cursor::from_bitmap(bitmap(file_name_g)));
    }
  };
  
  form form_main;
  form_main.text("Manual tests").client_size({340, 300});
  form_main.controls().push_back_range({button_run, panel_cursor_w, panel_cursor_m, panel_cursor_g});
  
  application::run(form_main);
}
