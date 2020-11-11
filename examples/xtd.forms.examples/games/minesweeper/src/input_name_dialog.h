#pragma once
#include "level.h"
#include "../properties/settings.h"
#include <xtd/xtd.forms>

namespace minesweeper {
  class input_name_dialog : public xtd::forms::form {
  public:
    input_name_dialog() {
      using namespace xtd::drawing;
      using namespace xtd::forms;
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
      message_label_.text(xtd::strings::format("You have the fastest time\nfor {} level.\nPlease type your name.", level_to_string()));
      
      name_text_box_.parent(*this);
      name_text_box_.location({10, 80});
      name_text_box_.width(180);
      name_text_box_.text(gammer_name_);
      name_text_box_.focus();

      ok_button_.parent(*this);
      ok_button_.location({57, 120});
      ok_button_.text(xtd::forms::texts::ok);
      ok_button_.dialog_result(dialog_result::ok);
      ok_button_.click += [&] {
        gammer_name_= name_text_box_.text();
      };
      accept_button(ok_button_);
    }
    
    minesweeper::level level() const {return level_;}
    void level(minesweeper::level level) {
      level_ = level;
      message_label_.text(xtd::strings::format("You have the fastest time\nfor {} level.\nPlease type your name.", level_to_string()));
    }
    
    std::string gammer_name() const {return gammer_name_;}
    void gammer_name(const std::string& gammer_name) {
      gammer_name_ = gammer_name;
      name_text_box_.text(gammer_name_);
    }
    
  private:
    std::string level_to_string() {return std::map<minesweeper::level, std::string> {{minesweeper::level::beginner, "beginner"}, {minesweeper::level::intermediate, "intermediate"}, {minesweeper::level::expert, "expert"}}[level_];}
    xtd::forms::label message_label_;
    xtd::forms::text_box name_text_box_;
    xtd::forms::button ok_button_;
    minesweeper::level level_ = level::beginner;
    std::string gammer_name_ = "Anonymous";
  };
}
