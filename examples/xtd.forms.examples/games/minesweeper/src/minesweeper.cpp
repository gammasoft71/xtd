#include <xtd/drawing/color_converter>
#include <xtd/forms/about_dialog>
#include <xtd/forms/tab_page>
#include <xtd/diagnostics/process>
#include <xtd/drawing/brushes>
#include <xtd/random>
#include "minesweeper.hpp"
#include "custom_field_dialog.hpp"
#include "input_name_dialog.hpp"

using namespace minesweeper;

void minesweeper_form::main() {
  application::run(minesweeper_form());
}

minesweeper_form::minesweeper_form() {
  auto_size_mode(forms::auto_size_mode::grow_and_shrink);
  auto_size(true);
  font(drawing::font(font(), 16, font_style::bold));
  icon(properties::resources::minesweeper_ico());
  menu(main_menu_);
  text("Minesweeper"_t);
  
  game_panel_.double_buffered(true);
  game_panel_.location({0, 60});
  game_panel_.parent(*this);
  game_panel_.mouse_up += {*this, &minesweeper_form::on_game_panel_mouse_up};
  game_panel_.paint += {*this, &minesweeper_form::on_game_panel_paint};
  
  status_panel_.height(60);
  status_panel_.parent(*this);
  status_panel_.paint += {*this, &minesweeper_form::on_status_panel_paint};
  status_panel_.resize += {*this, &minesweeper_form::on_status_panel_resize};
  
  mine_count_label_.auto_size(true);
  mine_count_label_.back_color(color::black);
  mine_count_label_.fore_color(color::red);
  mine_count_label_.height(38);
  mine_count_label_.location({17, 17});
  mine_count_label_.parent(status_panel_);
  mine_count_label_.segment_style(forms::segment_style::modern);
  mine_count_label_.text("000");
  mine_count_label_.thickness(5);
  
  stopwatch_label_.parent(status_panel_);
  stopwatch_label_.height(38);
  stopwatch_label_.auto_size(true);
  stopwatch_label_.back_color(color::black);
  stopwatch_label_.fore_color(color::red);
  stopwatch_label_.segment_style(forms::segment_style::modern);
  stopwatch_label_.text("000");
  stopwatch_label_.thickness(5);
  
  start_game_.parent(status_panel_);
  start_game_.image(bitmap {properties::resources::smiley1(), {24, 24}});
  start_game_.size({42, 38});
  start_game_.location({status_panel_.size().width / 2 - 21, 17});
  start_game_.click += {*this, &minesweeper_form::new_game};
  
  stopwatch_timer_.interval_milliseconds(1000);
  stopwatch_timer_.tick += {*this, &minesweeper_form::on_stopwatch_tick};
  
  update_colors();
  change_level(as<level>(properties::settings::default_settings().level()));
}

void minesweeper_form::change_level(level l) {
  properties::settings::default_settings().level(l);
  properties::settings::default_settings().save();
  
  level_ = l;
  cells_.clear();
  grid_size_ = std::map<minesweeper::level, grid_size> {{minesweeper::level::beginner, {9, 9}}, {minesweeper::level::intermediate, {16, 16}}, {minesweeper::level::expert, {30, 16}}, {minesweeper::level::custom, {properties::settings::default_settings().custom_width(), properties::settings::default_settings().custom_height()}}} [level_];
  mine_count_ = std::map<minesweeper::level, int> {{minesweeper::level::beginner, 10}, {minesweeper::level::intermediate, 40}, {minesweeper::level::expert, 99}, {minesweeper::level::custom, properties::settings::default_settings().custom_mines()}} [level_];
  
  game_panel_.size({30 + grid_size_.width * cell::width(), 30 + grid_size_.height * cell::height()});
  cells_ = row_cell(grid_size_.width, column_cell(grid_size_.height));
  status_panel_.width(game_panel_.width());
  new_game();
}

