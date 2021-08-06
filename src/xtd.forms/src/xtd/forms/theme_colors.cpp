#include "../../../include/xtd/forms/theme_colors.h"
#include <xtd/argument_exception.h>
#include <xtd/environment.h>
#include <xtd/drawing/system_colors.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace {
  color system_color_getter(known_themed_color color) {
    switch (color) {
      case known_themed_color::accent: return system_colors::accent();
      case known_themed_color::accent_text: return system_colors::accent_text();
      case known_themed_color::active_border: return system_colors::active_border();
      case known_themed_color::active_caption: return system_colors::active_caption();
      case known_themed_color::active_caption_text: return system_colors::active_caption_text();
      case known_themed_color::app_workspace: return system_colors::app_workspace();
      case known_themed_color::button_face: return system_colors::button_face();
      case known_themed_color::button_highlight: return system_colors::button_highlight();
      case known_themed_color::button_shadow: return system_colors::button_shadow();
      case known_themed_color::control: return system_colors::control();
      case known_themed_color::control_dark: return system_colors::control_dark();
      case known_themed_color::control_dark_dark: return system_colors::control_dark_dark();
      case known_themed_color::control_light: return system_colors::control_light();
      case known_themed_color::control_light_light: return system_colors::control_light_light();
      case known_themed_color::control_text: return system_colors::control_text();
      case known_themed_color::desktop: return system_colors::desktop();
      case known_themed_color::gradient_active_caption: return system_colors::gradient_active_caption();
      case known_themed_color::gradient_inactive_caption: return system_colors::gradient_inactive_caption();
      case known_themed_color::gray_text: return system_colors::gray_text();
      case known_themed_color::highlight: return system_colors::highlight();
      case known_themed_color::highlight_text: return system_colors::highlight_text();
      case known_themed_color::hot_track: return system_colors::hot_track();
      case known_themed_color::inactive_border: return system_colors::inactive_border();
      case known_themed_color::inactive_caption: return system_colors::inactive_caption();
      case known_themed_color::inactive_caption_text: return system_colors::inactive_caption_text();
      case known_themed_color::info: return system_colors::info();
      case known_themed_color::info_text: return system_colors::info_text();
      case known_themed_color::menu: return system_colors::menu();
      case known_themed_color::menu_text: return system_colors::menu_text();
      case known_themed_color::menu_bar: return system_colors::menu_bar();
      case known_themed_color::menu_highlight: return system_colors::menu_highlight();
      case known_themed_color::scroll_bar: return system_colors::scroll_bar();
      case known_themed_color::text_box: return system_colors::text_box();
      case known_themed_color::text_box_text: return system_colors::text_box_text();
      case known_themed_color::window: return system_colors::window();
      case known_themed_color::window_frame: return system_colors::window_frame();
      case known_themed_color::window_text: return system_colors::window_text();
      default: throw argument_exception("unknown know_color"_t, current_stack_frame_);
    }
  }

  // following methods are generated with this code :
  //
  // #include <xtd/xtd.forms>
  //
  // int main() {
  //   for (xtd::forms::known_themed_color color = xtd::forms::known_themed_color::accent; color <= xtd::forms::known_themed_color::window_text; color = (xtd::forms::known_themed_color)((int)color + 1))
  //     xtd::cdebug << xtd::ustring::format("      case xtd::forms::known_themed_color::{}: return xtd::drawing::color::from_argb(0x{:X8});", color, xtd::forms::theme_color::current_theme().from_known_themed_color(color).to_argb()) << std::endl;
  // }

  color gnome_dark_color_getter(known_themed_color color) {
    switch (color) {
      case xtd::forms::known_themed_color::accent: return xtd::drawing::color::from_argb(0xFF15539E);
      case xtd::forms::known_themed_color::accent_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::active_border: return xtd::drawing::color::from_argb(0xFF333333);
      case xtd::forms::known_themed_color::active_caption: return xtd::drawing::color::from_argb(0xFF282828);
      case xtd::forms::known_themed_color::active_caption_text: return xtd::drawing::color::from_argb(0xFFEEEEEC);
      case xtd::forms::known_themed_color::app_workspace: return xtd::drawing::color::from_argb(0xFF2D2D2D);
      case xtd::forms::known_themed_color::button_face: return xtd::drawing::color::from_argb(0xFF333333);
      case xtd::forms::known_themed_color::button_highlight: return xtd::drawing::color::from_argb(0xFF373737);
      case xtd::forms::known_themed_color::button_shadow: return xtd::drawing::color::from_argb(0xFF1B1B1B);
      case xtd::forms::known_themed_color::control: return xtd::drawing::color::from_argb(0xFF333333);
      case xtd::forms::known_themed_color::control_dark: return xtd::drawing::color::from_argb(0xFF1B1B1B);
      case xtd::forms::known_themed_color::control_dark_dark: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::control_light: return xtd::drawing::color::from_argb(0xFF333333);
      case xtd::forms::known_themed_color::control_light_light: return xtd::drawing::color::from_argb(0xFF373737);
      case xtd::forms::known_themed_color::control_text: return xtd::drawing::color::from_argb(0xFFEEEEEC);
      case xtd::forms::known_themed_color::desktop: return xtd::drawing::color::from_argb(0xFF333333);
      case xtd::forms::known_themed_color::gradient_active_caption: return xtd::drawing::color::from_argb(0xFF282828);
      case xtd::forms::known_themed_color::gradient_inactive_caption: return xtd::drawing::color::from_argb(0xFF353535);
      case xtd::forms::known_themed_color::gray_text: return xtd::drawing::color::from_argb(0xFF919190);
      case xtd::forms::known_themed_color::highlight: return xtd::drawing::color::from_argb(0xFF15539E);
      case xtd::forms::known_themed_color::highlight_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::hot_track: return xtd::drawing::color::from_argb(0xFF3584E4);
      case xtd::forms::known_themed_color::inactive_border: return xtd::drawing::color::from_argb(0xFF333333);
      case xtd::forms::known_themed_color::inactive_caption: return xtd::drawing::color::from_argb(0xFF353535);
      case xtd::forms::known_themed_color::inactive_caption_text: return xtd::drawing::color::from_argb(0xFFEEEEEC);
      case xtd::forms::known_themed_color::info: return xtd::drawing::color::from_argb(0xCC000000);
      case xtd::forms::known_themed_color::info_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::menu: return xtd::drawing::color::from_argb(0xFF2F2F2F);
      case xtd::forms::known_themed_color::menu_bar: return xtd::drawing::color::from_argb(0xFF353535);
      case xtd::forms::known_themed_color::menu_highlight: return xtd::drawing::color::from_argb(0xFF15539E);
      case xtd::forms::known_themed_color::menu_text: return xtd::drawing::color::from_argb(0xFFEEEEEC);
      case xtd::forms::known_themed_color::scroll_bar: return xtd::drawing::color::from_argb(0xFF333333);
      case xtd::forms::known_themed_color::text_box: return xtd::drawing::color::from_argb(0xFF2D2D2D);
      case xtd::forms::known_themed_color::text_box_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::window: return xtd::drawing::color::from_argb(0xFF2D2D2D);
      case xtd::forms::known_themed_color::window_frame: return xtd::drawing::color::from_argb(0xFF333333);
      case xtd::forms::known_themed_color::window_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      default: throw argument_exception("unknown know_color"_t, current_stack_frame_);
    }
  }

  color gnome_light_color_getter(known_themed_color color) {
    switch (color) {
      case xtd::forms::known_themed_color::accent: return xtd::drawing::color::from_argb(0xFF3584E4);
      case xtd::forms::known_themed_color::accent_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::active_border: return xtd::drawing::color::from_argb(0xFFF1F0EE);
      case xtd::forms::known_themed_color::active_caption: return xtd::drawing::color::from_argb(0xFFDDDAD6);
      case xtd::forms::known_themed_color::active_caption_text: return xtd::drawing::color::from_argb(0xFF2E3436);
      case xtd::forms::known_themed_color::app_workspace: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::button_face: return xtd::drawing::color::from_argb(0xFFF1F0EE);
      case xtd::forms::known_themed_color::button_highlight: return xtd::drawing::color::from_argb(0xFFF8F8F7);
      case xtd::forms::known_themed_color::button_shadow: return xtd::drawing::color::from_argb(0xFFCDC7C2);
      case xtd::forms::known_themed_color::control: return xtd::drawing::color::from_argb(0xFFF1F0EE);
      case xtd::forms::known_themed_color::control_dark: return xtd::drawing::color::from_argb(0xFFCDC7C2);
      case xtd::forms::known_themed_color::control_dark_dark: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::control_light: return xtd::drawing::color::from_argb(0xFFF1F0EE);
      case xtd::forms::known_themed_color::control_light_light: return xtd::drawing::color::from_argb(0xFFF8F8F7);
      case xtd::forms::known_themed_color::control_text: return xtd::drawing::color::from_argb(0xFF2E3436);
      case xtd::forms::known_themed_color::desktop: return xtd::drawing::color::from_argb(0xFFF1F0EE);
      case xtd::forms::known_themed_color::gradient_active_caption: return xtd::drawing::color::from_argb(0xFFDDDAD6);
      case xtd::forms::known_themed_color::gradient_inactive_caption: return xtd::drawing::color::from_argb(0xFFF6F5F4);
      case xtd::forms::known_themed_color::gray_text: return xtd::drawing::color::from_argb(0xFF929595);
      case xtd::forms::known_themed_color::highlight: return xtd::drawing::color::from_argb(0xFF3584E4);
      case xtd::forms::known_themed_color::highlight_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::hot_track: return xtd::drawing::color::from_argb(0xFF1B6ACB);
      case xtd::forms::known_themed_color::inactive_border: return xtd::drawing::color::from_argb(0xFFF1F0EE);
      case xtd::forms::known_themed_color::inactive_caption: return xtd::drawing::color::from_argb(0xFFF6F5F4);
      case xtd::forms::known_themed_color::inactive_caption_text: return xtd::drawing::color::from_argb(0xFF2E3436);
      case xtd::forms::known_themed_color::info: return xtd::drawing::color::from_argb(0xCC000000);
      case xtd::forms::known_themed_color::info_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::menu: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::menu_bar: return xtd::drawing::color::from_argb(0xFFF6F5F4);
      case xtd::forms::known_themed_color::menu_highlight: return xtd::drawing::color::from_argb(0xFF3584E4);
      case xtd::forms::known_themed_color::menu_text: return xtd::drawing::color::from_argb(0xFF2E3436);
      case xtd::forms::known_themed_color::scroll_bar: return xtd::drawing::color::from_argb(0xFFF1F0EE);
      case xtd::forms::known_themed_color::text_box: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::text_box_text: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::window: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::window_frame: return xtd::drawing::color::from_argb(0xFFF1F0EE);
      case xtd::forms::known_themed_color::window_text: return xtd::drawing::color::from_argb(0xFF000000);
      default: throw argument_exception("unknown know_color"_t, current_stack_frame_);
    }
  }

  color gnome_color_getter(known_themed_color color) {
    return xtd::drawing::system_colors::window().get_lightness() < 0.5 ? gnome_dark_color_getter(color) : gnome_light_color_getter(color);
  }

  color kde_dark_color_getter(known_themed_color color) {
    switch (color) {
      case xtd::forms::known_themed_color::accent: return xtd::drawing::color::from_argb(0xFF3DAEE9);
      case xtd::forms::known_themed_color::accent_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::active_border: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::active_caption: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::active_caption_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::app_workspace: return xtd::drawing::color::from_argb(0xFF232629);
      case xtd::forms::known_themed_color::button_face: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::button_highlight: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::button_shadow: return xtd::drawing::color::from_argb(0xFF606468);
      case xtd::forms::known_themed_color::control: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::control_dark: return xtd::drawing::color::from_argb(0xFF606468);
      case xtd::forms::known_themed_color::control_dark_dark: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::control_light: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::control_light_light: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::control_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::desktop: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::gradient_active_caption: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::gradient_inactive_caption: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::gray_text: return xtd::drawing::color::from_argb(0xFF6E7175);
      case xtd::forms::known_themed_color::highlight: return xtd::drawing::color::from_argb(0xFF3DAEE9);
      case xtd::forms::known_themed_color::highlight_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::hot_track: return xtd::drawing::color::from_argb(0xFF2980B9);
      case xtd::forms::known_themed_color::inactive_border: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::inactive_caption: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::inactive_caption_text: return xtd::drawing::color::from_argb(0xFF7F8C8D);
      case xtd::forms::known_themed_color::info: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::info_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::menu: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::menu_bar: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::menu_highlight: return xtd::drawing::color::from_argb(0xFF3DAEE9);
      case xtd::forms::known_themed_color::menu_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::scroll_bar: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::text_box: return xtd::drawing::color::from_argb(0xFF232629);
      case xtd::forms::known_themed_color::text_box_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::window: return xtd::drawing::color::from_argb(0xFF232629);
      case xtd::forms::known_themed_color::window_frame: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::window_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      default: throw argument_exception("unknown know_color"_t, current_stack_frame_);
    }
  }

  color kde_light_color_getter(known_themed_color color) {
    switch (color) {
      case xtd::forms::known_themed_color::accent: return xtd::drawing::color::from_argb(0xFF3DAEE9);
      case xtd::forms::known_themed_color::accent_text: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::active_border: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::active_caption: return xtd::drawing::color::from_argb(0xFF475057);
      case xtd::forms::known_themed_color::active_caption_text: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::app_workspace: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::button_face: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::button_highlight: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::button_shadow: return xtd::drawing::color::from_argb(0xFFBCBEBF);
      case xtd::forms::known_themed_color::control: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::control_dark: return xtd::drawing::color::from_argb(0xFFBCBEBF);
      case xtd::forms::known_themed_color::control_dark_dark: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::control_light: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::control_light_light: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::control_text: return xtd::drawing::color::from_argb(0xFF232627);
      case xtd::forms::known_themed_color::desktop: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::gradient_active_caption: return xtd::drawing::color::from_argb(0xFF475057);
      case xtd::forms::known_themed_color::gradient_inactive_caption: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::gray_text: return xtd::drawing::color::from_argb(0xFFA0A2A2);
      case xtd::forms::known_themed_color::highlight: return xtd::drawing::color::from_argb(0xFF3DAEE9);
      case xtd::forms::known_themed_color::highlight_text: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::hot_track: return xtd::drawing::color::from_argb(0xFF2980B9);
      case xtd::forms::known_themed_color::inactive_border: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::inactive_caption: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::inactive_caption_text: return xtd::drawing::color::from_argb(0xFFBDC3C7);
      case xtd::forms::known_themed_color::info: return xtd::drawing::color::from_argb(0xFF232627);
      case xtd::forms::known_themed_color::info_text: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::menu: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::menu_bar: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::menu_highlight: return xtd::drawing::color::from_argb(0xFF3DAEE9);
      case xtd::forms::known_themed_color::menu_text: return xtd::drawing::color::from_argb(0xFF232627);
      case xtd::forms::known_themed_color::scroll_bar: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::text_box: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::text_box_text: return xtd::drawing::color::from_argb(0xFF232627);
      case xtd::forms::known_themed_color::window: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::window_frame: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::window_text: return xtd::drawing::color::from_argb(0xFF23262);
      default: throw argument_exception("unknown know_color"_t, current_stack_frame_);
    }
  }

  color kde_color_getter(known_themed_color color) {
    return xtd::drawing::system_colors::window().get_lightness() < 0.5 ? kde_dark_color_getter(color) : kde_light_color_getter(color);
  }

  color macos_dark_color_getter(known_themed_color color) {
    switch (color) {
      case xtd::forms::known_themed_color::accent: return xtd::drawing::color::from_argb(0xFF007AFF);
      case xtd::forms::known_themed_color::accent_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::active_border: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFF4A4A4A : 0x19FFFFFF);
      case xtd::forms::known_themed_color::active_caption: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::active_caption_text: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFFE3E3E3 : 0xD8FFFFFF);
      case xtd::forms::known_themed_color::app_workspace: return xtd::drawing::color::from_argb(0xFF262626);
      case xtd::forms::known_themed_color::button_face: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFF6B6B6B : 0x3FFFFFFF);
      case xtd::forms::known_themed_color::button_highlight: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFF4A4A4A : 0x19FFFFFF);
      case xtd::forms::known_themed_color::button_shadow: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFF232323 : 0x44000000);
      case xtd::forms::known_themed_color::control: return xtd::drawing::color::from_argb(0xFF323232);
      case xtd::forms::known_themed_color::control_dark: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFF232323 : 0x44000000);
      case xtd::forms::known_themed_color::control_dark_dark: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFF232323 : 0x44000000);
      case xtd::forms::known_themed_color::control_light: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFF4A4A4A : 0x19FFFFFF);
      case xtd::forms::known_themed_color::control_light_light: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFF4A4A4A : 0x19FFFFFF);
      case xtd::forms::known_themed_color::control_text: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFFE3E3E3 : 0xD8FFFFFF);
      case xtd::forms::known_themed_color::desktop: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::gradient_active_caption: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::gradient_inactive_caption: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::gray_text: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFF6B6B6B : 0x3FFFFFFF);
      case xtd::forms::known_themed_color::highlight: return xtd::drawing::color::from_argb(0xFF314F78);
      case xtd::forms::known_themed_color::highlight_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::hot_track: return xtd::drawing::color::from_argb(0xFF3586FF);
      case xtd::forms::known_themed_color::inactive_border: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::inactive_caption: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::inactive_caption_text: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFF6B6B6B : 0x3FFFFFFF);
      case xtd::forms::known_themed_color::info: return xtd::drawing::color::from_argb(0xFF262626);
      case xtd::forms::known_themed_color::info_text: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFFE3E3E3 : 0xD8FFFFFF);
      case xtd::forms::known_themed_color::menu: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::menu_bar: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::menu_highlight: return xtd::drawing::color::from_argb(0xFF345DF1);
      case xtd::forms::known_themed_color::menu_text: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFFE3E3E3 : 0xD8FFFFFF);
      case xtd::forms::known_themed_color::scroll_bar: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::text_box: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFF414141 : 0x10FFFFFF);
      case xtd::forms::known_themed_color::text_box_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::window: return xtd::drawing::color::from_argb(0xFF171717);
      case xtd::forms::known_themed_color::window_frame: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::window_text: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFFE3E3E3 : 0xD8FFFFFF);
      default: throw argument_exception("unknown know_color"_t, current_stack_frame_);
    }
  }

  color macos_light_color_getter(known_themed_color color) {
    switch (color) {
      case xtd::forms::known_themed_color::accent: return xtd::drawing::color::from_argb(0xFF007AFF);
      case xtd::forms::known_themed_color::accent_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::active_border: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::active_caption: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::active_caption_text: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFF282828 : 0xD8000000);
      case xtd::forms::known_themed_color::app_workspace: return xtd::drawing::color::from_argb(0xFFE7E7E7);
      case xtd::forms::known_themed_color::button_face: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::button_highlight: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::button_shadow: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFFB4B4B4 : 0x44000000);
      case xtd::forms::known_themed_color::control: return xtd::drawing::color::from_argb(0xFFECECEC);
      case xtd::forms::known_themed_color::control_dark: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFFB4B4B4 : 0x44000000);
      case xtd::forms::known_themed_color::control_dark_dark: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFFB4B4B4 : 0x44000000);
      case xtd::forms::known_themed_color::control_light: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::control_light_light: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::control_text: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFF282828 : 0xD8000000);
      case xtd::forms::known_themed_color::desktop: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::gradient_active_caption: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::gradient_inactive_caption: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::gray_text: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFFB8B8B8 : 0x3F000000);
      case xtd::forms::known_themed_color::highlight: return xtd::drawing::color::from_argb(0xFFA5CDFF);
      case xtd::forms::known_themed_color::highlight_text: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::hot_track: return xtd::drawing::color::from_argb(0xFF094FD1);
      case xtd::forms::known_themed_color::inactive_border: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::inactive_caption: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::inactive_caption_text: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFFB8B8B8 : 0x3F000000);
      case xtd::forms::known_themed_color::info: return xtd::drawing::color::from_argb(0xFFE7E7E7);
      case xtd::forms::known_themed_color::info_text: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFF282828 : 0xD8000000);
      case xtd::forms::known_themed_color::menu: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::menu_bar: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::menu_highlight: return xtd::drawing::color::from_argb(0xFF345DF1);
      case xtd::forms::known_themed_color::menu_text: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFF282828 : 0xD8000000);
      case xtd::forms::known_themed_color::scroll_bar: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::text_box: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::text_box_text: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::window: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::window_frame: return xtd::drawing::color::from_argb(0xFF9A9A9A);
      case xtd::forms::known_themed_color::window_text: return xtd::drawing::color::from_argb(environment::os_version().is_windows_platform() ? 0xFF282828 : 0xD8000000);
      default: throw argument_exception("unknown know_color"_t, current_stack_frame_);
    }
  }

  color macos_color_getter(known_themed_color color) {
    return xtd::drawing::system_colors::window().get_lightness() < 0.5 ? macos_dark_color_getter(color) : macos_light_color_getter(color);
  }

  color symbolic_dark_color_getter(known_themed_color color) {
    switch (color) {
      case xtd::forms::known_themed_color::accent: return xtd::drawing::color::from_argb(0xFF3DAEE9);
      case xtd::forms::known_themed_color::accent_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::active_border: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::active_caption: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::active_caption_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::app_workspace: return xtd::drawing::color::from_argb(0xFF232629);
      case xtd::forms::known_themed_color::button_face: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::button_highlight: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::button_shadow: return xtd::drawing::color::from_argb(0xFF606468);
      case xtd::forms::known_themed_color::control: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::control_dark: return xtd::drawing::color::from_argb(0xFF606468);
      case xtd::forms::known_themed_color::control_dark_dark: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::control_light: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::control_light_light: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::control_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::desktop: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::gradient_active_caption: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::gradient_inactive_caption: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::gray_text: return xtd::drawing::color::from_argb(0xFF6E7175);
      case xtd::forms::known_themed_color::highlight: return xtd::drawing::color::from_argb(0xFF3DAEE9);
      case xtd::forms::known_themed_color::highlight_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::hot_track: return xtd::drawing::color::from_argb(0xFF2980B9);
      case xtd::forms::known_themed_color::inactive_border: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::inactive_caption: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::inactive_caption_text: return xtd::drawing::color::from_argb(0xFF7F8C8D);
      case xtd::forms::known_themed_color::info: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::info_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::menu: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::menu_bar: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::menu_highlight: return xtd::drawing::color::from_argb(0xFF3DAEE9);
      case xtd::forms::known_themed_color::menu_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::scroll_bar: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::text_box: return xtd::drawing::color::from_argb(0xFF232629);
      case xtd::forms::known_themed_color::text_box_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::window: return xtd::drawing::color::from_argb(0xFF232629);
      case xtd::forms::known_themed_color::window_frame: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::window_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      default: throw argument_exception("unknown know_color"_t, current_stack_frame_);
    }
  }

  color symbolic_light_color_getter(known_themed_color color) {
    switch (color) {
      case xtd::forms::known_themed_color::accent: return xtd::drawing::color::from_argb(0xFF3DAEE9);
      case xtd::forms::known_themed_color::accent_text: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::active_border: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::active_caption: return xtd::drawing::color::from_argb(0xFF475057);
      case xtd::forms::known_themed_color::active_caption_text: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::app_workspace: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::button_face: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::button_highlight: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::button_shadow: return xtd::drawing::color::from_argb(0xFFBCBEBF);
      case xtd::forms::known_themed_color::control: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::control_dark: return xtd::drawing::color::from_argb(0xFFBCBEBF);
      case xtd::forms::known_themed_color::control_dark_dark: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::control_light: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::control_light_light: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::control_text: return xtd::drawing::color::from_argb(0xFF232627);
      case xtd::forms::known_themed_color::desktop: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::gradient_active_caption: return xtd::drawing::color::from_argb(0xFF475057);
      case xtd::forms::known_themed_color::gradient_inactive_caption: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::gray_text: return xtd::drawing::color::from_argb(0xFFA0A2A2);
      case xtd::forms::known_themed_color::highlight: return xtd::drawing::color::from_argb(0xFF3DAEE9);
      case xtd::forms::known_themed_color::highlight_text: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::hot_track: return xtd::drawing::color::from_argb(0xFF2980B9);
      case xtd::forms::known_themed_color::inactive_border: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::inactive_caption: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::inactive_caption_text: return xtd::drawing::color::from_argb(0xFFBDC3C7);
      case xtd::forms::known_themed_color::info: return xtd::drawing::color::from_argb(0xFF232627);
      case xtd::forms::known_themed_color::info_text: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::menu: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::menu_bar: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::menu_highlight: return xtd::drawing::color::from_argb(0xFF3DAEE9);
      case xtd::forms::known_themed_color::menu_text: return xtd::drawing::color::from_argb(0xFF232627);
      case xtd::forms::known_themed_color::scroll_bar: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::text_box: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::text_box_text: return xtd::drawing::color::from_argb(0xFF232627);
      case xtd::forms::known_themed_color::window: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::window_frame: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::window_text: return xtd::drawing::color::from_argb(0xFF23262);
      default: throw argument_exception("unknown know_color"_t, current_stack_frame_);
    }
  }

  color symbolic_color_getter(known_themed_color color) {
    return xtd::drawing::system_colors::window().get_lightness() < 0.5 ? symbolic_dark_color_getter(color) : symbolic_light_color_getter(color);
  }

  color windows_dark_color_getter(known_themed_color color) {
    switch (color) {
      case xtd::forms::known_themed_color::accent: return xtd::drawing::color::from_argb(0xFF00A0FA);
      case xtd::forms::known_themed_color::accent_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::active_border: return xtd::drawing::color::from_argb(0xFF2C2C2C);
      case xtd::forms::known_themed_color::active_caption: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::active_caption_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::app_workspace: return xtd::drawing::color::from_argb(0xFF191919);
      case xtd::forms::known_themed_color::button_face: return xtd::drawing::color::from_argb(0xFF353535);
      case xtd::forms::known_themed_color::button_highlight: return xtd::drawing::color::from_argb(0xFF00A0FA);
      case xtd::forms::known_themed_color::button_shadow: return xtd::drawing::color::from_argb(0xFF232323);
      case xtd::forms::known_themed_color::control: return xtd::drawing::color::from_argb(0xFF191919);
      case xtd::forms::known_themed_color::control_dark: return xtd::drawing::color::from_argb(0xFF232323);
      case xtd::forms::known_themed_color::control_dark_dark: return xtd::drawing::color::from_argb(0xFF171717);
      case xtd::forms::known_themed_color::control_light: return xtd::drawing::color::from_argb(0xFF4A4A4A);
      case xtd::forms::known_themed_color::control_light_light: return xtd::drawing::color::from_argb(0xFF4A4A4A);
      case xtd::forms::known_themed_color::control_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::desktop: return xtd::drawing::color::from_argb(0xFF0078D7);
      case xtd::forms::known_themed_color::gradient_active_caption: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::gradient_inactive_caption: return xtd::drawing::color::from_argb(0xFF2B2B2B);
      case xtd::forms::known_themed_color::gray_text: return xtd::drawing::color::from_argb(0xFF6B6B6B);
      case xtd::forms::known_themed_color::highlight: return xtd::drawing::color::from_argb(0xFF4D4D4D);
      case xtd::forms::known_themed_color::highlight_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::hot_track: return xtd::drawing::color::from_argb(0xFF4D4D4D);
      case xtd::forms::known_themed_color::inactive_border: return xtd::drawing::color::from_argb(0xFF414143);
      case xtd::forms::known_themed_color::inactive_caption: return xtd::drawing::color::from_argb(0xFF2B2B2B);
      case xtd::forms::known_themed_color::inactive_caption_text: return xtd::drawing::color::from_argb(0xFF494949);
      case xtd::forms::known_themed_color::info: return xtd::drawing::color::from_argb(0xFF2B2B2B);
      case xtd::forms::known_themed_color::info_text: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::menu: return xtd::drawing::color::from_argb(0xFF2B2B2B);
      case xtd::forms::known_themed_color::menu_bar: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::menu_highlight: return xtd::drawing::color::from_argb(0xFF0078D7);
      case xtd::forms::known_themed_color::menu_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::scroll_bar: return xtd::drawing::color::from_argb(0xFF171717);
      case xtd::forms::known_themed_color::text_box: return xtd::drawing::color::from_argb(0xFF121212);
      case xtd::forms::known_themed_color::text_box_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::window: return xtd::drawing::color::from_argb(0xFF202020);
      case xtd::forms::known_themed_color::window_frame: return xtd::drawing::color::from_argb(0xFF333333);
      case xtd::forms::known_themed_color::window_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      default: throw argument_exception("unknown know_color"_t, current_stack_frame_);
    }
  }

  color windows_light_color_getter(known_themed_color color) {
    switch (color) {
      case xtd::forms::known_themed_color::accent: return xtd::drawing::color::from_argb(0xFFD2E8F8);
      case xtd::forms::known_themed_color::accent_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::active_border: return xtd::drawing::color::from_argb(0xFFB4B4B4);
      case xtd::forms::known_themed_color::active_caption: return xtd::drawing::color::from_argb(0xFF99B4D1);
      case xtd::forms::known_themed_color::active_caption_text: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::app_workspace: return xtd::drawing::color::from_argb(0xFFABABAB);
      case xtd::forms::known_themed_color::button_face: return xtd::drawing::color::from_argb(0xFFE1E1E1);
      case xtd::forms::known_themed_color::button_highlight: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::button_shadow: return xtd::drawing::color::from_argb(0xFFA0A0A0);
      case xtd::forms::known_themed_color::control: return xtd::drawing::color::from_argb(0xFFF0F0F0);
      case xtd::forms::known_themed_color::control_dark: return xtd::drawing::color::from_argb(0xFFA0A0A0);
      case xtd::forms::known_themed_color::control_dark_dark: return xtd::drawing::color::from_argb(0xFF696969);
      case xtd::forms::known_themed_color::control_light: return xtd::drawing::color::from_argb(0xFFE3E3E3);
      case xtd::forms::known_themed_color::control_light_light: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::control_text: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::desktop: return xtd::drawing::color::from_argb(0xFF0078D7);
      case xtd::forms::known_themed_color::gradient_active_caption: return xtd::drawing::color::from_argb(0xFFB9D1EA);
      case xtd::forms::known_themed_color::gradient_inactive_caption: return xtd::drawing::color::from_argb(0xFFD7E4F2);
      case xtd::forms::known_themed_color::gray_text: return xtd::drawing::color::from_argb(0xFF6D6D6D);
      case xtd::forms::known_themed_color::highlight: return xtd::drawing::color::from_argb(0xFF0078D7);
      case xtd::forms::known_themed_color::highlight_text: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::hot_track: return xtd::drawing::color::from_argb(0xFF0066CC);
      case xtd::forms::known_themed_color::inactive_border: return xtd::drawing::color::from_argb(0xFFF4F7FC);
      case xtd::forms::known_themed_color::inactive_caption: return xtd::drawing::color::from_argb(0xFFBFCDDB);
      case xtd::forms::known_themed_color::inactive_caption_text: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::info: return xtd::drawing::color::from_argb(0xFFFFFFE1);
      case xtd::forms::known_themed_color::info_text: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::menu: return xtd::drawing::color::from_argb(0xFFF0F0F0);
      case xtd::forms::known_themed_color::menu_bar: return xtd::drawing::color::from_argb(0xFFF0F0F0);
      case xtd::forms::known_themed_color::menu_highlight: return xtd::drawing::color::from_argb(0xFF0078D7);
      case xtd::forms::known_themed_color::menu_text: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::scroll_bar: return xtd::drawing::color::from_argb(0xFFC8C8C8);
      case xtd::forms::known_themed_color::text_box: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::text_box_text: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::window: return xtd::drawing::color::from_argb(0xFFFFFFFF);
      case xtd::forms::known_themed_color::window_frame: return xtd::drawing::color::from_argb(0xFF646464);
      case xtd::forms::known_themed_color::window_text: return xtd::drawing::color::from_argb(0xFF000000);
      default: throw argument_exception("unknown know_color"_t, current_stack_frame_);
    }
  }

  color windows_color_getter(known_themed_color color) {
    return xtd::drawing::system_colors::window().get_lightness() < 0.5 ? windows_dark_color_getter(color) : windows_light_color_getter(color);
  }

  color xtd_dark_color_getter(known_themed_color color) {
    switch (color) {
      case xtd::forms::known_themed_color::accent: return xtd::drawing::color::from_argb(0xFF3DAEE9);
      case xtd::forms::known_themed_color::accent_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::active_border: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::active_caption: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::active_caption_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::app_workspace: return xtd::drawing::color::from_argb(0xFF232629);
      case xtd::forms::known_themed_color::button_face: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::button_highlight: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::button_shadow: return xtd::drawing::color::from_argb(0xFF606468);
      case xtd::forms::known_themed_color::control: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::control_dark: return xtd::drawing::color::from_argb(0xFF606468);
      case xtd::forms::known_themed_color::control_dark_dark: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::control_light: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::control_light_light: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::control_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::desktop: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::gradient_active_caption: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::gradient_inactive_caption: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::gray_text: return xtd::drawing::color::from_argb(0xFF6E7175);
      case xtd::forms::known_themed_color::highlight: return xtd::drawing::color::from_argb(0xFF3DAEE9);
      case xtd::forms::known_themed_color::highlight_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::hot_track: return xtd::drawing::color::from_argb(0xFF2980B9);
      case xtd::forms::known_themed_color::inactive_border: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::inactive_caption: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::inactive_caption_text: return xtd::drawing::color::from_argb(0xFF7F8C8D);
      case xtd::forms::known_themed_color::info: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::info_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::menu: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::menu_bar: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::menu_highlight: return xtd::drawing::color::from_argb(0xFF3DAEE9);
      case xtd::forms::known_themed_color::menu_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::scroll_bar: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::text_box: return xtd::drawing::color::from_argb(0xFF232629);
      case xtd::forms::known_themed_color::text_box_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::window: return xtd::drawing::color::from_argb(0xFF232629);
      case xtd::forms::known_themed_color::window_frame: return xtd::drawing::color::from_argb(0xFF31363B);
      case xtd::forms::known_themed_color::window_text: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      default: throw argument_exception("unknown know_color"_t, current_stack_frame_);
    }
  }

  color xtd_light_color_getter(known_themed_color color) {
    switch (color) {
      case xtd::forms::known_themed_color::accent: return xtd::drawing::color::from_argb(0xFF3DAEE9);
      case xtd::forms::known_themed_color::accent_text: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::active_border: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::active_caption: return xtd::drawing::color::from_argb(0xFF475057);
      case xtd::forms::known_themed_color::active_caption_text: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::app_workspace: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::button_face: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::button_highlight: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::button_shadow: return xtd::drawing::color::from_argb(0xFFBCBEBF);
      case xtd::forms::known_themed_color::control: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::control_dark: return xtd::drawing::color::from_argb(0xFFBCBEBF);
      case xtd::forms::known_themed_color::control_dark_dark: return xtd::drawing::color::from_argb(0xFF000000);
      case xtd::forms::known_themed_color::control_light: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::control_light_light: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::control_text: return xtd::drawing::color::from_argb(0xFF232627);
      case xtd::forms::known_themed_color::desktop: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::gradient_active_caption: return xtd::drawing::color::from_argb(0xFF475057);
      case xtd::forms::known_themed_color::gradient_inactive_caption: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::gray_text: return xtd::drawing::color::from_argb(0xFFA0A2A2);
      case xtd::forms::known_themed_color::highlight: return xtd::drawing::color::from_argb(0xFF3DAEE9);
      case xtd::forms::known_themed_color::highlight_text: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::hot_track: return xtd::drawing::color::from_argb(0xFF2980B9);
      case xtd::forms::known_themed_color::inactive_border: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::inactive_caption: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::inactive_caption_text: return xtd::drawing::color::from_argb(0xFFBDC3C7);
      case xtd::forms::known_themed_color::info: return xtd::drawing::color::from_argb(0xFF232627);
      case xtd::forms::known_themed_color::info_text: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::menu: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::menu_bar: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::menu_highlight: return xtd::drawing::color::from_argb(0xFF3DAEE9);
      case xtd::forms::known_themed_color::menu_text: return xtd::drawing::color::from_argb(0xFF232627);
      case xtd::forms::known_themed_color::scroll_bar: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::text_box: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::text_box_text: return xtd::drawing::color::from_argb(0xFF232627);
      case xtd::forms::known_themed_color::window: return xtd::drawing::color::from_argb(0xFFFCFCFC);
      case xtd::forms::known_themed_color::window_frame: return xtd::drawing::color::from_argb(0xFFEFF0F1);
      case xtd::forms::known_themed_color::window_text: return xtd::drawing::color::from_argb(0xFF23262);
      default: throw argument_exception("unknown know_color"_t, current_stack_frame_);
    }
  }

  color xtd_color_getter(known_themed_color color) {
    return xtd::drawing::system_colors::window().get_lightness() < 0.5 ? xtd_dark_color_getter(color) : xtd_light_color_getter(color);
  }
}

