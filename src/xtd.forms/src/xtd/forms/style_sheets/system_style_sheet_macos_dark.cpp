#include "../../../../include/xtd/forms/style_sheets/style_sheet"
#include <xtd/drawing/system_colors>
/*
using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::web::css;

namespace {
  style_sheet::buttons_t get_buttons(const style_sheets::system_colors& system_color) {
    const auto button_standard = style_sheets::button().margin({2, 0, 1, 0}).border_style(border_type::outset).border_color(system_color.control_dark()).border_width({1}).border_radius({5}).background_image({image_type::linear_gradient, {system_color.button_face(), system_color.button_face()}}).padding({1, 1, 3, 1}).color(system_color.control_text());
    const auto button_default = style_sheets::button().margin({2, 0,1, 0}).border_style(border_type::outset).border_color(system_color.control_dark()).border_width({1}).border_radius({5}).background_image({image_type::linear_gradient, {color::from_argb(0xFF177AE5), color::from_argb(0xFF166ECD)}}).padding({1, 1, 3, 1}).color(system_color.control_text());
    const auto button_flat = style_sheets::button().border_style(border_type::solid).border_color(system_color.control_text()).border_width({1}).border_radius({5}).background_color(system_color.control()).padding({1, 1, 3, 1}).color(system_color.control_text());
    const auto button_flat_default = style_sheets::button().border_style(border_type::solid).border_color(system_color.control_text()).border_width({2}).border_radius({5}).background_color(system_color.control()).padding({1, 1, 3, 1}).color(system_color.control_text());
    const auto button_popup = style_sheets::button().border_style(border_type::solid).border_color(system_color.control_dark()).border_width({1}).border_radius({5}).background_color(system_color.control()).padding({1, 1, 3, 1}).color(system_color.control_text());
    const auto button_popup_default = style_sheets::button().border_style(border_type::solid).border_color(system_color.control_dark()).border_width({2}).border_radius({5}).background_color(system_color.control()).padding({1, 1, 3, 1}).color(system_color.control_text());
    return style_sheet::buttons_t {
      // :standard
      {xtd::forms::style_sheets::pseudo_state::standard, button_standard},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::pressed, style_sheets::button(button_standard).background_image({image_type::linear_gradient, {color::from_argb(93, 255, 255, 255), color::from_argb(93, 255, 255, 255)}})},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::checked, style_sheets::button(button_standard).background_image({image_type::linear_gradient, {color::from_argb(93, 255, 255, 255), color::from_argb(93, 255, 255, 255)}})},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::mixed, style_sheets::button(button_standard).background_image({image_type::linear_gradient, {color::from_argb(78, 255, 255, 255), color::from_argb(93, 255, 255, 255)}})},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::hover, button_standard},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::disabled, style_sheets::button(button_standard).background_image({image_type::linear_gradient, {color::from_argb(35, 255, 255, 255), color::from_argb(35, 255, 255, 255)}}).color(system_color.gray_text())},
      // :standard:default
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state, button_default},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::pressed, style_sheets::button(button_default).background_image({image_type::linear_gradient, {color::from_argb(0xFF24A0F2), color::from_argb(0xFF2194E5)}})},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::checked, style_sheets::button(button_default).background_image({image_type::linear_gradient, {color::from_argb(0xFF24A0F2), color::from_argb(0xFF2194E5)}})},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::mixed, style_sheets::button(button_default).background_image({image_type::linear_gradient, {color::from_argb(0xFF1E88CD), color::from_argb(0xFF1C7DC2)}})},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::hover, button_default},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::disabled, style_sheets::button(button_default).background_image({image_type::linear_gradient, {color::from_argb(35, 255, 255, 255), color::from_argb(35, 255, 255, 255)}}).color(system_color.gray_text())},
      // :flat
      {xtd::forms::style_sheets::pseudo_state::flat, button_flat},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::pressed, style_sheets::button(button_flat).background_color(color::from_argb(93, 255, 255, 255))},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::checked, style_sheets::button(button_flat).background_color(color::from_argb(93, 255, 255, 255))},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::mixed, style_sheets::button(button_flat).background_color(color::from_argb(78, 255, 255, 255))},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::hover, style_sheets::button(button_flat).background_color(color::from_argb(78, 255, 255, 255))},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::disabled, style_sheets::button(button_flat).border_style(border_type::solid).border_color(system_color.gray_text()).background_color(color::from_argb(35, 255, 255, 255)).color(system_color.gray_text())},
      // :flat:default
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state, button_flat_default},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::pressed, style_sheets::button(button_flat_default).background_color(color::from_argb(93, 255, 255, 255))},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::checked, style_sheets::button(button_flat_default).background_color(color::from_argb(93, 255, 255, 255))},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::mixed, style_sheets::button(button_flat_default).background_color(color::from_argb(78, 255, 255, 255))},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::hover, style_sheets::button(button_flat_default).background_color(color::from_argb(78, 255, 255, 255))},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::disabled, style_sheets::button(button_flat_default).border_color(system_color.gray_text()).background_color(color::from_argb(35, 255, 255, 255)).color(system_color.gray_text())},
      // :popup
      {xtd::forms::style_sheets::pseudo_state::popup, button_popup},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::pressed, style_sheets::button(button_popup).border_style(border_type::inset).border_width({2})},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::checked, style_sheets::button(button_popup).border_style(border_type::inset).border_width({2})},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::mixed, style_sheets::button(button_popup).border_style(border_type::inset).border_width({1})},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::hover, style_sheets::button(button_popup).border_style(border_type::outset).border_width({2})},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::disabled, style_sheets::button(button_popup).border_color(system_color.gray_text()).background_color(color::from_argb(35, 255, 255, 255)).color(system_color.gray_text())},
      // :popup:default
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state, button_popup_default},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::pressed, style_sheets::button(button_popup_default).border_style(border_type::inset).border_width({3})},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::checked, style_sheets::button(button_popup_default).border_style(border_type::inset).border_width({3})},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::mixed, style_sheets::button(button_popup_default).border_style(border_type::inset).border_width({2})},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::hover, style_sheets::button(button_popup_default).border_style(border_type::outset).border_width({3})},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::disabled, style_sheets::button(button_popup_default).border_color(system_color.gray_text()).background_color(color::from_argb(35, 255, 255, 255)).color(system_color.gray_text())},
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
  ss.buttons_ = get_buttons(ss.system_colors_);
  return ss;
}
*/
