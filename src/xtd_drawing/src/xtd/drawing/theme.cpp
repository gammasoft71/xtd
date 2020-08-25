#include "../../../include/xtd/drawing/theme.h"
#include <xtd/environment.h>
#include <xtd/drawing/native/theme.h>

using namespace std;
using namespace xtd::drawing;

string theme::application_theme() {
  return default_theme();
}

string theme::default_theme() {
  return native::theme::default_theme();
}

string theme::fallback_theme() {
  return "symbolic";
}

vector<string> theme::themes() {
  return {"kde", "gnome", "macos", "symbolic", "windows", "xtd"};
}
