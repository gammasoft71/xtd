/// @file
/// @brief Contains xtd::cpp_language class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <map>
#include <vector>
#include "language_id.h"
#include "object.h"
#include "ustring.h"
#include "version.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents information about c++ libraries, such as the version and language identifier. This class cannot be inherited.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks The cpp_language class contains information about c++ libraries.
  /// @remarks For information about current c++ libraries, retrieve the cpp_language object returned by the xtd::environment::cpp_language_version method.
  /// @remarks By design, the operating_system class is not a general purpose means of describing an operating system, and you cannot derive a more inclusive type from the operating_system class. If you need a type to contain other information about C++ libraries, create your own type, then include a field of type cpp_language and any additional fields or methods that you require.
  class cpp_language final : public object {
  public:
    /// @name Constructors
    
    /// @{
    /// @brief Initialize a new instance of xtd::cpp_language class.
    explicit cpp_language(uint32_t cpp) noexcept : cpp_(cpp) {}
    /// @}
    
    /// @cond
    cpp_language() noexcept = default;
    cpp_language(const cpp_language&) noexcept = default;
    cpp_language& operator =(const cpp_language&) noexcept = default;
    friend std::ostream& operator <<(std::ostream& os, const cpp_language& cpp_language) noexcept {return os << cpp_language.to_string();}
    /// @endcond
    
    /// @name Properties
    
    /// @{
    /// @brief Gets if is experimental language
    /// @return true if is experimental language; otherwise false.
    bool is_experimental_language() const noexcept {return language() != experimental_language();}
    
    /// @brief Gets if is supported by xtd.
    /// @return true is supported by xtd; otherwise false.
    bool is_supported() const noexcept {return cpp_ >= 201703L;}
    
    /// @brief Gets lagnguage id.
    /// @return One of xtd::languade_id values.
    language_id language() const noexcept {
      if (cpp_ >= 202002L) return language_id::cpp20;
      if (cpp_ >= 201703L) return language_id::cpp17;
      if (cpp_ >= 201402L) return language_id::cpp14;
      if (cpp_ >= 201103L) return language_id::cpp11;
      if (cpp_ >= 199711L) return language_id::cpp98;
      if (cpp_ >= 1L) return language_id::cpp_pre98;
      return language_id::unknown;
    }
    
    /// @brief Gets experimental language id.
    /// @return One of xtd::language_id values.
    /// @Remarks If is not experimental, the xtd::language_id is the same as xtd::cpp_language::language property.
    language_id experimental_language() const noexcept {
      if (cpp_ >= 201707L) return language_id::cpp20;
      if (cpp_ >= 201411L) return language_id::cpp17;
      if (cpp_ >= 201210L) return language_id::cpp14;
      if (cpp_ >= 200410L) return language_id::cpp11;
      if (cpp_ >= 199711L) return language_id::cpp98;
      if (cpp_ >= 1L) return language_id::cpp_pre98;
      return language_id::unknown;
    }
    
    /// @brief Gets the month when the cpp language was released.
    /// @return The month when the cpp version was released.
    int32_t month() const noexcept {return cpp_ % 100;}
    
    /// @brief Gets the offical name of the cpp language.
    /// @return The offical name of the cpp version.
    xtd::ustring name() const noexcept {
      static std::map<language_id, xtd::ustring> names {{language_id::cpp_pre98, "C++ Pre 98"}, {language_id::cpp98, "C++ 98"}, {language_id::cpp11, "C++ 11"}, {language_id::cpp14, "C++ 14"}, {language_id::cpp17, "C++ 17"}, {language_id::cpp20, "C++ 20"}, {language_id::unknown, "<unknown>"}};
      if (is_experimental_language()) return ustring::format("Experimental {}", names[experimental_language()]);
      return names[language()];
    }
    
    /// @brief Gets the value of cpp language.
    /// @return The value of cpp version.
    uint32_t value() const noexcept {return cpp_;}
    
    /// @brief Gets the version string of cpp language.
    /// @return The version string.
    xtd::ustring version_string() const noexcept {
      return ustring::format("{} {}", name(), version());
    }
    
    /// @brief Gets The version of cpp language.
    /// @return The version.
    const xtd::version& version() const noexcept {
      static xtd::version ver(cpp_ / 100, cpp_ % 100);
      return ver;
    }
    
    /// @brief Gets the year when the cpp language was released.
    /// @return The year when the cpp version was released.
    int32_t year() const noexcept {return cpp_ / 100;}
    /// @}
    
    /// @name Methods
    
    /// @{
    /// @brief Converts the value of this operating_system object to its equivalent string representation.
    /// @return The string representation of the values returned by the platform, version, and service_pack methods.
    xtd::ustring to_string() const noexcept override {return version_string();}
    /// @}
    
  private:
    uint32_t cpp_ = __cplusplus;
  };
}
