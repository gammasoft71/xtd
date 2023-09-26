#include "../../../include/xtd/drawing/categories_system_images"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

drawing::size categories_system_images::default_size() noexcept {
  return system_images_base::default_size();
}

image categories_system_images::applications_accessories() noexcept {
  return applications_accessories(default_size());
}

image categories_system_images::applications_accessories(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("applications-accessories", size);
}

image categories_system_images::applications_development() noexcept {
  return applications_development(default_size());
}

image categories_system_images::applications_development(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("applications-development", size);
}

image categories_system_images::applications_engineering() noexcept {
  return applications_engineering(default_size());
}

image categories_system_images::applications_engineering(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("applications-engineering", size);
}

image categories_system_images::applications_games() noexcept {
  return applications_games(default_size());
}

image categories_system_images::applications_games(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("applications-games", size);
}

image categories_system_images::applications_graphics() noexcept {
  return applications_graphics(default_size());
}

image categories_system_images::applications_graphics(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("applications-graphics", size);
}

image categories_system_images::applications_internet() noexcept {
  return applications_internet(default_size());
}

image categories_system_images::applications_internet(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("applications-internet", size);
}

image categories_system_images::applications_multimedia() noexcept {
  return applications_multimedia(default_size());
}

image categories_system_images::applications_multimedia(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("applications-multimedia", size);
}

image categories_system_images::applications_office() noexcept {
  return applications_office(default_size());
}

image categories_system_images::applications_office(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("applications-office", size);
}

image categories_system_images::applications_other() noexcept {
  return applications_other(default_size());
}

image categories_system_images::applications_other(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("applications-other", size);
}

image categories_system_images::applications_science() noexcept {
  return applications_science(default_size());
}

image categories_system_images::applications_science(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("applications-science", size);
}

image categories_system_images::applications_system() noexcept {
  return applications_system(default_size());
}

image categories_system_images::applications_system(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("applications-system", size);
}

image categories_system_images::applications_utilities() noexcept {
  return applications_utilities(default_size());
}

image categories_system_images::applications_utilities(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("applications-utilities", size);
}

image categories_system_images::preferences_desktop() noexcept {
  return preferences_desktop(default_size());
}

image categories_system_images::preferences_desktop(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("preferences-desktop", size);
}

image categories_system_images::preferences_desktop_peripherals() noexcept {
  return preferences_desktop_peripherals(default_size());
}

image categories_system_images::preferences_desktop_peripherals(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("preferences-desktop-peripherals", size);
}

image categories_system_images::preferences_desktop_personal() noexcept {
  return preferences_desktop_personal(default_size());
}

image categories_system_images::preferences_desktop_personal(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("preferences-desktop-personal", size);
}

image categories_system_images::preferences_other() noexcept {
  return preferences_other(default_size());
}

image categories_system_images::preferences_other(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("preferences-other", size);
}

image categories_system_images::preferences_system() noexcept {
  return preferences_system(default_size());
}

image categories_system_images::preferences_system(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("preferences-system", size);
}

image categories_system_images::preferences_system_network() noexcept {
  return preferences_system_network(default_size());
}

image categories_system_images::preferences_system_network(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("preferences-system-network", size);
}

image categories_system_images::system_help() noexcept {
  return system_help(default_size());
}

image categories_system_images::system_help(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("system-help", size);
}

const vector<image>& categories_system_images::get_images() noexcept {
  static auto images = get_images(default_size());
  return images;
}

vector<image> categories_system_images::get_images(const xtd::drawing::size& size) noexcept {
  return vector {applications_accessories(size), applications_development(size), applications_engineering(size), applications_games(size), applications_graphics(size), applications_internet(size), applications_multimedia(size), applications_office(size), applications_other(size), applications_science(size), applications_system(size), applications_utilities(size), preferences_desktop(size), preferences_desktop_peripherals(size), preferences_desktop_personal(size), preferences_other(size), preferences_system(size), preferences_system_network(size), system_help(size), };
}

const vector<ustring>& categories_system_images::get_image_names() noexcept {
  static auto names = vector {"applications-accessories"_s, "applications-development"_s, "applications-engineering"_s, "applications-games"_s, "applications-graphics"_s, "applications-internet"_s, "applications-multimedia"_s, "applications-office"_s, "applications-other"_s, "applications-science"_s, "applications-system"_s, "applications-utilities"_s, "preferences-desktop"_s, "preferences-desktop-peripherals"_s, "preferences-desktop-personal"_s, "preferences-other"_s, "preferences-system"_s, "preferences-system-network"_s, "system-help"_s, };
  return names;
}
