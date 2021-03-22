/// @file
/// @brief Contains xtd::forms::scrollable_control control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "system_information.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class forms_export_ scrollable_control : public control {
    public:
      virtual bool auto_scroll() const {return auto_scroll_;}
      virtual scrollable_control& auto_scroll(bool auto_scroll) {
        if (auto_scroll_ != auto_scroll) {
          auto_scroll_ = auto_scroll;
          recreate_handle();
        }
        return *this;
      }

      drawing::size auto_scroll_margin() const {return auto_scroll_margin_;}
      scrollable_control& auto_scroll_margin(const drawing::size& value) {
        if (auto_scroll_margin_ != value) {
          auto_scroll_margin_ = value;
          on_layout(event_args::empty);
        }
        return *this;
      }

      drawing::rectangle display_rectangle() const override {return display_rectangle_;}
      
      virtual bool hscroll() const {return hscroll_;}
      virtual scrollable_control& hscroll(bool hscroll) {
        if (hscroll_ != hscroll) {
          hscroll_ = hscroll;
          recreate_handle();
        }
        return *this;
      }
      
      virtual bool vscroll() const {return vscroll_;}
      virtual scrollable_control& vscroll(bool vscroll) {
        if (vscroll_ != vscroll) {
          vscroll_ = vscroll;
          recreate_handle();
        }
        return *this;
      }

    protected:
      scrollable_control() = default;

      forms::create_params create_params() const override;

      void on_layout(const event_args& e) override {
        control::on_layout(e);
        if (auto_scroll_) {
          display_rectangle_ = client_rectangle_;
          display_rectangle_.height(display_rectangle_.height() - system_information::horizontal_scroll_bar_height());
          display_rectangle_.width(display_rectangle_.width() - system_information::vertical_scroll_bar_width());
          for (auto item : controls()) {
            if (item.get().visible())
              display_rectangle_ = drawing::rectangle::make_union(display_rectangle_, item.get().bounds());
          }
          display_rectangle_.width(display_rectangle_.width() + auto_scroll_margin_.width());
          display_rectangle_.height(display_rectangle_.height() + auto_scroll_margin_.height());
        }
      }

      /// @cond
      bool auto_scroll_ = false;
      bool hscroll_ = false;
      bool vscroll_ = false;
      drawing::rectangle display_rectangle_;
      drawing::size auto_scroll_margin_;
      /// @endcond
    };
  }
}
