#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/cursors>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/point>
#include <xtd/io/path>
#include <xtd/environment>
#include <xtd/ustring>
#include <wx/cursor.h>
#include <wx/image.h>

using namespace xtd;
using namespace xtd::forms::native;

namespace {
  static std::string get_os_postfix() noexcept {
    static auto os_postfix = xtd::environment::os_version().is_windows_platform() ? "_w" : xtd::environment::os_version().is_unix_platform() ? "_g" : xtd::environment::os_version().is_macos_platform() ? "_m" : "";
    return os_postfix;
  }
  
  static std::string forms_resource_path() {
    return xtd::environment::get_folder_path(xtd::environment::special_folder::xtd_resources);
  }
  
  static intptr create_cursor_from_resources(const std::string& name, const xtd::drawing::point& hot_spot) {
    if (!xtd::io::file::exists(xtd::io::path::combine(forms_resource_path(), "cursors", xtd::ustring::format("{}{}.png", name, get_os_postfix())))) return reinterpret_cast<intptr>(new wxCursor(wxCURSOR_DEFAULT));
    wxImage image(std::string(xtd::io::path::combine(forms_resource_path(), "cursors", xtd::ustring::format("{}{}.png", name, get_os_postfix()))));
    image.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_X, hot_spot.x());
    image.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_Y, hot_spot.y());
    wxCursor* cursor = new wxCursor(image);
    return reinterpret_cast<intptr>(cursor);
  }
}

intptr cursors::app_starting() {
  if (environment::os_version().is_macos_platform()) return create_cursor_from_resources("app_starting", {0, 0});
  return reinterpret_cast<intptr>(new wxCursor(wxCURSOR_ARROWWAIT));
}

intptr cursors::arrow() {
  //return create_cursor_from_resources("arrow", {0, 0});
  return reinterpret_cast<intptr>(new wxCursor(wxCURSOR_ARROW));
}

intptr cursors::closed_hand() {
  return create_cursor_from_resources("closed_hand", {7, 7});
}

intptr cursors::contextual_menu() {
  return create_cursor_from_resources("contextual_menu", {0, 0});
}

intptr cursors::cell() {
  return create_cursor_from_resources("cell", {16, 16});
}

intptr cursors::cross() {
  //return create_cursor_from_resources("cross", {16, 16});
  return reinterpret_cast<intptr>(new wxCursor(wxCURSOR_CROSS));
}

intptr cursors::default_cursor() {
  return arrow();
}

intptr cursors::disappearing_item() {
  return create_cursor_from_resources("disappearing_item", {0, 0});
}

intptr cursors::drag_copy() {
  return create_cursor_from_resources("drag_copy", {0, 0});
}

intptr cursors::drag_link() {
  return create_cursor_from_resources("drag_link", {0, 0});
}

intptr cursors::hand() {
  //return create_cursor_from_resources("hand", {0, 0});
  return reinterpret_cast<intptr>(new wxCursor(wxCURSOR_HAND));
}

intptr cursors::help() {
  return create_cursor_from_resources("help", {0, 0});
  //return reinterpret_cast<intptr>(new wxCursor(wxCURSOR_QUESTION_ARROW));
}

intptr cursors::hsplit() {
  return create_cursor_from_resources("hsplit", {15, 15});
  //return reinterpret_cast<intptr>(new wxCursor(wxCURSOR_SIZENS));
}

intptr cursors::ibeam() {
  return create_cursor_from_resources("ibeam", {8, 9});
  //return reinterpret_cast<intptr>(new wxCursor(wxCURSOR_IBEAM));
}

intptr cursors::no() {
  return create_cursor_from_resources("no", {8, 8});
}

intptr cursors::no_drag() {
  return create_cursor_from_resources("no_drag", {0, 0});
}

intptr cursors::no_move_2d() {
  return create_cursor_from_resources("no_move_2d", {16, 15});
}

