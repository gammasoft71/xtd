/// @file
/// @brief Contains xtd::distribution class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <map>
#include <optional>
#include <vector>
#include "object.h"
#include "platform_id.h"
#include "ustring.h"
#include "version.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents information about an operating system distribution, such as the version and name. This class cannot be inherited.
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
    /// @name Constructors
    
    /// @{
    /// @brief Initializes a new instance of the distribution class, using the specified name.
    /// @param name The operating system distribution name.
    explicit distribution(const xtd::ustring& name);
    /// @brief Initializes a new instance of the distribution class, using the specified name, and version.
    /// @param name The operating system distribution name.
    /// @param version A Version object that indicates the version of the operating system distribution.
    distribution(const xtd::ustring& name, const xtd::version& version);
    /// @brief Initializes a new instance of the distribution class, using the specified name, version, and code name.
    /// @param name The operating system distribution name.
    /// @param version A Version object that indicates the version of the operating system distribution.
    /// @param code_name The operating system distribution code name.
    distribution(const xtd::ustring& name, const xtd::version& version, const xtd::ustring& code_name);
    /// @brief Initializes a new instance of the distribution class, using the specified name, version, code name, and decription.
    /// @param name The operating system distribution name.
    /// @param version A Version object that indicates the version of the operating system distribution.
    /// @param code_name The operating system distribution code name.
    /// @param description The operating system distribution description.
    distribution(const xtd::ustring& name, const xtd::version& version, const xtd::ustring& code_name, const xtd::ustring& description);
    /// @}
    
    /// @cond
    distribution() = default;
    distribution(const distribution&) = default;
    distribution& operator =(const distribution&) = default;
    /// @endcond
    
    /// @name Properties
    
    /// @{
    /// @brief Gets operating system distribution code name. For example "jammy".
    /// @return The operating system distribution code name.
    xtd::ustring code_name() const noexcept;
    
    /// @brief Gets operating system distribution description. For example "Ubuntu 22.04.2 LTS".
    /// @return The operating system distribution description.
    xtd::ustring description() const noexcept;
    
    /// @brief Gets operating system distribution name. For example "Ubuntu".
    /// @return The operating system distribution name.
    xtd::ustring name() const noexcept;
    
    /// @brief Gets a xtd::version object that identifies the operating system distribution. For example xtd::version(22, 4).
    /// @return Version A Version object that describes the major version, minor version, build, and revision numbers for the operating system distribution.
    const xtd::version& version() const noexcept;
    /// @}
    
    /// @name Methods
    
    /// @{
    /// @brief Converts the value of this distribution object to its equivalent string representation.
    /// @return The string representation of the value returned by the description property.
    xtd::ustring to_string() const noexcept override;
    /// @}
    
  private:
    xtd::ustring name_;
    xtd::version version_;
    xtd::ustring code_name_;
    xtd::ustring description_;
  };
}
