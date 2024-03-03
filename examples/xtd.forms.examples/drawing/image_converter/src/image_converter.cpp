#include "../properties/resources.h"
#include <xtd/drawing/drawing_2d/hatch_brush>
#include <xtd/drawing/image_converter>
#include <xtd/forms/application>
#include <xtd/forms/check_box>
#include <xtd/forms/choice>
#include <xtd/forms/color_picker>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/numeric_up_down>
#include <xtd/forms/panel>
#include <xtd/forms/switch_button>
#include <xtd/forms/track_bar>
#include <xtd/byte_object>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::forms;

namespace image_converter_example {
  class form1 : public form {
  public:
    form1() {
      text("Image conversions example");
      form_border_style(forms::form_border_style::fixed_3d);
      maximize_box(false);
      client_size({730, 525});
      
      threshold_bitonal_track_bar.tick_style(tick_style::none);
      radius_blur_track_bar.tick_style(tick_style::none);
      percent_brightness_track_bar.tick_style(tick_style::none);
      percent_color_track_bar.tick_style(tick_style::none);
      threshold_color_extraction_track_bar.tick_style(tick_style::none);
      threshold_color_substitution_track_bar.tick_style(tick_style::none);
      percent_contrast_track_bar.tick_style(tick_style::none);
      percent_red_gamma_correction_track_bar.tick_style(tick_style::none);
      percent_green_gamma_correction_track_bar.tick_style(tick_style::none);
      percent_blue_gamma_correction_track_bar.tick_style(tick_style::none);
      percent_grayscale_track_bar.tick_style(tick_style::none);
      percent_hue_rotate_track_bar.tick_style(tick_style::none);
      percent_invert_track_bar.tick_style(tick_style::none);
      percent_opacity_track_bar.tick_style(tick_style::none);
      resize_width_track_bar.tick_style(tick_style::none);
      resize_height_track_bar.tick_style(tick_style::none);
      percent_saturate_track_bar.tick_style(tick_style::none);
      percent_sepia_track_bar.tick_style(tick_style::none);
      threshold_threshold_track_bar.tick_style(tick_style::none);

      bitonal_panel.dock(xtd::forms::dock_style::fill);
      blur_panel.dock(xtd::forms::dock_style::fill);
      brightness_panel.dock(xtd::forms::dock_style::fill);
      color_panel.dock(xtd::forms::dock_style::fill);
      color_extraction_panel.dock(xtd::forms::dock_style::fill);
      color_substitution_panel.dock(xtd::forms::dock_style::fill);
      contrast_panel.dock(xtd::forms::dock_style::fill);
      disabled_panel.dock(xtd::forms::dock_style::fill);
      gamma_correction_panel.dock(xtd::forms::dock_style::fill);
      grayscale_panel.dock(xtd::forms::dock_style::fill);
      hue_rotate_panel.dock(xtd::forms::dock_style::fill);
      invert_panel.dock(xtd::forms::dock_style::fill);
      opacity_panel.dock(xtd::forms::dock_style::fill);
      resize_panel.dock(xtd::forms::dock_style::fill);
      rotate_flip_panel.dock(xtd::forms::dock_style::fill);
      saturate_panel.dock(xtd::forms::dock_style::fill);
      sepia_panel.dock(xtd::forms::dock_style::fill);
      threshold_panel.dock(xtd::forms::dock_style::fill);
      picures_panel.border_sides(xtd::forms::border_sides::bottom).border_style(xtd::forms::border_style::inset).dock(xtd::forms::dock_style::top);
      
      effect_choice.selected_value_changed += {*this, &form1::on_input_change};
      picture_choice.selected_value_changed += {*this, &form1::on_input_change};

      threshold_bitonal_numeric_up_down.value_changed += [&] {threshold_bitonal_track_bar.value(as<int32>(threshold_bitonal_numeric_up_down.value()));};
      threshold_bitonal_track_bar.value_changed += [&] {
        threshold_bitonal_numeric_up_down.value(threshold_bitonal_track_bar.value());
        adjusted_image = image_converter::bitonal(original_image(), threshold_bitonal_track_bar.value(), upper_color_bitonal_color_picker.color(), lower_color_bitonal_color_picker.color());
        adjusted_picture_panel.invalidate();
      };
      upper_color_bitonal_color_picker.color_picker_changed += [&] {
        adjusted_image = image_converter::bitonal(original_image(), threshold_bitonal_track_bar.value(), upper_color_bitonal_color_picker.color(), lower_color_bitonal_color_picker.color());
        adjusted_picture_panel.invalidate();
      };
      lower_color_bitonal_color_picker.color_picker_changed += [&] {
        adjusted_image = image_converter::bitonal(original_image(), threshold_bitonal_track_bar.value(), upper_color_bitonal_color_picker.color(), lower_color_bitonal_color_picker.color());
        adjusted_picture_panel.invalidate();
      };

      radius_blur_numeric_up_down.value_changed += [&] {radius_blur_track_bar.value(as<int32>(radius_blur_numeric_up_down.value()));};
      radius_blur_track_bar.value_changed += [&] {
        radius_blur_numeric_up_down.value(radius_blur_track_bar.value());
        adjusted_image = image_converter::blur(original_image(), radius_blur_track_bar.value());
        adjusted_picture_panel.invalidate();
      };
      
      percent_brightness_numeric_up_down.value_changed += [&] {percent_brightness_track_bar.value(as<int32>(percent_brightness_numeric_up_down.value()));};
      percent_brightness_track_bar.value_changed += [&] {
        percent_brightness_numeric_up_down.value(percent_brightness_track_bar.value());
        adjusted_image = image_converter::brightness(original_image(), percent_brightness_track_bar.value() / 100.0);
        adjusted_picture_panel.invalidate();
      };
      
      percent_color_numeric_up_down.value_changed += [&] {percent_color_track_bar.value(as<int32>(percent_color_numeric_up_down.value()));};
      percent_color_track_bar.value_changed += [&] {
        percent_color_numeric_up_down.value(percent_color_track_bar.value());
        adjusted_image = image_converter::color(original_image(), color_color_color_picker.color(), percent_color_track_bar.value() / 100.0);
        adjusted_picture_panel.invalidate();
      };
      color_color_color_picker.color_picker_changed += [&] {
        adjusted_image = image_converter::color(original_image(), color_color_color_picker.color(), percent_color_track_bar.value() / 100.0);
        adjusted_picture_panel.invalidate();
      };

      threshold_color_extraction_numeric_up_down.value_changed += [&] {threshold_color_extraction_track_bar.value(as<int32>(threshold_color_extraction_numeric_up_down.value()));};
      threshold_color_extraction_track_bar.value_changed += [&] {
        threshold_color_extraction_numeric_up_down.value(threshold_color_extraction_track_bar.value());
        adjusted_image = image_converter::color_extraction(original_image(), threshold_color_extraction_track_bar.value(), extraction_color_color_extraction_color_picker.color(), other_pixels_color_color_extraction_color_picker.color());
        adjusted_picture_panel.invalidate();
      };
      extraction_color_color_extraction_color_picker.color_picker_changed += [&] {
        adjusted_image = image_converter::color_extraction(original_image(), threshold_color_extraction_track_bar.value(), extraction_color_color_extraction_color_picker.color(), other_pixels_color_color_extraction_color_picker.color());
        adjusted_picture_panel.invalidate();
      };
      other_pixels_color_color_extraction_color_picker.color_picker_changed += [&] {
        adjusted_image = image_converter::color_extraction(original_image(), threshold_color_extraction_track_bar.value(), extraction_color_color_extraction_color_picker.color(), other_pixels_color_color_extraction_color_picker.color());
        adjusted_picture_panel.invalidate();
      };
      
      threshold_color_substitution_numeric_up_down.value_changed += [&] {threshold_color_substitution_track_bar.value(as<int32>(threshold_color_substitution_numeric_up_down.value()));};
      threshold_color_substitution_track_bar.value_changed += [&] {
        threshold_color_substitution_numeric_up_down.value(threshold_color_substitution_track_bar.value());
        adjusted_image = image_converter::color_substitution(original_image(), threshold_color_substitution_track_bar.value(), source_color_color_substitution_color_picker.color(), new_color_color_substitution_color_picker.color());
        adjusted_picture_panel.invalidate();
      };
      source_color_color_substitution_color_picker.color_picker_changed += [&] {
        adjusted_image = image_converter::color_substitution(original_image(), threshold_color_substitution_track_bar.value(), source_color_color_substitution_color_picker.color(), new_color_color_substitution_color_picker.color());
        adjusted_picture_panel.invalidate();
      };
      new_color_color_substitution_color_picker.color_picker_changed += [&] {
        adjusted_image = image_converter::color_substitution(original_image(), threshold_color_substitution_track_bar.value(), source_color_color_substitution_color_picker.color(), new_color_color_substitution_color_picker.color());
        adjusted_picture_panel.invalidate();
      };
      
      percent_contrast_numeric_up_down.value_changed += [&] {percent_contrast_track_bar.value(as<int32>(percent_contrast_numeric_up_down.value()));};
      percent_contrast_track_bar.value_changed += [&] {
        percent_contrast_numeric_up_down.value(percent_contrast_track_bar.value());
        adjusted_image = image_converter::contrast(original_image(), percent_contrast_track_bar.value() / 100.0);
        adjusted_picture_panel.invalidate();
      };

      disabled_switch_button.checked_changed += [&] {
        adjusted_image = disabled_switch_button.checked() ? bitmap {image_converter::disabled(original_image(), adjusted_picture_panel.back_color())} : original_image();
        adjusted_picture_panel.invalidate();
      };
      
      percent_grayscale_numeric_up_down.value_changed += [&] {percent_grayscale_track_bar.value(as<int32>(percent_grayscale_numeric_up_down.value()));};
      percent_grayscale_track_bar.value_changed += [&] {
        percent_grayscale_numeric_up_down.value(percent_grayscale_track_bar.value());
        adjusted_image = image_converter::grayscale(original_image(), percent_grayscale_track_bar.value() / 100.0);
        adjusted_picture_panel.invalidate();
      };

      percent_hue_rotate_numeric_up_down.value_changed += [&] {percent_hue_rotate_track_bar.value(as<int32>(percent_hue_rotate_numeric_up_down.value()));};
      percent_hue_rotate_track_bar.value_changed += [&] {
        percent_hue_rotate_numeric_up_down.value(percent_hue_rotate_track_bar.value());
        adjusted_image = image_converter::hue_rotate(original_image(), percent_hue_rotate_track_bar.value());
        adjusted_picture_panel.invalidate();
      };
      
      percent_invert_numeric_up_down.value_changed += [&] {percent_invert_track_bar.value(as<int32>(percent_invert_numeric_up_down.value()));};
      percent_invert_track_bar.value_changed += [&] {
        percent_invert_numeric_up_down.value(percent_invert_track_bar.value());
        adjusted_image = image_converter::invert(original_image(), percent_invert_track_bar.value() / 100.0);
        adjusted_picture_panel.invalidate();
      };
      
      percent_opacity_numeric_up_down.value_changed += [&] {percent_opacity_track_bar.value(as<int32>(percent_opacity_numeric_up_down.value()));};
      percent_opacity_track_bar.value_changed += [&] {
        percent_opacity_numeric_up_down.value(percent_opacity_track_bar.value());
        adjusted_image = image_converter::opacity(original_image(), percent_opacity_track_bar.value() / 100.0);
        adjusted_picture_panel.invalidate();
      };
      
      resize_width_numeric_up_down.value_changed += [&] {resize_width_track_bar.value(as<int32>(resize_width_numeric_up_down.value()));};
      resize_width_track_bar.value_changed += [&] {
        resize_width_numeric_up_down.value(resize_width_track_bar.value());
        if (resize_maintain_aspect_ratio_check_box.checked()) resize_height_numeric_up_down.value(as<int>(resize_width_track_bar.value() / resize_aspect_ratio));
        adjusted_image = image_converter::resize(original_image(), {resize_width_track_bar.value(), resize_height_track_bar.value()});
        adjusted_picture_panel.invalidate();
      };
      
      resize_height_numeric_up_down.value_changed += [&] {resize_height_track_bar.value(as<int32>(resize_height_numeric_up_down.value()));};
      resize_height_track_bar.value_changed += [&] {
        resize_height_numeric_up_down.value(resize_height_track_bar.value());
        if (resize_maintain_aspect_ratio_check_box.checked()) resize_width_numeric_up_down.value(as<int>(resize_height_track_bar.value() * resize_aspect_ratio));
        adjusted_image = image_converter::resize(original_image(), {resize_width_track_bar.value(), resize_height_track_bar.value()});
        adjusted_picture_panel.invalidate();
      };
      
      rotate_flip_choice.selected_index_changed += [&] {
        adjusted_image = image_converter::rotate_flip(original_image(), as<rotate_flip_type>(rotate_flip_choice.selected_item().tag()));
        adjusted_picture_panel.invalidate();
      };
      
      percent_saturate_numeric_up_down.value_changed += [&] {percent_saturate_track_bar.value(as<int32>(percent_saturate_numeric_up_down.value()));};
      percent_saturate_track_bar.value_changed += [&] {
        percent_saturate_numeric_up_down.value(percent_saturate_track_bar.value());
        adjusted_image = image_converter::saturate(original_image(), percent_saturate_track_bar.value() / 100.0);
        adjusted_picture_panel.invalidate();
      };
      
      percent_sepia_numeric_up_down.value_changed += [&] {percent_sepia_track_bar.value(as<int32>(percent_sepia_numeric_up_down.value()));};
      percent_sepia_track_bar.value_changed += [&] {
        percent_sepia_numeric_up_down.value(percent_sepia_track_bar.value());
        adjusted_image = image_converter::sepia(original_image(), percent_sepia_track_bar.value() / 100.0);
        adjusted_picture_panel.invalidate();
      };
      
      threshold_threshold_numeric_up_down.value_changed += [&] {threshold_threshold_track_bar.value(as<int32>(threshold_threshold_numeric_up_down.value()));};
      threshold_threshold_track_bar.value_changed += [&] {
        threshold_threshold_numeric_up_down.value(threshold_threshold_track_bar.value());
        adjusted_image = image_converter::threshold(original_image(), threshold_threshold_track_bar.value());
        adjusted_picture_panel.invalidate();
      };
      
      original_picture_panel.double_buffered(true);
      original_picture_panel.paint += [&](object& sender, paint_event_args& e) {
        e.graphics().fill_rectangle(hatch_brush {xtd::drawing::drawing_2d::hatch_style::wide_checker_board, xtd::drawing::color::from_argb(0x66, 0x66, 0x66), xtd::drawing::color::from_argb(0x99, 0x99, 0x99)}, e.clip_rectangle());
        e.graphics().draw_image(original_image(), rectangle {{(original_picture_panel.width() - original_image().width()) / 2, (original_picture_panel.height() - original_image().height()) / 2}, original_image().size()});
      };
      
      adjusted_picture_panel.double_buffered(true);
      adjusted_picture_panel.paint += [&](object& sender, paint_event_args& e) {
        e.graphics().fill_rectangle(hatch_brush {xtd::drawing::drawing_2d::hatch_style::wide_checker_board, xtd::drawing::color::from_argb(0x66, 0x66, 0x66), xtd::drawing::color::from_argb(0x99, 0x99, 0x99)}, e.clip_rectangle());
        e.graphics().draw_image(adjusted_image, rectangle {{(adjusted_picture_panel.width() - adjusted_image.width()) / 2, (adjusted_picture_panel.height() - adjusted_image.height()) / 2}, adjusted_image.size()});
      };
      
      effect_choice.selected_item("bitonal");
    }
    
    
  private:
    void on_input_change() {
      bitonal_panel.visible(effect_choice.selected_item() == "bitonal");
      blur_panel.visible(effect_choice.selected_item() == "blur");
      brightness_panel.visible(effect_choice.selected_item() == "brightness");
      color_panel.visible(effect_choice.selected_item() == "color");
      color_extraction_panel.visible(effect_choice.selected_item() == "color-extraction");
      color_substitution_panel.visible(effect_choice.selected_item() == "color-substitution");
      contrast_panel.visible(effect_choice.selected_item() == "contrast");
      disabled_panel.visible(effect_choice.selected_item() == "disabled");
      gamma_correction_panel.visible(effect_choice.selected_item() == "gamma-correction");
      grayscale_panel.visible(effect_choice.selected_item() == "grayscale");
      hue_rotate_panel.visible(effect_choice.selected_item().value() == "hue-rotate");
      invert_panel.visible(effect_choice.selected_item().value() == "invert");
      opacity_panel.visible(effect_choice.selected_item().value() == "opacity");
      resize_panel.visible(effect_choice.selected_item().value() == "resize");
      rotate_flip_panel.visible(effect_choice.selected_item().value() == "rotate-flip");
      saturate_panel.visible(effect_choice.selected_item().value() == "saturate");
      sepia_panel.visible(effect_choice.selected_item().value() == "sepia");
      threshold_panel.visible(effect_choice.selected_item().value() == "threshold");
      
      threshold_bitonal_track_bar.value(382);
      upper_color_bitonal_color_picker.color(color::red);
      lower_color_bitonal_color_picker.color(color::white);
      radius_blur_track_bar.value(10);
      percent_brightness_track_bar.value(125);
      percent_color_track_bar.value(200);
      color_color_color_picker.color(color::red);
      threshold_color_extraction_track_bar.value(50);
      extraction_color_color_extraction_color_picker.color(color::green);
      other_pixels_color_color_extraction_color_picker.color(color::white);
      threshold_color_substitution_track_bar.value(50);
      source_color_color_substitution_color_picker.color(color::green);
      new_color_color_substitution_color_picker.color(color::blue);
      percent_contrast_track_bar.value(200);
      disabled_switch_button.checked(true);
      percent_grayscale_track_bar.value(100);
      percent_hue_rotate_track_bar.value(90);
      percent_invert_track_bar.value(100);
      percent_opacity_track_bar.value(50);
      resize_aspect_ratio = as<double>(original_image().size().width()) / original_image().size().height();
      resize_maintain_aspect_ratio_check_box.checked(false);
      resize_width_track_bar.value(original_image().size().width() / 5 * 4);
      resize_height_track_bar.value(original_image().size().height() / 5 * 4);
      resize_maintain_aspect_ratio_check_box.checked(true);
      rotate_flip_choice.selected_index(6);
      percent_saturate_track_bar.value(300);
      percent_sepia_track_bar.value(100);
      threshold_threshold_track_bar.value(382);
      
      original_image_ = as<bitmap>(picture_choice.selected_item().tag());
      if (effect_choice.selected_item() == "bitonal") adjusted_image = image_converter::bitonal(original_image(), threshold_bitonal_track_bar.value(), upper_color_bitonal_color_picker.color(), lower_color_bitonal_color_picker.color());
      else if (effect_choice.selected_item() == "blur") adjusted_image = image_converter::blur(original_image(), radius_blur_track_bar.value());
      else if (effect_choice.selected_item() == "brightness") adjusted_image = image_converter::brightness(original_image(), percent_brightness_track_bar.value() / 100.0);
      else if (effect_choice.selected_item() == "color") adjusted_image = image_converter::color(original_image(), color_color_color_picker.color(), percent_color_track_bar.value() / 100.0);
      else if (effect_choice.selected_item() == "color-extraction") adjusted_image = image_converter::color_extraction(original_image(), threshold_color_extraction_track_bar.value(), extraction_color_color_extraction_color_picker.color(), other_pixels_color_color_extraction_color_picker.color());
      else if (effect_choice.selected_item() == "color-substitution") adjusted_image = image_converter::color_substitution(original_image(), threshold_color_substitution_track_bar.value(), source_color_color_substitution_color_picker.color(), new_color_color_substitution_color_picker.color());
      else if (effect_choice.selected_item() == "contrast") adjusted_image = image_converter::contrast(original_image(), percent_contrast_track_bar.value() / 100.0);
      else if (effect_choice.selected_item() == "disabled") adjusted_image = disabled_switch_button.checked() ? bitmap {image_converter::disabled(original_image(), adjusted_picture_panel.back_color())} : original_image();
      else if (effect_choice.selected_item() == "grayscale") adjusted_image = image_converter::grayscale(original_image(), percent_grayscale_track_bar.value() / 100.0);
      else if (effect_choice.selected_item() == "hue-rotate")adjusted_image = image_converter::hue_rotate(original_image(), percent_hue_rotate_track_bar.value());
      else if (effect_choice.selected_item() == "invert") adjusted_image = image_converter::invert(original_image(), percent_invert_track_bar.value() / 100.0);
      else if (effect_choice.selected_item() == "opacity") adjusted_image = image_converter::opacity(original_image(), percent_opacity_track_bar.value() / 100.0);
      else if (effect_choice.selected_item() == "resize") adjusted_image = image_converter::resize(original_image(), {resize_width_track_bar.value(), resize_height_track_bar.value()});
      else if (effect_choice.selected_item() == "rotate-flip") adjusted_image = image_converter::rotate_flip(original_image(), as<rotate_flip_type>(rotate_flip_choice.selected_item().tag()));
      else if (effect_choice.selected_item() == "saturate") adjusted_image = image_converter::saturate(original_image(), percent_saturate_track_bar.value() / 100.0);
      else if (effect_choice.selected_item() == "sepia") adjusted_image = image_converter::sepia(original_image(), percent_sepia_track_bar.value() / 100.0);
      else if (effect_choice.selected_item() == "threshold") adjusted_image = image_converter::threshold(original_image(), threshold_threshold_track_bar.value());
      else adjusted_image = original_image();
      adjusted_picture_panel.invalidate();
    }
    
