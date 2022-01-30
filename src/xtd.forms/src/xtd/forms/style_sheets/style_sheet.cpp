#include "../../../../include/xtd/forms/style_sheets/style_sheet.h"
#include <xtd/as.h>
#include <xtd/is.h>
#include <xtd/environment.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/drawing2d/linear_gradient_brush.h>
#include <xtd/forms/application.h>
#include <xtd/io/directory.h>
#include <xtd/io/file.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::io;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::web::css;

const style_sheet style_sheet::empty;
event<style_sheet, event_handler> style_sheet::current_style_sheet_changed;
style_sheet style_sheet::current_style_sheets_;
std::map<ustring, style_sheet> style_sheet::style_sheets_;

style_sheet::style_sheet(const ustring& text) {
  *this = system_style_sheet();
  css_reader reader(text);
  selector_map::const_iterator selectors_iterator;
  if ((selectors_iterator = reader.selectors().find("theme")) != reader.selectors().end()) theme_reader(selectors_iterator, theme_);
  if ((selectors_iterator = reader.selectors().find("system-colors")) != reader.selectors().end()) system_color_reader(selectors_iterator, system_colors_);
}

const xtd::forms::style_sheets::button& style_sheet::button() const noexcept {
  return button(pseudo_state::standard);
}

const xtd::forms::style_sheets::button& style_sheet::button(pseudo_state state) const noexcept {
  static xtd::forms::style_sheets::button fallback = buttons_.find(pseudo_state::standard) != buttons_.end() ? buttons_.find(state)->second : button();
  auto it = buttons_.find(state);
  if (it == buttons_.end()) return fallback;
  return it->second;
}

const xtd::forms::style_sheets::control& style_sheet::control() const noexcept {
  return control(pseudo_state::standard);
}

const xtd::forms::style_sheets::control& style_sheet::control(pseudo_state state) const noexcept {
  static xtd::forms::style_sheets::control fallback = controls_.find(pseudo_state::standard) != controls_.end() ? controls_.find(state)->second : control();
  auto it = controls_.find(state);
  if (it == controls_.end()) return fallback;
  return it->second;
}

style_sheet style_sheet::current_style_sheet() noexcept {
  if (current_style_sheets_ == style_sheet::empty) current_style_sheets_ = system_style_sheet();
  return current_style_sheets_;
}

void style_sheet::current_style_sheet(const style_sheet& value) {
  if (value == style_sheet::empty) throw argument_exception(csf_);
  if (current_style_sheets_ != value) {
    current_style_sheets_ = value;
    on_current_style_sheet_changed(event_args::empty);
  }
}

const xtd::forms::style_sheets::form& style_sheet::form() const noexcept {
  return form(pseudo_state::standard);
}

const xtd::forms::style_sheets::form& style_sheet::form(pseudo_state state) const noexcept {
  static xtd::forms::style_sheets::form fallback = forms_.find(pseudo_state::standard) != forms_.end() ? forms_.find(state)->second : form();
  auto it = forms_.find(state);
  if (it == forms_.end()) return fallback;
  return it->second;
}

const xtd::forms::style_sheets::label& style_sheet::label() const noexcept {
  return label(pseudo_state::standard);
}

const xtd::forms::style_sheets::label& style_sheet::label(pseudo_state state) const noexcept {
  static xtd::forms::style_sheets::label fallback = labels_.find(pseudo_state::standard) != labels_.end() ? labels_.find(state)->second : label();
  auto it = labels_.find(state);
  if (it == labels_.end()) return fallback;
  return it->second;
}

const map<ustring, style_sheet> style_sheet::style_sheets() noexcept {
  initilize();
  return style_sheets_;
}

const xtd::forms::style_sheets::system_colors& style_sheet::system_colors()const noexcept {
  return system_colors_;
}


