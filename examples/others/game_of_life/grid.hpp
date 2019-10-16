#pragma once
#include <vector>
#include <xtd/event.hpp>
#include "state_event_handler.hpp"

namespace game_of_life {
  using cell_row_collection = std::vector<cell>;
  using cell_collection = std::vector<cell_row_collection>;
  
  class grid {
  public:
    static constexpr int columns = 500; //5000;
    static constexpr int rows = 500; //5000;

    grid() = default;

    const cell_collection& cells() const {return cells_;}
    cell_collection& cells() {return cells_;}

    void clear() {cells_ = {columns, cell_row_collection {rows}};}

    void evolve() {
      cell_collection current_cells = cells_;

      for (int y = 0; y < columns; y++) {
        for (int x = 0; x < rows; x++) {
          int neighbors = 0;

          if ((x - 1) >= 0 && current_cells[x - 1][y] == cell::alive)
            neighbors++;
          if ((x + 1) < rows && current_cells[x + 1][y] == cell::alive)
            neighbors++;

          if ((y - 1) >= 0) {
            if ((x - 1) >= 0 && current_cells[x - 1][y - 1] == cell::alive)
              neighbors++;
            if (current_cells[x][y - 1] == cell::alive)
              neighbors++;
            if ((x + 1) < rows && current_cells[x + 1][y - 1] == cell::alive)
              neighbors++;
          }

          if ((y + 1) < columns) {
            if ((x - 1) >= 0 && current_cells[x - 1][y + 1] == cell::alive)
              neighbors++;
            if (current_cells[x][y + 1] == cell::alive)
              neighbors++;
            if ((x + 1) < rows && current_cells[x + 1][y + 1] == cell::alive)
              neighbors++;
          }

          if (current_cells[x][y] == cell::alive && (neighbors <= 1 || neighbors >= 4)) {
            cells_[x][y] = cell::dead;
            on_status_changed(state_event_args(cells_[x][y], x, y));
          } else if (current_cells[x][y] == cell::alive && (neighbors == 2 || neighbors == 3)) {
            cells_[x][y] = cell::alive;
            on_status_changed(state_event_args(cells_[x][y], x, y));
          } else if (current_cells[x][y] == cell::dead && neighbors == 3) {
            cells_[x][y] = cell::alive;
            on_status_changed(state_event_args(cells_[x][y], x, y));
          }
        }
      }
    }

    xtd::event<grid, state_event_handler<grid>> status_changed;

  private:
    void on_status_changed(const state_event_args& e) {status_changed(*this, e);}

    cell_collection cells_{columns, cell_row_collection {rows}};
  };
}
