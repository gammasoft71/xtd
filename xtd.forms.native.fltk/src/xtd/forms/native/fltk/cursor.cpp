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

intptr_t cursor::create() {
  return static_cast<intptr_t>(FL_CURSOR_DEFAULT);
}

intptr_t cursor::copy(intptr_t cursor) {
  return cursor;
}

void cursor::destroy(intptr_t cursor) {
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

point cursor::hot_spot(intptr_t cursor) {
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

drawing::size cursor::size(intptr_t cursor) {
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
