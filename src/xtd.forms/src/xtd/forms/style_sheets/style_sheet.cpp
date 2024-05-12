#include "../../../../include/xtd/forms/style_sheets/style_sheet.h"
#include "../../../../include/xtd/forms/application.h"
#include <xtd/drawing/drawing_2d/linear_gradient_brush>
#include <xtd/drawing/system_colors>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/window_definitions>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/io/directory>
#include <xtd/io/directory_not_found_exception>
#include <xtd/io/file>
#include <xtd/as>
#include <xtd/is>
#include <xtd/environment>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::io;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::web::css;

namespace {
  ustring get_css_string_from_path(const ustring& path_name) {
    if (!xtd::io::directory::exists(path_name)) throw xtd::io::directory_not_found_exception {csf_};
    auto theme_css = ustring::empty_string;
    for (auto theme_file : directory::enumerate_files(path_name, "*.css"))
      theme_css += file::read_all_text(theme_file);
    return theme_css;
  }
}

struct style_sheet::data {
  buttons_t buttons;
  controls_t controls;
  buttons_t flat_buttons;
  toggle_buttons_t flat_toggle_buttons;
  forms_t forms;
  labels_t labels;
  link_labels_t link_labels;
  panels_t panels;
  buttons_t popup_buttons;
  status_bars_t status_bars;
  status_bar_panels_t status_bar_panels;
  toggle_buttons_t popup_toggle_buttons;
  toggle_buttons_t toggle_buttons;
  tool_bars_t tool_bars;
  tool_bar_buttons_t tool_bar_buttons;
  user_controls_t user_controls;
  xtd::forms::style_sheets::system_colors system_colors;
  xtd::forms::style_sheets::theme theme;
};

const style_sheet style_sheet::empty;
event<style_sheet, event_handler> style_sheet::style_sheet_changed;
style_sheet style_sheet::current_style_sheet_;
style_sheet::style_sheets_t style_sheet::style_sheets_;
style_sheet::style_sheet_names_t style_sheet::style_sheet_names_;
style_sheet style_sheet::system_style_sheet_;

style_sheet::style_sheet() : data_(std::make_shared<data>()) {
}

style_sheet::style_sheet(const ustring& css_text) : style_sheet(css_text, true) {
}

style_sheet::style_sheet(const ustring& css_text, bool init_system) : data_(std::make_shared<data>()) {
  if (init_system) *this = system_style_sheet();
  else {
    data_->system_colors.accent(drawing::system_colors::accent());
    data_->system_colors.accent_text(drawing::system_colors::accent_text());
    data_->system_colors.active_border(drawing::system_colors::active_border());
    data_->system_colors.active_caption(drawing::system_colors::active_caption());
    data_->system_colors.active_caption_text(drawing::system_colors::active_caption_text());
    data_->system_colors.active_text(drawing::system_colors::active_text());
    data_->system_colors.app_workspace(drawing::system_colors::app_workspace());
    data_->system_colors.button_face(drawing::system_colors::button_face());
    data_->system_colors.button_highlight(drawing::system_colors::button_highlight());
    data_->system_colors.button_shadow(drawing::system_colors::button_shadow());
    data_->system_colors.control(drawing::system_colors::control());
    data_->system_colors.control_dark(drawing::system_colors::control_dark());
    data_->system_colors.control_dark_dark(drawing::system_colors::control_dark_dark());
    data_->system_colors.control_light(drawing::system_colors::control_light());
    data_->system_colors.control_light_light(drawing::system_colors::control_light_light());
    data_->system_colors.control_text(drawing::system_colors::control_text());
    data_->system_colors.desktop(drawing::system_colors::desktop());
    data_->system_colors.gradient_active_caption(drawing::system_colors::gradient_active_caption());
    data_->system_colors.gradient_inactive_caption(drawing::system_colors::gradient_inactive_caption());
    data_->system_colors.gray_text(drawing::system_colors::gray_text());
    data_->system_colors.highlight(drawing::system_colors::highlight());
    data_->system_colors.highlight_text(drawing::system_colors::highlight_text());
    data_->system_colors.hot_track(drawing::system_colors::hot_track());
    data_->system_colors.inactive_border(drawing::system_colors::inactive_border());
    data_->system_colors.inactive_caption(drawing::system_colors::inactive_caption());
    data_->system_colors.inactive_caption_text(drawing::system_colors::inactive_caption_text());
    data_->system_colors.info(drawing::system_colors::info());
    data_->system_colors.info_text(drawing::system_colors::info_text());
    data_->system_colors.link_text(drawing::system_colors::link_text());
    data_->system_colors.menu(drawing::system_colors::menu());
    data_->system_colors.menu_bar(drawing::system_colors::menu_bar());
    data_->system_colors.menu_highlight(drawing::system_colors::menu_highlight());
    data_->system_colors.menu_text(drawing::system_colors::menu_text());
    data_->system_colors.scroll_bar(drawing::system_colors::scroll_bar());
    data_->system_colors.text_box(drawing::system_colors::text_box());
    data_->system_colors.text_box_text(drawing::system_colors::text_box_text());
    data_->system_colors.visited_text(drawing::system_colors::visited_text());
    data_->system_colors.window(drawing::system_colors::window());
    data_->system_colors.window_frame(drawing::system_colors::window_frame());
    data_->system_colors.window_text(drawing::system_colors::window_text());
  }
  css_reader reader(css_text);
  theme_reader(reader);
  if (init_system) system_colors_reader(reader);
  button_reader(reader);
  control_reader(reader);
  flat_button_reader(reader);
  flat_toggle_button_reader(reader);
  form_reader(reader);
  label_reader(reader);
  link_label_reader(reader);
  panel_reader(reader);
  popup_button_reader(reader);
  popup_toggle_button_reader(reader);
  status_bar_reader(reader);
  status_bar_panel_reader(reader);
  toggle_button_reader(reader);
  tool_bar_reader(reader);
  tool_bar_button_reader(reader);
  user_control_reader(reader);
}

style_sheet::style_sheet(const style_sheet& value) : data_(std::make_shared<data>()) {
  // memberwise clone...
  *data_ = *value.data_;
}

style_sheet& style_sheet::operator =(const style_sheet& value) {
  // memberwise clone...
  *data_ = *value.data_;
  return *this;
}

xtd::forms::style_sheets::button style_sheet::button() const noexcept {
  return button(pseudo_state::standard);
}

xtd::forms::style_sheets::button style_sheet::button(pseudo_state state) const noexcept {
  return get_state_control<xtd::forms::style_sheets::button>(data_->buttons, state);
}

const style_sheet::buttons_t& style_sheet::buttons() const noexcept {
  return data_->buttons;
}

xtd::forms::style_sheets::control style_sheet::control() const noexcept {
  return control(pseudo_state::standard);
}

xtd::forms::style_sheets::control style_sheet::control(pseudo_state state) const noexcept {
  return get_state_control<xtd::forms::style_sheets::control>(data_->controls, state);
}

const style_sheet::controls_t& style_sheet::controls() const noexcept {
  return data_->controls;
}

const style_sheet& style_sheet::current_style_sheet() noexcept {
  try {
    if (current_style_sheet_ == style_sheet::empty) current_style_sheet(system_style_sheet());
  } catch (...) {
  }
  return current_style_sheet_;
}

void style_sheet::current_style_sheet(const style_sheet& value) {
  if (value == style_sheet::empty) throw argument_exception {csf_};
  if (current_style_sheet_ != value) {
    current_style_sheet_ = value;
    on_style_sheet_changed(event_args::empty);
  }
}

xtd::forms::style_sheets::button style_sheet::flat_button() const noexcept {
  return flat_button(pseudo_state::standard);
}

xtd::forms::style_sheets::button style_sheet::flat_button(pseudo_state state) const noexcept {
  return get_state_control<xtd::forms::style_sheets::button>(data_->flat_buttons, state);
}

const style_sheet::buttons_t& style_sheet::flat_buttons() const noexcept {
  return data_->flat_buttons;
}

xtd::forms::style_sheets::toggle_button style_sheet::flat_toggle_button() const noexcept {
  return flat_toggle_button(pseudo_state::standard);
}

xtd::forms::style_sheets::toggle_button style_sheet::flat_toggle_button(pseudo_state state) const noexcept {
  return get_state_control<xtd::forms::style_sheets::toggle_button>(data_->flat_toggle_buttons, state);
}

const style_sheet::buttons_t& style_sheet::flat_toggle_buttons() const noexcept {
  return data_->flat_toggle_buttons;
}

xtd::forms::style_sheets::form style_sheet::form() const noexcept {
  return form(pseudo_state::standard);
}

xtd::forms::style_sheets::form style_sheet::form(pseudo_state state) const noexcept {
  return get_state_control<xtd::forms::style_sheets::form>(data_->forms, state);
}

const style_sheet::forms_t& style_sheet::forms() const noexcept {
  return data_->forms;
}

bool style_sheet::is_system_style_sheet() const noexcept {
  try {
    return *this == system_style_sheet();
  } catch (...) {
    return false;
  }
}

xtd::forms::style_sheets::label style_sheet::label() const noexcept {
  return label(pseudo_state::standard);
}

