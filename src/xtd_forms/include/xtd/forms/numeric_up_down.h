#pragma once
#include "up_down_base.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class numeric_up_down : public up_down_base {
    public:      
      numeric_up_down();

      virtual double decimal_place() {return decimal_place_;}
      virtual numeric_up_down& decimal_place(int32_t value);

      virtual double increment() {return increment_;}
      virtual numeric_up_down& increment(double value);
      
      virtual double maximum() {return maximum_;}
      virtual numeric_up_down& maximum(double value);
      
      virtual double minimum() {return minimum_;}
      virtual numeric_up_down& minimum(double value);

      virtual double value() {return value_;}
      virtual numeric_up_down& value(double value);
      
      virtual bool wrapped() {return wrapped_;}
      virtual numeric_up_down& wrapped(bool value);
      
      /// @brief Sets the minimum and maximum values for a track_bar.
      /// @param min_value The lower limit of the range of the track bar.
      /// @param max_value The upper limit of the range of the track bar.
      /// @remarks You can use this method to set the entire range for the track_bar at the same time. To set the minimum or maximum values individually, use the minimum and maximum properties. If the min_value parameter is greater than the max_value parameter, max_value is set equal to min_value.
      void set_range(int min_value, int max_value) {
        this->minimum(min_value);
        this->maximum(min_value > max_value ? min_value : max_value);
      }
      
      /// @brief Returns a string that represents the track_bar control.
      /// @return A string that represents the current progress_bar.
      /// @remarks The return string includes the type and the values for the minimum, maximum, and value properties.
      std::string to_string() const override {return strings::format("{}, minimum: {}, maximum: {}, value: {}", strings::full_class_name(*this), this->minimum_, this->maximum_, this->value_);}

      event<numeric_up_down, event_handler<control&>> value_changed;
      
    protected:
      drawing::color default_back_color() const override {return xtd::forms::theme_color::current_theme_color().window();}
      
      drawing::color default_fore_color() const override {return xtd::forms::theme_color::current_theme_color().window_text();}
      
      drawing::size default_size() const override {return {120, 21};}

      forms::create_params create_params() const override;
      
      /// @brief Overrides control::on_handle_created(const event_args&)
      /// @param e A EventArgs that contains the event data.
      void on_handle_created(const event_args& e) override;

      virtual void on_value_changed(const event_args& e);

      /// @cond
      void wnd_proc(message& message) override;
      void wm_command(message& message);
      /// @endcond

      int32_t decimal_place_ = 0;
      double increment_ = 1.0;
      double maximum_ = 100.0;
      double minimum_ = 0.0;
      double value_ = 0.0;
      bool wrapped_ = false;
    };
  }
}
