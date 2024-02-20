#include <xtd/drawing/drawing_2d/hatch_brush>
#include <xtd/drawing/color_translator>
#include <xtd/forms/control_paint>
#include <xtd/forms/label>
#include <xtd/forms/numeric_up_down>
#include <xtd/forms/panel>
#include <xtd/forms/text_box>
#include <xtd/forms/track_bar>
#include <xtd/forms/user_control>
#include <xtd/int32>

namespace colors_example {
  class color_editor final : public xtd::forms::user_control {
  public:
    color_editor() {
      size({300, 580});
      
      alpha_label_.parent(*this);
      alpha_label_.location({55, 15});
      alpha_label_.auto_size(true);
      alpha_label_.text("A");
      
      alpha_track_bar_.parent(*this);
      alpha_track_bar_.location({85, 12});
      alpha_track_bar_.auto_size(false);
      alpha_track_bar_.maximum(255);
      alpha_track_bar_.size({100, 25});
      alpha_track_bar_.tick_style(xtd::forms::tick_style::none);
      alpha_track_bar_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::right);
      alpha_track_bar_.value_changed += [&] {
        if (color_.a() != xtd::as<unsigned char>(alpha_track_bar_.value())) color(xtd::drawing::color::from_argb(xtd::as<unsigned char>(alpha_track_bar_.value()), color_.r(), color_.g(), color_.b()));
      };
      
      alpha_numeric_up_down_.parent(*this);
      alpha_numeric_up_down_.bounds({200, 12, 50, 20});
      alpha_numeric_up_down_.minimum(0);
      alpha_numeric_up_down_.maximum(255);
      alpha_numeric_up_down_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::right);
      alpha_numeric_up_down_.value_changed += [&] {
        if (color_.a() != xtd::as<unsigned char>(alpha_numeric_up_down_.value())) color(xtd::drawing::color::from_argb(xtd::as<unsigned char>(alpha_numeric_up_down_.value()), color_.r(), color_.g(), color_.b()));
      };
      
      red_label_.parent(*this);
      red_label_.location({55, 60});
      red_label_.auto_size(true);
      red_label_.text("R");
      
