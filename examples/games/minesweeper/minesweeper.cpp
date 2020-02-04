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
    error,
  };

  class cell : public user_control {
  public:
    cell() {
      font(drawing::font(font(), 16));
      size({30, 30});
     };

    const point& cell_location() const {return cell_location_;}
    void cell_location(const point& value) {
      if (cell_location_ != value) {
        cell_location_ = value;
      }
    }

    bool has_mine() const {return has_mine_;}
    void has_mine(bool value) {
      if (has_mine_ != value) {
        has_mine_ = value;
      }
    }
 
    bool has_neighbors() const {return neighbors_;}

    int neighbors() const {return neighbors_;}
    void neighbors(int value) {
      if (neighbors_ != value) {
        neighbors_ = value;
      }
    }

    cell_state state() const {return state_;}
    void state(cell_state value) {
      if (state_ != value) {
        state_ = value;
      }
    }
    
    void clear() {
      state_ = cell_state::unchecked;
      has_mine_ = false;
      neighbors_ = 0;
    }

  protected:
    void on_paint(paint_event_args& e) override {
      std::map<cell_state, delegate<void(paint_event_args&)>> draw_state {{cell_state::unchecked, {*this, &cell::do_draw_unchecked}}, {cell_state::checked, {*this, &cell::do_draw_checked}}, {cell_state::flag, {*this, &cell::do_draw_flag}}, {cell_state::question, {*this, &cell::do_draw_question}}, {cell_state::mine, {*this, &cell::do_draw_mine}}, {cell_state::exploded_mine, {*this, &cell::do_draw_exploded_mine}}, {cell_state::error, {*this, &cell::do_draw_error}}};
      draw_state[state_](e);
      user_control::on_paint(e);
    }
    
  private:
    void do_draw_unchecked(paint_event_args& e) {
      draw_border_unchecked(e);
    }
    
    void do_draw_checked(paint_event_args& e) {
      draw_border_checked(e);
      color text_color = system_colors::control_text();
      if (neighbors_ == 6) text_color = fore_color();
      if (neighbors_ == 5) text_color = color::dark_red;
      if (neighbors_ == 4) text_color = color::dark_blue;
      if (neighbors_ == 3) text_color = color::red;
      if (neighbors_ == 2) text_color = color::green;
      if (neighbors_ == 1) text_color = color::blue;
      if (neighbors_ != 0) {
        std::string text = std::to_string(neighbors_);
        auto x = (e.clip_rectangle().width() - e.graphics().measure_string(text, font()).width()) / 2;
        auto y = (e.clip_rectangle().height() - e.graphics().measure_string(text, font()).height()) / 2;
        e.graphics().draw_string(text, font(), solid_brush(color::lighter(color::lighter(text_color))), x - 1, y - 1);
        e.graphics().draw_string(text, font(), solid_brush(color::darker(color::darker(text_color))), x + 1, y + 1);
        e.graphics().draw_string(text, font(), solid_brush(text_color), x, y);
      }
    }
    
    void do_draw_flag(paint_event_args& e) {
      draw_border_unchecked(e);
      static image flag = bitmap(image::from_data(flag_256x256), {16, 16});
      auto x = (e.clip_rectangle().width() - flag.width()) / 2;
      auto y = (e.clip_rectangle().height() - flag.height()) / 2;
      e.graphics().draw_image(flag, x, y);
    }
    
    void do_draw_question(paint_event_args& e) {
      draw_border_unchecked(e);
      auto x = (e.clip_rectangle().width() - e.graphics().measure_string("?", font()).width()) / 2;
      auto y = (e.clip_rectangle().height() - e.graphics().measure_string("?", font()).height()) / 2;
      e.graphics().draw_string("?", font(), solid_brush(fore_color()), x, y);
    }
    
    void do_draw_mine(paint_event_args& e) {
      draw_border_checked(e);
      static image mine = bitmap(image::from_data(mine_256x256), {16, 16});
      auto x = (e.clip_rectangle().width() - mine.width()) / 2;
      auto y = (e.clip_rectangle().height() - mine.height()) / 2;
      e.graphics().draw_image(mine, x, y);
    }
    
    void do_draw_exploded_mine(paint_event_args& e) {
      e.graphics().clear(color::red);
      draw_border_checked(e);
      static image mine = bitmap(image::from_data(mine_256x256), {16, 16});
      auto x = (e.clip_rectangle().width() - mine.width()) / 2;
      auto y = (e.clip_rectangle().height() - mine.height()) / 2;
      e.graphics().draw_image(mine, x, y);
    }

    void do_draw_error(paint_event_args& e) {
      draw_border_checked(e);
      static image mine = bitmap(image::from_data(mine_256x256), {16, 16});
      auto x = (e.clip_rectangle().width() - mine.width()) / 2;
      auto y = (e.clip_rectangle().height() - mine.height()) / 2;
      e.graphics().draw_image(mine, x, y);
      e.graphics().draw_line(pen(color::red, 2), 0, 0, e.clip_rectangle().width(), e.clip_rectangle().height());
      e.graphics().draw_line(pen(color::red, 2), e.clip_rectangle().width(), 0, 0, e.clip_rectangle().height());
    }

    void draw_border_unchecked(paint_event_args& e) {
      e.graphics().draw_line(pen(color::lighter(color::lighter(color::lighter(back_color())))), 0, 0, e.clip_rectangle().width(), 0);
      e.graphics().draw_line(pen(color::lighter(color::lighter(back_color()))), 0, 1, e.clip_rectangle().width(), 1);
      e.graphics().draw_line(pen(color::lighter(back_color())), 1, 2, e.clip_rectangle().width(), 2);
      e.graphics().draw_line(pen(color::lighter(color::lighter(color::lighter(back_color())))), 0, 0, 0, e.clip_rectangle().height());
      e.graphics().draw_line(pen(color::lighter(color::lighter(back_color()))), 1, 1, 1, e.clip_rectangle().height());
      e.graphics().draw_line(pen(color::lighter(back_color())), 2, 2, 2, e.clip_rectangle().height());
      e.graphics().draw_line(pen(color::darker(back_color())), 2, e.clip_rectangle().height() - 3, e.clip_rectangle().width(), e.clip_rectangle().height() - 3);
      e.graphics().draw_line(pen(color::darker(color::darker(back_color()))), 1, e.clip_rectangle().height() - 2, e.clip_rectangle().width(), e.clip_rectangle().height() - 2);
      e.graphics().draw_line(pen(color::darker(color::darker(color::darker(back_color())))), 0, e.clip_rectangle().height() - 1, e.clip_rectangle().width(), e.clip_rectangle().height() - 1);
      e.graphics().draw_line(pen(color::darker(back_color())), e.clip_rectangle().width() - 3, 2, e.clip_rectangle().width() - 3, e.clip_rectangle().height() - 3);
      e.graphics().draw_line(pen(color::darker(color::darker(back_color()))), e.clip_rectangle().width() - 2, 1, e.clip_rectangle().width() - 2, e.clip_rectangle().height() - 2);
      e.graphics().draw_line(pen(color::darker(color::darker(color::darker(back_color())))), e.clip_rectangle().width() - 1, 0, e.clip_rectangle().width() - 1, e.clip_rectangle().height() - 1);
    }
    
    void draw_border_checked(paint_event_args& e) {
      e.graphics().draw_line(pen(color::darker(back_color())), 0, 0, e.clip_rectangle().width(), 0);
      e.graphics().draw_line(pen(color::darker(back_color())), 0, 0, 0, e.clip_rectangle().height());
      e.graphics().draw_line(pen(color::lighter(back_color())), 1, e.clip_rectangle().height() - 1, e.clip_rectangle().width(), e.clip_rectangle().height() - 1);
      e.graphics().draw_line(pen(color::lighter(back_color())), e.clip_rectangle().width() - 1, 1, e.clip_rectangle().width() - 1, e.clip_rectangle().height() - 1);
    }
    
    #include "resources/flag.xpm"
    #include "resources/mine.xpm"
    cell_state state_ = cell_state::unchecked;
    bool has_mine_ = false;
    int neighbors_ = 0;
    point cell_location_;
  };

  class form_main : public form {
    using column_cell = std::vector<std::shared_ptr<cell>>;
    using row_cell = std::vector<column_cell>;
    using grid_size = drawing::size;
  public:
    form_main() {
      text("Minesweeper");
      auto_size_mode(forms::auto_size_mode::grow_and_shrink);
      auto_size(true);
      
      //back_color(color::silver);
      //fore_color(color::black);
      
      status_panel.parent(*this);
      status_panel.height(60);
      status_panel.paint += [&](control& sender, paint_event_args& e) {
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
      game_panel.paint += [&](control& sender, paint_event_args& e) {
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

      change_level(level::intermediate);
      status_panel.width(client_size().width());

      mine_count_label.parent(status_panel);
      mine_count_label.location({17, 17});
      mine_count_label.height(38);
      mine_count_label.auto_size(true);
      mine_count_label.back_color(color::black);
      mine_count_label.fore_color(color::red);

      stopwatch_label.parent(status_panel);
      stopwatch_label.height(38);
      stopwatch_label.auto_size(true);
      stopwatch_label.back_color(color::black);
      stopwatch_label.fore_color(color::red);
      stopwatch_label.location({status_panel.width() - stopwatch_label.width() - 18, 17});

      start_game.parent(status_panel);
      start_game.image(bitmap(image::from_data(smiley1_120x120), {24, 24}));
      start_game.size({42, 38});
      start_game.location({status_panel.size().width() / 2 - 21, 17});
      start_game.click += [&] {
        new_game();
      };
      
      stopwatch.interval(1000);
      stopwatch.tick += [&] {
        if (stopwatch_count_ <= 999) stopwatch_label.text(strings::format("{:D3}", ++stopwatch_count_));
      };
    }
    
  private:
    void change_level(level level) {
      level_ = level;
      cells_.clear();
      grid_size_ = std::map<minesweeper::level, grid_size> {{minesweeper::level::beginer, {9, 9}}, {minesweeper::level::intermediate, {16, 16}}, {minesweeper::level::expert, {30, 16}}} [level_];
      mine_count_ = std::map<minesweeper::level, int> {{minesweeper::level::beginer, 10}, {minesweeper::level::intermediate, 40}, {minesweeper::level::expert, 99}} [level_];

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
              start_game.image(bitmap(image::from_data(smiley4_120x120), {24, 24}));
              application::do_events();
              if (cell.state() == cell_state::question) {
                cell.state(cell_state::unchecked);
                cell.invalidate();
              }
              if (cell.state() == cell_state::unchecked) {
                if (!cell.has_mine()) {
                  check_neighbors(cell.cell_location());
                  cdebug << format("total cells = {}, mine to found = {}, mine uncheck = {}", grid_size_.width() * grid_size_.height(), mine_count_, grid_size_.width() * grid_size_.height() - checked_cell_count_) << std::endl;
                  if (grid_size_.width() * grid_size_.height() - checked_cell_count_ == mine_count_) {
                    suspend_layout();
                    stopwatch.enabled(false);
                    game_over_ = true;
                    start_game.image(bitmap(image::from_data(smiley3_120x120), {24, 24}));
                    for (int index1 = 0; index1 < grid_size_.height(); index1++)
                      for (int index2 = 0; index2 <grid_size_.width(); index2++)
                        if (cells_[index2][index1]->state() != cell_state::flag && cells_[index2][index1]->has_mine())
                          cells_[index2][index1]->state(cell_state::mine);
                    mine_count_label.text("000");
                    game_panel.invalidate();
                    resume_layout();
                    message_box::show(*this, "You win!");
                  } else
                    start_game.image(bitmap(image::from_data(smiley1_120x120), {24, 24}));
                } else {
                  suspend_layout();
                  stopwatch.enabled(false);
                  game_over_ = true;
                  start_game.image(bitmap(image::from_data(smiley2_120x120), {24, 24}));
                  for (int index1 = 0; index1 < grid_size_.height(); index1++) {
                    for (int index2 = 0; index2 <grid_size_.width(); index2++) {
                      if (cells_[index2][index1]->state() == cell_state::flag && !cells_[index2][index1]->has_mine())
                        cells_[index2][index1]->state(cell_state::error);
                      if (cells_[index2][index1]->state() != cell_state::flag && cells_[index2][index1]->has_mine())
                        cells_[index2][index1]->state(cell_state::mine);
                    }
                  }
                  cell.state(cell_state::exploded_mine);
                  game_panel.invalidate();
                  resume_layout();
                  message_box::show(*this, "BOOOooomm!");
                }
              }
            } else if (e.button() == mouse_buttons::right) {
              if (cell.state() == cell_state::unchecked) {
                cell.state(cell_state::flag);
                ++flagged_mine_count_;
              } else if (cell.state() == cell_state::flag) {
                cell.state(cell_state::question);
                --flagged_mine_count_;
              } else if (cell.state() == cell_state::question) cell.state(cell_state::unchecked);
              if ((mine_count_ - flagged_mine_count_) >= 0 && (mine_count_ - flagged_mine_count_) <= 999) mine_count_label.text(strings::format("{:D3}", mine_count_ - flagged_mine_count_));
              else if (mine_count_ - flagged_mine_count_ >= -99) mine_count_label.text(strings::format("{:D2}", mine_count_ - flagged_mine_count_));
              cell.invalidate();
            }
          };
        }
      }
      resume_layout();
      new_game();
    }

    void new_game() {
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
      start_game.image(bitmap(image::from_data(smiley1_120x120), {24, 24}));
      game_panel.invalidate();
      resume_layout();
    }
    
    void check_neighbors(const point& cell_location) {
      if (checked_cell(cell_location) != 0) return;
      for (auto y = cell_location.y() - 1; y <= cell_location.y() + 1; y++) {
        for (auto x = cell_location.x() - 1; x <= cell_location.x() + 1; x++) {
          if (y >= 0 && y < grid_size_.height() && x >= 0 && x < grid_size_.width() && cells_[x][y]->state() == cell_state::unchecked && checked_cell({x, y}) == 0) {
            check_neighbors({x, y});
          }
        }
      }
    }

    int checked_cell(const point& cell_location) {
      if (cells_[cell_location.x()][cell_location.y()]->state() == cell_state::unchecked) {
        cells_[cell_location.x()][cell_location.y()]->state(cell_state::checked);
        checked_cell_count_++;
      }

      for (int y = cell_location.y() - 1; y <= cell_location.y() + 1; y++) {
        for (int x = cell_location.x() - 1; x <= cell_location.x() + 1; x++) {
          if (y >= 0 && y < grid_size_.height() && x >= 0 && x < grid_size_.width() && cells_[x][y]->has_mine())
            cells_[cell_location.x()][cell_location.y()]->neighbors(cells_[cell_location.x()][cell_location.y()]->neighbors() + 1);
          cells_[cell_location.x()][cell_location.y()]->invalidate();
        }
      }

      return cells_[cell_location.x()][cell_location.y()]->neighbors();
    }

    #include "resources/smiley1.xpm"
    #include "resources/smiley2.xpm"
    #include "resources/smiley3.xpm"
    #include "resources/smiley4.xpm"
    panel status_panel;
    lcd_label mine_count_label;
    lcd_label stopwatch_label;
    button start_game;
    panel game_panel;
    timer stopwatch;
    grid_size grid_size_;
    int mine_count_;
    row_cell cells_;
    level level_ = level::beginer;
    bool game_over_ = false;
    int checked_cell_count_ = 0;
    int flagged_mine_count_ = 0;
    int stopwatch_count_ = 0;
  };
}

int main() {
  xtd::forms::application::run(minesweeper::form_main());
}
