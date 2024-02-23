#pragma once
#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/lcd_label>
#include <xtd/forms/main_menu>
#include <xtd/forms/panel>
#include <xtd/forms/timer>
#include "cell.h"
#include "high_scores_dialog.h"
#include "level.h"
#include "../properties/resources.h"
#include "../properties/settings.h"

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
    /// @name Constructors
    
    /// @{
    /// @brief Initialize a new instance of minesweeper::form_minesweeper form.
    minesweeper_form();
    /// @}

    /// @name Methods
    
    /// @{
    /// @brief The main entry point for the game.
    static void main();
    /// @}

  private:
    void change_level(level l);
    
    void new_game();
    
    void check_neighbors(const xtd::drawing::point& cell_location);
    int checked_cell(const xtd::drawing::point& cell_location);
    
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
    
    void on_about_menu_click(object& sender, const xtd::event_args& e);
    void on_custom_menu_click(object& sender, const xtd::event_args& e);
    void on_help_content_menu_click(object& sender, const xtd::event_args& e);
    void on_game_panel_mouse_up(object& sender, const xtd::forms::mouse_event_args& e);
    void on_game_panel_paint(object& sender, xtd::forms::paint_event_args& e);
    void on_marks_menu_click(object& sender, const xtd::event_args& e);
    void on_original_color_menu_click(object& sender, const xtd::event_args& e);
    void on_status_panel_paint(object& sender, xtd::forms::paint_event_args& e);
    void on_status_panel_resize(object& sender, const xtd::event_args& e);
    void on_stopwatch_tick();
    
    void uncover_cell(int x, int y);
    void update_colors();
    
    void you_win();
    
    xtd::forms::panel game_panel_;
    xtd::forms::panel status_panel_;
    xtd::forms::lcd_label mine_count_label_;
    xtd::forms::lcd_label stopwatch_label_;
    xtd::forms::button start_game_;
    
    xtd::forms::menu_item game_new_game_menu_item_ {"&New games", {[&] {new_game();}}, xtd::forms::shortcut::f2};
    xtd::forms::menu_item game_separator1_menu_item_ {"-"};
    xtd::forms::menu_item game_beginner_menu_item_ {"&Beginner", {[&] {change_level(level::beginner);}}, xtd::forms::menu_item_kind::radio, xtd::as<level>(properties::settings::default_settings().level()) == level::beginner};
    xtd::forms::menu_item game_inermediate_menu_item_ {"&Intermediate", {[&] {change_level(level::intermediate);}}, xtd::forms::menu_item_kind::radio, xtd::as<level>(properties::settings::default_settings().level()) == level::intermediate};
    xtd::forms::menu_item game_expert_menu_item_ {"&Expert", {[&] {change_level(level::expert);}}, xtd::forms::menu_item_kind::radio, xtd::as<level>(properties::settings::default_settings().level()) == level::expert};
    xtd::forms::menu_item game_custom_menu_item_ {"&Custom...", {*this, &minesweeper_form::on_custom_menu_click}, xtd::forms::menu_item_kind::radio, xtd::as<level>(properties::settings::default_settings().level()) == level::custom};
    xtd::forms::menu_item game_separator2_menu_item_ {"-"};
    xtd::forms::menu_item game_marks_menu_item_ {"&Marks [?]", {*this, &minesweeper_form::on_marks_menu_click}, xtd::forms::menu_item_kind::check, properties::settings::default_settings().marks()};
    xtd::forms::menu_item game_original_color_menu_item_ {"&Original color", {*this, &minesweeper_form::on_original_color_menu_click}, xtd::forms::menu_item_kind::check, properties::settings::default_settings().original_color()};
    xtd::forms::menu_item game_separator3_menu_item_ {"-"};
    xtd::forms::menu_item game_best_times_menu_item_ {"Best &times...", {[&] {high_scores_dialog().show_dialog(*this);}}};
    xtd::forms::menu_item game_separator4_menu_item_ {"-"};
    xtd::forms::menu_item game_exit_menu_item_ {xtd::drawing::texts::exit(), {overload_<>(xtd::forms::application::exit)}};
    xtd::forms::menu_item game_menu_item_ {"&Game", {game_new_game_menu_item_, game_separator1_menu_item_, game_beginner_menu_item_, game_inermediate_menu_item_, game_expert_menu_item_, game_custom_menu_item_, game_separator2_menu_item_, game_marks_menu_item_, game_original_color_menu_item_, game_separator3_menu_item_, game_best_times_menu_item_, game_separator4_menu_item_, game_exit_menu_item_}};
    xtd::forms::menu_item help_content_menu_item_ {"&Contents", {*this, &minesweeper_form::on_help_content_menu_click}, xtd::forms::shortcut::f1};
    xtd::forms::menu_item help_search_menu_item_ {"&Search for Help On...", {[&] {}}};
    xtd::forms::menu_item help_how_to_menu_item_ {"&How to Use Help", {[&] {}}};
    xtd::forms::menu_item help_separator1_menu_item_ {"-"};
    xtd::forms::menu_item help_about_menu_item_ {xtd::drawing::texts::about(), {*this, &minesweeper_form::on_about_menu_click}};
    xtd::forms::menu_item help_menu_item_ {xtd::drawing::texts::help(), {help_content_menu_item_, help_search_menu_item_, help_how_to_menu_item_, help_separator1_menu_item_, help_about_menu_item_}};
    xtd::forms::main_menu main_menu_ {game_menu_item_, help_menu_item_};
    
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
