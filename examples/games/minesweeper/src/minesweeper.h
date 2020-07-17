#pragma once
#include "cell.h"
#include "level.h"
#include "high_scores_dialog.h"
#include "input_name_dialog.h"
#include "../properties/settings.h"
#include <xtd/xtd.forms>

namespace minesweeper {
  class form_minesweeper : public xtd::forms::form {
    using column_cell = std::vector<std::shared_ptr<cell>>;
    using row_cell = std::vector<column_cell>;
    using grid_size = xtd::drawing::size;
    
  public:
    static void main() {
      xtd::forms::application::run(form_minesweeper());
    }
    
    form_minesweeper() {
      using namespace xtd;
      using namespace xtd::drawing;
      using namespace xtd::forms;

      text("Minesweeper");
      auto_size_mode(xtd::forms::auto_size_mode::grow_and_shrink);
      auto_size(true);
      
      //properties::settings::default_settings().original_color(false);
      //properties::settings::default_settings().save();
      
      if (properties::settings::default_settings().original_color()) {
        back_color(color::silver);
        fore_color(color::black);
      }
      
      menu({
        {
          "&Game", {
            {"&New games", {[&] {new_game();}}, shortcut::f2},
            {"-"},
            {"&Beginner", {[&] {change_level(level::beginner);}}, menu_item_kind::radio, true},
            {"&Intermediate", {[&] {change_level(level::intermediate);}}, menu_item_kind::radio},
            {"&Expert", {[&] {change_level(level::expert);}}, menu_item_kind::radio},
            {"&Custom...", {[&] {change_level(level::custom);}}, menu_item_kind::radio},
            {"-"},
            {"&Marks [?]", {[&](component& sender, const event_args& e) {/*reinterpret_cast<menu_item&>(sender).checked(!reinterpret_cast<menu_item&>(sender).checked());*/ properties::settings::default_settings().marks(!properties::settings::default_settings().marks());}}, menu_item_kind::check, true},
            {"&Original color", {[&](component& sender, const event_args& e) {/*reinterpret_cast<menu_item&>(sender).checked(!reinterpret_cast<menu_item&>(sender).checked());*/ properties::settings::default_settings().original_color(!properties::settings::default_settings().original_color());}}, menu_item_kind::check, true},
            {"-"},
            {"Best &times...", {[&] {minesweeper::high_scores_dialog().show_dialog(*this);}}},
            {"-"},
            {texts::exit, {[&] {close();}}},
          }
        },
        {
          texts::help, {
            {"&Contens", {[&] {}}, shortcut::f1},
            {"&Search for Help On...", {[&] {}}},
            {"&How to Use Help", {[&] {}}},
            {"-"},
            {texts::about, {[&] {about_dialog().common_dialog::show_dialog();}}}
          }
        },
      });

      status_panel.parent(*this);
      status_panel.height(60);
      status_panel.paint += [&](xtd::forms::control& sender, xtd::forms::paint_event_args& e) {
        e.graphics().draw_line(pen(color::lighter(color::lighter(color::lighter(back_color())))), 0, 0, e.clip_rectangle().width(), 0);
        e.graphics().draw_line(pen(color::lighter(color::lighter(back_color()))), 0, 1, e.clip_rectangle().width(), 1);
        e.graphics().draw_line(pen(color::lighter(back_color())), 1, 2, e.clip_rectangle().width(), 2);
        e.graphics().draw_line(pen(color::lighter(color::lighter(color::lighter(back_color())))), 0, 0, 0, e.clip_rectangle().height());
        e.graphics().draw_line(pen(color::lighter(color::lighter(back_color()))), 1, 1, 1, e.clip_rectangle().height());
        e.graphics().draw_line(pen(color::lighter(back_color())), 2, 2, 2, e.clip_rectangle().height());
        e.graphics().draw_line(pen(color::darker(back_color())), e.clip_rectangle().width() - 3, 2, e.clip_rectangle().width() - 3, e.clip_rectangle().height());
        e.graphics().draw_line(pen(color::darker(color::darker(back_color()))), e.clip_rectangle().width() - 2, 1, e.clip_rectangle().width() - 2, e.clip_rectangle().height());
        e.graphics().draw_line(pen(color::darker(color::darker(color::darker(back_color())))), e.clip_rectangle().width() - 1, 0, e.clip_rectangle().width() - 1, e.clip_rectangle().height());
        
        auto offset = 12;
        e.graphics().draw_line(pen(color::darker(color::darker(color::darker(back_color())))), offset, offset, e.clip_rectangle().width() - 1 - offset, offset);
        e.graphics().draw_line(pen(color::darker(color::darker(back_color()))), offset, 1 + offset, e.clip_rectangle().width() - 1 - offset, 1 + offset);
        e.graphics().draw_line(pen(color::darker(back_color())), 1 + offset, 2 + offset, e.clip_rectangle().width() - 1 - offset, 2 + offset);
        e.graphics().draw_line(pen(color::darker(color::darker(color::darker(back_color())))), offset, offset, offset, e.clip_rectangle().height() - 1);
        e.graphics().draw_line(pen(color::darker(color::darker(back_color()))), 1 + offset, 1 + offset, 1 + offset, e.clip_rectangle().height() - 1);
        e.graphics().draw_line(pen(color::darker(back_color())), 2 + offset, 2 + offset, 2 + offset, e.clip_rectangle().height() - 1);
        e.graphics().draw_line(pen(color::lighter(back_color())), 2 + offset, e.clip_rectangle().height() - 3, e.clip_rectangle().width() - 1 - offset, e.clip_rectangle().height() - 3);
        e.graphics().draw_line(pen(color::lighter(color::lighter(back_color()))), 1 + offset, e.clip_rectangle().height() - 2, e.clip_rectangle().width() - 1 - offset, e.clip_rectangle().height() - 2);
        e.graphics().draw_line(pen(color::lighter(color::lighter(color::lighter(back_color())))), offset, e.clip_rectangle().height() - 1, e.clip_rectangle().width() - 1 - offset, e.clip_rectangle().height() - 1);
        e.graphics().draw_line(pen(color::lighter(back_color())), e.clip_rectangle().width() - 3 - offset, 2 + offset, e.clip_rectangle().width() - 3 - offset, e.clip_rectangle().height() - 3);
        e.graphics().draw_line(pen(color::lighter(color::lighter(back_color()))), e.clip_rectangle().width() - 2 - offset, 1 + offset, e.clip_rectangle().width() - 2 - offset, e.clip_rectangle().height() - 2);
        e.graphics().draw_line(pen(color::lighter(color::lighter(color::lighter(back_color())))), e.clip_rectangle().width() - 1 - offset, offset, e.clip_rectangle().width() - 1 - offset, e.clip_rectangle().height() - 1);
      };
      
      game_panel.parent(*this);
      game_panel.location({0, 60});
      game_panel.paint += [&](xtd::forms::control& sender, xtd::forms::paint_event_args& e) {
        e.graphics().draw_line(pen(color::lighter(color::lighter(color::lighter(back_color())))), 0, 0, 0, e.clip_rectangle().height());
        e.graphics().draw_line(pen(color::lighter(color::lighter(back_color()))), 1, 0, 1, e.clip_rectangle().height());
        e.graphics().draw_line(pen(color::lighter(back_color())), 2, 0, 2, e.clip_rectangle().height());
        e.graphics().draw_line(pen(color::darker(back_color())), 2, e.clip_rectangle().height() - 3, e.clip_rectangle().width(), e.clip_rectangle().height() - 3);
        e.graphics().draw_line(pen(color::darker(color::darker(back_color()))), 1, e.clip_rectangle().height() - 2, e.clip_rectangle().width(), e.clip_rectangle().height() - 2);
        e.graphics().draw_line(pen(color::darker(color::darker(color::darker(back_color())))), 0, e.clip_rectangle().height() - 1, e.clip_rectangle().width(), e.clip_rectangle().height() - 1);
        e.graphics().draw_line(pen(color::darker(back_color())), e.clip_rectangle().width() - 3, 0, e.clip_rectangle().width() - 3, e.clip_rectangle().height() - 3);
        e.graphics().draw_line(pen(color::darker(color::darker(back_color()))), e.clip_rectangle().width() - 2, 0, e.clip_rectangle().width() - 2, e.clip_rectangle().height() - 2);
        e.graphics().draw_line(pen(color::darker(color::darker(color::darker(back_color())))), e.clip_rectangle().width() - 1, 0, e.clip_rectangle().width() - 1, e.clip_rectangle().height() - 1);
        
        auto offset = 12;
        e.graphics().draw_line(pen(color::darker(color::darker(color::darker(back_color())))), offset, offset, e.clip_rectangle().width() - 1 - offset, offset);
        e.graphics().draw_line(pen(color::darker(color::darker(back_color()))), offset, 1 + offset, e.clip_rectangle().width() - 1 - offset, 1 + offset);
        e.graphics().draw_line(pen(color::darker(back_color())), 1 + offset, 2 + offset, e.clip_rectangle().width() - 1 - offset, 2 + offset);
        e.graphics().draw_line(pen(color::darker(color::darker(color::darker(back_color())))), offset, offset, offset, e.clip_rectangle().height() - 1 - offset);
        e.graphics().draw_line(pen(color::darker(color::darker(back_color()))), 1 + offset, 1 + offset, 1 + offset, e.clip_rectangle().height() - 1 - offset);
        e.graphics().draw_line(pen(color::darker(back_color())), 2 + offset, 2 + offset, 2 + offset, e.clip_rectangle().height() - 1 - offset);
        e.graphics().draw_line(pen(color::lighter(back_color())), 2 + offset, e.clip_rectangle().height() - 3 - offset, e.clip_rectangle().width() - 1 - offset, e.clip_rectangle().height() - 3 - offset);
        e.graphics().draw_line(pen(color::lighter(color::lighter(back_color()))), 1 + offset, e.clip_rectangle().height() - 2 - offset, e.clip_rectangle().width() - 1 - offset, e.clip_rectangle().height() - 2 - offset);
        e.graphics().draw_line(pen(color::lighter(color::lighter(color::lighter(back_color())))), offset, e.clip_rectangle().height() - 1 - offset, e.clip_rectangle().width() - 1 - offset, e.clip_rectangle().height() - 1 - offset);
        e.graphics().draw_line(pen(color::lighter(back_color())), e.clip_rectangle().width() - 3 - offset, 2 + offset, e.clip_rectangle().width() - 3 - offset, e.clip_rectangle().height() - 3 - offset);
        e.graphics().draw_line(pen(color::lighter(color::lighter(back_color()))), e.clip_rectangle().width() - 2 - offset, 1 + offset, e.clip_rectangle().width() - 2 - offset, e.clip_rectangle().height() - 2 - offset);
        e.graphics().draw_line(pen(color::lighter(color::lighter(color::lighter(back_color())))), e.clip_rectangle().width() - 1 - offset, offset, e.clip_rectangle().width() - 1 - offset, e.clip_rectangle().height() - 1 - offset);
      };

      change_level(static_cast<level>(properties::settings::default_settings().level()));
      status_panel.width(client_size().width());

      mine_count_label.parent(status_panel);
      mine_count_label.location({17, 17});
      mine_count_label.height(38);
      mine_count_label.auto_size(true);
      mine_count_label.back_color(color::black);
      mine_count_label.fore_color(color::red);
      mine_count_label.thickness(5);

      stopwatch_label.parent(status_panel);
      stopwatch_label.height(38);
      stopwatch_label.auto_size(true);
      stopwatch_label.back_color(color::black);
      stopwatch_label.fore_color(color::red);
      stopwatch_label.location({status_panel.width() - stopwatch_label.width() - 18, 17});
      stopwatch_label.thickness(5);

      start_game.parent(status_panel);
      start_game.image(bitmap(properties::resources::smiley1(), {24, 24}));
      start_game.size({42, 38});
      start_game.location({status_panel.size().width() / 2 - 21, 17});
      start_game.click += [&] {
        new_game();
      };
      
      stopwatch.interval(1000);
      stopwatch.tick += [&] {
        if (stopwatch_count_ < 999) stopwatch_label.text(strings::format("{:D3}", ++stopwatch_count_));
      };
    }
    
