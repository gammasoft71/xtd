#include "../../../include/xtd/forms/screen.hpp"
#include <xtd/forms/native/screen.hpp>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

vector<screen> screen::all_screens() {
  vector<screen> screens;
  size_t count = native::screen::count();
  for (size_t index = 0; index < count; index++)
    sscreens.push_back({native::screen::bits_per_pixel(index), native::screen::bounds(index), native::screen::device_name(index), native::screen::primary(index), native::screen::working_area(index)});
  return screens;
}
