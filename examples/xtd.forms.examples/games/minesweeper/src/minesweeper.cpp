#include "minesweeper.h"
#include "high_scores_dialog.h"
#include "input_name_dialog.h"
#include "../properties/resources.h"
#include "../properties/settings.h"

using namespace minesweeper;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

void form_minesweeper::main() {
  application::run(form_minesweeper());
}

form_minesweeper::form_minesweeper() {
  auto_size_mode(forms::auto_size_mode::grow_and_shrink);
  auto_size(true);
  font(drawing::font(font(), 16, font_style::bold));
  menu(create_main_menu());
  text("Minesweeper"_t);
  
  update_colors();
  
  status_panel.parent(*this);
  status_panel.height(60);
  status_panel.paint += {*this, &form_minesweeper::on_status_panel_paint};
  status_panel.resize +=  {*this, &form_minesweeper::on_status_panel_resize};
  
  game_panel.parent(*this);
  game_panel.location({0, 60});
  game_panel.mouse_up +=  {*this, &form_minesweeper::on_game_panel_mouse_up};
  game_panel.paint +=  {*this, &form_minesweeper::on_game_panel_paint};
  
  change_level(static_cast<level>(properties::settings::default_settings().level()));
  
  mine_count_label.parent(status_panel);
  mine_count_label.location({17, 17});
  mine_count_label.height(38);
  mine_count_label.auto_size(true);
  mine_count_label.back_color(color::black);
  mine_count_label.fore_color(color::red);
  mine_count_label.segment_style(forms::segment_style::modern);
  mine_count_label.thickness(5);
  
  stopwatch_label.parent(status_panel);
  stopwatch_label.height(38);
  stopwatch_label.auto_size(true);
  stopwatch_label.back_color(color::black);
  stopwatch_label.fore_color(color::red);
  stopwatch_label.segment_style(forms::segment_style::modern);
  stopwatch_label.thickness(5);
  stopwatch_label.location({status_panel.width() - stopwatch_label.width() - 18, 17});
  
  start_game.parent(status_panel);
  start_game.image(bitmap(properties::resources::smiley1(), {24, 24}));
  start_game.size({42, 38});
  start_game.location({status_panel.size().width() / 2 - 21, 17});
  start_game.click += {*this, &form_minesweeper::new_game};
  
  stopwatch.interval_milliseconds(1000);
  stopwatch.tick += {*this, &form_minesweeper::on_stopwatch_tick};
}

void form_minesweeper::change_level(level l) {
  properties::settings::default_settings().level(static_cast<int>(l));
  properties::settings::default_settings().save();
  
  level_ = l;
  cells_.clear();
  grid_size_ = std::map<minesweeper::level, grid_size> {{minesweeper::level::beginner, {9, 9}}, {minesweeper::level::intermediate, {16, 16}}, {minesweeper::level::expert, {30, 16}}, {minesweeper::level::custom, {properties::settings::default_settings().custom_width(), properties::settings::default_settings().custom_height()}}} [level_];
  mine_count_ = std::map<minesweeper::level, int> {{minesweeper::level::beginner, 10}, {minesweeper::level::intermediate, 40}, {minesweeper::level::expert, 99}, {minesweeper::level::custom, properties::settings::default_settings().custom_mines()}} [level_];
  
  game_panel.size({30 + grid_size_.width() * cell::width(), 30 + grid_size_.height() * cell::height()});
  cells_ = row_cell(grid_size_.width(), column_cell(grid_size_.height()));
  
  suspend_layout();
  
  resume_layout();
  status_panel.width(game_panel.width());
  new_game();
}

