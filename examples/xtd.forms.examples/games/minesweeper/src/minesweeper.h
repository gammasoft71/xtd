#pragma once
#include "cell.h"
#include "level.h"
#include <xtd/xtd>

/// @brief The namespace minesweeper contains all classes and enums needed for the game.
namespace minesweeper {
  /// @brief Represents the form that contains the games.
  /// @remarks The form is composed of a status panel that contains the game evolution; and game paen that contains the cells to sweep.
  /// @remarks The form contains to a main menu.
  /// @remarks the game contains 81 (9 x 9) cells and 10 mines for beginner level.
  /// @remarks the game contains 256 (16 x 16) cells and 40 mines for intermediate level.
  /// @remarks the game contains 480 (30 x 16 cells and 99 mines for expert and custom level.
  class minesweeper_form final : public xtd::forms::form {
    using column_cell = std::vector<cell>;
    using row_cell = std::vector<column_cell>;
    using grid_size = xtd::drawing::size;
    
  public:
    /// @brief The main entry point for the game.
    static void main();
    
    /// @brief Initialize a new instance of minesweeper::form_minesweeper form.
    minesweeper_form();
    
  private:
    void change_level(level l);

    void new_game();
    
    void check_neighbors(const xtd::drawing::point& cell_location);
    int checked_cell(const xtd::drawing::point& cell_location);

    xtd::forms::main_menu create_main_menu();
    
    void draw_cell(xtd::forms::paint_event_args& e, const xtd::drawing::rectangle& clip_rectangle, minesweeper::cell cell);
    void draw_unchecked(xtd::forms::paint_event_args& e, const xtd::drawing::rectangle& clip_rectangle, minesweeper::cell cell);
    void draw_checked(xtd::forms::paint_event_args& e, const xtd::drawing::rectangle& clip_rectangle, minesweeper::cell cell);
    void draw_flag(xtd::forms::paint_event_args& e, const xtd::drawing::rectangle& clip_rectangle, minesweeper::cell cell);
    void draw_question(xtd::forms::paint_event_args& e, const xtd::drawing::rectangle& clip_rectangle, minesweeper::cell cell);
    void draw_mine(xtd::forms::paint_event_args& e, const xtd::drawing::rectangle& clip_rectangle, minesweeper::cell cell);
    void draw_exploded_mine(xtd::forms::paint_event_args& e, const xtd::drawing::rectangle& clip_rectangle, minesweeper::cell cell);
    void draw_error(xtd::forms::paint_event_args& e, const xtd::drawing::rectangle& clip_rectangle, minesweeper::cell cell);
    void draw_border_unchecked(xtd::forms::paint_event_args& e, const xtd::drawing::rectangle& clip_rectangle);
    void draw_border_checked(xtd::forms::paint_event_args& e, const xtd::drawing::rectangle& clip_rectangle);

    void game_over();

    void mark_cell(int x, int y);

    void on_about_menuu_click(xtd::forms::component& sender, const xtd::event_args& e);
    void on_custom_menu_click(xtd::forms::component& sender, const xtd::event_args& e);
    void on_game_panel_mouse_up(xtd::forms::control& sender, const xtd::forms::mouse_event_args& e);
    void on_game_panel_paint(xtd::forms::control& sender, xtd::forms::paint_event_args& e);
    void on_status_panel_paint(xtd::forms::control& sender, xtd::forms::paint_event_args& e);
    void on_status_panel_resize(xtd::forms::control& sender, const xtd::event_args& e);
    void on_stopwatch_tick();
    
    void uncover_cell(int x, int y);
    void update_colors();

    void you_win();

    xtd::forms::panel game_panel_;
    xtd::forms::panel status_panel_;
    xtd::forms::lcd_label mine_count_label_;
    xtd::forms::lcd_label stopwatch_label_;
    xtd::forms::button start_game_;
    xtd::forms::timer stopwatch_timer_;
    grid_size grid_size_ {9, 9};
    int mine_count_ = 0;
    row_cell cells_;
    level level_ = level::beginner;
    bool game_over_ = false;
    int checked_cell_count_ = 0;
    int flagged_mine_count_ = 0;
    int stopwatch_count_ = 0;
  };
}