xtd::forms::style_sheets::label style_sheet::label(pseudo_state state) const noexcept {
  return get_state_control<xtd::forms::style_sheets::label>(data_->labels, state);
}

const style_sheet::labels_t& style_sheet::labels() const noexcept {
  return data_->labels;
}

xtd::forms::style_sheets::link_label style_sheet::link_label() const noexcept {
  return link_label(pseudo_state::standard);
}

xtd::forms::style_sheets::link_label style_sheet::link_label(pseudo_state state) const noexcept {
  return get_state_control<xtd::forms::style_sheets::label>(data_->link_labels, state);
}

const style_sheet::link_labels_t& style_sheet::link_labels() const noexcept {
  return data_->link_labels;
}

xtd::forms::style_sheets::panel style_sheet::panel() const noexcept {
  return panel(pseudo_state::standard);
}

xtd::forms::style_sheets::panel style_sheet::panel(pseudo_state state) const noexcept {
  return get_state_control<xtd::forms::style_sheets::panel>(data_->panels, state);
}

const style_sheet::panels_t& style_sheet::panels() const noexcept {
  return data_->panels;
}

xtd::forms::style_sheets::button style_sheet::popup_button() const noexcept {
  return popup_button(pseudo_state::standard);
}

xtd::forms::style_sheets::button style_sheet::popup_button(pseudo_state state) const noexcept {
  return get_state_control<xtd::forms::style_sheets::button>(data_->popup_buttons, state);
}

const style_sheet::buttons_t& style_sheet::popup_buttons() const noexcept {
  return data_->popup_buttons;
}

xtd::forms::style_sheets::toggle_button style_sheet::popup_toggle_button() const noexcept {
  return popup_toggle_button(pseudo_state::standard);
}

xtd::forms::style_sheets::toggle_button style_sheet::popup_toggle_button(pseudo_state state) const noexcept {
  return get_state_control<xtd::forms::style_sheets::button>(data_->popup_toggle_buttons, state);
}

const style_sheet::buttons_t& style_sheet::popup_toggle_buttons() const noexcept {
  return data_->popup_toggle_buttons;
}

xtd::forms::style_sheets::status_bar style_sheet::status_bar() const noexcept {
  return status_bar(pseudo_state::standard);
}

xtd::forms::style_sheets::status_bar style_sheet::status_bar(pseudo_state state) const noexcept {
  return get_state_control<xtd::forms::style_sheets::status_bar>(data_->status_bars, state);
}

const style_sheet::status_bars_t& style_sheet::status_bars() const noexcept {
  return data_->status_bars;
}

xtd::forms::style_sheets::status_bar_panel style_sheet::status_bar_panel() const noexcept {
  return status_bar_panel(pseudo_state::standard);
}

xtd::forms::style_sheets::status_bar_panel style_sheet::status_bar_panel(pseudo_state state) const noexcept {
  return get_state_control<xtd::forms::style_sheets::button>(data_->status_bar_panels, state);
}

const style_sheet::status_bar_panels_t& style_sheet::status_bar_panels() const noexcept {
  return data_->status_bar_panels;
}

const style_sheet::style_sheets_t& style_sheet::style_sheets() noexcept {
  if (!style_sheets_.empty()) return style_sheets_;
  
  for (auto theme_dir : directory::enumerate_directories(environment::get_folder_path(environment::special_folder::xtd_themes))) {
    auto theme_css = ustring::empty_string;
    for (auto theme_file : directory::enumerate_files(theme_dir, "*.css"))
      theme_css += file::read_all_text(theme_file);
    auto style = style_sheet {theme_css};
    if (!style.theme().name().empty())
      style_sheets_[style.theme().name()] = style;
  }
  return style_sheets_;
}

const style_sheet::style_sheet_names_t& style_sheet::style_sheet_names() noexcept {
  if (!style_sheet_names_.empty()) return style_sheet_names_;
  
  for (auto theme_dir : directory::enumerate_directories(environment::get_folder_path(environment::special_folder::xtd_themes))) {
    if (!file::exists(path::combine(theme_dir, "theme.css"))) continue;
    auto reader = css_reader {file::read_all_text(path::combine(theme_dir, "theme.css"))};
    auto selectors_iterator =  reader.selectors().find("theme");
    if (selectors_iterator == reader.selectors().end()) continue;
    auto properties_iterator = selectors_iterator->second.properties().find("name");
    if (properties_iterator != selectors_iterator->second.properties().end()) style_sheet_names_.push_back(properties_iterator->second.to_string().trim().trim('\"'));
  }
  return style_sheet_names_;
}

const xtd::forms::style_sheets::system_colors& style_sheet::system_colors()const noexcept {
  return data_->system_colors;
}

const style_sheet& style_sheet::system_style_sheet() noexcept {
  try {
    if (system_style_sheet_ != style_sheet::empty)
      return system_style_sheet_;
    if (environment::os_version().is_windows_platform())
      return (system_style_sheet_ = style_sheet(get_css_string_from_path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::xtd_themes), application::dark_mode() ? "windows_dark" : "windows_light")), false));
    if (environment::os_version().is_macos_platform())
      return (system_style_sheet_ = style_sheet(get_css_string_from_path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::xtd_themes), application::dark_mode() ? "macos_dark" : "macos_light")), false));
    if (environment::os_version().is_unix_platform() && environment::os_version().desktop_environment() == "kde")
      return (system_style_sheet_ = style_sheet(get_css_string_from_path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::xtd_themes),  application::dark_mode() ? "kde_dark" : "kde_light")), false));
    if (environment::os_version().is_unix_platform())
      return (system_style_sheet_ = style_sheet(get_css_string_from_path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::xtd_themes), application::dark_mode() ? "gnome_dark" : "gnome_light")), false));
    return (system_style_sheet_ = style_sheet(get_css_string_from_path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::xtd_themes), "default")), false));
  } catch (...) {
    return system_style_sheet_;
  }
}

const xtd::forms::style_sheets::theme& style_sheet::theme() const noexcept {
  return data_->theme;
}

xtd::forms::style_sheets::toggle_button style_sheet::toggle_button() const noexcept {
  return toggle_button(pseudo_state::standard);
}

xtd::forms::style_sheets::toggle_button style_sheet::toggle_button(pseudo_state state) const noexcept {
  return get_state_control<xtd::forms::style_sheets::toggle_button>(data_->toggle_buttons, state);
}

const style_sheet::toggle_buttons_t& style_sheet::toggle_buttons() const noexcept {
  return data_->toggle_buttons;
}

xtd::forms::style_sheets::tool_bar style_sheet::tool_bar() const noexcept {
  return tool_bar(pseudo_state::standard);
}

xtd::forms::style_sheets::tool_bar style_sheet::tool_bar(pseudo_state state) const noexcept {
  return get_state_control<xtd::forms::style_sheets::tool_bar>(data_->tool_bars, state);
}

const style_sheet::tool_bars_t& style_sheet::tool_bars() const noexcept {
  return data_->tool_bars;
}

xtd::forms::style_sheets::tool_bar_button style_sheet::tool_bar_button() const noexcept {
  return tool_bar_button(pseudo_state::standard);
}

xtd::forms::style_sheets::tool_bar_button style_sheet::tool_bar_button(pseudo_state state) const noexcept {
  return get_state_control<xtd::forms::style_sheets::button>(data_->tool_bar_buttons, state);
}

const style_sheet::tool_bar_buttons_t& style_sheet::tool_bar_buttons() const noexcept {
  return data_->tool_bar_buttons;
}

xtd::forms::style_sheets::user_control style_sheet::user_control() const noexcept {
  return user_control(pseudo_state::standard);
}

xtd::forms::style_sheets::user_control style_sheet::user_control(pseudo_state state) const noexcept {
  return get_state_control<xtd::forms::style_sheets::user_control>(data_->user_controls, state);
}

const style_sheet::user_controls_t& style_sheet::user_controls() const noexcept {
  return data_->user_controls;
}

bool style_sheet::equals(const style_sheet& other) const noexcept {
  return data_->theme == other.data_->theme;
}

style_sheet::buttons_t style_sheet::button_from_css(const  ustring& css_text) {
  auto ss = style_sheet {css_text};
  return ss.buttons();
}

style_sheet::controls_t style_sheet::control_from_css(const  ustring& css_text) {
  auto ss = style_sheet {css_text};
  return ss.controls();
}

style_sheet::forms_t style_sheet::form_from_css(const  ustring& css_text) {
  auto ss = style_sheet {css_text};
  return ss.forms();
}

style_sheet style_sheet::get_style_sheet_from_name(const ustring& name) {
  for (auto theme_dir : directory::enumerate_directories(environment::get_folder_path(environment::special_folder::xtd_themes))) {
    auto reader = css_reader {file::read_all_text(path::combine(theme_dir, "theme.css"))};
    auto selectors_iterator =  reader.selectors().find("theme");
    if (selectors_iterator == reader.selectors().end()) break;
    auto properties_iterator = selectors_iterator->second.properties().find("name");
    if (properties_iterator != selectors_iterator->second.properties().end() && properties_iterator->second.to_string().trim().trim('\"') == name) {
      auto theme_css = ustring::empty_string;
      for (auto theme_file : directory::enumerate_files(theme_dir, "*.css"))
        theme_css += file::read_all_text(theme_file);
      return style_sheet(theme_css);
    }
  }
  throw argument_exception {csf_};
}

