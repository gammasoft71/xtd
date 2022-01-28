#include "../../../../include/xtd/forms/style_sheets/style_sheet.h"
#include <xtd/as.h>
#include <xtd/is.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/io/directory.h>
#include <xtd/io/file.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::io;
using namespace xtd::forms::style_sheets;
using namespace xtd::web::css;

std::map<ustring, style_sheet> style_sheet::style_sheets_;

style_sheet::style_sheet(const ustring& text) {
  css_reader reader(text);
  selector_map::const_iterator selectors_iterator;
  if ((selectors_iterator = reader.selectors().find("theme")) != reader.selectors().end()) theme_reader(selectors_iterator, theme_);
  if ((selectors_iterator = reader.selectors().find("system-colors")) != reader.selectors().end()) system_color_reader(selectors_iterator, system_colors_);
}

const button_selector& style_sheet::button() const noexcept {
  return button_;
}

const control_selector& style_sheet::control() const noexcept {
  return control_;
}

const form_selector& style_sheet::form() const noexcept {
  return form_;
}

const label_selector& style_sheet::label() const noexcept {
  return label_;
}

const map<ustring, style_sheet> style_sheet::style_sheets() noexcept {
  initilize();
  return style_sheets_;
}

const system_colors_selector& style_sheet::system_colors()const noexcept {
  return system_colors_;
}

const theme_selector& style_sheet::theme() const noexcept {
  return theme_;
}

bool style_sheet::equals(const object& other) const noexcept {
  return is<style_sheet>(other) ? equals(static_cast<const style_sheet&>(other)) : false;
}

bool style_sheet::equals(const style_sheet& other) const noexcept {
  return theme_ == theme_;
}

border_color style_sheet::border_color_from_css(const xtd::ustring& css_text, const border_color& default_value) const noexcept {
  vector<ustring> colors = split_colors_from_css(css_text);
  if (colors.size() < 1 || colors.size() > 4) return default_value;
  border_color result;
  result.all(color_from_css(colors[0], default_value.top()));
  if (colors.size() >= 2) result.right(color_from_css(colors[0], default_value.right()));
  if (colors.size() >= 3) result.bottom(color_from_css(colors[0], default_value.right()));
  if (colors.size() == 4) result.left(color_from_css(colors[0], default_value.right()));
  return result;
}

xtd::drawing::color style_sheet::color_from_css(const ustring& css_text, const color& default_value) const noexcept {
  color result;
  if (css_text.starts_with("#") && try_parse_hex_color(css_text, result)) return result;
  if (css_text.starts_with("rgb(") && css_text.ends_with(")") && try_parse_rgb_color(css_text, result)) return result;
  if (css_text.starts_with("rgba(") && css_text.ends_with(")") && try_parse_rgba_color(css_text, result)) return result;
  if (css_text.starts_with("argb(") && css_text.ends_with(")") && try_parse_argb_color(css_text, result)) return result;
  if (css_text.starts_with("hsv(") && css_text.ends_with(")") && try_parse_hsv_color(css_text, result)) return result;
  if (css_text.starts_with("hsva(") && css_text.ends_with(")") && try_parse_hsva_color(css_text, result)) return result;
  if (css_text.starts_with("ahsv(") && css_text.ends_with(")") && try_parse_ahsv_color(css_text, result)) return result;
  if (css_text.starts_with("hsl(") && css_text.ends_with(")") && try_parse_hsl_color(css_text, result)) return result;
  if (css_text.starts_with("hsla(") && css_text.ends_with(")") && try_parse_hsla_color(css_text, result)) return result;
  if (css_text.starts_with("ahsl(") && css_text.ends_with(")") && try_parse_ahsl_color(css_text, result)) return result;
  if (css_text.starts_with("system-color(") && css_text.ends_with(")") && try_parse_system_color(css_text, result)) return result;
  if (try_parse_named_color(css_text, result)) return result;
  return default_value;
}

void style_sheet::initilize() {
  if (!style_sheets_.empty()) return;
  
  for (auto theme_dir : directory::enumerate_directories(__XTD_THEMES_PATH__)) {
    xtd::ustring theme_css;
    for (auto theme_file : directory::enumerate_files(theme_dir, "*.css"))
      theme_css += file::read_all_text(theme_file);
    style_sheet style(theme_css);
    if (!style.theme().name().empty())
      style_sheets_[style.theme().name()] = style;
  }
}