style_sheet style_sheet::system_style_sheet() noexcept {
  bool static init = false;
  static style_sheet system_style_sheet;
  if (init) return system_style_sheet;
  init = true;

  if (environment::os_version().is_linux()) {
    if (environment::os_version().desktop_environment() == "kde" && application::dark_mode_enabled())
      system_style_sheet = system_style_sheet_kde_dark();
    else if (environment::os_version().desktop_environment() == "kde" && !application::dark_mode_enabled())
      system_style_sheet = system_style_sheet_kde_light();
    else if (application::dark_mode_enabled())
      system_style_sheet = system_style_sheet_gnome_dark();
    else
      system_style_sheet = system_style_sheet_gnome_light();
  } else if (environment::os_version().is_macos()) {
    if (application::dark_mode_enabled())
      system_style_sheet = system_style_sheet_macos_dark();
    else
      system_style_sheet = system_style_sheet_macos_light();
  } else {
    if (application::dark_mode_enabled())
      system_style_sheet = system_style_sheet_windows_dark();
    else
      system_style_sheet = system_style_sheet_windows_light();
  }
  
  return system_style_sheet;
}

const xtd::forms::style_sheets::theme& style_sheet::theme() const noexcept {
  return theme_;
}

bool style_sheet::equals(const object& other) const noexcept {
  return is<style_sheet>(other) ? equals(static_cast<const style_sheet&>(other)) : false;
}

bool style_sheet::equals(const style_sheet& other) const noexcept {
  return theme_ == theme_;
}

border_color style_sheet::border_color_from_css(const xtd::ustring& css_text, const border_color& default_value) const noexcept {
  vector<ustring> colors = split_colors_from_text(css_text);
  if (colors.size() < 1 || colors.size() > 4) return default_value;
  border_color result;
  result.all(color_from_css(colors[0], default_value.top()));
  if (colors.size() >= 2) result.right(color_from_css(colors[0], default_value.right()));
  if (colors.size() >= 3) result.bottom(color_from_css(colors[0], default_value.right()));
  if (colors.size() == 4) result.left(color_from_css(colors[0], default_value.right()));
  return result;
}

style_sheets::border_style style_sheet::border_style_from_css(const ustring& text, const border_style& default_value) const noexcept {
  auto border_styles = text.split();
  static map<ustring, xtd::forms::style_sheets::border_type> border_types = {{"none", border_type::none}, {"hidden", border_type::hidden}, {"dashed", border_type::dashed}, {"dot-dash", border_type::dot_dash},  {"dot-dot-dash", border_type::dot_dot_dash}, {"dotted", border_type::dotted}, {"double", border_type::double_border}, {"groove", border_type::groove}, {"inset", border_type::inset}, {"outset", border_type::outset}, {"ridge", border_type::ridge}, {"solid", border_type::solid}};
  if (border_styles.size() < 1 || border_styles.size() > 4) return default_value;
  
  border_style result;
  auto it = border_types.find(border_styles[0]);
  if (it == border_types.end()) return default_value;
  result.all(it->second);
  
  if (border_styles.size() >= 2) {
    it = border_types.find(border_styles[1]);
    if (it == border_types.end()) return default_value;
    result.right(it->second);
  }
  if (border_styles.size() >= 3) {
    it = border_types.find(border_styles[2]);
    if (it == border_types.end()) return default_value;
    result.bottom(it->second);
  }
  if (border_styles.size() == 4) {
    it = border_types.find(border_styles[3]);
    if (it == border_types.end()) return default_value;
    result.left(it->second);
  }
  
  return result;
}

xtd::drawing::color style_sheet::color_from_css(const ustring& css_text, const color& default_value) const noexcept {
  color result = default_value;
  try_parse_color(css_text, result);
  return result;
}

background_image style_sheet::background_image_from_css(const xtd::ustring& css_text, const background_image& default_value) const noexcept {
  background_image result;;
  if (css_text.starts_with("url(") && css_text.ends_with(")") && try_parse_uri(css_text, result.url_)) return result;
  if (css_text.starts_with("linear-gradient(") && css_text.ends_with(")") && try_parse_linear_gradient(css_text, result)) return result;
  return default_value;
}

