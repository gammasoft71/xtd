#include "settings_form.hpp"
#include <xtd/xtd>

using namespace ball;

settings_form::settings_form() {
  text(environment::os_version().is_macos() && environment::os_version().version().major() < 13 ? "Preferences" :  "Settings...");
  maximize_box(false);
  minimize_box(false);
  form_border_style(forms::form_border_style::fixed_3d);
  if (environment::os_version().is_macos()) back_color(application::style_sheet().system_colors().app_workspace());
  client_size({500, 250});
  start_position(form_start_position::manual);
  location(properties::settings::default_settings().settings_form_location());
  controls().push_back_range({color_label_, light_point_color_label_, size_label_, default_settings_label_, color_color_picker_, light_point_color_color_picker_, opcacity_label_, opacity_numeric_up_down_, size_numeric_up_down_, reset_button_});
  
  auto middle = width() / 2;
  color_label_.text("Color");
  color_label_.text_align(xtd::forms::content_alignment::middle_right);
  color_label_.size({200, 25});
  color_label_.location({middle - color_label_.width() - 10, 30});
  
  light_point_color_label_.text("Light point color");
  light_point_color_label_.text_align(xtd::forms::content_alignment::middle_right);
  light_point_color_label_.size({200, 25});
  light_point_color_label_.location({middle - light_point_color_label_.width() - 10, 60});
  
  opcacity_label_.text("Opacity");
  opcacity_label_.text_align(xtd::forms::content_alignment::middle_right);
  opcacity_label_.size({200, 25});
  opcacity_label_.location({middle - opcacity_label_.width() - 10, 90});
  
  size_label_.text("Size");
  size_label_.text_align(xtd::forms::content_alignment::middle_right);
  size_label_.size({200, 25});
  size_label_.location({middle - size_label_.width() - 10, 120});

  default_settings_label_.text("Default settings");
  default_settings_label_.text_align(xtd::forms::content_alignment::middle_right);
  default_settings_label_.size({200, 25});
  default_settings_label_.location({middle - default_settings_label_.width() - 10, 180});

  color_color_picker_.location({middle + 10, 30});
  color_color_picker_.color(properties::settings::default_settings().color());
  color_color_picker_.color_picker_changed += delegate_ {
    if (properties::settings::default_settings().color() == color_color_picker_.color()) return;
    properties::settings::default_settings().color(color_color_picker_.color());
    light_point_color_color_picker_.color(color_converter::light(color_color_picker_.color(), 0.66f));
    on_settings_changed(event_args::empty);
  };

  light_point_color_color_picker_.location({middle + 10, 60});
  light_point_color_color_picker_.color(properties::settings::default_settings().light_point_color());
  light_point_color_color_picker_.color_picker_changed += delegate_ {
    if (properties::settings::default_settings().light_point_color() == light_point_color_color_picker_.color()) return;
    properties::settings::default_settings().light_point_color(light_point_color_color_picker_.color());
    on_settings_changed(event_args::empty);
  };

  opacity_numeric_up_down_.location({middle + 10, 90});
  opacity_numeric_up_down_.set_range(1, 100);
  opacity_numeric_up_down_.value(properties::settings::default_settings().opacity() * 100);
  opacity_numeric_up_down_.value_changed += delegate_ {
    if (properties::settings::default_settings().opacity() == opacity_numeric_up_down_.value() / 100) return;
    properties::settings::default_settings().opacity(opacity_numeric_up_down_.value() / 100);
    on_settings_changed(event_args::empty);
  };

  size_numeric_up_down_.location({middle + 10, 120});
  size_numeric_up_down_.set_range(10, 600);
  size_numeric_up_down_.value(properties::settings::default_settings().size().width);
  size_numeric_up_down_.value_changed += delegate_ {
    if (properties::settings::default_settings().size().width == as<int>(size_numeric_up_down_.value()) && properties::settings::default_settings().size().height == as<int>(size_numeric_up_down_.value())) return;
    properties::settings::default_settings().size({as<int>(size_numeric_up_down_.value()), as<int>(size_numeric_up_down_.value())});
    on_settings_changed(event_args::empty);
  };

  reset_button_.location({middle + 10, 180});
  reset_button_.text("Reset");
  reset_button_.click += delegate_ {
    properties::settings::default_settings().reset();
    auto default_settings = properties::settings::default_settings();
    color_color_picker_.color(default_settings.color());
    light_point_color_color_picker_.color(default_settings.light_point_color());
    opacity_numeric_up_down_.value(default_settings.opacity() * 100);
    size_numeric_up_down_.value(default_settings.size().width);
    settings(default_settings);
  };
}

const ball::properties::settings& settings_form::settings() const noexcept {
  return properties::settings::default_settings();
}

settings_form& settings_form::settings(const ball::properties::settings& value) noexcept {
  if (properties::settings::default_settings() == value) return *this;
  properties::settings::default_settings() = value;
  on_settings_changed(xtd::event_args::empty);
  return *this;
}

void settings_form::on_form_closed(const xtd::forms::form_closed_event_args& e) {
  properties::settings::default_settings().settings_form_location(location());
  properties::settings::default_settings().save();
}

void settings_form::on_settings_changed(const xtd::event_args& e) {
  settings_changed(*this, e);
}
