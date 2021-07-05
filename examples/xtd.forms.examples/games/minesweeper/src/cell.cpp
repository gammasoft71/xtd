#include "cell.h"

using namespace minesweeper;

bool cell::has_mine() const noexcept {
  return has_mine_;
}

void cell::has_mine(bool value) noexcept {
  has_mine_ = value;
}

bool cell::has_neighbors() const noexcept {
  return neighbors_;
}

int cell::height() noexcept {
  return size_.height();
}

int cell::neighbors() const noexcept {
  return neighbors_;
}

void cell::neighbors(int value) noexcept {
  neighbors_ = value;
}

xtd::drawing::size cell::size() noexcept {
  return size_;
}

cell_state cell::state() const noexcept {
  return state_;
}

void cell::state(cell_state value) noexcept {
  state_ = value;
}

int cell::width() noexcept {
  return size_.width();
}

void cell::clear() noexcept {
  has_mine_ = false;
  neighbors_ = 0;
  state_ = cell_state::unchecked;
}
