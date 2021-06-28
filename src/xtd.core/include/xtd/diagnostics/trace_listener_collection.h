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
    /// @brief Represents a collection of xtd::diagnostics::trace_listener.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks The xtd::diagnostics::trace_listener_collection contains all methods and properties of std::vector<std::shared_ptr<xtd::diagnostics::trace_listener>>.
    class trace_listener_collection : public std::vector<std::shared_ptr<xtd::diagnostics::trace_listener>> {
    public:
      /// @brief Represents the value type of the collection.
      using value_type = std::shared_ptr<trace_listener>;
      /// @brief Represents the allocator type of the collection.
      using allocator_type = std::allocator<value_type>;
      /// @brief Represents the size type of the collection.
      using size_type = size_t;
      /// @brief Represents the pointer difference type of the collection.
      using difference_type = ptrdiff_t;
      /// @brief Represents the value type reference of the collection.
      using reference = value_type&;
      /// @brief Represents the value type const reference the collection.
      using const_reference = const value_type&;
      /// @brief Represents the value type pointer of the collection.
      using pointer = typename std::allocator_traits<allocator_type>::pointer;
      /// @brief Represents the value type const pointer of the collection.
      using const_pointer = typename std::allocator_traits<allocator_type>::const_pointer;
      /// @brief Represents the base type of the collection.
      using base = std::vector<std::shared_ptr<trace_listener>>;
      /// @brief Represents the iterator type of the collection.
      using iterator = typename base::iterator;
      /// @brief Represents the const iterator type of the collection.
      using const_iterator = typename base::const_iterator;
      /// @brief Represents the reverse iterrator type of the collection.
      using reverse_iterator = typename base::reverse_iterator;
      /// @brief Represents the constt reverse iterator type of the collection.
      using const_reverse_iterator = typename base::const_reverse_iterator;
      
      /// @brief Creates a new object xtd::diagnostics::trace_listener_collection with specified alllocator (optional).
      /// @param allocator The allocator associate to the collection (optional).
      /// @remarks If allocator not specified, the std::allocator<value_type> is used.
      explicit trace_listener_collection(const allocator_type& allocator = allocator_type()) : base(allocator) {}
      /// @brief Creates a new object xtd::diagnostics::trace_listener_collection with specified initializer list.
      /// @param il The initializer list that contains xtd::diagnostics::trace_listener items to fill the collection.
      trace_listener_collection(const std::initializer_list<value_type>& il) : base(il) {}

      /// @cond
      trace_listener_collection(const base& collection) : base(collection) {}
      trace_listener_collection(const trace_listener_collection& collection) : base(collection) {}
      trace_listener_collection& operator=(const trace_listener_collection& collection) {
        base::operator=(collection);
        return *this;
      }
      trace_listener_collection(trace_listener_collection&&) = default;
      bool operator==(const trace_listener_collection& value) const {return reinterpret_cast<const base&>(*this) == reinterpret_cast<const base&>(value);}
      bool operator!=(const trace_listener_collection& value) const {return !operator==(value);}
      /// @endcond
      
      using base::operator[];

      /// @brief Gets the first xtd::diagnostics::trace_listener in the list with the specified name.
      /// @param name The name of the xtd::diagnostics::trace_listener to get from the list.
      /// @return The first xtd::diagnostics::trace_listener in the list with the given Name. This item returns empty if no xtd::diagnostics::trace_listener with the given name can be found.
      /// @remarks The operator[] property is case-sensitive when searching for names. That is, if two listeners exist with the names "Lname" and "lname", operator[] property will find only the xtd::diagnostics::trace_listener with the xtd::diagnostics::trace_listener::name() that you specify, not both.
      const_reference operator[](const std::string& name) const {
        for(auto& item : *this)
          if(item->name() == name) return item;
        return empty_;
      }
      
      /// @brief Gets the first xtd::diagnostics::trace_listener in the list with the specified name.
      /// @param name The name of the xtd::diagnostics::trace_listener to get from the list.
      /// @return The first xtd::diagnostics::trace_listener in the list with the given Name. This item returns empty if no xtd::diagnostics::trace_listener with the given name can be found.
      /// @remarks The operator[] property is case-sensitive when searching for names. That is, if two listeners exist with the names "Lname" and "lname", operator[] property will find only the xtd::diagnostics::trace_listener with the xtd::diagnostics::trace_listener::name() that you specify, not both.
      reference operator[](const std::string& name) {
        for(auto& item : *this)
          if(item->name() == name) return item;
        return empty_;
      }

    private:
      inline static value_type empty_;
    };
  }
}
