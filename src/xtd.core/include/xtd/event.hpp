/// @file
/// @brief Contains xtd::event event.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents an event.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @tparam object_t the owner object type of the event.
  /// @tparam handler_t Typically a xtd::event_handler or inherited type.
  /// @remarks Only an object of type object_t can be create and invoke event.
  /// @remarks For more info about events see [Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/events) guide.
  /// @par Examples
  /// The following example cshow hot to use event.
  /// @include event.cpp
  template<typename object_t, typename handler_t>
  class event : protected handler_t {
    friend object_t;
  public:
    /// @name Public Properties
    
    /// @{
    /// @brief Gets a value indicate if the event is empty.
    /// @return `true` if evcent does not contains functions; otherwise `false`.
    [[nodiscard]] auto is_empty() const noexcept -> bool {return handler_t::is_empty();}
    /// @}
    
    /// @name Operators
    
    /// @{
    /// @brief Adds an handler to the event.
    /// @param handler Handler to add.
    /// @return The current event instance.
    auto operator +=(const handler_t& handler) noexcept -> handler_t& {return handler_t::operator +=(handler);}
    
    /// @brief Adds a function to the event.
    /// @param handler Function to add.
    /// @return The current event instance.
    auto operator +=(const typename handler_t::function_t& function) noexcept -> handler_t& {return handler_t::operator +=(function);}
    
    /// @brief Adds a function to the event.
    /// @param function Function to add.
    /// @return The current event instance.
    template<typename fn_t>
    auto operator +=(fn_t function) noexcept -> handler_t& {return handler_t::operator +=(function);}
    
    /// @brief Removes an handler to the event.
    /// @param handler Handler to remove.
    /// @return The current event instance.
    auto operator -=(const handler_t& handler) noexcept -> handler_t& {return handler_t::operator -=(handler);}
    
    /// @brief Removes a function to the event.
    /// @param function Function to remove.
    /// @return The current event instance.
    auto operator -=(const typename handler_t::function_t& function) noexcept -> handler_t& {return handler_t::operator -=(function);}
    
    /// @brief Removes a function to the event.
    /// @param function Function to remove.
    /// @return The current event instance.
    template<typename fn_t>
    auto operator -=(fn_t function) noexcept -> handler_t& {return handler_t::operator -=(function);}
    
    /// @brief Clear event.
    auto clear() noexcept -> void {*this = event {};}
    /// @}
  };
}