vector<ustring> style_sheet::split_colors_from_css(const ustring& text) const noexcept {
  static vector<ustring> color_keywords = {"rgb(", "rgba(", "argb(", "hsl(", "hsla(", "ahsl(", "hsv(", "hsva(", "ahsv(", "system-color("};
  auto string_starts_with_any = [](const ustring& text, const vector<ustring>& values)->ustring {
    for (auto value : values)
      if (text.starts_with(value)) return value;
    return "";
  };
  vector<ustring> result;
  auto value = text.trim();
  while (!value.empty()) {
    auto color_keyword = string_starts_with_any(value, color_keywords);
    if (color_keyword != "") {
      result.push_back(value.substring(0, value.find(")") + 1).trim());
      value = value.remove(0, value.find(")") + 1).trim();
      if (value[0] == ',') value = value.remove(0, 1).trim();
    } else if (value.find(",") == ustring::npos) {
      result.push_back(value.trim());
      value = "";
    } else if (value.find(",") != ustring::npos) {
      result.push_back(value.substring(0, value.find(",")).trim());
      value = value.remove(0, value.find(",") + 1).trim();
    }
  }
  return result;
}

ustring style_sheet::string_from_css(const xtd::ustring& css_text, const ustring& default_value) const noexcept {
  auto value = css_text.trim();
  if (!value.starts_with("\"") || !value.ends_with("\"")) return default_value;
  return value.remove(value.size() - 1, 1).replace("\"", "");
}

bool style_sheet::try_parse_hex_color(const ustring& text, color& result) const noexcept {
  if (text.starts_with("#") && text.size() == 4U) {
    byte_t r = 0;
    if (xtd::try_parse<byte_t>(text.substring(1, 1), r, number_styles::hex_number) == false) return false;
    r += r * 16;
    byte_t g = 0;
    if (xtd::try_parse<byte_t>(text.substring(2, 1), g, number_styles::hex_number) == false) return false;
    g += g * 16;
    byte_t b = 0;
    if (xtd::try_parse<byte_t>(text.substring(3, 1), b, number_styles::hex_number) == false) return false;
    b += b * 16;
    result = color::from_argb(r, g, b);
    return true;
  }
  if (text.starts_with("#") && text.size() == 5U) {
    byte_t a = 0;
    if (xtd::try_parse<byte_t>(text.substring(1, 1), a, number_styles::hex_number) == false) return false;
    a += a * 16;
    byte_t r = 0;
    if (xtd::try_parse<byte_t>(text.substring(2, 1), r, number_styles::hex_number) == false) return false;
    r += r * 16;
    byte_t g = 0;
    if (xtd::try_parse<byte_t>(text.substring(3, 1), g, number_styles::hex_number) == false) return false;
    g += g * 16;
    byte_t b = 0;
    if (xtd::try_parse<byte_t>(text.substring(4, 1), b, number_styles::hex_number) == false) return false;
    b += b * 16;
    result = color::from_argb(a, r, g, b);
    return true;
  }
  if (text.starts_with("#") &&text.size() == 7U) {
    int32_t rgb;
    if (xtd::try_parse<int>(text.substring(1), rgb, number_styles::hex_number) == false) return false;
    result = color::from_argb(rgb + 0xFF000000);
    return true;
  }
  if (text.starts_with("#") &&text.size() == 9U) {
    int32_t argb;
    if (xtd::try_parse<int>(text.substring(1), argb, number_styles::hex_number) == false) return false;
    result = color::from_argb(argb);
    return true;
  }
  return false;
}

