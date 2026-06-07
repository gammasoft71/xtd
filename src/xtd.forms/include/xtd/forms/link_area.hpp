/// @file
/// @brief Contains xtd::forms::link_area struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.hpp"
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents an area within a xtd::forms::link_label control that represents a hyperlink within the control.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/link_area>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks There are two ways to add a hyperlink to the text of a xtd::forms::link_label control. You can access the xtd::forms::link_label::link_collection::push_back method of the xtd::forms::link_label::link_collection class through the xtd::forms::link_label::links property of the xtd::forms::link_label to add multiple hyperlinks to the control's text. If you only need to add a single hyperlink to the text of the control, you can use the xtd::forms::link_label::link_area property of the xtd::forms::link_label. This property accepts a xtd::forms::link_area that defines the location of the hyperlink within the control's text. When a hyperlink is specified using the xtd::forms::link_label::link_area property, the link area is then added to the xtd::forms::link_label::link_collection in the same manner as adding the link using the xtd::forms::link_label::link_collection::push_back method of the xtd::forms::link_label::link_collection.
    /// @remarks The xtd::forms::link_area::length property specifies the number of characters within the text of the xtd::forms::link_label to include in the link area. The xtd::forms::link_area::start property specifies the first character in the control text to include in the hyperlink. If you want to determine whether a specific xtd::forms::link_area is empty, you can use the xtd::forms::link_area::is_empty property instead of checking the values of the xtd::form::link_area::start and xtd::form::link_area::length properties.
    forms_export_ struct link_area : public xtd::object, public xtd::iequatable<link_area> {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @param start The zero-based starting location of the link area within the text of the LinkLabel.
      link_area() = default;
      /// @brief Initializes a new instance of the xtd::forms::link_area class.
      /// @param start The zero-based starting location of the link area within the text of the LinkLabel.
      /// @param length The number of characters, after the starting character, to include in the link area.
      link_area(xtd::usize start, xtd::usize length) noexcept;
      /// @}

      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value indicating whether the LinkArea is empty.
      /// @return `true` if the specified start and length return an empty link area; otherwise, `false`.
      [[nodiscard]] auto is_empty() const noexcept -> bool;
      
      /// @brief Gets the number of characters in the link area.
      /// @return The number of characters, including spaces, in the link area.
      /// @remarks To specify text from the xtd::forms::link_label to display as a link, set the xtd::forms::link_area::start property to the location in the text to start creating the link. After the xtd::forms::link_area::start property is set, set the value of the xtd::forms::link_area::length property to the number of characters, including the character position specified in the xtd::forms::link_area::start property, that you want to make the link text. For example, if you want to make the first word of the text "The quick brown fox" a link, you set the xtd::forms::link_area::start property to zero (0) and the xtd::forms::link_area::length property to three (3).
      [[nodiscard]] auto length() const noexcept -> xtd::usize;
      /// @brief Sets the number of characters in the link area.
      /// @param value The number of characters, including spaces, in the link area.
      /// @return This current instance.
      /// @remarks To specify text from the xtd::forms::link_label to display as a link, set the xtd::forms::link_area::start property to the location in the text to start creating the link. After the xtd::forms::link_area::start property is set, set the value of the xtd::forms::link_area::length property to the number of characters, including the character position specified in the xtd::forms::link_area::start property, that you want to make the link text. For example, if you want to make the first word of the text "The quick brown fox" a link, you set the xtd::forms::link_area::start property to zero (0) and the xtd::forms::link_area::length property to three (3).
      auto length(xtd::usize value) noexcept -> link_area&;
      
      /// @brief Gets the starting location of the link area within the text of the xtd::forms::link_label.
      /// @return The location within the text of the xtd::fors::link_label control where the link starts.
      /// @remarks To specify text from the xtd::forms::link_label to display as a link, set the xtd::forms::link_area::start property to the location in the text to start creating the link. After the xtd::forms::link_area::start property is set, set the value of the xtd::forms::link_area::length property to the number of characters, including the character position specified in the xtd::forms::link_area::start property, that you want to make the link text. For example, if you want to make the first word of the text "The quick brown fox" a link, you set the xtd::forms::link_area::start property to zero (0) and the xtd::forms::link_area::length property to three (3).
      [[nodiscard]] auto start() const noexcept -> xtd::usize;
      /// @brief Sets the starting location of the link area within the text of the xtd::forms::link_label.
      /// @param value The location within the text of the xtd::fors::link_label control where the link starts.
      /// @return This current instance.
      /// @remarks To specify text from the xtd::forms::link_label to display as a link, set the xtd::forms::link_area::start property to the location in the text to start creating the link. After the xtd::forms::link_area::start property is set, set the value of the xtd::forms::link_area::length property to the number of characters, including the character position specified in the xtd::forms::link_area::start property, that you want to make the link text. For example, if you want to make the first word of the text "The quick brown fox" a link, you set the xtd::forms::link_area::start property to zero (0) and the xtd::forms::link_area::length property to three (3).
      auto start(xtd::usize value) noexcept -> link_area&;
      /// @}
      
      /// @name Public Methods
      ///
      /// @{
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const xtd::object& obj) const noexcept -> bool override;
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param other The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const link_area& other) const noexcept -> bool override;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
      
      [[nodiscard]] auto to_string() const noexcept -> xtd::string override;
      /// @}
      
    private:
      xtd::usize start_ = 0;
      xtd::usize length_ = 0;
    };
  }
}
