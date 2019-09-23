#if defined(__APPLE__)
#include <xtd/forms/native/cursor.hpp>
#include <Quartz/Quartz.h>

using namespace xtd::forms::native;

void cursor::hide() {
  CGDisplayHideCursor(kCGDirectMainDisplay);
}

void cursor::position(const drawing::point& position) {
  CGDisplayMoveCursorToPoint(kCGDirectMainDisplay, CGPointMake(position.x(), position.y()));
}

void cursor::show() {
  CGDisplayShowCursor(kCGDirectMainDisplay);
}
#endif
