/// @file
/// @brief Contains xtd::forms::emoticon enum component.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.h"
#include <xtd/object.h>
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <ostream>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represent a emoticon with name and codepoints.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    /// @par Examples
    /// The following code example demonstrate the use of emoticon class.
    /// @include emoticons.cpp
    /// @par Windows
    /// @image html emoticons_w.png
    /// <br>
    /// @image html emoticons_wd.png
    /// @par macOS
    /// @image html emoticons_m.png
    /// <br>
    /// @image html emoticons_md.png
    /// @par Gnome
    /// @image html emoticons_g.png
    /// <br>
    /// @image html emoticons_gd.png
    class forms_export_ emoticon : public object {
    public:
      /// @brief Represents an empty emoticon.
      static const emoticon empty();
      
      /// @brief Initialize a new instance of emoticon class with specified name and codepoints.
      /// @param name A string that represent the name of emoticon
      /// @param codepoints An initializer list of char32_t that represent the emoticon.
      emoticon(const xtd::ustring& name, std::initializer_list<char32_t> codepoints) : name_(name), codepoints_(codepoints) {}
      
      /// @brief Initialize a new instance of emoticon class with specified name and codepoints.
      /// @param name A string that represent the name of emoticon
      /// @param codepoints An array of char32_t that represent the emoticon.
      emoticon(const xtd::ustring& name, const std::vector<char32_t>& codepoints) : name_(name), codepoints_(codepoints) {}
      
      /// @brief Initialize a new instance of emoticon class with specified name and codepoint.
      /// @param name A string that represent the name of emoticon
      /// @param codepoint A char32_t that represent the emoticon.
      emoticon(const xtd::ustring& name, char32_t codepoint) : name_(name), codepoints_({codepoint}) {}
      
      /// @brief Initialize a new instance of emoticon class with specified codepoints.
      /// @param codepoints An initializer list of char32_t that represent the emoticon.
      emoticon(std::initializer_list<char32_t> codepoints) : codepoints_(codepoints) {}
      
      /// @brief Initialize a new instance of emoticon class with specified codepoints.
      /// @param codepoints An array of char32_t that represent the emoticon.
      emoticon(const std::vector<char32_t>& codepoints) : codepoints_(codepoints) {}
      
      /// @brief Initialize a new instance of emoticon class with specified codepoint.
      /// @param codepoints A char32_t that represent the emoticon.
      emoticon(char32_t codepoint) : codepoints_({codepoint}) {}
      
      /// @cond
      template<typename type_t>
      emoticon(const xtd::ustring& name, std::initializer_list<type_t> codepoints) : name_(name) {
        for(auto codepoint : codepoints)
          codepoints_.push_back(static_cast<char32_t>(codepoint));
      }
      
      template<typename type_t>
      emoticon(const xtd::ustring& name, const std::vector<type_t>& codepoints) : name_(name) {
        for(auto codepoint : codepoints)
          codepoints_.push_back(static_cast<char32_t>(codepoint));
      }
      
      template<typename type_t>
      emoticon(const xtd::ustring& name, type_t codepoint) : name_(name), codepoints_({static_cast<char32_t>(codepoint)}) {}
      
      template<typename type_t>
      emoticon(std::initializer_list<type_t> codepoints) {
        for(auto codepoint : codepoints)
          codepoints_.push_back(static_cast<char32_t>(codepoint));
      }
      
      template<typename type_t>
      emoticon(const std::vector<type_t>& codepoints) {
        for(auto codepoint : codepoints)
          codepoints_.push_back(static_cast<char32_t>(codepoint));
      }

      template<typename type_t>
      emoticon(type_t codepoint) : codepoints_({static_cast<char32_t>(codepoint)}) {}

      emoticon() = default;
      emoticon(const emoticon&) = default;
      emoticon& operator=(const emoticon&) = default;
      bool operator==(const emoticon& value) {return name_ == value.name_ && codepoints_ == value.codepoints_;}
      bool operator!=(const emoticon& value) {return !operator==(value);}
      friend std::ostream& operator<<(std::ostream& os, const xtd::forms::emoticon& emoticon) noexcept {
        return os << emoticon.to_string();
      }
      /// @endcond
      
      /// @brief Gets name of emoticon.
      /// @return A string that represent the name of emoticon.
      const xtd::ustring& name() const {return name_;}
      
      /// @brief Gets codepoints of emoticon.
      /// @return An array of char32_t that represent the emoticon.
      const std::vector<char32_t>& codepoints() const {return codepoints_;}

      /// @brief Returns a string containing the codepoints of the emoticons.
      /// @return A string containing the codepoints of the emoticon. Empty string ("") for none codepoints.
      xtd::ustring to_string() const noexcept override {
        std::string result;
        for (auto codepoint : codepoints_) {
          if (codepoint < 0x80) {
            result.push_back(static_cast<char>(codepoint));
          } else  if (codepoint < 0x800) {
            result.push_back(static_cast<char>((codepoint >> 6) | 0xc0));
            result.push_back(static_cast<char>((codepoint & 0x3f) | 0x80));
          } else if (codepoint < 0x10000) {
            result.push_back(static_cast<char>((codepoint >> 12) | 0xe0));
            result.push_back(static_cast<char>(((codepoint >> 6) & 0x3f) | 0x80));
            result.push_back(static_cast<char>((codepoint & 0x3f) | 0x80));
          } else {
            result.push_back(static_cast<char>((codepoint >> 18) | 0xf0));
            result.push_back(static_cast<char>(((codepoint >> 12) & 0x3f) | 0x80));
            result.push_back(static_cast<char>(((codepoint >> 6) & 0x3f) | 0x80));
            result.push_back(static_cast<char>((codepoint & 0x3f) | 0x80));
          }
        }
        return result;
      }
      
    private:
      xtd::ustring name_;
      std::vector<char32_t> codepoints_;
    };
  }
}

/// @cond
inline xtd::ustring operator+(const xtd::forms::emoticon& value_a, const xtd::forms::emoticon& value_b) {
  return value_a.to_string() + value_b.to_string();
}

inline xtd::ustring operator+(const xtd::forms::emoticon& value_a, const char* value_b) {
  return value_a.to_string() + value_b;
}

inline xtd::ustring operator+(const xtd::forms::emoticon& value_a, const xtd::ustring& value_b) {
  return value_a.to_string() + value_b;
}

inline xtd::ustring operator+(const xtd::ustring& value_a, const xtd::forms::emoticon& value_b) {
  return value_a + value_b.to_string();
}

inline xtd::ustring operator+(const char* value_a, const xtd::forms::emoticon& value_b) {
  return xtd::ustring(value_a) + value_b.to_string();
}
/// @endcond
