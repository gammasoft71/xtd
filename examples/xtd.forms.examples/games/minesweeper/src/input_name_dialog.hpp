#pragma once
#include "level.hpp"
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/text_box>
#include <xtd/globalization/translator>

/// @brief The namespace minesweeper contains all classes and enums needed for the game.
namespace minesweeper {
  /// @brief Represent input name dialog that display input name dialog.
  class input_name_dialog final : public form {
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
    [[nodiscard]] auto level() const noexcept -> minesweeper::level;
    /// @brief Sets the level for which the gammer name is entered.
    /// @param level One of minesweeper::level values.
    auto level(minesweeper::level level) noexcept -> void;
    
    /// @brief Gets the gammer name.
    /// @return The gammer name.
    [[nodiscard]] auto gammer_name() const noexcept -> string;
    /// @brief Sets the gammer name.
    /// @param gammer_name The gammer name.
    auto gammer_name(const string& gammer_name) noexcept -> void;
    /// @}
    
  private:
    [[nodiscard]] auto level_to_string() noexcept -> string;
    
    label message_label_;
    text_box name_text_box_;
    button ok_button_;
    minesweeper::level level_ = level::beginner;
    string gammer_name_ = "Anonymous"_t;
  };
}
