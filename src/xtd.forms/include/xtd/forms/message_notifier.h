#pragma once
#include "component.h"

#include <xtd/delegate.h>
#include <xtd/ustring.h>
#include <xtd/drawing/icon.h>
#include <xtd/event.h>
#include <xtd/event_args.h>

#include <chrono>
#include "message_notifier_icon.h"
#include "message_notifier_buttons.h"
#include "notifier_result.h"
#include "notifier_style.h"
#include "iwin32_window.h"

//TODO: Documentation

namespace xtd {
  namespace forms {
    // TODO: move to seperate file
    class notifier_closed_event_args final : public event_args {
    public:
      notifier_closed_event_args() = default;
      explicit notifier_closed_event_args(forms::notifier_result notifier_result) : notifier_result_(notifier_result) {};
      virtual forms::notifier_result notifier_result() const {return notifier_result_;}
    private:
      forms::notifier_result notifier_result_ = forms::notifier_result::none;
    };
    using notifier_closed_event_handler = delegate<void(object& sender, const notifier_closed_event_args& e)>;
    
    
    class forms_export_ message_notifier final : public component {
    public:
      message_notifier() = default;
      
      /// Properties
      xtd::ustring title() const { return title_; }
      message_notifier& title(const xtd::ustring& title) { title_ = title; return *this; }
      
      xtd::ustring message() const { return message_; }
      message_notifier& message(const xtd::ustring& message) { message_ = message; return *this; }
      
      const xtd::drawing::image& icon() const { return icon_; }
      message_notifier& icon(const xtd::drawing::icon& icon) {icon_ = icon.to_bitmap(); return *this; }
      xtd::forms::message_notifier_icon notifier_icon() const { return notifier_icon_; }
      message_notifier& notifier_icon(xtd::forms::message_notifier_icon icon) {notifier_icon_ = icon; return *this; }
      
      bool close_timeout_enabled() const { return close_timeout_enabled_; }
      message_notifier& close_timeout_enabled(bool value) { close_timeout_enabled_ = value; return *this; }
      
      std::chrono::system_clock::duration close_timeout_interval() const { return close_timeout_interval_; }
      message_notifier& close_timeout_interval(std::chrono::system_clock::duration value) { close_timeout_interval_ = value; return *this; }
      
      xtd::forms::message_notifier_buttons buttons() const { return buttons_; }
      message_notifier& buttons(xtd::forms::message_notifier_buttons value) { buttons_ = value; return *this; }
      
      xtd::forms::notifier_style notifier_style() const {return notifier_style_; }
      message_notifier& notifier_style(xtd::forms::notifier_style notifier_style) { notifier_style_ = notifier_style; return *this; }
      
      xtd::forms::notifier_result notifier_result() const { return result_; }
      
      void reset();
      
      void show();
      void show(const iwin32_window& owner);
      
    public: /** Events */
      event<message_notifier, xtd::forms::notifier_closed_event_handler> notifier_closed;
      
    protected:
      virtual void on_notifier_closed(const xtd::forms::notifier_closed_event_args& e) {
        result_ = e.notifier_result();
        notifier_closed(*this, e);
      }
      
    private:
      xtd::ustring title_;
      xtd::ustring message_;
      xtd::drawing::image icon_ = xtd::drawing::image::empty;
      xtd::forms::message_notifier_icon notifier_icon_ = xtd::forms::message_notifier_icon::none;
      xtd::forms::message_notifier_buttons buttons_ = xtd::forms::message_notifier_buttons::none;
      bool close_timeout_enabled_ = false;
      std::chrono::system_clock::duration close_timeout_interval_ = std::chrono::seconds(10);
      xtd::forms::notifier_result result_ = xtd::forms::notifier_result::none;
      xtd::forms::notifier_style notifier_style_ = xtd::forms::notifier_style::system;
    };
  }
}
