#if defined(__APPLE__)
#include <AppKit/AppKit.h>

namespace {
  uint32_t to_argb(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue) {
    return (alpha << 24) + (red << 16) + (green << 8) + blue;
  }

  uint32_t to_argb(uint8_t red, uint8_t green, uint8_t blue) {
    return to_argb(255, red, green, blue);
  }

  uint32_t to_argb(NSColor* color) {
    const CGFloat* components = CGColorGetComponents(color.CGColor);
    uint32_t alpha = CGColorGetAlpha(color.CGColor) * 0xFF;
    uint32_t red = components[0] * 0xFF;
    uint32_t green = components[1] * 0xFF;
    uint32_t blue = components[2] * 0xFF;
    return (alpha << 24) + (red << 16) + (green << 8) + blue;
  }
}

intptr_t __xtd__macos_system_colors_accent_control__() {
  return to_argb(NSColor.controlAccentColor);
}

intptr_t __xtd__macos_system_colors_accent_text__() {
  return to_argb(255, 255, 255);
}

intptr_t __xtd__macos_system_colors_active_border__() {
  return to_argb([[NSColor controlHighlightColor] colorUsingColorSpace:[NSColorSpace deviceRGBColorSpace]]);
}

intptr_t __xtd__macos_system_colors_active_caption__() {
  return to_argb([[NSColor controlHighlightColor] colorUsingColorSpace:[NSColorSpace deviceRGBColorSpace]]);
}

intptr_t __xtd__macos_system_colors_button_face__() {
  return to_argb(NSColor.controlColor);
}

intptr_t __xtd__macos_system_colors_button_text__() {
  return to_argb(NSColor.controlTextColor);
}

intptr_t __xtd__macos_system_colors_control__() {
  return to_argb(NSColor.windowBackgroundColor);
}

intptr_t __xtd__macos_system_colors_control_text__() {
  return to_argb(NSColor.controlTextColor);
}

#endif
