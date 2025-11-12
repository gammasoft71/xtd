#include "shape.hpp"
#include <xtd/math>
#include <algorithm>

using namespace tetris;

shape::shape(tetris::tetrominoes tetrominoes) {
  static const auto coords_values = dictionary<tetris::tetrominoes, fixed_array<key_value_pair<int, int>, 4>> {
    {tetris::tetrominoes::no_shape, {key_value_pair<>::create(0, 0), key_value_pair<>::create(0, 0), key_value_pair<>::create(0, 0), key_value_pair<>::create(0, 0)}},
    {tetris::tetrominoes::z_shape, {key_value_pair<>::create(0, -1), key_value_pair<>::create(0, 0), key_value_pair<>::create(-1, 0), key_value_pair<>::create(-1, 1)}},
    {tetris::tetrominoes::s_shape, {key_value_pair<>::create(0, -1), key_value_pair<>::create(0, 0), key_value_pair<>::create(1, 0), key_value_pair<>::create(1, 1)}},
    {tetris::tetrominoes::line_shape, {key_value_pair<>::create(0, -1), key_value_pair<>::create(0, 0), key_value_pair<>::create(0, 1), key_value_pair<>::create(0, 2)}},
    {tetris::tetrominoes::t_shape, {key_value_pair<>::create(-1, 0), key_value_pair<>::create(0, 0), key_value_pair<>::create(1, 0), key_value_pair<>::create(0, 1)}},
    {tetris::tetrominoes::square_shape, {key_value_pair<>::create(0, 0), key_value_pair<>::create(1, 0), key_value_pair<>::create(0, 1), key_value_pair<>::create(1, 1)}},
    {tetris::tetrominoes::l_shape, {key_value_pair<>::create(-1, -1), key_value_pair<>::create(0, -1), key_value_pair<>::create(0, 0), key_value_pair<>::create(0, 1)}},
    {tetris::tetrominoes::mirrored_l_shape, {key_value_pair<>::create(1, -1), key_value_pair<>::create(0, -1), key_value_pair<>::create(0, 0), key_value_pair<>::create(0, 1)}},
  };
  coords_ = coords_values[tetrominoes];
  tetrominoes_ = tetrominoes;
}

tetris::tetrominoes shape::tetrominoes() const noexcept {
  return tetrominoes_;
}

int shape::max_x() const noexcept {
  auto result = coords_[0].first;
  for (auto i = 0; i < 4; ++i)
    result = math::max(result, coords_[i].first);
  return result;
}

int shape::max_y() const noexcept {
  auto result = coords_[0].second;
  for (auto i = 0; i < 4; ++i)
    result = math::max(result, coords_[i].second);
  return result;
}

int shape::min_x() const noexcept {
  auto result = coords_[0].first;
  for (auto i = 0; i < 4; ++i)
    result = math::min(result, coords_[i].first);
  return result;
}

int shape::min_y() const noexcept {
  auto result = coords_[0].second;
  for (auto i = 0; i < 4; ++i)
    result = math::min(result, coords_[i].second);
  return result;
}

int shape::x(int index) const {
  if (index < 0 || index >= coords_size) throw argument_out_of_range_exception {};
  return coords_[index].first;
}

int shape::y(int index) const {
  if (index < 0 || index >= coords_size) throw argument_out_of_range_exception {};
  return coords_[index].second;
}

shape shape::generate() noexcept {
  static auto rnd = xtd::random {};
  static auto [min, max] = std::ranges::minmax(enum_object<>::get_values_as_int32<tetris::tetrominoes>().items());
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
  coords_[index] = key_value_pair<>::create(x, coords_[index].second);
}

void shape::y(int index, int y) {
      coords_[index] = key_value_pair<>::create(coords_[index].first, y);
}
