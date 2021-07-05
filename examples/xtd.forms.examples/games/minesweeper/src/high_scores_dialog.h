#pragma once
#include <xtd/xtd>

namespace minesweeper {
  class high_scores_dialog : public xtd::forms::form {
  public:
    high_scores_dialog();
    
  private:
    void read_and_update_settings();
    
    xtd::forms::label title_;
    xtd::forms::label beginner_level_label_;
    xtd::forms::label intermediate_level_label_;
    xtd::forms::label expert_level_label_;
    xtd::forms::label beginner_score_label_;
    xtd::forms::label intermediate_score_label_;
    xtd::forms::label expert_score_label_;
    xtd::forms::label beginner_name_label_;
    xtd::forms::label intermediate_name_label_;
    xtd::forms::label expert_name_label_;
    xtd::forms::button reset_scores_button_;
    xtd::forms::button ok_button_;
  };
}
