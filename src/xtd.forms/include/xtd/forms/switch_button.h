/// @file
/// @brief Contains xtd::forms::switch_button control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#include <optional>
#include "button_base.h"
#include "control_paint.h"

namespace xtd {
  namespace forms {
    /// @brief Represents a standard Windows switch button.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of switch button control.
    /// @include switch_button.cpp
    class switch_button : public button_base {
    public:
      /// Initialize new instance of switch_button class.
      switch_button() = default;
      
      /// @brief Gets a value indicating whether the checked and the switch_button's appearance are automatically changed when the switch_button is clicked.
      /// @return true if the checked value and the appearance of the control are automatically changed on the click event; otherwise, false. The default value is true.
      /// @remarks If auto_check is set to false, you will need to add code to update the checked in the click event handler.
      virtual bool auto_check() const {return auto_check_;}
      /// @brief Sets a value indicating whether the checked and the switch_button's appearance are automatically changed when the switch_button is clicked.
      /// @param auto_check true if the checked value and the appearance of the control are automatically changed on the click event; otherwise, false. The default value is true.
      /// @return Current switch_button instance.
      /// @remarks If auto_check is set to false, you will need to add code to update the checked in the click event handler.
      virtual switch_button& auto_check(bool auto_check) {
        if (auto_check_ != auto_check)
          auto_check_ = auto_check;
        return *this;
      }
      
      /// @brief Gets the checked background color for the control.
      /// @return A xtd::drawing::color that represents the checked background color of the control. The default is the value of the xtd::forms::theme_colors::current_theme::accent color.
      virtual xtd::drawing::color checked_back_color() const {return checked_back_color_.value_or(xtd::forms::theme_colors::current_theme().accent());}
      /// @brief Sets the checked background color for the control.
      /// @param color A xtd::drawing::color that represents the checked background color of the control. The default is the value of the xtd::forms::theme_colors::current_theme::accent clor.
      virtual switch_button& checked_back_color(const xtd::drawing::color& color) {
        if (!checked_back_color_.has_value() || checked_back_color_.value() != color) {
          checked_back_color_ = color;
          invalidate();
        }
        return *this;
      }
      /// @cond
      virtual switch_button& checked_back_color(nullptr_t) {
        if (checked_back_color_.has_value()) {
          checked_back_color_.reset();
          invalidate();
        }
        return *this;
      }
      /// @endcond
      
      /// @brief Gets the slider color for the control.
      /// @return A xtd::drawing::color that represents the slider color of the control. The default is the value of the xtd::switch_button::back_color property.
      virtual xtd::drawing::color slider_color() const {return slider_color_.value_or(back_color());}
      /// @brief Sets the slider color for the control.
      /// @param color A xtd::drawing::color that represents the slider color of the control. The default is the value of the xtd::switch_button::back_color property.
      virtual switch_button& slider_color(const xtd::drawing::color& color) {
        if (!slider_color_.has_value() || slider_color_.value() != color) {
          slider_color_ = color;
          invalidate();
        }
        return *this;
      }
      /// @cond
      virtual switch_button& slider_color(nullptr_t) {
        if (slider_color_.has_value()) {
          slider_color_.reset();
          invalidate();
        }
        return *this;
      }
      /// @endcond

      /// @brief Gets a value indicating whether the switch_button is rouded appearance.
      /// @return true if the switch_button is in the rounded appearance; otherwise, false. The default value is true.
      virtual bool rounded() const {return rounded_;}
      /// @brief Sets a value indicating whether the switch_button is rouded appearance.
      /// @param value true if the switch_button is in the rounded appearance; otherwise, false. The default value is true.
      /// @return Current switch_button instance.
      virtual switch_button& rounded(bool value) {
        if (rounded_ != value) {
          rounded_ = value;
          invalidate();
        }
        return *this;
      }
      
      /// @brief Gets a value indicating whether the switch_button is in the checked state.
      /// @return true if the switch_button is in the checked state; otherwise, false. The default value is false.
      virtual bool checked() const {return checked_;}
      /// @brief Sets a value indicating whether the switch_button is in the checked state.
      /// @param checked true if the switch_button is in the checked state; otherwise, false. The default value is false.
      /// @return Current switch_button instance.
      virtual switch_button& checked(bool checked) {
        if (checked_ != checked) {
          checked_ = checked;
          invalidate();
          on_checked_changed(event_args::empty);
        }
        return *this;
      }

      /// @brief Gets a value indicating whether the switch_button text is shown.
      /// @return true if the switch_button text is shown; otherwise, false. The default value is false.
      virtual bool show_text() const {return show_text_;}
      /// @brief Sets a value indicating whether the switch_button text is shown.
      /// @param value true if the switch_button text is shown; otherwise, false. The default value is false.
      /// @return Current switch_button instance.
      virtual switch_button& show_text(bool value) {
        if (show_text_ != value) {
          show_text_ = value;
          invalidate();
        }
        return *this;
      }

      /// @brief Occurs when the value of the checked property changes.
      /// @ingroup events
      event<switch_button, event_handler> checked_changed;

    protected:
      /// @brief Raises the switch_button::checked_changed event.
      /// @param e An event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_checked_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      virtual void on_checked_changed(const event_args& e) {checked_changed(*this, e);}

      void on_mouse_down(const mouse_event_args& e) override {
        button_base::on_mouse_down(e);
        if (auto_check_) checked(!checked());
      }
      
      void on_handle_created(const event_args& e) override {
        button_base::on_handle_created(e);
        invalidate();
      }
      