style_sheet style_sheet::get_style_sheet_from_file(const ustring& file_name) {
  if (!xtd::io::file::exists(file_name)) throw xtd::io::directory_not_found_exception {csf_};
  auto theme_css = file::read_all_text(file_name);
  return style_sheet(theme_css);
}

style_sheet style_sheet::get_style_sheet_from_path(const ustring& path_name) {
  return style_sheet(get_css_string_from_path(path_name));
}

xtd::forms::style_sheets::system_colors style_sheet::system_colors_from_css(const ustring& css_text) {
  auto ss = style_sheet {css_text};
  return ss.system_colors();
}

xtd::forms::style_sheets::theme style_sheet::theme_from_css(const ustring& css_text) {
  auto ss = style_sheet {css_text};
  return ss.theme();
}

std::tuple<border_type, int32, int32> style_sheet::to_border_type(xtd::forms::border_style border) {
  switch (border) {
    case xtd::forms::border_style::none: return make_tuple(border_type::none, 0, 0); break;
    case xtd::forms::border_style::solid: return make_tuple(border_type::solid, 1, 0); break;
    case xtd::forms::border_style::inset: return make_tuple(border_type::inset, 1, 0); break;
    case xtd::forms::border_style::outset: return make_tuple(border_type::outset, 1, 0); break;
    case xtd::forms::border_style::groove: return make_tuple(border_type::groove, 2, 0); break;
    case xtd::forms::border_style::ridge: return make_tuple(border_type::ridge, 2, 0); break;
    case xtd::forms::border_style::theme: return make_tuple(border_type::theme, 2, 0); break;
    case xtd::forms::border_style::dashed: return make_tuple(border_type::dashed, 1, 0); break;
    case xtd::forms::border_style::dot_dash: return make_tuple(border_type::dot_dash, 1, 0); break;
    case xtd::forms::border_style::dot_dot_dash: return make_tuple(border_type::dot_dot_dash, 1, 0); break;
    case xtd::forms::border_style::dotted: return make_tuple(border_type::dotted, 1, 0); break;
    case xtd::forms::border_style::double_border: return make_tuple(border_type::double_border, 3, 0); break;
    case xtd::forms::border_style::bevel_inset: return make_tuple(border_type::inset, 4, 0); break;
    case xtd::forms::border_style::bevel_outset: return make_tuple(border_type::outset, 4, 0); break;
    case xtd::forms::border_style::rounded: return make_tuple(border_type::solid, 1, 6); break;
    default: break;
  }
  return make_tuple(border_type::none, 0, 0);
}

color style_sheet::background_color_from_css(const ustring& css_text, const color& default_value) const noexcept {
  auto result = default_value;
  try_parse_color(css_text.to_lower(), result);
  return result;
}

background_image style_sheet::background_image_from_css(const ustring& css_text, const background_image& default_value) const noexcept {
  auto result = background_image {};
  if (css_text.starts_with("url(", true) && css_text.ends_with(")", true) && try_parse_uri(css_text, result.url_)) return result;
  if (css_text.starts_with("linear-gradient(", true) && css_text.ends_with(")", true) && try_parse_linear_gradient(css_text.to_lower(), result)) return result;
  return default_value;
}

border_color style_sheet::border_color_from_css(const ustring& css_text, const border_color& default_value) const noexcept {
  auto values = split_values_from_text(css_text.to_lower());
  if (values.size() < 1 || values.size() > 4) return default_value;
  auto result = border_color {};
  result.all(color_from_css(values[0], default_value.top()));
  if (values.size() >= 2) result.right(color_from_css(values[0], default_value.right()));
  if (values.size() >= 3) result.bottom(color_from_css(values[0], default_value.right()));
  if (values.size() == 4) result.left(color_from_css(values[0], default_value.right()));
  return result;
}

