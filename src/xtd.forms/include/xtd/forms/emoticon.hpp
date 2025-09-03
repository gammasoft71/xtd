/// @file
/// @brief Contains xtd::forms::emoticon enum component.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.hpp"
#include <xtd/collections/generic/list>
#include <xtd/icomparable>
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/static>
#include <xtd/string>
#include <ostream>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represent a emoticon with name and codepoints.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/emoticon>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    /// @par Examples
    /// The following code example demonstrates the use of emoticon class.
    /// @include emoticons.cpp
    class forms_export_ emoticon : public object, public xtd::iequatable<emoticon>, public icomparable<emoticon> {
      struct data;
    public:
      /// @name Public Fields
      
      /// @{
      /// @brief Represents an empty emoticon.
      static const emoticon empty();
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new instance of emoticon class with specified name and codepoints.
      /// @param name A string that represent the name of emoticon
      /// @param codepoints An initializer list of char32 that represent the emoticon.
      emoticon(const xtd::string& name, std::initializer_list<char32> codepoints);
      
      /// @brief Initialize a new instance of emoticon class with specified name and codepoints.
      /// @param name A string that represent the name of emoticon
      /// @param codepoints An array of char32 that represent the emoticon.
      emoticon(const xtd::string& name, const xtd::array<char32>& codepoints);
      
      /// @brief Initialize a new instance of emoticon class with specified name and codepoint.
      /// @param name A string that represent the name of emoticon
      /// @param codepoint A char32 that represent the emoticon.
      emoticon(const xtd::string& name, char32 codepoint);
      
      /// @brief Initialize a new instance of emoticon class with specified codepoints.
      /// @param codepoints An initializer list of char32 that represent the emoticon.
      explicit emoticon(std::initializer_list<char32> codepoints);
      
      /// @brief Initialize a new instance of emoticon class with specified codepoints.
      /// @param codepoints An array of char32 that represent the emoticon.
      explicit emoticon(const xtd::array<char32>& codepoints);
      
      /// @brief Initialize a new instance of emoticon class with specified codepoint.
      /// @param codepoints A char32 that represent the emoticon.
      explicit emoticon(char32 codepoint);
      /// @}
      
      /// @cond
      template<class type_t>
      emoticon(const xtd::string& name, std::initializer_list<type_t> codepoints) {
        create_data();
        name_(name);
        for (auto codepoint : codepoints)
          codepoints_().add(static_cast<char32>(codepoint));
      }
      
      template<class type_t>
      emoticon(const xtd::string& name, const xtd::array<type_t>& codepoints) {
        create_data();
        name_(name);
        for (auto codepoint : codepoints)
          codepoints_().add(static_cast<char32>(codepoint));
      }
      
      template<class type_t>
      emoticon(const xtd::string& name, type_t codepoint) {
        create_data();
        name_(name);
        codepoints_({static_cast<char32>(codepoint)});
      }
      
      template<class type_t>
      explicit emoticon(std::initializer_list<type_t> codepoints) {
        create_data();
        for (auto codepoint : codepoints)
          codepoints_().add(static_cast<char32>(codepoint));
      }
      
      template<class type_t>
      explicit emoticon(const xtd::array<type_t>& codepoints) {
        create_data();
        for (auto codepoint : codepoints)
          codepoints_().add(static_cast<char32>(codepoint));
      }
      
      template<class type_t>
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
      const xtd::string& name() const noexcept;
      
      /// @brief Gets codepoints of emoticon.
      /// @return An array of char32 that represent the emoticon.
      xtd::array<char32> codepoints() const noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Compares the current instance with another object of the same type.
      /// @param obj An object to compare with this instance.
      /// @return A 32-bit signed integer that indicates the relative order of the objects being compared.
      /// The return value has these meanings:
      ///
      /// | Value             | Condition                          |
      /// | ----------------- | ---------------------------------- |
      /// | Less than zero    | This instance is less than obj.    |
      /// | Zero              | This instance is equal to obj.     |
      /// | Greater than zero | This instance is greater than obj. |
      int32 compare_to(const emoticon &obj) const noexcept override;
      
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      bool equals(const xtd::object& obj) const noexcept override;
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param other The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      bool equals(const emoticon& other) const noexcept override;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      xtd::size get_hash_code() const noexcept override;
      
      /// @brief Returns a string containing the codepoints of the emoticons.
      /// @return A string containing the codepoints of the emoticon. Empty string ("") for none codepoints.
      xtd::string to_string() const noexcept override;
      /// @}
      
    private:
      void create_data();
      void name_(const string& name);
      xtd::collections::generic::list<char32>& codepoints_();
      void codepoints_(xtd::array<char32>&& codepoints);
      
      xtd::sptr<data> data_;
    };
  }
}

/// @cond
inline xtd::string operator +(const xtd::forms::emoticon& value_a, const xtd::forms::emoticon& value_b) {
  return value_a.to_string() + value_b.to_string();
}

inline xtd::string operator +(const xtd::forms::emoticon& value_a, const char* value_b) {
  return value_a.to_string() + value_b;
}

inline xtd::string operator +(const xtd::forms::emoticon& value_a, const xtd::string& value_b) {
  return value_a.to_string() + value_b;
}

inline xtd::string operator +(const xtd::string& value_a, const xtd::forms::emoticon& value_b) {
  return value_a + value_b.to_string();
}

inline xtd::string operator +(const char* value_a, const xtd::forms::emoticon& value_b) {
  return xtd::string(value_a) + value_b.to_string();
}
/// @endcond
