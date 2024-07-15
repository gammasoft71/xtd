#include "board_control.h"

using namespace tetris;
using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::forms;

board_control::board_control(status_bar& status_bar) : status_bar_ {status_bar} {
  static constexpr int block_size = 30;
  size({board_width * block_size, board_height * block_size});
  timer_.interval_milliseconds(300);
  timer_.tick += {*this, &board_control::on_tick};
}

void board_control::start() {
  if (paused_) return;
  
  timer_.stop();
  started_ = true;
  falling_finished_ = false;
  num_lines_removed_ = 0;
  cur_x_ = 0;
  cur_y_ = 0;
  
  clear_board();
  
  status_bar_.text(ustring::format("{}", num_lines_removed_));
  new_piece();
  timer_.start();
}

void board_control::pause() {
  if (!started_) return;
  
  paused_ = !paused_;
  if (paused_) {
    timer_.stop();
    status_bar_.text("paused"_t);
  } else {
    timer_.start();
    status_bar_.text(ustring::format("{}", num_lines_removed_));
  }
  refresh();
}

void board_control::clear_board() {
  for (auto i = 0; i < board_height * board_width; ++i)
    board_[i] = tetrominoes::no_shape;
}

void board_control::draw_square(graphics& graphics, int x, int y, tetris::tetrominoes tetrominoes) {
  static const auto colors = list<color> {color::from_argb(0, 0, 0), color::from_argb(204, 102, 102), color::from_argb(102, 204, 102), color::from_argb(102, 102, 204), color::from_argb(204, 204, 102), color::from_argb(204, 102, 204), color::from_argb(102, 204, 204), color::from_argb(218, 170, 0)};
  static const auto lights = list<color> {color::from_argb(0, 0, 0), color::from_argb(248, 159, 171), color::from_argb(121, 252, 121), color::from_argb(121, 121, 252), color::from_argb(252, 252, 121), color::from_argb(252, 121, 252), color::from_argb(121, 252, 252), color::from_argb(252, 198, 0)};
  static const auto darks = list<color> {color::from_argb(0, 0, 0), color::from_argb(128, 59, 59), color::from_argb(59, 128, 59), color::from_argb(59, 59, 128), color::from_argb(128, 128, 59), color::from_argb(128, 59, 128), color::from_argb(59, 128, 128), color::from_argb(128, 98, 0)};
  
  auto pen = drawing::pen {lights[as<int>(tetrominoes)]};
  pen.start_cap(line_cap::square);
  pen.end_cap(line_cap::square);
  
  graphics.draw_line(pen, x, y + square_height() - 1, x, y);
  graphics.draw_line(pen, x, y, x + square_width() - 1, y);
  
  pen = drawing::pen {darks[as<int>(tetrominoes)]};
  pen.start_cap(line_cap::square);
  pen.end_cap(line_cap::square);
  
  graphics.draw_line(pen, x + 1, y + square_height() - 1, x + square_width() - 1, y + square_height() - 1);
  graphics.draw_line(pen, x + square_width() - 1, y + square_height() - 1, x + square_width() - 1, y + 1);
  
  graphics.fill_rectangle(solid_brush {colors[as<int>(tetrominoes)]}, x + 1, y + 1, square_width() - 2, square_height() - 2);
}

void board_control::drop_down() {
  auto new_y = cur_y_;
  while (new_y > 0) {
    if (!try_move(cur_piece_, cur_x_, new_y - 1)) break;
    --new_y;
  }
  piece_dropped();
}

void board_control::new_piece() {
  cur_piece_ = shape::generate();
  cur_x_ = board_width / 2 - 1;
  cur_y_ = board_height - 1 + cur_piece_.min_y();
  
  if (!try_move(cur_piece_, cur_x_, cur_y_)) {
    cur_piece_ = shape {tetrominoes::no_shape};
    timer_.stop();
    started_ = false;
    status_bar_.text("game over");
  }
}

void board_control::one_line_down() {
  if (!try_move(cur_piece_, cur_x_, cur_y_ - 1))
    piece_dropped();
}