    const image& original_image() const {return original_image_;}
    image original_image_ = properties::resources::pineapple();
    image adjusted_image = properties::resources::pineapple();
    double resize_aspect_ratio = as<double>(original_image().size().width()) / original_image().size().height();

    panel bitonal_panel = panel::create(*this, {0, 0}, {730, 170});
    label threshold_bitonal_label = label::create(bitonal_panel, "Threshold", {10, 34}, {70, 23});
    track_bar threshold_bitonal_track_bar = track_bar::create(bitonal_panel, 382, 0, 3 * byte_object::max_value, {80, 30}, {200, 25});
    numeric_up_down threshold_bitonal_numeric_up_down = numeric_up_down::create(bitonal_panel, 382, 0, 3 * byte_object::max_value, {290, 30}, {110, 25});
    label upper_color_bitonal_label = label::create(bitonal_panel, "Upper", {10, 74}, {50, 23});
    color_picker upper_color_bitonal_color_picker = color_picker::create(bitonal_panel, color::green, {70, 70});
    label lower_color_bitonal_label = label::create(bitonal_panel, "Lower", {200, 74}, {70, 23});
    color_picker lower_color_bitonal_color_picker = color_picker::create(bitonal_panel, color::white, {260, 70});

    panel blur_panel = panel::create(*this, {0, 0}, {730, 170});
    label radius_blur_label = label::create(blur_panel, "Radius", {10, 54}, {50, 23});
    track_bar radius_blur_track_bar = track_bar::create(blur_panel, 10, 0, 100, {60, 50}, {200, 25});
    numeric_up_down radius_blur_numeric_up_down = numeric_up_down::create(blur_panel, 10, 0, 100, {270, 50}, {130, 25});
    
