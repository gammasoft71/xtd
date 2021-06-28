/// @file
/// @brief Contains xtd::diagnostics::trace_listener_collection class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <vector>
#include "trace_listener.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Represents a collection of trace_listener.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class trace_listener_collection : public std::vector<std::shared_ptr<trace_listener>> {
    public:
      /// @{
      /// Member types
      using value_type = std::shared_ptr<trace_listener>;
      using allocator_type = std::allocator<std::shared_ptr<trace_listener>>;
      using size_type = size_t;
      using difference_type = ptrdiff_t;
      using reference = value_type&;
      using const_reference = const value_type&;
      using pointer = typename std::allocator_traits<allocator_type>::pointer;
      using const_pointer = typename std::allocator_traits<allocator_type>::const_pointer;
      using iterator = typename std::vector<value_type>::iterator;
      using const_iterator = typename std::vector<value_type>::const_iterator;
      using reverse_iterator = typename std::vector<value_type>::reverse_iterator;
      using const_reverse_iterator = typename std::vector<value_type>::const_reverse_iterator;
      /// @}
      
      /// @brief Creats a new object trace_listener_collection
      explicit trace_listener_collection(const allocator_type& allocator = allocator_type()) : std::vector<std::shared_ptr<trace_listener>>(allocator) {}
      
      /// @cond
      trace_listener_collection(const std::initializer_list<std::shared_ptr<trace_listener>>& il) : std::vector<std::shared_ptr<trace_listener>>(il) {}
      trace_listener_collection(const std::vector<std::shared_ptr<trace_listener>>& collection) : std::vector<std::shared_ptr<trace_listener>>(collection) {}
      trace_listener_collection(const trace_listener_collection& collection) : std::vector<std::shared_ptr<trace_listener>>(collection) {}
      trace_listener_collection& operator=(const trace_listener_collection& collection) {
        std::vector<std::shared_ptr<trace_listener>>::operator=(collection);
        return *this;
      }
      trace_listener_collection(trace_listener_collection&&) = default;
      bool operator==(const trace_listener_collection& value) const {return reinterpret_cast<const std::vector<std::shared_ptr<trace_listener>>&>(*this) == reinterpret_cast<const std::vector<std::shared_ptr<trace_listener>>&>(value);}
      bool operator!=(const trace_listener_collection& value) const {return !operator==(value);}
      /// @endcond
    };
  }
}
