#include "../../../../include/xtd/forms/style_sheets/style_sheet.h"
#include <xtd/as.h>
#include <xtd/is.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/io/directory.h>
#include <xtd/io/file.h>
#include <xtd/web/css/css_reader.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::io;
using namespace xtd::forms::style_sheets;
using namespace xtd::web::css;

namespace {
  void theme_reader(selector_map::const_iterator& selectors_iterator, theme_selector& theme) {
    property_map::const_iterator properties_iterator;
    if ((properties_iterator = selectors_iterator->second.properties().find("name")) != selectors_iterator->second.properties().end()) theme.name(string_value::from_css(properties_iterator->second.to_string(), string_value()));
    if ((properties_iterator = selectors_iterator->second.properties().find("description")) != selectors_iterator->second.properties().end()) theme.description(string_value::from_css(properties_iterator->second.to_string(), string_value()));
    if ((properties_iterator = selectors_iterator->second.properties().find("authors")) != selectors_iterator->second.properties().end()) theme.authors(string_value::from_css(properties_iterator->second.to_string(), string_value()));
    if ((properties_iterator = selectors_iterator->second.properties().find("website")) != selectors_iterator->second.properties().end()) theme.website(url_value::from_css(properties_iterator->second.to_string(), url_value()));
  }

  void system_color_reader(selector_map::const_iterator& selectors_iterator, system_colors_selector& colors) {
    property_map::const_iterator properties_iterator;
    if ((properties_iterator = selectors_iterator->second.properties().find("accent")) != selectors_iterator->second.properties().end()) colors.accent(color_property::from_css(properties_iterator->second.to_string(), color_property(system_colors::accent())));
    if ((properties_iterator = selectors_iterator->second.properties().find("accent-text")) != selectors_iterator->second.properties().end()) colors.accent_text(color_property::from_css(properties_iterator->second.to_string(), color_property(system_colors::accent_text())));
    if ((properties_iterator = selectors_iterator->second.properties().find("active-border")) != selectors_iterator->second.properties().end()) colors.active_border(color_property::from_css(properties_iterator->second.to_string(), color_property(system_colors::active_border())));
    if ((properties_iterator = selectors_iterator->second.properties().find("active-caption")) != selectors_iterator->second.properties().end()) colors.active_caption(color_property::from_css(properties_iterator->second.to_string(), color_property(system_colors::active_caption())));
    if ((properties_iterator = selectors_iterator->second.properties().find("app-workspace")) != selectors_iterator->second.properties().end()) colors.app_workspace(color_property::from_css(properties_iterator->second.to_string(), color_property(system_colors::app_workspace())));
    if ((properties_iterator = selectors_iterator->second.properties().find("button-face")) != selectors_iterator->second.properties().end()) colors.button_face(color_property::from_css(properties_iterator->second.to_string(), color_property(system_colors::button_face())));
    if ((properties_iterator = selectors_iterator->second.properties().find("button-highlight")) != selectors_iterator->second.properties().end()) colors.button_highlight(color_property::from_css(properties_iterator->second.to_string(), color_property(system_colors::button_highlight())));
    if ((properties_iterator = selectors_iterator->second.properties().find("button-shadow")) != selectors_iterator->second.properties().end()) colors.button_shadow(color_property::from_css(properties_iterator->second.to_string(), color_property(system_colors::button_shadow())));
    if ((properties_iterator = selectors_iterator->second.properties().find("control")) != selectors_iterator->second.properties().end()) colors.control(color_property::from_css(properties_iterator->second.to_string(), color_property(system_colors::control())));
    if ((properties_iterator = selectors_iterator->second.properties().find("control-dark")) != selectors_iterator->second.properties().end()) colors.control_dark(color_property::from_css(properties_iterator->second.to_string(), color_property(system_colors::control_dark())));
    if ((properties_iterator = selectors_iterator->second.properties().find("control-dark-dark")) != selectors_iterator->second.properties().end()) colors.control_dark_dark(color_property::from_css(properties_iterator->second.to_string(), color_property(system_colors::control_dark_dark())));
    if ((properties_iterator = selectors_iterator->second.properties().find("control-light")) != selectors_iterator->second.properties().end()) colors.control_light(color_property::from_css(properties_iterator->second.to_string(), color_property(system_colors::control_light())));
    if ((properties_iterator = selectors_iterator->second.properties().find("control-light-light")) != selectors_iterator->second.properties().end()) colors.control_light_light(color_property::from_css(properties_iterator->second.to_string(), color_property(system_colors::control_light_light())));
    if ((properties_iterator = selectors_iterator->second.properties().find("control-text")) != selectors_iterator->second.properties().end()) colors.control_text(color_property::from_css(properties_iterator->second.to_string(), color_property(system_colors::control_text())));
    if ((properties_iterator = selectors_iterator->second.properties().find("desktop")) != selectors_iterator->second.properties().end()) colors.desktop(color_property::from_css(properties_iterator->second.to_string(), color_property(system_colors::desktop())));
  }
}

std::map<ustring, style_sheet> style_sheet::style_sheets_;

style_sheet::style_sheet(const xtd::ustring& text) {
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

void style_sheet::initilize() {
  if (!style_sheets_.empty()) return;
  
  for (auto theme_dir : directory::enumerate_directories(__XTD_THEMES_PATH__)) {
    xtd::ustring theme_css;
    for (auto theme_file : directory::enumerate_files(theme_dir, "*.css"))
      theme_css += file::read_all_text(theme_file);
    style_sheet style(theme_css);
    if (!style.theme().name().text().empty())
      style_sheets_[style.theme().name().text()] = style;
  }
  
}