void form_minesweeper::new_game() {
  game_panel.visible(false);
  suspend_layout();
  game_over_ = false;
  stopwatch.enabled(false);
  checked_cell_count_ = 0;
  flagged_mine_count_ = 0;
  stopwatch_count_ = 0;
  for (auto y = 0; y < grid_size_.height(); y++)
    for (auto x = 0; x < grid_size_.width(); x++)
      cells_[x][y].clear();
  
  std::random_device rand;
  for (auto count = 0; count < mine_count_; count++) {
    auto x = std::uniform_int_distribution<int>{0, grid_size_.width() - 1}(rand);;
    auto y = std::uniform_int_distribution<int>{0, grid_size_.height() - 1}(rand);;
    
    if (cells_[x][y].has_mine()) {
      count--;
      continue;
    }
    cells_[x][y].has_mine(true);
  }
  
  for (int y = 0; y < grid_size_.height(); y++)
    for (int x = 0; x < grid_size_.width(); x++)
      for (int yy = y - 1; yy <= y + 1; yy++)
        for (int xx = x - 1; xx <= x + 1; xx++)
          if (yy >= 0 && yy < grid_size_.height() && xx >= 0 && xx < grid_size_.width() && cells_[xx][yy].has_mine())
            cells_[x][y].neighbors(cells_[x][y].neighbors() + 1);
  
  mine_count_label.text(strings::format("{:D3}", mine_count_ - flagged_mine_count_));
  stopwatch_label.text("000");
  start_game.image(bitmap(properties::resources::smiley1(), {24, 24}));
  resume_layout();
  game_panel.visible(true);
}

void form_minesweeper::check_neighbors(const point& cell_location) {
  if (checked_cell(cell_location) != 0) return;
  for (auto y = cell_location.y() - 1; y <= cell_location.y() + 1; y++)
    for (auto x = cell_location.x() - 1; x <= cell_location.x() + 1; x++)
      if (y >= 0 && y < grid_size_.height() && x >= 0 && x < grid_size_.width() && cells_[x][y].state() == cell_state::unchecked && checked_cell({x, y}) == 0)
        check_neighbors({x, y});
}

int form_minesweeper::checked_cell(const point& cell_location) {
  if (cells_[cell_location.x()][cell_location.y()].state() == cell_state::unchecked) {
    cells_[cell_location.x()][cell_location.y()].state(cell_state::checked);
    checked_cell_count_++;
  }
  return cells_[cell_location.x()][cell_location.y()].neighbors();
}

main_menu form_minesweeper::create_main_menu() {
  return {
    {"&Game"_t, {
      {"&New games"_t, {[&] {new_game();}}, shortcut::f2},
      {"-"},
      {"&Beginner"_t, {[&] {change_level(level::beginner);}}, menu_item_kind::radio, as<level>(properties::settings::default_settings().level()) == level::beginner},
      {"&Intermediate"_t, {[&] {change_level(level::intermediate);}}, menu_item_kind::radio, as<level>(properties::settings::default_settings().level()) == level::intermediate},
      {"&Expert"_t, {[&] {change_level(level::expert);}}, menu_item_kind::radio, as<level>(properties::settings::default_settings().level()) == level::expert},
      {"&Custom..."_t, {[&] {change_level(level::custom);}}, menu_item_kind::radio, as<level>(properties::settings::default_settings().level()) == level::custom},
      {"-"},
      {"&Marks [?]"_t, {[&](component& sender, const event_args& e) {
        properties::settings::default_settings().marks(!properties::settings::default_settings().marks());
        properties::settings::default_settings().save();
      }}, menu_item_kind::check, true},
      {"&Original color"_t, {[&](component& sender, const event_args& e) {
        properties::settings::default_settings().original_color(!properties::settings::default_settings().original_color());
        properties::settings::default_settings().save();
        update_colors();
      }}, menu_item_kind::check, properties::settings::default_settings().original_color()},
      {"-"},
      {"Best &times..."_t, {[&] {minesweeper::high_scores_dialog().show_dialog(*this);}}},
      {"-"},
      {texts::exit(), {overload_<>(application::exit)}},
    }},
    {texts::help(), {
      {"&Contens"_t, {[&] {}}, shortcut::f1},
      {"&Search for Help On..."_t, {[&] {}}},
      {"&How to Use Help"_t, {[&] {}}},
      {"-"},
      {texts::about(), {*this, &form_minesweeper::show_about_dialog}}
    }},
  };
}

void form_minesweeper::draw_cell(paint_event_args& e, int x, int y, minesweeper::cell cell) {
  std::map<cell_state, delegate<void(paint_event_args&, int, int, minesweeper::cell)>> draw_state {{cell_state::unchecked, {*this, &form_minesweeper::draw_unchecked}}, {cell_state::checked, {*this, &form_minesweeper::draw_checked}}, {cell_state::flag, {*this, &form_minesweeper::draw_flag}}, {cell_state::question, {*this, &form_minesweeper::draw_question}}, {cell_state::mine, {*this, &form_minesweeper::draw_mine}}, {cell_state::exploded_mine, {*this, &form_minesweeper::draw_exploded_mine}}, {cell_state::error, {*this, &form_minesweeper::draw_error}}};
  draw_state[cell.state()](e, x, y, cell);
}

