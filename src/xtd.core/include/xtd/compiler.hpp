/// @file
/// @brief Contains xtd::compiler class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "build_type.hpp"
#include "compiler_id.hpp"
#include "object.hpp"
#include "string.hpp"
#include "version.hpp"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents information about c++ libraries, such as the version and standard identifier. This class cannot be inherited.
  /// @par Header
  /// ```cpp
  /// #include <xtd/compiler>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks The compiler class contains information about c++ libraries.
  /// @remarks For information about current c++ libraries, retrieve the compiler object returned by the xtd::environment::compiler_version method.
  /// @remarks By design, the operating_system class is not a general purpose means of describing an operating system, and you cannot derive a more inclusive type from the operating_system class. If you need a type to contain other information about C++ libraries, create your own type, then include a field of compiler type and any additional fields or methods that you require.
  class compiler final : public object {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Initialise a new xtd::compiler class.
    /// @param compiler_id One of xtd::compiler_id values.
    /// @param version The compiler version.
    /// @param build_type One of xtd::build_type values.
    /// @param is_64_bit `true` if 64 bits; otherwise `false`.
    compiler(xtd::compiler_id compiler_id, const xtd::version& version, xtd::build_type build_type, bool is_64_bit);
    /// @}
    
    /// @cond
    compiler() = default;
    compiler(const compiler&) = default;
    compiler& operator =(const compiler&) = default;
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets additional information.
    /// @return Additional information.
    [[nodiscard]] auto additional_information() const noexcept -> xtd::string;
    
    /// @brief Gets the build type.
    /// @return One of xtd::build_type values.
    [[nodiscard]] auto build_type() const noexcept -> xtd::build_type;
    
    /// @brief Gets the compiler id.
    /// @return One of xtd::compiler_id values.
    [[nodiscard]] auto compiler_id() const noexcept -> xtd::compiler_id;
    
    /// @brief Gets build type is debug.
    /// @return `true` if build type debug; otherwise `false`.
    [[nodiscard]] auto is_build_type_debug() const noexcept -> bool;
    
    /// @brief Gets is 64 bits.
    /// @return `true` if 64 bits; otherwise `false`.
    [[nodiscard]] auto is_64_bit() noexcept -> bool;
    
    /// @brief Gets compiler name.
    /// @return The compiler name.
    [[nodiscard]] auto name() const noexcept -> xtd::string;
    
    /// @brief Gets compiler version string.
    /// @return The compiler version string.
    [[nodiscard]] auto version_string() const noexcept -> xtd::string;
    
    /// @brief Gets compiler version.
    /// @return The compiler version.
    [[nodiscard]] auto version() const noexcept -> const xtd::version&;
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Serves as a hash function for a particular type.
    /// @return A hash code for the current object.
    [[nodiscard]] auto get_hash_code() const noexcept -> xtd::size override;
    
    /// @brief Converts the value of this operating_system object to its equivalent string representation.
    /// @return The string representation of the values returned by the platform, version, and service_pack methods.
    [[nodiscard]] auto to_string() const noexcept -> xtd::string override;
    /// @}
    
  private:
    [[nodiscard]] auto get_apple_clang_additional_information() const noexcept -> xtd::string;
    [[nodiscard]] auto get_compiler_version_string(const xtd::string& compiler_name) const noexcept -> xtd::string;
    [[nodiscard]] auto get_msvc_additional_information() const noexcept -> xtd::string;
    
    xtd::compiler_id compiler_id_ = xtd::compiler_id::unknown;
    xtd::version version_;
    xtd::build_type build_type_ = xtd::build_type::debug;
    bool is_64_bit_ = false;
  };
}
