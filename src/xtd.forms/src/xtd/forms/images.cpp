#include "../../../include/xtd/forms/images.hpp"

using namespace xtd::drawing;
using namespace xtd::forms;

xtd::drawing::image images::from_name(const xtd::string& name, const xtd::drawing::size& size) {
  return from_name(xtd::forms::application::style_sheet().theme().name(), name, size);
}

xtd::drawing::image images::from_name(const xtd::string& theme, const xtd::string& name, const xtd::drawing::size& size) {
  return system_images::from_name(theme, name, size);
}
