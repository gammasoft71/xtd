#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

auto main()->int {
  auto form = control::create<forms::form>("System report", {0, 0}, {500, 700});
  form->start_position(form_start_position::center_screen);
  auto text_box = control::create<forms::text_box>(*form, xtd::system_report::to_string());
  text_box->multiline(true).read_only(true).dock(dock_style::fill).font({drawing::font_family::generic_monospace(), text_box->font().size()});
  xtd::forms::application::run(*form);
}
