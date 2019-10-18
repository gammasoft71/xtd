#include <FL/Fl.H>
#include <xtd/version.hpp>

using namespace xtd;

version __xtd_forms_native_fltk_version() {
  return {FL_MAJOR_VERSION, FL_MINOR_VERSION, FL_PATCH_VERSION };
}
