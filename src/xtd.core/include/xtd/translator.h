#pragma once
#include <filesystem>
#include <string>
#include <vector>
#include "static.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  class translator final static_ {
  public:
    static std::string language();
    static void language(const std::string& language);
    
    static std::vector<std::string> languages();

    static void parse_locale(const std::filesystem::path& locale_path);
    static void parse_locale(const std::string& locale_path) {parse_locale(std::filesystem::path(locale_path));}
    /// @cond
    static void parse_locale(const char* locale_path) {parse_locale(std::filesystem::path(locale_path));}
    /// @endcond

    static std::string translate(const std::string& value) {return translate(language(), value);}
    static std::string translate(const std::string& language, const std::string& value);
    static const char* translate(const char* value) {return translate(language(), value);}
    static const char* translate(const std::string& language, const char* value);

  private:
    static void initialize();
  };
}
