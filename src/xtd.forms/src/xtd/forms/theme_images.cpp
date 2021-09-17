#include "../../../include/xtd/forms/theme_images.h"
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/system_images.h>

using namespace xtd::forms;

namespace {
  xtd::drawing::image system_dark_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
    return xtd::drawing::system_images::from_name(name, size);
  }

  xtd::drawing::image system_light_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
    return xtd::drawing::system_images::from_name(name, size);
  }

  xtd::drawing::image system_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
    return xtd::drawing::system_colors::window().get_lightness() < 0.5 ? system_dark_image_getter(name, size) : system_light_image_getter(name, size);
  }

  xtd::drawing::image gnome_dark_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
    return xtd::drawing::system_images::from_name("gnome (dark)", name, size);
  }

  xtd::drawing::image gnome_light_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
    return xtd::drawing::system_images::from_name("gnome (light)", name, size);
  }

  xtd::drawing::image gnome_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
    return xtd::drawing::system_colors::window().get_lightness() < 0.5 ? gnome_dark_image_getter(name, size) : gnome_light_image_getter(name, size);
  }

  xtd::drawing::image kde_dark_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
    return xtd::drawing::system_images::from_name("kde (dark)", name, size);
  }

  xtd::drawing::image kde_light_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
    return xtd::drawing::system_images::from_name("kde (light)", name, size);
  }

  xtd::drawing::image kde_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
    return xtd::drawing::system_colors::window().get_lightness() < 0.5 ? kde_dark_image_getter(name, size) : kde_light_image_getter(name, size);
  }

  xtd::drawing::image macos_dark_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
    return xtd::drawing::system_images::from_name("macos (dark)", name, size);
  }

  xtd::drawing::image macos_light_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
    return xtd::drawing::system_images::from_name("macos (light)", name, size);
  }

  xtd::drawing::image macos_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
    return xtd::drawing::system_colors::window().get_lightness() < 0.5 ? macos_dark_image_getter(name, size) : macos_light_image_getter(name, size);
  }

xtd::drawing::image symbolic_dark_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
  return xtd::drawing::system_images::from_name("symbolic (dark)", name, size);
}

xtd::drawing::image symbolic_light_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
  return xtd::drawing::system_images::from_name("symbolic (light)", name, size);
}

xtd::drawing::image symbolic_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
  return xtd::drawing::system_colors::window().get_lightness() < 0.5 ? symbolic_dark_image_getter(name, size) : symbolic_light_image_getter(name, size);
}

xtd::drawing::image windows_dark_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
  return xtd::drawing::system_images::from_name("windows (dark)", name, size);
}

xtd::drawing::image windows_light_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
  return xtd::drawing::system_images::from_name("windows (light)", name, size);
}

xtd::drawing::image windows_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
  return xtd::drawing::system_colors::window().get_lightness() < 0.5 ? windows_dark_image_getter(name, size) : windows_light_image_getter(name, size);
}

xtd::drawing::image xtd_dark_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
  return xtd::drawing::system_images::from_name("xtd (dark)", name, size);
}

xtd::drawing::image xtd_light_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
  return xtd::drawing::system_images::from_name("xtd (light)", name, size);
}

xtd::drawing::image xtd_image_getter(const xtd::ustring& name, const xtd::drawing::size& size) {
  return xtd::drawing::system_colors::window().get_lightness() < 0.5 ? xtd_dark_image_getter(name, size) : xtd_light_image_getter(name, size);
}

}

const theme_images theme_images::empty {};
theme_images theme_images::current_theme_;

theme_images theme_images::theme_from_name(const xtd::ustring& name) {
  if (name == default_theme_name()) return theme_images(default_theme_name(), theme_style::system_auto, {system_image_getter}, true);
  if (name == "gnome") return theme_images("gnome", theme_style::system_auto, {gnome_image_getter});
  if (name == "gnome (dark)") return theme_images("gnome (dark)", theme_style::dark, {gnome_dark_image_getter});
  if (name == "gnome (light)") return theme_images("gnome (light)", theme_style::light, {gnome_light_image_getter});
  if (name == "kde") return theme_images("kde", theme_style::system_auto, {kde_image_getter});
  if (name == "kde (dark)") return theme_images("kde (dark)", theme_style::dark, {kde_dark_image_getter});
  if (name == "kde (light)") return theme_images("kde (light)", theme_style::light, {kde_light_image_getter});
  if (name == "macos") return theme_images("macos", theme_style::system_auto, {macos_image_getter});
  if (name == "macos (dark)") return theme_images("macos (dark)", theme_style::dark, {macos_dark_image_getter});
  if (name == "macos (light)") return theme_images("macos (light)", theme_style::light, {macos_light_image_getter});
  if (name == "symbolic") return theme_images("symbolic", theme_style::system_auto, {symbolic_image_getter});
  if (name == "symbolic (dark)") return theme_images("symbolic (dark)", theme_style::dark, {symbolic_dark_image_getter});
  if (name == "symbolic (light)") return theme_images("symbolic (light)", theme_style::light, {symbolic_light_image_getter});
  if (name == "windows") return theme_images("windows", theme_style::system_auto, {windows_image_getter});
  if (name == "windows (dark)") return theme_images("windows (dark)", theme_style::dark, {windows_dark_image_getter});
  if (name == "windows (light)") return theme_images("windows (light)", theme_style::light, {windows_light_image_getter});
  if (name == "xtd") return theme_images("xtd", theme_style::system_auto, {xtd_image_getter});
  if (name == "xtd (dark)") return theme_images("xtd (dark)", theme_style::dark, {xtd_dark_image_getter});
  if (name == "xtd (light)") return theme_images("xtd (light)", theme_style::light, {xtd_light_image_getter});
  return current_theme_;
}