    panel brightness_panel = panel::create(*this, {0, 0}, {730, 170});
    label percent_brightness_label = label::create(brightness_panel, "Percent", {10, 54}, {70, 23});
    track_bar percent_brightness_track_bar = track_bar::create(brightness_panel, 125, 0, 200, {80, 50}, {200, 25});
    numeric_up_down percent_brightness_numeric_up_down = numeric_up_down::create(brightness_panel, 125, 0, 200, {290, 50}, {110, 25});
    
    panel color_panel = panel::create(*this, {0, 0}, {730, 170});
    label percent_color_label = label::create(color_panel, "Percent", {10, 34}, {70, 23});
    track_bar percent_color_track_bar = track_bar::create(color_panel, 200, 0, 200, {80, 30}, {200, 25});
    numeric_up_down percent_color_numeric_up_down = numeric_up_down::create(color_panel, 200, 0, 200, {290, 30}, {110, 25});
    label color_color_label = label::create(color_panel, "Color", {10, 74}, {50, 23});
    color_picker color_color_color_picker = color_picker::create(color_panel, color::red, {70, 70});

    panel color_extraction_panel = panel::create(*this, {0, 0}, {730, 170});
    label threshold_color_extraction_label = label::create(color_extraction_panel, "Threshold", {10, 34}, {70, 23});
    track_bar threshold_color_extraction_track_bar = track_bar::create(color_extraction_panel, 50, 0, 3 * byte_object::max_value, {80, 30}, {200, 25});
    numeric_up_down threshold_color_extraction_numeric_up_down = numeric_up_down::create(color_extraction_panel, 50, 0, 3 * byte_object::max_value, {290, 30}, {110, 25});
    label extraction_color_color_extraction_label = label::create(color_extraction_panel, "Extraction color", {10, 74}, {100, 23});
    color_picker extraction_color_color_extraction_color_picker = color_picker::create(color_extraction_panel, color::green, {120, 70});
    label other_pixels_color_color_extraction_label = label::create(color_extraction_panel, "Other pixels color", {250, 74}, {110, 23});
    color_picker other_pixels_color_color_extraction_color_picker = color_picker::create(color_extraction_panel, color::white, {370, 70});

