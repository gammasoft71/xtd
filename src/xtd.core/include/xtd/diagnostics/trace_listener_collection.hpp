/// @file
/// @brief Contains xtd::diagnostics::trace_listener_collection class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include "../collections/generic/list.hpp"
#include "../iequatable.hpp"
#include "trace_listener.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Represents a collection of xtd::diagnostics::trace_listener.
    /// ```cpp
    /// class core_export_ trace_listener_collection : public xtd::collections::generic::list<xtd::sptr<xtd::diagnostics::trace_listener>>
    /// ```
    /// @par Inheritance
    /// xtd::collections::generic::list<xtd::sptr<xtd::diagnostics::trace_listener>> → xtd::diagnostics::trace_listener_collection
    /// @par Header
    /// ```cpp
    /// #include <xtd/diagnostics/trace_listener_collection>
    /// ```
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class core_export_ trace_listener_collection : public xtd::collections::generic::list<xtd::sptr<xtd::diagnostics::trace_listener>>, public xtd::iequatable<trace_listener_collection> {
    public:
      /// @name Public Aliases
      
      /// @{
      /// @brief Represents the base type of the collection.
      using base = xtd::collections::generic::list<value_type>;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Creates a new object xtd::diagnostics::trace_listener_collection with specified allocator (optional).
      explicit trace_listener_collection() = default;
      /// @brief Creates a new object xtd::diagnostics::trace_listener_collection with specified initializer list.
      /// @param il The initializer list that contains xtd::diagnostics::trace_listener items to fill the collection.
      trace_listener_collection(const std::initializer_list<value_type>& il); // Can't be explicit by design.
      /// @}
      /// @cond
      explicit trace_listener_collection(const base& collection);
      trace_listener_collection(const trace_listener_collection& collection);
      trace_listener_collection& operator =(const trace_listener_collection& collection);
      trace_listener_collection(trace_listener_collection&&) = default;
      /// @endcond
      
      /// @{
      bool equals(const object& value) const noexcept override;
      using list::equals;
      bool equals(const trace_listener_collection& value) const noexcept override;
      /// @}
      
      /// @name Operators
      
      /// @{
      using base::operator [];
      /// @brief Gets the first xtd::diagnostics::trace_listener in the list with the specified name.
      /// @param name The name of the xtd::diagnostics::trace_listener to get from the list.
      /// @return The first xtd::diagnostics::trace_listener in the list with the given Name. This item returns empty if no xtd::diagnostics::trace_listener with the given name can be found.
      /// @remarks The operator [] property is case-sensitive when searching for names. That is, if two listeners exist with the names "Lname" and "lname", operator [] property will find only the xtd::diagnostics::trace_listener with the xtd::diagnostics::trace_listener::name() that you specify, not both.
      /// @par Examples
      /// This example shows how to write "User message" text on the default trace listener of debug with name operator:
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using xtd::diagnostics;
      ///
      /// auto main() -> int {
      ///   debug::listeners()["default"]->write_line("User message");
      /// }
      /// ```
      const_reference operator [](const xtd::string& name) const;
      /// @brief Gets the first xtd::diagnostics::trace_listener in the list with the specified name.
      /// @param name The name of the xtd::diagnostics::trace_listener to get from the list.
      /// @return The first xtd::diagnostics::trace_listener in the list with the given Name. This item returns empty if no xtd::diagnostics::trace_listener with the given name can be found.
      /// @remarks The operator [] property is case-sensitive when searching for names. That is, if two listeners exist with the names "Lname" and "lname", operator [] property will find only the xtd::diagnostics::trace_listener with the xtd::diagnostics::trace_listener::name() that you specify, not both.
      /// @par Examples
      /// This example shows how to write "User message" text on the default trace listener of debug with name operator:
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using xtd::diagnostics;
      ///
      /// auto main() -> int {
      ///   debug::listeners()["default"]->write_line("User message");
      /// }
      /// ```
      reference operator [](const xtd::string& name);
      /// @}
      
      /// @name Public Methods
      
    private:
      inline static value_type empty_;
    };
  }
}
