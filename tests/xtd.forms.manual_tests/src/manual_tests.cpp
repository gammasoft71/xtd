#include <xtd/xtd.forms>
#include "logo.xpm"

using namespace xtd;
using namespace xtd::forms;

int main() {
  form form;
  form.text("Manual tests");
  form.client_size({300, 300});
  form.form_border_style(forms::form_border_style::fixed_dialog);
  form.maximize_box(false);
  form.minimize_box(false);

  picture_box picture_box;
  picture_box.border_style(forms::border_style::fixed_3d);
  picture_box.image(xtd::drawing::bitmap(logo_xpm));
  picture_box.location({20, 20});
  picture_box.parent(form);
  picture_box.size({260, 260});
  //picture_box.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
  //picture_box.dock(dock_style::fill);
  
  application::run(form);
}
