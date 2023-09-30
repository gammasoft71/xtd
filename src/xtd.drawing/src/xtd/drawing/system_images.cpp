#include "../../../include/xtd/drawing/system_images.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

drawing::size system_images::default_size() noexcept {
  return system_images_base::default_size();
}

image system_images::image_loading() noexcept {
  return image_loading(default_size());
}

image system_images::image_loading(const xtd::drawing::size& size) noexcept {
  return system_images::from_name("image-loading", size);
}

image system_images::image_missing() noexcept {
  return image_missing(default_size());
}

image system_images::image_missing(const xtd::drawing::size& size) noexcept {
  return from_name("image-missing", size);
}

vector<ustring> system_images::contexts() noexcept {
  return system_images_base::contexts();
}

map<ustring, vector<ustring>> system_images::context_names() noexcept {
  return system_images_base::context_names();
}

std::vector<ustring> system_images::names() noexcept {
  return system_images_base::names();
}

std::vector<xtd::ustring> system_images::names(const xtd::ustring& context) noexcept {
  return context_names()[context];
}

std::vector<xtd::drawing::size> system_images::sizes() noexcept {
  return {{16, 16}, {24, 24}, {32, 32}, {48, 48}, {64, 64}, {96, 96}, {128, 128}, {256, 256}, {512, 512}, {1024, 1024}};
}

image system_images::from_name(const xtd::ustring& name) {
  return system_images_base::from_name(name);
}

image system_images::from_name(const xtd::ustring& name, const xtd::drawing::size& size) {
  return system_images_base::from_name(name, size);
}

image system_images::from_name(const xtd::ustring& theme, const xtd::ustring& name) {
  return system_images_base::from_name(theme, name);
}

image system_images::from_name(const ustring& theme, const ustring& name, const size& size) {
  return system_images_base::from_name(theme, name, size);
}