void style_sheet::theme_reader(selector_map::const_iterator& selectors_iterator, theme_selector& theme) const noexcept {
  property_map::const_iterator properties_iterator;
  if ((properties_iterator = selectors_iterator->second.properties().find("name")) != selectors_iterator->second.properties().end()) theme.name(string_from_css(properties_iterator->second.to_string(), ustring()));
  if ((properties_iterator = selectors_iterator->second.properties().find("description")) != selectors_iterator->second.properties().end()) theme.description(string_from_css(properties_iterator->second.to_string(), ustring()));
  if ((properties_iterator = selectors_iterator->second.properties().find("authors")) != selectors_iterator->second.properties().end()) theme.authors(string_from_css(properties_iterator->second.to_string(), ustring()));
  if ((properties_iterator = selectors_iterator->second.properties().find("website")) != selectors_iterator->second.properties().end()) theme.website(uri_from_css(properties_iterator->second.to_string(), uri()));
}
                                                                                                                                                      
void style_sheet::system_color_reader(selector_map::const_iterator& selectors_iterator, system_colors_selector& colors) const noexcept {
  property_map::const_iterator properties_iterator;
  if ((properties_iterator = selectors_iterator->second.properties().find("accent")) != selectors_iterator->second.properties().end()) colors.accent(color_from_css(properties_iterator->second.to_string(), system_colors::accent()));
  if ((properties_iterator = selectors_iterator->second.properties().find("accent-text")) != selectors_iterator->second.properties().end()) colors.accent_text(color_from_css(properties_iterator->second.to_string(), system_colors::accent_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("active-border")) != selectors_iterator->second.properties().end()) colors.active_border(color_from_css(properties_iterator->second.to_string(), system_colors::active_border()));
  if ((properties_iterator = selectors_iterator->second.properties().find("active-caption")) != selectors_iterator->second.properties().end()) colors.active_caption(color_from_css(properties_iterator->second.to_string(), system_colors::active_caption()));
  if ((properties_iterator = selectors_iterator->second.properties().find("active-caption-text")) != selectors_iterator->second.properties().end()) colors.active_caption_text(color_from_css(properties_iterator->second.to_string(), system_colors::active_caption_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("app-workspace")) != selectors_iterator->second.properties().end()) colors.app_workspace(color_from_css(properties_iterator->second.to_string(), system_colors::app_workspace()));
  if ((properties_iterator = selectors_iterator->second.properties().find("button-face")) != selectors_iterator->second.properties().end()) colors.button_face(color_from_css(properties_iterator->second.to_string(), system_colors::button_face()));
  if ((properties_iterator = selectors_iterator->second.properties().find("button-highlight")) != selectors_iterator->second.properties().end()) colors.button_highlight(color_from_css(properties_iterator->second.to_string(), system_colors::button_highlight()));
  if ((properties_iterator = selectors_iterator->second.properties().find("button-shadow")) != selectors_iterator->second.properties().end()) colors.button_shadow(color_from_css(properties_iterator->second.to_string(), system_colors::button_shadow()));
  if ((properties_iterator = selectors_iterator->second.properties().find("control")) != selectors_iterator->second.properties().end()) colors.control(color_from_css(properties_iterator->second.to_string(), system_colors::control()));
  if ((properties_iterator = selectors_iterator->second.properties().find("control-dark")) != selectors_iterator->second.properties().end()) colors.control_dark(color_from_css(properties_iterator->second.to_string(), system_colors::control_dark()));
  if ((properties_iterator = selectors_iterator->second.properties().find("control-dark-dark")) != selectors_iterator->second.properties().end()) colors.control_dark_dark(color_from_css(properties_iterator->second.to_string(), system_colors::control_dark_dark()));
  if ((properties_iterator = selectors_iterator->second.properties().find("control-light")) != selectors_iterator->second.properties().end()) colors.control_light(color_from_css(properties_iterator->second.to_string(), system_colors::control_light()));
  if ((properties_iterator = selectors_iterator->second.properties().find("control-light-light")) != selectors_iterator->second.properties().end()) colors.control_light_light(color_from_css(properties_iterator->second.to_string(), system_colors::control_light_light()));
  if ((properties_iterator = selectors_iterator->second.properties().find("control-text")) != selectors_iterator->second.properties().end()) colors.control_text(color_from_css(properties_iterator->second.to_string(), system_colors::control_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("desktop")) != selectors_iterator->second.properties().end()) colors.desktop(color_from_css(properties_iterator->second.to_string(), system_colors::desktop()));
  if ((properties_iterator = selectors_iterator->second.properties().find("gradient-active-caption")) != selectors_iterator->second.properties().end()) colors.gradient_active_caption(color_from_css(properties_iterator->second.to_string(), system_colors::gradient_active_caption()));
  if ((properties_iterator = selectors_iterator->second.properties().find("gradient-inactive-caption")) != selectors_iterator->second.properties().end()) colors.gradient_inactive_caption(color_from_css(properties_iterator->second.to_string(), system_colors::gradient_inactive_caption()));
  if ((properties_iterator = selectors_iterator->second.properties().find("gray-text")) != selectors_iterator->second.properties().end()) colors.gray_text(color_from_css(properties_iterator->second.to_string(), system_colors::gray_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("highlight")) != selectors_iterator->second.properties().end()) colors.highlight(color_from_css(properties_iterator->second.to_string(), system_colors::highlight()));
  if ((properties_iterator = selectors_iterator->second.properties().find("highlight-text")) != selectors_iterator->second.properties().end()) colors.highlight_text(color_from_css(properties_iterator->second.to_string(), system_colors::highlight_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("hot-track")) != selectors_iterator->second.properties().end()) colors.hot_track(color_from_css(properties_iterator->second.to_string(), system_colors::hot_track()));
  if ((properties_iterator = selectors_iterator->second.properties().find("inactive-border")) != selectors_iterator->second.properties().end()) colors.inactive_border(color_from_css(properties_iterator->second.to_string(), system_colors::inactive_border()));
  if ((properties_iterator = selectors_iterator->second.properties().find("inactive-caption")) != selectors_iterator->second.properties().end()) colors.inactive_caption(color_from_css(properties_iterator->second.to_string(), system_colors::inactive_caption()));
  if ((properties_iterator = selectors_iterator->second.properties().find("inactive-caption-text")) != selectors_iterator->second.properties().end()) colors.inactive_caption_text(color_from_css(properties_iterator->second.to_string(), system_colors::inactive_caption_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("info")) != selectors_iterator->second.properties().end()) colors.info(color_from_css(properties_iterator->second.to_string(), system_colors::info()));
  if ((properties_iterator = selectors_iterator->second.properties().find("info-text")) != selectors_iterator->second.properties().end()) colors.info_text(color_from_css(properties_iterator->second.to_string(), system_colors::info_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("menu")) != selectors_iterator->second.properties().end()) colors.menu(color_from_css(properties_iterator->second.to_string(), system_colors::menu()));
  if ((properties_iterator = selectors_iterator->second.properties().find("menu-bar")) != selectors_iterator->second.properties().end()) colors.menu_bar(color_from_css(properties_iterator->second.to_string(), system_colors::menu_bar()));
  if ((properties_iterator = selectors_iterator->second.properties().find("menu-highlight")) != selectors_iterator->second.properties().end()) colors.menu_highlight(color_from_css(properties_iterator->second.to_string(), system_colors::menu_highlight()));
  if ((properties_iterator = selectors_iterator->second.properties().find("menu-text")) != selectors_iterator->second.properties().end()) colors.menu_text(color_from_css(properties_iterator->second.to_string(), system_colors::menu_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("scroll-bar")) != selectors_iterator->second.properties().end()) colors.scroll_bar(color_from_css(properties_iterator->second.to_string(), system_colors::scroll_bar()));
  if ((properties_iterator = selectors_iterator->second.properties().find("text-box")) != selectors_iterator->second.properties().end()) colors.text_box(color_from_css(properties_iterator->second.to_string(), system_colors::text_box()));
  if ((properties_iterator = selectors_iterator->second.properties().find("text-box-text")) != selectors_iterator->second.properties().end()) colors.text_box_text(color_from_css(properties_iterator->second.to_string(), system_colors::text_box_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("window")) != selectors_iterator->second.properties().end()) colors.window(color_from_css(properties_iterator->second.to_string(), system_colors::window()));
  if ((properties_iterator = selectors_iterator->second.properties().find("window-frame")) != selectors_iterator->second.properties().end()) colors.window_frame(color_from_css(properties_iterator->second.to_string(), system_colors::window_frame()));
  if ((properties_iterator = selectors_iterator->second.properties().find("window-text")) != selectors_iterator->second.properties().end()) colors.window_text(color_from_css(properties_iterator->second.to_string(), system_colors::window_text()));
}

