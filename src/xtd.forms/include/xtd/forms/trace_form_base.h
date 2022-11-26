/// @file
/// @brief Contains xtd::forms::trace_form_base dialog.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/drawing/font_family.h>
#include <xtd/date_time.h>
#include "form.h"
#include "text_box.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a base form for debug_form and trace_form forms. This class cannot be instantiated.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms debug
    class trace_form_base : public xtd::forms::form {
    public:
      /// @name Properties
      
      /// @{
      xtd::forms::control& dock(xtd::forms::dock_style dock) override {
        if (dock == xtd::forms::dock_style::left) bounds({xtd::forms::screen::get_working_area(handle()).left(), xtd::forms::screen::get_working_area(handle()).top(), xtd::forms::screen::get_working_area(handle()).width() / 4, xtd::forms::screen::get_working_area(handle()).height()});
        else if (dock == xtd::forms::dock_style::top) bounds({xtd::forms::screen::get_working_area(handle()).left(), xtd::forms::screen::get_working_area(handle()).top(), xtd::forms::screen::get_working_area(handle()).width(), xtd::forms::screen::get_working_area(handle()).height() / 4});
        else if (dock == xtd::forms::dock_style::right) bounds({xtd::forms::screen::get_working_area(handle()).left() + xtd::forms::screen::get_working_area(handle()).width() - xtd::forms::screen::get_working_area(handle()).width() / 4, xtd::forms::screen::get_working_area(handle()).top(), xtd::forms::screen::get_working_area(handle()).width() / 4, xtd::forms::screen::get_working_area(handle()).height()});
        else if (dock == xtd::forms::dock_style::bottom) bounds({xtd::forms::screen::get_working_area(handle()).left(), xtd::forms::screen::get_working_area(handle()).top() + xtd::forms::screen::get_working_area(handle()).height() - xtd::forms::screen::get_working_area(handle()).height() / 4, xtd::forms::screen::get_working_area(handle()).width(), xtd::forms::screen::get_working_area(handle()).height() / 4});
        else if (dock == xtd::forms::dock_style::fill) bounds({xtd::forms::screen::get_working_area(handle()).left(), xtd::forms::screen::get_working_area(handle()).top(), xtd::forms::screen::get_working_area(handle()).width(), xtd::forms::screen::get_working_area(handle()).height()});
        return xtd::forms::control::dock(dock);
      }
      
      /// @brief Gets the string used to separate date and/or time from trace text.
      /// @return A string that represent separator. By default is "|".
      virtual const xtd::ustring& header_separator() const {return header_separator_;}
      /// @brief Sets the string used to separate date and/or time from trace text.
      /// @param header_separator A string that represent separator. By default is "|".
      /// @return Current trace_form_base.
      virtual trace_form_base& header_separator(const xtd::ustring& header_separator) {
        if (header_separator != header_separator_) {
          header_separator_ = header_separator;
          update_format();
        }
        return *this;
      }
      
      const xtd::ustring& name() const noexcept override {return form::name();}
      
      /// @brief Gets a value indicate if date is showing before trace text.
      /// @return true is date showing; otherwise false. By default is true.
      virtual bool show_date() const {return show_date_;}
      /// @brief Sets a value indicate if date is showing before trace text.
      /// @param value true is date showing; otherwise false. By default is true.
      /// @return Current trace_form_base.
      virtual trace_form_base& show_date(bool value) {
        if (show_date_ != value) {
          show_date_ = value;
          update_format();
        }
        return *this;
      }
      
      /// @brief Gets a value indicate if time is showing before trace text.
      /// @return true is time showing; otherwise false. By default is true.
      virtual  bool show_time() const {return show_time_;}
      /// @brief Sets a value indicate if time is showing before trace text.
      /// @param value true is time showing; otherwise false. By default is true.
      /// @return Current trace_form_base.
      virtual trace_form_base& show_time(bool value) {
        if (show_time_ != value) {
          show_time_ = value;
          update_format();
        }
        return *this;
      }
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initializes a new instance of the trace_form_base class with specified caption text.
      /// @param text A string that represent the caption text oof the debug form.
      trace_form_base(const xtd::ustring& text) {
        close_box(false);
        minimize_box(false);
        name("9f5767d6-7a21-4ebe-adfe-2427b2024a55");
        show_in_taskbar(false);
        text_.name("d014d407-851c-49c1-a343-3380496a639a");
        
        dock(xtd::forms::dock_style::bottom);
        start_position(xtd::forms::form_start_position::manual);
        font(xtd::drawing::font(xtd::drawing::font_family::generic_monospace(), font().size()));
        this->text(text);
        
        text_.dock(xtd::forms::dock_style::fill);
        text_.multiline(true);
        text_.parent(*this);
        text_.read_only(true);
        text_.word_wrap(false);
        update_format();
      }
      /// @}
      
      /// @name Protected methods
      
      /// @{
      void on_back_color_changed(const xtd::event_args& e) override {
        text_.back_color(back_color());
      }
      
      void on_fore_color_changed(const xtd::event_args& e) override {
        text_.fore_color(fore_color());
      }
      
      /// @brief Writes trace string to the multiline text.
      /// @param trace A string to write.
      virtual void write(const xtd::ustring& trace) {
        if (need_header()) write_header();
        text_.append_text(trace);
      }
      
      /// @brief Writes trace string to the multiline text followed by a line terminator.
      /// @param trace A string to write.
      virtual void write_line(const xtd::ustring& trace) {
        write(trace);
        write(environment::new_line());
        need_header(true);
      }
      
      /// @brief Writes header, if needed. Writes date and/or time and header_separator.
      /// @param trace A string to write.
      virtual void write_header() {
        auto now =  xtd::date_time::now();
        text_.append_text(xtd::ustring::format(format_, now, (now.ticks() / 10 % 1000000).count(), header_separator_));
        need_header_ = false;
      }
      
      /// @brief Gets a value indicate if header need written.
      /// @return true if header needed; otherwise false.
      /// @remarks After each line terminator, header was needed.
      virtual bool need_header() const {return need_header_;}
      /// @brief Sets a value indicate if header need written.
      /// @param value true if header needed; otherwise false.
      /// @remarks After each line terminator, header was needed.
      /// @return Current trace_form_base.
      virtual trace_form_base& need_header(bool value) {
        if (need_header_ != value)
          need_header_ = value;
        return *this;
      }
      /// @}
      
    private:
      using form::name;
      
      void update_format() {
        format_ = "";
        if (show_date_ && show_time_) format_ = "{0:u}.{1:D6}{2}" + format_;
        else if (show_date_) format_ = "{0:L}-{0:k}-{0:i}{2}" + format_;
        else if (show_time_) format_ = "{0:t}.{1:D6}{2}" + format_;
      }
      
      bool need_header_ = true;
      bool show_date_ = true;
      bool show_time_ = true;
      xtd::ustring format_ = "{0}";
      xtd::ustring header_separator_ = "|";
      xtd::forms::text_box text_;
    };
  }
}