  private:
    void change_level(level l) {
      using namespace xtd;
      using namespace xtd::drawing;
      using namespace xtd::forms;
      level_ = l;
      cells_.clear();
      grid_size_ = std::map<minesweeper::level, grid_size> {{minesweeper::level::beginner, {9, 9}}, {minesweeper::level::intermediate, {16, 16}}, {minesweeper::level::expert, {30, 16}}, {minesweeper::level::custom, {properties::settings::default_settings().custom_width(), properties::settings::default_settings().custom_height()}}} [level_];
      mine_count_ = std::map<minesweeper::level, int> {{minesweeper::level::beginner, 10}, {minesweeper::level::intermediate, 40}, {minesweeper::level::expert, 99}, {minesweeper::level::custom, properties::settings::default_settings().custom_mines()}} [level_];

      game_panel.size({30 + grid_size_.width() * cell().width(),30 + grid_size_.height() * cell().height()});

      suspend_layout();
      cells_ = row_cell(grid_size_.width(), column_cell(grid_size_.height()));
      for (auto y = 0; y < grid_size_.height(); y++) {
        for (auto x = 0; x < grid_size_.width(); x++) {
          cells_[x][y] = std::make_shared<cell>();
          cells_[x][y]->parent(game_panel);
          cells_[x][y]->cell_location({x, y});
          cells_[x][y]->location({15 + x * cells_[x][y]->size().width(), 15 + y * cells_[x][y]->size().height()});
          cells_[x][y]->mouse_up += [&](control& sender, const mouse_event_args& e) {
            if (game_over_) return;
            minesweeper::cell& cell = static_cast<minesweeper::cell&>(sender);
            stopwatch.enabled(true);
            if (e.button() == mouse_buttons::left) {
              start_game.image(bitmap(properties::resources::smiley4(), {24, 24}));
              application::do_events();
              if (cell.state() == cell_state::question) cell.state(cell_state::unchecked);
              if (cell.state() == cell_state::unchecked) {
                if (!cell.has_mine()) {
                  check_neighbors(cell.cell_location());
                  if (grid_size_.width() * grid_size_.height() - checked_cell_count_ == mine_count_) {
                    stopwatch.enabled(false);
                    game_over_ = true;
                    start_game.image(bitmap(properties::resources::smiley3(), {24, 24}));
                    for (int index1 = 0; index1 < grid_size_.height(); index1++)
                      for (int index2 = 0; index2 <grid_size_.width(); index2++)
                        if (cells_[index2][index1]->state() != cell_state::flag && cells_[index2][index1]->has_mine())
                          cells_[index2][index1]->state(cell_state::mine);
                    mine_count_label.text("000");
                    if (level_ != level::custom && stopwatch_count_ < std::map<level, int> {{level::beginner, properties::settings::default_settings().beginner_high_scores_value()}, {level::intermediate, properties::settings::default_settings().intermediate_high_scores_value()}, {level::expert, properties::settings::default_settings().expert_high_scores_value()}}[level_]) {
                      std::string gamer_name = std::map<level, std::string> {{level::beginner, properties::settings::default_settings().beginner_high_scores_name()}, {level::intermediate, properties::settings::default_settings().intermediate_high_scores_name()}, {level::expert, properties::settings::default_settings().expert_high_scores_name()}}[level_];
                      minesweeper::input_name_dialog input_name_dialog;
                      input_name_dialog.gammer_name(gamer_name);
                      input_name_dialog.level(level_);
                      if (input_name_dialog.show_dialog(*this) == dialog_result::ok)
                        gamer_name = input_name_dialog.gammer_name();
                      
                      std::map<level, delegate<void(int)>> set_settings_high_scores_values {{level::beginner, {properties::settings::default_settings(), &properties::settings::beginner_high_scores_value}}, {level::intermediate, {properties::settings::default_settings(), &properties::settings::intermediate_high_scores_value}}, {level::expert, {properties::settings::default_settings(), &properties::settings::expert_high_scores_value}}};
                      std::map<level, delegate<void(std::string)>> set_settings_high_scores_names {{level::beginner, {properties::settings::default_settings(), &properties::settings::beginner_high_scores_name}}, {level::intermediate, {properties::settings::default_settings(), &properties::settings::intermediate_high_scores_name}}, {level::expert, {properties::settings::default_settings(), &properties::settings::expert_high_scores_name}}};
                      set_settings_high_scores_values[level_](stopwatch_count_);
                      set_settings_high_scores_names[level_](gamer_name);
                      properties::settings::default_settings().save();
                      
                      minesweeper::high_scores_dialog().show_dialog(*this);
                    }
                  } else
                    start_game.image(bitmap(properties::resources::smiley1(), {24, 24}));
                } else {
                  stopwatch.enabled(false);
                  game_over_ = true;
                  start_game.image(bitmap(properties::resources::smiley2(), {24, 24}));
                  for (int index1 = 0; index1 < grid_size_.height(); index1++) {
                    for (int index2 = 0; index2 <grid_size_.width(); index2++) {
                      if (cells_[index2][index1]->state() == cell_state::flag && !cells_[index2][index1]->has_mine())
                        cells_[index2][index1]->state(cell_state::error);
                      if (cells_[index2][index1]->state() != cell_state::flag && cells_[index2][index1]->has_mine())
                        cells_[index2][index1]->state(cell_state::mine);
                    }
                  }
                  cell.state(cell_state::exploded_mine);
                }
              }
            } else if (e.button() == mouse_buttons::right) {
              if (cell.state() == cell_state::unchecked) {
                cell.state(cell_state::flag);
                ++flagged_mine_count_;
              } else if (cell.state() == cell_state::flag && properties::settings::default_settings().marks()) {
                cell.state(cell_state::question);
                --flagged_mine_count_;
              } else if (cell.state() == cell_state::flag || cell.state() == cell_state::question) cell.state(cell_state::unchecked);
              if ((mine_count_ - flagged_mine_count_) >= 0 && (mine_count_ - flagged_mine_count_) <= 999) mine_count_label.text(strings::format("{:D3}", mine_count_ - flagged_mine_count_));
              else if (mine_count_ - flagged_mine_count_ >= -99) mine_count_label.text(strings::format("{:D2}", mine_count_ - flagged_mine_count_));
            }
          };
        }
      }
      resume_layout();
      new_game();
    }