      void on_resize(const event_args& e) override {
        button_base::on_resize(e);
        invalidate();
      }

      void on_paint(paint_event_args& e) override {
        drawing::color button_back_color = checked_ ? checked_back_color() : xtd::forms::theme_colors::current_theme().gray_text();
        drawing::color text_color = checked_ ? fore_color() : drawing::color::average(button_back_color, fore_color(), .33);
        drawing::color slider_color = this->slider_color();
        xtd::ustring text = checked_ ? "ON" : "OFF";

        if (!enabled()) {
          button_back_color = drawing::color::average(back_color(), button_back_color, .33);
          text_color = drawing::color::average(button_back_color, text_color, .33);
          slider_color = drawing::color::average(button_back_color, slider_color, .33);
        }

        if (rounded_) {
          float height = static_cast<float>(e.clip_rectangle().height() - e.clip_rectangle().height() % 2);
          float offset = (e.clip_rectangle().width() - height) / 2.0f - 0.5f;
          drawing::point_f slider_location(checked_ ? drawing::point_f(e.clip_rectangle().width() - height - offset / 2.0f + 2.0f, 2.0f) : drawing::point_f(offset / 2.0f + 2.0f, 2.0f));

          drawing::size_f string_size = e.graphics().measure_string(text, font());
          drawing::point_f string_location(checked_ ? drawing::point_f(slider_location.x() - string_size.width() - 2, (height- string_size.height()) / 2) : drawing::point_f(slider_location.x() + static_cast<float>(height - 4) + 2, (height - string_size.height()) / 2));

          e.graphics().fill_pie(drawing::solid_brush(button_back_color), offset / 2.0f, .0f, static_cast<float>(height), static_cast<float>(height), 90.0f, 180.0f);
          e.graphics().fill_pie(drawing::solid_brush(button_back_color), e.clip_rectangle().width() - height - offset / 2.0f - 0.5f, .0f, static_cast<float>(height), static_cast<float>(height), 270.0f, 180.0f);
          e.graphics().fill_rectangle(drawing::solid_brush(button_back_color), height / 2.0f + offset / 2.0f, .0f, static_cast<float>(e.clip_rectangle().width() - height) - offset, static_cast<float>(height));
          e.graphics().fill_ellipse(drawing::solid_brush(slider_color), slider_location.x(), slider_location.y(), static_cast<float>(height - 4), static_cast<float>(height - 4));
          if (show_text_) e.graphics().draw_string(text, font(), drawing::solid_brush(text_color), string_location);
        } else {
          drawing::size_f slider_size(static_cast<float>((e.clip_rectangle().width() - 6) / 2), static_cast<float>(e.clip_rectangle().height() - 6));
          drawing::point_f slider_location(checked_ ? drawing::point_f(width() / 2.0f, 3.0f) : drawing::point_f(3.0f, 3.0f));

          drawing::size_f string_size = e.graphics().measure_string(text, font());
          drawing::point_f string_location(checked_ ? drawing::point_f((width() / 2 - string_size.width()) / 2, (height() - string_size.height()) / 2) : drawing::point_f(width() / 2 + (width() / 2 - string_size.width()) / 2, (height() - string_size.height()) / 2));

          e.graphics().clear(button_back_color);
          if (show_text_) e.graphics().draw_string(text, font(), drawing::solid_brush(text_color), string_location);
          e.graphics().draw_line(drawing::pen(control_paint::dark(button_back_color), 2), e.clip_rectangle().left(), e.clip_rectangle().top(), e.clip_rectangle().right(), e.clip_rectangle().top());
          e.graphics().draw_line(drawing::pen(control_paint::dark(button_back_color), 2), e.clip_rectangle().left(), e.clip_rectangle().top(), e.clip_rectangle().left(), e.clip_rectangle().bottom());
          e.graphics().draw_line(drawing::pen(control_paint::light(button_back_color), 2), e.clip_rectangle().left(), e.clip_rectangle().bottom(), e.clip_rectangle().right(), e.clip_rectangle().bottom());
          e.graphics().draw_line(drawing::pen(control_paint::light(button_back_color), 2), e.clip_rectangle().right(), e.clip_rectangle().top() + 2, e.clip_rectangle().right(), e.clip_rectangle().bottom());
          
          e.graphics().fill_rectangle(drawing::solid_brush(slider_color), {slider_location, slider_size});
          e.graphics().draw_line(drawing::pen(control_paint::light(slider_color)), slider_location.x(), slider_location.y(), slider_location.x() + slider_size.width(), slider_location.y());
          e.graphics().draw_line(drawing::pen(control_paint::light(slider_color)), slider_location.x(), slider_location.y(), slider_location.x(), slider_location.y() + slider_size.height() - 2);
          e.graphics().draw_line(drawing::pen(control_paint::dark(slider_color)), slider_location.x(), slider_location.y() + slider_size.height() - 1, slider_location.x() + slider_size.width(), slider_location.y() + slider_size.height() - 1);
          e.graphics().draw_line(drawing::pen(control_paint::dark(slider_color)), slider_location.x() + slider_size.width(), slider_location.y(), slider_location.x() + slider_size.width(), slider_location.y() + slider_size.height() - 1);
        }
        button_base::on_paint(e);
      }
      
    private:
      std::optional<xtd::drawing::color> checked_back_color_;
      std::optional<xtd::drawing::color> slider_color_;
      bool rounded_ = true;
      bool auto_check_ = true;
      bool show_text_ = false;
      bool checked_ = false;
    };
  }
}
