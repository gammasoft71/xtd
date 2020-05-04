#include <stdexcept>
#include <xtd/forms/native/cursors.h>
#include <xtd/environment.h>
#include <xtd/drawing/point.h>
#include <xtd/io/path.h>
#include <xtd/strings.h>
#include <wx/cursor.h>
#include <wx/image.h>

void __xtd_init_image_handlers__();
void __xtd_clean_image_handlers__();

using namespace xtd::forms::native;

namespace {
  static std::string get_os_potfix() noexcept {
    return xtd::environment::os_version().is_windows_platform() ? "_w" : xtd::environment::os_version().is_linux_platform() ? "_g" : xtd::environment::os_version().is_osx_platform() ? "_m" : "";
  }
 
  static std::string forms_resource_path() {
#if defined(__XTD_FORMS_RESOURCES_PATH__)
    return xtd::io::path::combine(__XTD_FORMS_RESOURCES_PATH__, "share", "xtd", "resources");
#else
    return "";
#endif
  }

  static intptr_t create_cursor_from_resources(const std::string& name, const xtd::drawing::point& hot_spot ) {
    __xtd_init_image_handlers__();
    if (!xtd::io::file::exists(xtd::io::path::combine(forms_resource_path(), "cursors", xtd::strings::format("{}{}.png", name, get_os_potfix())))) return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_DEFAULT));
    wxImage image(xtd::io::path::combine(forms_resource_path(), "cursors", xtd::strings::format("{}{}.png", name, get_os_potfix())));
    image.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_X, hot_spot.x());
    image.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_Y, hot_spot.y());
    wxCursor* cursor = new wxCursor(image);
    __xtd_clean_image_handlers__();
    return reinterpret_cast<intptr_t>(cursor);
  }
}

intptr_t cursors::app_starting() {
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_ARROWWAIT));
}

intptr_t cursors::arrow() {
  //return create_cursor_from_resources("arrow", {0, 0});
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_ARROW));
}

intptr_t cursors::closed_hand() {
  return create_cursor_from_resources("close_hand", {7, 7});
}

intptr_t cursors::contextual_menu() {
  return create_cursor_from_resources("contextual_menu", {0, 0});
}

intptr_t cursors::cell() {
  return create_cursor_from_resources("cell", {7, 7});
}

intptr_t cursors::cross() {
  return create_cursor_from_resources("cross", {16, 16});
  //return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_CROSS));
}

intptr_t cursors::default_cursor() {
  return arrow();
}

intptr_t cursors::disappearing_item() {
  return create_cursor_from_resources("disappearing_item", {0, 0});
}

intptr_t cursors::drag_copy() {
  return create_cursor_from_resources("drag_copy", {0, 0});
}

intptr_t cursors::drag_link() {
  return create_cursor_from_resources("drag_link", {0, 0});
}

intptr_t cursors::hand() {
  //return create_cursor_from_resources("hand", {0, 0});
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_HAND));
}

intptr_t cursors::help() {
  return create_cursor_from_resources("help", {0, 0});
  //return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_QUESTION_ARROW));
}

intptr_t cursors::hsplit() {
  return create_cursor_from_resources("hsplit", {15, 15});
  //return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_SIZENS));
}

intptr_t cursors::ibeam() {
  return create_cursor_from_resources("ibeam", {0, 0});
  //return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_IBEAM));
}

intptr_t cursors::no() {
  return create_cursor_from_resources("no", {0, 0});
}

intptr_t cursors::no_drag() {
  return create_cursor_from_resources("no_drag", {0, 0});
}

intptr_t cursors::no_move_2d() {
  return create_cursor_from_resources("no_move_2d", {15, 15});
}

intptr_t cursors::no_move_horiz() {
  return create_cursor_from_resources("no_move_horiz", {15, 15});
}

intptr_t cursors::no_move_vert() {
  return create_cursor_from_resources("no_move_vert", {15, 15});
}

intptr_t cursors::open_hand() {
  return create_cursor_from_resources("open_hand", {0, 0});
}

intptr_t cursors::pan_east() {
  return create_cursor_from_resources("pan_east", {0, 0});
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
  return create_cursor_from_resources("pan_west", {0, 0});
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
  return create_cursor_from_resources("vibeam", {0, 0});
}

intptr_t cursors::vsplit() {
  return create_cursor_from_resources("vsplit", {15, 15});
  //return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_SIZEWE));
}

intptr_t cursors::wait_cursor() {
  return reinterpret_cast<intptr_t>(new wxCursor(wxCURSOR_WAIT));
}
