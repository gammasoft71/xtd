#include "input_name_dialog.h"
#include "../properties/settings.h"

using namespace minesweeper;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

input_name_dialog::input_name_dialog() {
  start_position(form_start_position::center_parent);
  minimize_box(false);
  maximize_box(false);
  close_box(false);
  control_box(false);
  form_border_style(xtd::forms::form_border_style::none);
  client_size({200, 160});
  
  if (properties::settings::default_settings().original_color()) {
    back_color(color::silver);
    fore_color(color::black);
    name_text_box_.fore_color(color::black);
  }
  
  message_label_.parent(*this);
  message_label_.location({10, 10});
  message_label_.size({180, 60});
  message_label_.text_align(content_alignment::middle_center);
  message_label_.text(xtd::ustring::format("You have the fastest time\nfor {} level.\nPlease type your name."_t, level_to_string()));
  
  name_text_box_.parent(*this);
  name_text_box_.location({10, 80});
  name_text_box_.width(180);
  name_text_box_.text(gammer_name_);
  name_text_box_.focus();
  
  ok_button_.parent(*this);
  ok_button_.location({57, 120});
  ok_button_.text(xtd::forms::texts::ok());
  ok_button_.dialog_result(dialog_result::ok);
  ok_button_.click += [&] {
    gammer_name_= name_text_box_.text();
  };
  accept_button(ok_button_);
}

minesweeper::level input_name_dialog::level() const noexcept {
  return level_;
}

void input_name_dialog::level(minesweeper::level level) noexcept {
  level_ = level;
  message_label_.text(xtd::ustring::format("You have the fastest time\nfor {} level.\nPlease type your name."_t, level_to_string()));
}

std::string input_name_dialog::gammer_name() const noexcept {
  return gammer_name_;
}

void input_name_dialog::gammer_name(const std::string& gammer_name) noexcept {
  gammer_name_ = gammer_name;
  name_text_box_.text(gammer_name_);
}

std::string input_name_dialog::level_to_string() noexcept {
  static std::map<minesweeper::level, std::string> levels {{minesweeper::level::beginner, "beginner"_t}, {minesweeper::level::intermediate, "intermediate"_t}, {minesweeper::level::expert, "expert"_t}};
  auto it = levels.find(level_);
  if (it == levels.end()) return "{unknown"_t;
  return it->second;
}