length style_sheet::length_from_css(const xtd::ustring& css_text, const length& default_value) const noexcept {
  if (css_text == "auto" || css_text == "initial" || css_text == "inherit") return length(-1);
  auto l = .0;
  if (css_text.ends_with("cm") && ::try_parse<double>(css_text.replace("cm", ""), l)) return length(l, length_unit::centimeters);
  if (css_text.ends_with("mm") && ::try_parse<double>(css_text.replace("mm", ""), l)) return length(l, length_unit::millimeters);
  if (css_text.ends_with("in") && ::try_parse<double>(css_text.replace("in", ""), l)) return length(l, length_unit::inches);
  if (css_text.ends_with("px") && ::try_parse<double>(css_text.replace("px", ""), l)) return length(l, length_unit::pixels);
  if (css_text.ends_with("pt") && ::try_parse<double>(css_text.replace("pt", ""), l)) return length(l, length_unit::points);
  if (css_text.ends_with("pc") && ::try_parse<double>(css_text.replace("pc", ""), l)) return length(l, length_unit::picas);
  if (css_text.ends_with("em") && ::try_parse<double>(css_text.replace("em", ""), l)) return length(l, length_unit::element);
  if (css_text.ends_with("ex") && ::try_parse<double>(css_text.replace("ex", ""), l)) return length(l, length_unit::element_x_height);
  if (css_text.ends_with("ch") && ::try_parse<double>(css_text.replace("ch", ""), l)) return length(l, length_unit::chase);
  if (css_text.ends_with("rem") && ::try_parse<double>(css_text.replace("rem", ""), l)) return length(l, length_unit::root_element);
  if (css_text.ends_with("vw") && ::try_parse<double>(css_text.replace("vw", ""), l)) return length(l, length_unit::viewport_width);
  if (css_text.ends_with("vh") && ::try_parse<double>(css_text.replace("vh", ""), l)) return length(l, length_unit::viewport_height);
  if (css_text.ends_with("vmin") && ::try_parse<double>(css_text.replace("vmin", ""), l)) return length(l, length_unit::viewport_min);
  if (css_text.ends_with("vmax") && ::try_parse<double>(css_text.replace("vmax", ""), l)) return length(l, length_unit::viewport_max);
  if (css_text.ends_with("%") && ::try_parse<double>(css_text.replace("%", ""), l)) return length(l, length_unit::percent);
  if (css_text == "0") return length(0);
  return default_value;
}

ustring style_sheet::string_from_css(const xtd::ustring& css_text, const ustring& default_value) const noexcept {
  auto value = css_text.trim();
  if (!value.starts_with("\"") || !value.ends_with("\"")) return default_value;
  return value.remove(value.size() - 1, 1).replace("\"", "");
}

