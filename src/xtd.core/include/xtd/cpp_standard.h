#pragma once
#include <cstdint>
#include <map>
#include <vector>
#include "standard_id.h"
#include "version.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents information about c++ libraries, such as the version and standard identifier. This class cannot be inherited.
  /// @remarks The cpp_standard class contains information about c++ libraries.
  /// @remarks For information about current c++ libraries, retrieve the cpp_standard object returned by the xtd::environment::cpp_standard_version method.
  /// @remarks By design, the operating_system class is not a general purpose means of describing an operating system, and you cannot derive a more inclusive type from the operating_system class. If you need a type to contain other information about C++ libraries, create your own type, then include a field of typecpp_standard and any additional fields or methods that you require.
  class cpp_standard final {
  public:
    cpp_standard(uint32_t cpp) : cpp_(cpp) {}
  
    /// @cond
    cpp_standard() = default;
    cpp_standard(const cpp_standard&) = default;
    cpp_standard& operator=(const cpp_standard&) = default;
    friend std::ostream& operator <<(std::ostream& os, const cpp_standard& cpp_standard) noexcept {return os << cpp_standard.to_string();}
    /// @endcond
    
    bool is_supported() const noexcept {return cpp_ >= 201703L;}
    
    int32_t month() const noexcept {return cpp_ % 100;}
    
    standard_id standard() const noexcept {
      if (cpp_ >= 202002L) return standard_id::cpp20;
      if (cpp_ >= 201703L) return standard_id::cpp17;
      if (cpp_ >= 201402L) return standard_id::cpp14;
      if (cpp_ >= 201103L) return standard_id::cpp11;
      if (cpp_ >= 199711L) return standard_id::cpp98;
      if (cpp_ >= 1L) return standard_id::cpp_pre98;
      return standard_id::unknown;
    }
    
    std::string version_string() const noexcept {
      static std::map<standard_id, std::string> names {{standard_id::cpp_pre98, "Standard C++ Pre 98"}, {standard_id::cpp98, "Standard C++ 98"}, {standard_id::cpp11, "Standard C++ 11"}, {standard_id::cpp14, "Standard C++ 14"}, {standard_id::cpp17, "Standard C++ 17"}, {standard_id::cpp20, "Standard C++ 20"}, {standard_id::unknown, "<unknown>"}};
      return names[standard()];
    }
    
    const xtd::version& version() const noexcept {
      static xtd::version ver(cpp_/100, cpp_%100);
      return ver;
    }
    
    int32_t year() const noexcept {return cpp_ / 100;}
    
    /// @brief Converts the value of this operating_system object to its equivalent string representation.
    /// @return The string representation of the values returned by the platform, version, and service_pack methods.
    std::string to_string() const noexcept {return version_string();}

  private:
    uint32_t cpp_ = __cplusplus;
  };
}
