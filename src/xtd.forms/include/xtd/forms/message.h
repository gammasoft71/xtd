/// @file
/// @brief Contains xtd::forms::message class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <iomanip>
#include <sstream>
#include <cstdint>
#include <string>
#include "../forms_export.h"

namespace xtd {
  namespace forms {
    class forms_export_ message {
    public:
      /// @cond
      message() = default;
      message(const message& message) = default;
      message& operator=(const message&) = default;
      /// @cond
      
      intptr_t hwnd() const {return hwnd_;}
      void hwnd(intptr_t value) {hwnd_ = value;}
      
      intptr_t lparam() const {return lparam_;}
      void lparam(intptr_t value) {lparam_ = value;}
      
      int32_t msg() const {return msg_;}
      void msg(int32_t value) {msg_ = value;}
      
      intptr_t result() const {return result_;}
      void result(intptr_t value) {result_ = value;}
      
      intptr_t wparam() const {return wparam_;}
      void wparam(intptr_t value) {wparam_ = value;}
      
      /// @cond
      intptr_t handle() const {return handle_;}
      void handle(intptr_t value) {handle_ = value;}
      /// @endcond
      
      static message create(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t result) {return message(hwnd, msg, wparam, lparam, result);}
      
      /// @cond
      static message create(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t result, intptr_t handle) {return message(hwnd, msg, wparam, lparam, result, handle);}
      /// @endcond
      
      template<typename type>
      type get_lparam() { return (type)lparam_; }
      
      std::string to_string() const;
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::forms::message& message) noexcept {
        return os << message.to_string();
      }
      /// @endcond

      
    private:
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
