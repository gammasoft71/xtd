#pragma once
#include "cell_state.h"
#include <xtd/xtd>

namespace minesweeper {
  class cell {
  public:
    bool has_mine() const;
    void has_mine(bool value);
    
    bool has_neighbors() const;
    
    static int height();
    
    int neighbors() const;
    void neighbors(int value);
    
    static xtd::drawing::size size();
    
    cell_state state() const;
    void state(cell_state value);
    
    static int width();
    
    void clear();
    
  private:
    bool has_mine_ = false;
    int neighbors_ = 0;
    cell_state state_ = cell_state::unchecked;
    inline static xtd::drawing::size size_ {30, 30};
  };
}