void form_minesweeper::draw_unchecked(paint_event_args& e, int x, int y, minesweeper::cell cell) {
  draw_border_unchecked(e, x, y);
}

void form_minesweeper::draw_checked(paint_event_args& e, int x, int y, minesweeper::cell cell) {
  draw_border_checked(e, x, y);
  color text_color;
  switch (cell.neighbors()) {
    case 1: text_color = back_color().get_brightness() < 0.5f ? color::from_argb(0x60, 0xB0, 0xFF) : color::blue; break;
    case 2: text_color = back_color().get_brightness() < 0.5f ? color::from_argb(0x30, 0xDC, 0x66) : color::green; break;
    case 3: text_color = back_color().get_brightness() < 0.5f ? color::from_argb(0xD0, 0x3E, 0x3D) : color::red; break;
    case 4: text_color = color::from_argb(0xDE, 0x77, 0x35); break;
    case 5: text_color = back_color().get_brightness() < 0.5f ? color::from_argb(0xE2, 0xCC, 0x1E) : color::brown; break;
    case 6: text_color = back_color().get_brightness() < 0.5f ? color::from_argb(0xC6, 0x5E, 0x3A) : color::from_argb(0x80, 0x02, 0x80); break;
    case 7:  text_color = back_color().get_brightness() < 0.5f ? color::light_gray : color::dark_gray; break;
    case 8: text_color = fore_color(); break;
    default: return;
  }
  std::string text = std::to_string(cell.neighbors());
  rectangle rect(x, y, cell::width(), cell::height());
  auto text_x = rect.left() + (rect.width() - e.graphics().measure_string(text, font()).width()) / 2;
  auto text_y = rect.top() + (rect.height() - e.graphics().measure_string(text, font()).height()) / 2;
  e.graphics().draw_string(text, font(), solid_brush(text_color), text_x, text_y);
}

void form_minesweeper::draw_flag(paint_event_args& e, int x, int y, minesweeper::cell cell) {
  draw_border_unchecked(e, x, y);
  
  static image flag = bitmap(properties::resources::flag(), {16, 16});
  rectangle rect(x, y, cell::width(), cell::height());
  auto flag_x = rect.left() + (rect.width() - flag.width()) / 2;
  auto flag_y = rect.top() + (rect.height() - flag.height()) / 2;
  e.graphics().draw_image(flag, flag_x, flag_y);
}

void form_minesweeper::draw_question(paint_event_args& e, int x, int y, minesweeper::cell cell) {
  draw_border_unchecked(e, x, y);
  rectangle rect(x, y, cell::width(), cell::height());
  auto question_x = rect.left() + (rect.width() - e.graphics().measure_string("?", font()).width()) / 2;
  auto question_y = rect.top() + (rect.height() - e.graphics().measure_string("?", font()).height()) / 2;
  e.graphics().draw_string("?", font(), solid_brush(fore_color()), question_x, question_y);
}

void form_minesweeper::draw_mine(paint_event_args& e, int x, int y, minesweeper::cell cell) {
  draw_border_checked(e, x, y);
  rectangle rect(x, y, cell::width(), cell::height());
  static image mine = bitmap(properties::resources::mine(), {16, 16});
  auto mine_x = rect.left() + (rect.width() - mine.width()) / 2;
  auto mine_y = rect.top() + (rect.height() - mine.height()) / 2;
  e.graphics().draw_image(mine, mine_x, mine_y);
}

void form_minesweeper::draw_exploded_mine(paint_event_args& e, int x, int y, minesweeper::cell cell) {
  e.graphics().fill_rectangle(brushes::red(), x, y, cell::width(), cell::height());
  draw_mine(e, x, y, cell);
}

void form_minesweeper::draw_error(paint_event_args& e, int x, int y, minesweeper::cell cell) {
  draw_border_checked(e, x, y);
  draw_mine(e, x, y, cell);
  rectangle rect(x, y, cell::width(), cell::height());
  e.graphics().draw_line(pen(color::red, 3), rect.left() + 7, rect.top() + 7, rect.left() + rect.width() - 7, rect.top() + rect.height() - 7);
  e.graphics().draw_line(pen(color::red, 3), rect.left() + rect.width() - 7, rect.top() + 7, rect.left() + 7, rect.top() + rect.height() - 7);
}

