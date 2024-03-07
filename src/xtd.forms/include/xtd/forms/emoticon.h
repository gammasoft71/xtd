/// @file
/// @brief Contains xtd::forms::emoticon enum component.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.h"
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/static>
#include <xtd/ustring>
#include <ostream>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represent a emoticon with name and codepoints.
    /// @par Header
    /// @code #include <xtd/forms/emoticon> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    /// @par Examples
    /// The following code example demonstrates the use of emoticon class.
    /// @include emoticons.cpp
    class forms_export_ emoticon : public object, public xtd::iequatable<emoticon> {
      struct data;
    public:
      /// @name Public Fields
      
      /// @{
      /// @brief Represents an empty emoticon.
      static const emoticon empty();
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new instance of emoticon class with specified name and codepoints.
      /// @param name A string that represent the name of emoticon
      /// @param codepoints An initializer list of char32 that represent the emoticon.
      emoticon(const xtd::ustring& name, std::initializer_list<char32> codepoints);
      
      /// @brief Initialize a new instance of emoticon class with specified name and codepoints.
      /// @param name A string that represent the name of emoticon
      /// @param codepoints An array of char32 that represent the emoticon.
      emoticon(const xtd::ustring& name, const std::vector<char32>& codepoints);
      
      /// @brief Initialize a new instance of emoticon class with specified name and codepoint.
      /// @param name A string that represent the name of emoticon
      /// @param codepoint A char32 that represent the emoticon.
      emoticon(const xtd::ustring& name, char32 codepoint);
      
      /// @brief Initialize a new instance of emoticon class with specified codepoints.
      /// @param codepoints An initializer list of char32 that represent the emoticon.
      explicit emoticon(std::initializer_list<char32> codepoints);
      
      /// @brief Initialize a new instance of emoticon class with specified codepoints.
      /// @param codepoints An array of char32 that represent the emoticon.
      explicit emoticon(const std::vector<char32>& codepoints);
      
      /// @brief Initialize a new instance of emoticon class with specified codepoint.
      /// @param codepoints A char32 that represent the emoticon.
      explicit emoticon(char32 codepoint);
      /// @}
      
      /// @cond
      template<typename type_t>
      emoticon(const xtd::ustring& name, std::initializer_list<type_t> codepoints) {
        create_data();
        name_(name);
        for (auto codepoint : codepoints)
          codepoints_().push_back(static_cast<char32>(codepoint));
      }
      
      template<typename type_t>
      emoticon(const xtd::ustring& name, const std::vector<type_t>& codepoints) {
        create_data();
        name_(name);
        for (auto codepoint : codepoints)
          codepoints_().push_back(static_cast<char32>(codepoint));
      }
      
      template<typename type_t>
      emoticon(const xtd::ustring& name, type_t codepoint) {
        create_data();
        name_(name);
        codepoints_({static_cast<char32>(codepoint)});
      }
      
      template<typename type_t>
      explicit emoticon(std::initializer_list<type_t> codepoints) {
        create_data();
        for (auto codepoint : codepoints)
          codepoints_().push_back(static_cast<char32>(codepoint));
      }
      
      template<typename type_t>
      explicit emoticon(const std::vector<type_t>& codepoints) {
        create_data();
        for (auto codepoint : codepoints)
          codepoints_().push_back(static_cast<char32>(codepoint));
      }
      
      template<typename type_t>
      explicit emoticon(type_t codepoint) {
        create_data();
        codepoints_({static_cast<char32>(codepoint)});
      }
      
      emoticon();
      emoticon(const emoticon& other);
      emoticon& operator =(const emoticon& other);
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets name of emoticon.
      /// @return A string that represent the name of emoticon.
      const xtd::ustring& name() const noexcept;
      
      /// @brief Gets codepoints of emoticon.
      /// @return An array of char32 that represent the emoticon.
      const std::vector<char32>& codepoints() const noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      bool equals(const emoticon& value) const noexcept override;
      
      /// @brief Returns a string containing the codepoints of the emoticons.
      /// @return A string containing the codepoints of the emoticon. Empty string ("") for none codepoints.
      xtd::ustring to_string() const noexcept override;
      /// @}
      
    private:
      void create_data();
      void name_(const ustring& name);
      std::vector<char32>& codepoints_();
      void codepoints_(std::vector<char32>&& codepoints);
      
      std::shared_ptr<data> data_;
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
