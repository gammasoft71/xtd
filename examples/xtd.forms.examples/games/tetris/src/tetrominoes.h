#pragma once
#include <xtd/xtd>

namespace tetris {
  enum class tetrominoes {
    no_shape,
    z_shape,
    s_shape,
    line_shape,
    t_shape,
    square_shape,
    l_shape,
    mirrored_l_shape
  };
}

template<> struct xtd::enum_register<tetris::tetrominoes> {
  explicit operator auto() const noexcept {return xtd::enum_collection<tetris::tetrominoes> {{tetris::tetrominoes::no_shape, "no_shape"}, {tetris::tetrominoes::z_shape, "z_shape"}, {tetris::tetrominoes::s_shape, "s_shape"}, {tetris::tetrominoes::line_shape, "line_shape"}, {tetris::tetrominoes::t_shape, "t_shape"}, {tetris::tetrominoes::square_shape, "square_shape"}, {tetris::tetrominoes::l_shape, "l_shape"}, {tetris::tetrominoes::mirrored_l_shape, "mirrored_l_shape"}};}
};
