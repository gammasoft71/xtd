#include <stdexcept>
#include <xtd/forms/native/cursors.hpp>
#include <FL/fl_draw.H>

using namespace xtd::forms::native;

intmax_t cursors::app_starting() {
  return static_cast<intmax_t>(FL_CURSOR_WAIT);
}

intmax_t cursors::close_hand() {
  return static_cast<intmax_t>(FL_CURSOR_HAND);
}

intmax_t cursors::contextual_menu() {
  return static_cast<intmax_t>(FL_CURSOR_DEFAULT);
}

intmax_t cursors::arrow() {
  return static_cast<intmax_t>(FL_CURSOR_ARROW);
}

intmax_t cursors::cross() {
  return static_cast<intmax_t>(FL_CURSOR_CROSS);
}

intmax_t cursors::default_cursor() {
  return static_cast<intmax_t>(FL_CURSOR_DEFAULT);
}

intmax_t cursors::disappearing_item() {
  return static_cast<intmax_t>(FL_CURSOR_DEFAULT);
}

intmax_t cursors::drag_copy() {
  return static_cast<intmax_t>(FL_CURSOR_DEFAULT);
}

intmax_t cursors::drag_link() {
  return static_cast<intmax_t>(FL_CURSOR_DEFAULT);
}

intmax_t cursors::hand() {
  return static_cast<intmax_t>(FL_CURSOR_HAND);
}

intmax_t cursors::help() {
  return static_cast<intmax_t>(FL_CURSOR_HELP);
}

intmax_t cursors::hsplit() {
  return static_cast<intmax_t>(FL_CURSOR_NS);
}

intmax_t cursors::ibeam() {
  return static_cast<intmax_t>(FL_CURSOR_INSERT);
}

intmax_t cursors::no() {
  return static_cast<intmax_t>(FL_CURSOR_DEFAULT);
}

intmax_t cursors::no_move_2d() {
  return static_cast<intmax_t>(FL_CURSOR_DEFAULT);
}

intmax_t cursors::no_move_vert() {
  return static_cast<intmax_t>(FL_CURSOR_DEFAULT);
}

intmax_t cursors::no_move_horiz() {
  return static_cast<intmax_t>(FL_CURSOR_DEFAULT);
}

intmax_t cursors::open_hand() {
  return static_cast<intmax_t>(FL_CURSOR_HAND);
}

intmax_t cursors::pan_east() {
  return static_cast<intmax_t>(FL_CURSOR_E);
}

intmax_t cursors::pan_ne() {
  return static_cast<intmax_t>(FL_CURSOR_NE);
}

intmax_t cursors::pan_north() {
  return static_cast<intmax_t>(FL_CURSOR_N);
}

intmax_t cursors::pan_nw() {
  return static_cast<intmax_t>(FL_CURSOR_NW);
}

intmax_t cursors::pan_se() {
  return static_cast<intmax_t>(FL_CURSOR_SE);
}

intmax_t cursors::pan_south() {
  return static_cast<intmax_t>(FL_CURSOR_S);
}

intmax_t cursors::pan_sw() {
  return static_cast<intmax_t>(FL_CURSOR_SW);
}

intmax_t cursors::pan_west() {
  return static_cast<intmax_t>(FL_CURSOR_W);
}

intmax_t cursors::size_all() {
  return static_cast<intmax_t>(FL_CURSOR_MOVE);
}

intmax_t cursors::size_nesw() {
  return static_cast<intmax_t>(FL_CURSOR_DEFAULT);
}

intmax_t cursors::size_ns() {
  return static_cast<intmax_t>(FL_CURSOR_NS);
}

intmax_t cursors::size_nwse() {
  return static_cast<intmax_t>(FL_CURSOR_NWSE);
}

intmax_t cursors::size_we() {
  return static_cast<intmax_t>(FL_CURSOR_WE);
}

intmax_t cursors::up_arrow() {
  return static_cast<intmax_t>(FL_CURSOR_DEFAULT);
}

intmax_t cursors::vibeam() {
  return static_cast<intmax_t>(FL_CURSOR_INSERT);
}

intmax_t cursors::vsplit() {
  return static_cast<intmax_t>(FL_CURSOR_WE);
}

intmax_t cursors::wait_cursor() {
  return static_cast<intmax_t>(FL_CURSOR_WAIT);
}
