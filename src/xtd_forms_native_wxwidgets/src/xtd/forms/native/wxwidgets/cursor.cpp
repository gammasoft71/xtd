#include <stdexcept>
#include <xtd/forms/native/cursor.h>
#include <wx/bitmap.h>
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

intptr_t cursor::create(intptr_t image, const xtd::drawing::point& hot_spot) {
  wxImage wx_image(*reinterpret_cast<wxImage*>(image));
  wx_image.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_X, hot_spot.x());
  wx_image.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_Y, hot_spot.y());
  return reinterpret_cast<intptr_t>(new wxCursor(wx_image));
}

intptr_t cursor::copy(intptr_t cursor) {
  return reinterpret_cast<intptr_t>(new wxCursor(*reinterpret_cast<wxCursor*>(cursor)));
}

void cursor::current(intptr_t cursor) {
  wxSetCursor(cursor ? *reinterpret_cast<wxCursor*>(cursor) : wxNullCursor);
}

void cursor::destroy(intptr_t cursor) {
  if (cursor == 0) return;
  delete reinterpret_cast<wxCursor*>(cursor);
}

#if defined (__APPLE__)
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
  wxPoint hot_spot = reinterpret_cast<wxCursor*>(cursor)->GetHotSpot();
  if (hot_spot == wxDefaultPosition) return {};
  return {hot_spot.x, hot_spot.y};
  return {};
}

point cursor::position() {
  wxPoint position = wxGetMousePosition();
  return {position.x, position.y};
}

#if defined (__APPLE__)
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

#if defined (__APPLE__)
#elif defined (__WXMSW__)
void cursor::show() {
  ShowCursor(TRUE);
}
#else
void cursor::show() {
}
#endif
