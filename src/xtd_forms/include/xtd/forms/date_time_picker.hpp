#pragma once
#include <ctime>
#include "control.hpp"
#include "date_time_picker_format.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class date_time_picker : public control {
    public:
      date_time_picker();

      virtual date_time_picker_format format() const {return format_;}
      virtual control& format(date_time_picker_format format);
      
      virtual std::tm max_date() const {return max_date_;}
      virtual control& max_date(const std::tm& max_date);
      
      virtual std::tm min_date() const {return max_date_;}
      virtual control& min_date(const std::tm& min_date);
      
      virtual std::tm value() const {return value_;}
      virtual control& value(const std::tm& value);

      drawing::size default_size() const override {return{100, 25};}
      
      event<date_time_picker, event_handler<control&>> value_changed;

    protected:
      forms::create_params create_params() const override;
      
      virtual void on_value_changed(const event_args& e);
      
      void on_handle_created(const event_args& e) override;
      
      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      void wnd_proc(message& message) override;
      
    private:
      void wm_click(message& message);
      date_time_picker_format format_ = date_time_picker_format::long_format;
      std::tm max_date_ {23, 59, 59, 31, 11, 8098, 0, 0, 0, 0, nullptr};
      std::tm min_date_ {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, nullptr};
      std::tm value_ {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, nullptr};
    };
  }
}