void minesweeper_form::new_game() {
  game_over_ = false;
  stopwatch_timer_.enabled(false);
  checked_cell_count_ = 0;
  flagged_mine_count_ = 0;
  stopwatch_count_ = 0;
  for (auto y = 0; y < grid_size_.height; ++y)
    for (auto x = 0; x < grid_size_.width; ++x)
      cells_[x][y].clear();
      
  xtd::random rand;
  for (auto count = 0; count < mine_count_; ++count) {
    auto x = rand.next(0, grid_size_.width - 1);
    auto y = rand.next(0, grid_size_.height - 1);
    
    if (cells_[x][y].contains_mine()) {
      count--;
      continue;
    }
    cells_[x][y].has_mine(true);
  }
  
  for (auto y = 0; y < grid_size_.height; ++y)
    for (auto x = 0; x < grid_size_.width; ++x)
      for (auto yy = y - 1; yy <= y + 1; ++yy)
        for (auto xx = x - 1; xx <= x + 1; ++xx)
          if (yy >= 0 && yy < grid_size_.height && xx >= 0 && xx < grid_size_.width && cells_[xx][yy].contains_mine())
            cells_[x][y].neighbors(cells_[x][y].number_of_neighbouring_mines() + 1);
            
  mine_count_label_.text(string::format("{:D3}", mine_count_ - flagged_mine_count_));
  stopwatch_label_.text("000");
  start_game_.image(bitmap {properties::resources::smiley1(), {24, 24}});
  invalidate();
}

void minesweeper_form::check_neighbors(const point& cell_location) {
  if (checked_cell(cell_location) != 0) return;
  for (auto y = cell_location.y - 1; y <= cell_location.y + 1; ++y)
    for (auto x = cell_location.x - 1; x <= cell_location.x + 1; ++x)
      if (y >= 0 && y < grid_size_.height && x >= 0 && x < grid_size_.width && cells_[x][y].state() == cell_state::unchecked && checked_cell({x, y}) == 0)
        check_neighbors({x, y});
}

int minesweeper_form::checked_cell(const point& cell_location) {
  if (cells_[cell_location.x][cell_location.y].state() == cell_state::unchecked) {
    cells_[cell_location.x][cell_location.y].state(cell_state::checked);
    checked_cell_count_++;
  }
  return cells_[cell_location.x][cell_location.y].number_of_neighbouring_mines();
}

void minesweeper_form::draw_cell(paint_event_args& e, const rectangle& clip_rectangle, minesweeper::cell cell) {
  static std::map<cell_state, delegate<void(paint_event_args&, const rectangle&, minesweeper::cell)>> draw_state {{cell_state::unchecked, {*this, &minesweeper_form::draw_unchecked}}, {cell_state::checked, {*this, &minesweeper_form::draw_checked}}, {cell_state::flag, {*this, &minesweeper_form::draw_flag}}, {cell_state::question, {*this, &minesweeper_form::draw_question}}, {cell_state::mine, {*this, &minesweeper_form::draw_mine}}, {cell_state::exploded_mine, {*this, &minesweeper_form::draw_exploded_mine}}, {cell_state::error, {*this, &minesweeper_form::draw_error}}};
  draw_state[cell.state()](e, clip_rectangle, cell);
}

void minesweeper_form::draw_unchecked(paint_event_args& e, const rectangle& clip_rectangle, minesweeper::cell cell) {
  draw_border_unchecked(e, clip_rectangle);
}

void minesweeper_form::draw_checked(paint_event_args& e, const rectangle& clip_rectangle, minesweeper::cell cell) {
  draw_border_checked(e, clip_rectangle);
  color text_color;
  
  if (properties::settings::default_settings().original_color()) {
    switch (cell.number_of_neighbouring_mines()) {
      case 1: text_color = color::blue; break;
      case 2: text_color = color::green; break;
      case 3: text_color = color::red; break;
      case 4: text_color = color::dark_blue; break;
      case 5: text_color = color::dark_red; break;
      case 6: text_color = color::teal; break;
      case 7: text_color = color::dark_magenta; break;
      case 8: text_color = color::black; break;
      default: return;
    }
  } else if (back_color().get_brightness() < 0.5f) {
    switch (cell.number_of_neighbouring_mines()) {
      case 1: text_color = color::light_sky_blue; break;
      case 2: text_color = color::from_argb(0x30, 0xDC, 0x66); break;
      case 3: text_color = color::from_argb(0xD0, 0x3E, 0x3D); break;
      case 4: text_color = color::dodger_blue; break;
      case 5: text_color = color::orange; break;
      case 6: text_color = color::light_sea_green; break;
      case 7: text_color = color::from_argb(0xC6, 0x5E, 0xE9); break;
      case 8: text_color = fore_color(); break;
      default: return;
    }
  } else {
    switch (cell.number_of_neighbouring_mines()) {
      case 1: text_color = color::blue; break;
      case 2: text_color = color::green; break;
      case 3: text_color = color::red; break;
      case 4: text_color = color::dodger_blue; break;
      case 5: text_color = color::dark_orange; break;
      case 6: text_color = color::teal; break;
      case 7: text_color = color::dark_magenta; break;
      case 8: text_color = fore_color(); break;
      default: return;
    }
  }
  auto text = std::to_string(cell.number_of_neighbouring_mines());
  auto x = clip_rectangle.left() + (clip_rectangle.width - e.graphics().measure_string(text, font()).width) / 2;
  auto y = clip_rectangle.top() + (clip_rectangle.height - e.graphics().measure_string(text, font()).height) / 2;
  e.graphics().draw_string(text, font(), solid_brush(text_color), x, y);
}

