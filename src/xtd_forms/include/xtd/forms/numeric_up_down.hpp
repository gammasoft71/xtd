#pragma once
#include "up_down_base.hpp"

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

      event<numeric_up_down, event_handler<control&>> value_changed;
      
    protected:
      drawing::color default_back_color() const override {return drawing::system_colors::window();}
      
      drawing::color default_fore_color() const override {return drawing::system_colors::window_text();}
      
      drawing::size default_size() const override {return {120, 21};}

      forms::create_params create_params() const override;
      
      /// @brief Overrides control::on_handle_created(const event_args&)
      /// @param e A EventArgs that contains the event data.
      void on_handle_created(const event_args& e) override;

      void on_text_changed(const event_args& e) override;
      
      virtual void on_value_changed(const event_args& e);

      int32_t decimal_place_ = 0;
      double increment_ = 1.0;
      double maximum_ = 100.0;
      double minimum_ = 0.0;
      double value_ = 0.0;
    };
  }
}
