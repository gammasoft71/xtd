#pragma once
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/label>

/// @brief The namespace minesweeper contains all classes and enums needed for the game.
namespace minesweeper {
  /// @brief Represent high scores dialog that display high scores dialog.
  class high_scores_dialog final : public form {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Initialize a new instance of minesweeper::high_scores_dialog class.
    high_scores_dialog();
    /// @}
    
  private:
    void read_and_update_settings();
    
    label title_;
    label beginner_level_label_;
    label intermediate_level_label_;
    label expert_level_label_;
    label beginner_score_label_;
    label intermediate_score_label_;
    label expert_score_label_;
    label beginner_name_label_;
    label intermediate_name_label_;
    label expert_name_label_;
    button reset_scores_button_;
    button ok_button_;
  };
}
