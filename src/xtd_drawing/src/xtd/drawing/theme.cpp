#include "../../../include/xtd/drawing/theme.h"
#include <xtd/environment.h>
#include <xtd/drawing/native/theme.h>

using namespace std;
using namespace xtd::drawing;

string theme_image::default_theme() {
  return native::theme::default_theme();
}

string theme_image::fallback_theme() {
  return "symbolic";
}

vector<string> theme_image::themes() {
  return {"kde", "gnome", "macos", "symbolic", "windows", "xtd"};
}