void form_minesweeper::draw_border_unchecked(paint_event_args& e, int x, int y) {
  rectangle rect(x, y, cell::width(), cell::height());
  if (!properties::settings::default_settings().original_color()) {
    if (back_color().get_brightness() < 0.5f) e.graphics().fill_rectangle(solid_brush(color::light(back_color(), 0.1)), x, y, cell::width(), cell::height());
    else e.graphics().fill_rectangle(solid_brush(color::dark(back_color(), 0.1)), x, y, cell::width(), cell::height());
  }
  e.graphics().draw_line(pen(color::light(color::light(color::light(back_color())))), rect.left(), rect.top(), rect.left() + rect.width(), rect.top());
  e.graphics().draw_line(pen(color::light(color::light(back_color()))), rect.left(), rect.top() + 1, rect.left() + rect.width(), rect.top() + 1);
  e.graphics().draw_line(pen(color::light(back_color())), rect.left() + 1, rect.top() + 2, rect.left() + rect.width(), rect.top() + 2);
  
  e.graphics().draw_line(pen(color::light(color::light(color::light(back_color())))), rect.left(), rect.top(), rect.left(), rect.top() + rect.height());
  e.graphics().draw_line(pen(color::light(color::light(back_color()))), rect.left() + 1, rect.top() + 1, rect.left() + 1, rect.top() + rect.height());
  e.graphics().draw_line(pen(color::light(back_color())), rect.left() + 2, rect.top() + 2, rect.left() + 2, rect.top() + rect.height());
  
  e.graphics().draw_line(pen(color::dark(back_color())), rect.left() + 2, rect.top() + rect.height() - 3, rect.left() + rect.width(), rect.top() + rect.height() - 3);
  e.graphics().draw_line(pen(color::dark(color::dark(back_color()))), rect.left() + 1, rect.top() + rect.height() - 2, rect.left() + rect.width(), rect.top() + rect.height() - 2);
  e.graphics().draw_line(pen(color::dark(color::dark(color::dark(back_color())))), rect.left(), rect.top() + rect.height() - 1, rect.left() + rect.width(), rect.top() + rect.height() - 1);
  
  e.graphics().draw_line(pen(color::dark(back_color())), rect.left() + rect.width() - 3, rect.top() + 2, rect.left() + rect.width() - 3, rect.top() + rect.height() - 3);
  e.graphics().draw_line(pen(color::dark(color::dark(back_color()))), rect.left() + rect.width() - 2, rect.top() + 1, rect.left() + rect.width() - 2, rect.top() + rect.height() - 2);
  e.graphics().draw_line(pen(color::dark(color::dark(color::dark(back_color())))), rect.left() + rect.width() - 1, rect.top(), rect.left() + rect.width() - 1, rect.top() + rect.height() - 1);
}

void form_minesweeper::draw_border_checked(paint_event_args& e, int x, int y) {
  rectangle rect(x, y, cell::width(), cell::height());
  e.graphics().draw_line(pen(color::dark(back_color())), rect.left(), rect.top(), rect.left() + rect.width(), rect.top());
  e.graphics().draw_line(pen(color::dark(back_color())), rect.left(), rect.top(), rect.left(), rect.top() + rect.height());
  e.graphics().draw_line(pen(color::light(back_color())), rect.left() + 1, rect.top() + rect.height() - 1, rect.left() + rect.width(), rect.top() + rect.height() - 1);
  e.graphics().draw_line(pen(color::light(back_color())), rect.left() + rect.width() - 1, rect.top() + 1, rect.left() + rect.width() - 1, rect.top() + rect.height() - 1);
}

