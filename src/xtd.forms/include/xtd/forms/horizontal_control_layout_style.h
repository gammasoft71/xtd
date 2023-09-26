/// @file
/// @brief Contains xtd::forms::horizontal_control_layout_style class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "control_layout_style"
#include <xtd/optional>
#include <xtd/iequatable>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Implements the basic functionality that represents the appearance and behavior of a control layout.
    /// @par Header
    /// @code #include <xtd/forms/horizontal_control_layout_style> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class horizontal_control_layout_style : public control_layout_style, public xtd::iequatable<horizontal_control_layout_style> {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialises a new instance of horizontal control layout style class.
      horizontal_control_layout_style() = default;
      /// @brief Initialises a new instance of horizontal control layout style class with specified width.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      explicit horizontal_control_layout_style(float width);
      /// @brief Initialises a new instance of horizontal control layout style class with specified width.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      explicit horizontal_control_layout_style(int32 width);
      /// @brief Initialises a new instance of horizontal control layout style class with specified size type.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      explicit horizontal_control_layout_style(xtd::forms::size_type size_type);
      /// @brief Initialises a new instance of horizontal control layout style class with specified width and size type.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      horizontal_control_layout_style(float width, xtd::forms::size_type size_type);
      /// @brief Initialises a new instance of horizontal control layout style class with specified width and size type.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      horizontal_control_layout_style(int32 width, xtd::forms::size_type size_type);
      /// @brief Initialises a new instance of horizontal control layout style class with specified expanded.
      /// @param expanded true if control expanded; otherwise false.
      explicit horizontal_control_layout_style(bool expanded);
      /// @brief Initialises a new instance of horizontal control layout style class with specified width and expanded.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param expanded true if control expanded; otherwise false.
      horizontal_control_layout_style(float width, bool expanded);
      /// @brief Initialises a new instance of horizontal control layout style class with specified width and expanded.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param expanded true if control expanded; otherwise false.
      horizontal_control_layout_style(int32 width, bool expanded);
      /// @brief Initialises a new instance of horizontal control layout style class with specified content alignment.
      /// @param align One of the content_alignment values. The default is middle_center.
      explicit horizontal_control_layout_style(xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of horizontal control layout style class with specified width and content alignment.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(float width, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of horizontal control layout style class with specified width and content alignment.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(int32 width, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of horizontal control layout style class with specified size type and expanded.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      horizontal_control_layout_style(xtd::forms::size_type size_type, bool expanded);
      /// @brief Initialises a new instance of horizontal control layout style class with specified width, size type and expanded.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      horizontal_control_layout_style(float width, xtd::forms::size_type size_type, bool expanded);
      /// @brief Initialises a new instance of horizontal control layout style class with specified width, size type and expanded.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      horizontal_control_layout_style(int32 width, xtd::forms::size_type size_type, bool expanded);
      /// @brief Initialises a new instance of horizontal control layout style class with specified size type and content alignment.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(xtd::forms::size_type size_type, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of horizontal control layout style class with specified width, size type and content alignment.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(float width, xtd::forms::size_type size_type, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of horizontal control layout style class with specified width, size type and content alignment.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(int32 width, xtd::forms::size_type size_type, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of horizontal control layout style class with specified size type, expanded and content alignment.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of horizontal control layout style class with specified width, size type, expanded and content alignment.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(float width, xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of horizontal control layout style class with specified width, size type, expanded and content alignment.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(int32 width, xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of horizontal control layout style class with specified expanded and content alignment.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(bool expanded, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of horizontal control layout style class with specified expanded and content alignment.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(float width, bool expanded, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of horizontal control layout style class with specified expanded and content alignment.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(int32 width, bool expanded, xtd::forms::content_alignment align);
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the width value for a control.
      /// @return The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      std::optional<float> width() const noexcept;
      /// @brief Sets the width value for a control.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      void width(float width);
      /// @}
      
      /// @name Methods
      
      /// @{
      using control_layout_style::equals;
      bool equals(const horizontal_control_layout_style& value) const noexcept override;
      
      /// @brief Returns a string that represent xtd::forms::control_layout_style.
      /// @return A string containing that represent xtd::forms::control_layout_style.
      xtd::ustring to_string() const noexcept override;
      /// @}
      
    private:
      std::optional<float> width_;
    };
  }
}
