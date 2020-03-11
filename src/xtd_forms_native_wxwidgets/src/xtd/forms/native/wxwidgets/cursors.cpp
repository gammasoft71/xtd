#include <stdexcept>
#include <xtd/forms/native/cursors.h>
#include <wx/cursor.h>

using namespace xtd::forms::native;

intptr_t cursors::app_starting() {
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_ARROWWAIT));
}

intptr_t cursors::close_hand() {
  /// @todo create a bitmap represented close_hand cursor
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_HAND));
}

intptr_t cursors::contextual_menu() {
  /// @todo create a bitmap represented contextual_menu cursor
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_DEFAULT));
}

intptr_t cursors::arrow() {
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_ARROW));
}

intptr_t cursors::cross() {
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_CROSS));
}

intptr_t cursors::default_cursor() {
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_DEFAULT));
}

intptr_t cursors::disappearing_item() {
  /// @todo create a bitmap represented disappearing_item cursor
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_DEFAULT));
}

intptr_t cursors::drag_copy() {
  /// @todo create a bitmap represented drag_copy cursor
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_DEFAULT));
}

intptr_t cursors::drag_link() {
  /// @todo create a bitmap represented drag_link cursor
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_DEFAULT));
}

intptr_t cursors::hand() {
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_HAND));
}

intptr_t cursors::help() {
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_QUESTION_ARROW));
}

intptr_t cursors::hsplit() {
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_SIZENS));
}

intptr_t cursors::ibeam() {
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_IBEAM));
}

intptr_t cursors::no() {
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_NO_ENTRY));
}

intptr_t cursors::no_move_2d() {
  /// @todo create a bitmap represented no_move_2d cursor
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_NO_ENTRY));
}

intptr_t cursors::no_move_vert() {
  /// @todo create a bitmap represented no_move_vert cursor
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_NO_ENTRY));
}

intptr_t cursors::no_move_horiz() {
  /// @todo create a bitmap represented no_move_horiz cursor
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_NO_ENTRY));
}

intptr_t cursors::open_hand() {
  /// @todo create a bitmap represented open_hand cursor
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_HAND));
}

intptr_t cursors::pan_east() {
  /// @todo create a bitmap represented pan_east cursor
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_DEFAULT));
}

intptr_t cursors::pan_ne() {
  /// @todo create a bitmap represented pan_ne cursor
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_DEFAULT));
}

intptr_t cursors::pan_north() {
  /// @todo create a bitmap represented pan_ne cursor
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_DEFAULT));
}

intptr_t cursors::pan_nw() {
  /// @todo create a bitmap represented pan_nw cursor
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_DEFAULT));
}

intptr_t cursors::pan_se() {
  /// @todo create a bitmap represented pan_se cursor
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_DEFAULT));
}

intptr_t cursors::pan_south() {
  /// @todo create a bitmap represented pan_south cursor
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_DEFAULT));
}

intptr_t cursors::pan_sw() {
  /// @todo create a bitmap represented pan_sw cursor
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_DEFAULT));
}

intptr_t cursors::pan_west() {
  /// @todo create a bitmap represented pan_west cursor
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_DEFAULT));
}

intptr_t cursors::size_all() {
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_SIZING));
}

intptr_t cursors::size_nesw() {
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_SIZENESW));
}

intptr_t cursors::size_ns() {
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_SIZENS));
}

intptr_t cursors::size_nwse() {
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_SIZENWSE));
}

intptr_t cursors::size_we() {
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_SIZEWE));
}

intptr_t cursors::up_arrow() {
  /// @todo create a bitmap represented up_arrow cursor
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_DEFAULT));
}

intptr_t cursors::vibeam() {
  /// @todo create a bitmap vibeam up_arrow cursor
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_IBEAM));
}

intptr_t cursors::vsplit() {
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_SIZEWE));
}

intptr_t cursors::wait_cursor() {
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_WAIT));
}
