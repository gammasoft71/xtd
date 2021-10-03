#include "high_scores_dialog.h"
#include "level.h"
#include "../properties/settings.h"

using namespace minesweeper;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

high_scores_dialog::high_scores_dialog() {
  start_position(form_start_position::center_parent);
  minimize_box(false);
  maximize_box(false);
  close_box(false);
  control_box(false);
  form_border_style(forms::form_border_style::none);
  client_size({360, 200});
  accept_button(ok_button_);
  controls().push_back_range({title_, beginner_level_label_, intermediate_level_label_, expert_level_label_, beginner_score_label_, intermediate_score_label_, expert_score_label_, beginner_name_label_, intermediate_name_label_, expert_name_label_, reset_scores_button_, ok_button_});
  
  if (properties::settings::default_settings().original_color()) {
    back_color(color::silver);
    fore_color(color::black);
  }
  
  title_.text_align(content_alignment::middle_center);
  title_.location({10, 15});
  title_.width(340);
  title_.text("Fastest Mine Sweepers"_t);
  
  beginner_level_label_.location({10, 55});
  beginner_level_label_.auto_size(true);
  beginner_level_label_.text("Beginner"_t);
  
  intermediate_level_label_.location({10, 85});
  intermediate_level_label_.auto_size(true);
  intermediate_level_label_.text("Intermediate"_t);
  
  expert_level_label_.location({10, 115});
  expert_level_label_.auto_size(true);
  expert_level_label_.text("Expert"_t);
  
  beginner_score_label_.location({130, 55});
  beginner_score_label_.auto_size(true);
  
  intermediate_score_label_.location({130, 85});
  intermediate_score_label_.auto_size(true);
  
  expert_score_label_.location({130, 115});
  expert_score_label_.auto_size(true);
  
  beginner_name_label_.location({250, 55});
  beginner_name_label_.auto_size(true);
  
  intermediate_name_label_.location({250, 85});
  intermediate_name_label_.auto_size(true);
  
  expert_name_label_.location({250, 115});
  expert_name_label_.auto_size(true);
  
  reset_scores_button_.location({70, 150});
  reset_scores_button_.width(100);
  reset_scores_button_.text("&Reset Scores"_t);
  reset_scores_button_.click += [&] {
    properties::settings empty;
    properties::settings::default_settings().beginner_high_scores_name(empty.beginner_high_scores_name());
    properties::settings::default_settings().beginner_high_scores_value(empty.beginner_high_scores_value());
    properties::settings::default_settings().intermediate_high_scores_name(empty.intermediate_high_scores_name());
    properties::settings::default_settings().intermediate_high_scores_value(empty.intermediate_high_scores_value());
    properties::settings::default_settings().expert_high_scores_name(empty.expert_high_scores_name());
    properties::settings::default_settings().expert_high_scores_value(empty.expert_high_scores_value());
    properties::settings::default_settings().save();
    read_and_update_settings();
  };
  
  ok_button_.location({190, 150});
  ok_button_.width(100);
  ok_button_.text(system_texts::ok());
  ok_button_.dialog_result(dialog_result::ok);
  accept_button(ok_button_);
  
  read_and_update_settings();
}

void high_scores_dialog::read_and_update_settings() {
  beginner_score_label_.text(ustring::format("{} seconds"_t, properties::settings::default_settings().beginner_high_scores_value()));
  intermediate_score_label_.text(ustring::format("{} seconds"_t, properties::settings::default_settings().intermediate_high_scores_value()));
  expert_score_label_.text(ustring::format("{} seconds"_t, properties::settings::default_settings().expert_high_scores_value()));
  
  beginner_name_label_.text(properties::settings::default_settings().beginner_high_scores_name());
  intermediate_name_label_.text(properties::settings::default_settings().intermediate_high_scores_name());
  expert_name_label_.text(properties::settings::default_settings().expert_high_scores_name());
}
