#pragma once
#include "dialog_result.hpp"
#include "message_box_buttons.hpp"
#include "message_box_default_button.hpp"
#include "message_box_icon.hpp"
#include "message_box_options.hpp"
#include <xtd/static.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond
    
    class message_box static_ {
    public:
      static dialog_result show(const control& owner, const std::string& text);
      
      static dialog_result show(const control& owner, const std::string& text, const std::string& caption);
      
      static dialog_result show(const control& owner, const std::string& text, const std::string& caption, message_box_buttons buttons);

      static dialog_result show(const control& owner, const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon);

      static dialog_result show(const control& owner, const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button);

      static dialog_result show(const control& owner, const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options);

      static dialog_result show(const control& owner, const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button);

      static dialog_result show(const std::string& text);
      
      static dialog_result show(const std::string& text, const std::string& caption);
      
      static dialog_result show(const std::string& text, const std::string& caption, message_box_buttons buttons);

      static dialog_result show(const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon);

      static dialog_result show(const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button);

      static dialog_result show(const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options);

      static dialog_result show(const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button);
    };
  }
}
