#pragma once
#include "cell_state.hpp"
#include <xtd/drawing/size>
#include <xtd/iequatable>

/// @brief The namespace minesweeper contains all classes and enums needed for the game.
namespace minesweeper {
  /// @brief Represent one cell the game.
  /// @remarks the game contains 81 (9 x 9) cells and 10 mines for beginner level.
  /// @remarks the game contains 256 (16 x 16) cells and 40 mines for intermediate level.
  /// @remarks the game contains 480 (30 x 16 cells and 99 mines for expert and custom level.
  class cell final : public iequatable<cell> {
  public:
    /// @name Public Properties
    
    /// @{
    /// @brief Gets a value indicate if cell contains mine.
    /// @return true if cell contains mine; otherwhise false.
    [[nodiscard]] auto contains_mine() const noexcept -> bool;
    /// @brief Sets a value indicate if cell contains mine.
    /// @param value true if cell contains mine; otherwhise false.
    void has_mine(bool value) noexcept;
    
    /// @brief Gets a value indicate if cell has neighboring mines.
    /// @return true if cell has neighbors; otherwhise false.
    [[nodiscard]] bool has_neighbouring_mines() const noexcept;
    
    /// @brief Gets the height of cell in pixels.
    /// @return The height of cell.
    /// @remarks The values is 30.
    [[nodiscard]] static auto height() noexcept -> int;
    
    /// @brief Gets the number of neighboring mines of the cell.
    /// @return The number of cell's neighbors.
    /// @remarks The value is betwen 0 and 8.
    [[nodiscard]] auto number_of_neighbouring_mines() const noexcept -> int;
    /// @brief Sets the number of neighboring mines of the cell.
    /// @param value The number neighbors of the cell.
    /// @remarks The value must be betwen 0 and 8.
    /// @remarks The value is provided by minesweeper::minesweeper_form and there is no check.
    auto neighbors(int value) noexcept -> void;
    
    /// @brief Gets the size of cell in pixels.
    /// @return The size of cell.
    /// @remarks The values is 30 x 30.
    [[nodiscard]] static auto size() noexcept -> drawing::size;
    
    /// @brief Gets the cell state.
    /// @return One of minesweeper::cell_state value.
    [[nodiscard]] auto state() const noexcept -> cell_state;
    /// @brief Sets the cell state.
    /// @param value One of minesweeper::cell_state value.
    auto state(cell_state value) noexcept -> void;
    
    /// @brief Gets the width of cell in pixels.
    /// @return The width of cell.
    /// @remarks The values is 30.
    [[nodiscard]] static auto width() noexcept -> int;
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Clear all cell's values
    /// @remarks Clear as follow:
    /// | name                         | value                 |
    /// | ---------------------------- | --------------------- |
    /// | contains_mine                | false                 |
    /// | number_of_neighbouring_mines | 0                     |
    /// | state                        | cell_state::unchecked |
    void clear() noexcept;
    
    [[nodiscard]] bool equals(const cell& rhs) const noexcept override {return has_mine_ == rhs.has_mine_ && number_of_neighboring_mines_ == rhs.number_of_neighboring_mines_ && state_ == rhs.state_ && size_ ==rhs.size_;}
    /// @}

  private:
    bool has_mine_ = false;
    int number_of_neighboring_mines_ = 0;
    cell_state state_ = cell_state::unchecked;
    inline static drawing::size size_ {30, 30};
  };
}
