#include "cell.h"

using namespace minesweeper;

bool cell::has_mine() const {
  return has_mine_;
}

void cell::has_mine(bool value) {
  has_mine_ = value;
}

bool cell::has_neighbors() const {
  return neighbors_;
}

int cell::height() {
  return size_.height();
}

int cell::neighbors() const {
  return neighbors_;
}

void cell::neighbors(int value) {
  neighbors_ = value;
}

xtd::drawing::size cell::size() {
  return size_;
}

cell_state cell::state() const {
  return state_;
}

void cell::state(cell_state value) {
  state_ = value;
}

int cell::width() {
  return size_.width();
}

void cell::clear() {
  has_mine_ = false;
  neighbors_ = 0;
  state_ = cell_state::unchecked;
}
