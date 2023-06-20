/// @file
/// @brief Contains xtd::toolkit class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "core_export.h"
#include "iequatable.h"
#include "object.h"
#include "ustring.h"
#include "version.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a toolkit.
  /// @par Namespace
  /// xtd::forms
  /// @par Library
  /// xtd.forms
  /// @ingroup xtd_forms
  class core_export_ toolkit : public object, public xtd::iequatable<toolkit> {
    struct data;
    
  public:
    /// @name Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::toolkit class.
    /// @remarks The xtd::toolkit class is used by xtd::system_information::toolkit_version method.
    toolkit() = default;
    /// @brief Initializes a new instance of the xtd::toolkit class with the specified name and version.
    /// @param name The toolkit name.
    /// @param version The toolkit version.
    /// @param description The toolkit description.
    toolkit(const xtd::ustring& name, const xtd::version& version, const xtd::ustring& description);
    /// @}
    
    /// @cond
    toolkit(const toolkit&) = default;
    toolkit(toolkit&&) = default;
    toolkit& operator =(const toolkit&) = default;
    /// @endcond
    
    /// @name Properties
    
    /// @{
    /// @brief Gets the toolkit description.
    /// @return The toolkit description.
    const xtd::ustring& description() const noexcept;
    
    /// @brief Gets the toolkit name.
    /// @return The toolkit name.
    const xtd::ustring& name() const noexcept;
    
    /// @brief Gets the toolkit version.
    /// @return The toolkit version.
    const xtd::version& version() const noexcept;
    /// @}
    
    /// @name Methods
    
    /// @{
    bool equals(const toolkit& other) const noexcept override;
    xtd::ustring to_string() const noexcept override;
    /// @}
    
  private:
    xtd::ustring description_ = "No toolkit defined.";
    xtd::ustring name_ = "Unknown";
    xtd::version version_;
  };
}

