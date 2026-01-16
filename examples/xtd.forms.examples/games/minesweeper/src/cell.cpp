#include "cell.hpp"

using namespace minesweeper;

auto cell::contains_mine() const noexcept -> bool {
  return has_mine_;
}

auto cell::has_mine(bool value) noexcept -> void {
  has_mine_ = value;
}

auto cell::has_neighbouring_mines() const noexcept -> bool {
  return number_of_neighboring_mines_;
}

auto cell::height() noexcept -> int{
  return size_.height;
}

auto cell::number_of_neighbouring_mines() const noexcept -> int{
  return number_of_neighboring_mines_;
}

auto cell::neighbors(int value) noexcept -> void {
  number_of_neighboring_mines_ = value;
}

auto cell::size() noexcept -> drawing::size {
  return size_;
}

auto cell::state() const noexcept -> cell_state {
  return state_;
}

auto cell::state(cell_state value) noexcept -> void {
  state_ = value;
}

auto cell::width() noexcept -> int{
  return size_.width;
}

auto cell::clear() noexcept -> void {
  has_mine_ = false;
  number_of_neighboring_mines_ = 0;
  state_ = cell_state::unchecked;
}
