/// @file
/// @brief Contains xtd::forms::vertical_control_layout_style class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "control_layout_style"
#include <xtd/iequatable>
#include <xtd/optional>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Implements the basic functionality that represents the appearance and behavior of a control layout.
    /// @par Header
    /// @code #include <xtd/forms/vertical_control_layout_style> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class vertical_control_layout_style : public control_layout_style, public xtd::iequatable<vertical_control_layout_style> {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialises a new instance of vertical control layout style class.
      vertical_control_layout_style() = default;
      /// @brief Initialises a new instance of vertical control layout style class with specified height.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      explicit vertical_control_layout_style(float height);
      /// @brief Initialises a new instance of vertical control layout style class with specified height.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      explicit vertical_control_layout_style(int32 height);
      /// @brief Initialises a new instance of vertical control layout style class with specified size type.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      explicit vertical_control_layout_style(xtd::forms::size_type size_type);
      /// @brief Initialises a new instance of vertical control layout style class with specified height and size type.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      vertical_control_layout_style(float height, xtd::forms::size_type size_type);
      /// @brief Initialises a new instance of vertical control layout style class with specified height and size type.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      vertical_control_layout_style(int32 height, xtd::forms::size_type size_type);
      /// @brief Initialises a new instance of vertical control layout style class with specified expanded.
      /// @param expanded true if control expanded; otherwise false.
      explicit vertical_control_layout_style(bool expanded);
      /// @brief Initialises a new instance of vertical control layout style class with specified height and expanded.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param expanded true if control expanded; otherwise false.
      vertical_control_layout_style(float height, bool expanded);
      /// @brief Initialises a new instance of vertical control layout style class with specified height and expanded.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param expanded true if control expanded; otherwise false.
      vertical_control_layout_style(int32 height, bool expanded);
      /// @brief Initialises a new instance of vertical control layout style class with specified content alignment.
      /// @param align One of the content_alignment values. The default is middle_center.
      explicit vertical_control_layout_style(xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of vertical control layout style class with specified height and content alignment.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(float height, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of vertical control layout style class with specified height and content alignment.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(int32 height, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of vertical control layout style class with specified size type and expanded.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      vertical_control_layout_style(xtd::forms::size_type size_type, bool expanded);
      /// @brief Initialises a new instance of vertical control layout style class with specified height, size type and expanded.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      vertical_control_layout_style(float height, xtd::forms::size_type size_type, bool expanded);
      /// @brief Initialises a new instance of vertical control layout style class with specified height, size type and expanded.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      vertical_control_layout_style(int32 height, xtd::forms::size_type size_type, bool expanded);
      /// @brief Initialises a new instance of vertical control layout style class with specified size type and content alignment.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(xtd::forms::size_type size_type, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of vertical control layout style class with specified height, size type and content alignment.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(float height, xtd::forms::size_type size_type, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of vertical control layout style class with specified height, size type and content alignment.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(int32 height, xtd::forms::size_type size_type, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of vertical control layout style class with specified size type, expanded and content alignment.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of vertical control layout style class with specified height, size type, expanded and content alignment.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(float height, xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of vertical control layout style class with specified height, size type, expanded and content alignment.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(int32 height, xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of vertical control layout style class with specified expanded and content alignment.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(bool expanded, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of vertical control layout style class with specified height, expanded and content alignment.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(float height, bool expanded, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of vertical control layout style class with specified height, expanded and content alignment.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(int32 height, bool expanded, xtd::forms::content_alignment align);
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the height value for a control.
      /// @return The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      std::optional<float> height() const noexcept;
      /// @brief Sets the height value for a control.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      void height(float height);
      /// @}
      
      /// @name Methods
      
      /// @{
      using control_layout_style::equals;
      bool equals(const vertical_control_layout_style& value) const noexcept override;
      
      /// @brief Returns a string that represent xtd::forms::control_layout_style.
      /// @return A string containing that represent xtd::forms::control_layout_style.
      xtd::ustring to_string() const noexcept override;
      /// @}
      
    private:
      std::optional<float> height_;
    };
  }
}