void minesweeper_form::draw_flag(paint_event_args& e, const rectangle& clip_rectangle, minesweeper::cell cell) {
  draw_border_unchecked(e, clip_rectangle);
  
  static auto flag = bitmap {properties::resources::flag(), {16, 16}};
  auto x = clip_rectangle.left() + (clip_rectangle.width - flag.width()) / 2;
  auto y = clip_rectangle.top() + (clip_rectangle.height - flag.height()) / 2;
  e.graphics().draw_image(flag, x, y);
}

void minesweeper_form::draw_question(paint_event_args& e, const rectangle& clip_rectangle, minesweeper::cell cell) {
  draw_border_unchecked(e, clip_rectangle);
  auto x = clip_rectangle.left() + (clip_rectangle.width - e.graphics().measure_string("?", font()).width) / 2;
  auto y = clip_rectangle.top() + (clip_rectangle.height - e.graphics().measure_string("?", font()).height) / 2;
  auto question_color = back_color().get_brightness() < 0.5f ? color::light_sky_blue : color::blue;
  e.graphics().draw_string("?", font(), solid_brush(question_color), x, y);
}

void minesweeper_form::draw_mine(paint_event_args& e, const rectangle& clip_rectangle, minesweeper::cell cell) {
  draw_border_checked(e, clip_rectangle);
  static auto mine = bitmap {properties::resources::mine(), {16, 16}};
  auto x = clip_rectangle.left() + (clip_rectangle.width - mine.width()) / 2;
  auto y = clip_rectangle.top() + (clip_rectangle.height - mine.height()) / 2;
  e.graphics().draw_image(mine, x, y);
}

void minesweeper_form::draw_exploded_mine(paint_event_args& e, const rectangle& clip_rectangle, minesweeper::cell cell) {
  e.graphics().fill_rectangle(brushes::red(), clip_rectangle);
  draw_mine(e, clip_rectangle, cell);
}

void minesweeper_form::draw_error(paint_event_args& e, const rectangle& clip_rectangle, minesweeper::cell cell) {
  draw_border_checked(e, clip_rectangle);
  draw_mine(e, clip_rectangle, cell);
  e.graphics().draw_line(pen {color::red, 3}, clip_rectangle.left() + 7, clip_rectangle.top() + 7, clip_rectangle.right() - 7, clip_rectangle.bottom() - 7);
  e.graphics().draw_line(pen {color::red, 3}, clip_rectangle.right() - 7, clip_rectangle.top() + 7, clip_rectangle.left() + 7, clip_rectangle.bottom() - 7);
}

