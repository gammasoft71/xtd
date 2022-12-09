/// @file
/// @brief Contains xtd::forms::emoticon enum component.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.h"
#include <xtd/iequatable.h>
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
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    /// @par Examples
    /// The following code example demonstrates the use of emoticon class.
    /// @include emoticons.cpp
    class forms_export_ emoticon : public object, public xtd::iequatable<emoticon> {
    public:
      /// @name Fields
      
      /// @{
      /// @brief Represents an empty emoticon.
      static const emoticon empty();
      
      /// @name Constructors
      
      /// @{
      /// @brief Initialize a new instance of emoticon class with specified name and codepoints.
      /// @param name A string that represent the name of emoticon
      /// @param codepoints An initializer list of char32_t that represent the emoticon.
      emoticon(const xtd::ustring& name, std::initializer_list<char32_t> codepoints);
      
      /// @brief Initialize a new instance of emoticon class with specified name and codepoints.
      /// @param name A string that represent the name of emoticon
      /// @param codepoints An array of char32_t that represent the emoticon.
      emoticon(const xtd::ustring& name, const std::vector<char32_t>& codepoints);
      
      /// @brief Initialize a new instance of emoticon class with specified name and codepoint.
      /// @param name A string that represent the name of emoticon
      /// @param codepoint A char32_t that represent the emoticon.
      emoticon(const xtd::ustring& name, char32_t codepoint);
      
      /// @brief Initialize a new instance of emoticon class with specified codepoints.
      /// @param codepoints An initializer list of char32_t that represent the emoticon.
      explicit emoticon(std::initializer_list<char32_t> codepoints);
      
      /// @brief Initialize a new instance of emoticon class with specified codepoints.
      /// @param codepoints An array of char32_t that represent the emoticon.
      explicit emoticon(const std::vector<char32_t>& codepoints);
      
      /// @brief Initialize a new instance of emoticon class with specified codepoint.
      /// @param codepoints A char32_t that represent the emoticon.
      explicit emoticon(char32_t codepoint);
      /// @}
      
      /// @cond
      template<typename type_t>
      emoticon(const xtd::ustring& name, std::initializer_list<type_t> codepoints) {
        data_->name = name;
        for (auto codepoint : codepoints)
          data_->codepoints.push_back(static_cast<char32_t>(codepoint));
      }
      
      template<typename type_t>
      emoticon(const xtd::ustring& name, const std::vector<type_t>& codepoints) {
        data_->name = name;
        for (auto codepoint : codepoints)
          data_->codepoints.push_back(static_cast<char32_t>(codepoint));
      }
      
      template<typename type_t>
      emoticon(const xtd::ustring& name, type_t codepoint) {
        data_->name = name;
        data_->codepoints = {static_cast<char32_t>(codepoint)};
      }
      
      template<typename type_t>
      explicit emoticon(std::initializer_list<type_t> codepoints) {
        for (auto codepoint : codepoints)
          data_->codepoints.push_back(static_cast<char32_t>(codepoint));
      }
      
      template<typename type_t>
      explicit emoticon(const std::vector<type_t>& codepoints) {
        for (auto codepoint : codepoints)
          data_->codepoints.push_back(static_cast<char32_t>(codepoint));
      }
      
      template<typename type_t>
      explicit emoticon(type_t codepoint) {
        data_->codepoints = {static_cast<char32_t>(codepoint)};
      }
      
      emoticon() = default;
      emoticon(const emoticon& other) {
        *data_ = *other.data_;
      }
      
      emoticon& operator =(const emoticon& other) {
        *data_ = *other.data_;
        return *this;
      }
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets name of emoticon.
      /// @return A string that represent the name of emoticon.
      const xtd::ustring& name() const noexcept;
      
      /// @brief Gets codepoints of emoticon.
      /// @return An array of char32_t that represent the emoticon.
      const std::vector<char32_t>& codepoints() const noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      bool equals(const emoticon& value) const noexcept override;

      /// @brief Returns a string containing the codepoints of the emoticons.
      /// @return A string containing the codepoints of the emoticon. Empty string ("") for none codepoints.
      xtd::ustring to_string() const noexcept override;
      /// @}
      
    private:
      struct data {
        xtd::ustring name;
        std::vector<char32_t> codepoints;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}

/// @cond
inline xtd::ustring operator +(const xtd::forms::emoticon& value_a, const xtd::forms::emoticon& value_b) {
  return value_a.to_string() + value_b.to_string();
}

inline xtd::ustring operator +(const xtd::forms::emoticon& value_a, const char* value_b) {
  return value_a.to_string() + value_b;
}

inline xtd::ustring operator +(const xtd::forms::emoticon& value_a, const xtd::ustring& value_b) {
  return value_a.to_string() + value_b;
}

inline xtd::ustring operator +(const xtd::ustring& value_a, const xtd::forms::emoticon& value_b) {
  return value_a + value_b.to_string();
}

inline xtd::ustring operator +(const char* value_a, const xtd::forms::emoticon& value_b) {
  return xtd::ustring(value_a) + value_b.to_string();
}
/// @endcond
