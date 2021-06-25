#include "../include/xtd/tunit/settings.h"

xtd::tunit::settings& xtd::tunit::settings::default_settings() noexcept {
  static xtd::tunit::settings settings;
  return settings;
  }
