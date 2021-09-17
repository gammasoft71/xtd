/// @file
/// @brief Contains xtd::forms::horizontal_control_layout_style class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <optional>
#include "control_layout_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Implements the basic functionality that represents the appearance and behavior of a control layout.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class horizontal_control_layout_style : public control_layout_style {
    public:
      /// @brief Initialises a new instance of horizontal control layout style class.
      horizontal_control_layout_style() = default;
      /// @brief Initialises a new instance of horizontal control layout style class with spcified width.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      horizontal_control_layout_style(float width) : width_(width) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified width.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      horizontal_control_layout_style(int32_t width) : width_(static_cast<float>(width)) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified size type.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      horizontal_control_layout_style(xtd::forms::size_type size_type) : control_layout_style(size_type) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified width and size type.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      horizontal_control_layout_style(float width, xtd::forms::size_type size_type) : control_layout_style(size_type), width_(width) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified width and size type.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      horizontal_control_layout_style(int32_t width, xtd::forms::size_type size_type) : control_layout_style(size_type), width_(static_cast<float>(width)) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified expanded.
      /// @param expanded true if control expanded; otherwise false.
      horizontal_control_layout_style(bool expanded) : control_layout_style(expanded) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified width and expanded.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param expanded true if control expanded; otherwise false.
      horizontal_control_layout_style(float width, bool expanded) : control_layout_style(expanded), width_(width) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified width and expanded.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param expanded true if control expanded; otherwise false.
      horizontal_control_layout_style(int32_t width, bool expanded) : control_layout_style(expanded), width_(static_cast<float>(width)) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified content alignement.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(xtd::forms::content_alignment align) : control_layout_style(align) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified width and content alignement.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(float width, xtd::forms::content_alignment align) : control_layout_style(align), width_(width) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified width and content alignement.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(int32_t width, xtd::forms::content_alignment align) : control_layout_style(align), width_(static_cast<float>(width)) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified size type and expanded.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      horizontal_control_layout_style(xtd::forms::size_type size_type, bool expanded) : control_layout_style(size_type, expanded) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified width, size type and expanded.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      horizontal_control_layout_style(float width, xtd::forms::size_type size_type, bool expanded) : control_layout_style(size_type, expanded), width_(width) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified width, size type and expanded.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      horizontal_control_layout_style(int32_t width, xtd::forms::size_type size_type, bool expanded) : control_layout_style(size_type, expanded), width_(static_cast<float>(width)) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified size type and content alignement.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(xtd::forms::size_type size_type, xtd::forms::content_alignment align) : control_layout_style(size_type, align) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified width, size type and content alignement.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(float width, xtd::forms::size_type size_type, xtd::forms::content_alignment align) : control_layout_style(size_type, align), width_(width) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified width, size type and content alignement.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(int32_t width, xtd::forms::size_type size_type, xtd::forms::content_alignment align) : control_layout_style(size_type, align), width_(static_cast<float>(width)) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified size type, expanded and content alignement.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align) : control_layout_style(size_type, expanded, align) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified width, size type, expanded and content alignement.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(float width, xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align) : control_layout_style(size_type, expanded, align), width_(width) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified width, size type, expanded and content alignement.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(int32_t width, xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align) : control_layout_style(size_type, expanded, align), width_(static_cast<float>(width)) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified expanded and content alignement.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(bool expanded, xtd::forms::content_alignment align) : control_layout_style(expanded, align) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified expanded and content alignement.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(float width, bool expanded, xtd::forms::content_alignment align) : control_layout_style(expanded, align), width_(width) {}
      /// @brief Initialises a new instance of horizontal control layout style class with spcified expanded and content alignement.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values. The default is middle_center.
      horizontal_control_layout_style(int32_t width, bool expanded, xtd::forms::content_alignment align) : control_layout_style(expanded, align), width_(static_cast<float>(width)) {}

      /// @brief Gets the width value for a control.
      /// @return The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      std::optional<float> width() const {return width_;}
      /// @brief Sets the width value for a control.
      /// @param width The preferred width, in pixels or percentage, depending on the xtd::forms::control_layout_style::size_type property.
      void width(float width) {width_ = width;}

      /// @brief Returns a string that represent xtd::forms::control_layout_style.
      /// @return A string containing that represent xtd::forms::control_layout_style.
      xtd::ustring to_string() const noexcept override {return ustring::format("horizontal_control_layout_style=[expanded={}, align={}, size_type={}, width={}]", expanded(), align(), size_type(), width_.value_or(-1));}
      
      /// @cond
      bool operator==(const horizontal_control_layout_style& value) const {return width_ == value.width_ && control_layout_style::operator==(value);}
      bool operator!=(const horizontal_control_layout_style& value) const {return !operator==(value);}
      friend std::ostream& operator<<(std::ostream& os, const xtd::forms::horizontal_control_layout_style& control_layout_style) noexcept {
        return os << control_layout_style.to_string();
      }
      /// @endcond

    private:
      std::optional<float> width_;
    };
  }
}
