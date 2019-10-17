#pragma once
#include <vector>
#include <xtd/event.hpp>
#include "state_event_handler.hpp"

namespace game_of_life {
  using cell_row_collection = std::vector<cell>;
  using cell_collection = std::vector<cell_row_collection>;
  
  class grid {
  public:
    static constexpr int columns = 700; // 5200
    static constexpr int rows = 700; // 2900

    grid() = default;

    const cell_collection& cells() const {return cells_;}
    cell_collection& cells() {return cells_;}

    void clear() {cells_ = {columns, cell_row_collection {rows}};}
    
    void next() {
      struct updated_cell {
        int x = 0;
        int y = 0;
        cell state = cell::dead;
      };
      std::vector<updated_cell> updated_cells;
      
      for (int y = 0; y < columns; y++) {
        for (int x = 0; x < rows; x++) {
          int neighbors = get_neighbors(x, y);
          if (cells_[y][x] == cell::alive && (neighbors <= 1 || neighbors >= 4)) {
            updated_cells.push_back({x, y, cell::dead});
          } else if (cells_[y][x] == cell::dead && neighbors == 3) {
            updated_cells.push_back({x, y, cell::alive});
          }
        }
      }
      
      for(auto cell : updated_cells) {
        cells_[cell.y][cell.x] = cell.state;
        on_status_changed(state_event_args(cells_[cell.y][cell.x], cell.x, cell.y));
      }
    }
    
    int get_neighbors(int x, int y) const {
      int neighbors = 0;

      if ((x - 1) >= 0 && cells_[y][x - 1] == cell::alive)
        neighbors++;
      if ((x + 1) < rows && cells_[y][x + 1] == cell::alive)
        neighbors++;

      if ((y - 1) >= 0) {
        if ((x - 1) >= 0 && cells_[y - 1][x - 1] == cell::alive)
          neighbors++;
        if (cells_[y - 1][x] == cell::alive)
          neighbors++;
        if ((x + 1) < rows && cells_[y - 1][x + 1] == cell::alive)
          neighbors++;
      }

      if ((y + 1) < columns) {
        if ((x - 1) >= 0 && cells_[y + 1][x - 1] == cell::alive)
          neighbors++;
        if (cells_[y + 1][x] == cell::alive)
          neighbors++;
        if ((x + 1) < rows && cells_[y + 1][x + 1] == cell::alive)
          neighbors++;
      }
      return neighbors;
    }

    xtd::event<grid, state_event_handler<grid>> status_changed;

  private:
    void on_status_changed(const state_event_args& e) {status_changed(*this, e);}

    cell_collection cells_{columns, cell_row_collection {rows}};
  };
}
