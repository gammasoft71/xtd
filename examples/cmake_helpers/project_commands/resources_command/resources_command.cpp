#include <xtd/xtd.forms>
#include "properties/resources.hpp"

using namespace xtd::forms;

int main() {
  auto main_form = control::create<form>("Resources example", {0, 0}, {800, 450});
  auto main_tab_control = control::create<tab_control>(*main_form);
  main_tab_control->dock(dock_style::fill);

  auto information_tab_page = control::create<tab_page>(*main_tab_control, "Information");
  auto information_label = control::create<label>(*information_tab_page, resources_command::properties::resources::information());
  information_label->dock(dock_style::fill).font({xtd::drawing::font_family::generic_monospace(), 11});
  
  auto gammasoft_tab_page = control::create<tab_page>(*main_tab_control, "Gammasoft");
  auto gammasoft_picture_box = control::create<picture_box>(*gammasoft_tab_page);
  gammasoft_picture_box->image(resources_command::properties::resources::gammasoft()).size_mode(picture_box_size_mode::center_image).dock(dock_style::fill);

  auto readme_tab_page = control::create<tab_page>(*main_tab_control, "Read me");
  auto readme_label = control::create<label>(*readme_tab_page, resources_command::properties::resources::readme());
  readme_label->dock(dock_style::fill);
  
  auto xtd_tab_page = control::create<tab_page>(*main_tab_control, "xtd");
  auto xtd_picture_box = control::create<picture_box>(*xtd_tab_page);
  xtd_picture_box->image(resources_command::properties::resources::xtd()).size_mode(picture_box_size_mode::center_image).dock(dock_style::fill);

  application::run(*main_form);
}
