#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<typename object_t, typename handler_t>
  class event : public handler_t {
  private:
    friend object_t;
    template<typename... arguments_t>
    void invoke(arguments_t&&... arguments) const {
      this->handler_t::invoke(arguments...);
    }
    
    template<typename... arguments_t>
    void operator()(arguments_t&&... arguments) const {
      this->invoke(arguments...);
    }
  };
}
