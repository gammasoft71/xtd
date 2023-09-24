/// @file
/// @brief Contains xtd::cpp_language class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "language_id"
#include "object"
#include "ustring"
#include "version"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents information about c++ libraries, such as the version and language identifier. This class cannot be inherited.
  /// @par Header
  /// @code #include <xtd/cpp_language> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks The cpp_language class contains information about c++ libraries.
  /// @remarks For information about current c++ libraries, retrieve the cpp_language object returned by the xtd::environment::cpp_language_version method.
  /// @remarks By design, the xtd::cpp_language class is not a general purpose means of describing c++ language, and you cannot derive a more inclusive type from the xtd::cpp_language class. If you need a type to contain other information about C++ libraries, create your own type, then include a field of type cpp_language and any additional fields or methods that you require.
  /// @remarks For more info about c++ see <a href="https://en.cppreference.com/w/cpp">cppreference</a>.
  class cpp_language final : public object {
  public:
    /// @name Constructors
    
    /// @{
    /// @brief Initialize a new instance of xtd::cpp_language class.
    explicit cpp_language(uint32 cpp) noexcept;
    /// @}
    
    /// @cond
    cpp_language() noexcept = default;
    cpp_language(const cpp_language&) noexcept = default;
    cpp_language& operator =(const cpp_language&) noexcept = default;
    /// @endcond
    
    /// @name Properties
    
    /// @{
    /// @brief Gets if is experimental language
    /// @return true if is experimental language; otherwise false.
    bool is_experimental_language() const noexcept;
    
    /// @brief Gets if is supported by xtd.
    /// @return true is supported by xtd; otherwise false.
    bool is_supported() const noexcept;
    
    /// @brief Gets lagnguage id.
    /// @return One of xtd::languade_id values.
    language_id language() const noexcept;
    
    /// @brief Gets experimental language id.
    /// @return One of xtd::language_id values.
    /// @Remarks If is not experimental, the xtd::language_id is the same as xtd::cpp_language::language property.
    language_id experimental_language() const noexcept;
    
    /// @brief Gets the month when the cpp language was released.
    /// @return The month when the cpp version was released.
    int32 month() const noexcept;
    
    /// @brief Gets the offical name of the cpp language.
    /// @return The offical name of the cpp version.
    xtd::ustring name() const noexcept;
    
    /// @brief Gets the value of cpp language.
    /// @return The value of cpp version.
    uint32 value() const noexcept;
    
    /// @brief Gets the version string of cpp language.
    /// @return The version string.
    xtd::ustring version_string() const noexcept;
    
    /// @brief Gets The version of cpp language.
    /// @return The version.
    xtd::version version() const noexcept;
    
    /// @brief Gets the year when the cpp language was released.
    /// @return The year when the cpp version was released.
    int32 year() const noexcept;
    /// @}
    
    /// @name Methods
    
    /// @{
    /// @brief Converts the value of this operating_system object to its equivalent string representation.
    /// @return The string representation of the values returned by the platform, version, and service_pack methods.
    xtd::ustring to_string() const noexcept override;
    /// @}
    
  private:
    uint32 cpp_ = 0;
  };
}
