#if defined(__WXOSX__)
#include <Quartz/Quartz.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/cursor>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd::forms::native;

void cursor::hide() {
  [NSCursor hide];
}

void cursor::position(const drawing::point& position) {
  CGDisplayMoveCursorToPoint(kCGDirectMainDisplay, CGPointMake(position.x, position.y));
}

void cursor::show() {
  [NSCursor unhide];
}
#endif