    panel color_substitution_panel = panel::create(*this, {0, 0}, {730, 170});
    label threshold_color_substitution_label = label::create(color_substitution_panel, "Threshold", {10, 34}, {70, 23});
    track_bar threshold_color_substitution_track_bar = track_bar::create(color_substitution_panel, 50, 0, 3 * byte_object::max_value, {80, 30}, {200, 25});
    numeric_up_down threshold_color_substitution_numeric_up_down = numeric_up_down::create(color_substitution_panel, 50, 0, 3 * byte_object::max_value, {290, 30}, {110, 25});
    label source_color_color_substitution_label = label::create(color_substitution_panel, "Extraction color", {10, 74}, {100, 23});
    color_picker source_color_color_substitution_color_picker = color_picker::create(color_substitution_panel, color::green, {120, 70});
    label new_color_color_substitution_label = label::create(color_substitution_panel, "Other pixels color", {250, 74}, {110, 23});
    color_picker new_color_color_substitution_color_picker = color_picker::create(color_substitution_panel, color::blue, {370, 70});

    panel contrast_panel = panel::create(*this, {0, 0}, {730, 170});
    label percent_contrast_label = label::create(contrast_panel, "Percent", {10, 54}, {70, 23});
    track_bar percent_contrast_track_bar = track_bar::create(contrast_panel, 200, 0, 400, {80, 50}, {200, 25});
    numeric_up_down percent_contrast_numeric_up_down = numeric_up_down::create(contrast_panel, 200, 0, 400, {290, 50}, {110, 25});

