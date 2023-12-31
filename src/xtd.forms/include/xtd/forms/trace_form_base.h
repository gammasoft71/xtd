/// @file
/// @brief Contains xtd::forms::trace_form_base dialog.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "form.h"
#include "text_box.h"
#include <xtd/drawing/font_family>
#include <xtd/date_time>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a base form for debug_form and trace_form forms. This class cannot be instantiated.
    /// @par Header
    /// @code #include <xtd/forms/trace_form_base> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms debug
    class trace_form_base : public xtd::forms::form {
      struct data;
      
    public:
      /// @name Properties
      
      /// @{
      xtd::forms::control& dock(xtd::forms::dock_style dock) override;
      
      /// @brief Gets the string used to separate date and/or time from trace text.
      /// @return A string that represent separator. By default is "|".
      virtual const xtd::ustring& header_separator() const noexcept;
      /// @brief Sets the string used to separate date and/or time from trace text.
      /// @param header_separator A string that represent separator. By default is "|".
      /// @return Current trace_form_base.
      virtual trace_form_base& header_separator(const xtd::ustring& header_separator);
      
      const xtd::ustring& name() const noexcept override;
      
      /// @brief Gets a value indicate if date is showing before trace text.
      /// @return true is date showing; otherwise false. By default is true.
      virtual bool show_date() const noexcept;
      /// @brief Sets a value indicate if date is showing before trace text.
      /// @param value true is date showing; otherwise false. By default is true.
      /// @return Current trace_form_base.
      virtual trace_form_base& show_date(bool value);
      
      /// @brief Gets a value indicate if time is showing before trace text.
      /// @return true is time showing; otherwise false. By default is true.
      virtual  bool show_time() const noexcept;
      /// @brief Sets a value indicate if time is showing before trace text.
      /// @param value true is time showing; otherwise false. By default is true.
      /// @return Current trace_form_base.
      virtual trace_form_base& show_time(bool value);
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initializes a new instance of the trace_form_base class with specified caption text.
      /// @param text A string that represent the caption text oof the debug form.
      explicit trace_form_base(const xtd::ustring& text);
      /// @}
      
      /// @name Protected methods
      
      /// @{
      void on_back_color_changed(const xtd::event_args& e) override;
      void on_fore_color_changed(const xtd::event_args& e) override;
      
      /// @brief Writes trace string to the multiline text.
      /// @param trace A string to write.
      virtual void write(const xtd::ustring& trace);
      
      /// @brief Writes trace string to the multiline text followed by a line terminator.
      /// @param trace A string to write.
      virtual void write_line(const xtd::ustring& trace);
      
      /// @brief Writes header, if needed. Writes date and/or time and header_separator.
      /// @param trace A string to write.
      virtual void write_header();
      
      /// @brief Gets a value indicate if header need written.
      /// @return true if header needed; otherwise false.
      /// @remarks After each line terminator, header was needed.
      virtual bool need_header() const;
      /// @brief Sets a value indicate if header need written.
      /// @param value true if header needed; otherwise false.
      /// @remarks After each line terminator, header was needed.
      /// @return Current trace_form_base.
      virtual trace_form_base& need_header(bool value);
      /// @}
      
    private:
      using form::name;
      
      void update_format();
      
      std::shared_ptr<data> data_;
    };
  }
}