    void new_game() {
      using namespace xtd;
      using namespace xtd::drawing;
      game_panel.visible(false);
      suspend_layout();
      game_over_ = false;
      stopwatch.enabled(false);
      checked_cell_count_ = 0;
      flagged_mine_count_ = 0;
      stopwatch_count_ = 0;
      for (auto y = 0; y < grid_size_.height(); y++)
        for (auto x = 0; x < grid_size_.width(); x++)
          cells_[x][y]->clear();
      
      std::random_device rand;
      for (auto count = 0; count < mine_count_; count++) {
        auto x = std::uniform_int_distribution<int>{0, grid_size_.width() - 1}(rand);;
        auto y = std::uniform_int_distribution<int>{0, grid_size_.height() - 1}(rand);;

        if (cells_[x][y]->has_mine()) {
          count--;
          continue;
        }
        cells_[x][y]->has_mine(true);
      }
      mine_count_label.text(strings::format("{:D3}", mine_count_ - flagged_mine_count_));
      stopwatch_label.text("000");
      start_game.image(bitmap(properties::resources::smiley1(), {24, 24}));
      resume_layout();
      game_panel.visible(true);
    }
    
    void check_neighbors(const xtd::drawing::point& cell_location) {
      if (checked_cell(cell_location) != 0) return;
      for (auto y = cell_location.y() - 1; y <= cell_location.y() + 1; y++) {
        for (auto x = cell_location.x() - 1; x <= cell_location.x() + 1; x++) {
          if (y >= 0 && y < grid_size_.height() && x >= 0 && x < grid_size_.width() && cells_[x][y]->state() == cell_state::unchecked && checked_cell({x, y}) == 0) {
            check_neighbors({x, y});
          }
        }
      }
    }

