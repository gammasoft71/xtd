#include "../../../include/xtd/drawing/animations_system_images.h"

using namespace std;
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

const vector<image>& animations_system_images::get_images() noexcept {
  static auto images = get_images(default_size());
  return images;
}

vector<image> animations_system_images::get_images(const xtd::drawing::size& size) noexcept {
  return vector {process_working(size), };
}

const vector<ustring>& animations_system_images::get_image_names() noexcept {
  static auto names = vector {"process-working"_s, };
  return names;
}
