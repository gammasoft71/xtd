/// @file
/// @brief Contains xtd::distribution class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "optional.hpp"
#include "object.hpp"
#include "platform_id.hpp"
#include "uri.hpp"
#include "string.hpp"
#include "version.hpp"
#include <map>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents information about an operating system distribution, such as the version and name. This class cannot be inherited.
  /// @par Header
  /// ```cpp
  /// #include <xtd/distribution>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks The distribution class contains information about an operating system distribution.
  /// @remarks For information about the current runtime operating system, retrieve the distribution object returned by the xtd::environment::os_version method.
  /// @remarks By design, the distribution class is not a general purpose means of describing an operating system distribution, and you cannot derive a more inclusive type from the distribution class. If you need a type to contain other information about an operating system distribution, create your own type, then include a field of type distribution and any additional fields or methods that you require.
  class distribution final : public object {
  public:
    using id_collection = xtd::array<xtd::string>;
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of the distribution class, using the specified name, version, code name, decription, identifier, like identifiers array, version string, home url and bug repport url.
    /// @param name The operating system distribution name.
    /// @param version A Version object that indicates the version of the operating system distribution.
    /// @param code_name The operating system distribution code name.
    /// @param description The operating system distribution description.
    /// @param id The operating system distribution identifier.
    /// @param like_ids The operating system distribution like identifiers array.
    /// @param version_string The operating system distribution version string.
    /// @param home The operating system distribution home url.
    /// @param bug_repport The operating system distribution bug report url.
    distribution(const xtd::string& name, const xtd::version& version, const xtd::string& code_name, const xtd::string& description, const xtd::string& id, const id_collection& like_ids, const xtd::string& version_string, const xtd::uri& home, const xtd::uri& bug_repport);
    /// @}
    
    /// @cond
    distribution() = default;
    distribution(const distribution&) = default;
    distribution& operator =(const distribution&) = default;
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets operating system distribution bug repport url.
    /// @return The operating system distribution bug repport url.
    const xtd::uri& bug_repport() const noexcept;
    
    /// @brief Gets operating system distribution code name. For example "jammy" is the code name of Ubuntu 22.04.
    /// @return The operating system distribution code name.
    const xtd::string& code_name() const noexcept;
    
    /// @brief Gets operating system distribution description. For example "Ubuntu 22.04.2 LTS".
    /// @return The operating system distribution description.
    const xtd::string& description() const noexcept;
    
    /// @brief Gets operating system distribution home url.
    /// @return The operating system distribution home url.
    const xtd::uri& home() const noexcept;
    
    /// @brief Gets operating system distribution identifier.
    /// @return The operating system distribution identifier.
    const xtd::string& id() const noexcept;
    
    /// @brief Gets operating system distribution like identifiers array.
    /// @return The operating system distribution like identifiers array.
    const id_collection& like_ids() const noexcept;
    
    /// @brief Gets operating system distribution name. For example "Ubuntu".
    /// @return The operating system distribution name.
    const xtd::string& name() const noexcept;
    
    /// @brief Gets a xtd::version object that identifies the operating system distribution. For example xtd::version(22, 4).
    /// @return Version A Version object that describes the major version, minor version, build, and revision numbers for the operating system distribution.
    const xtd::version& version() const noexcept;
    
    /// @brief Gets operating system distribution version string.
    /// @return The operating system distribution version string.
    const xtd::string& version_string() const noexcept;
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Serves as a hash function for a particular type.
    /// @return A hash code for the current object.
    xtd::size get_hash_code() const noexcept override;
    
    /// @brief Converts the value of this distribution object to its equivalent string representation.
    /// @return The string representation of the value returned by the description property.
    xtd::string to_string() const noexcept override;
    /// @}
    
  private:
    xtd::string name_;
    xtd::version version_;
    xtd::string code_name_;
    xtd::string description_;
    xtd::string id_;
    id_collection like_ids_;
    xtd::string version_string_;
    xtd::uri home_;
    xtd::uri bug_repport_;
  };
}
