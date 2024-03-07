#pragma once
#include "level.h"
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/text_box>

/// @brief The namespace minesweeper contains all classes and enums needed for the game.
namespace minesweeper {
  /// @brief Represent custom field dialog that display custom field dialog.
  /// @remarks minesweeper::custom_field_dialog is used when user choose Custom from the Game menu.
  class custom_field_dialog final : public xtd::forms::form {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Initialize a new instance of minesweeper::custom_field_dialog class.
    custom_field_dialog();
    /// @}
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets the custom height for the game area.
    /// @return The height of game area.
    /// @remarks The value is between 8 and 24.
    int custom_heght() const noexcept;
    /// @brief Sets the custom height for the game area.
    /// @param value The height of game area.
    /// @remarks The value is between 8 and 24.
    void custom_height(int value) noexcept;
    
    /// @brief Gets the custom width for the game area.
    /// @return The width of game area.
    /// @remarks The value is between 8 and 30.
    int custom_width() const noexcept;
    /// @brief Sets the custom width for the game area.
    /// @param value The width of game area.
    /// @remarks The value is between 8 and 30.
    void custom_width(int value) noexcept;
    
    /// @brief Gets the custom mines number.
    /// @return The custom mines number.
    /// @remarks The value is between 10 and 667.
    int custom_mines() const noexcept;
    /// @brief Sets the custom mines number.
    /// @param value The custom mines number.
    /// @remarks The value is between 10 and 667.
    void custom_mines(int value) noexcept;
    /// @}
    
  private:
    void on_text_box_key_press(object& sender, xtd::forms::key_press_event_args& e);

    static constexpr const int minimum_height_ = 8;
    static constexpr const int maximum_height_ = 24;
    static constexpr const int minimum_width_ = 8;
    static constexpr const int maximum_width_ = 30;
    static constexpr const int minimum_mines_ = 10;
    static constexpr const int maximum_mines_ = 667;

    xtd::forms::label message_label_;
    xtd::forms::label custom_height_label_;
    xtd::forms::label custom_width_label_;
    xtd::forms::label custom_mines_label_;
    xtd::forms::text_box custom_height_text_box_;
    xtd::forms::text_box custom_width_text_box_;
    xtd::forms::text_box custom_mines_text_box_;
    xtd::forms::button ok_button_;
    int custom_height_ = minimum_height_;
    int custom_width_ = minimum_width_;
    int custom_mines_ = minimum_mines_;
  };
}
