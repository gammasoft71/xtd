#include "../../../../include/xtd/forms/style_sheets/style_sheet.h"
#include <xtd/as.h>
#include <xtd/is.h>
#include <xtd/environment.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/drawing2d/linear_gradient_brush.h>
#include <xtd/forms/application.h>
#include <xtd/io/directory.h>
#include <xtd/io/file.h>
#include <xtd/io/directory_not_found_exception.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::io;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::web::css;

namespace {
  xtd::ustring get_css_string_from_path(const xtd::ustring& path_name) {
    if (!xtd::io::directory::exists(path_name)) throw xtd::io::directory_not_found_exception(csf_);
    xtd::ustring theme_css;
    for (auto theme_file : directory::enumerate_files(path_name, "*.css"))
      theme_css += file::read_all_text(theme_file);
    return theme_css;
  }
}

const style_sheet style_sheet::empty;
event<style_sheet, event_handler> style_sheet::style_sheet_changed;
style_sheet style_sheet::current_style_sheet_;
style_sheet::style_sheets_t style_sheet::style_sheets_;
style_sheet::style_sheet_names_t style_sheet::style_sheet_names_;
style_sheet style_sheet::system_style_sheet_;

style_sheet::style_sheet(const ustring& css_text) : style_sheet(css_text, true) {
}

style_sheet::style_sheet(const xtd::ustring& css_text, bool init_system) {
  if (init_system) *this = system_style_sheet();
  else {
    system_colors_.accent(drawing::system_colors::accent());
    system_colors_.accent_text(drawing::system_colors::accent_text());
    system_colors_.active_border(drawing::system_colors::active_border());
    system_colors_.active_caption(drawing::system_colors::active_caption());
    system_colors_.active_caption_text(drawing::system_colors::active_caption_text());
    system_colors_.app_workspace(drawing::system_colors::app_workspace());
    system_colors_.button_face(drawing::system_colors::button_face());
    system_colors_.button_highlight(drawing::system_colors::button_highlight());
    system_colors_.button_shadow(drawing::system_colors::button_shadow());
    system_colors_.control(drawing::system_colors::control());
    system_colors_.control_dark(drawing::system_colors::control_dark());
    system_colors_.control_dark_dark(drawing::system_colors::control_dark_dark());
    system_colors_.control_light(drawing::system_colors::control_light());
    system_colors_.control_light_light(drawing::system_colors::control_light_light());
    system_colors_.control_text(drawing::system_colors::control_text());
    system_colors_.desktop(drawing::system_colors::desktop());
    system_colors_.gradient_active_caption(drawing::system_colors::gradient_active_caption());
    system_colors_.gradient_inactive_caption(drawing::system_colors::gradient_inactive_caption());
    system_colors_.gray_text(drawing::system_colors::gray_text());
    system_colors_.highlight(drawing::system_colors::highlight());
    system_colors_.highlight_text(drawing::system_colors::highlight_text());
    system_colors_.hot_track(drawing::system_colors::hot_track());
    system_colors_.inactive_border(drawing::system_colors::inactive_border());
    system_colors_.inactive_caption(drawing::system_colors::inactive_caption());
    system_colors_.inactive_caption_text(drawing::system_colors::inactive_caption_text());
    system_colors_.info(drawing::system_colors::info());
    system_colors_.info_text(drawing::system_colors::info_text());
    system_colors_.menu(drawing::system_colors::menu());
    system_colors_.menu_bar(drawing::system_colors::menu_bar());
    system_colors_.menu_highlight(drawing::system_colors::menu_highlight());
    system_colors_.menu_text(drawing::system_colors::menu_text());
    system_colors_.scroll_bar(drawing::system_colors::scroll_bar());
    system_colors_.text_box(drawing::system_colors::text_box());
    system_colors_.text_box_text(drawing::system_colors::text_box_text());
    system_colors_.window(drawing::system_colors::window());
    system_colors_.window_frame(drawing::system_colors::window_frame());
    system_colors_.window_text(drawing::system_colors::window_text());
  }
  css_reader reader(css_text);
  theme_reader(reader);
  system_colors_reader(reader);
  button_reader(reader);
  control_reader(reader);
}

const xtd::forms::style_sheets::button& style_sheet::button() const noexcept {
  return button(pseudo_state::standard);
}

const xtd::forms::style_sheets::button& style_sheet::button(pseudo_state state) const noexcept {
  static xtd::forms::style_sheets::button fallback;
  fallback = buttons_.find(pseudo_state::standard) != buttons_.end() ? buttons_.find(state)->second : xtd::forms::style_sheets::button();
  auto it = buttons_.find(state);
  if (it == buttons_.end()) return fallback;
  return it->second;
}

const style_sheet::buttons_t& style_sheet::buttons() const noexcept {
  return buttons_;
}

const xtd::forms::style_sheets::control& style_sheet::control() const noexcept {
  return control(pseudo_state::standard);
}

const xtd::forms::style_sheets::control& style_sheet::control(pseudo_state state) const noexcept {
  static xtd::forms::style_sheets::control fallback;
  fallback = controls_.find(pseudo_state::standard) != controls_.end() ? controls_.find(state)->second : xtd::forms::style_sheets::control();
  auto it = controls_.find(state);
  if (it == controls_.end()) return fallback;
  return it->second;
}

const style_sheet::controls_t& style_sheet::controls() const noexcept {
  return controls_;
}

const style_sheet& style_sheet::current_style_sheet() noexcept {
  if (current_style_sheet_ == style_sheet::empty) current_style_sheet(system_style_sheet());
  return current_style_sheet_;
}