style_sheets::border_style style_sheet::border_style_from_css(const ustring& css_text, const border_style& default_value) const noexcept {
  auto values = css_text.to_lower().split();
  static auto border_types = map<ustring, xtd::forms::style_sheets::border_type> {{"none", border_type::none}, {"hidden", border_type::hidden}, {"dashed", border_type::dashed}, {"dot-dash", border_type::dot_dash},  {"dot-dot-dash", border_type::dot_dot_dash}, {"dotted", border_type::dotted}, {"double", border_type::double_border}, {"groove", border_type::groove}, {"inset", border_type::inset}, {"outset", border_type::outset}, {"ridge", border_type::ridge}, {"solid", border_type::solid}, {"theme", border_type::theme}};
  if (values.size() < 1 || values.size() > 4) return default_value;
  
  auto result = border_style {};
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

border_radius style_sheet::border_radius_from_css(const ustring& css_text, const border_radius& default_value) const noexcept {
  auto values = css_text.to_lower().split();
  if (values.size() < 1 || values.size() > 4) return default_value;
  
  auto result = border_radius {};
  result.all(length_from_css(values[0], default_value.all()));
  
  if (values.size() >= 2) result.top_right(length_from_css(values[1], default_value.top_right()));
  if (values.size() >= 3) result.bottom_right(length_from_css(values[2], default_value.bottom_right()));
  if (values.size() == 4) result.bottom_left(length_from_css(values[3], default_value.bottom_left()));
  
  return result;
}

border_width style_sheet::border_width_from_css(const ustring& css_text, const border_width& default_value) const noexcept {
  auto values = css_text.to_lower().split();
  if (values.size() < 1 || values.size() > 4) return default_value;
  
  auto result = border_width {};
  result.all(length_from_css(values[0], default_value.all()));
  
  if (values.size() >= 2) result.right(length_from_css(values[1], default_value.left()));
  if (values.size() >= 3) result.bottom(length_from_css(values[2], default_value.bottom()));
  if (values.size() == 4) result.left(length_from_css(values[3], default_value.right()));
  
  return result;
}

color style_sheet::color_from_css(const ustring& css_text, const color& default_value) const noexcept {
  auto result = default_value;
  try_parse_color(css_text.to_lower(), result);
  return result;
}

length style_sheet::length_from_css(const ustring& css_text, const length& default_value) const noexcept {
  if (css_text.to_lower() == "auto" || css_text.to_lower() == "initial" || css_text.to_lower() == "inherit") return length(-1);
  auto l = .0;
  if (css_text.to_lower().ends_with("cm") && ::try_parse<double>(css_text.to_lower().replace("cm", ustring::empty_string), l)) return length(l, length_unit::centimeters);
  if (css_text.to_lower().ends_with("mm") && ::try_parse<double>(css_text.to_lower().replace("mm", ustring::empty_string), l)) return length(l, length_unit::millimeters);
  if (css_text.to_lower().ends_with("in") && ::try_parse<double>(css_text.to_lower().replace("in", ustring::empty_string), l)) return length(l, length_unit::inches);
  if (css_text.to_lower().ends_with("px") && ::try_parse<double>(css_text.to_lower().replace("px", ustring::empty_string), l)) return length(l, length_unit::pixels);
  if (css_text.to_lower().ends_with("pt") && ::try_parse<double>(css_text.to_lower().replace("pt", ustring::empty_string), l)) return length(l, length_unit::points);
  if (css_text.to_lower().ends_with("pc") && ::try_parse<double>(css_text.to_lower().replace("pc", ustring::empty_string), l)) return length(l, length_unit::picas);
  if (css_text.to_lower().ends_with("em") && ::try_parse<double>(css_text.to_lower().replace("em", ustring::empty_string), l)) return length(l, length_unit::element);
  if (css_text.to_lower().ends_with("ex") && ::try_parse<double>(css_text.to_lower().replace("ex", ustring::empty_string), l)) return length(l, length_unit::element_x_height);
  if (css_text.to_lower().ends_with("ch") && ::try_parse<double>(css_text.to_lower().replace("ch", ustring::empty_string), l)) return length(l, length_unit::chase);
  if (css_text.to_lower().ends_with("rem") && ::try_parse<double>(css_text.to_lower().replace("rem", ustring::empty_string), l)) return length(l, length_unit::root_element);
  if (css_text.to_lower().ends_with("vw") && ::try_parse<double>(css_text.to_lower().replace("vw", ustring::empty_string), l)) return length(l, length_unit::viewport_width);
  if (css_text.to_lower().ends_with("vh") && ::try_parse<double>(css_text.to_lower().replace("vh", ustring::empty_string), l)) return length(l, length_unit::viewport_height);
  if (css_text.to_lower().ends_with("vmin") && ::try_parse<double>(css_text.to_lower().replace("vmin", ustring::empty_string), l)) return length(l, length_unit::viewport_min);
  if (css_text.to_lower().ends_with("vmax") && ::try_parse<double>(css_text.to_lower().replace("vmax", ustring::empty_string), l)) return length(l, length_unit::viewport_max);
  if (css_text.to_lower().ends_with("%") && ::try_parse<double>(css_text.replace("%", ustring::empty_string), l)) return length(l, length_unit::percent);
  if (css_text == "0") return length(0);
  return default_value;
}

margin style_sheet::margin_from_css(const ustring& css_text, const margin& default_value) const noexcept {
  auto values = css_text.to_lower().split();
  if (values.size() < 1 || values.size() > 4) return default_value;
  
  auto result = margin {};
  result.all(length_from_css(values[0], default_value.all()));
  
  if (values.size() >= 2) result.right(length_from_css(values[1], default_value.left()));
  if (values.size() >= 3) result.bottom(length_from_css(values[2], default_value.bottom()));
  if (values.size() == 4) result.left(length_from_css(values[3], default_value.right()));
  
  return result;
}

margin style_sheet::margin_bottom_from_css(const ustring& css_text, const margin& default_value) const noexcept {
  auto values = css_text.to_lower().split();
  auto result = default_value;
  if (values.size() < 1 || values.size() > 1) return result;
  result.bottom(length_from_css(values[0], default_value.bottom()));
  return result;
}

margin style_sheet::margin_left_from_css(const ustring& css_text, const margin& default_value) const noexcept {
  auto values = css_text.to_lower().split();
  
  auto result = default_value;
  if (values.size() < 1 || values.size() > 1) return result;
  
  result.left(length_from_css(values[0], default_value.left()));
  
  return result;
}

margin style_sheet::margin_right_from_css(const ustring& css_text, const margin& default_value) const noexcept {
  auto values = css_text.to_lower().split();
  auto result = default_value;
  if (values.size() < 1 || values.size() > 1) return result;
  result.right(length_from_css(values[0], default_value.right()));
  return result;
}

margin style_sheet::margin_top_from_css(const ustring& css_text, const margin& default_value) const noexcept {
  auto values = css_text.to_lower().split();
  auto result = default_value;
  if (values.size() < 1 || values.size() > 1) return result;
  result.top(length_from_css(values[0], default_value.top()));
  return result;
}

style_sheets::padding style_sheet::padding_from_css(const ustring& css_text, const style_sheets::padding& default_value) const noexcept {
  auto values = css_text.to_lower().split();
  if (values.size() < 1 || values.size() > 4) return default_value;
  
  auto result = style_sheets::padding {};
  result.all(length_from_css(values[0], default_value.all()));
  
  if (values.size() >= 2) result.right(length_from_css(values[1], default_value.left()));
  if (values.size() >= 3) result.bottom(length_from_css(values[2], default_value.bottom()));
  if (values.size() == 4) result.left(length_from_css(values[3], default_value.right()));
  
  return result;
}

style_sheets::padding style_sheet::padding_bottom_from_css(const ustring& css_text, const style_sheets::padding& default_value) const noexcept {
  auto values = css_text.to_lower().split();
  auto result = default_value;
  if (values.size() < 1 || values.size() > 1) return result;
  result.bottom(length_from_css(values[0], default_value.bottom()));
  return result;
}

style_sheets::padding style_sheet::padding_left_from_css(const ustring& css_text, const style_sheets::padding& default_value) const noexcept {
  auto values = css_text.to_lower().split();
  auto result = default_value;
  if (values.size() < 1 || values.size() > 1) return result;
  result.left(length_from_css(values[0], default_value.left()));
  return result;
}

style_sheets::padding style_sheet::padding_right_from_css(const ustring& css_text, const style_sheets::padding& default_value) const noexcept {
  auto values = css_text.to_lower().split();
  auto result = default_value;
  
  if (values.size() < 1 || values.size() > 1) return result;
  result.right(length_from_css(values[0], default_value.right()));
  return result;
}

style_sheets::padding style_sheet::padding_top_from_css(const ustring& css_text, const style_sheets::padding& default_value) const noexcept {
  auto values = css_text.to_lower().split();
  auto result = default_value;
  if (values.size() < 1 || values.size() > 1) return result;
  result.top(length_from_css(values[0], default_value.top()));
  return result;
}

ustring style_sheet::string_from_css(const ustring& css_text, const ustring& default_value) const noexcept {
  auto value = css_text.trim();
  if (!value.starts_with("\"") || !value.ends_with("\"")) return default_value;
  return value.remove(value.size() - 1, 1).replace("\"", ustring::empty_string);
}

content_alignment style_sheet::text_align_from_css(const ustring& css_text, const content_alignment& default_value) const noexcept {
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
  auto decorations = map<ustring, text_decoration> {{"none", text_decoration::none}, {"line-through", text_decoration::line_through}, {"overline", text_decoration::overline}, {"underline", text_decoration::underline}};
  auto it = decorations.find(css_text.to_lower());
  if (it == decorations.end()) return default_value;
  return it->second;
}

text_transformation style_sheet::text_transformation_from_css(const ustring& css_text, const text_transformation& default_value) const noexcept {
  auto transformations = map<ustring, text_transformation> {{"none", text_transformation::none}, {"capitalize", text_transformation::capitalize}, {"lowercase", text_transformation::lowercase}, {"uppercase", text_transformation::uppercase}};
  auto it = transformations.find(css_text.to_lower());
  if (it == transformations.end()) return default_value;
  return it->second;
}

uri style_sheet::uri_from_css(const ustring& css_text, const uri& default_value) const noexcept {
  auto result = default_value;
  try_parse_uri(css_text, result);
  return result;
}

white_space style_sheet::white_space_from_css(const ustring& css_text, const xtd::forms::style_sheets::white_space& default_value) const noexcept {
  auto white_spaces = map<ustring, white_space> {{"normal", white_space::normal}, {"nowrap", white_space::no_wrap}, {"pre", white_space::pre}, {"pre-line", white_space::pre_line}, {"pre-wrap", white_space::pre_wrap}};
  auto it = white_spaces.find(css_text.to_lower());
  if (it == white_spaces.end()) return default_value;
  return it->second;
}

void style_sheet::on_style_sheet_changed(const xtd::event_args& e) {
  for (auto h : xtd::forms::control::handles_)
    h.second->send_message(h.first, WM_STYLE_SHEET_CHANGED, 0, 0);
  style_sheet_changed(current_style_sheet_, e);
}

void style_sheet::on_system_colors_changed(const event_args& e) {
  if (current_style_sheet().is_system_style_sheet() && current_style_sheet().system_colors().window() != xtd::drawing::system_colors::window()) {
    system_style_sheet_ = style_sheet::empty;
    current_style_sheet(system_style_sheet());
  } else system_style_sheet_ = style_sheet::empty;
}

vector<ustring> style_sheet::split_values_from_text(const ustring& text) const noexcept {
  static auto color_keywords = vector<ustring> {"rgb(", "rgba(", "argb(", "hsl(", "hsla(", "ahsl(", "hsv(", "hsva(", "ahsv(", "system-color("};
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
      result.push_back(value.substring(0, value.find(')') + 1).trim());
      value = value.remove(0, value.find(')') + 1).trim();
      if (value[0] == ',') value = value.remove(0, 1).trim();
    } else if (value.find(',') == ustring::npos) {
      result.push_back(value.trim());
      value = "";
    } else if (value.find(',') != ustring::npos) {
      result.push_back(value.substring(0, value.find(',')).trim());
      value = value.remove(0, value.find(',') + 1).trim();
    }
  }
  return result;
}

void style_sheet::button_reader(xtd::web::css::css_reader& reader) noexcept {
  static auto states = vector<pair<ustring, pseudo_state>> {{"", pseudo_state::standard}, {":pressed", pseudo_state::pressed}, {":checked", pseudo_state::checked}, {":hover", pseudo_state::hover}, {":disabled", pseudo_state::disabled}};
  static auto button_states = vector<pair<ustring, pseudo_state>> {{"button", pseudo_state::standard}, {"button:default", pseudo_state::default_state}};
  for (auto button : button_states) {
    for (auto state : states) {
      selector_map::const_iterator selectors_iterator = reader.selectors().find(button.first + state.first);
      if (selectors_iterator == reader.selectors().end() && state.second == pseudo_state::standard) return;
      if (selectors_iterator != reader.selectors().end() && state.second == pseudo_state::standard) data_->buttons[button.second] = xtd::forms::style_sheets::button();
      if (selectors_iterator == reader.selectors().end() || state.second != pseudo_state::standard) data_->buttons[button.second | state.second] = data_->buttons[button.second];
      if (selectors_iterator != reader.selectors().end()) fill_control(selectors_iterator, data_->buttons[button.second | state.second]);
    }
  }
}

void style_sheet::control_reader(xtd::web::css::css_reader& reader) noexcept {
  static auto states = vector<pair<ustring, pseudo_state>> {{"", pseudo_state::standard}, {":pressed", pseudo_state::pressed}, {":checked", pseudo_state::checked}, {":hover", pseudo_state::hover}, {":disabled", pseudo_state::disabled}};
  for (auto state : states) {
    selector_map::const_iterator selectors_iterator = reader.selectors().find("control" + state.first);
    if (selectors_iterator == reader.selectors().end() && state.second == pseudo_state::standard) return;
    if (selectors_iterator != reader.selectors().end() && state.second == pseudo_state::standard) data_->controls[pseudo_state::standard] = xtd::forms::style_sheets::control();
    if (selectors_iterator == reader.selectors().end() || state.second != pseudo_state::standard) data_->controls[pseudo_state::standard | state.second] = data_->controls[pseudo_state::standard];
    if (selectors_iterator != reader.selectors().end()) fill_control(selectors_iterator, data_->controls[pseudo_state::standard | state.second]);
  }
}

