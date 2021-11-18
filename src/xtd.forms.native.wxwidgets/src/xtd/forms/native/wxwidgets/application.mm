#if defined(__APPLE__)
#include <Quartz/Quartz.h>
#include <AvailabilityMacros.h>

void __xtd_macos_enable_dark_mode__() {
  [NSApp setAppearance:[NSAppearance appearanceNamed:NSAppearanceNameDarkAqua]];
}

void __xtd_macos_enable_light_mode__() {
  [NSApp setAppearance:[NSAppearance appearanceNamed:NSAppearanceNameAqua]];
}

bool __xtd_macos_dark_mode_enabled__() {
#if MAC_OS_X_VERSION_MAX_ALLOWED <= MAC_OS_X_VERSION_10_15
  return [[[NSAppearance currentAppearance] name] isEqualToString:(NSAppearanceNameDarkAqua)];
#else
  return [[[NSAppearance currentDrawingAppearance] name] isEqualToString:(NSAppearanceNameDarkAqua)];
#endif
}

#endif
