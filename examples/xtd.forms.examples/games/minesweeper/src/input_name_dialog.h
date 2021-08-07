#pragma once
#include "level.h"
#include <xtd/xtd>

/// @brief The namespace minesweeper contains all classes and enums needed for the game.
namespace minesweeper {
  /// @brief Represent input name dialog that display input name dialog.
  class input_name_dialog final : public xtd::forms::form {
  public:
    /// @brief Initialize a new instance of minesweeper::input_name_dialog class.
    input_name_dialog();
    
    /// @brief Gets the level for which the gammer name is entered.
    /// @return One of minesweeper::level values.
    minesweeper::level level() const noexcept;
    /// @brief Sets the level for which the gammer name is entered.
    /// @param level One of minesweeper::level values.
    void level(minesweeper::level level) noexcept;

    /// @brief Gets the gammer name.
    /// @return The gammer name.
    xtd::ustring gammer_name() const noexcept;
    /// @brief Sets the gammer name.
    /// @param gammer_name The gammer name.
    void gammer_name(const xtd::ustring& gammer_name) noexcept;
    
  private:
    xtd::ustring level_to_string() noexcept;
    
    xtd::forms::label message_label_;
    xtd::forms::text_box name_text_box_;
    xtd::forms::button ok_button_;
    minesweeper::level level_ = level::beginner;
    xtd::ustring gammer_name_ = xtd::translator::translate("Anonymous");
  };
}
