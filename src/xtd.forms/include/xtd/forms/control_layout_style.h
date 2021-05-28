/// @file
/// @brief Contains xtd::forms::control_layout_style class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/strings.h>
#include "content_alignment.h"
#include "size_type.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Implements the basic functionality that represents the appearance and behavior of a control layout.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class control_layout_style {
    protected:
      /// @brief Initialises a new instance of control layout style class.
      control_layout_style() = default;
      /// @brief Initialises a new instance of control layout style class with specified expanded.
      /// @param expanded true if control expanded; otherwise false.
      explicit control_layout_style(bool expanded) : expanded_(expanded) {}
      /// @brief Initialises a new instance of control layout style class with specified expanded and content alignment.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values..
      explicit control_layout_style(bool expanded, xtd::forms::content_alignment align) : expanded_(expanded), align_(align) {}
      /// @brief Initialises a new instance of control layout style class with specified size type.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container.
      explicit control_layout_style(xtd::forms::size_type size_type) : size_type_(size_type) {}
      /// @brief Initialises a new instance of control layout style class with specified expanded and size type.
      /// @param expanded true if control expanded; otherwise false.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container.
      explicit control_layout_style(bool expanded, xtd::forms::size_type size_type) : expanded_(expanded), size_type_(size_type) {}
      /// @brief Initialises a new instance of control layout style class with specified expanded and size type.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container.
      explicit control_layout_style(bool expanded, xtd::forms::content_alignment align, xtd::forms::size_type size_type) : expanded_(expanded), align_(align), size_type_(size_type) {}

    public:
      /// @brief Gets a flag indicating how a control should be sized relative to its containing layout container.
      /// @return One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::absolute.
      xtd::forms::size_type size_type() const {return size_type_;}
      /// @brief Sets a flag indicating how a control should be sized relative to its containing layout container.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::absolute.
      control_layout_style& size_type(xtd::forms::size_type size_type) {
        size_type_ = size_type;
        return *this;
      }

      /// @brief Gets a flag indicating if control is expanded to its containing layout container.
      /// @return true if control expanded; otherwise false. The default is false.
      bool expanded() const {return expanded_;}
      /// @brief Sets a flag indicating if control is expanded to its containing layout container.
      /// @param expanded true if control expanded; otherwise false. The default is false.
      control_layout_style& expanded(bool expanded) {
        expanded_ = expanded;
        return *this;
      }

      /// @brief Gets a flag indicating how a control should be align to its containing layout container.
      /// @return align One of the content_alignment values. The default is top_left.
      /// @remarks This property work only if expanded = false.
      xtd::forms::content_alignment align() const {return align_;}
      /// @brief Sets a flag indicating how a control should be align to its containing layout container.
      /// @param align One of the content_alignment values. The default is top_left.
      /// @remarks This property work only if expanded = false.
      control_layout_style& align(xtd::forms::content_alignment align) {
        align_ = align;
        return *this;
      }

      /// @brief Returns a string that represent xtd::forms::control_layout_style.
      /// @return A string containing that represent xtd::forms::control_layout_style.
      virtual std::string to_string() const {return strings::format("control_layout_style=[expanded={}, align={}, size_type={}]", expanded_, align_, size_type_);}
      
      /// @cond
      bool operator==(const control_layout_style& value) const {return size_type_ == value.size_type_ && expanded_ == value.expanded_;}
      bool operator!=(const control_layout_style& value) const {return !operator==(value);}
      friend std::ostream& operator<<(std::ostream& os, const xtd::forms::control_layout_style& control_layout_style) noexcept {
        return os << control_layout_style.to_string();
      }
      /// @endcond

    private:
      bool expanded_ = false;
      xtd::forms::content_alignment align_ = xtd::forms::content_alignment::top_left;
      xtd::forms::size_type size_type_ = xtd::forms::size_type::absolute;
    };
  }
}
