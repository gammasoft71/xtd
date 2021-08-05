/// @file
/// @brief Contains xtd::version class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <string>
#include <sstream>
#include <regex>
#include <vector>
#include "collections/specialized/string_vector.h"
#include "argument_exception.h"
#include "format_exception.h"
#include "object.h"
#include "ustring.h"

/// @cond
#undef major
#undef minor
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the version number of an assembly, operating system, or the common language runtime. This class cannot be inherited.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  class version final : public object {
  public:
    version() noexcept = default;
    version(int major, int minor) noexcept : major_(major), minor_(minor) {}
    version(int major, int minor, int build) noexcept : major_(major), minor_(minor), build_(build) {}
    version(int major, int minor, int build, int revision) noexcept : major_(major), minor_(minor), build_(build), revision_(revision) {}
    
    /// @cond
    version(const version&) noexcept = default;
    version& operator=(const version&) noexcept = default;
    
    bool operator==(const version& v) const noexcept {return major_ == v.major_ && minor_ == v.minor_ && build_ == v.build_ && revision_ == v.revision_;}
    bool operator!=(const version& v) const noexcept {return !operator==(v);}
    friend std::ostream& operator <<(std::ostream& os, const version& ver) noexcept {return os << ver.to_string();}
    /// @endcond

    int build() const noexcept {return build_;}
    
    int major() const noexcept {return major_;}
    
    int16_t major_revision() const noexcept {return (int16_t)((revision_ & 0xFFFF0000) >> 16);}
    
    int minor() const noexcept {return minor_;}
    
    int16_t mainor_revision() const noexcept {return (int16_t)(revision_ & 0x0000FFFF);}
    
    int revision() const noexcept {return revision_;}
    
    static version parse(const xtd::ustring& ver) {
      std::regex rgx("\\.");
      xtd::collections::specialized::string_vector versions;
      for (std::sregex_token_iterator it(ver.begin(), ver.end(), rgx, -1), end; it != end; ++it)
        versions.push_back(it->str());
      
      switch (versions.size()) {
        case 2: return version(std::stoi(versions[0]), std::stoi(versions[1]));
        case 3: return version(std::stoi(versions[0]), std::stoi(versions[1]), std::stoi(versions[2]));
        case 4: return version(std::stoi(versions[0]), std::stoi(versions[1]), std::stoi(versions[2]), std::stoi(versions[3]));
      }
      throw xtd::format_exception(current_stack_frame_);
    }
    
    static bool try_parse(const xtd::ustring& ver, version& result) noexcept {
      try {
        result = parse(ver);
        return true;
      } catch (...) {
        return false;
      }
    }
    
    xtd::ustring to_string() const noexcept {return to_string(2 + (build_ != -1 ? 1 : 0) + (revision_ != -1 ? 1 : 0));}
    
    xtd::ustring to_string(size_t field_count) const {
      if (field_count > 4 || (field_count >= 3 && build_ == -1) || (field_count == 4 && revision_ == -1))
        throw xtd::argument_exception("Field count invalid"_t, current_stack_frame_);
      std::stringstream result;
      if (field_count >= 1)
        result << std::to_string(major_);
      if (field_count >= 2)
        result << "." << std::to_string(minor_);
      if (field_count >= 3)
        result << "." << std::to_string(build_);
      if (field_count == 4)
        result << "." << std::to_string(revision_);
      return result.str();
    }
    
  private:
    int major_ = 0;
    int minor_ = 0;
    int build_ = -1;
    int revision_ = -1;
  };
}
