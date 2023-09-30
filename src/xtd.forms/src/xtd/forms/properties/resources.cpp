#include "../../../../include/xtd/forms/properties/resources.h"
#include <xtd/environment>
#include <xtd/io/file>
#include <xtd/io/path>

using namespace xtd;
using namespace io;
using namespace drawing;
using namespace forms;
using namespace forms::properties;

namespace {
  ustring get_os_postfix() noexcept {
    return environment::os_version().is_windows_platform() ? "_w" : environment::os_version().is_unix_platform() ? "_g" : environment::os_version().is_macos_platform() ? "_m" : "";
  }
}

const bitmap& resources::cursor_arrow() {
  if (!file::exists(path::combine(environment::get_folder_path(environment::special_folder::xtd_resources), "cursors", ustring::format("arrow{}.png", get_os_postfix())))) return bitmap::empty;
  static auto bitmap = drawing::bitmap {path::combine(environment::get_folder_path(environment::special_folder::xtd_resources), "cursors", ustring::format("arrow{}.png", get_os_postfix()))};
  return bitmap;
}

const bitmap& resources::cursor_no_move_2d() {
  if (!file::exists(path::combine(environment::get_folder_path(environment::special_folder::xtd_resources), "cursors", ustring::format("cursor_no_move_2d{}.png", get_os_postfix())))) return bitmap::empty;
  static auto bitmap = drawing::bitmap {path::combine(environment::get_folder_path(environment::special_folder::xtd_resources), "cursors", ustring::format("cursor_no_move_2d{}.png", get_os_postfix()))};
  return bitmap;
}

const bitmap& resources::gammasoft() {
  if (!file::exists(path::combine(environment::get_folder_path(environment::special_folder::xtd_resources), "pictures", "gammasoft.png"))) return bitmap::empty;
  static auto bitmap = drawing::bitmap {path::combine(environment::get_folder_path(environment::special_folder::xtd_resources), "pictures", "gammasoft.png")};
  return bitmap;
}

const bitmap& resources::xtd() {
  if (!file::exists(path::combine(environment::get_folder_path(environment::special_folder::xtd_resources), "pictures", "xtd.png"))) return bitmap::empty;
  static auto bitmap = drawing::bitmap {path::combine(environment::get_folder_path(environment::special_folder::xtd_resources), "pictures", "xtd.png")};
  return bitmap;
}

const bitmap& resources::xtd_console() {
  if (!file::exists(path::combine(environment::get_folder_path(environment::special_folder::xtd_resources), "pictures", "xtd_console.png"))) return bitmap::empty;
  static auto bitmap = drawing::bitmap {path::combine(environment::get_folder_path(environment::special_folder::xtd_resources), "pictures", "xtd_console.png")};
  return bitmap;
}

const bitmap& resources::xtd_forms() {
  if (!file::exists(path::combine(environment::get_folder_path(environment::special_folder::xtd_resources), "pictures", "xtd_forms.png"))) return bitmap::empty;
  static auto bitmap = drawing::bitmap {path::combine(environment::get_folder_path(environment::special_folder::xtd_resources), "pictures", "xtd_forms.png")};
  return bitmap;
}