void style_sheet::fill_control(const xtd::web::css::selector_map::const_iterator& selectors_iterator, xtd::forms::style_sheets::control& control) noexcept {
  for (auto property : selectors_iterator->second.properties()) {
    if (property.first == "margin") control.margin(margin_from_css(property.second.to_string(), margin(length(0))));
    if (property.first == "margin-bottom") control.margin(margin_bottom_from_css(property.second.to_string(), control.margin()));
    if (property.first == "margin-left") control.margin(margin_left_from_css(property.second.to_string(), control.margin()));
    if (property.first == "margin-right") control.margin(margin_right_from_css(property.second.to_string(), control.margin()));
    if (property.first == "margin-top") control.margin(margin_top_from_css(property.second.to_string(), control.margin()));
    if (property.first == "border-style") control.border_style(border_style_from_css(property.second.to_string(), border_style(border_type::none)));
    if (property.first == "border-color") control.border_color(border_color_from_css(property.second.to_string(), border_color(color::transparent)));
    if (property.first == "border-width") control.border_width(border_width_from_css(property.second.to_string(), border_width(length(1))));
    if (property.first == "border-radius") control.border_radius(border_radius_from_css(property.second.to_string(), border_radius(length(0))));
    if (property.first == "outline-style") control.outline_style(border_style_from_css(property.second.to_string(), outline_style(border_type::none)));
    if (property.first == "outline-color") control.outline_color(border_color_from_css(property.second.to_string(), outline_color(color::transparent)));
    if (property.first == "outline-offset") control.outline_offset(border_width_from_css(property.second.to_string(), outline_offset(length(1))));
    if (property.first == "outline-width") control.outline_width(border_width_from_css(property.second.to_string(), outline_width(length(1))));
    if (property.first == "outline-radius") control.outline_radius(border_radius_from_css(property.second.to_string(), outline_radius(length(0))));
    if (property.first == "padding") control.padding(margin_from_css(property.second.to_string(), padding(length(0))));
    if (property.first == "padding-bottom") control.padding(margin_bottom_from_css(property.second.to_string(), control.padding()));
    if (property.first == "padding-left") control.padding(margin_left_from_css(property.second.to_string(), control.padding()));
    if (property.first == "padding-right") control.padding(margin_right_from_css(property.second.to_string(), control.padding()));
    if (property.first == "padding-top") control.padding(margin_top_from_css(property.second.to_string(), control.padding()));
    if (property.first == "height") control.height(length_from_css(property.second.to_string(), length(25)));
    if (property.first == "width") control.width(length_from_css(property.second.to_string(), length(75)));
    if (property.first == "background-color") control.background_color(background_color_from_css(property.second.to_string(), color::transparent));
    if (property.first == "background-image") control.background_image(background_image_from_css(property.second.to_string(), background_image::empty));
    if (property.first == "color") control.color(color_from_css(property.second.to_string(), color::transparent));
    if (property.first == "text-align") control.text_alignment(text_align_from_css(property.second.to_string(), content_alignment::middle_center));
    //if (property.first == "font") control.font(font_from_css(property.second.to_string(), content_alignment::middle_center));
    if (property.first == "text-decoration") control.decoration(text_decoration_from_css(property.second.to_string(), text_decoration::none));
    if (property.first == "text-transformation") control.transformation(text_transformation_from_css(property.second.to_string(), text_transformation::none));
    if (property.first == "image-align") control.image_alignment(text_align_from_css(property.second.to_string(), content_alignment::middle_center));
    if (property.first == "white-space") control.white_space(white_space_from_css(property.second.to_string(), xtd::forms::style_sheets::white_space::normal));
  }
}

void style_sheet::flat_button_reader(xtd::web::css::css_reader& reader) noexcept {
  static auto states = vector<pair<ustring, pseudo_state>> {{"", pseudo_state::standard}, {":hover", pseudo_state::hover}, {":pressed", pseudo_state::pressed}, {":checked", pseudo_state::checked}, {":disabled", pseudo_state::disabled}};
  static auto button_states = vector<pair<ustring, pseudo_state>> {{"flat-button", pseudo_state::standard}, {"flat-button:default", pseudo_state::standard | pseudo_state::default_state}};
  for (auto button : button_states) {
    for (auto state : states) {
      selector_map::const_iterator selectors_iterator = reader.selectors().find(button.first + state.first);
      if (selectors_iterator == reader.selectors().end() && state.second == pseudo_state::standard) return;
      if (selectors_iterator != reader.selectors().end() && state.second == pseudo_state::standard) data_->flat_buttons[button.second] = xtd::forms::style_sheets::button();
      if (selectors_iterator == reader.selectors().end() || state.second != pseudo_state::standard) data_->flat_buttons[button.second | state.second] = data_->flat_buttons[button.second];
      if (selectors_iterator != reader.selectors().end()) fill_control(selectors_iterator, data_->flat_buttons[button.second | state.second]);
    }
  }
}

void style_sheet::flat_toggle_button_reader(xtd::web::css::css_reader& reader) noexcept {
  static auto states = vector<pair<ustring, pseudo_state>> {{"", pseudo_state::standard}, {":hover", pseudo_state::hover}, {":pressed", pseudo_state::pressed}, {":disabled", pseudo_state::disabled}, {":checked", pseudo_state::checked}, {":checked:hover", pseudo_state::checked | pseudo_state::hover}, {":checked:pressed", pseudo_state::checked | pseudo_state::pressed}, {":checked:disabled", pseudo_state::checked | pseudo_state::disabled}, {":mixed", pseudo_state::mixed}, {":mixed:hover", pseudo_state::mixed | pseudo_state::hover}, {":mixed:pressed", pseudo_state::mixed | pseudo_state::pressed}, {":mixed:disabled", pseudo_state::mixed | pseudo_state::disabled}};
  for (auto state : states) {
    selector_map::const_iterator selectors_iterator = reader.selectors().find("flat-toggle-button" + state.first);
    if (selectors_iterator == reader.selectors().end() && state.second == pseudo_state::standard) return;
    if (selectors_iterator != reader.selectors().end() && state.second == pseudo_state::standard) data_->flat_toggle_buttons[pseudo_state::standard] = xtd::forms::style_sheets::button();
    if (selectors_iterator == reader.selectors().end() || state.second != pseudo_state::standard) data_->flat_toggle_buttons[pseudo_state::standard | state.second] = data_->flat_toggle_buttons[pseudo_state::standard];
    if (selectors_iterator != reader.selectors().end()) fill_control(selectors_iterator, data_->flat_toggle_buttons[pseudo_state::standard | state.second]);
  }
}

void style_sheet::form_reader(xtd::web::css::css_reader& reader) noexcept {
  static auto states = vector<pair<ustring, pseudo_state>> {{"", pseudo_state::standard}, {":pressed", pseudo_state::pressed}, {":checked", pseudo_state::checked}, {":hover", pseudo_state::hover}, {":disabled", pseudo_state::disabled}};
  for (auto state : states) {
    selector_map::const_iterator selectors_iterator = reader.selectors().find("form" + state.first);
    if (selectors_iterator == reader.selectors().end() && state.second == pseudo_state::standard) return;
    if (selectors_iterator != reader.selectors().end() && state.second == pseudo_state::standard) data_->forms[pseudo_state::standard] = xtd::forms::style_sheets::form();
    if (selectors_iterator == reader.selectors().end() || state.second != pseudo_state::standard) data_->forms[pseudo_state::standard | state.second] = data_->forms[pseudo_state::standard];
    if (selectors_iterator != reader.selectors().end()) fill_control(selectors_iterator, data_->forms[pseudo_state::standard | state.second]);
  }
}

void style_sheet::label_reader(xtd::web::css::css_reader& reader) noexcept {
  static auto states = vector<pair<ustring, pseudo_state>> {{"", pseudo_state::standard}, {":pressed", pseudo_state::pressed}, {":checked", pseudo_state::checked}, {":hover", pseudo_state::hover}, {":disabled", pseudo_state::disabled}};
  for (auto state : states) {
    selector_map::const_iterator selectors_iterator = reader.selectors().find("label" + state.first);
    if (selectors_iterator == reader.selectors().end() && state.second == pseudo_state::standard) return;
    if (selectors_iterator != reader.selectors().end() && state.second == pseudo_state::standard) data_->labels[pseudo_state::standard] = xtd::forms::style_sheets::label();
    if (selectors_iterator == reader.selectors().end() || state.second != pseudo_state::standard) data_->labels[pseudo_state::standard | state.second] = data_->labels[pseudo_state::standard];
    if (selectors_iterator != reader.selectors().end()) fill_control(selectors_iterator, data_->labels[pseudo_state::standard | state.second]);
  }
}

