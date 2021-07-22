/// @file
/// @brief Contains xtd::forms::scroll_bar control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows scroll bar.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    // class forms_export_ scroll_bar : public control {
    class scroll_bar : public control {
    public:
      virtual int32_t large_change() const;
      virtual scroll_bar& large_change(int32_t large_change);
      
      virtual int32_t maximum() const;
      virtual scroll_bar& maximum(int32_t maximum);
      
      virtual int32_t minimum() const;
      virtual scroll_bar& minimum(int32_t minimum);
      
      virtual int32_t small_change() const;
      virtual scroll_bar& small_change(int32_t small_change);

      virtual int32_t value() const;
      virtual scroll_bar& value(int32_t value);

      /// @brief Occurs when either a mouse or keyboard action moves the scroll box.
      /// @ingroup events
      event<scroll_bar, event_handler> scroll;
      
      /// @brief Occurs when the value property of a scroll bar changes, either by movement of the scroll box or by manipulation in code.
      /// @ingroup events
      event<scroll_bar, event_handler> value_changed;

    protected:
      /// @brief Intializes a new instance of scroll_bar class.
      scroll_bar() = default;
 
      xtd::forms::create_params create_params() const override;
      
      void on_handle_created(const event_args& e) override;

      /// @brief Raises the scroll_bar::scroll event.
      /// @param e An event_args that contains the event data.
      /// @remarks You can use the OnScroll event to update other controls as the position of the scroll box changes.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_scroll method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Notes to Inheritors
      /// @remarks When overriding on_scroll(const event_args&) in a derived class, be sure to call the base class' on_scroll(const event_args&) method so that registered delegates receive the event.
      virtual void on_scroll(const event_args& e);
      
      /// @brief Raises the scroll_bar::value_changed event.
      /// @param e The event_args that contains the event data.
      virtual void on_value_changed(const event_args& e);

      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      void wnd_proc(message& message) override;
      
      /// @cond
      int32_t large_change_ = 10;
      int32_t maximum_ = 100;
      int32_t minimum_ = 0;
      int32_t small_change_ = 1;
      int32_t value_ = 0;
      bool vscroll_ = true;
      /// @endcond
      
    private:
      void wm_scroll(message& message);
    };
  }
}