bool style_sheet::try_parse_rgb_color(const ustring& text, color& result) const noexcept {
  auto value = text.remove(text.size()-1).replace("rgb(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 3) return false;
  byte_t r = 0;
  if (xtd::try_parse<byte_t>(color_parts[0], r) == false) return false;
  byte_t g = 0;
  if (xtd::try_parse<byte_t>(color_parts[1], g) == false) return false;
  byte_t b = 0;
  if (xtd::try_parse<byte_t>(color_parts[2], b) == false) return false;
  result = color::from_argb(r, g, b);
  return true;
}

bool style_sheet::try_parse_rgba_color(const ustring& text, color& result) const noexcept {
  auto value = text.remove(text.size()-1).replace("rgba(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 4) return false;
  byte_t r = 0;
  if (xtd::try_parse<byte_t>(color_parts[0], r) == false) return false;
  byte_t g = 0;
  if (xtd::try_parse<byte_t>(color_parts[1], g) == false) return false;
  byte_t b = 0;
  if (xtd::try_parse<byte_t>(color_parts[2], b) == false) return false;
  byte_t a = 0;
  if (xtd::try_parse<byte_t>(color_parts[3], a) == false) return false;
  result = color::from_argb(a, r, g, b);
  return true;
}

bool style_sheet::try_parse_argb_color(const ustring& text, color& result) const noexcept {
  auto value = text.remove(text.size()-1).replace("argb(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 4) return false;
  byte_t a = 0;
  if (xtd::try_parse<byte_t>(color_parts[0], a) == false) return false;
  byte_t r = 0;
  if (xtd::try_parse<byte_t>(color_parts[1], r) == false) return false;
  byte_t g = 0;
  if (xtd::try_parse<byte_t>(color_parts[2], g) == false) return false;
  byte_t b = 0;
  if (xtd::try_parse<byte_t>(color_parts[3], b) == false) return false;
  result = color::from_argb(a, r, g, b);
  return true;
}

bool style_sheet::try_parse_hsv_color(const ustring& text, color& result) const noexcept {
  auto value = text.remove(text.size()-1).replace("hsv(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 3) return false;
  float h = 0;
  if (xtd::try_parse<float>(color_parts[0], h) == false) return false;
  float s = 0;
  if (xtd::try_parse<float>(color_parts[1], s) == false) return false;
  float v = 0;
  if (xtd::try_parse<float>(color_parts[2], v) == false) return false;
  result = color::from_hsb(h, s, v);
  return true;
}

bool style_sheet::try_parse_hsva_color(const ustring& text, color& result) const noexcept {
  auto value = text.remove(text.size()-1).replace("hsva(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 4) return false;
  float h = 0;
  if (xtd::try_parse<float>(color_parts[0], h) == false) return false;
  float s = 0;
  if (xtd::try_parse<float>(color_parts[1], s) == false) return false;
  float v = 0;
  if (xtd::try_parse<float>(color_parts[2], v) == false) return false;
  byte_t a = 0;
  if (xtd::try_parse<byte_t>(color_parts[3], a) == false) return false;
  result = color::from_argb(a, color::from_hsb(h, s, v));
  return true;
}

bool style_sheet::try_parse_ahsv_color(const ustring& text, color& result) const noexcept {
  auto value = text.remove(text.size()-1).replace("ahsv(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 4) return false;
  byte_t a = 0;
  if (xtd::try_parse<byte_t>(color_parts[0], a) == false) return false;
  float h = 0;
  if (xtd::try_parse<float>(color_parts[1], h) == false) return false;
  float s = 0;
  if (xtd::try_parse<float>(color_parts[2], s) == false) return false;
  float v = 0;
  if (xtd::try_parse<float>(color_parts[3], v) == false) return false;
  result = color::from_argb(a, color::from_hsb(h, s, v));
  return true;
}

bool style_sheet::try_parse_hsl_color(const ustring& text, color& result) const noexcept {
  auto value = text.remove(text.size()-1).replace("hsl(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 3) return false;
  float h = 0;
  if (xtd::try_parse<float>(color_parts[0], h) == false) return false;
  float s = 0;
  if (xtd::try_parse<float>(color_parts[1], s) == false) return false;
  float l = 0;
  if (xtd::try_parse<float>(color_parts[2], l) == false) return false;
  result = color::from_hsl(h, s, l);
  return true;
}

bool style_sheet::try_parse_hsla_color(const ustring& text, color& result) const noexcept {
  auto value = text.remove(text.size()-1).replace("hsla(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 4) return false;
  float h = 0;
  if (xtd::try_parse<float>(color_parts[0], h) == false) return false;
  float s = 0;
  if (xtd::try_parse<float>(color_parts[1], s) == false) return false;
  float l = 0;
  if (xtd::try_parse<float>(color_parts[2], l) == false) return false;
  byte_t a = 0;
  if (xtd::try_parse<byte_t>(color_parts[3], a) == false) return false;
  result = color::from_argb(a, color::from_hsl(h, s, l));
  return true;
}

bool style_sheet::try_parse_ahsl_color(const ustring& text, color& result) const noexcept {
  auto value = text.remove(text.size()-1).replace("ahsl(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 4) return false;
  byte_t a = 0;
  if (xtd::try_parse<byte_t>(color_parts[0], a) == false) return false;
  float h = 0;
  if (xtd::try_parse<float>(color_parts[1], h) == false) return false;
  float s = 0;
  if (xtd::try_parse<float>(color_parts[2], s) == false) return false;
  float l = 0;
  if (xtd::try_parse<float>(color_parts[3], l) == false) return false;
  result = color::from_argb(a, color::from_hsl(h, s, l));
  return true;
}

bool style_sheet::try_parse_named_color(const ustring& text, color& result) const noexcept {
  if (text.trim().find(" ") != ustring::npos) return false;
  result = color::from_name(text);
  return result.is_known_color();
}

bool style_sheet::try_parse_system_color(const ustring& text, color& result) const noexcept {
  auto value = text.remove(text.size()-1).replace("system-color(", "");
  /// @todo Replace drawing::system_colors by theme::system_colors
  static map<ustring, drawing::color> colors {{"accent", system_colors().accent()}, {"accent-text", system_colors().accent_text()}, {"active-border", system_colors().active_border()}, {"active-caption", system_colors().active_caption()}, {"active-caption-text", system_colors().active_caption_text()}, {"app-workspace", system_colors().app_workspace()}, {"button-face", system_colors().button_face()}, {"button-highlight", system_colors().button_highlight()}, {"button-shadow", system_colors().button_shadow()}, {"control", system_colors().control()}, {"control-dark", system_colors().control_dark()}, {"control-dark-dark", system_colors().control_dark_dark()}, {"control-light", system_colors().control_light()}, {"control-light-light", system_colors().control_light_light()}, {"control-text", system_colors().control_text()}, {"desktop", system_colors().desktop()}, {"gradient-active-caption", system_colors().gradient_active_caption()}, {"gradient-inactive-caption", system_colors().gradient_inactive_caption()}, {"gray-text", system_colors().gray_text()}, {"highlight", system_colors().highlight()}, {"highlight-text", system_colors().highlight_text()}, {"hot-track", system_colors().hot_track()}, {"inactive-border", system_colors().inactive_border()}, {"inactive-caption", system_colors().inactive_caption()}, {"inactive-caption-text", system_colors().inactive_caption_text()}, {"info", system_colors().info()}, {"info-text", system_colors().info_text()}, {"menu", system_colors().menu()}, {"menu-bar", system_colors().menu_bar()}, {"menu-highlight", system_colors().menu_highlight()}, {"menu-text", system_colors().menu_text()}, {"scroll-bar", system_colors().scroll_bar()}, {"text-box", system_colors().text_box()}, {"text-box-text", system_colors().text_box_text()}, {"window", system_colors().window()}, {"window-frame", system_colors().window_frame()}, {"window-text", system_colors().window_text()}};
  auto it = colors.find(value);
  if (it == colors.end()) return false;
  result = it->second;
  return true;
}

uri style_sheet::uri_from_css(const ustring& css_text, const uri& default_value) const noexcept {
  if (!css_text.starts_with("url") || !css_text.ends_with(")")) return default_value;
  return uri(css_text.remove(css_text.size() - 1, 1).replace("url(", ""));
}
