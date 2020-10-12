#pragma once
#include "control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class text_box_base : public control {
    public:      
      forms::cursor default_cursor() const override {return forms::cursors::ibeam();}

      virtual bool accepts_tab() const {return accepts_tab_;}
      virtual text_box_base& accepts_tab(bool value) {
        if (accepts_tab_ != value) {
          accepts_tab_ = value;
          recreate_handle();
          on_accepts_tab_changed(event_args::empty);
        }
        return *this;
      }

      virtual bool read_only() const {return read_only_;}
      virtual text_box_base& read_only(bool value) {
        if (read_only_ != value) {
          read_only_ = value;
          recreate_handle();
          on_read_only_changed(event_args::empty);
        }
        return *this;
      }

      virtual size_t selection_length() const {return selection_length_;}
      virtual text_box_base& selection_length(size_t value) {
        select(selection_start_, value);
        return *this;
      }
      
      virtual size_t selection_start() const {return selection_start_;}
      virtual text_box_base& selection_start(size_t value) {
        select(value, selection_length_);
        return *this;
      }
      
      virtual bool word_wrap() const {return word_wrap_;}
      virtual text_box_base& word_wrap(bool value) {
        if (word_wrap_ != value) {
          word_wrap_ = value;
          recreate_handle();
        }
        return *this;
      }
      
      event<text_box_base, event_handler<control&>> accepts_tab_changed;
      event<text_box_base, event_handler<control&>> read_only_changed;

      virtual void append_text(const std::string& value) {
        suspend_layout();
        text(text() + value);
        select(text().size(), 0);
        resume_layout();
      }
      
      void clear() {
        text("");
      }
      
      std::vector<std::string> lines() const {
        return strings::split(text(), {'\n'});
      }
      
      void lines(const std::vector<std::string>& lines) {
        append_text(strings::join("\n", lines));
      }
      
      virtual void select(size_t start, size_t length) {
        if (selection_start_ != start || length != selection_length_) {
          if (start > text().size()) throw std::invalid_argument("start greater than text size");
          if (start + length > text().size()) throw std::invalid_argument("start + lenght greater than text size");
          selection_start_ = start;
          selection_length_ = length;
        }
      }
      
      void select_all() {
        select(0, text().size());
      }

    protected:
      text_box_base() = default;
      virtual void on_accepts_tab_changed(const event_args& e) {if (can_raise_events()) accepts_tab_changed(*this, e);}
      virtual void on_read_only_changed(const event_args& e) {if (can_raise_events()) read_only_changed(*this, e);}
      bool accepts_tab_ = false;
      bool read_only_ = false;
      bool word_wrap_ = false;
      mutable size_t selection_start_ = 0;
      mutable size_t selection_length_ = 0;
    };
  }
}
