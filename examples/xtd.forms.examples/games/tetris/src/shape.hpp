#pragma once
#include "tetrominoes.hpp"
#include <xtd/collections/generic/key_value_pair>
#include <array>

namespace tetris {
  class shape final : public xtd::object {
  public:
    shape() = default;
    explicit shape(tetris::tetrominoes tetrominoes);

    int max_x() const noexcept;
    int max_y() const noexcept;
    int min_x() const noexcept;
    int min_y() const noexcept;
    tetris::tetrominoes tetrominoes() const noexcept;
    int x(int index) const;
    int y(int index) const;
    
    static shape generate() noexcept;
    shape rotate_left() const noexcept;
    shape rotate_right() const noexcept;
    
  private:
    void x(int index, int x);
    void y(int index, int y);

    inline static constexpr int coords_size = 4;
    std::array<xtd::collections::generic::key_value_pair<int, int>, coords_size> coords_;
    tetris::tetrominoes tetrominoes_ = tetris::tetrominoes::no_shape;
  };
}
