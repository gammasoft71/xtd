#include "../../../include/xtd/forms/screen.hpp
#include <xtd/forms/native/screen.hpp>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

vector<screen> screen::all_screens() {
  vector<screen> screens;
  size_t count = native::screen::count();
  for (size_t index = 0; index < count; index++)
    screens.push_back({});
  return screens;
}
