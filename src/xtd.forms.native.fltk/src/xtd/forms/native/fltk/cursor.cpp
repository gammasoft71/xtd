#include <stdexcept>
#include <xtd/forms/native/cursor.hpp>
#include <FL/Fl.H>
#include <FL/fl_draw.H>

#if defined(__WXMSW__)
#include <Windows.h>
#endif

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

intmax_t cursor::create() {
  return static_cast<intmax_t>(FL_CURSOR_DEFAULT);
}

intmax_t cursor::copy(intmax_t cursor) {
  return cursor;
}

void cursor::destroy(intmax_t cursor) {
}


#if defined __APPLE__
#elif defined (__WXMSW__)
void cursor::hide() {
  ShowCursor(FALSE);
}
#else
void cursor::hide() {
}
#endif

point cursor::hot_spot(intmax_t cursor) {
  if (cursor == 0) return {};
  return {};
}

point cursor::position() {
  return {Fl::event_x_root(), Fl::event_y_root()};
}

#if defined __APPLE__
#elif defined (__WXMSW__)
void cursor::position(const point& position) {
  SetCursorPos(position.x(), position.y());
}
#else
void cursor::position(const point& position) {
}
#endif

drawing::size cursor::size(intmax_t cursor) {
  return {32, 32};
}

#if defined __APPLE__
#elif defined (__WXMSW__)
void cursor::show() {
  ShowCursor(TRUE);
}
#else
void cursor::show() {
}
#endif
