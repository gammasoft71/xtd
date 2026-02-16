/// @file
/// @brief Contains xtd::forms::form_collection alias.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "form.hpp"
#include <xtd/ref>
#include <xtd/collections/generic/list>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a collection of form objects.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/form_collection>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks form_collection is used by the application object to list the currently open forms in an application through the open_forms property.
    class form_collection : public xtd::collections::generic::list<xtd::ref<form>> {
    public:
      /// @name Public Aliases
      
      /// @{
      /// @brief Represents the base type of the collection.
      using base_type = xtd::collections::generic::list<xtd::ref<form>>;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Creates a new object xtd::forms::form_collection with specified allocator (optional).
      /// @remarks If allocator not specified, the std::allocator<value_type> is used.
      explicit form_collection() = default;
      /// @}
      
      /// @cond
      form_collection(form_collection&&) = default;
      form_collection(const form_collection& collection) = default;
      auto operator =(form_collection&& collection) -> form_collection& = default;
      auto operator =(const form_collection& collection) -> form_collection& = default;
      /// @endcond
      
      /// @name Operators
      
      /// @{
      using base_type::operator [];
      /// @brief Gets the first xtd::forms::form_collection in the list with the specified name.
      /// @param name The name of the xtd::forms::control to get from the list.
      /// @return The first xtd::forms::control in the list with the given Name. This item returns optional with no value if no xtd::forms::control with the given name can be found.
      /// @remarks The operator [] property is case-sensitive when searching for names. That is, if two controls exist with the names "Lname" and "lname", operator [] property will find only the xtd::forms::control with the xtd::forms::control::name() that you specify, not both.
      auto operator [](const xtd::string& name) const -> value_type {
        for (auto item : self_)
          if (item.get().name() == name) return item;
        return {};
      }
      /// @brief Gets the first xtd::forms::form_collection in the list with the specified name.
      /// @param name The name of the xtd::forms::control to get from the list.
      /// @return The first xtd::forms::control in the list with the given Name. This item returns optional with no value if no xtd::forms::control with the given name can be found.
      /// @remarks The operator [] property is case-sensitive when searching for names. That is, if two controls exist with the names "Lname" and "lname", operator [] property will find only the xtd::forms::control with the xtd::forms::control::name() that you specify, not both.
      auto operator [](const xtd::string& name) -> value_type {
        for (auto item : self_)
          if (item.get().name() == name) return item;
        return {};
      }
      /// @}
    };
  }
}
