#pragma once
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Defines a message filter interface.
    /// @remarks This interface allows an application to capture a message before it is dispatched to a control or form.
    /// @remarks A class that implements the imessage_filter interface can be added to the application's message pump to filter out a message or perform other operations before the message is dispatched to a form or control. To add the message filter to an application's message pump, use the add_message_filter method in the application class.
    class imessage_filter  {
    public:
      /// @brief Filters out a message before it is dispatched.
      /// @param m The message to be dispatched. You cannot modify this message.
      /// @return true to filter the message and stop it from being dispatched; false to allow the message to continue to the next filter or control.
      /// @remarks Use pre_filter_message to filter out a message before it is dispatched to a control or form. For example, to stop the click event of a button control from being dispatched to the control, you implement the pre_filter_message method and return a true value when the click message occurs. You can also use this method to perform code work that you might need to do before the message is dispatched.
      virtual bool pre_filter_message(const message& m) const = 0;
      
      /// @cond
      virtual ~imessage_filter() = default;
      /// @endcond
    };
  }
}
