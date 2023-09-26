/// @file
/// @brief Contains xtd::forms::control_layout_style class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "content_alignment"
#include "size_type"
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/ustring>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Implements the basic functionality that represents the appearance and behavior of a control layout.
    /// @par Header
    /// @code #include <xtd/forms/conrol_layout_style> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class control_layout_style : public object, public xtd::iequatable<control_layout_style> {
      struct data;
      
    protected:
      /// @name Protected Constructors
      
      /// @{
      /// @brief Initialises a new instance of control layout style class.
      control_layout_style();
      /// @brief Initialises a new instance of control layout style class with specified size type.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container.
      explicit control_layout_style(xtd::forms::size_type size_type);
      /// @brief Initialises a new instance of control layout style class with specified expanded.
      /// @param expanded true if control expanded; otherwise false.
      explicit control_layout_style(bool expanded);
      /// @brief Initialises a new instance of control layout style class with specified content alignment.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values..
      explicit control_layout_style(xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of control layout style class with specified size type and expanded.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container.
      /// @param expanded true if control expanded; otherwise false.
      control_layout_style(xtd::forms::size_type size_type, bool expanded);
      /// @brief Initialises a new instance of control layout style class with specified size type and content alignment.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container.
      /// @param align One of the content_alignment values.
      control_layout_style(xtd::forms::size_type size_type, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of control layout style class with specified size type, expanded and content alignment.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values.
      control_layout_style(xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of control layout style class with specified expanded and content alignment.
      /// @param expanded true if control expanded; otherwise false.
      /// @param align One of the content_alignment values..
      control_layout_style(bool expanded, xtd::forms::content_alignment align);
      /// @}
      
    public:
      /// @cond
      control_layout_style(const control_layout_style& other);
      control_layout_style& operator =(const control_layout_style& other);
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets a flag indicating how a control should be sized relative to its containing layout container.
      /// @return One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::absolute.
      xtd::forms::size_type size_type() const noexcept;
      /// @brief Sets a flag indicating how a control should be sized relative to its containing layout container.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::absolute.
      control_layout_style& size_type(xtd::forms::size_type size_type);
      
      /// @brief Gets a flag indicating if control is expanded to its containing layout container.
      /// @return true if control expanded; otherwise false. The default is false.
      bool expanded() const noexcept;
      /// @brief Sets a flag indicating if control is expanded to its containing layout container.
      /// @param expanded true if control expanded; otherwise false. The default is false.
      control_layout_style& expanded(bool expanded);
      
      /// @brief Gets a flag indicating how a control should be align to its containing layout container.
      /// @return align One of the content_alignment values. The default is top_left.
      /// @remarks This property work only if expanded = false.
      xtd::forms::content_alignment align() const noexcept;
      /// @brief Sets a flag indicating how a control should be align to its containing layout container.
      /// @param align One of the content_alignment values. The default is top_left.
      /// @remarks This property work only if expanded = false.
      control_layout_style& align(xtd::forms::content_alignment align);
      /// @}
      
      /// @name Methods
      
      /// @{
      bool equals(const control_layout_style& value) const noexcept override;
      
      /// @brief Returns a string that represent xtd::forms::control_layout_style.
      /// @return A string containing that represent xtd::forms::control_layout_style.
      xtd::ustring to_string() const noexcept override;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
