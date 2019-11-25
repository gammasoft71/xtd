#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace minesweeper {
  enum class level {
    beginer,
    intermediate,
    expert,
    //custom,
  };

  class cell : public user_control {
  public:
    cell() {
      size_ = default_size();
      border_style(forms::border_style::fixed_3d);
    };
    
    bool has_mine() const {return has_mine_;}
    void has_mine(bool value) {
      if (has_mine_ != value) {
        has_mine_ = value;
      }
    }
    
    int neighbors() const {return neighbors_;}
    void neighbors(int value) {
      if (neighbors_ != value) {
        neighbors_ = value;
      }
    }
    
  protected:
    drawing::size default_size() const override {return {30, 30};}
    
  private:
    bool has_mine_ = false;
    int neighbors_ = 0;
  };

  class form_main : public form {
    using column_cell = std::vector<std::shared_ptr<cell>>;
    using row_cell = std::vector<column_cell>;
    using grid_size = drawing::size;
  public:
    form_main() {
      new_game();
      auto_size_mode(forms::auto_size_mode::grow_and_shrink);
      auto_size(true);
    }
    
  private:
    void new_game() {
      cells_.clear();
      grid_size_ = std::map<level, grid_size> {{level::beginer, {9, 9}}, {level::intermediate, {16, 16}}, {level::expert, {30, 16}}} [level_];
      mine_count_ = std::map<level, int> {{level::beginer, 10}, {level::intermediate, 40}, {level::expert, 99}} [level_];
    
      cells_ = row_cell(grid_size_.width(), column_cell(grid_size_.height()));
      for (int y = 0; y < grid_size_.height(); y++) {
        for (int x = 0; x < grid_size_.width(); x++) {
          cells_[x][y] = std::make_shared<cell>();
          cells_[x][y]->parent(*this);
          cells_[x][y]->location({x * cells_[x][y]->size().width(), y * cells_[x][y]->size().height()});
        }
      }
    }
    
    grid_size grid_size_;
    int mine_count_;
    row_cell cells_;
    level level_ = minesweeper::level::beginer;
  };
}

int main() {
  xtd::forms::application::run(minesweeper::form_main());
}
