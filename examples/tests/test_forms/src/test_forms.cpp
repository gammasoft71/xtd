#include <xtd/xtd.forms>
#include "document_new_32x32.xpm"
#include "document_open_32x32.xpm"
#include "document_print_preview_32x32.xpm"
#include "document_print_32x32.xpm"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace std::literals;

int main() {
  button button_print;
  button_print.width(40);
  button_print.dock(dock_style::left);
  button_print.image(bitmap(document_print_32x32));

  button button_print_preview;
  button_print_preview.width(40);
  button_print_preview.dock(dock_style::left);
  button_print_preview.image(bitmap(document_print_preview_32x32));

  button button_open;
  button_open.width(40);
  button_open.dock(dock_style::left);
  button_open.image(bitmap(document_open_32x32));

  button button_new;
  button_new.width(40);
  button_new.dock(dock_style::left);
  button_new.image(bitmap(document_new_32x32));

  panel panel_top;
  panel_top.height(45);
  panel_top.border_style(forms::border_style::fixed_single);
  panel_top.dock(dock_style::top);
  panel_top.controls().push_back_range({button_print, button_print_preview, button_open, button_new});
  
  form form;
  form.text("Test Gui");
  form.controls().push_back(panel_top);

  application::run(form);
}
