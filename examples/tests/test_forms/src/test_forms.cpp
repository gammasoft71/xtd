#include <filesystem>
#include <xtd/xtd.forms>

using namespace std;
using namespace std::filesystem;
using namespace xtd;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  /*
  auto main_form = control::create<form>("Test Gui");
  auto picture = control::create<picture_box>(*main_form);
  picture->size_mode(picture_box_size_mode::zoom).dock(dock_style::fill);
  //picture->image(properties::resources::xtd_console());
  picture->image(system_images::from_name("xtd", size(1024, 1024)));
  application::run(*main_form);
   */
  
  auto source_path = path("/Users/yves/Projects/xtd/src/xtd_drawing/resources/system_images/gnome");
  auto target_path = path("/Users/yves/Projects/xtd/src/xtd_drawing/resources/system_images/xtd");
  auto sizes = {"16x16", "24x24", "32x32", "48x48", "64x64", "96x96", "128x128", "256x256", "512x512", "1024x1024"};
  auto images = {"help-faq"};
  
  for (auto size : sizes) {
    for (auto image : images) {
      copy(source_path/size/strings::format("{}.png", image), target_path/size/strings::format("{}.png", image), copy_options::overwrite_existing);
    }
  }
  
}