uri style_sheet::uri_from_css(const ustring& css_text, const uri& default_value) const noexcept {
  auto result = default_value;
  try_parse_uri(css_text, result);
  return result;;
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

vector<ustring> style_sheet::split_colors_from_text(const ustring& text) const noexcept {
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

void style_sheet::system_color_reader(selector_map::const_iterator& selectors_iterator, xtd::forms::style_sheets::system_colors& colors) const noexcept {
  property_map::const_iterator properties_iterator;
  if ((properties_iterator = selectors_iterator->second.properties().find("accent")) != selectors_iterator->second.properties().end()) colors.accent(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::accent()));
  if ((properties_iterator = selectors_iterator->second.properties().find("accent-text")) != selectors_iterator->second.properties().end()) colors.accent_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::accent_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("active-border")) != selectors_iterator->second.properties().end()) colors.active_border(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::active_border()));
  if ((properties_iterator = selectors_iterator->second.properties().find("active-caption")) != selectors_iterator->second.properties().end()) colors.active_caption(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::active_caption()));
  if ((properties_iterator = selectors_iterator->second.properties().find("active-caption-text")) != selectors_iterator->second.properties().end()) colors.active_caption_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::active_caption_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("app-workspace")) != selectors_iterator->second.properties().end()) colors.app_workspace(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::app_workspace()));
  if ((properties_iterator = selectors_iterator->second.properties().find("button-face")) != selectors_iterator->second.properties().end()) colors.button_face(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::button_face()));
  if ((properties_iterator = selectors_iterator->second.properties().find("button-highlight")) != selectors_iterator->second.properties().end()) colors.button_highlight(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::button_highlight()));
  if ((properties_iterator = selectors_iterator->second.properties().find("button-shadow")) != selectors_iterator->second.properties().end()) colors.button_shadow(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::button_shadow()));
  if ((properties_iterator = selectors_iterator->second.properties().find("control")) != selectors_iterator->second.properties().end()) colors.control(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::control()));
  if ((properties_iterator = selectors_iterator->second.properties().find("control-dark")) != selectors_iterator->second.properties().end()) colors.control_dark(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::control_dark()));
  if ((properties_iterator = selectors_iterator->second.properties().find("control-dark-dark")) != selectors_iterator->second.properties().end()) colors.control_dark_dark(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::control_dark_dark()));
  if ((properties_iterator = selectors_iterator->second.properties().find("control-light")) != selectors_iterator->second.properties().end()) colors.control_light(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::control_light()));
  if ((properties_iterator = selectors_iterator->second.properties().find("control-light-light")) != selectors_iterator->second.properties().end()) colors.control_light_light(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::control_light_light()));
  if ((properties_iterator = selectors_iterator->second.properties().find("control-text")) != selectors_iterator->second.properties().end()) colors.control_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::control_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("desktop")) != selectors_iterator->second.properties().end()) colors.desktop(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::desktop()));
  if ((properties_iterator = selectors_iterator->second.properties().find("gradient-active-caption")) != selectors_iterator->second.properties().end()) colors.gradient_active_caption(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::gradient_active_caption()));
  if ((properties_iterator = selectors_iterator->second.properties().find("gradient-inactive-caption")) != selectors_iterator->second.properties().end()) colors.gradient_inactive_caption(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::gradient_inactive_caption()));
  if ((properties_iterator = selectors_iterator->second.properties().find("gray-text")) != selectors_iterator->second.properties().end()) colors.gray_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::gray_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("highlight")) != selectors_iterator->second.properties().end()) colors.highlight(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::highlight()));
  if ((properties_iterator = selectors_iterator->second.properties().find("highlight-text")) != selectors_iterator->second.properties().end()) colors.highlight_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::highlight_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("hot-track")) != selectors_iterator->second.properties().end()) colors.hot_track(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::hot_track()));
  if ((properties_iterator = selectors_iterator->second.properties().find("inactive-border")) != selectors_iterator->second.properties().end()) colors.inactive_border(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::inactive_border()));
  if ((properties_iterator = selectors_iterator->second.properties().find("inactive-caption")) != selectors_iterator->second.properties().end()) colors.inactive_caption(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::inactive_caption()));
  if ((properties_iterator = selectors_iterator->second.properties().find("inactive-caption-text")) != selectors_iterator->second.properties().end()) colors.inactive_caption_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::inactive_caption_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("info")) != selectors_iterator->second.properties().end()) colors.info(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::info()));
  if ((properties_iterator = selectors_iterator->second.properties().find("info-text")) != selectors_iterator->second.properties().end()) colors.info_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::info_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("menu")) != selectors_iterator->second.properties().end()) colors.menu(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::menu()));
  if ((properties_iterator = selectors_iterator->second.properties().find("menu-bar")) != selectors_iterator->second.properties().end()) colors.menu_bar(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::menu_bar()));
  if ((properties_iterator = selectors_iterator->second.properties().find("menu-highlight")) != selectors_iterator->second.properties().end()) colors.menu_highlight(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::menu_highlight()));
  if ((properties_iterator = selectors_iterator->second.properties().find("menu-text")) != selectors_iterator->second.properties().end()) colors.menu_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::menu_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("scroll-bar")) != selectors_iterator->second.properties().end()) colors.scroll_bar(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::scroll_bar()));
  if ((properties_iterator = selectors_iterator->second.properties().find("text-box")) != selectors_iterator->second.properties().end()) colors.text_box(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::text_box()));
  if ((properties_iterator = selectors_iterator->second.properties().find("text-box-text")) != selectors_iterator->second.properties().end()) colors.text_box_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::text_box_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("window")) != selectors_iterator->second.properties().end()) colors.window(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::window()));
  if ((properties_iterator = selectors_iterator->second.properties().find("window-frame")) != selectors_iterator->second.properties().end()) colors.window_frame(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::window_frame()));
  if ((properties_iterator = selectors_iterator->second.properties().find("window-text")) != selectors_iterator->second.properties().end()) colors.window_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::window_text()));
}

