/// @file
/// @brief Contains xtd::forms::country component.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "component.h"
#include <xtd/strings.h>
#include <xtd/static.h>
#include <xtd/drawing/bitmap.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class countries;
    /// @endcond

    /// @brief Represent a coountry with name, codes nd flag.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    class forms_export_ country : component {
    public:
      /// @cond
      country() = default;
      bool operator==(const country& value) const {return name_ == value.name_ && alpha_2_code_ == value.alpha_2_code_ && alpha_3_code_ == value.alpha_3_code_ && numeric_code_ == value.numeric_code_;}
      bool operator!=(const country& value) const {return !operator==(value);}
      /// @endcond
      
      /// @brief Get an empty country.
      /// @return An empty country
      static const country empty();

      /// @brief Gets the country 2 alpha codde.
      /// @return A string that represent the 2 alpha code.
      virtual const std::string alpha_2_code() const {return alpha_2_code_;}

      /// @brief Gets the country 3 alpha codde.
      /// @return A string that represent the 3 alpha code.
      virtual const std::string alpha_3_code() const {return alpha_3_code_;}

      virtual const std::string emoticon() const {return emoticon_;}
      
      virtual const xtd::drawing::image flag() const;
      
      virtual const xtd::drawing::image flag_squared() const;

      /// @brief Gets the country name.
      /// @return A string that represent the country.
      virtual const std::string name() const {return name_;}

      /// @brief Gets the country numeric code.
      /// @return A signed-integer that represent the numerci codde.
      virtual int numeric_code() const {return numeric_code_;}

      static country from_name(const std::string& name);
      static country from_alpha_2_code(const std::string& alpha_2_code);
      static country from_alpha_3_code(const std::string& alpha_3_code);
      static country from_numeric_code(int numeric_code);

      virtual std::string to_string() const;
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::forms::country& country) noexcept {
        return os << country.to_string();
      }
      /// @endcond

    private:
      friend class countries;
      
      static const std::vector<std::string> enclosed_letters;
      country(const std::string& name, const std::string& alpha_2_code, const std::string& alpha_3_code, int numeric_code) : name_(name), alpha_2_code_(alpha_2_code), alpha_3_code_(alpha_3_code), numeric_code_(numeric_code), emoticon_(enclosed_letters[alpha_2_code[0] - 'A'] + enclosed_letters[alpha_2_code[1] - 'A']) {}
#if defined(__cpp_lib_char8_t)
      country(const std::u8string& name, const std::string& alpha_2_code, const std::string& alpha_3_code, int numeric_code) : name_(xtd::strings::to_string(name)), alpha_2_code_(alpha_2_code), alpha_3_code_(alpha_3_code), numeric_code_(numeric_code), emoticon_(enclosed_letters[alpha_2_code[0] - 'A'] + enclosed_letters[alpha_2_code[1] - 'A']) {}
#endif

      std::string name_;
      std::string alpha_2_code_;
      std::string alpha_3_code_;
      int numeric_code_;
      std::string emoticon_;
    };
  }
}