    panel disabled_panel = panel::create(*this, {0, 0}, {730, 170});
    label disabled_label = label::create(disabled_panel, "Disabled", {10, 54}, {60, 23});
    switch_button disabled_switch_button = switch_button::create(disabled_panel, true, {70, 50});
    
    panel gamma_correction_panel = panel::create(*this, {0, 0}, {730, 170});
    label percent_red_bgamma_correction_label = label::create(gamma_correction_panel, "Red", {10, 14}, {70, 23});
    track_bar percent_red_gamma_correction_track_bar = track_bar::create(gamma_correction_panel, 100, 0, 100, {80, 10}, {200, 25});
    numeric_up_down percent_red_gamma_correction_numeric_up_down = numeric_up_down::create(gamma_correction_panel, 100, 0, 100, {290, 10}, {110, 25});
    label percent_green_bgamma_correction_label = label::create(gamma_correction_panel, "Green", {10, 54}, {70, 23});
    track_bar percent_green_gamma_correction_track_bar = track_bar::create(gamma_correction_panel, 100, 0, 100, {80, 50}, {200, 25});
    numeric_up_down percent_green_gamma_correction_numeric_up_down = numeric_up_down::create(gamma_correction_panel, 100, 0, 100, {290, 50}, {110, 25});
    label percent_blue_bgamma_correction_label = label::create(gamma_correction_panel, "Blue", {10, 94}, {70, 23});
    track_bar percent_blue_gamma_correction_track_bar = track_bar::create(gamma_correction_panel, 100, 0, 100, {80, 90}, {200, 25});
    numeric_up_down percent_blue_gamma_correction_numeric_up_down = numeric_up_down::create(gamma_correction_panel, 100, 0, 100, {290, 90}, {110, 25});

