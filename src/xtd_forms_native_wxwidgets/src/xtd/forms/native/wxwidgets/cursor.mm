#if defined(__APPLE__)
#include <xtd/forms/native/cursor.h>
#include <Quartz/Quartz.h>

using namespace xtd::forms::native;

void cursor::hide() {
  [NSCursor hide];
}

void cursor::position(const drawing::point& position) {
  CGDisplayMoveCursorToPoint(kCGDirectMainDisplay, CGPointMake(position.x(), position.y()));
}

void cursor::show() {
  [NSCursor unhide];
}
#endif
