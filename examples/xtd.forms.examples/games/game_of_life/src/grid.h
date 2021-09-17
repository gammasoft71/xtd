#pragma once
#include <vector>
#include <xtd/event.h>
#include <xtd/object.h>
#include "cell.h"

namespace game_of_life {
  using cell_row_collection = std::vector<cell>;
  using cell_collection = std::vector<cell_row_collection>;
  
  class grid : public xtd::object {
  public:
    static constexpr int columns = 1000; //5200;
    static constexpr int rows = 800; //4100;

    grid() = default;

    const cell_collection& cells() const {return cells_;}
    cell_collection& cells() {return cells_;}

    void clear() {cells_ = {columns, cell_row_collection {rows}};}
    
    void next() {
      struct updated_cell {
        int x = 0;
        int y = 0;
        cell state = cell::empty;
      };
      std::vector<updated_cell> updated_cells;
      
      for (auto y = 0; y < columns; y++) {
        for (auto x = 0; x < rows; x++) {
          int neighbors = get_neighbors(x, y);
          if (cells_[y][x] == cell::populated && (neighbors <= 1 || neighbors >= 4)) {
            updated_cells.push_back({x, y, cell::empty});
          } else if (cells_[y][x] == cell::empty && neighbors == 3) {
            updated_cells.push_back({x, y, cell::populated});
          }
        }
      }
      
      for(auto cell : updated_cells)
        cells_[cell.y][cell.x] = cell.state;
      if (!updated_cells.empty())  on_cells_updated(xtd::event_args::empty);
    }
    
    int get_neighbors(int x, int y) const {
      auto neighbors = 0;

      if ((x - 1) >= 0 && cells_[y][x - 1] == cell::populated)
        neighbors++;
      if ((x + 1) < rows && cells_[y][x + 1] == cell::populated)
        neighbors++;

      if ((y - 1) >= 0) {
        if ((x - 1) >= 0 && cells_[y - 1][x - 1] == cell::populated)
          neighbors++;
        if (cells_[y - 1][x] == cell::populated)
          neighbors++;
        if ((x + 1) < rows && cells_[y - 1][x + 1] == cell::populated)
          neighbors++;
      }

      if ((y + 1) < columns) {
        if ((x - 1) >= 0 && cells_[y + 1][x - 1] == cell::populated)
          neighbors++;
        if (cells_[y + 1][x] == cell::populated)
          neighbors++;
        if ((x + 1) < rows && cells_[y + 1][x + 1] == cell::populated)
          neighbors++;
      }
      return neighbors;
    }

    xtd::event<grid, xtd::event_handler> cells_updated;

  private:
    void on_cells_updated(const xtd::event_args& e) {cells_updated(*this, e);}

    cell_collection cells_{columns, cell_row_collection {rows}};
  };
}
