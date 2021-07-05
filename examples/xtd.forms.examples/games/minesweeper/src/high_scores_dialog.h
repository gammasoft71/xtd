#pragma once
#include <xtd/xtd>

/// @brief The namespace minesweeper contains all classes and enums needed for the game.
namespace minesweeper {
  /// @brief Represent high scores dialog that display high scores dialog.
  class high_scores_dialog final : public xtd::forms::form {
  public:
    /// @brief Initialize a new instance of minesweeper::high_scores_dialog class.
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