void minesweeper_form::draw_border_unchecked(paint_event_args& e, const rectangle& clip_rectangle) {
  if (!properties::settings::default_settings().original_color()) {
    if (back_color().get_brightness() < 0.5f) e.graphics().fill_rectangle(solid_brush {color_converter::light(back_color(), 0.1)}, clip_rectangle);
    else e.graphics().fill_rectangle(solid_brush {color_converter::dark(back_color(), 0.1)}, clip_rectangle);
  }
  e.graphics().draw_line(pen {color_converter::light(color_converter::light(color_converter::light(back_color())))}, clip_rectangle.left(), clip_rectangle.top(), clip_rectangle.right(), clip_rectangle.top());
  e.graphics().draw_line(pen {color_converter::light(color_converter::light(back_color()))}, clip_rectangle.left(), clip_rectangle.top() + 1, clip_rectangle.right(), clip_rectangle.top() + 1);
  e.graphics().draw_line(pen {color_converter::light(back_color())}, clip_rectangle.left() + 1, clip_rectangle.top() + 2, clip_rectangle.right(), clip_rectangle.top() + 2);
  
  e.graphics().draw_line(pen {color_converter::light(color_converter::light(color_converter::light(back_color())))}, clip_rectangle.left(), clip_rectangle.top(), clip_rectangle.left(), clip_rectangle.bottom());
  e.graphics().draw_line(pen {color_converter::light(color_converter::light(back_color()))}, clip_rectangle.left() + 1, clip_rectangle.top() + 1, clip_rectangle.left() + 1, clip_rectangle.bottom());
  e.graphics().draw_line(pen {color_converter::light(back_color())}, clip_rectangle.left() + 2, clip_rectangle.top() + 2, clip_rectangle.left() + 2, clip_rectangle.bottom());
  
  e.graphics().draw_line(pen {color_converter::dark(back_color())}, clip_rectangle.left() + 2, clip_rectangle.bottom() - 3, clip_rectangle.right(), clip_rectangle.bottom() - 3);
  e.graphics().draw_line(pen {color_converter::dark(color_converter::dark(back_color()))}, clip_rectangle.left() + 1, clip_rectangle.bottom() - 2, clip_rectangle.right(), clip_rectangle.bottom() - 2);
  e.graphics().draw_line(pen {color_converter::dark(color_converter::dark(color_converter::dark(back_color())))}, clip_rectangle.left(), clip_rectangle.bottom() - 1, clip_rectangle.right(), clip_rectangle.bottom() - 1);
  
  e.graphics().draw_line(pen {color_converter::dark(back_color())}, clip_rectangle.right() - 3, clip_rectangle.top() + 2, clip_rectangle.right() - 3, clip_rectangle.bottom() - 3);
  e.graphics().draw_line(pen {color_converter::dark(color_converter::dark(back_color()))}, clip_rectangle.right() - 2, clip_rectangle.top() + 1, clip_rectangle.right() - 2, clip_rectangle.bottom() - 2);
  e.graphics().draw_line(pen {color_converter::dark(color_converter::dark(color_converter::dark(back_color())))}, clip_rectangle.right() - 1, clip_rectangle.top(), clip_rectangle.right() - 1, clip_rectangle.bottom() - 1);
}

void minesweeper_form::draw_border_checked(paint_event_args& e, const rectangle& clip_rectangle) {
  e.graphics().draw_line(pen {color_converter::dark(back_color())}, clip_rectangle.left(), clip_rectangle.top(), clip_rectangle.right(), clip_rectangle.top());
  e.graphics().draw_line(pen {color_converter::dark(back_color())}, clip_rectangle.left(), clip_rectangle.top(), clip_rectangle.left(), clip_rectangle.bottom());
  e.graphics().draw_line(pen {color_converter::light(back_color())}, clip_rectangle.left() + 1, clip_rectangle.bottom() - 1, clip_rectangle.right(), clip_rectangle.bottom() - 1);
  e.graphics().draw_line(pen {color_converter::light(back_color())}, clip_rectangle.right() - 1, clip_rectangle.top() + 1, clip_rectangle.right() - 1, clip_rectangle.bottom() - 1);
}

void minesweeper_form::game_over() {
  stopwatch_timer_.enabled(false);
  game_over_ = true;
  start_game_.image(bitmap {properties::resources::smiley2(), {24, 24}});
  for (auto y = 0; y < grid_size_.height; ++y) {
    for (auto x = 0; x < grid_size_.width; ++x) {
      if (cells_[x][y].state() == cell_state::exploded_mine) continue;
      if (cells_[x][y].state() == cell_state::flag && !cells_[x][y].contains_mine())
        cells_[x][y].state(cell_state::error);
      if (cells_[x][y].state() != cell_state::flag && cells_[x][y].contains_mine())
        cells_[x][y].state(cell_state::mine);
    }
  }
}

