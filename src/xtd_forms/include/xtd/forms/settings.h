#pragma once
#include <memory>
#include <xtd/xtd.strings>
#include "component.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
/// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
namespace forms {
/// @brief Represent settings associate to the application
/// @remarks On Windows settings are stored in registry with '"HKEY_CURRENT_USER\Software\Company Name\Product Name" key or if no Comapny name "\HKEY_CURRENT_USER\Software\Product Name\Product Name" key.
/// @remarks On macos settings are stored in '~/Library/Preferences/Product Name Preferences" file.
/// @remarks On linux settings are stored in '~/.Product Name" file.
class settings : public component {
public:
  settings();
  ~settings();
  
  std::string read(const std::string& key, const std::string& default_value) {return read_string(key, default_value);}
  void reset();
  void save();
  void write(const std::string& key, const std::string& value) {write_string(key, value);}
  
  template<typename type_t>
  type_t read(const std::string& key, const type_t& default_value) {
    return xtd::parse<type_t>(read_string(key, xtd::strings::format("{}", default_value)));
  }
  
  template<typename type_t>
  void write(const std::string& key, type_t&& value) {
    write_string(key, xtd::strings::format("{}", value));
  }
  
private:
  std::string read_string(const std::string& key, const std::string& default_value);
  void write_string(const std::string& key, const std::string& value);
  struct data {
    intptr_t settings_;
  };
  
  std::shared_ptr<data> data_ = std::make_shared<data>();
};
}
}
