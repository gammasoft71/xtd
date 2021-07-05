#pragma once
#include "cell_state.h"
#include <xtd/xtd>

/// @brief The namespace minesweeper contains all classes and enums needed for the game.
namespace minesweeper {
  /// @brief Represent one cell the game.
  /// @remarks the game contains 81 (9 x 9) cells and 10 mines for beginner level.
  /// @remarks the game contains 256 (16 x 16) cells and 40 mines for intermediate level.
  /// @remarks the game contains 480 (30 x 16 cells and 99 mines for expert and custom level.
  class cell final {
  public:
    /// @brief Gets a value indicate if cell contains mine.
    /// @return true if cell contains mine; otherwhise false.
    bool has_mine() const noexcept;
    /// @brief Sets a value indicate if cell contains mine.
    /// @param value true if cell contains mine; otherwhise false.
    void has_mine(bool value) noexcept;
    
    /// @brief Gets a value indicate if cell has neighbors.
    /// @return true if cell has neighbors; otherwhise false.
    bool has_neighbors() const noexcept;
    
    /// @brief Gets the height of cell in pixels.
    /// @return The height of cell.
    /// @remarks The values is 30.
    static int height() noexcept;
    
    /// @brief Gets the number of neighbors of the cell.
    /// @return The number of cell's neighbors.
    /// @remarks The value is betwen 0 and 8.
    int neighbors() const noexcept;
    /// @brief Sets the number of neighbors of the cell.
    /// @param value The number neighbors of the cell.
    /// @remarks The value must be betwen 0 and 8.
    /// @remarks The value is provided by minesweeper::minesweeper_form and there is no check.
    void neighbors(int value) noexcept;
    
    /// @brief Gets the size of cell in pixels.
    /// @return The size of cell.
    /// @remarks The values is 30 x 30.
    static xtd::drawing::size size() noexcept;
    
    cell_state state() const noexcept;
    void state(cell_state value) noexcept;
    
    /// @brief Gets the width of cell in pixels.
    /// @return The width of cell.
    /// @remarks The values is 30.
    static int width() noexcept;
    
    /// @brief Clear all cell's values
    /// @remarks Clear as follow:
    /// | name      | value                 |
    /// |-----------|-----------------------|
    /// | has_mine  | false                 |
    /// | neighbors | 0                     |
    /// | state     | cell_state::unchecked |
    void clear() noexcept;
    
  private:
    bool has_mine_ = false;
    int neighbors_ = 0;
    cell_state state_ = cell_state::unchecked;
    inline static xtd::drawing::size size_ {30, 30};
  };
}
