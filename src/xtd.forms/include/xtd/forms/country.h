/// @file
/// @brief Contains xtd::forms::country component.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.h"
#include <xtd/object.h>
#include <xtd/convert_string.h>
#include <xtd/static.h>
#include <xtd/drawing/bitmap.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class countries;
    /// @endcond

    /// @brief Represent a country with name, alpha codes, numeric code, emoticon and flag.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    /// @par Examples
    /// The following code example demonstrate the use of country component.
    /// @include countries.cpp
    /// @par Windows
    /// @image html countries_w.png
    /// <br>
    /// @image html countries_wd.png
    /// @par macOS
    /// @image html countries_m.png
    /// <br>
    /// @image html countries_md.png
    /// @par Gnome
    /// @image html countries_g.png
    /// <br>
    /// @image html countries_gd.png
    class forms_export_ country : public object {
    public:
      /// @cond
      country() = default;
      bool operator==(const country& value) const {return name_ == value.name_ && alpha_2_code_ == value.alpha_2_code_ && alpha_3_code_ == value.alpha_3_code_ && numeric_code_ == value.numeric_code_;}
      bool operator!=(const country& value) const {return !operator==(value);}
      /// @endcond
      
      /// @brief Get an empty country.
      /// @return An empty country
      static const country empty();

      /// @brief Gets the country alpha 2 code.
      /// @return A string that represent the alpha 2 code.
      virtual const std::string alpha_2_code() const {return alpha_2_code_;}

      /// @brief Gets the country alpha 3 code.
      /// @return A string that represent the alpha 3 code.
      virtual const std::string alpha_3_code() const {return alpha_3_code_;}

      /// @brief Gets the country emoticon.
      /// @return A string that represent the emoticpn.
      virtual const std::string emoticon() const {return emoticon_;}
      
      /// @brief Gets the country flag.
      /// @return A xtd::drawing::image that represent the flag of 1024 x 768 pixels.
      virtual const xtd::drawing::image flag() const;
      
      /// @brief Gets the country flag.
      /// @return A xtd::drawing::image that represent the flag of 1024 x 1024 pixels.
      virtual const xtd::drawing::image flag_squared() const;

      /// @brief Gets the country name.
      /// @return A string that represent the country.
      virtual const std::string name() const {return name_;}

      /// @brief Gets the country numeric code.
      /// @return A signed-integer that represent the numerci code.
      virtual int numeric_code() const {return numeric_code_;}

      /// @brief Gets a country from alpha 2 code.
      /// @return If exist a xtd::forms::country that represent alpha 2 coded; otherwise xtd::forms::country::empty.
      static country from_alpha_2_code(const std::string& alpha_2_code);
      /// @brief Gets a country from alpha 3 code.
      /// @return If exist a xtd::forms::country that represent alpha 3 coded; otherwise xtd::forms::country::empty.
      static country from_alpha_3_code(const std::string& alpha_3_code);
      /// @brief Gets a country from name.
      /// @return If exist a xtd::forms::country that represent name; otherwise xtd::forms::country::empty.
      static country from_name(const std::string& name);
      /// @brief Gets a country from numeric code.
      /// @return If exist a xtd::forms::country that represent numeric coded; otherwise xtd::forms::country::empty.
      static country from_numeric_code(int numeric_code);

      /// @brief Returns a string containing the name, alpha codes and numeric code of the country.
      /// @return A string containing the name, alpha codes and numeric code of the country.
      virtual std::string to_string() const noexcept override;
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::forms::country& country) noexcept {
        return os << country.to_string();
      }
      /// @endcond

    private:
      friend class countries;
      
      static const std::vector<std::string> enclosed_letters;
      country(const std::string& name, const std::string& alpha_2_code, const std::string& alpha_3_code, int numeric_code) : name_(name), alpha_2_code_(alpha_2_code), alpha_3_code_(alpha_3_code), numeric_code_(numeric_code), emoticon_(enclosed_letters[alpha_2_code[0] - 'A'] + enclosed_letters[alpha_2_code[1] - 'A']) {}
      country(const std::u8string& name, const std::string& alpha_2_code, const std::string& alpha_3_code, int numeric_code) : name_(xtd::convert_string::to_string(name)), alpha_2_code_(alpha_2_code), alpha_3_code_(alpha_3_code), numeric_code_(numeric_code), emoticon_(enclosed_letters[alpha_2_code[0] - 'A'] + enclosed_letters[alpha_2_code[1] - 'A']) {}

      std::string name_;
      std::string alpha_2_code_;
      std::string alpha_3_code_;
      int numeric_code_;
      std::string emoticon_;
    };
  }
}
