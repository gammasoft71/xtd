#include <stdexcept>
#include <xtd/forms/native/cursor.hpp>
#include <wx/cursor.h>
#include <wx/window.h>

using namespace xtd::drawing;
using namespace xtd::forms::native;

intptr_t cursor::create() {
  return reinterpret_cast<intptr_t>(new wxCursor());
}

void cursor::destroy(intptr_t cursor) {
  if (cursor == 0) return;
  delete reinterpret_cast<wxCursor*>(cursor);
}

#if !defined __APPLE__
void cursor::hide() {
}
#endif

point cursor::hot_spot(intptr_t cursor) {
  if (cursor == 0) return {};
  wxPoint hot_spot = reinterpret_cast<wxCursor*>(cursor)->GetHotSpot();
  return {hot_spot.x, hot_spot.y};
}

point cursor::position() {
  wxPoint position = wxGetMousePosition();
  return {position.x, position.y};
}

#if !defined __APPLE__
void cursor::position(const drawing::point& position) {
  wxWindow* window = wxGetActiveWindow();
  if (window) {
    wxPoint clientPosition = window->ScreenToClient(wxPoint(position.x(), position.y()));
    window->WarpPointer(clientPosition.x, clientPosition.y);
  }
}
#endif

#if !defined __APPLE__
void cursor::show() {
}
#endif