void style_sheet::link_label_reader(xtd::web::css::css_reader& reader) noexcept {
  static auto states = vector<pair<ustring, pseudo_state>> {{"", pseudo_state::standard}, {":pressed", pseudo_state::pressed}, {":checked", pseudo_state::checked}, {":link", pseudo_state::link}, {":visited", pseudo_state::visited}, {":hover", pseudo_state::hover}, {":active", pseudo_state::active}, {":disabled", pseudo_state::disabled}};
  for (auto state : states) {
    selector_map::const_iterator selectors_iterator = reader.selectors().find("link-label" + state.first);
    if (selectors_iterator == reader.selectors().end() && state.second == pseudo_state::standard) return;
    if (selectors_iterator != reader.selectors().end() && state.second == pseudo_state::standard) data_->link_labels[pseudo_state::standard] = xtd::forms::style_sheets::link_label();
    if (selectors_iterator == reader.selectors().end() || state.second != pseudo_state::standard) data_->link_labels[pseudo_state::standard | state.second] = data_->link_labels[pseudo_state::standard];
    if (selectors_iterator != reader.selectors().end()) fill_control(selectors_iterator, data_->link_labels[pseudo_state::standard | state.second]);
  }
}

void style_sheet::panel_reader(xtd::web::css::css_reader& reader) noexcept {
  static auto states = vector<pair<ustring, pseudo_state>> {{"", pseudo_state::standard}, {":pressed", pseudo_state::pressed}, {":checked", pseudo_state::checked}, {":hover", pseudo_state::hover}, {":disabled", pseudo_state::disabled}};
  for (auto state : states) {
    selector_map::const_iterator selectors_iterator = reader.selectors().find("panel" + state.first);
    if (selectors_iterator == reader.selectors().end() && state.second == pseudo_state::standard) return;
    if (selectors_iterator != reader.selectors().end() && state.second == pseudo_state::standard) data_->panels[pseudo_state::standard] = xtd::forms::style_sheets::panel();
    if (selectors_iterator == reader.selectors().end() || state.second != pseudo_state::standard) data_->panels[pseudo_state::standard | state.second] = data_->panels[pseudo_state::standard];
    if (selectors_iterator != reader.selectors().end()) fill_control(selectors_iterator, data_->panels[pseudo_state::standard | state.second]);
  }
}

void style_sheet::popup_button_reader(xtd::web::css::css_reader& reader) noexcept {
  static auto states = vector<pair<ustring, pseudo_state>> {{"", pseudo_state::standard}, {":hover", pseudo_state::hover}, {":pressed", pseudo_state::pressed}, {":checked", pseudo_state::checked}, {":disabled", pseudo_state::disabled}};
  static auto button_states = vector<pair<ustring, pseudo_state>> {{"popup-button", pseudo_state::standard}, {"popup-button:default", pseudo_state::standard | pseudo_state::default_state}};
  for (auto button : button_states) {
    for (auto state : states) {
      selector_map::const_iterator selectors_iterator = reader.selectors().find(button.first + state.first);
      if (selectors_iterator == reader.selectors().end() && state.second == pseudo_state::standard) return;
      if (selectors_iterator != reader.selectors().end() && state.second == pseudo_state::standard) data_->popup_buttons[button.second] = xtd::forms::style_sheets::button();
      if (selectors_iterator == reader.selectors().end() || state.second != pseudo_state::standard) data_->popup_buttons[button.second | state.second] = data_->popup_buttons[button.second];
      if (selectors_iterator != reader.selectors().end()) fill_control(selectors_iterator, data_->popup_buttons[button.second | state.second]);
    }
  }
}

void style_sheet::popup_toggle_button_reader(xtd::web::css::css_reader& reader) noexcept {
  static auto states = vector<pair<ustring, pseudo_state>> {{"", pseudo_state::standard}, {":hover", pseudo_state::hover}, {":pressed", pseudo_state::pressed}, {":disabled", pseudo_state::disabled}, {":checked", pseudo_state::checked}, {":checked:hover", pseudo_state::checked | pseudo_state::hover}, {":checked:pressed", pseudo_state::checked | pseudo_state::pressed}, {":checked:disabled", pseudo_state::checked | pseudo_state::disabled}, {":mixed", pseudo_state::mixed}, {":mixed:hover", pseudo_state::mixed | pseudo_state::hover}, {":mixed:pressed", pseudo_state::mixed | pseudo_state::pressed}, {":mixed:disabled", pseudo_state::mixed | pseudo_state::disabled}};
  for (auto state : states) {
    selector_map::const_iterator selectors_iterator = reader.selectors().find("popup-toggle-button" + state.first);
    if (selectors_iterator == reader.selectors().end() && state.second == pseudo_state::standard) return;
    if (selectors_iterator != reader.selectors().end() && state.second == pseudo_state::standard) data_->popup_toggle_buttons[pseudo_state::standard] = xtd::forms::style_sheets::button();
    if (selectors_iterator == reader.selectors().end() || state.second != pseudo_state::standard) data_->popup_toggle_buttons[pseudo_state::standard | state.second] = data_->popup_toggle_buttons[pseudo_state::standard];
    if (selectors_iterator != reader.selectors().end()) fill_control(selectors_iterator, data_->popup_toggle_buttons[pseudo_state::standard | state.second]);
  }
}

void style_sheet::status_bar_reader(xtd::web::css::css_reader& reader) noexcept {
  static auto states = vector<pair<ustring, pseudo_state>> {{"", pseudo_state::standard}, {":pressed", pseudo_state::pressed}, {":checked", pseudo_state::checked}, {":hover", pseudo_state::hover}, {":disabled", pseudo_state::disabled}};
  for (auto state : states) {
    selector_map::const_iterator selectors_iterator = reader.selectors().find("status-bar" + state.first);
    if (selectors_iterator == reader.selectors().end() && state.second == pseudo_state::standard) return;
    if (selectors_iterator != reader.selectors().end() && state.second == pseudo_state::standard) data_->status_bars[pseudo_state::standard] = xtd::forms::style_sheets::status_bar();
    if (selectors_iterator == reader.selectors().end() || state.second != pseudo_state::standard) data_->status_bars[pseudo_state::standard | state.second] = data_->status_bars[pseudo_state::standard];
    if (selectors_iterator != reader.selectors().end()) fill_control(selectors_iterator, data_->status_bars[pseudo_state::standard | state.second]);
  }
}

void style_sheet::status_bar_panel_reader(xtd::web::css::css_reader& reader) noexcept {
  static auto states = vector<pair<ustring, pseudo_state>> {{"", pseudo_state::standard}, {":pressed", pseudo_state::pressed}, {":checked", pseudo_state::checked}, {":hover", pseudo_state::hover}, {":disabled", pseudo_state::disabled}};
  for (auto state : states) {
    selector_map::const_iterator selectors_iterator = reader.selectors().find("tool-bar-button" + state.first);
    if (selectors_iterator == reader.selectors().end() && state.second == pseudo_state::standard) return;
    if (selectors_iterator != reader.selectors().end() && state.second == pseudo_state::standard) data_->status_bar_panels[pseudo_state::standard] = xtd::forms::style_sheets::status_bar_panel();
    if (selectors_iterator == reader.selectors().end() || state.second != pseudo_state::standard) data_->status_bar_panels[pseudo_state::standard | state.second] = data_->status_bar_panels[pseudo_state::standard];
    if (selectors_iterator != reader.selectors().end()) fill_control(selectors_iterator, data_->status_bar_panels[pseudo_state::standard | state.second]);
  }
}

void style_sheet::tool_bar_reader(xtd::web::css::css_reader& reader) noexcept {
  static auto states = vector<pair<ustring, pseudo_state>> {{"", pseudo_state::standard}, {":pressed", pseudo_state::pressed}, {":checked", pseudo_state::checked}, {":hover", pseudo_state::hover}, {":disabled", pseudo_state::disabled}};
  for (auto state : states) {
    selector_map::const_iterator selectors_iterator = reader.selectors().find("tool-bar" + state.first);
    if (selectors_iterator == reader.selectors().end() && state.second == pseudo_state::standard) return;
    if (selectors_iterator != reader.selectors().end() && state.second == pseudo_state::standard) data_->tool_bars[pseudo_state::standard] = xtd::forms::style_sheets::tool_bar();
    if (selectors_iterator == reader.selectors().end() || state.second != pseudo_state::standard) data_->tool_bars[pseudo_state::standard | state.second] = data_->tool_bars[pseudo_state::standard];
    if (selectors_iterator != reader.selectors().end()) fill_control(selectors_iterator, data_->tool_bars[pseudo_state::standard | state.second]);
  }
}

void style_sheet::tool_bar_button_reader(xtd::web::css::css_reader& reader) noexcept {
  static auto states = vector<pair<ustring, pseudo_state>> {{"", pseudo_state::standard}, {":pressed", pseudo_state::pressed}, {":checked", pseudo_state::checked}, {":hover", pseudo_state::hover}, {":disabled", pseudo_state::disabled}};
  for (auto state : states) {
    selector_map::const_iterator selectors_iterator = reader.selectors().find("tool-bar-button" + state.first);
    if (selectors_iterator == reader.selectors().end() && state.second == pseudo_state::standard) return;
    if (selectors_iterator != reader.selectors().end() && state.second == pseudo_state::standard) data_->tool_bar_buttons[pseudo_state::standard] = xtd::forms::style_sheets::tool_bar_button();
    if (selectors_iterator == reader.selectors().end() || state.second != pseudo_state::standard) data_->tool_bar_buttons[pseudo_state::standard | state.second] = data_->tool_bar_buttons[pseudo_state::standard];
    if (selectors_iterator != reader.selectors().end()) fill_control(selectors_iterator, data_->tool_bar_buttons[pseudo_state::standard | state.second]);
  }
}

