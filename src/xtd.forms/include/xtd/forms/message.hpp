/// @file
/// @brief Contains xtd::forms::message class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.hpp"
#include <xtd/object>
#include <xtd/string>
#include <cstdint>
#include <iomanip>
#include <sstream>
#include <string>

namespace xtd {
  namespace forms {
    /// @cond
    class application;
    class control;
    /// @endcond
    
    /// @brief Implements a Windows message.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/message>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks The message structure wraps messages that Windows sends. You can use this structure to wrap a message and assign it to the window procedure to be dispatched. You can also use this structure to get information about a message the system sends to your application or controls.
    /// @remarks You cannot create the message directly. Instead, use the create method. For the sake of efficiency, the message uses its pool of existing Messages instead of instantiating a new one, if possible. However, if a message is not available in the pool, a new one is instantiated.
    /// @remarks Windows message are simulate on macOS and linux.
    struct forms_export_ message : object, iequatable<message> {
      /// @cond
      message() = default;
      message(message&& message) = default;
      message(const message& message) = default;
      message& operator =(message&&) = default;
      message& operator =(const message&) = default;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets or sets the window handle of the message.
      /// @param hwnd The window handle of the message.
      /// @remarks Window handle is a value that uniquely identifies a window on the system. This property returns a handle of the window whose window procedure receives this message. It is useful when your code need to interact with some native Windows API functions that expect window handles as parameters.
      intptr hwnd = 0;
      
      /// @brief Gets or sets the ID number for the message.
      /// @param msg The ID number for the message.
      uint32 msg = 0;
      
      /// @brief Gets or sets the wparam field of the message.
      /// @param wparam The wparam field of the message.
      /// @remarks The value of this field depends on the message. Use the wparam field to get information that is important to handling the message. This field is typically used to store small pieces of information, such as flags.
      intptr wparam = 0;
      
      /// @brief Sets the lparam field of the message.
      /// @param lparam The lparam field of the message.
      /// @remarks The value of this field depends on the message. Use the lparam field to get information that is important for handling the message. lparam is typically used to store an object if it is needed by the message.
      intptr lparam = 0;
      
      /// @brief Gets or sets the value that is returned to Windows in response to handling the message.
      /// @param result The return value of the message.
      intptr result = 0;
      
      /// @brief Gets or sets the handle field of the message.
      /// @param handle The handle field of the message.
      /// @warning Internal use only
      intptr __handle__ = 0;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      bool equals(const xtd::object& obj) const noexcept override;
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param other The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      bool equals(const message& other) const noexcept override;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      xtd::size get_hash_code() const noexcept override;
      
      /// @brief Gets the lparam value and converts the value to an object.
      /// @tparam type The type to use to create an instance. This type must be declared as a structure type.
      /// @return An object that represents an instance of the class specified by the template parameter, with the data from the lparam field of the message.
      template<class type_t>
      type_t get_lparam() const noexcept { return reinterpret_cast<type_t>(lparam); }
      
      /// @brief Returns a string that represents the msg property.
      /// @return A xtd::string that represents the msg property.
      xtd::string to_msg_string() const noexcept;
      
      /// @brief Returns a string that represents the current message.
      /// @return A xtd::string that represents the current message.
      xtd::string to_string() const noexcept override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Creates a new message.
      /// @param hwnd The window handle that the message is for.
      /// @param msg The message ID.The message ID.
      /// @param wparam The message wparam field.
      /// @param lparam The message lparam field.
      /// @return A xtd::forms::message that represents the message that was created.
      /// @remarks Use the xtd::message::create method to create a xtd::forms::message to wrap a message sent by Windows.
      static message create(intptr hwnd, int32 msg, intptr wparam, intptr lparam);
      /// @}
      
    private:
      friend class application;
      friend class control;
      message(intptr hwnd, int32 msg, intptr wparam, intptr lparam, intptr result, intptr handle);
    };
  }
}