void style_sheet::current_style_sheet(const style_sheet& value) {
  if (value == style_sheet::empty) throw argument_exception(csf_);
  if (current_style_sheet_ != value) {
    current_style_sheet_ = value;
    on_style_sheet_changed(event_args::empty);
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

const style_sheet::forms_t& style_sheet::forms() const noexcept {
  return forms_;
}

bool style_sheet::is_system_style_sheet() const noexcept {
  return *this == system_style_sheet();
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

const style_sheet::labels_t& style_sheet::labels() const noexcept {
  return forms_;
}

const style_sheet::style_sheets_t& style_sheet::style_sheets() noexcept {
  if (!style_sheets_.empty()) return style_sheets_;
  
  for (auto theme_dir : directory::enumerate_directories(__XTD_THEMES_PATH__)) {
    xtd::ustring theme_css;
    for (auto theme_file : directory::enumerate_files(theme_dir, "*.css"))
      theme_css += file::read_all_text(theme_file);
    style_sheet style(theme_css);
    if (!style.theme().name().empty())
      style_sheets_[style.theme().name()] = style;
  }
  return style_sheets_;
}

const style_sheet::style_sheet_names_t& style_sheet::style_sheet_names() noexcept {
  if (!style_sheet_names_.empty()) return style_sheet_names_;
  
  for (auto theme_dir : directory::enumerate_directories(__XTD_THEMES_PATH__)) {
    if (!file::exists(path::combine(theme_dir, "theme.css"))) continue;
    css_reader reader(file::read_all_text(path::combine(theme_dir, "theme.css")));
    selector_map::const_iterator selectors_iterator =  reader.selectors().find("theme");
    if (selectors_iterator == reader.selectors().end()) continue;
    property_map::const_iterator properties_iterator;
    if ((properties_iterator = selectors_iterator->second.properties().find("name")) != selectors_iterator->second.properties().end()) style_sheet_names_.push_back(properties_iterator->second.to_string().trim().trim('\"'));
  }
  return style_sheet_names_;
}

const xtd::forms::style_sheets::system_colors& style_sheet::system_colors()const noexcept {
  return system_colors_;
}

const style_sheet& style_sheet::system_style_sheet() noexcept {
  if (system_style_sheet_ != style_sheet::empty) return system_style_sheet_;
  
  if (environment::os_version().is_linux()) {
    if (environment::os_version().desktop_environment() == "kde" && application::dark_mode_enabled()) system_style_sheet_ = style_sheet(get_css_string_from_path(xtd::io::path::combine(__XTD_THEMES_PATH__, "kde_dark")), false);
    else if (environment::os_version().desktop_environment() == "kde" && !application::dark_mode_enabled()) system_style_sheet_ = style_sheet(get_css_string_from_path(xtd::io::path::combine(__XTD_THEMES_PATH__, "kde_light")), false);
    else if (application::dark_mode_enabled()) system_style_sheet_ = style_sheet(get_css_string_from_path(xtd::io::path::combine(__XTD_THEMES_PATH__, "gnome_dark")), false);
    else system_style_sheet_ = style_sheet(get_css_string_from_path(xtd::io::path::combine(__XTD_THEMES_PATH__, "gnome_light")), false);
  } else if (environment::os_version().is_macos()) {
    if (application::dark_mode_enabled()) system_style_sheet_ = style_sheet(get_css_string_from_path(xtd::io::path::combine(__XTD_THEMES_PATH__, "macos_dark")), false);
    else system_style_sheet_ = style_sheet(get_css_string_from_path(xtd::io::path::combine(__XTD_THEMES_PATH__, "macos_light")), false);
  } else if (environment::os_version().is_windows()) {
    if (application::dark_mode_enabled()) system_style_sheet_ = style_sheet(get_css_string_from_path(xtd::io::path::combine(__XTD_THEMES_PATH__, "windows_dark")), false);
    else system_style_sheet_ = style_sheet(get_css_string_from_path(xtd::io::path::combine(__XTD_THEMES_PATH__, "windows_light")), false);
  } else system_style_sheet_ = style_sheet(get_css_string_from_path(xtd::io::path::combine(__XTD_THEMES_PATH__, "default")), false);
  
  return system_style_sheet_;
}

const xtd::forms::style_sheets::theme& style_sheet::theme() const noexcept {
  return theme_;
}

bool style_sheet::equals(const object& other) const noexcept {
  return is<style_sheet>(other) ? equals(static_cast<const style_sheet&>(other)) : false;
}

bool style_sheet::equals(const style_sheet& other) const noexcept {
  return theme_ == other.theme_;
}

style_sheet::buttons_t style_sheet::button_from_css(const  xtd::ustring& css_text) {
  style_sheet ss(css_text);
  return ss.buttons();
}

style_sheet::controls_t style_sheet::control_from_css(const  xtd::ustring& css_text) {
  style_sheet ss(css_text);
  return ss.controls();
}

style_sheet::forms_t style_sheet::form_from_css(const  xtd::ustring& css_text) {
  style_sheet ss(css_text);
  return ss.forms();
}

style_sheet style_sheet::get_style_sheet_from_name(const xtd::ustring& name) {
  for (auto theme_dir : directory::enumerate_directories(__XTD_THEMES_PATH__)) {
    css_reader reader(file::read_all_text(path::combine(theme_dir, "theme.css")));
    selector_map::const_iterator selectors_iterator =  reader.selectors().find("theme");
    if (selectors_iterator == reader.selectors().end()) break;
    property_map::const_iterator properties_iterator;
    if ((properties_iterator = selectors_iterator->second.properties().find("name")) != selectors_iterator->second.properties().end() && properties_iterator->second.to_string().trim().trim('\"') == name) {
      xtd::ustring theme_css;
      for (auto theme_file : directory::enumerate_files(theme_dir, "*.css"))
        theme_css += file::read_all_text(theme_file);
      return style_sheet(theme_css);
    }
  }
  throw argument_exception(csf_);
}

style_sheet style_sheet::get_style_sheet_from_file(const xtd::ustring& file_name) {
  if (!xtd::io::file::exists(file_name)) throw xtd::io::directory_not_found_exception(csf_);
  xtd::ustring theme_css = file::read_all_text(file_name);
  return style_sheet(theme_css);
}

style_sheet style_sheet::get_style_sheet_from_path(const xtd::ustring& path_name) {
  return style_sheet(get_css_string_from_path(path_name));
}

xtd::forms::style_sheets::system_colors style_sheet::system_colors_from_css(const xtd::ustring& css_text) {
  style_sheet ss(css_text);
  return ss.system_colors();
}

xtd::forms::style_sheets::theme style_sheet::theme_from_css(const xtd::ustring& css_text) {
  style_sheet ss(css_text);
  return ss.theme();
}

color style_sheet::background_color_from_css(const ustring& css_text, const color& default_value) const noexcept {
  color result = default_value;
  try_parse_color(css_text.to_lower(), result);
  return result;
}

background_image style_sheet::background_image_from_css(const xtd::ustring& css_text, const background_image& default_value) const noexcept {
  background_image result;;
  if (css_text.starts_with("url(", true) && css_text.ends_with(")", true) && try_parse_uri(css_text, result.url_)) return result;
  if (css_text.starts_with("linear-gradient(", true) && css_text.ends_with(")", true) && try_parse_linear_gradient(css_text.to_lower(), result)) return result;
  return default_value;
}

border_color style_sheet::border_color_from_css(const xtd::ustring& css_text, const border_color& default_value) const noexcept {
  vector<ustring> values = split_values_from_text(css_text.to_lower());
  if (values.size() < 1 || values.size() > 4) return default_value;
  border_color result;
  result.all(color_from_css(values[0], default_value.top()));
  if (values.size() >= 2) result.right(color_from_css(values[0], default_value.right()));
  if (values.size() >= 3) result.bottom(color_from_css(values[0], default_value.right()));
  if (values.size() == 4) result.left(color_from_css(values[0], default_value.right()));
  return result;
}

style_sheets::border_style style_sheet::border_style_from_css(const ustring& css_text, const border_style& default_value) const noexcept {
  auto values = css_text.to_lower().split();
  static map<ustring, xtd::forms::style_sheets::border_type> border_types = {{"none", border_type::none}, {"hidden", border_type::hidden}, {"dashed", border_type::dashed}, {"dot-dash", border_type::dot_dash},  {"dot-dot-dash", border_type::dot_dot_dash}, {"dotted", border_type::dotted}, {"double", border_type::double_border}, {"groove", border_type::groove}, {"inset", border_type::inset}, {"outset", border_type::outset}, {"ridge", border_type::ridge}, {"solid", border_type::solid}, {"theme", border_type::theme}};
  if (values.size() < 1 || values.size() > 4) return default_value;
  
  border_style result;
  auto it = border_types.find(values[0]);
  if (it == border_types.end()) return default_value;
  result.all(it->second);
  
  if (values.size() >= 2) {
    it = border_types.find(values[1]);
    if (it == border_types.end()) return default_value;
    result.right(it->second);
  }
  if (values.size() >= 3) {
    it = border_types.find(values[2]);
    if (it == border_types.end()) return default_value;
    result.bottom(it->second);
  }
  if (values.size() == 4) {
    it = border_types.find(values[3]);
    if (it == border_types.end()) return default_value;
    result.left(it->second);
  }
  
  return result;
}

border_radius style_sheet::border_radius_from_css(const xtd::ustring& css_text, const border_radius& default_value) const noexcept {
  auto values = css_text.to_lower().split();
  if (values.size() < 1 || values.size() > 4) return default_value;
  
  border_radius result;
  result.all(length_from_css(values[0], default_value.all()));
  
  if (values.size() >= 2) result.top_right(length_from_css(values[1], default_value.top_right()));
  if (values.size() >= 3) result.bottom_right(length_from_css(values[2], default_value.bottom_right()));
  if (values.size() == 4) result.bottom_left(length_from_css(values[3], default_value.bottom_left()));
  
  return result;
}

border_width style_sheet::border_width_from_css(const xtd::ustring& css_text, const border_width& default_value) const noexcept {
  auto values = css_text.to_lower().split();
  if (values.size() < 1 || values.size() > 4) return default_value;
  
  border_width result;
  result.all(length_from_css(values[0], default_value.all()));
  
  if (values.size() >= 2) result.right(length_from_css(values[1], default_value.left()));
  if (values.size() >= 3) result.bottom(length_from_css(values[2], default_value.bottom()));
  if (values.size() == 4) result.left(length_from_css(values[3], default_value.right()));
  
  return result;
}

color style_sheet::color_from_css(const ustring& css_text, const color& default_value) const noexcept {
  color result = default_value;
  try_parse_color(css_text.to_lower(), result);
  return result;
}

length style_sheet::length_from_css(const xtd::ustring& css_text, const length& default_value) const noexcept {
  if (css_text.to_lower() == "auto" || css_text.to_lower() == "initial" || css_text.to_lower() == "inherit") return length(-1);
  auto l = .0;
  if (css_text.to_lower().ends_with("cm") && ::try_parse<double>(css_text.to_lower().replace("cm", ""), l)) return length(l, length_unit::centimeters);
  if (css_text.to_lower().ends_with("mm") && ::try_parse<double>(css_text.to_lower().replace("mm", ""), l)) return length(l, length_unit::millimeters);
  if (css_text.to_lower().ends_with("in") && ::try_parse<double>(css_text.to_lower().replace("in", ""), l)) return length(l, length_unit::inches);
  if (css_text.to_lower().ends_with("px") && ::try_parse<double>(css_text.to_lower().replace("px", ""), l)) return length(l, length_unit::pixels);
  if (css_text.to_lower().ends_with("pt") && ::try_parse<double>(css_text.to_lower().replace("pt", ""), l)) return length(l, length_unit::points);
  if (css_text.to_lower().ends_with("pc") && ::try_parse<double>(css_text.to_lower().replace("pc", ""), l)) return length(l, length_unit::picas);
  if (css_text.to_lower().ends_with("em") && ::try_parse<double>(css_text.to_lower().replace("em", ""), l)) return length(l, length_unit::element);
  if (css_text.to_lower().ends_with("ex") && ::try_parse<double>(css_text.to_lower().replace("ex", ""), l)) return length(l, length_unit::element_x_height);
  if (css_text.to_lower().ends_with("ch") && ::try_parse<double>(css_text.to_lower().replace("ch", ""), l)) return length(l, length_unit::chase);
  if (css_text.to_lower().ends_with("rem") && ::try_parse<double>(css_text.to_lower().replace("rem", ""), l)) return length(l, length_unit::root_element);
  if (css_text.to_lower().ends_with("vw") && ::try_parse<double>(css_text.to_lower().replace("vw", ""), l)) return length(l, length_unit::viewport_width);
  if (css_text.to_lower().ends_with("vh") && ::try_parse<double>(css_text.to_lower().replace("vh", ""), l)) return length(l, length_unit::viewport_height);
  if (css_text.to_lower().ends_with("vmin") && ::try_parse<double>(css_text.to_lower().replace("vmin", ""), l)) return length(l, length_unit::viewport_min);
  if (css_text.to_lower().ends_with("vmax") && ::try_parse<double>(css_text.to_lower().replace("vmax", ""), l)) return length(l, length_unit::viewport_max);
  if (css_text.to_lower().ends_with("%") && ::try_parse<double>(css_text.replace("%", ""), l)) return length(l, length_unit::percent);
  if (css_text == "0") return length(0);
  return default_value;
}

margin style_sheet::margin_from_css(const xtd::ustring& css_text, const margin& default_value) const noexcept {
  auto values = css_text.to_lower().split();
  if (values.size() < 1 || values.size() > 4) return default_value;
  
  margin result;
  result.all(length_from_css(values[0], default_value.all()));
  
  if (values.size() >= 2) result.right(length_from_css(values[1], default_value.left()));
  if (values.size() >= 3) result.bottom(length_from_css(values[2], default_value.bottom()));
  if (values.size() == 4) result.left(length_from_css(values[3], default_value.right()));
  
  return result;
}

style_sheets::padding style_sheet::padding_from_css(const xtd::ustring& css_text, const style_sheets::padding& default_value) const noexcept {
  auto values = css_text.to_lower().split();
  if (values.size() < 1 || values.size() > 4) return default_value;
  
  style_sheets::padding result;
  result.all(length_from_css(values[0], default_value.all()));
  
  if (values.size() >= 2) result.right(length_from_css(values[1], default_value.left()));
  if (values.size() >= 3) result.bottom(length_from_css(values[2], default_value.bottom()));
  if (values.size() == 4) result.left(length_from_css(values[3], default_value.right()));
  
  return result;
}

ustring style_sheet::string_from_css(const xtd::ustring& css_text, const ustring& default_value) const noexcept {
  auto value = css_text.trim();
  if (!value.starts_with("\"") || !value.ends_with("\"")) return default_value;
  return value.remove(value.size() - 1, 1).replace("\"", "");
}

content_alignment style_sheet::text_align_from_css(const xtd::ustring& css_text, const content_alignment& default_value) const noexcept {
  auto values = css_text.to_lower().split();
  if (values.size() == 1) {
    if (values[0] == "top") return content_alignment::top_center;
    if (values[0] == "middle") return content_alignment::middle_center;
    if (values[0] == "bottom") return content_alignment::bottom_center;
    if (values[0] == "left") return content_alignment::middle_left;
    if (values[0] == "center") return content_alignment::middle_center;
    if (values[0] == "right") return content_alignment::middle_right;
  } else if (values.size() == 2) {
    if ((values[0] == "top" && values[1] == "left") || (values[1] == "top" && values[0] == "left")) return content_alignment::top_left;
    if ((values[0] == "top" && values[1] == "center") || (values[1] == "top" && values[0] == "center")) return content_alignment::top_center;
    if ((values[0] == "top" && values[1] == "right") || (values[1] == "top" && values[0] == "right")) return content_alignment::top_right;
    if ((values[0] == "middle" && values[1] == "left") || (values[1] == "middle" && values[0] == "left")) return content_alignment::middle_left;
    if ((values[0] == "middle" && values[1] == "center") || (values[1] == "middle" && values[0] == "center")) return content_alignment::middle_center;
    if ((values[0] == "middle" && values[1] == "right") || (values[1] == "middle" && values[0] == "right")) return content_alignment::middle_right;
    if ((values[0] == "bottom" && values[1] == "left") || (values[1] == "bottom" && values[0] == "left")) return content_alignment::bottom_left;
    if ((values[0] == "bottom" && values[1] == "center") || (values[1] == "bottom" && values[0] == "center")) return content_alignment::bottom_center;
    if ((values[0] == "bottom" && values[1] == "right") || (values[1] == "bottom" && values[0] == "right")) return content_alignment::bottom_right;
  }
  
  return default_value;
}

text_decoration style_sheet::text_decoration_from_css(const ustring& css_text, const text_decoration& default_value) const noexcept {
  map<ustring, text_decoration> decorations {{"none", text_decoration::none}, {"line-through", text_decoration::line_through}, {"overline", text_decoration::overline}, {"underline", text_decoration::underline}};
  auto it = decorations.find(css_text.to_lower());
  if (it == decorations.end()) return default_value;
  return it->second;
}

text_transformation style_sheet::text_transformation_from_css(const ustring& css_text, const text_transformation& default_value) const noexcept {
  map<ustring, text_transformation> transformations {{"none", text_transformation::none}, {"capitalize", text_transformation::capitalize}, {"lowercase", text_transformation::lowercase}, {"uppercase", text_transformation::uppercase}};
  auto it = transformations.find(css_text.to_lower());
  if (it == transformations.end()) return default_value;
  return it->second;
}

uri style_sheet::uri_from_css(const ustring& css_text, const uri& default_value) const noexcept {
  auto result = default_value;
  try_parse_uri(css_text, result);
  return result;;
}

void style_sheet::on_style_sheet_changed(const xtd::event_args& e) {
  /*
  std::function<void(xtd::forms::control&)> update_control = [&](xtd::forms::control & control) {
    control.back_color(control.default_back_color());
    control.fore_color(control.default_fore_color());
    for (auto& child_control : control.controls())
      update_control(child_control.get());
  };*/
  
  for (auto form : application::open_forms()) {
    form.get().back_color(current_style_sheet().system_colors().window());
    form.get().fore_color(current_style_sheet().system_colors().window_text());
    form.get().back_color(form.get().default_back_color());
    form.get().fore_color(form.get().default_fore_color());
    //for (auto& child_control : form.get().controls())
    //  update_control(child_control.get());
    form.get().invalidate(true);
    form.get().refresh();
  }
  style_sheet_changed(current_style_sheet_, e);
}

void style_sheet::on_system_colors_changed(const event_args& e) {
  if (current_style_sheet().is_system_style_sheet() && current_style_sheet().system_colors().window() != xtd::drawing::system_colors::window()) {
    system_style_sheet_ = style_sheet::empty;
    current_style_sheet_ = system_style_sheet();
  } else system_style_sheet_ = style_sheet::empty;
}

vector<ustring> style_sheet::split_values_from_text(const ustring& text) const noexcept {
  static vector<ustring> color_keywords = {"rgb(", "rgba(", "argb(", "hsl(", "hsla(", "ahsl(", "hsv(", "hsva(", "ahsv(", "system-color("};
  auto string_starts_with_any = [](const ustring & text, const vector<ustring>& values)->ustring {
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

void style_sheet::button_reader(xtd::web::css::css_reader& reader) noexcept {
  static vector<pair<ustring, pseudo_state>> states {{"", pseudo_state::standard}, {":pressed", pseudo_state::pressed}, {":checked", pseudo_state::checked}, {":mixed", pseudo_state::mixed}, {":hover", pseudo_state::hover}, {":disabled", pseudo_state::disabled}};
  static vector<pair<ustring, pseudo_state>> buttons {{"button", pseudo_state::standard}, {"button:default", pseudo_state::default_state}, {"button:flat", pseudo_state::flat}, {"button:flat:default", pseudo_state::flat | pseudo_state::default_state}, {"button:popup", pseudo_state::popup}, {"button:popup:default", pseudo_state::popup | pseudo_state::default_state}};
  for (auto button : buttons) {
    for (auto state : states) {
      selector_map::const_iterator selectors_iterator = reader.selectors().find(button.first + state.first);
      if (selectors_iterator != reader.selectors().end() && state.second == pseudo_state::standard) buttons_[button.second] = xtd::forms::style_sheets::button();
      if (selectors_iterator == reader.selectors().end() || state.second != pseudo_state::standard) buttons_[button.second | state.second] = buttons_[button.second];
      if (selectors_iterator != reader.selectors().end()) fill_control(selectors_iterator, buttons_[button.second | state.second]);
    }
  }
}

void style_sheet::control_reader(xtd::web::css::css_reader& reader) noexcept {
  static vector<pair<ustring, pseudo_state>> states {{"", pseudo_state::standard}, {":pressed", pseudo_state::pressed}, {":checked", pseudo_state::checked}, {":mixed", pseudo_state::mixed}, {":hover", pseudo_state::hover}, {":disabled", pseudo_state::disabled}};
  for (auto state : states) {
    selector_map::const_iterator selectors_iterator = reader.selectors().find("control" + state.first);
    if (selectors_iterator != reader.selectors().end() && state.second == pseudo_state::standard) controls_[pseudo_state::standard] = xtd::forms::style_sheets::control();
    if (selectors_iterator == reader.selectors().end() || state.second != pseudo_state::standard) controls_[pseudo_state::standard | state.second] = controls_[pseudo_state::standard];
    if (selectors_iterator != reader.selectors().end()) fill_control(selectors_iterator, controls_[pseudo_state::standard | state.second]);
  }
}

void style_sheet::fill_control(xtd::web::css::selector_map::const_iterator& selectors_iterator, xtd::forms::style_sheets::control& control) noexcept {
  property_map::const_iterator properties_iterator;
  if ((properties_iterator = selectors_iterator->second.properties().find("margin")) != selectors_iterator->second.properties().end()) control.margin(margin_from_css(properties_iterator->second.to_string(), margin(0)));
  if ((properties_iterator = selectors_iterator->second.properties().find("border-style")) != selectors_iterator->second.properties().end()) control.border_style(border_style_from_css(properties_iterator->second.to_string(), border_style(border_type::none)));
  if ((properties_iterator = selectors_iterator->second.properties().find("border-color")) != selectors_iterator->second.properties().end()) control.border_color(border_color_from_css(properties_iterator->second.to_string(), border_color(color::transparent)));
  if ((properties_iterator = selectors_iterator->second.properties().find("border-width")) != selectors_iterator->second.properties().end()) control.border_width(border_width_from_css(properties_iterator->second.to_string(), border_width(1)));
  if ((properties_iterator = selectors_iterator->second.properties().find("border-radius")) != selectors_iterator->second.properties().end()) control.border_radius(border_radius_from_css(properties_iterator->second.to_string(), border_radius(0)));
  if ((properties_iterator = selectors_iterator->second.properties().find("padding")) != selectors_iterator->second.properties().end()) control.padding(margin_from_css(properties_iterator->second.to_string(), padding(0)));
  if ((properties_iterator = selectors_iterator->second.properties().find("height")) != selectors_iterator->second.properties().end()) control.height(length_from_css(properties_iterator->second.to_string(), length(25)));
  if ((properties_iterator = selectors_iterator->second.properties().find("width")) != selectors_iterator->second.properties().end()) control.width(length_from_css(properties_iterator->second.to_string(), length(75)));
  if ((properties_iterator = selectors_iterator->second.properties().find("background-color")) != selectors_iterator->second.properties().end()) control.background_color(background_color_from_css(properties_iterator->second.to_string(), color::transparent));
  if ((properties_iterator = selectors_iterator->second.properties().find("background-image")) != selectors_iterator->second.properties().end()) control.background_image(background_image_from_css(properties_iterator->second.to_string(), background_image::empty));
  if ((properties_iterator = selectors_iterator->second.properties().find("color")) != selectors_iterator->second.properties().end()) control.color(color_from_css(properties_iterator->second.to_string(), color::transparent));
  if ((properties_iterator = selectors_iterator->second.properties().find("text-align")) != selectors_iterator->second.properties().end()) control.text_alignment(text_align_from_css(properties_iterator->second.to_string(), content_alignment::middle_center));
  //if ((properties_iterator = selectors_iterator->second.properties().find("font")) != selectors_iterator->second.properties().end()) control.font(font_from_css(properties_iterator->second.to_string(), content_alignment::middle_center));
  if ((properties_iterator = selectors_iterator->second.properties().find("text-decoration")) != selectors_iterator->second.properties().end()) control.decoration(text_decoration_from_css(properties_iterator->second.to_string(), text_decoration::none));
  if ((properties_iterator = selectors_iterator->second.properties().find("text-transformation")) != selectors_iterator->second.properties().end()) control.transformation(text_transformation_from_css(properties_iterator->second.to_string(), text_transformation::none));
  if ((properties_iterator = selectors_iterator->second.properties().find("image-align")) != selectors_iterator->second.properties().end()) control.image_alignment(text_align_from_css(properties_iterator->second.to_string(), content_alignment::middle_center));
}

void style_sheet::system_colors_reader(xtd::web::css::css_reader& reader) noexcept {
  selector_map::const_iterator selectors_iterator =  reader.selectors().find("system-colors");
  if (selectors_iterator == reader.selectors().end()) return;
  property_map::const_iterator properties_iterator;
  if ((properties_iterator = selectors_iterator->second.properties().find("accent")) != selectors_iterator->second.properties().end()) system_colors_.accent(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::accent()));
  if ((properties_iterator = selectors_iterator->second.properties().find("accent-text")) != selectors_iterator->second.properties().end()) system_colors_.accent_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::accent_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("active-border")) != selectors_iterator->second.properties().end()) system_colors_.active_border(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::active_border()));
  if ((properties_iterator = selectors_iterator->second.properties().find("active-caption")) != selectors_iterator->second.properties().end()) system_colors_.active_caption(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::active_caption()));
  if ((properties_iterator = selectors_iterator->second.properties().find("active-caption-text")) != selectors_iterator->second.properties().end()) system_colors_.active_caption_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::active_caption_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("app-workspace")) != selectors_iterator->second.properties().end()) system_colors_.app_workspace(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::app_workspace()));
  if ((properties_iterator = selectors_iterator->second.properties().find("button-face")) != selectors_iterator->second.properties().end()) system_colors_.button_face(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::button_face()));
  if ((properties_iterator = selectors_iterator->second.properties().find("button-highlight")) != selectors_iterator->second.properties().end()) system_colors_.button_highlight(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::button_highlight()));
  if ((properties_iterator = selectors_iterator->second.properties().find("button-shadow")) != selectors_iterator->second.properties().end()) system_colors_.button_shadow(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::button_shadow()));
  if ((properties_iterator = selectors_iterator->second.properties().find("control")) != selectors_iterator->second.properties().end()) system_colors_.control(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::control()));
  if ((properties_iterator = selectors_iterator->second.properties().find("control-dark")) != selectors_iterator->second.properties().end()) system_colors_.control_dark(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::control_dark()));
  if ((properties_iterator = selectors_iterator->second.properties().find("control-dark-dark")) != selectors_iterator->second.properties().end()) system_colors_.control_dark_dark(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::control_dark_dark()));
  if ((properties_iterator = selectors_iterator->second.properties().find("control-light")) != selectors_iterator->second.properties().end()) system_colors_.control_light(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::control_light()));
  if ((properties_iterator = selectors_iterator->second.properties().find("control-light-light")) != selectors_iterator->second.properties().end()) system_colors_.control_light_light(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::control_light_light()));
  if ((properties_iterator = selectors_iterator->second.properties().find("control-text")) != selectors_iterator->second.properties().end()) system_colors_.control_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::control_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("desktop")) != selectors_iterator->second.properties().end()) system_colors_.desktop(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::desktop()));
  if ((properties_iterator = selectors_iterator->second.properties().find("gradient-active-caption")) != selectors_iterator->second.properties().end()) system_colors_.gradient_active_caption(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::gradient_active_caption()));
  if ((properties_iterator = selectors_iterator->second.properties().find("gradient-inactive-caption")) != selectors_iterator->second.properties().end()) system_colors_.gradient_inactive_caption(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::gradient_inactive_caption()));
  if ((properties_iterator = selectors_iterator->second.properties().find("gray-text")) != selectors_iterator->second.properties().end()) system_colors_.gray_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::gray_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("highlight")) != selectors_iterator->second.properties().end()) system_colors_.highlight(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::highlight()));
  if ((properties_iterator = selectors_iterator->second.properties().find("highlight-text")) != selectors_iterator->second.properties().end()) system_colors_.highlight_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::highlight_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("hot-track")) != selectors_iterator->second.properties().end()) system_colors_.hot_track(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::hot_track()));
  if ((properties_iterator = selectors_iterator->second.properties().find("inactive-border")) != selectors_iterator->second.properties().end()) system_colors_.inactive_border(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::inactive_border()));
  if ((properties_iterator = selectors_iterator->second.properties().find("inactive-caption")) != selectors_iterator->second.properties().end()) system_colors_.inactive_caption(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::inactive_caption()));
  if ((properties_iterator = selectors_iterator->second.properties().find("inactive-caption-text")) != selectors_iterator->second.properties().end()) system_colors_.inactive_caption_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::inactive_caption_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("info")) != selectors_iterator->second.properties().end()) system_colors_.info(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::info()));
  if ((properties_iterator = selectors_iterator->second.properties().find("info-text")) != selectors_iterator->second.properties().end()) system_colors_.info_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::info_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("menu")) != selectors_iterator->second.properties().end()) system_colors_.menu(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::menu()));
  if ((properties_iterator = selectors_iterator->second.properties().find("menu-bar")) != selectors_iterator->second.properties().end()) system_colors_.menu_bar(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::menu_bar()));
  if ((properties_iterator = selectors_iterator->second.properties().find("menu-highlight")) != selectors_iterator->second.properties().end()) system_colors_.menu_highlight(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::menu_highlight()));
  if ((properties_iterator = selectors_iterator->second.properties().find("menu-text")) != selectors_iterator->second.properties().end()) system_colors_.menu_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::menu_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("scroll-bar")) != selectors_iterator->second.properties().end()) system_colors_.scroll_bar(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::scroll_bar()));
  if ((properties_iterator = selectors_iterator->second.properties().find("text-box")) != selectors_iterator->second.properties().end()) system_colors_.text_box(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::text_box()));
  if ((properties_iterator = selectors_iterator->second.properties().find("text-box-text")) != selectors_iterator->second.properties().end()) system_colors_.text_box_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::text_box_text()));
  if ((properties_iterator = selectors_iterator->second.properties().find("window")) != selectors_iterator->second.properties().end()) system_colors_.window(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::window()));
  if ((properties_iterator = selectors_iterator->second.properties().find("window-frame")) != selectors_iterator->second.properties().end()) system_colors_.window_frame(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::window_frame()));
  if ((properties_iterator = selectors_iterator->second.properties().find("window-text")) != selectors_iterator->second.properties().end()) system_colors_.window_text(color_from_css(properties_iterator->second.to_string(), drawing::system_colors::window_text()));
}