void form_minesweeper::on_game_panel_mouse_up(control& sender, const mouse_event_args& e) {
  if (game_over_) return;
  stopwatch.enabled(true);
  
  if (e.location().x() < 15 || e.location().y() < 15 || e.location().x() >= (grid_size_.width() * cell::width() + 15) || e.location().y() >= (grid_size_.height() * cell::height() + 15)) return;
  int x = (e.location().x() - 15) / cell::width();
  int y = (e.location().y() - 15) / cell::height();
  
  auto& cell = cells_[x][y];
  if (e.button() == mouse_buttons::right) {
    if (cell.state() == cell_state::unchecked) {
      cell.state(cell_state::flag);
      ++flagged_mine_count_;
    } else if (cell.state() == cell_state::flag && properties::settings::default_settings().marks()) {
      cell.state(cell_state::question);
      --flagged_mine_count_;
    } else if (cell.state() == cell_state::flag || cell.state() == cell_state::question) cell.state(cell_state::unchecked);
    if ((mine_count_ - flagged_mine_count_) >= 0 && (mine_count_ - flagged_mine_count_) <= 999) mine_count_label.text(strings::format("{:D3}", mine_count_ - flagged_mine_count_));
    else if (mine_count_ - flagged_mine_count_ >= -99) mine_count_label.text(strings::format("{:D2}", mine_count_ - flagged_mine_count_));
  } else if (e.button() == mouse_buttons::left) {
    start_game.image(bitmap(properties::resources::smiley4(), {24, 24}));
    application::do_events();
    if (cell.state() == cell_state::question) cell.state(cell_state::unchecked);
    if (cell.state() == cell_state::unchecked) {
      if (!cell.has_mine()) {
        check_neighbors({x, y});
        if (grid_size_.width() * grid_size_.height() - checked_cell_count_ == mine_count_) {
          stopwatch.enabled(false);
          game_over_ = true;
          start_game.image(bitmap(properties::resources::smiley3(), {24, 24}));
          for (int index1 = 0; index1 < grid_size_.height(); index1++)
            for (int index2 = 0; index2 <grid_size_.width(); index2++)
              if (cells_[index2][index1].state() != cell_state::flag && cells_[index2][index1].has_mine())
                cells_[index2][index1].state(cell_state::mine);
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
            if (cells_[index2][index1].state() == cell_state::flag && !cells_[index2][index1].has_mine())
              cells_[index2][index1].state(cell_state::error);
            if (cells_[index2][index1].state() != cell_state::flag && cells_[index2][index1].has_mine())
              cells_[index2][index1].state(cell_state::mine);
          }
        }
        cell.state(cell_state::exploded_mine);
      }
    }
  }
  invalidate();
}