void minesweeper_form::mark_cell(int x, int y) {
  auto& cell = cells_[x][y];
  if (cell.state() == cell_state::unchecked) {
    cell.state(cell_state::flag);
    ++flagged_mine_count_;
  } else if (cell.state() == cell_state::flag && properties::settings::default_settings().marks()) {
    cell.state(cell_state::question);
    --flagged_mine_count_;
  } else if (cell.state() == cell_state::flag || cell.state() == cell_state::question) cell.state(cell_state::unchecked);
  if ((mine_count_ - flagged_mine_count_) >= 0 && (mine_count_ - flagged_mine_count_) <= 999) mine_count_label_.text(string::format("{:D3}", mine_count_ - flagged_mine_count_));
  else if (mine_count_ - flagged_mine_count_ >= -99) mine_count_label_.text(string::format("{:D2}", mine_count_ - flagged_mine_count_));
  invalidate();
}

void minesweeper_form::on_about_menu_click(object& sender, const xtd::event_args& e) {
  static auto dialog = about_dialog {};
  static auto information_page = tab_page::create("Information");
  information_page.auto_scroll(true);
  static auto information_label = label::create(information_page,
                                                "The goal of the game is to uncover all the squares that do not contain\n"
                                                "mines.\n"
                                                "\n"
                                                "To mark a mine use right click. Minesweeper is one of the most\n"
                                                "interesting logic games.\n"
                                                "\n"
                                                "The objective of the game is to clear a rectangular board containing\n"
                                                "hidden \"mines\" or landmine without detonating any of them, with help\n"
                                                "from clues about the number of neighboring landmine in each field.\n"
                                                "\n"
                                                "Minesweeper features:\n"
                                                "\n"
                                                "  • Variable minefield.\n"
                                                "  • Very addictive puzzle.\n"
                                                "  • Its a real classic minesweeper free.\n"
                                                "  • Adapted to the screen.\n"
                                                "\n"
                                                "If you like minesweeper, you're going to love this game!\n"
                                                "\n\n");
  information_label.left(5);
  information_label.auto_size(true);
  dialog.icon(properties::resources::minesweeper_png());
  dialog.name("Minesweeper"_t);
  dialog.version("1.0");
  dialog.long_version("1.0.0");
  dialog.description("The goal of the game is to uncover all the squares\nthat do not contain mines."_t);
  dialog.copyright("Copyright (c) 2024 Gammasoft.\nAll rights reserved."_t);
  dialog.user_tab_pages().push_back(information_page);
  dialog.website("https://gammasoft71.github.io"_t);
  dialog.website_label("gammasoft website"_t);
  dialog.license("MIT License\n"
    "\n"
    "Copyright (c) 2024 Gammasoft.\n"
    "\n"
    "Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the \"Software\"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:\n"
    "\n"
    "The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.\n"
    "\n"
    "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.\n");
  dialog.show();
}

void minesweeper_form::on_help_content_menu_click(object& sender, const xtd::event_args& e) {
  diagnostics::process::start(diagnostics::process_start_info {"https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/games/minesweeper/resources/help.md"}.use_shell_execute(true));
}

void minesweeper_form::on_custom_menu_click(object& sender, const xtd::event_args& e) {
  auto dialog = custom_field_dialog {};
  dialog.custom_height(properties::settings::default_settings().custom_height());
  dialog.custom_width(properties::settings::default_settings().custom_width());
  dialog.custom_mines(properties::settings::default_settings().custom_mines());
  dialog.show_dialog(*this);
  properties::settings::default_settings().custom_height(dialog.custom_heght());
  properties::settings::default_settings().custom_width(dialog.custom_width());
  properties::settings::default_settings().custom_mines(dialog.custom_mines());
  properties::settings::default_settings().save();
  change_level(level::custom);
}

void minesweeper_form::on_game_panel_mouse_up(object& sender, const mouse_event_args& e) {
  if (game_over_) return;
  stopwatch_timer_.enabled(true);
  
  if (e.location().x < 15 || e.location().y < 15 || e.location().x >= (grid_size_.width * cell::width() + 15) || e.location().y >= (grid_size_.height * cell::height() + 15)) return;
  auto x = (e.location().x - 15) / cell::width();
  auto y = (e.location().y - 15) / cell::height();
  
  if (e.button() == mouse_buttons::right) mark_cell(x, y);
  else if (e.button() == mouse_buttons::left) uncover_cell(x, y);
}