void style_sheet::theme_reader(xtd::web::css::css_reader& reader) noexcept {
  selector_map::const_iterator selectors_iterator =  reader.selectors().find("theme");
  if (selectors_iterator == reader.selectors().end()) return;
  property_map::const_iterator properties_iterator;
  if ((properties_iterator = selectors_iterator->second.properties().find("name")) != selectors_iterator->second.properties().end()) theme_.name(string_from_css(properties_iterator->second.to_string(), ustring()));
  if ((properties_iterator = selectors_iterator->second.properties().find("description")) != selectors_iterator->second.properties().end()) theme_.description(string_from_css(properties_iterator->second.to_string(), ustring()));
  if ((properties_iterator = selectors_iterator->second.properties().find("authors")) != selectors_iterator->second.properties().end()) theme_.authors(string_from_css(properties_iterator->second.to_string(), ustring()));
  if ((properties_iterator = selectors_iterator->second.properties().find("website")) != selectors_iterator->second.properties().end()) theme_.website(uri_from_css(properties_iterator->second.to_string(), uri()));
}

bool style_sheet::try_parse_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept {
  if (text.starts_with("#") && try_parse_hex_color(text, result)) return true;
  if (text.starts_with("rgb(") && text.ends_with(")") && try_parse_rgb_color(text, result)) return true;
  if (text.starts_with("rgba(") && text.ends_with(")") && try_parse_rgba_color(text, result)) return true;
  if (text.starts_with("hsv(") && text.ends_with(")") && try_parse_hsv_color(text, result)) return true;
  if (text.starts_with("hsva(") && text.ends_with(")") && try_parse_hsva_color(text, result)) return true;
  if (text.starts_with("hsl(") && text.ends_with(")") && try_parse_hsl_color(text, result)) return true;
  if (text.starts_with("hsla(") && text.ends_with(")") && try_parse_hsla_color(text, result)) return true;
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
    uint32_t rgb;
    if (xtd::try_parse<uint32_t>(text.substring(1), rgb, number_styles::hex_number) == false) return false;
    result = color::from_argb(rgb + 0xFF000000U);
    return true;
  }
  if (text.starts_with("#") && text.size() == 9U) {
    uint32_t argb;
    if (xtd::try_parse<uint32_t>(text.substring(1), argb, number_styles::hex_number) == false) return false;
    result = color::from_argb(argb);
    return true;
  }
  return false;
}