intptr cursors::no_move_horiz() {
  return create_cursor_from_resources("no_move_horiz", {16, 15});
}

intptr cursors::no_move_vert() {
  return create_cursor_from_resources("no_move_vert", {16, 15});
}

intptr cursors::open_hand() {
  return create_cursor_from_resources("open_hand", {0, 0});
}

intptr cursors::pan_east() {
  return create_cursor_from_resources("pan_east", environment::os_version().is_unix_platform() ? drawing::point {17, 9} : drawing::point {10, 14});
}

intptr cursors::pan_ne() {
  return create_cursor_from_resources("pan_ne", environment::os_version().is_unix_platform() ? drawing::point {18, 5} : drawing::point {12, 18});
}

intptr cursors::pan_north() {
  return create_cursor_from_resources("pan_north", environment::os_version().is_unix_platform() ? drawing::point {12, 6} : drawing::point {15, 20});
}

intptr cursors::pan_nw() {
  return create_cursor_from_resources("pan_nw", environment::os_version().is_unix_platform() ? drawing::point {5, 5} : drawing::point {19, 18});
}

intptr cursors::pan_se() {
  return create_cursor_from_resources("pan_se", environment::os_version().is_unix_platform() ? drawing::point {19, 19} : drawing::point {12, 11});
}

intptr cursors::pan_south() {
  return create_cursor_from_resources("pan_south", environment::os_version().is_unix_platform() ? drawing::point {12, 18} : drawing::point {16, 8});
}

intptr cursors::pan_sw() {
  return create_cursor_from_resources("pan_sw", environment::os_version().is_unix_platform() ? drawing::point {6, 19} : drawing::point {19, 10});
}

intptr cursors::pan_west() {
  return create_cursor_from_resources("pan_west", environment::os_version().is_unix_platform() ? drawing::point {3, 9} : drawing::point {21, 14});
}

intptr cursors::size_all() {
  return create_cursor_from_resources("size_all", {11, 11});
  //return reinterpret_cast<intptr>(new wxCursor(wxCURSOR_SIZING));
}

intptr cursors::size_nesw() {
  return create_cursor_from_resources("size_nesw", {8, 8});
  //return reinterpret_cast<intptr>(new wxCursor(wxCURSOR_SIZENESW));
}

intptr cursors::size_ns() {
  return create_cursor_from_resources("size_ns", environment::os_version().is_unix_platform() ? drawing::point {7, 11} : drawing::point {4, 11});
  //return reinterpret_cast<intptr>(new wxCursor(wxCURSOR_SIZENS));
}

intptr cursors::size_nwse() {
  return create_cursor_from_resources("size_nwse", {8, 8});
  //return reinterpret_cast<intptr>(new wxCursor(wxCURSOR_SIZENWSE));
}

intptr cursors::size_we() {
  return create_cursor_from_resources("size_we", environment::os_version().is_unix_platform() ? drawing::point {11, 8} : drawing::point {11, 4});
  //return reinterpret_cast<intptr>(new wxCursor(wxCURSOR_SIZEWE));
}

intptr cursors::up_arrow() {
  return create_cursor_from_resources("up_arrow", {4, 0});
}

intptr cursors::vibeam() {
  return create_cursor_from_resources("vibeam", {9, 9});
}

intptr cursors::vsplit() {
  return create_cursor_from_resources("vsplit", {15, 15});
  //return reinterpret_cast<intptr>(new wxCursor(wxCURSOR_SIZEWE));
}

intptr cursors::wait_cursor() {
  if (environment::os_version().is_macos_platform()) return create_cursor_from_resources("wait", {7, 7});
  return reinterpret_cast<intptr>(new wxCursor(wxCURSOR_WAIT));
}

intptr cursors::zoom_in() {
  return create_cursor_from_resources("zoom_in", {10, 10});
}

intptr cursors::zoom_out() {
  return create_cursor_from_resources("zoom_out", {10, 10});
}
