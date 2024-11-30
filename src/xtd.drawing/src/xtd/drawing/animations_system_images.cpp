#include "../../../include/xtd/drawing/animations_system_images.hpp"

using namespace xtd;
using namespace xtd::drawing;

drawing::size animations_system_images::default_size() noexcept {
  return system_images_base::default_size();
}

image animations_system_images::process_working() noexcept {
  return process_working(default_size());
}

image animations_system_images::process_working(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("process-working", size);
}

const std::vector<image>& animations_system_images::get_images() noexcept {
  static auto images = get_images(default_size());
  return images;
}

std::vector<image> animations_system_images::get_images(const xtd::drawing::size& size) noexcept {
  return std::vector {process_working(size), };
}

const std::vector<string>& animations_system_images::get_image_names() noexcept {
  static auto names = std::vector {"process-working"_s, };
  return names;
}