    panel grayscale_panel = panel::create(*this, {0, 0}, {730, 170});
    label percent_bgrayscale_label = label::create(grayscale_panel, "Percent", {10, 54}, {70, 23});
    track_bar percent_grayscale_track_bar = track_bar::create(grayscale_panel, 100, 0, 100, {80, 50}, {200, 25});
    numeric_up_down percent_grayscale_numeric_up_down = numeric_up_down::create(grayscale_panel, 100, 0, 100, {290, 50}, {110, 25});

    panel hue_rotate_panel = panel::create(*this, {0, 0}, {730, 170});
    label percent_bhue_rotate_label = label::create(hue_rotate_panel, "Angle", {10, 54}, {70, 23});
    track_bar percent_hue_rotate_track_bar = track_bar::create(hue_rotate_panel, 90, 0, 360, {80, 50}, {200, 25});
    numeric_up_down percent_hue_rotate_numeric_up_down = numeric_up_down::create(hue_rotate_panel, 90, 0, 360, {290, 50}, {110, 25});
    
    panel invert_panel = panel::create(*this, {0, 0}, {730, 170});
    label percent_invert_label = label::create(invert_panel, "Percent", {10, 54}, {70, 23});
    track_bar percent_invert_track_bar = track_bar::create(invert_panel, 100, 0, 100, {80, 50}, {200, 25});
    numeric_up_down percent_invert_numeric_up_down = numeric_up_down::create(invert_panel, 100, 0, 100, {290, 50}, {110, 25});
    