void form_minesweeper::on_game_panel_paint(control& sender, paint_event_args& e) {
  e.graphics().clear(back_color());
  e.graphics().draw_line(pen(color::light(color::light(color::light(back_color())))), 0, 0, 0, e.clip_rectangle().height());
  e.graphics().draw_line(pen(color::light(color::light(back_color()))), 1, 0, 1, e.clip_rectangle().height());
  e.graphics().draw_line(pen(color::light(back_color())), 2, 0, 2, e.clip_rectangle().height());
  e.graphics().draw_line(pen(color::dark(back_color())), 2, e.clip_rectangle().height() - 3, e.clip_rectangle().width(), e.clip_rectangle().height() - 3);
  e.graphics().draw_line(pen(color::dark(color::dark(back_color()))), 1, e.clip_rectangle().height() - 2, e.clip_rectangle().width(), e.clip_rectangle().height() - 2);
  e.graphics().draw_line(pen(color::dark(color::dark(color::dark(back_color())))), 0, e.clip_rectangle().height() - 1, e.clip_rectangle().width(), e.clip_rectangle().height() - 1);
  e.graphics().draw_line(pen(color::dark(back_color())), e.clip_rectangle().width() - 3, 0, e.clip_rectangle().width() - 3, e.clip_rectangle().height() - 3);
  e.graphics().draw_line(pen(color::dark(color::dark(back_color()))), e.clip_rectangle().width() - 2, 0, e.clip_rectangle().width() - 2, e.clip_rectangle().height() - 2);
  e.graphics().draw_line(pen(color::dark(color::dark(color::dark(back_color())))), e.clip_rectangle().width() - 1, 0, e.clip_rectangle().width() - 1, e.clip_rectangle().height() - 1);
  
  auto offset = 12;
  e.graphics().draw_line(pen(color::dark(color::dark(color::dark(back_color())))), offset, offset, e.clip_rectangle().width() - 1 - offset, offset);
  e.graphics().draw_line(pen(color::dark(color::dark(back_color()))), offset, 1 + offset, e.clip_rectangle().width() - 1 - offset, 1 + offset);
  e.graphics().draw_line(pen(color::dark(back_color())), 1 + offset, 2 + offset, e.clip_rectangle().width() - 1 - offset, 2 + offset);
  e.graphics().draw_line(pen(color::dark(color::dark(color::dark(back_color())))), offset, offset, offset, e.clip_rectangle().height() - 1 - offset);
  e.graphics().draw_line(pen(color::dark(color::dark(back_color()))), 1 + offset, 1 + offset, 1 + offset, e.clip_rectangle().height() - 1 - offset);
  e.graphics().draw_line(pen(color::dark(back_color())), 2 + offset, 2 + offset, 2 + offset, e.clip_rectangle().height() - 1 - offset);
  e.graphics().draw_line(pen(color::light(back_color())), 2 + offset, e.clip_rectangle().height() - 3 - offset, e.clip_rectangle().width() - 1 - offset, e.clip_rectangle().height() - 3 - offset);
  e.graphics().draw_line(pen(color::light(color::light(back_color()))), 1 + offset, e.clip_rectangle().height() - 2 - offset, e.clip_rectangle().width() - 1 - offset, e.clip_rectangle().height() - 2 - offset);
  e.graphics().draw_line(pen(color::light(color::light(color::light(back_color())))), offset, e.clip_rectangle().height() - 1 - offset, e.clip_rectangle().width() - 1 - offset, e.clip_rectangle().height() - 1 - offset);
  e.graphics().draw_line(pen(color::light(back_color())), e.clip_rectangle().width() - 3 - offset, 2 + offset, e.clip_rectangle().width() - 3 - offset, e.clip_rectangle().height() - 3 - offset);
  e.graphics().draw_line(pen(color::light(color::light(back_color()))), e.clip_rectangle().width() - 2 - offset, 1 + offset, e.clip_rectangle().width() - 2 - offset, e.clip_rectangle().height() - 2 - offset);
  e.graphics().draw_line(pen(color::light(color::light(color::light(back_color())))), e.clip_rectangle().width() - 1 - offset, offset, e.clip_rectangle().width() - 1 - offset, e.clip_rectangle().height() - 1 - offset);
  
  for (auto y = 0; y < grid_size_.height(); y++)
    for (auto x = 0; x < grid_size_.width(); x++)
      draw_cell(e, 15 + x * cell::width(), 15 + y * cell::height(), cells_[x][y]);
}