void style_sheet::toggle_button_reader(xtd::web::css::css_reader& reader) noexcept {
  static auto states = vector<pair<ustring, pseudo_state>> {{"", pseudo_state::standard}, {":hover", pseudo_state::hover}, {":pressed", pseudo_state::pressed}, {":disabled", pseudo_state::disabled}, {":checked", pseudo_state::checked}, {":checked:hover", pseudo_state::checked | pseudo_state::hover}, {":checked:pressed", pseudo_state::checked | pseudo_state::pressed}, {":checked:disabled", pseudo_state::checked | pseudo_state::disabled}, {":mixed", pseudo_state::mixed}, {":mixed:hover", pseudo_state::mixed | pseudo_state::hover}, {":mixed:pressed", pseudo_state::mixed | pseudo_state::pressed}, {":mixed:disabled", pseudo_state::mixed | pseudo_state::disabled}};
  for (auto state : states) {
    selector_map::const_iterator selectors_iterator = reader.selectors().find("toggle-button" + state.first);
    if (selectors_iterator == reader.selectors().end() && state.second == pseudo_state::standard) return;
    if (selectors_iterator != reader.selectors().end() && state.second == pseudo_state::standard) data_->toggle_buttons[pseudo_state::standard] = xtd::forms::style_sheets::button();
    if (selectors_iterator == reader.selectors().end() || state.second != pseudo_state::standard) data_->toggle_buttons[pseudo_state::standard | state.second] = data_->toggle_buttons[pseudo_state::standard];
    if (selectors_iterator != reader.selectors().end()) fill_control(selectors_iterator, data_->toggle_buttons[pseudo_state::standard | state.second]);
  }
}

void style_sheet::user_control_reader(xtd::web::css::css_reader& reader) noexcept {
  static auto states = vector<pair<ustring, pseudo_state>> {{"", pseudo_state::standard}, {":pressed", pseudo_state::pressed}, {":checked", pseudo_state::checked}, {":hover", pseudo_state::hover}, {":disabled", pseudo_state::disabled}};
  for (auto state : states) {
    selector_map::const_iterator selectors_iterator = reader.selectors().find("user-control" + state.first);
    if (selectors_iterator == reader.selectors().end() && state.second == pseudo_state::standard) return;
    if (selectors_iterator != reader.selectors().end() && state.second == pseudo_state::standard) data_->user_controls[pseudo_state::standard] = xtd::forms::style_sheets::user_control();
    if (selectors_iterator == reader.selectors().end() || state.second != pseudo_state::standard) data_->user_controls[pseudo_state::standard | state.second] = data_->user_controls[pseudo_state::standard];
    if (selectors_iterator != reader.selectors().end()) fill_control(selectors_iterator, data_->user_controls[pseudo_state::standard | state.second]);
  }
}

void style_sheet::system_colors_reader(xtd::web::css::css_reader& reader) noexcept {
  auto selectors_iterator = reader.selectors().find("system-colors");
  if (selectors_iterator == reader.selectors().end()) return;
  for (auto property : selectors_iterator->second.properties()) {
    if (property.first == "accent") data_->system_colors.accent(color_from_css(property.second.to_string(), drawing::system_colors::accent()));
    if (property.first == "accent-text") data_->system_colors.accent_text(color_from_css(property.second.to_string(), drawing::system_colors::accent_text()));
    if (property.first == "active-border") data_->system_colors.active_border(color_from_css(property.second.to_string(), drawing::system_colors::active_border()));
    if (property.first == "active-caption") data_->system_colors.active_caption(color_from_css(property.second.to_string(), drawing::system_colors::active_caption()));
    if (property.first == "active-caption-text") data_->system_colors.active_caption_text(color_from_css(property.second.to_string(), drawing::system_colors::active_caption_text()));
    if (property.first == "active-text") data_->system_colors.active_text(color_from_css(property.second.to_string(), drawing::system_colors::active_text()));
    if (property.first == "app-workspace") data_->system_colors.app_workspace(color_from_css(property.second.to_string(), drawing::system_colors::app_workspace()));
    if (property.first == "button-face") data_->system_colors.button_face(color_from_css(property.second.to_string(), drawing::system_colors::button_face()));
    if (property.first == "button-highlight") data_->system_colors.button_highlight(color_from_css(property.second.to_string(), drawing::system_colors::button_highlight()));
    if (property.first == "button-shadow") data_->system_colors.button_shadow(color_from_css(property.second.to_string(), drawing::system_colors::button_shadow()));
    if (property.first == "control") data_->system_colors.control(color_from_css(property.second.to_string(), drawing::system_colors::control()));
    if (property.first == "control-dark") data_->system_colors.control_dark(color_from_css(property.second.to_string(), drawing::system_colors::control_dark()));
    if (property.first == "control-dark-dark") data_->system_colors.control_dark_dark(color_from_css(property.second.to_string(), drawing::system_colors::control_dark_dark()));
    if (property.first == "control-light") data_->system_colors.control_light(color_from_css(property.second.to_string(), drawing::system_colors::control_light()));
    if (property.first == "control-light-light") data_->system_colors.control_light_light(color_from_css(property.second.to_string(), drawing::system_colors::control_light_light()));
    if (property.first == "control-text") data_->system_colors.control_text(color_from_css(property.second.to_string(), drawing::system_colors::control_text()));
    if (property.first == "desktop") data_->system_colors.desktop(color_from_css(property.second.to_string(), drawing::system_colors::desktop()));
    if (property.first == "gradient-active-caption") data_->system_colors.gradient_active_caption(color_from_css(property.second.to_string(), drawing::system_colors::gradient_active_caption()));
    if (property.first == "gradient-inactive-caption") data_->system_colors.gradient_inactive_caption(color_from_css(property.second.to_string(), drawing::system_colors::gradient_inactive_caption()));
    if (property.first == "gray-text") data_->system_colors.gray_text(color_from_css(property.second.to_string(), drawing::system_colors::gray_text()));
    if (property.first == "highlight") data_->system_colors.highlight(color_from_css(property.second.to_string(), drawing::system_colors::highlight()));
    if (property.first == "highlight-text") data_->system_colors.highlight_text(color_from_css(property.second.to_string(), drawing::system_colors::highlight_text()));
    if (property.first == "hot-track") data_->system_colors.hot_track(color_from_css(property.second.to_string(), drawing::system_colors::hot_track()));
    if (property.first == "inactive-border") data_->system_colors.inactive_border(color_from_css(property.second.to_string(), drawing::system_colors::inactive_border()));
    if (property.first == "inactive-caption") data_->system_colors.inactive_caption(color_from_css(property.second.to_string(), drawing::system_colors::inactive_caption()));
    if (property.first == "inactive-caption-text") data_->system_colors.inactive_caption_text(color_from_css(property.second.to_string(), drawing::system_colors::inactive_caption_text()));
    if (property.first == "info") data_->system_colors.info(color_from_css(property.second.to_string(), drawing::system_colors::info()));
    if (property.first == "info-text") data_->system_colors.info_text(color_from_css(property.second.to_string(), drawing::system_colors::info_text()));
    if (property.first == "link-text") data_->system_colors.link_text(color_from_css(property.second.to_string(), drawing::system_colors::link_text()));
    if (property.first == "menu") data_->system_colors.menu(color_from_css(property.second.to_string(), drawing::system_colors::menu()));
    if (property.first == "menu-bar") data_->system_colors.menu_bar(color_from_css(property.second.to_string(), drawing::system_colors::menu_bar()));
    if (property.first == "menu-highlight") data_->system_colors.menu_highlight(color_from_css(property.second.to_string(), drawing::system_colors::menu_highlight()));
    if (property.first == "menu-text") data_->system_colors.menu_text(color_from_css(property.second.to_string(), drawing::system_colors::menu_text()));
    if (property.first == "scroll-bar") data_->system_colors.scroll_bar(color_from_css(property.second.to_string(), drawing::system_colors::scroll_bar()));
    if (property.first == "shadow-text") data_->system_colors.shadow_text(color_from_css(property.second.to_string(), drawing::system_colors::shadow_text()));
    if (property.first == "text-box") data_->system_colors.text_box(color_from_css(property.second.to_string(), drawing::system_colors::text_box()));
    if (property.first == "text-box-text") data_->system_colors.text_box_text(color_from_css(property.second.to_string(), drawing::system_colors::text_box_text()));
    if (property.first == "visited-text") data_->system_colors.visited_text(color_from_css(property.second.to_string(), drawing::system_colors::visited_text()));
    if (property.first == "window") data_->system_colors.window(color_from_css(property.second.to_string(), drawing::system_colors::window()));
    if (property.first == "window-frame") data_->system_colors.window_frame(color_from_css(property.second.to_string(), drawing::system_colors::window_frame()));
    if (property.first == "window-text") data_->system_colors.window_text(color_from_css(property.second.to_string(), drawing::system_colors::window_text()));
  }
}

