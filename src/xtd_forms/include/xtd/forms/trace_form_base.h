#pragma once
#include "form.h"
#include "text_box.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
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
      
      bool show_date() const {return show_date_;}
      void show_date(bool value) {
        if (show_date_ != value) {
          show_date_ = value;
          update_format();
        }
      }
      
      bool show_time() const {return show_time_;}
      void show_time(bool value) {
        if (show_time_ != value) {
          show_time_ = value;
          update_format();
        }
      }

    protected:
      trace_form_base(const std::string& text) {
        dock(xtd::forms::dock_style::bottom);
        start_position(xtd::forms::form_start_position::manual);
        this->text(text);
        
        text_.dock(xtd::forms::dock_style::fill);
        text_.multiline(true);
        text_.parent(*this);
        text_.read_only(true);
        text_.word_wrap(false);
        update_format();
      }
      
      virtual void write_trace(const std::string& trace) {text_.append_text(xtd::strings::format(format_, trace, std::chrono::system_clock::now()));}
      
    private:
      void update_format() {
        format_ = "{0}";
        if (show_date_ && show_time_) format_ = "{1:u}: " + format_;
        else if (show_date_) format_ = "{1:L}-{1:k}-{1:i}: " + format_;
        else if (show_time_) format_ = "{1:t}: " + format_;
      }

      bool show_date_ = true;
      bool show_time_ = true;
      std::string format_ = "{0}";
      xtd::forms::text_box text_;
    };
  }
}
