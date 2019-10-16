
#pragma once
#include <xtd/event_args.hpp>
#include "cell.hpp"

namespace game_of_life {
  class state_event_args : public xtd::event_args {
  public:
    state_event_args(const game_of_life::cell& cell, int x, int y) : cell_(&cell), x_(x), y_(y) {}

    const game_of_life::cell& cell() const {return *cell_;}
    int x() const {return x_;}
    int y() const {return y_;}

  private:
    const game_of_life::cell* cell_ = nullptr;
    int x_ = 0;
    int y_ = 0;
  };
}
