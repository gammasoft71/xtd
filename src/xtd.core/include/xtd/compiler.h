/// @file
/// @brief Contains xtd::compiler class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <vector>
#include "build_type.h"
#include "compiler_id.h"
#include "object.h"
#include "ustring.h"
#include "version.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents information about c++ libraries, such as the version and standard identifier. This class cannot be inherited.
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
    /// @name Constructors
    
    /// @{
    /// @brief Initialise a new xtd::compiler class.
    /// @param compiler_id One of xtd::compiler_id values.
    explicit compiler(xtd::compiler_id compiler_id);
    /// @}
    
    /// @cond
    compiler() = default;
    compiler(const compiler&) = default;
    compiler& operator =(const compiler&) = default;
    /// @endcond
    
    /// @name Properties
    
    /// @{
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
    static bool is_64_bit() noexcept;
    
    /// @brief Gets compiler name.
    /// @return The compiler name.
    xtd::ustring name() const noexcept;
    
    /// @brief Gets compiler version string.
    /// @return The compiler version string.
    xtd::ustring version_string() const noexcept;
    
    /// @brief Gets compiler version.
    /// @return The compiler version.
    const xtd::version& version() const noexcept;
    /// @}
    
    /// @name Methods
    
    /// @{
    /// @brief Converts the value of this operating_system object to its equivalent string representation.
    /// @return The string representation of the values returned by the platform, version, and service_pack methods.
    xtd::ustring to_string() const noexcept override;
    /// @}
    
  private:
    #if defined(_MSC_VER)
    xtd::compiler_id compiler_id_ = xtd::compiler_id::microsoft_visual_studio;
    #elif defined(__clang__)
    xtd::compiler_id compiler_id_ = xtd::compiler_id::clang;
    #elif defined(__GNUC__)
    xtd::compiler_id compiler_id_ = xtd::compiler_id::gcc;
    #else
    xtd::compiler_id compiler_id_ = xtd::compiler_id::unknown;
    #endif
    #if defined(_MSC_VER)
    xtd::version version_ {_MSC_VER / 100, _MSC_VER % 100, 0};
    #elif defined(__clang__)
    xtd::version version_ {__clang_major__, __clang_minor__, __clang_patchlevel__};
    #elif defined(__GNUC__)
    xtd::version version_ {__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__};
    #else
    xtd::version version_;
    #endif
    #if defined(NDEBUG)
    xtd::build_type build_type_ = xtd::build_type::release;
    #else
    xtd::build_type build_type_ = xtd::build_type::debug;
    #endif
  };
}