const theme_colors theme_colors::empty {};
theme_colors theme_colors::current_theme_;

theme_colors theme_colors::theme_from_name(const xtd::ustring& name) {
  if (name == default_theme_name()) return theme_colors(default_theme_name(), theme_style::system_auto, {system_color_getter}, true);
  if (name == "gnome") return theme_colors("gnome", theme_style::system_auto, {gnome_color_getter});
  if (name == "gnome (dark)") return theme_colors("gnome (dark)", theme_style::dark, {gnome_dark_color_getter});
  if (name == "gnome (light)") return theme_colors("gnome (light)", theme_style::light, {gnome_light_color_getter});
  if (name == "kde") return theme_colors("kde", theme_style::system_auto, {kde_color_getter});
  if (name == "kde (dark)") return theme_colors("kde (dark)", theme_style::dark, {kde_dark_color_getter});
  if (name == "kde (light)") return theme_colors("kde (light)", theme_style::light, {kde_light_color_getter});
  if (name == "macos") return theme_colors("macos", theme_style::system_auto, {macos_color_getter});
  if (name == "macos (dark)") return theme_colors("macos (dark)", theme_style::dark, {macos_dark_color_getter});
  if (name == "macos (light)") return theme_colors("macos (light)", theme_style::light, {macos_light_color_getter});
  if (name == "symbolic") return theme_colors("symbolic", theme_style::system_auto, {symbolic_color_getter});
  if (name == "symbolic (dark)") return theme_colors("symbolic (dark)", theme_style::dark, {symbolic_dark_color_getter});
  if (name == "symbolic (light)") return theme_colors("symbolic (light)", theme_style::light, {symbolic_light_color_getter});
  if (name == "windows") return theme_colors("windows", theme_style::system_auto, {windows_color_getter});
  if (name == "windows (dark)") return theme_colors("windows (dark)", theme_style::dark, {windows_dark_color_getter});
  if (name == "windows (light)") return theme_colors("windows (light)", theme_style::light, {windows_light_color_getter});
  if (name == "xtd") return theme_colors("xtd", theme_style::system_auto, {xtd_color_getter});
  if (name == "xtd (dark)") return theme_colors("xtd (dark)", theme_style::dark, {xtd_dark_color_getter});
  if (name == "xtd (light)") return theme_colors("xtd (light)", theme_style::light, {xtd_light_color_getter});
  return current_theme_;
}