    int checked_cell(const xtd::drawing::point& cell_location) {
      if (cells_[cell_location.x()][cell_location.y()]->state() == cell_state::unchecked) {
        cells_[cell_location.x()][cell_location.y()]->state(cell_state::checked);
        checked_cell_count_++;
      }

      for (int y = cell_location.y() - 1; y <= cell_location.y() + 1; y++) {
        for (int x = cell_location.x() - 1; x <= cell_location.x() + 1; x++) {
          if (y >= 0 && y < grid_size_.height() && x >= 0 && x < grid_size_.width() && cells_[x][y]->has_mine()) {
            cells_[cell_location.x()][cell_location.y()]->neighbors(cells_[cell_location.x()][cell_location.y()]->neighbors() + 1);
          }
        }
      }

      return cells_[cell_location.x()][cell_location.y()]->neighbors();
    }

    xtd::forms::panel status_panel;
    xtd::forms::lcd_label mine_count_label;
    xtd::forms::lcd_label stopwatch_label;
    xtd::forms::button start_game;
    xtd::forms::panel game_panel;
    xtd::forms::timer stopwatch;
    grid_size grid_size_;
    int mine_count_;
    row_cell cells_;
    level level_ = level::beginner;
    bool game_over_ = false;
    int checked_cell_count_ = 0;
    int flagged_mine_count_ = 0;
    int stopwatch_count_ = 0;
  };
}
