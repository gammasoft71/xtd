#include "properties/resources.h"
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/picture_box>
#include <xtd/forms/tab_control>
#include <xtd/forms/tab_page>

using namespace xtd::forms;

auto main() -> int {
  auto main_form = form::create("Resources example", xtd::drawing::size {800, 450});
  auto main_tab_control = tab_control::create(main_form);
  main_tab_control.dock(dock_style::fill);
  
  auto information_tab_page = tab_page::create(main_tab_control, "Information");
  auto information_label = label::create(information_tab_page, resources_command::properties::resources::information());
  information_label.dock(dock_style::fill).font({xtd::drawing::font_family::generic_monospace(), 11});
  
  auto gammasoft_tab_page = tab_page::create(main_tab_control, "Gammasoft");
  auto gammasoft_picture_box = picture_box::create(gammasoft_tab_page, resources_command::properties::resources::gammasoft());
  gammasoft_picture_box.size_mode(picture_box_size_mode::center_image).dock(dock_style::fill);
  
  auto readme_tab_page = tab_page::create(main_tab_control, "Read me");
  auto readme_label = label::create(readme_tab_page, resources_command::properties::resources::readme());
  readme_label.dock(dock_style::fill);
  
  auto xtd_tab_page = tab_page::create(main_tab_control, "xtd");
  auto xtd_picture_box = picture_box::create(xtd_tab_page, resources_command::properties::resources::xtd());
  xtd_picture_box.size_mode(picture_box_size_mode::center_image).dock(dock_style::fill);
  
  application::run(main_form);
}
