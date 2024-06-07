#include "shape.h"
#include <algorithm>

using namespace std;
using namespace tetris;
using namespace xtd;

shape::shape(tetris::tetrominoes tetrominoes) {
  static const auto coords_map = map<tetris::tetrominoes, array<pair<int, int>, 4>> {
    {tetris::tetrominoes::no_shape, {make_pair(0, 0), make_pair(0, 0), make_pair(0, 0), make_pair(0, 0)}},
    {tetris::tetrominoes::z_shape, {make_pair(0, -1), make_pair(0, 0), make_pair(-1, 0), make_pair(-1, 1)}},
    {tetris::tetrominoes::s_shape, {make_pair(0, -1), make_pair(0, 0), make_pair(1, 0), make_pair(1, 1)}},
    {tetris::tetrominoes::line_shape, {make_pair(0, -1), make_pair(0, 0), make_pair(0, 1), make_pair(0, 2)}},
    {tetris::tetrominoes::t_shape, {make_pair(-1, 0), make_pair(0, 0), make_pair(1, 0), make_pair(0, 1)}},
    {tetris::tetrominoes::square_shape, {make_pair(0, 0), make_pair(1, 0), make_pair(0, 1), make_pair(1, 1)}},
    {tetris::tetrominoes::l_shape, {make_pair(-1, -1), make_pair(0, -1), make_pair(0, 0), make_pair(0, 1)}},
    {tetris::tetrominoes::mirrored_l_shape, {make_pair(1, -1), make_pair(0, -1), make_pair(0, 0), make_pair(0, 1)}},
  };
  coords_ = coords_map.at(tetrominoes);
  tetrominoes_ = tetrominoes;
}

tetris::tetrominoes shape::tetrominoes() const noexcept {
  return tetrominoes_;
}

int shape::max_x() const noexcept {
  auto result = coords_[0].first;
  for (auto i = 0; i < 4; ++i)
    result = max(result, coords_.at(i).first);
  return result;
}

int shape::max_y() const noexcept {
  auto result = coords_[0].second;
  for (auto i = 0; i < 4; ++i)
    result = max(result, coords_.at(i).second);
  return result;
}

int shape::min_x() const noexcept {
  auto result = coords_[0].first;
  for (auto i = 0; i < 4; ++i)
    result = min(result, coords_.at(i).first);
  return result;
}

int shape::min_y() const noexcept {
  auto result = coords_[0].second;
  for (auto i = 0; i < 4; ++i)
    result = min(result, coords_.at(i).second);
  return result;
}

int shape::x(int index) const {
  if (index < 0 || index >= coords_size) throw argument_out_of_range_exception {csf_};
  return coords_.at(index).first;
}

int shape::y(int index) const {
  if (index < 0 || index >= coords_size) throw argument_out_of_range_exception {csf_};
  return coords_.at(index).second;
}

shape shape::generate() noexcept {
  static auto rnd = xtd::random {};
  static auto [min, max] = ranges::minmax(enum_object<>::get_values_as_int32<tetris::tetrominoes>());
  return shape {as<tetris::tetrominoes>(rnd.next(min + 1, max + 1))};
}

shape shape::rotate_left() const noexcept {
  if (tetrominoes_ == tetris::tetrominoes::square_shape) return *this;
  auto result = shape {tetrominoes_};
  for (auto i = 0; i < 4; ++i) {
    result.x(i, y(i));
    result.y(i, -x(i));
  }
  return result;
}

shape shape::rotate_right() const noexcept {
  if (tetrominoes_ == tetris::tetrominoes::square_shape) return *this;
  auto result = shape {tetrominoes_};
  for (auto i = 0; i < 4; ++i) {
    result.x(i, -x(i));
    result.y(i, y(i));
  }
  return result;
}

void shape::x(int index, int x) {
  coords_.at(index) = std::make_pair(x, coords_.at(index).second);
}

void shape::y(int index, int y) {
      coords_.at(index) = std::make_pair(coords_.at(index).first, y);
}