void minesweeper_form::on_game_panel_paint(object& sender, paint_event_args& e) {
  e.graphics().clear(back_color());
  e.graphics().draw_line(pen {color_converter::light(color_converter::light(color_converter::light(back_color())))}, 0, 0, 0, e.clip_rectangle().height);
  e.graphics().draw_line(pen {color_converter::light(color_converter::light(back_color()))}, 1, 0, 1, e.clip_rectangle().height);
  e.graphics().draw_line(pen {color_converter::light(back_color())}, 2, 0, 2, e.clip_rectangle().height);
  e.graphics().draw_line(pen {color_converter::dark(back_color())}, 2, e.clip_rectangle().height - 3, e.clip_rectangle().width, e.clip_rectangle().height - 3);
  e.graphics().draw_line(pen {color_converter::dark(color_converter::dark(back_color()))}, 1, e.clip_rectangle().height - 2, e.clip_rectangle().width, e.clip_rectangle().height - 2);
  e.graphics().draw_line(pen {color_converter::dark(color_converter::dark(color_converter::dark(back_color())))}, 0, e.clip_rectangle().height - 1, e.clip_rectangle().width, e.clip_rectangle().height - 1);
  e.graphics().draw_line(pen {color_converter::dark(back_color())}, e.clip_rectangle().width - 3, 0, e.clip_rectangle().width - 3, e.clip_rectangle().height - 3);
  e.graphics().draw_line(pen {color_converter::dark(color_converter::dark(back_color()))}, e.clip_rectangle().width - 2, 0, e.clip_rectangle().width - 2, e.clip_rectangle().height - 2);
  e.graphics().draw_line(pen {color_converter::dark(color_converter::dark(color_converter::dark(back_color())))}, e.clip_rectangle().width - 1, 0, e.clip_rectangle().width - 1, e.clip_rectangle().height - 1);
  
  auto offset = 12;
  e.graphics().draw_line(pen {color_converter::dark(color_converter::dark(color_converter::dark(back_color())))}, offset, offset, e.clip_rectangle().width - 1 - offset, offset);
  e.graphics().draw_line(pen {color_converter::dark(color_converter::dark(back_color()))}, offset, 1 + offset, e.clip_rectangle().width - 1 - offset, 1 + offset);
  e.graphics().draw_line(pen {color_converter::dark(back_color())}, 1 + offset, 2 + offset, e.clip_rectangle().width - 1 - offset, 2 + offset);
  e.graphics().draw_line(pen {color_converter::dark(color_converter::dark(color_converter::dark(back_color())))}, offset, offset, offset, e.clip_rectangle().height - 1 - offset);
  e.graphics().draw_line(pen {color_converter::dark(color_converter::dark(back_color()))}, 1 + offset, 1 + offset, 1 + offset, e.clip_rectangle().height - 1 - offset);
  e.graphics().draw_line(pen {color_converter::dark(back_color())}, 2 + offset, 2 + offset, 2 + offset, e.clip_rectangle().height - 1 - offset);
  e.graphics().draw_line(pen {color_converter::light(back_color())}, 2 + offset, e.clip_rectangle().height - 3 - offset, e.clip_rectangle().width - 1 - offset, e.clip_rectangle().height - 3 - offset);
  e.graphics().draw_line(pen {color_converter::light(color_converter::light(back_color()))}, 1 + offset, e.clip_rectangle().height - 2 - offset, e.clip_rectangle().width - 1 - offset, e.clip_rectangle().height - 2 - offset);
  e.graphics().draw_line(pen {color_converter::light(color_converter::light(color_converter::light(back_color())))}, offset, e.clip_rectangle().height - 1 - offset, e.clip_rectangle().width - 1 - offset, e.clip_rectangle().height - 1 - offset);
  e.graphics().draw_line(pen {color_converter::light(back_color())}, e.clip_rectangle().width - 3 - offset, 2 + offset, e.clip_rectangle().width - 3 - offset, e.clip_rectangle().height - 3 - offset);
  e.graphics().draw_line(pen {color_converter::light(color_converter::light(back_color()))}, e.clip_rectangle().width - 2 - offset, 1 + offset, e.clip_rectangle().width - 2 - offset, e.clip_rectangle().height - 2 - offset);
  e.graphics().draw_line(pen {color_converter::light(color_converter::light(color_converter::light(back_color())))}, e.clip_rectangle().width - 1 - offset, offset, e.clip_rectangle().width - 1 - offset, e.clip_rectangle().height - 1 - offset);
  
  for (auto y = 0; y < grid_size_.height; ++y)
    for (auto x = 0; x < grid_size_.width; ++x)
      draw_cell(e, {15 + x * cell::width(), 15 + y * cell::height(), cell::width(), cell::height()}, cells_[x][y]);
}