void style_sheet::theme_reader(selector_map::const_iterator& selectors_iterator, xtd::forms::style_sheets::theme& theme) const noexcept {
  property_map::const_iterator properties_iterator;
  if ((properties_iterator = selectors_iterator->second.properties().find("name")) != selectors_iterator->second.properties().end()) theme.name(string_from_css(properties_iterator->second.to_string(), ustring()));
  if ((properties_iterator = selectors_iterator->second.properties().find("description")) != selectors_iterator->second.properties().end()) theme.description(string_from_css(properties_iterator->second.to_string(), ustring()));
  if ((properties_iterator = selectors_iterator->second.properties().find("authors")) != selectors_iterator->second.properties().end()) theme.authors(string_from_css(properties_iterator->second.to_string(), ustring()));
  if ((properties_iterator = selectors_iterator->second.properties().find("website")) != selectors_iterator->second.properties().end()) theme.website(uri_from_css(properties_iterator->second.to_string(), uri()));
}

bool style_sheet::try_parse_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept {
  if (text.starts_with("#") && try_parse_hex_color(text, result)) return true;
  if (text.starts_with("rgb(") && text.ends_with(")") && try_parse_rgb_color(text, result)) return true;
  if (text.starts_with("rgba(") && text.ends_with(")") && try_parse_rgba_color(text, result)) return true;
  if (text.starts_with("argb(") && text.ends_with(")") && try_parse_argb_color(text, result)) return true;
  if (text.starts_with("hsv(") && text.ends_with(")") && try_parse_hsv_color(text, result)) return true;
  if (text.starts_with("hsva(") && text.ends_with(")") && try_parse_hsva_color(text, result)) return true;
  if (text.starts_with("ahsv(") && text.ends_with(")") && try_parse_ahsv_color(text, result)) return true;
  if (text.starts_with("hsl(") && text.ends_with(")") && try_parse_hsl_color(text, result)) return true;
  if (text.starts_with("hsla(") && text.ends_with(")") && try_parse_hsla_color(text, result)) return true;
  if (text.starts_with("ahsl(") && text.ends_with(")") && try_parse_ahsl_color(text, result)) return true;
  if (text.starts_with("system-color(") && text.ends_with(")") && try_parse_system_color(text, result)) return true;
  if (try_parse_named_color(text, result)) return true;
  return false;
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
  if (text.starts_with("#") && text.size() == 7U) {
    int32_t rgb;
    if (xtd::try_parse<int>(text.substring(1), rgb, number_styles::hex_number) == false) return false;
    result = color::from_argb(rgb + 0xFF000000);
    return true;
  }
  if (text.starts_with("#") && text.size() == 9U) {
    int32_t argb;
    if (xtd::try_parse<int>(text.substring(1), argb, number_styles::hex_number) == false) return false;
    result = color::from_argb(argb);
    return true;
  }
  return false;
}

bool style_sheet::try_parse_linear_gradient(const xtd::ustring& text, background_image& result) const noexcept {
  vector<ustring> arguments = split_colors_from_text(text.remove(text.size()-1).replace("linear-gradient(", ""));
  vector<color> colors;
  int32_t angle = -1;
  for (auto argument : arguments) {
    drawing::color color;
    if (argument == "to top") {
      if (angle != -1) return false;
      angle = 0;
    } else if (argument == "to top right") {
      if (angle != -1) return false;
      angle = 45;
    } else if (argument == "to right") {
      if (angle != -1) return false;
      angle = 90;
    } else if (argument == "to bottom right") {
      if (angle != -1) return false;
      angle = 135;
    } else if (argument == "to bottom") {
      if (angle != -1) return false;
      angle = 180;
    } else if (argument == "to bottom left") {
      if (angle != -1) return false;
      angle = 225;
    } else if (argument == "to left") {
      if (angle != -1) return false;
      angle = 270;
    } else if (argument == "to top left") {
      if (angle != -1) return false;
      angle = 315;
    } else if (argument.ends_with("deg")) {
      argument = argument.replace("deg", "");
      if (angle != -1 || xtd::try_parse<int32_t>(argument, angle) == false) return false;
    } else if (try_parse_color(argument, color))
      colors.push_back(color);
  }
  if (colors.size() < 2) return false;
  result = background_image(style_sheets::image_type::linear_gradient, colors, angle == -1? 180 : angle);
  return true;
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
  auto named_color = color::from_name(text);
  if (!named_color.is_known_color()) return false;
  result = named_color;
  return true;
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

bool style_sheet::try_parse_uri(const xtd::ustring& text, xtd::uri& result) const noexcept {
  if (!text.starts_with("url") || !text.ends_with(")")) return false;
  result = uri(text.remove(text.size() - 1, 1).replace("url(", ""));
  return true;
}
