#include "../../../../include/xtd/forms/style_sheets/style_sheet.h"
#include <xtd/drawing/system_colors.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::web::css;

namespace {
  style_sheet::buttons_t get_buttons() {
    return style_sheet::buttons_t {
      // :standard
      {xtd::forms::style_sheets::pseudo_state::standard, style_sheets::button().margin({2, 0, 1, 0}).border_style(border_type::outset).border_color(drawing::system_colors::control_dark()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_image({image_type::linear_gradient, {drawing::system_colors::button_face(), drawing::system_colors::button_face()}, 180}).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::pressed, style_sheets::button().margin({2, 0,1, 0}).border_style(border_type::outset).border_color(drawing::system_colors::control_dark()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(93, 255, 255, 255)).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::checked, style_sheets::button().margin({2, 0,1, 0}).border_style(border_type::outset).border_color(drawing::system_colors::control_dark()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(93, 255, 255, 255)).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::mixed, style_sheets::button().margin({2, 0,1, 0}).border_style(border_type::outset).border_color(drawing::system_colors::control_dark()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(78, 255, 255, 255)).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::hover, style_sheets::button().margin({2, 0,1, 0}).border_style(border_type::outset).border_color(drawing::system_colors::control_dark()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(drawing::system_colors::button_face()).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::disabled, style_sheets::button().margin({2, 0,1, 0}).border_style(border_type::outset).border_color(drawing::system_colors::control_dark()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(35, 255, 255, 255)).color(drawing::system_colors::gray_text())},
      // :standard:default
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state, style_sheets::button().margin({2, 0,1, 0}).border_style(border_type::outset).border_color(drawing::system_colors::control_dark()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_image({image_type::linear_gradient, {color::from_argb(0xFF177AE5), color::from_argb(0xFF166ECD)}, 180}).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::pressed, style_sheets::button().margin({2, 0,1, 0}).border_style(border_type::outset).border_color(drawing::system_colors::control_dark()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_image({image_type::linear_gradient, {color::from_argb(0xFF24A0F2), color::from_argb(0xFF2194E5)}, 180}).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::checked, style_sheets::button().margin({2, 0,1, 0}).border_style(border_type::outset).border_color(drawing::system_colors::control_dark()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_image({image_type::linear_gradient, {color::from_argb(0xFF24A0F2), color::from_argb(0xFF2194E5)}, 180}).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::mixed, style_sheets::button().margin({2, 0,1, 0}).border_style(border_type::outset).border_color(drawing::system_colors::control_dark()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_image({image_type::linear_gradient, {color::from_argb(0xFF24A0F2), color::from_argb(0xFF2194E5)}, 180}).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::hover, style_sheets::button().margin({2, 0,1, 0}).border_style(border_type::outset).border_color(drawing::system_colors::control_dark()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_image({image_type::linear_gradient, {color::from_argb(0xFF177AE5), color::from_argb(0xFF166ECD)}, 180}).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::disabled, style_sheets::button().margin({2, 0,1, 0}).border_style(border_type::outset).border_color(drawing::system_colors::control_dark()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_image({image_type::linear_gradient, {color::from_argb(35, 255, 255, 255), color::from_argb(35, 255, 255, 255)}, 180}).color(drawing::system_colors::gray_text())},
      // :flat
      {xtd::forms::style_sheets::pseudo_state::flat, style_sheets::button().border_style(border_type::solid).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(drawing::system_colors::control()).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::pressed, style_sheets::button().border_style(border_type::solid).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(93, 255, 255, 255)).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::checked, style_sheets::button().border_style(border_type::solid).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(93, 255, 255, 255)).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::mixed, style_sheets::button().border_style(border_type::solid).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(78, 255, 255, 255)).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::hover, style_sheets::button().border_style(border_type::solid).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(78, 255, 255, 255)).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::disabled, style_sheets::button().border_style(border_type::solid).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(30, 255, 255, 255)).color(drawing::system_colors::gray_text())},
      // :flat:default
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state, style_sheets::button().border_style(border_type::solid).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(drawing::system_colors::control()).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::pressed, style_sheets::button().border_style(border_type::solid).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(93, 255, 255, 255)).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::checked, style_sheets::button().border_style(border_type::solid).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(93, 255, 255, 255)).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::mixed, style_sheets::button().border_style(border_type::solid).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(78, 255, 255, 255)).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::hover, style_sheets::button().border_style(border_type::solid).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(78, 255, 255, 255)).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::disabled, style_sheets::button().border_style(border_type::solid).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(30, 255, 255, 255)).color(drawing::system_colors::gray_text())},
      // :popup
      {xtd::forms::style_sheets::pseudo_state::popup, style_sheets::button().border_style(border_type::solid).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(drawing::system_colors::control()).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::pressed, style_sheets::button().border_style(border_type::inset).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(93, 255, 255, 255)).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::checked, style_sheets::button().border_style(border_type::inset).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(93, 255, 255, 255)).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::mixed, style_sheets::button().border_style(border_type::inset).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(78, 255, 255, 255)).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::hover, style_sheets::button().border_style(border_type::outset).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(78, 255, 255, 255)).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::disabled, style_sheets::button().border_style(border_type::solid).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(30, 255, 255, 255)).color(drawing::system_colors::gray_text())},
      // :popup:default
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state, style_sheets::button().border_style(border_type::solid).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(drawing::system_colors::control()).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::pressed, style_sheets::button().border_style(border_type::inset).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(93, 255, 255, 255)).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::checked, style_sheets::button().border_style(border_type::inset).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(93, 255, 255, 255)).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::mixed, style_sheets::button().border_style(border_type::inset).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(78, 255, 255, 255)).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::hover, style_sheets::button().border_style(border_type::outset).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(78, 255, 255, 255)).color(drawing::system_colors::control_text())},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::disabled, style_sheets::button().border_style(border_type::solid).border_color(drawing::system_colors::control_text()).border_width(length(1)).border_radius({5}).padding({1, 1, 3, 1}).background_color(color::from_argb(30, 255, 255, 255)).color(drawing::system_colors::gray_text())},
    };
  }

  style_sheets::system_colors get_system_colors() {
    style_sheets::system_colors colors;
    colors.accent(drawing::system_colors::accent());
    colors.accent_text(drawing::system_colors::accent_text());
    colors.active_border(drawing::system_colors::active_border());
    colors.active_caption(drawing::system_colors::active_caption());
    colors.active_caption_text(drawing::system_colors::active_caption_text());
    colors.app_workspace(drawing::system_colors::app_workspace());
    colors.button_face(drawing::system_colors::button_face());
    colors.button_highlight(drawing::system_colors::button_highlight());
    colors.button_shadow(drawing::system_colors::button_shadow());
    colors.control(drawing::system_colors::control());
    colors.control_dark(drawing::system_colors::control_dark());
    colors.control_dark_dark(drawing::system_colors::control_dark_dark());
    colors.control_light(drawing::system_colors::control_light());
    colors.control_light_light(drawing::system_colors::control_light_light());
    colors.control_text(drawing::system_colors::control_text());
    colors.desktop(drawing::system_colors::desktop());
    colors.gradient_active_caption(drawing::system_colors::gradient_active_caption());
    colors.gradient_inactive_caption(drawing::system_colors::gradient_inactive_caption());
    colors.gray_text(drawing::system_colors::gray_text());
    colors.highlight(drawing::system_colors::highlight());
    colors.highlight_text(drawing::system_colors::highlight_text());
    colors.hot_track(drawing::system_colors::hot_track());
    colors.inactive_border(drawing::system_colors::inactive_border());
    colors.inactive_caption(drawing::system_colors::inactive_caption());
    colors.inactive_caption_text(drawing::system_colors::inactive_caption_text());
    colors.info(drawing::system_colors::info());
    colors.info_text(drawing::system_colors::info_text());
    colors.menu(drawing::system_colors::menu());
    colors.menu_bar(drawing::system_colors::menu_bar());
    colors.menu_highlight(drawing::system_colors::menu_highlight());
    colors.menu_text(drawing::system_colors::menu_text());
    colors.scroll_bar(drawing::system_colors::scroll_bar());
    colors.text_box(drawing::system_colors::text_box());
    colors.text_box_text(drawing::system_colors::text_box_text());
    colors.window(drawing::system_colors::window());
    colors.window_frame(drawing::system_colors::window_frame());
    colors.window_text(drawing::system_colors::window_text());
   return colors;
  }
}

style_sheet style_sheet::system_style_sheet_macos_dark() noexcept {
  style_sheet ss;
  ss.theme_ = style_sheets::theme("macOS (dark)", "Contains macOS (dark) theme.", "Gammasoft", uri("https://gammasoft71.wixsite.com/gammasoft"));
  ss.system_colors_ = get_system_colors();
  ss.buttons_ = get_buttons();
  return ss;
}
