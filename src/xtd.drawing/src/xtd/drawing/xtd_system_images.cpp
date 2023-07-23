#include "../../../include/xtd/drawing/xtd_system_images.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

drawing::size xtd_system_images::default_size() noexcept {
  return system_images_base::default_size();
}

image xtd_system_images::gammasoft() noexcept {
  return gammasoft(default_size());
}

image xtd_system_images::gammasoft(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("gammasoft", size);
}

image xtd_system_images::xtd() noexcept {
  return xtd(default_size());
}

image xtd_system_images::xtd(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("xtd", size);
}

image xtd_system_images::xtd_console() noexcept {
  return xtd_console(default_size());
}

image xtd_system_images::xtd_console(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("xtd-console", size);
}

image xtd_system_images::xtd_forms() noexcept {
  return xtd_forms(default_size());
}

image xtd_system_images::xtd_forms(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("xtd-forms", size);
}

image xtd_system_images::xtd_tunit() noexcept {
  return xtd_tunit(default_size());
}

image xtd_system_images::xtd_tunit(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("xtd-tunit", size);
}

image xtd_system_images::xtd_core() noexcept {
  return xtd_core(default_size());
}

image xtd_system_images::xtd_core(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("xtd-core", size);
}

image xtd_system_images::xtd_delegates() noexcept {
  return xtd_delegates(default_size());
}

image xtd_system_images::xtd_delegates(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("xtd-delegates", size);
}

image xtd_system_images::xtd_diagnostics() noexcept {
  return xtd_diagnostics(default_size());
}

image xtd_system_images::xtd_diagnostics(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("xtd-diagnostics", size);
}

image xtd_system_images::xtd_drawing() noexcept {
  return xtd_drawing(default_size());
}

image xtd_system_images::xtd_drawing(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("xtd-drawing", size);
}

image xtd_system_images::xtd_io() noexcept {
  return xtd_io(default_size());
}

image xtd_system_images::xtd_io(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("xtd-io", size);
}

image xtd_system_images::xtd_strings() noexcept {
  return xtd_strings(default_size());
}

image xtd_system_images::xtd_strings(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("xtd-strings", size);
}

image xtd_system_images::xtd_cmake() noexcept {
  return xtd_cmake(default_size());
}

image xtd_system_images::xtd_cmake(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("xtd-cmake", size);
}

const vector<image>& xtd_system_images::get_images() noexcept {
  static auto images = get_images(default_size());
  return images;
}

vector<image> xtd_system_images::get_images(const xtd::drawing::size& size) noexcept {
  return vector {gammasoft(size), xtd(size), xtd_console(size), xtd_forms(size), xtd_tunit(size), xtd_core(size), xtd_delegates(size), xtd_diagnostics(size), xtd_drawing(size), xtd_io(size), xtd_strings(size), xtd_cmake(size), };
}

const vector<ustring>& xtd_system_images::get_image_names() noexcept {
  static auto names = vector {"gammasoft"_s, "xtd"_s, "xtd-console"_s, "xtd-forms"_s, "xtd-tunit"_s, "xtd-core"_s, "xtd-delegates"_s, "xtd-diagnostics"_s, "xtd-drawing"_s, "xtd-io"_s, "xtd-strings"_s, "xtd-cmake"_s, };
  return names;
}
