#pragma once
#include <string>
#include <sstream>
#include <regex>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  class version final {
  public:
    version() noexcept = default;
    version(int major, int minor) noexcept : major_(major), minor_(minor) {}
    version(int major, int minor, int build) noexcept : major_(major), minor_(minor), build_(build) {}
    version(int major, int minor, int build, int revision) noexcept : major_(major), minor_(minor), build_(build), revision_(revision) {}
    
    /// @cond
    version(const version&) noexcept = default;
    version& operator=(const version&) noexcept = default;
    
    bool operator==(const version& v) const noexcept {return this->major_ == v.major_ && this->minor_ == v.minor_ && this->build_ == v.build_ && this->revision_ == v.revision_;}
    bool operator!=(const version& v) const noexcept {return !this->operator==(v);}
    friend std::ostream& operator <<(std::ostream& os, const version& ver) noexcept {return os << ver.to_string();}
    /// @endcond

    int build() const noexcept {return this->build_;}
    
    int major() const noexcept {return this->major_;}
    
    int16_t major_revision() const noexcept {return (int16_t)((this->revision_ & 0xFFFF0000) >> 16);}
    
    int minor() const noexcept {return this->minor_;}
    
    int16_t mainor_revision() const noexcept {return (int16_t)(this->revision_ & 0x0000FFFF);}
    
    int revision() const noexcept {return this->revision_;}
    
    static version parse(const std::string& ver) {
      std::regex rgx("\\.");
      std::vector<std::string> versions;
      for (std::sregex_token_iterator it(ver.begin(), ver.end(), rgx, -1), end; it != end; ++it)
        versions.push_back(*it);
      
      switch (versions.size()) {
        case 2: return version(std::stoi(versions[0]), std::stoi(versions[1]));
        case 3: return version(std::stoi(versions[0]), std::stoi(versions[1]), std::stoi(versions[2]));
        case 4: return version(std::stoi(versions[0]), std::stoi(versions[1]), std::stoi(versions[2]), std::stoi(versions[3]));
      }
      throw std::invalid_argument("bad format");
    }
    
    static bool try_parse(const std::string& ver, version& result) noexcept {
      try {
        result = parse(ver);
        return true;
      } catch (...) {
        return false;
      }
    }
    
    std::string to_string() const noexcept {return this->to_string(2 + (this->build_ != -1 ? 1 : 0) + (this->revision_ != -1 ? 1 : 0));}
    
    std::string to_string(size_t field_count) const {
      if (field_count > 4 || (field_count >= 3 && this->build_ == -1) || (field_count == 4 && this->revision_ == -1))
        throw std::invalid_argument("field_count invalid");
      std::stringstream result;
      if (field_count >= 1)
        result << std::to_string(this->major_);
      if (field_count >= 2)
        result << "." << std::to_string(this->minor_);
      if (field_count >= 3)
        result << "." << std::to_string(this->build_);
      if (field_count == 4)
        result << "." << std::to_string(this->revision_);
      return result.str();
    }
    
  private:
    int major_ = 0;
    int minor_ = 0;
    int build_ = -1;
    int revision_ = -1;
  };
}
