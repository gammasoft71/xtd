#include <stdexcept>
#include <xtd/forms/native/cursor.h>
#include <wx/cursor.h>
#include <wx/window.h>

#if defined(__WXMSW__)
#include <Windows.h>
#endif

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

intptr_t cursor::create() {
  return reinterpret_cast<intptr_t>(new wxCursor());
  }

  intptr_t cursor::copy(intptr_t cursor) {
    return reinterpret_cast<intptr_t>(new wxCursor(*reinterpret_cast<wxCursor*>(cursor)));
  }

  void cursor::destroy(intptr_t cursor) {
  if (cursor == 0) return;
  delete reinterpret_cast<wxCursor*>(cursor);
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
  #if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
    wxPoint hot_spot = reinterpret_cast<wxCursor*>(cursor)->GetHotSpot();
    return {hot_spot.x, hot_spot.y};
  #endif
  return {};
}

point cursor::position() {
  wxPoint position = wxGetMousePosition();
  return {position.x, position.y};
}

#if defined __APPLE__
#elif defined (__WXMSW__)
void cursor::position(const point& position) {
  SetCursorPos(position.x(), position.y());
}
#else
void cursor::position(const point& position) {
  wxWindow* window = wxGetActiveWindow();
  if (window) {
    wxPoint clientPosition = window->ScreenToClient(wxPoint(position.x(), position.y()));
    window->WarpPointer(clientPosition.x, clientPosition.y);
  }
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
