/// @file
/// @brief Contains xtd::forms::vertical_control_layout_style class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <optional>
#include "control_layout_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Implements the basic functionality that represents the appearance and behavior of a control layout.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class vertical_control_layout_style : public control_layout_style {
    public:
      /// @brief Initialises a new instance of vertical control layout style class.
      vertical_control_layout_style() = default;
      /// @brief Initialises a new instance of vertical control layout style class with spcified height.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      vertical_control_layout_style(float height) : height_(height) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified height.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      vertical_control_layout_style(int32_t height) : height_(static_cast<float>(height)) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified size type.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      vertical_control_layout_style(xtd::forms::size_type size_type) : control_layout_style(size_type) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified height and size type.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      vertical_control_layout_style(float height, xtd::forms::size_type size_type) : control_layout_style(size_type), height_(height) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified height and size type.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      vertical_control_layout_style(int32_t height, xtd::forms::size_type size_type) : control_layout_style(size_type), height_(static_cast<float>(height)) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified expanded.
      /// @param expanded true if control expanded; otherwise false.
      vertical_control_layout_style(bool expanded) : control_layout_style(expanded) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified height and expanded.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param expanded true if control expanded; otherwise false.
      vertical_control_layout_style(float height, bool expanded) : control_layout_style(expanded), height_(height) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified height and expanded.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param expanded true if control expanded; otherwise false.
      vertical_control_layout_style(int32_t height, bool expanded) : control_layout_style(expanded), height_(static_cast<float>(height)) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified content alignement.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(xtd::forms::content_alignment align) : control_layout_style(align) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified height and content alignement.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(float height, xtd::forms::content_alignment align) : control_layout_style(align), height_(height) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified height and content alignement.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(int32_t height, xtd::forms::content_alignment align) : control_layout_style(align), height_(static_cast<float>(height)) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified size type and expanded.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      vertical_control_layout_style(xtd::forms::size_type size_type, bool expanded) : control_layout_style(size_type, expanded) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified height, size type and expanded.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      vertical_control_layout_style(float height, xtd::forms::size_type size_type, bool expanded) : control_layout_style(size_type, expanded), height_(height) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified height, size type and expanded.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      vertical_control_layout_style(int32_t height, xtd::forms::size_type size_type, bool expanded) : control_layout_style(size_type, expanded), height_(static_cast<float>(height)) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified size type and content alignement.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(xtd::forms::size_type size_type, xtd::forms::content_alignment align) : control_layout_style(size_type, align) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified height, size type and content alignement.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(float height, xtd::forms::size_type size_type, xtd::forms::content_alignment align) : control_layout_style(size_type, align), height_(height) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified height, size type and content alignement.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(int32_t height, xtd::forms::size_type size_type, xtd::forms::content_alignment align) : control_layout_style(size_type, align), height_(static_cast<float>(height)) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified size type, expanded and content alignement.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align) : control_layout_style(size_type, expanded, align) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified height, size type, expanded and content alignement.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(float height, xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align) : control_layout_style(size_type, expanded, align), height_(height) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified height, size type, expanded and content alignement.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(int32_t height, xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align) : control_layout_style(size_type, expanded, align), height_(static_cast<float>(height)) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified expanded and content alignement.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(bool expanded, xtd::forms::content_alignment align) : control_layout_style(expanded, align) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified height, expanded and content alignement.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(float height, bool expanded, xtd::forms::content_alignment align) : control_layout_style(expanded, align), height_(height) {}
      /// @brief Initialises a new instance of vertical control layout style class with spcified height, expanded and content alignement.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      vertical_control_layout_style(int32_t height, bool expanded, xtd::forms::content_alignment align) : control_layout_style(expanded, align), height_(static_cast<float>(height)) {}

      /// @brief Gets the height value for a control.
      /// @return The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      std::optional<float> height() const {return height_;}
      /// @brief Sets the height value for a control.
      /// @param height The preferred height, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      void height(float height) {height_ = height;}

      /// @brief Returns a string that represent xtd::forms::control_layout_style.
      /// @return A string containing that represent xtd::forms::control_layout_style.
      std::string to_string() const noexcept override {return strings::format("vertical_control_layout_style=[expanded={}, align={}, size_type={}, height={}]", expanded(), align(), size_type(), height_);}
      
      /// @cond
      bool operator==(const vertical_control_layout_style& value) const {return height_ == value.height_ && control_layout_style::operator==(value);}
      bool operator!=(const vertical_control_layout_style& value) const {return !operator==(value);}
      friend std::ostream& operator<<(std::ostream& os, const xtd::forms::vertical_control_layout_style& control_layout_style) noexcept {
        return os << control_layout_style.to_string();
      }
      /// @endcond

    private:
      std::optional<float> height_;
    };
  }
}
