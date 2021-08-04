/// @file
/// @brief Contains xtd::cpp_language class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
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
  /// @brief Represents information about c++ libraries, such as the version and langauge identifier. This class cannot be inherited.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks The cpp_language class contains information about c++ libraries.
  /// @remarks For information about current c++ libraries, retrieve the cpp_language object returned by the xtd::environment::cpp_language_version method.
  /// @remarks By design, the operating_system class is not a general purpose means of describing an operating system, and you cannot derive a more inclusive type from the operating_system class. If you need a type to contain other information about C++ libraries, create your own type, then include a field of typecpp_language and any additional fields or methods that you require.
  class cpp_language final : public object {
  public:
    cpp_language(uint32_t cpp) : cpp_(cpp) {}
  
    /// @cond
    cpp_language() = default;
    cpp_language(const cpp_language&) = default;
    cpp_language& operator=(const cpp_language&) = default;
    friend std::ostream& operator <<(std::ostream& os, const cpp_language& cpp_language) noexcept {return os << cpp_language.to_string();}
    /// @endcond
    
    bool is_experimental_language() const noexcept {return language() != experimental_language();}

    bool is_supported() const noexcept {return cpp_ >= 201703L;}
    
    language_id language() const noexcept {
      if (cpp_ >= 202002L) return language_id::cpp20;
      if (cpp_ >= 201703L) return language_id::cpp17;
      if (cpp_ >= 201402L) return language_id::cpp14;
      if (cpp_ >= 201103L) return language_id::cpp11;
      if (cpp_ >= 199711L) return language_id::cpp98;
      if (cpp_ >= 1L) return language_id::cpp_pre98;
      return language_id::unknown;
    }
    
    language_id experimental_language() const noexcept {
      if (cpp_ >= 201707L) return language_id::cpp20;
      if (cpp_ >= 201411L) return language_id::cpp17;
      if (cpp_ >= 201210L) return language_id::cpp14;
      if (cpp_ >= 200410L) return language_id::cpp11;
      if (cpp_ >= 199711L) return language_id::cpp98;
      if (cpp_ >= 1L) return language_id::cpp_pre98;
      return language_id::unknown;
    }
    
    int32_t month() const noexcept {return cpp_ % 100;}

    std::string name() const noexcept {
      static std::map<language_id, std::string> names {{language_id::cpp_pre98, "C++ Pre 98"}, {language_id::cpp98, "C++ 98"}, {language_id::cpp11, "C++ 11"}, {language_id::cpp14, "C++ 14"}, {language_id::cpp17, "C++ 17"}, {language_id::cpp20, "C++ 20"}, {language_id::unknown, "<unknown>"}};
      if (is_experimental_language()) return strings::format("Experimental {}", names[experimental_language()]);
      return names[language()];
    }
    
    uint32_t value() const noexcept {return cpp_;}

    std::string version_string() const noexcept {
      return strings::format("{} {}", name(), version());
    }
    
    const xtd::version& version() const noexcept {
      static xtd::version ver(cpp_/100, cpp_%100);
      return ver;
    }
    
    int32_t year() const noexcept {return cpp_ / 100;}
    
    /// @brief Converts the value of this operating_system object to its equivalent string representation.
    /// @return The string representation of the values returned by the platform, version, and service_pack methods.
    xtd::ustring to_string() const noexcept {return version_string();}

  private:
    uint32_t cpp_ = __cplusplus;
  };
}
