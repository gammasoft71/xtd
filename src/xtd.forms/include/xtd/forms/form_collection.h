/// @file
/// @brief Contains xtd::forms::form_collection alias.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "form"
#include <functional>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a collection of form objects.
    /// @par Header
    /// @code #include <xtd/forms/form_collection> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks form_collection is used by the application object to list the currently open forms in an application through the open_forms property.
    using form_collection = std::vector<std::reference_wrapper<form>>;
  }
}
