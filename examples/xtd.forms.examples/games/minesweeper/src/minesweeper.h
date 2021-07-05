#pragma once
#include "cell.h"
#include "level.h"
#include <xtd/xtd>

namespace minesweeper {
  class form_minesweeper : public xtd::forms::form {
    using column_cell = std::vector<cell>;
    using row_cell = std::vector<column_cell>;
    using grid_size = xtd::drawing::size;
    
  public:
    static void main();
    
    form_minesweeper();
    
  private:
    void change_level(level l);

    void new_game();
    
    void check_neighbors(const xtd::drawing::point& cell_location);
    
    int checked_cell(const xtd::drawing::point& cell_location);

    xtd::forms::main_menu create_main_menu();
    
    void draw_cell(xtd::forms::paint_event_args& e, int x, int y, minesweeper::cell cell);

    void draw_unchecked(xtd::forms::paint_event_args& e, int x, int y, minesweeper::cell cell);
    
    void draw_checked(xtd::forms::paint_event_args& e, int x, int y, minesweeper::cell cell);
    
    void draw_flag(xtd::forms::paint_event_args& e, int x, int y, minesweeper::cell cell);
    
    void draw_question(xtd::forms::paint_event_args& e, int x, int y, minesweeper::cell cell);
    
    void draw_mine(xtd::forms::paint_event_args& e, int x, int y, minesweeper::cell cell);
    
    void draw_exploded_mine(xtd::forms::paint_event_args& e, int x, int y, minesweeper::cell cell);
    
    void draw_error(xtd::forms::paint_event_args& e, int x, int y, minesweeper::cell cell);
    
    void draw_border_unchecked(xtd::forms::paint_event_args& e, int x, int y);
    
    void draw_border_checked(xtd::forms::paint_event_args& e, int x, int y);
    
    void on_game_panel_mouse_up(xtd::forms::control& sender, const xtd::forms::mouse_event_args& e);

    void on_game_panel_paint(xtd::forms::control& sender, xtd::forms::paint_event_args& e);

    void on_status_panel_paint(xtd::forms::control& sender, xtd::forms::paint_event_args& e);
    
    void on_status_panel_resize(xtd::forms::control& sender, const xtd::event_args& e);
    
    void on_stopwatch_tick();
    
    void show_about_dialog();
    
    void update_colors();

    xtd::forms::panel status_panel;
    xtd::forms::lcd_label mine_count_label;
    xtd::forms::lcd_label stopwatch_label;
    xtd::forms::button start_game;
    xtd::forms::panel game_panel;
    xtd::forms::timer stopwatch;
    grid_size grid_size_ {9, 9};
    int mine_count_;
    row_cell cells_;
    level level_ = level::beginner;
    bool game_over_ = false;
    int checked_cell_count_ = 0;
    int flagged_mine_count_ = 0;
    int stopwatch_count_ = 0;
  };
}
