#if defined(__APPLE__)
#include <Quartz/Quartz.h>

void __xtd_macos_enable_dark_mode__() {
  [NSApp setAppearance:[NSAppearance appearanceNamed:NSAppearanceNameDarkAqua]];
}

void __xtd_macos_enable_light_mode__() {
  [NSApp setAppearance:[NSAppearance appearanceNamed:NSAppearanceNameAqua]];
}

bool __xtd_macos_dark_mode_enabled__() {
  //return [[[NSApp appearance] name] isEqualToString:(NSAppearanceNameDarkAqua)];
  return [[[NSAppearance currentAppearance] name] isEqualToString:(NSAppearanceNameDarkAqua)];
}

#endif