void board_control::piece_dropped() {
  for (auto i = 0; i < 4; ++i) {
    auto x = cur_x_ + cur_piece_.x(i);
    auto y = cur_y_ - cur_piece_.y(i);
    tetrominoes_at(x, y) = cur_piece_.tetrominoes();
  }
  
  remove_full_lines();
  
  if (!falling_finished_)
    new_piece();
}

void board_control::remove_full_lines() {
  auto num_full_lines = 0;
  
  for (auto i = board_height - 1; i >= 0; --i) {
    auto line_is_full = true;
    
    for (auto j = 0; j < board_width; ++j) {
      if (tetrominoes_at(j, i) == tetrominoes::no_shape) {
        line_is_full = false;
        break;
      }
    }
    
    if (line_is_full) {
      ++num_full_lines;
      for (auto k = i; k < board_height - 1; ++k) {
        for (auto j = 0; j < board_width; ++j)
          tetrominoes_at(j, k) = tetrominoes_at(j, k + 1);
      }
    }
  }
  
  if (num_full_lines > 0) {
    num_lines_removed_ += num_full_lines;
    status_bar_.text(ustring::format("{}", num_lines_removed_));
    falling_finished_ = true;
    cur_piece_ = shape {tetrominoes::no_shape};
    refresh();
  }
}

bool board_control::try_move(const shape& new_piece, int new_x, int new_y) noexcept {
  for (auto i = 0; i < 4; ++i) {
    auto x = new_x + new_piece.x(i);
    auto y = new_y - new_piece.y(i);
    if (x < 0 || x >= board_width || y < 0 || y >= board_height) return false;
    if (tetrominoes_at(x, y) != tetrominoes::no_shape) return false;
  }
  
  cur_piece_ = new_piece;
  cur_x_ = new_x;
  cur_y_ = new_y;
  refresh();
  return true;
}

int board_control::square_width() {
  return client_size().width() / board_width;
}

int board_control::square_height() {
  return client_size().height() / board_height;
}

tetrominoes& board_control::tetrominoes_at(int x, int y) {
  return board_[(y * board_width) + x];
}

void board_control::on_paint(paint_event_args& event) {
  control::on_paint(event);
  
  auto graphics = event.graphics();
  auto size = event.clip_rectangle().size();
  auto board_top = size.height() - board_height * square_height();
  
  for (auto i = 0; i < board_height; ++i) {
    for (auto j = 0; j < board_width; ++j) {
      auto tetrominoes = tetrominoes_at(j, board_height - i - 1);
      if (tetrominoes != tetris::tetrominoes::no_shape)
        draw_square(graphics, 0 + j * square_width(), board_top + i * square_height(), tetrominoes);
    }
  }
  
  if (cur_piece_.tetrominoes() != tetris::tetrominoes::no_shape) {
    for (auto i = 0; i < 4; ++i) {
      auto x = cur_x_ + cur_piece_.x(i);
      auto y = cur_y_ - cur_piece_.y(i);
      draw_square(graphics, 0 + x * square_width(), board_top + (board_height - y - 1) * square_height(), cur_piece_.tetrominoes());
    }
  }
}

void board_control::on_key_down(key_event_args& event) {
  control::on_key_down(event);
  
  if (event.key_code() != keys::r && event.key_code() != keys::p && (!started_ || cur_piece_.tetrominoes() == tetrominoes::no_shape || paused_)) return;
  
  switch (event.key_code()) {
    case keys::left: try_move(cur_piece_, cur_x_ - 1, cur_y_); break;
    case keys::right: try_move(cur_piece_, cur_x_ + 1, cur_y_); break;
    case keys::down: try_move(cur_piece_.rotate_right(), cur_x_, cur_y_); break;
    case keys::up: try_move(cur_piece_.rotate_left(), cur_x_, cur_y_); break;
    case keys::space: drop_down(); break;
    case keys::d: one_line_down(); break;
    case keys::p: pause(); break;
    case keys::r: start(); break;
    default: break;
  }
}

void board_control::on_tick(object& sender, const event_args& event) {
  if (!falling_finished_) {
    one_line_down();
    return;
  }
  falling_finished_ = false;
  new_piece();
}