bool style_sheet::try_parse_linear_gradient(const xtd::ustring& text, background_image& result) const noexcept {
  vector<ustring> arguments = split_values_from_text(text.remove(text.size() - 1).replace("linear-gradient(", ""));
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
  result = background_image(style_sheets::image_type::linear_gradient, colors, angle == -1 ? 180 : angle);
  return true;
}

bool style_sheet::try_parse_rgb_color(const ustring& text, color& result) const noexcept {
  auto value = text.remove(text.size() - 1).replace("rgb(", "");
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
  auto value = text.remove(text.size() - 1).replace("rgba(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 4) return false;
  byte_t r = 0;
  if (xtd::try_parse<byte_t>(color_parts[0], r) == false) return false;
  byte_t g = 0;
  if (xtd::try_parse<byte_t>(color_parts[1], g) == false) return false;
  byte_t b = 0;
  if (xtd::try_parse<byte_t>(color_parts[2], b) == false) return false;
  float a = 0;
  if (xtd::try_parse<float>(color_parts[3], a) == false) return false;
  result = color::from_argb(as<byte_t>(as<int32_t>(a * 255) % 256), r, g, b);
  return true;
}

bool style_sheet::try_parse_hsv_color(const ustring& text, color& result) const noexcept {
  auto value = text.remove(text.size() - 1).replace("hsv(", "");
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
  auto value = text.remove(text.size() - 1).replace("hsva(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 4) return false;
  float h = 0;
  if (xtd::try_parse<float>(color_parts[0], h) == false) return false;
  float s = 0;
  if (xtd::try_parse<float>(color_parts[1], s) == false) return false;
  float v = 0;
  if (xtd::try_parse<float>(color_parts[2], v) == false) return false;
  float a = 0;
  if (xtd::try_parse<float>(color_parts[3], a) == false) return false;
  result = color::from_argb(as<byte_t>(as<int32_t>(a * 255) % 256), color::from_hsb(h, s, v));
  return true;
}

bool style_sheet::try_parse_hsl_color(const ustring& text, color& result) const noexcept {
  auto value = text.remove(text.size() - 1).replace("hsl(", "");
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
  auto value = text.remove(text.size() - 1).replace("hsla(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 4) return false;
  float h = 0;
  if (xtd::try_parse<float>(color_parts[0], h) == false) return false;
  float s = 0;
  if (xtd::try_parse<float>(color_parts[1], s) == false) return false;
  float l = 0;
  if (xtd::try_parse<float>(color_parts[2], l) == false) return false;
  float a = 0;
  if (xtd::try_parse<float>(color_parts[3], a) == false) return false;
  result = color::from_argb(as<byte_t>(as<int32_t>(a * 255) % 256), color::from_hsl(h, s, l));
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
  auto value = text.remove(text.size() - 1).replace("system-color(", "");
  map<ustring, drawing::color> colors {{"accent", system_colors().accent()}, {"accent-text", system_colors().accent_text()}, {"active-border", system_colors().active_border()}, {"active-caption", system_colors().active_caption()}, {"active-caption-text", system_colors().active_caption_text()}, {"app-workspace", system_colors().app_workspace()}, {"button-face", system_colors().button_face()}, {"button-highlight", system_colors().button_highlight()}, {"button-shadow", system_colors().button_shadow()}, {"control", system_colors().control()}, {"control-dark", system_colors().control_dark()}, {"control-dark-dark", system_colors().control_dark_dark()}, {"control-light", system_colors().control_light()}, {"control-light-light", system_colors().control_light_light()}, {"control-text", system_colors().control_text()}, {"desktop", system_colors().desktop()}, {"gradient-active-caption", system_colors().gradient_active_caption()}, {"gradient-inactive-caption", system_colors().gradient_inactive_caption()}, {"gray-text", system_colors().gray_text()}, {"highlight", system_colors().highlight()}, {"highlight-text", system_colors().highlight_text()}, {"hot-track", system_colors().hot_track()}, {"inactive-border", system_colors().inactive_border()}, {"inactive-caption", system_colors().inactive_caption()}, {"inactive-caption-text", system_colors().inactive_caption_text()}, {"info", system_colors().info()}, {"info-text", system_colors().info_text()}, {"menu", system_colors().menu()}, {"menu-bar", system_colors().menu_bar()}, {"menu-highlight", system_colors().menu_highlight()}, {"menu-text", system_colors().menu_text()}, {"scroll-bar", system_colors().scroll_bar()}, {"text-box", system_colors().text_box()}, {"text-box-text", system_colors().text_box_text()}, {"window", system_colors().window()}, {"window-frame", system_colors().window_frame()}, {"window-text", system_colors().window_text()}};
  auto it = colors.find(value);
  if (it == colors.end()) return false;
  result = it->second;
  return true;
}

bool style_sheet::try_parse_uri(const xtd::ustring& text, xtd::uri& result) const noexcept {
  if (!text.starts_with("url", true) || !text.ends_with(")", true)) return false;
  result = uri(text.remove(text.size() - 1, 1).remove(0, 4));
  return true;
}
