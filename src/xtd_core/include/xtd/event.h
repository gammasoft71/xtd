#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<typename object_t, typename handler_t>
  class event : protected handler_t {
    friend object_t;
  public:
    bool is_empty() const noexcept { return this->handler_t::is_empty(); }

    handler_t& operator+=(const handler_t& handler) noexcept {
      return this->handler_t::operator+=(handler);
    }
    
    handler_t& operator +=(const typename handler_t::function_t& function) noexcept {
      return this->handler_t::operator+=(function);
    }
    
    template<typename fn_t>
    handler_t& operator +=(fn_t function) noexcept {
      return this->handler_t::operator+=(function);
    }
    
    handler_t& operator -=(const handler_t& delegate) noexcept {
      return this->handler_t::operator-=(delegate);
    }
    
    handler_t& operator -=(const typename handler_t::function_t& function) noexcept {
      return this->handler_t::operator-=(function);
    }
    
    template<typename fn_t>
    handler_t& operator -=(fn_t function) noexcept {
      return this->handler_t::operator-=(function);
    }
  };
}
