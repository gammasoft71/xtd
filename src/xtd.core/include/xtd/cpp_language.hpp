/// @file
/// @brief Contains xtd::cpp_language class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "language_id.hpp"
#include "object.hpp"
#include "string.hpp"
#include "version.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents information about c++ libraries, such as the version and language identifier. This class cannot be inherited.
  /// @par Header
  /// ```cpp
  /// #include <xtd/cpp_language>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks The cpp_language class contains information about c++ libraries.
  /// @remarks For information about current c++ libraries, retrieve the cpp_language object returned by the xtd::environment::cpp_language_version method.
  /// @remarks By design, the xtd::cpp_language class is not a general purpose means of describing c++ language, and you cannot derive a more inclusive type from the xtd::cpp_language class. If you need a type to contain other information about C++ libraries, create your own type, then include a field of type cpp_language and any additional fields or methods that you require.
  /// @remarks For more info about c++ see [cppreference](https://en.cppreference.com/w/cpp).
  class cpp_language final : public object {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Initialize a new instance of xtd::cpp_language class.
    explicit cpp_language(int32 cpp) noexcept;
    /// @}
    
    /// @cond
    cpp_language() noexcept = default;
    cpp_language(const cpp_language&) noexcept = default;
    cpp_language& operator =(const cpp_language&) noexcept = default;
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets if is experimental language
    /// @return `true` if is experimental language; otherwise `false`.
    [[nodiscard]] auto is_experimental_language() const noexcept -> bool;
    
    /// @brief Gets if is supported by xtd.
    /// @return `true` is supported by xtd; otherwise `false`.
    [[nodiscard]] auto is_supported() const noexcept -> bool;
    
    /// @brief Gets lagnguage id.
    /// @return One of xtd::languade_id values.
    [[nodiscard]] auto language() const noexcept -> language_id;
    
    /// @brief Gets experimental language id.
    /// @return One of xtd::language_id values.
    /// @remarks If is not experimental, the xtd::language_id is the same as xtd::cpp_language::language property.
    [[nodiscard]] auto experimental_language() const noexcept -> language_id;
    
    /// @brief Gets the month when the cpp language was released.
    /// @return The month when the cpp version was released.
    [[nodiscard]] auto month() const noexcept -> int32;
    
    /// @brief Gets the offical name of the cpp language.
    /// @return The offical name of the cpp version.
    [[nodiscard]] auto name() const noexcept -> xtd::string;
    
    /// @brief Gets the value of cpp language.
    /// @return The value of cpp version.
    [[nodiscard]] auto value() const noexcept -> uint32;
    
    /// @brief Gets the version string of cpp language.
    /// @return The version string.
    [[nodiscard]] auto version_string() const noexcept -> xtd::string;
    
    /// @brief Gets The version of cpp language.
    /// @return The version.
    [[nodiscard]] auto version() const noexcept -> xtd::version;
    
    /// @brief Gets the year when the cpp language was released.
    /// @return The year when the cpp version was released.
    [[nodiscard]] auto year() const noexcept -> int32;
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Serves as a hash function for a particular type.
    /// @return A hash code for the current object.
    [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
    
    /// @brief Converts the value of this operating_system object to its equivalent string representation.
    /// @return The string representation of the values returned by the platform, version, and service_pack methods.
    [[nodiscard]] auto to_string() const noexcept -> xtd::string override;
    /// @}
    
  private:
    int32 cpp_ = 0;
  };
}
