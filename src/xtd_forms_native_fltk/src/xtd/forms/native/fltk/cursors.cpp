#include <stdexcept>
#include <xtd/forms/native/cursors.hpp>
#include <FL/fl_draw.H>

using namespace xtd::forms::native;

intptr_t cursors::app_starting() {
  return static_cast<intptr_t>(FL_CURSOR_WAIT);
}

intptr_t cursors::close_hand() {
  return static_cast<intptr_t>(FL_CURSOR_HAND);
}

intptr_t cursors::contextual_menu() {
  return static_cast<intptr_t>(FL_CURSOR_DEFAULT);
}

intptr_t cursors::arrow() {
  return static_cast<intptr_t>(FL_CURSOR_ARROW);
}

intptr_t cursors::cross() {
  return static_cast<intptr_t>(FL_CURSOR_CROSS);
}

intptr_t cursors::default_cursor() {
  return static_cast<intptr_t>(FL_CURSOR_DEFAULT);
}

intptr_t cursors::disappearing_item() {
  return static_cast<intptr_t>(FL_CURSOR_DEFAULT);
}

intptr_t cursors::drag_copy() {
  return static_cast<intptr_t>(FL_CURSOR_DEFAULT);
}

intptr_t cursors::drag_link() {
  return static_cast<intptr_t>(FL_CURSOR_DEFAULT);
}

intptr_t cursors::hand() {
  return static_cast<intptr_t>(FL_CURSOR_HAND);
}

intptr_t cursors::help() {
  return static_cast<intptr_t>(FL_CURSOR_HELP);
}

intptr_t cursors::hsplit() {
  return static_cast<intptr_t>(FL_CURSOR_NS);
}

intptr_t cursors::ibeam() {
  return static_cast<intptr_t>(FL_CURSOR_INSERT);
}

intptr_t cursors::no() {
  return static_cast<intptr_t>(FL_CURSOR_DEFAULT);
}

intptr_t cursors::no_move_2d() {
  return static_cast<intptr_t>(FL_CURSOR_DEFAULT);
}

intptr_t cursors::no_move_vert() {
  return static_cast<intptr_t>(FL_CURSOR_DEFAULT);
}

intptr_t cursors::no_move_horiz() {
  return static_cast<intptr_t>(FL_CURSOR_DEFAULT);
}

intptr_t cursors::open_hand() {
  return static_cast<intptr_t>(FL_CURSOR_HAND);
}

intptr_t cursors::pan_east() {
  return static_cast<intptr_t>(FL_CURSOR_E);
}

intptr_t cursors::pan_ne() {
  return static_cast<intptr_t>(FL_CURSOR_NE);
}

intptr_t cursors::pan_north() {
  return static_cast<intptr_t>(FL_CURSOR_N);
}

intptr_t cursors::pan_nw() {
  return static_cast<intptr_t>(FL_CURSOR_NW);
}

intptr_t cursors::pan_se() {
  return static_cast<intptr_t>(FL_CURSOR_SE);
}

intptr_t cursors::pan_south() {
  return static_cast<intptr_t>(FL_CURSOR_S);
}

intptr_t cursors::pan_sw() {
  return static_cast<intptr_t>(FL_CURSOR_SW);
}

intptr_t cursors::pan_west() {
  return static_cast<intptr_t>(FL_CURSOR_W);
}

intptr_t cursors::size_all() {
  return static_cast<intptr_t>(FL_CURSOR_MOVE);
}

intptr_t cursors::size_nesw() {
  return static_cast<intptr_t>(FL_CURSOR_DEFAULT);
}

intptr_t cursors::size_ns() {
  return static_cast<intptr_t>(FL_CURSOR_NS);
}

intptr_t cursors::size_nwse() {
  return static_cast<intptr_t>(FL_CURSOR_NWSE);
}

intptr_t cursors::size_we() {
  return static_cast<intptr_t>(FL_CURSOR_WE);
}

intptr_t cursors::up_arrow() {
  return static_cast<intptr_t>(FL_CURSOR_DEFAULT);
}

intptr_t cursors::vibeam() {
  return static_cast<intptr_t>(FL_CURSOR_INSERT);
}

intptr_t cursors::vsplit() {
  return static_cast<intptr_t>(FL_CURSOR_WE);
}

intptr_t cursors::wait_cursor() {
  return static_cast<intptr_t>(FL_CURSOR_WAIT);
}
