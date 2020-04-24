#pragma once
#include <chrono>
#include "control.h"
#include "date_time_picker_format.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class date_time_picker : public control {
    public:
      date_time_picker();

      virtual date_time_picker_format format() const {return format_;}
      virtual control& format(date_time_picker_format format);
      
      virtual std::chrono::system_clock::time_point max_date() const {return max_date_;}
      virtual control& max_date(std::chrono::system_clock::time_point max_date);
      virtual control& max_date(time_t max_date) {return this->max_date(std::chrono::system_clock::from_time_t(max_date));}
      virtual control& max_date(const std::tm& max_date) {
        std::tm internal_max_date = max_date;
        return this->max_date(mktime(&internal_max_date));
      }

      virtual std::chrono::system_clock::time_point min_date() const {return max_date_;}
      virtual control& min_date(std::chrono::system_clock::time_point min_date);
      virtual control& min_date(time_t min_date) {return this->min_date(std::chrono::system_clock::from_time_t(min_date));}
      virtual control& min_date(const std::tm& min_date) {
        std::tm internal_min_date = min_date;
        return this->min_date(mktime(&internal_min_date));
      }

      virtual std::chrono::system_clock::time_point value() const {return value_;}
      virtual control& value(std::chrono::system_clock::time_point value);
      virtual control& value(time_t value) {return this->value(std::chrono::system_clock::from_time_t(value));}
      virtual control& value(const std::tm& value) {
        std::tm internal_value = value;
        return this->value(mktime(&internal_value));
      }

      drawing::size default_size() const override {return{100, 25};}
      
      event<date_time_picker, event_handler<control&>> value_changed;

    protected:
      forms::create_params create_params() const override;
      
      drawing::color default_back_color() const override {return drawing::system_colors::window();}
      
      drawing::color default_fore_color() const override {return drawing::system_colors::window_text();}
      
      virtual void on_value_changed(const event_args& e);
      
      void on_handle_created(const event_args& e) override;
      
      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      void wnd_proc(message& message) override;
      
    private:
      void wm_click(message& message);
      date_time_picker_format format_ = date_time_picker_format::long_format;
      std::chrono::system_clock::time_point max_date_ = std::chrono::system_clock::time_point::max();
      std::chrono::system_clock::time_point min_date_ = std::chrono::system_clock::time_point::min();
      std::chrono::system_clock::time_point value_ = std::chrono::system_clock::now();
    };
  }
}