void minesweeper_form::on_marks_menu_click(object& sender, const xtd::event_args& e) {
  properties::settings::default_settings().marks(!properties::settings::default_settings().marks());
  properties::settings::default_settings().save();
}

void minesweeper_form::on_original_color_menu_click(object& sender, const xtd::event_args& e) {
  properties::settings::default_settings().original_color(!properties::settings::default_settings().original_color());
  properties::settings::default_settings().save();
  update_colors();
}

void minesweeper_form::on_status_panel_paint(object& sender, paint_event_args& e) {
  e.graphics().clear(back_color());
  e.graphics().draw_line(pen {color_converter::light(color_converter::light(color_converter::light(back_color())))}, 0, 0, e.clip_rectangle().width, 0);
  e.graphics().draw_line(pen {color_converter::light(color_converter::light(back_color()))}, 0, 1, e.clip_rectangle().width, 1);
  e.graphics().draw_line(pen {color_converter::light(back_color())}, 1, 2, e.clip_rectangle().width, 2);
  e.graphics().draw_line(pen {color_converter::light(color_converter::light(color_converter::light(back_color())))}, 0, 0, 0, e.clip_rectangle().height);
  e.graphics().draw_line(pen {color_converter::light(color_converter::light(back_color()))}, 1, 1, 1, e.clip_rectangle().height);
  e.graphics().draw_line(pen {color_converter::light(back_color())}, 2, 2, 2, e.clip_rectangle().height);
  e.graphics().draw_line(pen {color_converter::dark(back_color())}, e.clip_rectangle().width - 3, 2, e.clip_rectangle().width - 3, e.clip_rectangle().height);
  e.graphics().draw_line(pen {color_converter::dark(color_converter::dark(back_color()))}, e.clip_rectangle().width - 2, 1, e.clip_rectangle().width - 2, e.clip_rectangle().height);
  e.graphics().draw_line(pen {color_converter::dark(color_converter::dark(color_converter::dark(back_color())))}, e.clip_rectangle().width - 1, 0, e.clip_rectangle().width - 1, e.clip_rectangle().height);
  
  auto offset = 12;
  e.graphics().draw_line(pen {color_converter::dark(color_converter::dark(color_converter::dark(back_color())))}, offset, offset, e.clip_rectangle().width - 1 - offset, offset);
  e.graphics().draw_line(pen {color_converter::dark(color_converter::dark(back_color()))}, offset, 1 + offset, e.clip_rectangle().width - 1 - offset, 1 + offset);
  e.graphics().draw_line(pen {color_converter::dark(back_color())}, 1 + offset, 2 + offset, e.clip_rectangle().width - 1 - offset, 2 + offset);
  e.graphics().draw_line(pen {color_converter::dark(color_converter::dark(color_converter::dark(back_color())))}, offset, offset, offset, e.clip_rectangle().height - 1);
  e.graphics().draw_line(pen {color_converter::dark(color_converter::dark(back_color()))}, 1 + offset, 1 + offset, 1 + offset, e.clip_rectangle().height - 1);
  e.graphics().draw_line(pen {color_converter::dark(back_color())}, 2 + offset, 2 + offset, 2 + offset, e.clip_rectangle().height - 1);
  e.graphics().draw_line(pen {color_converter::light(back_color())}, 2 + offset, e.clip_rectangle().height - 3, e.clip_rectangle().width - 1 - offset, e.clip_rectangle().height - 3);
  e.graphics().draw_line(pen {color_converter::light(color_converter::light(back_color()))}, 1 + offset, e.clip_rectangle().height - 2, e.clip_rectangle().width - 1 - offset, e.clip_rectangle().height - 2);
  e.graphics().draw_line(pen {color_converter::light(color_converter::light(color_converter::light(back_color())))}, offset, e.clip_rectangle().height - 1, e.clip_rectangle().width - 1 - offset, e.clip_rectangle().height - 1);
  e.graphics().draw_line(pen {color_converter::light(back_color())}, e.clip_rectangle().width - 3 - offset, 2 + offset, e.clip_rectangle().width - 3 - offset, e.clip_rectangle().height - 3);
  e.graphics().draw_line(pen {color_converter::light(color_converter::light(back_color()))}, e.clip_rectangle().width - 2 - offset, 1 + offset, e.clip_rectangle().width - 2 - offset, e.clip_rectangle().height - 2);
  e.graphics().draw_line(pen {color_converter::light(color_converter::light(color_converter::light(back_color())))}, e.clip_rectangle().width - 1 - offset, offset, e.clip_rectangle().width - 1 - offset, e.clip_rectangle().height - 1);
}

