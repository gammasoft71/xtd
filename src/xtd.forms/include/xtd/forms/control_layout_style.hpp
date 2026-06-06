/// @file
/// @brief Contains xtd::forms::control_layout_style class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "content_alignment.hpp"
#include "size_type.hpp"
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Implements the basic functionality that represents the appearance and behavior of a control layout.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/conrol_layout_style>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class control_layout_style : public xtd::object, public xtd::iequatable<control_layout_style> {
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
      /// @param expanded `true` if control expanded; otherwise `false`.
      explicit control_layout_style(bool expanded);
      /// @brief Initialises a new instance of control layout style class with specified content alignment.
      /// @param expanded `true` if control expanded; otherwise `false`.
      /// @param align One of the content_alignment values..
      explicit control_layout_style(xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of control layout style class with specified size type and expanded.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container.
      /// @param expanded `true` if control expanded; otherwise `false`.
      control_layout_style(xtd::forms::size_type size_type, bool expanded);
      /// @brief Initialises a new instance of control layout style class with specified size type and content alignment.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container.
      /// @param align One of the content_alignment values.
      control_layout_style(xtd::forms::size_type size_type, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of control layout style class with specified size type, expanded and content alignment.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container.
      /// @param expanded `true` if control expanded; otherwise `false`.
      /// @param align One of the content_alignment values.
      control_layout_style(xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align);
      /// @brief Initialises a new instance of control layout style class with specified expanded and content alignment.
      /// @param expanded `true` if control expanded; otherwise `false`.
      /// @param align One of the content_alignment values..
      control_layout_style(bool expanded, xtd::forms::content_alignment align);
      /// @}
      
    public:
      /// @cond
      control_layout_style(const control_layout_style& other);
      control_layout_style& operator =(const control_layout_style& other);
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a flag indicating how a control should be sized relative to its containing layout container.
      /// @return One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::absolute.
      [[nodiscard]] auto size_type() const noexcept -> xtd::forms::size_type;
      /// @brief Sets a flag indicating how a control should be sized relative to its containing layout container.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::absolute.
      auto size_type(xtd::forms::size_type size_type) -> control_layout_style&;
      
      /// @brief Gets a flag indicating if control is expanded to its containing layout container.
      /// @return `true` if control expanded; otherwise `false`. The default is `false`.
      [[nodiscard]] auto expanded() const noexcept -> bool;
      /// @brief Sets a flag indicating if control is expanded to its containing layout container.
      /// @param expanded `true` if control expanded; otherwise `false`. The default is `false`.
      auto expanded(bool expanded) -> control_layout_style&;
      
      /// @brief Gets a flag indicating how a control should be align to its containing layout container.
      /// @return align One of the content_alignment values. The default is top_left.
      /// @remarks This property work only if expanded = `false`.
      [[nodiscard]] auto align() const noexcept -> xtd::forms::content_alignment;
      /// @brief Sets a flag indicating how a control should be align to its containing layout container.
      /// @param align One of the content_alignment values. The default is top_left.
      /// @remarks This property work only if expanded = `false`.
      auto align(xtd::forms::content_alignment align) -> control_layout_style&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const xtd::object& obj) const noexcept -> bool override;
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param other The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const control_layout_style& other) const noexcept -> bool override;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
      
      /// @brief Returns a string that represent xtd::forms::control_layout_style.
      /// @return A string containing that represent xtd::forms::control_layout_style.
      [[nodiscard]] auto to_string() const noexcept -> xtd::string override;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
