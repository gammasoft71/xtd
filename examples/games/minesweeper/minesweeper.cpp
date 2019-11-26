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

  enum class cell_state {
    unchecked,
    checked,
    flag,
    question,
    mine,
    exploded_mine,
  };

  class cell : public user_control {
  public:
    cell() {
      size_ = default_size();
      //border_style(forms::border_style::fixed_3d);
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

    void on_mouse_down(const mouse_event_args& e) override {
      mouse_button_left_pressed_ = (mouse_buttons() & forms::mouse_buttons::left) == forms::mouse_buttons::left;
      invalidate();
    }
    
    void on_mouse_enter(const event_args& e) override {
      mouse_button_left_pressed_ = (mouse_buttons() & forms::mouse_buttons::left) == forms::mouse_buttons::left;
      invalidate();
    }
    
    void on_mouse_leave(const event_args& e) override {
      mouse_button_left_pressed_ = false;
      invalidate();
    }

    void on_mouse_move(const mouse_event_args& e) override {
      mouse_button_left_pressed_ = (mouse_buttons() & forms::mouse_buttons::left) == forms::mouse_buttons::left;
    }

    void on_mouse_up(const mouse_event_args& e) override {
      user_control::on_mouse_down(e);
      if (e.button() == mouse_buttons::left) {
        mouse_button_left_pressed_ = false;
        if (state_ == cell_state::unchecked) {
         state_ = cell_state::checked;
          invalidate();
        }
      } else if (e.button() == mouse_buttons::right) {
        
      }
    }
    
    void on_paint(paint_event_args& e) override {
      static std::map<cell_state, delegate<void(paint_event_args&)>> draw_state {{cell_state::unchecked, {*this, &cell::do_draw_unchecked}}, {cell_state::checked, {*this, &cell::do_draw_checked}}, {cell_state::flag, {*this, &cell::do_draw_flag}}, {cell_state::question, {*this, &cell::do_draw_question}}, {cell_state::mine, {*this, &cell::do_draw_mine}}, {cell_state::exploded_mine, {*this, &cell::do_draw_exploded_mine}}};
      if (state_ == cell_state::unchecked && mouse_button_left_pressed_)
        draw_border_checked(e);
      else
        draw_state[state_](e);
      user_control::on_paint(e);
    }
    
  private:
    void do_draw_unchecked(paint_event_args& e) {
      draw_border_unchecked(e);
    }
    
    void do_draw_checked(paint_event_args& e) {
      draw_border_checked(e);
    }
    
    void do_draw_flag(paint_event_args& e) {
      draw_border_unchecked(e);
      
    }
    
    void do_draw_question(paint_event_args& e) {
      draw_border_unchecked(e);

    }
    
    void do_draw_mine(paint_event_args& e) {
      draw_border_checked(e);
    }
    
    void do_draw_exploded_mine(paint_event_args& e) {
      draw_border_checked(e);
    }

    void draw_border_unchecked(paint_event_args& e) {
      e.graphics().draw_line(pen(color::lighter(color::lighter(color::lighter(back_color())))), 0, 0, e.clip_rectangle().width(), 0);
      e.graphics().draw_line(pen(color::lighter(color::lighter(back_color()))), 0, 1, e.clip_rectangle().width(), 1);
      e.graphics().draw_line(pen(color::lighter(back_color())), 1, 2, e.clip_rectangle().width(), 2);
      e.graphics().draw_line(pen(color::lighter(color::lighter(color::lighter(back_color())))), 0, 0, 0, e.clip_rectangle().height());
      e.graphics().draw_line(pen(color::lighter(color::lighter(back_color()))), 1, 1, 1, e.clip_rectangle().height());
      e.graphics().draw_line(pen(color::lighter(back_color())), 2, 2, 2, e.clip_rectangle().height());
      e.graphics().draw_line(pen(color::darker(back_color())), 2, e.clip_rectangle().height() - 2, e.clip_rectangle().width(), e.clip_rectangle().height() - 3);
      e.graphics().draw_line(pen(color::darker(color::darker(back_color()))), 1, e.clip_rectangle().height() - 2, e.clip_rectangle().width(), e.clip_rectangle().height() - 2);
      e.graphics().draw_line(pen(color::darker(color::darker(color::darker(back_color())))), 0, e.clip_rectangle().height() - 1, e.clip_rectangle().width(), e.clip_rectangle().height() - 1);
      e.graphics().draw_line(pen(color::darker(back_color())), e.clip_rectangle().width() - 3, 2, e.clip_rectangle().width() - 3, e.clip_rectangle().height() - 3);
      e.graphics().draw_line(pen(color::darker(color::darker(back_color()))), e.clip_rectangle().width() - 2, 1, e.clip_rectangle().width() - 2, e.clip_rectangle().height() - 2);
      e.graphics().draw_line(pen(color::darker(color::darker(color::darker(back_color())))), e.clip_rectangle().width() - 1, 0, e.clip_rectangle().width() - 1, e.clip_rectangle().height() - 1);
    }
    
    void draw_border_checked(paint_event_args& e) {
      e.graphics().draw_line(pen(color::darker(back_color())), 0, 0, e.clip_rectangle().width(), 0);
      e.graphics().draw_line(pen(color::lighter(back_color())), 0, 1, e.clip_rectangle().width(), 1);
      e.graphics().draw_line(pen(color::darker(color::darker(back_color()))), 0, 0, 0, e.clip_rectangle().height());
      e.graphics().draw_line(pen(color::lighter(back_color())), 1, 1, 1, e.clip_rectangle().height());
      e.graphics().draw_line(pen(color::darker(back_color())), 0, e.clip_rectangle().height() - 1, e.clip_rectangle().width(), e.clip_rectangle().height() - 1);
      e.graphics().draw_line(pen(color::darker(color::darker(back_color()))), e.clip_rectangle().width() - 1, 0, e.clip_rectangle().width() - 1, e.clip_rectangle().height() - 1);
    }
    
    cell_state state_ = cell_state::unchecked;
    bool has_mine_ = false;
    int neighbors_ = 0;
    bool mouse_button_left_pressed_ = false;
  };

  class form_main : public form {
    using column_cell = std::vector<std::shared_ptr<cell>>;
    using row_cell = std::vector<column_cell>;
    using grid_size = drawing::size;
  public:
    form_main() {
      auto_size_mode(forms::auto_size_mode::grow_and_shrink);
      auto_size(true);
      status_panel.parent(*this);
      status_panel.height(40);
      game_panel.parent(*this);
      game_panel.auto_size(true);
      game_panel.top(40);
      new_game();
      status_panel.width(client_size().width());
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
          cells_[x][y]->parent(game_panel);
          cells_[x][y]->location({x * cells_[x][y]->size().width(), y * cells_[x][y]->size().height()});
        }
      }
    }
    
    panel status_panel;
    panel game_panel;
    grid_size grid_size_;
    int mine_count_;
    row_cell cells_;
    level level_ = minesweeper::level::beginer;
  };
}

int main() {
  xtd::forms::application::run(minesweeper::form_main());
}
