/// @file
/// @brief Contains xtd::forms::trace_form_base dialog.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <chrono>
#include <xtd/drawing/font_family.h>
#include "form.h"
#include "text_box.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a base form for debug_form and trace_form forms. This class cannot be instantiated.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms debug
    class trace_form_base : public xtd::forms::form {
    public:
      xtd::forms::control& dock(xtd::forms::dock_style dock) override {
        if (dock == xtd::forms::dock_style::left) bounds({xtd::forms::screen::get_working_area(handle_).left(), xtd::forms::screen::get_working_area(handle_).top(), xtd::forms::screen::get_working_area(handle_).width() / 4, xtd::forms::screen::get_working_area(handle_).height()});
        else if (dock == xtd::forms::dock_style::top) bounds({xtd::forms::screen::get_working_area(handle_).left(), xtd::forms::screen::get_working_area(handle_).top(), xtd::forms::screen::get_working_area(handle_).width(), xtd::forms::screen::get_working_area(handle_).height() / 4});
        else if (dock == xtd::forms::dock_style::right) bounds({xtd::forms::screen::get_working_area(handle_).left() + xtd::forms::screen::get_working_area(handle_).width() - xtd::forms::screen::get_working_area(handle_).width() / 4, xtd::forms::screen::get_working_area(handle_).top(), xtd::forms::screen::get_working_area(handle_).width() / 4, xtd::forms::screen::get_working_area(handle_).height()});
        else if (dock == xtd::forms::dock_style::bottom) bounds({xtd::forms::screen::get_working_area(handle_).left(), xtd::forms::screen::get_working_area(handle_).top() + xtd::forms::screen::get_working_area(handle_).height() - xtd::forms::screen::get_working_area(handle_).height() / 4, xtd::forms::screen::get_working_area(handle_).width(), xtd::forms::screen::get_working_area(handle_).height() / 4});
        else if (dock == xtd::forms::dock_style::fill) bounds({xtd::forms::screen::get_working_area(handle_).left(), xtd::forms::screen::get_working_area(handle_).top(), xtd::forms::screen::get_working_area(handle_).width(), xtd::forms::screen::get_working_area(handle_).height()});
        return xtd::forms::control::dock(dock);
      }
      
      /// @brief Gets the string used to separate date and/or time from trace text.
      /// @return A string that represent separator. By default is "|".
      virtual const xtd::ustring& header_separator() const {return header_separator_;}
      /// @brief Sets the string used to separate date and/or time from trace text.
      /// @param header_separator A string that represent separator. By default is "|".
      /// @return Current trace_form_base.
      virtual trace_form_base& header_separator(const xtd::ustring& header_separator) {
        if (header_separator_ != header_separator_) {
          header_separator_ = header_separator;
          update_format();
        }
        return *this;
      }

      const xtd::ustring& name() const override {return form::name();}
      
      /// @brief Gets a vallue indicate if date is showing before trace text.
      /// @return true is date showing; otherwise false. By default is true.
      virtual bool show_date() const {return show_date_;}
      /// @brief Sets a vallue indicate if date is showing before trace text.
      /// @param value true is date showing; otherwise false. By default is true.
      /// @return Current trace_form_base.
      virtual trace_form_base& show_date(bool value) {
        if (show_date_ != value) {
          show_date_ = value;
          update_format();
        }
        return *this;
      }
      
      /// @brief Gets a vallue indicate if time is showing before trace text.
      /// @return true is time showing; otherwise false. By default is true.
      virtual  bool show_time() const {return show_time_;}
      /// @brief Sets a vallue indicate if time is showing before trace text.
      /// @param value true is time showing; otherwise false. By default is true.
      /// @return Current trace_form_base.
      virtual trace_form_base& show_time(bool value) {
        if (show_time_ != value) {
          show_time_ = value;
          update_format();
        }
        return *this;
      }

   protected:
      /// @brief Initializes a new instance of the trace_form_base class with spefied caption text.
      /// @param text A string that represent the caption text oof the debug form.
      trace_form_base(const xtd::ustring& text) {
        name("9f5767d6-7a21-4ebe-adfe-2427b2024a55");
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
      
      void on_form_closing(form_closing_event_args& e) override {
        e.cancel(true);
        window_state(form_window_state::minimized);
        form::on_form_closing(e);
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
        text_.append_text(environment::new_line());
        need_header(true);
      }
      
      /// @brief Writes header, if needed. Writes date and/or time and header_separtor.
      /// @param trace A string to write.
      virtual void write_header() {
        auto now =  std::chrono::system_clock::now();
        text_.append_text(xtd::ustring::format(format_, now, (std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch())).count() % 1000000, header_separator_));
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