void form_minesweeper::on_status_panel_paint(control& sender, paint_event_args& e) {
  e.graphics().clear(back_color());
  e.graphics().draw_line(pen(color::light(color::light(color::light(back_color())))), 0, 0, e.clip_rectangle().width(), 0);
  e.graphics().draw_line(pen(color::light(color::light(back_color()))), 0, 1, e.clip_rectangle().width(), 1);
  e.graphics().draw_line(pen(color::light(back_color())), 1, 2, e.clip_rectangle().width(), 2);
  e.graphics().draw_line(pen(color::light(color::light(color::light(back_color())))), 0, 0, 0, e.clip_rectangle().height());
  e.graphics().draw_line(pen(color::light(color::light(back_color()))), 1, 1, 1, e.clip_rectangle().height());
  e.graphics().draw_line(pen(color::light(back_color())), 2, 2, 2, e.clip_rectangle().height());
  e.graphics().draw_line(pen(color::dark(back_color())), e.clip_rectangle().width() - 3, 2, e.clip_rectangle().width() - 3, e.clip_rectangle().height());
  e.graphics().draw_line(pen(color::dark(color::dark(back_color()))), e.clip_rectangle().width() - 2, 1, e.clip_rectangle().width() - 2, e.clip_rectangle().height());
  e.graphics().draw_line(pen(color::dark(color::dark(color::dark(back_color())))), e.clip_rectangle().width() - 1, 0, e.clip_rectangle().width() - 1, e.clip_rectangle().height());
  
  auto offset = 12;
  e.graphics().draw_line(pen(color::dark(color::dark(color::dark(back_color())))), offset, offset, e.clip_rectangle().width() - 1 - offset, offset);
  e.graphics().draw_line(pen(color::dark(color::dark(back_color()))), offset, 1 + offset, e.clip_rectangle().width() - 1 - offset, 1 + offset);
  e.graphics().draw_line(pen(color::dark(back_color())), 1 + offset, 2 + offset, e.clip_rectangle().width() - 1 - offset, 2 + offset);
  e.graphics().draw_line(pen(color::dark(color::dark(color::dark(back_color())))), offset, offset, offset, e.clip_rectangle().height() - 1);
  e.graphics().draw_line(pen(color::dark(color::dark(back_color()))), 1 + offset, 1 + offset, 1 + offset, e.clip_rectangle().height() - 1);
  e.graphics().draw_line(pen(color::dark(back_color())), 2 + offset, 2 + offset, 2 + offset, e.clip_rectangle().height() - 1);
  e.graphics().draw_line(pen(color::light(back_color())), 2 + offset, e.clip_rectangle().height() - 3, e.clip_rectangle().width() - 1 - offset, e.clip_rectangle().height() - 3);
  e.graphics().draw_line(pen(color::light(color::light(back_color()))), 1 + offset, e.clip_rectangle().height() - 2, e.clip_rectangle().width() - 1 - offset, e.clip_rectangle().height() - 2);
  e.graphics().draw_line(pen(color::light(color::light(color::light(back_color())))), offset, e.clip_rectangle().height() - 1, e.clip_rectangle().width() - 1 - offset, e.clip_rectangle().height() - 1);
  e.graphics().draw_line(pen(color::light(back_color())), e.clip_rectangle().width() - 3 - offset, 2 + offset, e.clip_rectangle().width() - 3 - offset, e.clip_rectangle().height() - 3);
  e.graphics().draw_line(pen(color::light(color::light(back_color()))), e.clip_rectangle().width() - 2 - offset, 1 + offset, e.clip_rectangle().width() - 2 - offset, e.clip_rectangle().height() - 2);
  e.graphics().draw_line(pen(color::light(color::light(color::light(back_color())))), e.clip_rectangle().width() - 1 - offset, offset, e.clip_rectangle().width() - 1 - offset, e.clip_rectangle().height() - 1);
}

void form_minesweeper::on_status_panel_resize(control& sender, const event_args& e) {
  start_game.location({status_panel.size().width() / 2 - 21, 17});
  stopwatch_label.location({status_panel.width() - stopwatch_label.width() - 18, 17});
}

void form_minesweeper::on_stopwatch_tick() {
  if (stopwatch_count_ < 999)
    stopwatch_label.text(strings::format("{:D3}", ++stopwatch_count_));
}

void form_minesweeper::show_about_dialog() {
  about_dialog about_dialog;
  about_dialog.icon(properties::resources::minesweeper_png());
  about_dialog.name("Minesweeper"_t);
  about_dialog.version("1.0");
  about_dialog.long_version("1.0.0");
  about_dialog.description("The goal of the game is to uncover all the squares\nthat do not contain mines."_t);
  about_dialog.copyright("Copyright (c) 2021 Gammasoft.\nAll rights reserved."_t);
  about_dialog.website("https://gammasoft71.wixsite.com/gammasoft"_t);
  about_dialog.website_label("gammasoft website"_t);
  about_dialog.license("MIT License\n"
                       "\n"
                       "Copyright (c) 2021 Gammasoft.\n"
                       "\n"
                       "Permission is hereby granted, free of charge, to any person obtaining\n"
                       "a copy of this software and associated documentation files (the\n"
                       "\"Software\"), to deal in the Software without restriction, including\n"
                       "without limitation the rights to use, copy, modify, merge, publish,\n"
                       "distribute, sublicense, and/or sell copies of the Software, and to\n"
                       "permit persons to whom the Software is furnished to do so, subject\n"
                       "to the following conditions:\n"
                       "\n"
                       "The above copyright notice and this permission notice shall be\n"
                       "included in all copies or substantial portions of the Software.\n"
                       "\n"
                       "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF\n"
                       "ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO\n"
                       "THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A\n"
                       "PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT\n"
                       "SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR\n"
                       "ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN\n"
                       "ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n"
                       "OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE\n"
                       "OR OTHER DEALINGS IN THE SOFTWARE.\n");
  about_dialog.show();
}

void form_minesweeper::update_colors() {
  back_color(properties::settings::default_settings().original_color() ? color::from_argb(192, 196, 200) : default_back_color());
  fore_color(properties::settings::default_settings().original_color() ? color::black : default_fore_color());
}
