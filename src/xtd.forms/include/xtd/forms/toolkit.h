/// @file
/// @brief Contains xtd::forms::toolkit class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <any>
#include <tuple>
#include <xtd/iequatable.h>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include <xtd/version.h>
#include "../forms_export.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a toolkit.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class forms_export_ toolkit : public object, public xtd::iequatable<toolkit> {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::toolkit class.
      /// @remarks The xtd::forms::toolkit class is used by xtd::forms::system_information::toolkit_version method.
      toolkit() = default;
      /// @brief Initializes a new instance of the xtd::forms::toolkit class with the specified name and version.
      /// @param name The toolkit name.
      /// @param version The toolkit version.
      toolkit(const xtd::ustring& name, const xtd::version& version);
      /// @}
      
      /// @cond
      toolkit(const toolkit&) = default;
      toolkit(toolkit&&) = default;
      toolkit& operator =(const toolkit&) = default;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the toolkit name.
      /// @return The toolkit name.
      const xtd::ustring& name() const noexcept;
      /// @brief Sets the toolkit name.
      /// @param value The toolkit name.
      /// @return The current instance of xtd::forms::toolkit.
      toolkit& name(const xtd::ustring& value);

      /// @brief Gets the toolkit version.
      /// @return The toolkit version.
      const xtd::version& version() const noexcept;
      
      /// @brief Sets the toolkit version.
      /// @param value The toolkit version.
      /// @return The current instance of xtd::forms::toolkit.
      toolkit& version(const xtd::version& value);
      /// @}
      
      /// @name Methods
      
      /// @{
      bool equals(const toolkit& other) const noexcept override;
      xtd::ustring to_string() const noexcept override;
      /// @}
      
    private:
      xtd::ustring name_;
      xtd::version version_;
    };
  }
}