    panel opacity_panel = panel::create(*this, {0, 0}, {730, 170});
    label percent_opacity_label = label::create(opacity_panel, "Percent", {10, 54}, {70, 34});
    track_bar percent_opacity_track_bar = track_bar::create(opacity_panel, 50, 0, 100, {80, 50}, {200, 25});
    numeric_up_down percent_opacity_numeric_up_down = numeric_up_down::create(opacity_panel, 50, 0, 100, {290, 50}, {110, 25});
    
    panel resize_panel = panel::create(*this, {0, 0}, {730, 170});
    label resize_width_label = label::create(resize_panel, "Width", {10, 34}, {50, 23});
    track_bar resize_width_track_bar = track_bar::create(resize_panel, original_image().size().width(), 1, original_image().size().width() * 2, {60, 30}, {200, 25});
    numeric_up_down resize_width_numeric_up_down = numeric_up_down::create(resize_panel, original_image().size().width(), 1, original_image().size().width() * 2, {270, 30}, {130, 25});
    label resize_height_label = label::create(resize_panel, "Height", {10, 74}, {50, 23});
    track_bar resize_height_track_bar = track_bar::create(resize_panel, original_image().size().height(), 1, original_image().size().height() * 2, {60, 70}, {200, 25});
    numeric_up_down resize_height_numeric_up_down = numeric_up_down::create(resize_panel, original_image().size().height(), 1, original_image().size().height() * 2, {270, 70}, {130, 25});
    check_box resize_maintain_aspect_ratio_check_box = check_box::create(resize_panel, "Maintain aspect ratio", check_state::checked, {420, 54}, {150, 23});
    
