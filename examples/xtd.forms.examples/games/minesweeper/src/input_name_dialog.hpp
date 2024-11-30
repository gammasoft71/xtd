#pragma once
#include "level.hpp"
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/text_box>
#include <xtd/translator>

/// @brief The namespace minesweeper contains all classes and enums needed for the game.
namespace minesweeper {
  /// @brief Represent input name dialog that display input name dialog.
  class input_name_dialog final : public xtd::forms::form {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Initialize a new instance of minesweeper::input_name_dialog class.
    input_name_dialog();
    /// @}
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets the level for which the gammer name is entered.
    /// @return One of minesweeper::level values.
    minesweeper::level level() const noexcept;
    /// @brief Sets the level for which the gammer name is entered.
    /// @param level One of minesweeper::level values.
    void level(minesweeper::level level) noexcept;
    
    /// @brief Gets the gammer name.
    /// @return The gammer name.
    xtd::string gammer_name() const noexcept;
    /// @brief Sets the gammer name.
    /// @param gammer_name The gammer name.
    void gammer_name(const xtd::string& gammer_name) noexcept;
    /// @}
    
  private:
    xtd::string level_to_string() noexcept;
    
    xtd::forms::label message_label_;
    xtd::forms::text_box name_text_box_;
    xtd::forms::button ok_button_;
    minesweeper::level level_ = level::beginner;
    xtd::string gammer_name_ = xtd::translator::translate("Anonymous");
  };
}
