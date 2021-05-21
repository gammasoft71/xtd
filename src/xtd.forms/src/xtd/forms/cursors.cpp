#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/cursors.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/cursors.h"

using namespace xtd::forms;

cursor cursors::app_starting() {
  return cursor(native::cursors::app_starting(), true, "app_starting");
}

cursor cursors::arrow() {
  return cursor(native::cursors::arrow(), true, "arrow");
}

cursor cursors::closed_hand() {
  return cursor(native::cursors::closed_hand(), true, "closed_hand");
}

cursor cursors::contextual_menu() {
  return cursor(native::cursors::contextual_menu(), true, "contextual_menu");
}

cursor cursors::cell() {
  return cursor(native::cursors::cell(), true, "cell");
}

cursor cursors::cross() {
  return cursor(native::cursors::cross(), true, "cross");
}

cursor cursors::default_cursor() {
  return cursor(native::cursors::default_cursor(), true, "default_cursor");
}

cursor cursors::disappearing_item() {
  return cursor(native::cursors::disappearing_item(), true, "disappearing_item");
}

cursor cursors::drag_copy() {
  return cursor(native::cursors::drag_copy(), true, "drag_copy");
}

cursor cursors::drag_link() {
  return cursor(native::cursors::drag_link(), true, "drag_link");
}

cursor cursors::hand() {
  return cursor(native::cursors::hand(), true, "hand");
}

cursor cursors::help() {
  return cursor(native::cursors::help(), true, "help");
}

cursor cursors::hsplit() {
  return cursor(native::cursors::hsplit(), true, "hsplit");
}

cursor cursors::ibeam() {
  return cursor(native::cursors::ibeam(), true, "ibeam");
}

cursor cursors::no() {
  return cursor(native::cursors::no(), true, "no");
}

cursor cursors::no_drag() {
  return cursor(native::cursors::no_drag(), true, "no_drag");
}

cursor cursors::no_move_2d() {
  return cursor(native::cursors::no_move_2d(), true, "no_move_2d");
}

cursor cursors::no_move_horiz() {
  return cursor(native::cursors::no_move_horiz(), true, "no_move_horiz");
}

cursor cursors::no_move_vert() {
  return cursor(native::cursors::no_move_vert(), true, "no_move_vert");
}

cursor cursors::open_hand() {
  return cursor(native::cursors::open_hand(), true, "open_hand");
}

cursor cursors::pan_east() {
  return cursor(native::cursors::pan_east(), true, "pan_east");
}

cursor cursors::pan_ne() {
  return cursor(native::cursors::pan_ne(), true, "pan_ne");
}

cursor cursors::pan_north() {
  return cursor(native::cursors::pan_north(), true, "pan_north");
}

cursor cursors::pan_nw() {
  return cursor(native::cursors::pan_nw(), true, "pan_nw");
}

cursor cursors::pan_se() {
  return cursor(native::cursors::pan_se(), true, "pan_se");
}

cursor cursors::pan_south() {
  return cursor(native::cursors::pan_south(), true, "pan_south");
}

cursor cursors::pan_sw() {
  return cursor(native::cursors::pan_sw(), true, "pan_sw");
}

cursor cursors::pan_west() {
  return cursor(native::cursors::pan_west(), true, "pan_west");
}

cursor cursors::size_all() {
  return cursor(native::cursors::size_all(), true, "size_all");
}

cursor cursors::size_nesw() {
  return cursor(native::cursors::size_nesw(), true, "size_nesw");
}

cursor cursors::size_ns() {
  return cursor(native::cursors::size_ns(), true, "size_ns");
}

cursor cursors::size_nwse() {
  return cursor(native::cursors::size_nwse(), true, "size_nwse");
}

cursor cursors::size_we() {
  return cursor(native::cursors::size_we(), true, "size_we");
}

cursor cursors::up_arrow() {
  return cursor(native::cursors::up_arrow(), true, "up_arrow");
}

cursor cursors::vibeam() {
  return cursor(native::cursors::vibeam(), true, "vibeam");
}

cursor cursors::vsplit() {
  return cursor(native::cursors::vsplit(), true, "vsplit");
}

cursor cursors::wait_cursor() {
  return cursor(native::cursors::wait_cursor(), true, "wait_cursor");
}

cursor cursors::zoom_in() {
  return cursor(native::cursors::zoom_in(), true, "zoom_in");
}

cursor cursors::zoom_out() {
  return cursor(native::cursors::zoom_out(), true, "zoom_out");
}

const std::vector<cursor>& cursors::get_cursors() {
  static std::vector<cursor> cursors {app_starting(), arrow(), closed_hand(), contextual_menu(), cell(), cross(), default_cursor(), disappearing_item(), drag_copy(), drag_link(), hand(), help(), hsplit(), ibeam(), no(), no_drag(), no_move_2d(), no_move_horiz(), no_move_vert(), open_hand(), pan_east(), pan_ne(), pan_north(), pan_nw(), pan_se(), pan_south(), pan_sw(), pan_west(), size_all(), size_nesw(), size_ns(), size_we(), up_arrow(), vibeam(), vsplit(), wait_cursor(), zoom_in(), zoom_out()};
  return cursors;
}
