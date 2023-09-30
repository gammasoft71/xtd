/// @file
/// @brief Contains xtd::forms::country component.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.h"
#include <xtd/drawing/bitmap>
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/ustring>
#include <xtd/convert_string>
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class countries;
    /// @endcond
    
    /// @brief Represent a country with name, alpha codes, numeric code, emoticon and flag.
    /// @par Header
    /// @code #include <xtd/forms/country> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    /// @par Examples
    /// The following code example demonstrates the use of country component.
    /// @include countries.cpp
    class forms_export_ country : public object, public xtd::iequatable<country> {
      struct data;
      
    public:
      /// @cond
      country();
      country(const country& other);
      country& operator =(const country& other);
      /// @endcond
      
      /// @name Fields
      
      /// @{
      /// @brief Gets an empty country.
      /// @return An empty country
      static const country empty();
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the country alpha 2 code.
      /// @return A string that represent the alpha 2 code.
      virtual const xtd::ustring alpha_2_code() const noexcept;
      
      /// @brief Gets the country alpha 3 code.
      /// @return A string that represent the alpha 3 code.
      virtual const xtd::ustring alpha_3_code() const noexcept;
      
      /// @brief Gets the country emoticon.
      /// @return A string that represent the emoticon.
      virtual const xtd::ustring emoticon() const noexcept;
      
      /// @brief Gets the country flag.
      /// @return A xtd::drawing::image that represent the flag of 1024 x 768 pixels.
      virtual const xtd::drawing::image flag() const noexcept;
      
      /// @brief Gets the country flag.
      /// @return A xtd::drawing::image that represent the flag of 1024 x 1024 pixels.
      virtual const xtd::drawing::image flag_squared() const noexcept;
      
      /// @brief Gets the country name.
      /// @return A string that represent the country.
      virtual const xtd::ustring name() const noexcept;
      
      /// @brief Gets the country numeric code.
      /// @return A signed-integer that represent the numeric code.
      virtual int32 numeric_code() const noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      bool equals(const country& value) const noexcept override;
      
      /// @brief Gets a country from alpha 2 code.
      /// @return If exist a xtd::forms::country that represent alpha 2 coded; otherwise xtd::forms::country::empty.
      static country from_alpha_2_code(const xtd::ustring& alpha_2_code);
      
      /// @brief Gets a country from alpha 3 code.
      /// @return If exist a xtd::forms::country that represent alpha 3 coded; otherwise xtd::forms::country::empty.
      static country from_alpha_3_code(const xtd::ustring& alpha_3_code);
      
      /// @brief Gets a country from name.
      /// @return If exist a xtd::forms::country that represent name; otherwise xtd::forms::country::empty.
      static country from_name(const xtd::ustring& name);
      
      /// @brief Gets a country from numeric code.
      /// @return If exist a xtd::forms::country that represent numeric coded; otherwise xtd::forms::country::empty.
      static country from_numeric_code(int32 numeric_code);
      
      /// @brief Returns a string containing the name, alpha codes and numeric code of the country.
      /// @return A string containing the name, alpha codes and numeric code of the country.
      virtual xtd::ustring to_string() const noexcept override;
      /// @}
      /// @endcond
      
    private:
      friend class countries;
      static const std::vector<xtd::ustring> enclosed_letters;
      country(const xtd::ustring& name, const xtd::ustring& alpha_2_code, const xtd::ustring& alpha_3_code, int32 numeric_code);
      
      std::shared_ptr<data> data_;
    };
  }
}
