#if defined(__APPLE__)
#include <Quartz/Quartz.h>

void __xtd_enable_dark_mode__() {
  [NSApp setAppearance:[NSAppearance appearanceNamed:NSAppearanceNameDarkAqua]];
}

void __xtd_enable_light_mode__() {
  [NSApp setAppearance:[NSAppearance appearanceNamed:NSAppearanceNameAqua]];
}
#endif
