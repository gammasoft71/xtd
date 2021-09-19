/// @file
/// @brief Contains xtd::forms::message class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <iomanip>
#include <sstream>
#include <cstdint>
#include <string>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include "../forms_export.h"

namespace xtd {
  namespace forms {
    /// @brief Implements a Windows message.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks The message structure wraps messages that Windows sends. You can use this structure to wrap a message and assign it to the window procedure to be dispatched. You can also use this structure to get information about a message the system sends to your application or controls.
    /// @remarks You cannot create the message directly. Instead, use the create method. For the sake of efficiency, the message uses its pool of existing Messages instead of instantiating a new one, if possible. However, if a message is not available in the pool, a new one is instantiated.
    /// @remarks Windows message are simulate on macOS and linux.
    class forms_export_ message : public object {
    public:
      /// @cond
      message() = default;
      message(const message& message) = default;
      message& operator=(const message&) = default;
      /// @endcond
      
      /// @brief Gets the window handle of the message.
      /// @return The window handle of the message.
      /// @remarks Window handle is a value that uniquely identifies a window on the system. This property returns a handle of the window whose window procedure receives this message. It is useful when your code need to interact with some native Windows API functions that expect window handles as parameters.
      intptr_t hwnd() const {return hwnd_;}
      /// @brief Sets the window handle of the message.
      /// @param hwnd The window handle of the message.
      /// @remarks Window handle is a value that uniquely identifies a window on the system. This property returns a handle of the window whose window procedure receives this message. It is useful when your code need to interact with some native Windows API functions that expect window handles as parameters.
      void hwnd(intptr_t value) {hwnd_ = value;}
      
      /// @brief Gets the lparam field of the message.
      /// @return The lparam field of the message.
      /// @remarks The value of this field depends on the message. Use the lparam field to get information that is important for handling the message. lparam is typically used to store an object if it is needed by the message.
      intptr_t lparam() const {return lparam_;}
      /// @brief Sets the lparam field of the message.
      /// @param value The lparam field of the message.
      /// @remarks The value of this field depends on the message. Use the lparam field to get information that is important for handling the message. lparam is typically used to store an object if it is needed by the message.
      void lparam(intptr_t value) {lparam_ = value;}
      
      /// @brief Gets the ID number for the message.
      /// @return The ID number for the message.
      int32_t msg() const {return msg_;}
      /// @brief Sets the ID number for the message.
      /// @param value The ID number for the message.
      void msg(int32_t value) {msg_ = value;}
      
      /// @brief Gets the value that is returned to Windows in response to handling the message.
      /// @return The return value of the message.
      intptr_t result() const {return result_;}
      /// @brief Sets the value that is returned to Windows in response to handling the message.
      /// @param value The return value of the message.
      void result(intptr_t value) {result_ = value;}
      
      /// @brief Gets the wparam field of the message.
      /// @return The wparam field of the message.
      /// @remarks The value of this field depends on the message. Use the wparam field to get information that is important to handling the message. This field is typically used to store small pieces of information, such as flags.
      intptr_t wparam() const {return wparam_;}
      /// @brief Sets the wparam field of the message.
      /// @param value The wparam field of the message.
      /// @remarks The value of this field depends on the message. Use the wparam field to get information that is important to handling the message. This field is typically used to store small pieces of information, such as flags.
      void wparam(intptr_t value) {wparam_ = value;}
      
      /// @cond
      intptr_t handle() const {return handle_;}
      void handle(intptr_t value) {handle_ = value;}
      /// @endcond
      
      /// @brief Creates a new message.
      /// @param hwnd The window handle that the message is for.
      /// @param msg The message ID.The message ID.
      /// @param wparam The message wparam field.
      /// @param lparam The message lparam field.
      /// @return A xtd::forms::message that represents the message that was created.
      /// @remarks Use the xtd::message::create method to create a xtd::forms::message to wrap a message sent by Windows.
      static message create(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam) {return message(hwnd, msg, wparam, lparam);}
      
      /// @cond
      static message create(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t result) {return message(hwnd, msg, wparam, lparam, result);}
      static message create(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t result, intptr_t handle) {return message(hwnd, msg, wparam, lparam, result, handle);}
      /// @endcond
      
      /// @brief Gets the lparam value and converts the value to an object.
      /// @tparam type The type to use to create an instance. This type must be declared as a structure type.
      /// @return An object that represents an instance of the class specified by the template parameter, with the data from the lparam field of the message.
      template<typename type>
      type get_lparam() { return reinterpret_cast<type>(lparam_); }
      
      /// @brief Returns a string that represents the current message.
      /// @return A xtd::ustring that represents the current message.
      xtd::ustring to_string() const noexcept override;
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::forms::message& message) noexcept {
        return os << message.to_string();
      }
      /// @endcond

      
    private:
      message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam) : hwnd_(hwnd), msg_(msg), wparam_(wparam), lparam_(lparam) {counter_++;}
      message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t result) : hwnd_(hwnd), msg_(msg), wparam_(wparam), lparam_(lparam), result_(result) {counter_++;}
      message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t result, intptr_t handle) : hwnd_(hwnd), msg_(msg), wparam_(wparam), lparam_(lparam), result_(result), handle_(handle) {counter_++;}
      
      intptr_t hwnd_ = 0;
      int32_t msg_ = 0;
      intptr_t wparam_ = 0;
      intptr_t lparam_ = 0;
      intptr_t result_ = 0;
      intptr_t handle_ = 0;
      static int32_t counter_;
    };
  }
}
