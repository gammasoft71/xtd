/// @file
/// @brief Contains xtd::toolkit class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "core_export.hpp"
#include "iequatable.hpp"
#include "object.hpp"
#include "string.hpp"
#include "version.hpp"

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
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::toolkit class.
    /// @remarks The xtd::toolkit class is used by xtd::system_information::toolkit_version method.
    toolkit() = default;
    /// @brief Initializes a new instance of the xtd::toolkit class with the specified name and version.
    /// @param name The toolkit name.
    /// @param version The toolkit version.
    /// @param description The toolkit description.
    toolkit(const xtd::string& name, const xtd::version& version, const xtd::string& description);
    /// @}
    
    /// @cond
    toolkit(const toolkit&) = default;
    toolkit(toolkit&&) = default;
    toolkit& operator =(const toolkit&) = default;
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets the toolkit description.
    /// @return The toolkit description.
    const xtd::string& description() const noexcept;
    
    /// @brief Gets the toolkit name.
    /// @return The toolkit name.
    const xtd::string& name() const noexcept;
    
    /// @brief Gets the toolkit version.
    /// @return The toolkit version.
    const xtd::version& version() const noexcept;
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    bool equals(const object& obj) const noexcept override;
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param other The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    bool equals(const toolkit& other) const noexcept override;
    
    /// @brief Serves as a hash function for a particular type.
    /// @return A hash code for the current object.
    xtd::size get_hash_code() const noexcept override;
    
    /// @brief Returns a xtd::string that represents the current object.
    /// @return A string that represents the current object.
    xtd::string to_string() const noexcept override;
    /// @}
    
  private:
    xtd::string description_ = "No toolkit defined.";
    xtd::string name_ = "Unknown";
    xtd::version version_;
  };
}

