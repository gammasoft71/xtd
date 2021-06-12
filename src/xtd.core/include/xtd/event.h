/// @file
/// @brief Contains xtd::event event.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents an event.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core events
  /// @paramt object_t the owner object type of the event.
  /// @paramt handler_t Tipically a xtd::event_handler or inherited type.
  /// @remarks Only an object of type object_t can be create and invoke event.
  /// @par Examples
  /// The following example cshow hot to use event.
  /// @include event.cpp
  template<typename object_t, typename handler_t>
  class event : protected handler_t {
    friend object_t;
  public:
    /// @brief Gets a value indicate if the event is empty.
    /// @return true if evcent does not contains functions; otherwise false.
    bool is_empty() const noexcept { return handler_t::is_empty(); }

    /// @brief Adds an handler to the event.
    /// @param handler Handler to add.
    /// @return The current event instance.
    handler_t& operator+=(const handler_t& handler) noexcept {
      return handler_t::operator+=(handler);
    }
    
    /// @brief Adds a function to the event.
    /// @param handler Function to add.
    /// @return The current event instance.
    handler_t& operator+=(const typename handler_t::function_t& function) noexcept {
      return handler_t::operator+=(function);
    }
    
    /// @brief Adds a function to the event.
    /// @param function Function to add.
    /// @return The current event instance.
    template<typename fn_t>
    handler_t& operator+=(fn_t function) noexcept {
      return handler_t::operator+=(function);
    }
    
    /// @brief Removes an handler to the event.
    /// @param handler Handler to remove.
    /// @return The current event instance.
    handler_t& operator-=(const handler_t& handler) noexcept {
      return handler_t::operator-=(handler);
    }
    
    /// @brief Removes a function to the event.
    /// @param function Function to remove.
    /// @return The current event instance.
    handler_t& operator-=(const typename handler_t::function_t& function) noexcept {
      return handler_t::operator-=(function);
    }
    
    /// @brief Removes a function to the event.
    /// @param function Function to remove.
    /// @return The current event instance.
    template<typename fn_t>
    handler_t& operator-=(fn_t function) noexcept {
      return handler_t::operator-=(function);
    }
  };
}
