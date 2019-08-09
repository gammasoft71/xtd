#include <xtd/forms/native/screen.hpp>
#include <wx/display.h

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

size_t screen::count() {
  return wxDisplay::GetCount();
}

int32_t screen::bits_per_pixel(size_t index) {
  return wxDisplay(index).GetPPI().GetWWidth();
}
