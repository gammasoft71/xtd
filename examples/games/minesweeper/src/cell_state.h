#pragma once

namespace minesweeper {
  enum class cell_state {
    unchecked,
    checked,
    flag,
    question,
    mine,
    exploded_mine,
    error,
  };
}
