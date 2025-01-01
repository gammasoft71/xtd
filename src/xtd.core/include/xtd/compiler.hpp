/// @file
/// @brief Contains xtd::compiler class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
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
    /// @param is_64_bit true if 64 bits; otherwise false.
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
    xtd::string additional_information() const noexcept;
    
    /// @brief Gets the build type.
    /// @return One of xtd::build_type values.
    xtd::build_type build_type() const noexcept;
    
    /// @brief Gets the compiler id.
    /// @return One of xtd::compiler_id values.
    xtd::compiler_id compiler_id() const noexcept;
    
    /// @brief Gets build type is debug.
    /// @return true if build type debug; otherwise false.
    bool is_build_type_debug() const noexcept;
    
    /// @brief Gets is 64 bits.
    /// @return true if 64 bits; otherwise false.
    bool is_64_bit() noexcept;
    
    /// @brief Gets compiler name.
    /// @return The compiler name.
    xtd::string name() const noexcept;
    
    /// @brief Gets compiler version string.
    /// @return The compiler version string.
    xtd::string version_string() const noexcept;
    
    /// @brief Gets compiler version.
    /// @return The compiler version.
    const xtd::version& version() const noexcept;
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Converts the value of this operating_system object to its equivalent string representation.
    /// @return The string representation of the values returned by the platform, version, and service_pack methods.
    xtd::string to_string() const noexcept override;
    /// @}
    
  private:
    xtd::string get_apple_clang_additional_information() const noexcept;
    xtd::string get_compiler_version_string(const xtd::string& compiler_name) const noexcept;
    xtd::string get_msvc_additional_information() const noexcept;
    
    xtd::compiler_id compiler_id_ = xtd::compiler_id::unknown;
    xtd::version version_;
    xtd::build_type build_type_ = xtd::build_type::debug;
    bool is_64_bit_ = false;
  };
}
