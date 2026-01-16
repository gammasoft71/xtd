#pragma once
#include <xtd/enum_class>

/// @brief The namespace minesweeper contains all classes and enums needed for the game.
namespace minesweeper {
  /// @brief Represent the state for minesweeper::cell.
  enum class cell_state {
    /// @brief The cell is unckecked.
    unchecked,
    /// @brief The cell is ckecked with neighbors or not.
    checked,
    /// @biref The cell is marked with flag.
    flag,
    /// @biref The cell is marked with question mark.
    question,
    /// @biref The cell has mine with not flag and not exploded.
    mine,
    /// @biref The cell has exploded mine. This state is set only on the end of game.
    exploded_mine,
    /// @biref The cell has marked with flags but has not mine. This state is set only on the end of game.
    error,
  };
}

/// @cond
template<> struct xtd::enum_register<minesweeper::cell_state> {
  explicit operator auto() const noexcept {return enum_collection<minesweeper::cell_state> {{minesweeper::cell_state::unchecked, "unchecked"}, {minesweeper::cell_state::checked, "checked"}, {minesweeper::cell_state::flag, "flag"}, {minesweeper::cell_state::question, "question"}, {minesweeper::cell_state::mine, "mine"}, {minesweeper::cell_state::exploded_mine, "exploded_mine"}, {minesweeper::cell_state::error, "error"}};}
};
/// @endcond
