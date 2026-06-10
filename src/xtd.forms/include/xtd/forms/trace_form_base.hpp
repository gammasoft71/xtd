/// @file
/// @brief Contains xtd::forms::trace_form_base dialog.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "form.hpp"
#include "text_box.hpp"
#include <xtd/drawing/font_family>
#include <xtd/date_time>

/// @cond
auto __xtd_forms_trace_form_base_default_form_name__() noexcept -> xtd::string&;
auto __xtd_forms_trace_form_base_default_text_box_name__() noexcept -> xtd::string&;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
  
    /// @brief Represents a base form for debug_form and trace_form forms. This class cannot be instantiated.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/trace_form_base>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms debug
    class trace_form_base : public xtd::forms::form {
      struct data;
      
    public:
      /// @name Public Properties
      
      /// @{
      using xtd::forms::form::dock;
      auto dock(xtd::forms::dock_style dock) -> xtd::forms::control& override;
      
      /// @brief Gets the string used to separate date and/or time from trace text.
      /// @return A string that represent separator. By default is "|".
      [[nodiscard]] virtual auto header_separator() const noexcept -> const xtd::string&;
      /// @brief Sets the string used to separate date and/or time from trace text.
      /// @param value A string that represent separator. By default is "|".
      /// @return Current trace_form_base.
      virtual auto header_separator(const xtd::string& value) -> trace_form_base&;
      
      [[nodiscard]] auto name() const noexcept -> const xtd::string& override;
      
      /// @brief Gets a value indicate if date is showing before trace text.
      /// @return `true` is date showing; otherwise `false`. By default is `true`.
      [[nodiscard]] virtual auto show_date() const noexcept -> bool;
      /// @brief Sets a value indicate if date is showing before trace text.
      /// @param value `true` is date showing; otherwise `false`. By default is `true`.
      /// @return Current trace_form_base.
      virtual auto show_date(bool value) -> trace_form_base&;
      
      /// @brief Gets a value indicate if time is showing before trace text.
      /// @return `true` is time showing; otherwise `false`. By default is `true`.
      [[nodiscard]] virtual auto show_time() const noexcept -> bool;
      /// @brief Sets a value indicate if time is showing before trace text.
      /// @param value `true` is time showing; otherwise `false`. By default is `true`.
      /// @return Current trace_form_base.
      virtual auto show_time(bool value) -> trace_form_base&;
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initializes a new instance of the trace_form_base class with specified caption text.
      /// @param text A string that represent the caption text oof the debug form.
      explicit trace_form_base(const xtd::string& text);
      /// @}
 
      /// @name Protected Prperties
      
      /// @{
      /// @brief Gets a value indicate if header need written.
      /// @return `true` if header needed; otherwise `false`.
      /// @remarks After each line terminator, header was needed.
      [[nodiscard]] virtual auto need_header() const -> bool;
      /// @brief Sets a value indicate if header need written.
      /// @param value `true` if header needed; otherwise `false`.
      /// @remarks After each line terminator, header was needed.
      /// @return Current trace_form_base.
      virtual auto need_header(bool value) -> trace_form_base&;
      /// @}

      /// @name Protected Methods
      
      /// @{
      auto on_back_color_changed(const xtd::event_args& e) -> void override;
      auto on_fore_color_changed(const xtd::event_args& e) -> void override;
      
      /// @brief Writes trace string to the multiline text.
      /// @param trace A string to write.
      virtual auto write(const xtd::string& trace) -> void;
      
      /// @brief Writes trace string to the multiline text followed by a line terminator.
      /// @param trace A string to write.
      virtual auto write_line(const xtd::string& trace) -> void;
      
      /// @brief Writes header, if needed. Writes date and/or time and header_separator.
      /// @param trace A string to write.
      virtual auto write_header() -> void;
      /// @}
      
    private:
      using form::name;
      
      auto update_format() -> void;
      
      xtd::sptr<data> data_;
    };
  }
}
