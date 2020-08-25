#include <atomic>
#include <wx/image.h>
#include <wx/bitmap.h>
#include <xtd/drawing/native/theme.h>
#include <xtd/environment.h>
#include <xtd/xtd.io>
#include <xtd/xtd.strings>

using namespace xtd;
using namespace xtd::drawing::native;

std::string theme::default_theme() {
  auto desktop_environment = environment::os_version().desktop_environment();
  if (desktop_environment == "") return "symbolic";
  return desktop_environment;
}
