
#pragma once
#include <xtd/event_args.h>
#include "cell.h"

namespace game_of_life {
  class cell_event_args : public xtd::event_args {
  public:
    cell_event_args(const game_of_life::cell& cell, int x, int y) : cell_(&cell), x_(x), y_(y) {}

    const game_of_life::cell& cell() const {return *cell_;}
    int x() const {return x_;}
    int y() const {return y_;}

  private:
    const game_of_life::cell* cell_ = nullptr;
    int x_ = 0;
    int y_ = 0;
  };
}
