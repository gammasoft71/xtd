#pragma once
#include "control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class text_box_base : public control {
    public:      
      forms::cursor default_cursor() const override {return forms::cursors::ibeam();}

      virtual bool read_only() const {return read_only_;}
      virtual text_box_base& read_only(bool value) {
        if (read_only_ != value) {
          read_only_ = value;
          recreate_handle();
          on_read_only_changed(event_args::empty);
        }
        return *this;
      }
      
      event<text_box_base, event_handler<control&>> read_only_changed;
      
    protected:
      text_box_base() = default;
      virtual void on_read_only_changed(const event_args& e) {if (can_raise_events()) read_only_changed(*this, e);}
      bool read_only_ = false;
    };
  }
}