      red_track_bar_.parent(*this);
      red_track_bar_.location({85, 57});
      red_track_bar_.auto_size(false);
      red_track_bar_.maximum(255);
      red_track_bar_.size({100, 25});
      red_track_bar_.tick_style(xtd::forms::tick_style::none);
      red_track_bar_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::right);
      red_track_bar_.value_changed += [&] {
        if (color_.r() != xtd::as<unsigned char>(red_track_bar_.value())) color(xtd::drawing::color::from_argb(color_.a(), xtd::as<unsigned char>(red_track_bar_.value()), color_.g(), color_.b()));
      };
      
      red_numeric_up_down_.parent(*this);
      red_numeric_up_down_.bounds({200, 57, 50, 20});
      red_numeric_up_down_.minimum(0);
      red_numeric_up_down_.maximum(255);
      red_numeric_up_down_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::right);
      red_numeric_up_down_.value_changed += [&] {
        if (color_.r() != xtd::as<unsigned char>(red_numeric_up_down_.value())) color(xtd::drawing::color::from_argb(color_.a(), xtd::as<unsigned char>(red_numeric_up_down_.value()), color_.g(), color_.b()));
      };
      
      green_label_.parent(*this);
      green_label_.location({55, 105});
      green_label_.auto_size(true);
      green_label_.text("G");
      
      green_track_bar_.parent(*this);
      green_track_bar_.location({85, 102});
      green_track_bar_.auto_size(false);
      green_track_bar_.maximum(255);
      green_track_bar_.size({100, 25});
      green_track_bar_.tick_style(xtd::forms::tick_style::none);
      green_track_bar_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::right);
      green_track_bar_.value_changed += [&] {
        if (color_.g() != xtd::as<unsigned char>(green_track_bar_.value())) color(xtd::drawing::color::from_argb(color_.a(), color_.r(), xtd::as<unsigned char>(green_track_bar_.value()), color_.b()));
      };
      
      green_numeric_up_down_.parent(*this);
      green_numeric_up_down_.bounds({200, 102, 50, 20});
      green_numeric_up_down_.minimum(0);
      green_numeric_up_down_.maximum(255);
      green_numeric_up_down_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::right);
      green_numeric_up_down_.value_changed += [&] {
        if (color_.g() != xtd::as<unsigned char>(green_numeric_up_down_.value())) color(xtd::drawing::color::from_argb(color_.a(), color_.r(), xtd::as<unsigned char>(green_numeric_up_down_.value()), color_.b()));
      };
      
      blue_label_.parent(*this);
      blue_label_.location({55, 150});
      blue_label_.auto_size(true);
      blue_label_.text("B");
      
      blue_track_bar_.parent(*this);
      blue_track_bar_.location({85, 147});
      blue_track_bar_.auto_size(false);
      blue_track_bar_.maximum(255);
      blue_track_bar_.size({100, 25});
      blue_track_bar_.tick_style(xtd::forms::tick_style::none);
      blue_track_bar_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::right);
      blue_track_bar_.value_changed += [&] {
        if (color_.b() != xtd::as<unsigned char>(blue_track_bar_.value())) color(xtd::drawing::color::from_argb(color_.a(), color_.r(), color_.g(), xtd::as<unsigned char>(blue_track_bar_.value())));
      };
      
      blue_numeric_up_down_.parent(*this);
      blue_numeric_up_down_.bounds({200, 147, 50, 20});
      blue_numeric_up_down_.minimum(0);
      blue_numeric_up_down_.maximum(255);
      blue_numeric_up_down_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::right);
      blue_numeric_up_down_.value_changed += [&] {
        if (color_.b() != xtd::as<unsigned char>(blue_numeric_up_down_.value())) color(xtd::drawing::color::from_argb(color_.a(), color_.r(), color_.g(), xtd::as<unsigned char>(blue_numeric_up_down_.value())));
      };
      
      color_box_panel_.parent(*this);
      color_box_panel_.location({55, 195});
      color_box_panel_.size({190, 190});
      color_box_panel_.double_buffered(true);
      color_box_panel_.anchor(xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::right | xtd::forms::anchor_styles::bottom);
      color_box_panel_.paint += [&](xtd::object& sender, xtd::forms::paint_event_args& e) {
        e.graphics().fill_rectangle(xtd::drawing::drawing_2d::hatch_brush(xtd::drawing::drawing_2d::hatch_style::wide_checker_board, xtd::drawing::color::from_argb(0x54, 0x54, 0x54), xtd::drawing::color::from_argb(0xA8, 0xA8, 0xA8)), e.clip_rectangle());
        if (color_ != xtd::drawing::color::empty) e.graphics().fill_rectangle(xtd::drawing::solid_brush(color_), e.clip_rectangle());
        xtd::forms::control_paint::draw_border(color_box_panel_, e.graphics(), color_box_panel_.border_style(), color_box_panel_.border_sides(), xtd::forms::application::style_sheet().system_colors().control_text(), e.clip_rectangle());
      };
      
      hex_label_.parent(*this);
      hex_label_.location({55, 397});
      hex_label_.anchor(xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::bottom);
      hex_label_.auto_size(true);
      hex_label_.text("HEX :");
      
      hsl_label_.parent(*this);
      hsl_label_.location({55, 427});
      hsl_label_.anchor(xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::bottom);
      hsl_label_.auto_size(true);
      hsl_label_.text("HSL :");
      
      hsv_label_.parent(*this);
      hsv_label_.location({55, 457});
      hsv_label_.anchor(xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::bottom);
      hsv_label_.auto_size(true);
      hsv_label_.text("HSV :");

      html_label_.parent(*this);
      html_label_.location({55, 487});
      html_label_.anchor(xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::bottom);
      html_label_.auto_size(true);
      html_label_.text("HTML :");
      
      rgb_label_.parent(*this);
      rgb_label_.location({55, 517});
      rgb_label_.anchor(xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::bottom);
      rgb_label_.auto_size(true);
      rgb_label_.text("RGB :");
      
      win32_label_.parent(*this);
      win32_label_.location({55, 547});
      win32_label_.anchor(xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::bottom);
      win32_label_.auto_size(true);
      win32_label_.text("Win32 :");
      
      hex_ltext_box_.parent(*this);
      hex_ltext_box_.location({110, 395});
      hex_ltext_box_.width(140);
      hex_ltext_box_.anchor(xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::bottom | xtd::forms::anchor_styles::right);
      hex_ltext_box_.key_down += [&](xtd::object& sender, xtd::forms::key_event_args& e){
        if (e.key_code() != xtd::forms::keys::enter) return;
        try {
          color(xtd::drawing::color_translator::from_hex(hex_ltext_box_.text()));
        } catch(...) {
        }
      };

      hsl_text_box_.parent(*this);
      hsl_text_box_.location({110, 425});
      hsl_text_box_.width(140);
      hsl_text_box_.anchor(xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::bottom | xtd::forms::anchor_styles::right);
      hsl_text_box_.key_down += [&](xtd::object& sender, xtd::forms::key_event_args& e){
        if (e.key_code() != xtd::forms::keys::enter) return;
        try {
          color(xtd::drawing::color_translator::from_hsl(hsl_text_box_.text()));
        } catch(...) {
          try {
            color(xtd::drawing::color_translator::from_hsla(hsl_text_box_.text()));
          } catch(...) {
          }
        }
      };

      hsv_text_box_.parent(*this);
      hsv_text_box_.location({110, 455});
      hsv_text_box_.width(140);
      hsv_text_box_.anchor(xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::bottom | xtd::forms::anchor_styles::right);
      hsv_text_box_.key_down += [&](xtd::object& sender, xtd::forms::key_event_args& e){
        if (e.key_code() != xtd::forms::keys::enter) return;
        try {
          color(xtd::drawing::color_translator::from_hsv(hsv_text_box_.text()));
        } catch(...) {
          try {
            color(xtd::drawing::color_translator::from_hsva(hsv_text_box_.text()));
          } catch(...) {
          }
        }
      };

      html_text_box_.parent(*this);
      html_text_box_.location({110, 485});
      html_text_box_.width(140);
      html_text_box_.anchor(xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::bottom | xtd::forms::anchor_styles::right);
      html_text_box_.key_down += [&](xtd::object& sender, xtd::forms::key_event_args& e){
        if (e.key_code() != xtd::forms::keys::enter) return;
        try {
          color(xtd::drawing::color_translator::from_html(html_text_box_.text()));
        } catch(...) {
        }
      };

      rgb_text_box_.parent(*this);
      rgb_text_box_.location({110, 515});
      rgb_text_box_.width(140);
      rgb_text_box_.anchor(xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::bottom | xtd::forms::anchor_styles::right);
      rgb_text_box_.key_down += [&](xtd::object& sender, xtd::forms::key_event_args& e){
        if (e.key_code() != xtd::forms::keys::enter) return;
        try {
          color(xtd::drawing::color_translator::from_rgb(rgb_text_box_.text()));
        } catch(...) {
          try {
            color(xtd::drawing::color_translator::from_rgba(rgb_text_box_.text()));
          } catch(...) {
          }
        }
      };

      win32_text_box_.parent(*this);
      win32_text_box_.location({110, 545});
      win32_text_box_.width(140);
      win32_text_box_.anchor(xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::bottom | xtd::forms::anchor_styles::right);
      win32_text_box_.key_down += [&](xtd::object& sender, xtd::forms::key_event_args& e){
        if (e.key_code() != xtd::forms::keys::enter) return;
        try {
          color(xtd::drawing::color_translator::from_win32(xtd::int32_object::parse(win32_text_box_.text(), xtd::number_styles::hex_number)));
        } catch(...) {
        }
      };
    }
    
    void color(const xtd::drawing::color& value) {
      if (color_ != value) {
        color_ = value;
        on_color_changed(xtd::event_args::empty);
      }
    }
    
    xtd::event<color_editor, xtd::event_handler> color_changed;
    
  protected:
    virtual void on_color_changed(const xtd::event_args& e) {
      color_box_panel_.invalidate();
      alpha_track_bar_.value(color_.a());
      alpha_numeric_up_down_.value(color_.a());
      red_track_bar_.value(color_.r());
      red_numeric_up_down_.value(color_.r());
      green_track_bar_.value(color_.g());
      green_numeric_up_down_.value(color_.g());
      blue_track_bar_.value(color_.b());
      blue_numeric_up_down_.value(color_.b());
      hex_ltext_box_.text(xtd::drawing::color_translator::to_hex(color_, true));
      hsl_text_box_.text(xtd::drawing::color_translator::to_hsl(color_, true));
      hsv_text_box_.text(xtd::drawing::color_translator::to_hsv(color_, true));
      html_text_box_.text(xtd::drawing::color_translator::to_html(color_));
      rgb_text_box_.text(xtd::drawing::color_translator::to_rgb(color_, true));
      win32_text_box_.text(xtd::ustring::format("0x{:x6}", xtd::drawing::color_translator::to_win32(color_)));
      color_changed(*this, e);
    }
    
  private:
  
    void on_argb_changed() {
      color(xtd::drawing::color::from_argb(xtd::as<unsigned char>(alpha_track_bar_.value()), xtd::as<unsigned char>(red_track_bar_.value()), xtd::as<unsigned char>(green_track_bar_.value()), xtd::as<unsigned char>(blue_track_bar_.value())));
    }
    
    xtd::forms::label alpha_label_;
    xtd::forms::label red_label_;
    xtd::forms::label green_label_;
    xtd::forms::label blue_label_;
    xtd::forms::track_bar alpha_track_bar_;
    xtd::forms::track_bar red_track_bar_;
    xtd::forms::track_bar green_track_bar_;
    xtd::forms::track_bar blue_track_bar_;
    xtd::forms::numeric_up_down alpha_numeric_up_down_;
    xtd::forms::numeric_up_down red_numeric_up_down_;
    xtd::forms::numeric_up_down green_numeric_up_down_;
    xtd::forms::numeric_up_down blue_numeric_up_down_;
    xtd::forms::panel color_box_panel_;
    xtd::forms::label hex_label_;
    xtd::forms::label hsl_label_;
    xtd::forms::label hsv_label_;
    xtd::forms::label html_label_;
    xtd::forms::label rgb_label_;
    xtd::forms::label win32_label_;
    xtd::forms::text_box hex_ltext_box_;
    xtd::forms::text_box hsl_text_box_;
    xtd::forms::text_box hsv_text_box_;
    xtd::forms::text_box html_text_box_;
    xtd::forms::text_box rgb_text_box_;
    xtd::forms::text_box win32_text_box_;
    xtd::drawing::color color_ = xtd::drawing::color::empty;
  };
}
