#if defined(__APPLE__)
#include <AppKit/AppKit.h>
#include <xtd/types.h>

namespace {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  // Partial code of wxWidgets...
  // helper class for setting the current appearance to the effective appearance
  // For explanation see : https://christiantietze.de/posts/2021/10/nscolor-performAsCurrentDrawingAppearance-resolve-current-appearance/
  /// @todo Find a way to replace deprecated properties...
  class effective_appearance_setter {
  public:
    effective_appearance_setter() {
      previous_appearance = NSAppearance.currentAppearance;
      NSAppearance.currentAppearance = NSApp.effectiveAppearance;
    }
    ~effective_appearance_setter() {
      NSAppearance.currentAppearance = previous_appearance;
    }
    
  private:
    NSAppearance* previous_appearance;
  };
#pragma GCC diagnostic pop
  
  uint32_t to_argb(xtd::byte alpha, xtd::byte red, xtd::byte green, xtd::byte blue) {
    return (alpha << 24) + (red << 16) + (green << 8) + blue;
  }
  
  uint32_t to_argb(xtd::byte red, xtd::byte green, xtd::byte blue) {
    return to_argb(255, red, green, blue);
  }
  
  uint32_t to_argb(const NSColor* color) {
    const CGFloat* components = CGColorGetComponents([color CGColor]);
    uint32_t alpha = CGColorGetAlpha([color CGColor]) * 0xFF;
    uint32_t red = components[0] * 0xFF;
    uint32_t green = components[1] * 0xFF;
    uint32_t blue = components[2] * 0xFF;
    return (alpha << 24) + (red << 16) + (green << 8) + blue;
  }
}

intptr_t __xtd__macos_system_colors_accent_control__() {
  effective_appearance_setter helper;
  return to_argb([NSColor controlAccentColor]);
}

intptr_t __xtd__macos_system_colors_accent_text__() {
  effective_appearance_setter helper;
  return to_argb(255, 255, 255);
}

intptr_t __xtd__macos_system_colors_active_border__() {
  effective_appearance_setter helper;
  return to_argb([[NSColor highlightColor] colorUsingColorSpace:[NSColorSpace deviceRGBColorSpace]]);
}

intptr_t __xtd__macos_system_colors_active_caption__() {
  effective_appearance_setter helper;
  return to_argb([[NSColor highlightColor] colorUsingColorSpace:[NSColorSpace deviceRGBColorSpace]]);
}

intptr_t __xtd__macos_system_colors_button_face__() {
  effective_appearance_setter helper;
  uint32_t argb = to_argb(NSColor.controlColor);
  if (argb != 0xFFFFFFFF) {
    argb &= 0x00FFFFFF;
    argb |= 0x40000000;
  }
  return argb;
  
}

intptr_t __xtd__macos_system_colors_button_text__() {
  effective_appearance_setter helper;
  return to_argb([NSColor controlTextColor]);
}

intptr_t __xtd__macos_system_colors_control__() {
  effective_appearance_setter helper;
  return to_argb([NSColor windowBackgroundColor]);
}

intptr_t __xtd__macos_system_colors_control_text__() {
  effective_appearance_setter helper;
  return to_argb([NSColor controlTextColor]);
}

intptr_t __xtd__macos_system_colors_text_box__() {
  effective_appearance_setter helper;
  uint32_t argb = to_argb([NSColor controlColor]);
  if (argb != 0xFFFFFFFF) {
    argb &= 0x00FFFFFF;
    argb |= 0x10000000;
  }
  return argb;
}

intptr_t __xtd__macos_system_colors_text_box_text__() {
  effective_appearance_setter helper;
  return to_argb([NSColor textColor]);
}

#endif