void style_sheet::theme_reader(xtd::web::css::css_reader& reader) noexcept {
  auto selectors_iterator =  reader.selectors().find("theme");
  if (selectors_iterator == reader.selectors().end()) return;
  for (auto property : selectors_iterator->second.properties()) {
    if (property.first == "name") data_->theme.name(string_from_css(property.second.to_string(), ustring()));
    if (property.first == "description") data_->theme.description(string_from_css(property.second.to_string(), ustring()));
    if (property.first == "authors") data_->theme.authors(string_from_css(property.second.to_string(), ustring()));
    if (property.first == "website") data_->theme.website(uri_from_css(property.second.to_string(), uri()));
  }
}

bool style_sheet::try_parse_color(const ustring& text, xtd::drawing::color& result) const noexcept {
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
  if (text.starts_with("#") && text.size() == 4_z) {
    xtd::byte r = 0;
    if (xtd::try_parse<xtd::byte>(text.substring(1, 1), r, number_styles::hex_number) == false) return false;
    r += r * 16;
    xtd::byte g = 0;
    if (xtd::try_parse<xtd::byte>(text.substring(2, 1), g, number_styles::hex_number) == false) return false;
    g += g * 16;
    xtd::byte b = 0;
    if (xtd::try_parse<xtd::byte>(text.substring(3, 1), b, number_styles::hex_number) == false) return false;
    b += b * 16;
    result = color::from_argb(r, g, b);
    return true;
  }
  if (text.starts_with("#") && text.size() == 5_z) {
    xtd::byte a = 0;
    if (xtd::try_parse<xtd::byte>(text.substring(1, 1), a, number_styles::hex_number) == false) return false;
    a += a * 16;
    xtd::byte r = 0;
    if (xtd::try_parse<xtd::byte>(text.substring(2, 1), r, number_styles::hex_number) == false) return false;
    r += r * 16;
    xtd::byte g = 0;
    if (xtd::try_parse<xtd::byte>(text.substring(3, 1), g, number_styles::hex_number) == false) return false;
    g += g * 16;
    xtd::byte b = 0;
    if (xtd::try_parse<xtd::byte>(text.substring(4, 1), b, number_styles::hex_number) == false) return false;
    b += b * 16;
    result = color::from_argb(a, r, g, b);
    return true;
  }
  if (text.starts_with("#") && text.size() == 7_z) {
    auto rgb = 0u;
    if (xtd::try_parse<uint32>(text.substring(1), rgb, number_styles::hex_number) == false) return false;
    result = color::from_argb(rgb + 0xFF000000u);
    return true;
  }
  if (text.starts_with("#") && text.size() == 9_z) {
    auto argb = 0u;
    if (xtd::try_parse<uint32>(text.substring(1), argb, number_styles::hex_number) == false) return false;
    result = color::from_argb(argb);
    return true;
  }
  return false;
}

bool style_sheet::try_parse_linear_gradient(const ustring& text, background_image& result) const noexcept {
  auto arguments = split_values_from_text(text.remove(text.size() - 1).replace("linear-gradient(", ustring::empty_string));
  auto colors = vector<color> {};
  auto angle = -1;
  for (auto argument : arguments) {
    drawing::color gradient_color;
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
      argument = argument.replace("deg", ustring::empty_string);
      if (angle != -1 || xtd::try_parse<int32>(argument, angle) == false) return false;
    } else if (try_parse_color(argument, gradient_color))
      colors.push_back(gradient_color);
  }
  if (colors.size() < 2) return false;
  result = background_image(style_sheets::image_type::linear_gradient, colors, angle == -1 ? 180 : angle);
  return true;
}

bool style_sheet::try_parse_rgb_color(const ustring& text, color& result) const noexcept {
  auto value = text.remove(text.size() - 1).replace("rgb(", ustring::empty_string);
  auto color_parts = value.split({','});
  if (color_parts.size() != 3) return false;
  xtd::byte r = 0;
  if (xtd::try_parse<xtd::byte>(color_parts[0], r) == false) return false;
  xtd::byte g = 0;
  if (xtd::try_parse<xtd::byte>(color_parts[1], g) == false) return false;
  xtd::byte b = 0;
  if (xtd::try_parse<xtd::byte>(color_parts[2], b) == false) return false;
  result = color::from_argb(r, g, b);
  return true;
}

bool style_sheet::try_parse_rgba_color(const ustring& text, color& result) const noexcept {
  auto value = text.remove(text.size() - 1).replace("rgba(", ustring::empty_string);
  auto color_parts = value.split({','});
  if (color_parts.size() != 4) return false;
  xtd::byte r = 0;
  if (xtd::try_parse<xtd::byte>(color_parts[0], r) == false) return false;
  xtd::byte g = 0;
  if (xtd::try_parse<xtd::byte>(color_parts[1], g) == false) return false;
  xtd::byte b = 0;
  if (xtd::try_parse<xtd::byte>(color_parts[2], b) == false) return false;
  float a = 0;
  if (xtd::try_parse<float>(color_parts[3], a) == false) return false;
  result = color::from_argb(as<xtd::byte>(as<int32>(a * 255) % 256), r, g, b);
  return true;
}

bool style_sheet::try_parse_hsv_color(const ustring& text, color& result) const noexcept {
  auto value = text.remove(text.size() - 1).replace("hsv(", ustring::empty_string);
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
  auto value = text.remove(text.size() - 1).replace("hsva(", ustring::empty_string);
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
  result = color::from_argb(as<xtd::byte>(as<int32>(a * 255) % 256), color::from_hsb(h, s, v));
  return true;
}

bool style_sheet::try_parse_hsl_color(const ustring& text, color& result) const noexcept {
  auto value = text.remove(text.size() - 1).replace("hsl(", ustring::empty_string);
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
  auto value = text.remove(text.size() - 1).replace("hsla(", ustring::empty_string);
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
  result = color::from_argb(as<xtd::byte>(as<int32>(a * 255) % 256), color::from_hsl(h, s, l));
  return true;
}

bool style_sheet::try_parse_named_color(const ustring& text, color& result) const noexcept {
  if (text.trim().find(' ') != ustring::npos) return false;
  auto named_color = color::from_name(text);
  if (!named_color.is_known_color()) return false;
  result = named_color;
  return true;
}

bool style_sheet::try_parse_system_color(const ustring& text, color& result) const noexcept {
  auto value = text.remove(text.size() - 1).replace("system-color(", ustring::empty_string);
  map<ustring, drawing::color> colors {{"accent", system_colors().accent()}, {"accent-text", system_colors().accent_text()}, {"active-border", system_colors().active_border()}, {"active-caption", system_colors().active_caption()}, {"active-caption-text", system_colors().active_caption_text()}, {"app-workspace", system_colors().app_workspace()}, {"button-face", system_colors().button_face()}, {"button-highlight", system_colors().button_highlight()}, {"button-shadow", system_colors().button_shadow()}, {"control", system_colors().control()}, {"control-dark", system_colors().control_dark()}, {"control-dark-dark", system_colors().control_dark_dark()}, {"control-light", system_colors().control_light()}, {"control-light-light", system_colors().control_light_light()}, {"control-text", system_colors().control_text()}, {"desktop", system_colors().desktop()}, {"gradient-active-caption", system_colors().gradient_active_caption()}, {"gradient-inactive-caption", system_colors().gradient_inactive_caption()}, {"gray-text", system_colors().gray_text()}, {"highlight", system_colors().highlight()}, {"highlight-text", system_colors().highlight_text()}, {"hot-track", system_colors().hot_track()}, {"inactive-border", system_colors().inactive_border()}, {"inactive-caption", system_colors().inactive_caption()}, {"inactive-caption-text", system_colors().inactive_caption_text()}, {"info", system_colors().info()}, {"info-text", system_colors().info_text()}, {"menu", system_colors().menu()}, {"menu-bar", system_colors().menu_bar()}, {"menu-highlight", system_colors().menu_highlight()}, {"menu-text", system_colors().menu_text()}, {"scroll-bar", system_colors().scroll_bar()}, {"shadow-text", system_colors().shadow_text()}, {"text-box", system_colors().text_box()}, {"text-box-text", system_colors().text_box_text()}, {"window", system_colors().window()}, {"window-frame", system_colors().window_frame()}, {"window-text", system_colors().window_text()}};
  auto it = colors.find(value);
  if (it == colors.end()) return false;
  result = it->second;
  return true;
}

bool style_sheet::try_parse_uri(const ustring& text, xtd::uri& result) const noexcept {
  if (!text.starts_with("url", true) || !text.ends_with(")", true)) return false;
  result = uri(text.remove(text.size() - 1, 1).remove(0, 4));
  return true;
}

void style_sheet::system_colors_(const xtd::forms::style_sheets::system_colors& system_colors) {
  data_->system_colors = system_colors;
}

void style_sheet::theme_(const xtd::forms::style_sheets::theme& theme) {
  data_->theme = theme;
}

void style_sheet::theme_name_(const ustring& name) {
  data_->theme.name(name);
}
