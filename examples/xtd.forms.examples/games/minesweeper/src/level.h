#pragma once

/// @brief The namespace minesweeper contains all classes and enums needed for the game.
namespace minesweeper {
  /// @brief Represent the level for minesweeper game.
  /// @remarks the game contains 81 (9 x 9) cells and 10 mines for beginner level.
  /// @remarks the game contains 256 (16 x 16) cells and 40 mines for intermediate level.
  /// @remarks the game contains 480 (30 x 16 cells and 99 mines for expert and custom level.
  enum class level {
    /// @brief The beginner level.
    beginner,
    /// @brief The intermediate level.
    intermediate,
    /// @brief The expert level.
    expert,
    /// @brief The custom level.
    custom,
  };
}