    panel rotate_flip_panel = panel::create(*this, {0, 0}, {730, 170});
    label rotate_flip_label = label::create(rotate_flip_panel, "Rotate-flip", {10, 54}, {80, 23});
    choice rotate_flip_choice = choice::create(rotate_flip_panel, {{"rotate_none_flip_none", rotate_flip_type::rotate_none_flip_none}, {"rotate_90_flip_none", rotate_flip_type::rotate_90_flip_none}, {"rotate_180_flip_none", rotate_flip_type::rotate_180_flip_none}, {"rotate_270_flip_none", rotate_flip_type::rotate_270_flip_none}, {"rotate_none_flip_x", rotate_flip_type::rotate_none_flip_x}, {"rotate_90_flip_x", rotate_flip_type::rotate_90_flip_x}, {"rotate_180_flip_x", rotate_flip_type::rotate_180_flip_x}, {"rotate_270_flip_x", rotate_flip_type::rotate_270_flip_x}, {"rotate_none_flip_y", rotate_flip_type::rotate_none_flip_y}, {"rotate_90_flip_y", rotate_flip_type::rotate_90_flip_y}, {"rotate_180_flip_y", rotate_flip_type::rotate_180_flip_y}, {"rotate_270_flip_y", rotate_flip_type::rotate_270_flip_y}, {"rotate_none_flip_xy", rotate_flip_type::rotate_none_flip_xy}, {"rotate_90_flip_xy", rotate_flip_type::rotate_90_flip_xy}, {"rotate_180_flip_xy", rotate_flip_type::rotate_180_flip_xy}, {"rotate_270_flip_xy", rotate_flip_type::rotate_270_flip_xy}}, 6, {100, 50}, {180, 25});
    
    panel saturate_panel = panel::create(*this, {0, 0}, {730, 170});
    label percent_saturate_label = label::create(saturate_panel, "Percent", {10, 54}, {70, 23});
    track_bar percent_saturate_track_bar = track_bar::create(saturate_panel, 300, 0, 400, {80, 50}, {200, 25});
    numeric_up_down percent_saturate_numeric_up_down = numeric_up_down::create(saturate_panel, 300, 0, 400, {290, 50}, {110, 25});
    
    panel sepia_panel = panel::create(*this, {0, 0}, {730, 170});
    label percent_sepia_label = label::create(sepia_panel, "Percent", {10, 54}, {70, 23});
    track_bar percent_sepia_track_bar = track_bar::create(sepia_panel, 100, 0, 100, {80, 50}, {200, 25});
    numeric_up_down percent_sepia_numeric_up_down = numeric_up_down::create(sepia_panel, 100, 0, 100, {290, 50}, {110, 25});
    
    panel threshold_panel = panel::create(*this, {0, 0}, {730, 170});
    label threshold_threshold_label = label::create(threshold_panel, "Threshold", {10, 54}, {70, 23});
    track_bar threshold_threshold_track_bar = track_bar::create(threshold_panel, 382, 0, 3 * byte_object::max_value, {80, 50}, {200, 25});
    numeric_up_down threshold_threshold_numeric_up_down = numeric_up_down::create(threshold_panel, 382, 0, 3 * byte_object::max_value, {290, 50}, {110, 25});
    
    panel picures_panel = panel::create(*this, {0, 0}, {630, 400});
    label effect_label = label::create(picures_panel, "Effect", {10, 14}, {50, 23});
    choice effect_choice = choice::create(picures_panel, {"bitonal", "blur", "brightness", "color", "color-extraction", "color-substitution", "contrast", "disabled", "gamma-correction", "grayscale", "hue-rotate", "invert", "opacity", "resize", "rotate-flip", "saturate", "sepia", "threshold"}, {70, 10});
    label picture_label = label::create(picures_panel, "Picture", {220, 14}, {50, 23});
    choice picture_choice = choice::create(picures_panel, {{"pineapple", properties::resources::pineapple()}, {"rose", properties::resources::rose()}}, 1, {280, 10});
    panel original_picture_panel = panel::create(picures_panel, {10, 40}, {350, 350});
    panel adjusted_picture_panel = panel::create(picures_panel, {370, 40}, {350, 350});
  };
}
auto main()->int {
  application::run(image_converter_example::form1 {});
}
