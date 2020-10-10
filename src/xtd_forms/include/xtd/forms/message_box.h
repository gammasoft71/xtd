#pragma once
#include "dialog_result.h"
#include "iwin32_window.h"
#include "message_box_buttons.h"
#include "message_box_default_button.h"
#include "message_box_icon.h"
#include "message_box_options.h"
#include <xtd/static.h>

/// @cond
struct __xtd_forms_message_box_closed_caller__;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond

    class message_box_closed_event_args : public event_args {
    public:
      message_box_closed_event_args() = default;
      message_box_closed_event_args(forms::dialog_result dialog_result) : dialog_result_(dialog_result) {};
      
      /// @cond
      message_box_closed_event_args(const message_box_closed_event_args& form_closed_event_args) = default;
      message_box_closed_event_args& operator=(const message_box_closed_event_args& form_closed_event_args) = default;
      /// @endcond
      
      forms::dialog_result dialog_result() const {return this->dialog_result_;}
      
    private:
      forms::dialog_result dialog_result_ = forms::dialog_result::none;
    };

    using message_box_closed_event_handler = delegate<void(const message_box_closed_event_args& e)>;

    class message_box static_ {
    public:
      static event<message_box, message_box_closed_event_handler> message_box_closed;

      
      static void show_sheet(const iwin32_window& owner, const std::string& text);
      
      static void show_sheet(const iwin32_window& owner, const std::string& text, const std::string& caption);
      
      static void show_sheet(const iwin32_window& owner, const std::string& text, const std::string& caption, message_box_buttons buttons);
      
      static void show_sheet(const iwin32_window& owner, const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon);
      
      static void show_sheet(const iwin32_window& owner, const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button);
      
      static void show_sheet(const iwin32_window& owner, const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options);
      
      static void show_sheet(const iwin32_window& owner, const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button);
      
      static dialog_result show(const iwin32_window& owner, const std::string& text);
      
      static dialog_result show(const iwin32_window& owner, const std::string& text, const std::string& caption);
      
      static dialog_result show(const iwin32_window& owner, const std::string& text, const std::string& caption, message_box_buttons buttons);
      
      static dialog_result show(const iwin32_window& owner, const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon);
      
      static dialog_result show(const iwin32_window& owner, const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button);
      
      static dialog_result show(const iwin32_window& owner, const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options);
      
      static dialog_result show(const iwin32_window& owner, const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button);
      
      static dialog_result show(const std::string& text);
      
      static dialog_result show(const std::string& text, const std::string& caption);
      
      static dialog_result show(const std::string& text, const std::string& caption, message_box_buttons buttons);

      static dialog_result show(const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon);

      static dialog_result show(const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button);

      static dialog_result show(const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options);

      static dialog_result show(const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button);
      
    private:
      friend struct ::__xtd_forms_message_box_closed_caller__;
      static void call_message_box_closed(dialog_result dialog_result) {
        message_box_closed(dialog_result);
      }
    };
  }
}