void minesweeper_form::on_status_panel_resize(object& sender, const event_args& e) {
  start_game_.location({status_panel_.size().width / 2 - 21, 17});
  stopwatch_label_.location({status_panel_.width() - stopwatch_label_.width() - 18, 17});
}

void minesweeper_form::on_stopwatch_tick() {
  if (stopwatch_count_ < 999)
    stopwatch_label_.text(string::format("{:D3}", ++stopwatch_count_));
}

void minesweeper_form::uncover_cell(int x, int y) {
  start_game_.image(bitmap(properties::resources::smiley4(), {24, 24}));
  application::do_events();
  if (cells_[x][y].state() == cell_state::question)
    cells_[x][y].state(cell_state::unchecked);
  if (cells_[x][y].state() == cell_state::unchecked) {
    if (cells_[x][y].contains_mine()) {
      cells_[x][y].state(cell_state::exploded_mine);
      game_over();
    } else {
      check_neighbors({x, y});
      if (grid_size_.width * grid_size_.height - checked_cell_count_ != mine_count_) start_game_.image(bitmap(properties::resources::smiley1(), {24, 24}));
      else you_win();
    }
    invalidate();
  }
}

void minesweeper_form::update_colors() {
  back_color(properties::settings::default_settings().original_color() ? color::from_argb(192, 196, 200) : default_back_color());
  fore_color(properties::settings::default_settings().original_color() ? color::black : default_fore_color());
}

void minesweeper_form::you_win() {
  stopwatch_timer_.enabled(false);
  game_over_ = true;
  for (auto y = 0; y < grid_size_.height; ++y)
    for (auto x = 0; x < grid_size_.width; ++x)
      if (cells_[x][y].state() != cell_state::flag && cells_[x][y].contains_mine())
        cells_[x][y].state(cell_state::mine);
        
  start_game_.image(bitmap(properties::resources::smiley3(), {24, 24}));
  mine_count_label_.text("000");
  
  if (level_ != level::custom && stopwatch_count_ < std::map<level, int> {{level::beginner, properties::settings::default_settings().beginner_high_scores_value()}, {level::intermediate, properties::settings::default_settings().intermediate_high_scores_value()}, {level::expert, properties::settings::default_settings().expert_high_scores_value()}} [level_]) {
    auto gamer_name = std::map<level, string> {{level::beginner, properties::settings::default_settings().beginner_high_scores_name()}, {level::intermediate, properties::settings::default_settings().intermediate_high_scores_name()}, {level::expert, properties::settings::default_settings().expert_high_scores_name()}} [level_];
    minesweeper::input_name_dialog input_name_dialog;
    input_name_dialog.gammer_name(gamer_name);
    input_name_dialog.level(level_);
    if (input_name_dialog.show_dialog(*this) == dialog_result::ok)
      gamer_name = input_name_dialog.gammer_name();
      
    std::map<level, delegate<void(int)>> set_settings_high_scores_values {{level::beginner, {[](int value) {properties::settings::default_settings().beginner_high_scores_value(value);}}}, {level::intermediate, {[](int value) {properties::settings::default_settings().intermediate_high_scores_value(value);}}}, {level::expert, {[](int value) {properties::settings::default_settings().expert_high_scores_value(value);}}}};
    std::map<level, delegate<void(string)>> set_settings_high_scores_names {{level::beginner, {[](string name) {properties::settings::default_settings().beginner_high_scores_name(name);}}}, {level::intermediate, {[](string name) {properties::settings::default_settings().intermediate_high_scores_name(name);}}}, {level::expert, {[](string name) {properties::settings::default_settings().expert_high_scores_name(name);}}}};
    set_settings_high_scores_values[level_](stopwatch_count_);
    set_settings_high_scores_names[level_](gamer_name);
    properties::settings::default_settings().save();
    
    minesweeper::high_scores_dialog().show_sheet_dialog(*this);
  }
}
