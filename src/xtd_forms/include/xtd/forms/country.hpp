#pragma once
#include <string>
#include <xtd/static.hpp>
#include <xtd/drawing/bitmap.hpp>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class countries;
    /// @endcond

    class country {
    public:
      country() = default;
      
      static const country empty();
      
      const std::string name() const {return name_;}
      const std::string alpha_2_code() const {return alpha_2_code_;}
      const std::string alpha_3_code() const {return alpha_3_code_;}
      const int numeric_code() const {return numeric_code_;}
      const std::string text_flag() const {return text_flag_;}
      const xtd::drawing::image flag() const {return flag_;}
      
      static country from_name(const std::string& name);
      static country from_alpha_2_code(const std::string& alpha_2_code);
      static country from_alpha_3_code(const std::string& alpha_3_code);
      static country from_numeric_code(int numeric_code);
      
    private:
      friend class countries;
      
      static const std::vector<std::string> enclosed_letters;
      country(const std::string& name, const std::string& alpha_2_code, const std::string& alpha_3_code, int numeric_code) : name_(name), alpha_2_code_(alpha_2_code), alpha_3_code_(alpha_3_code), numeric_code_(numeric_code), text_flag_(enclosed_letters[alpha_2_code[0] - 'A'] + enclosed_letters[alpha_2_code[1] - 'A']) {}
      country(const std::string& name, const std::string& alpha_2_code, const std::string& alpha_3_code, int numeric_code, xtd::drawing::image& flag) : name_(name), alpha_2_code_(alpha_2_code), alpha_3_code_(alpha_3_code), numeric_code_(numeric_code), text_flag_(enclosed_letters[alpha_2_code[0] - 'A'] + enclosed_letters[alpha_2_code[1] - 'A']), flag_(flag) {}
      
      std::string name_;
      std::string alpha_2_code_;
      std::string alpha_3_code_;
      int numeric_code_;
      std::string text_flag_;
      xtd::drawing::image flag_  = xtd::drawing::bitmap(256, 256);
    };
  }
}
