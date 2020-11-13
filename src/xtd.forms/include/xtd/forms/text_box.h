#pragma once
#include "border_style.h"
#include "character_casing.h"
#include "text_box_base.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class text_box : public text_box_base {
    public:
      text_box();

      virtual bool accepts_return() const {return accepts_return_;}
      virtual text_box_base& accepts_return(bool value) {
        if (accepts_return_ != value) {
          accepts_return_ = value;
          recreate_handle();
          on_accepts_return_changed(event_args::empty);
        }
        return *this;
      }
      
      virtual forms::border_style border_style() const {return this->border_style_;}
      virtual text_box& border_style(forms::border_style border_style);
      
      virtual xtd::forms::character_casing character_casing() const {return character_casing_;}
      virtual text_box& character_casing(xtd::forms::character_casing value);

      drawing::color default_back_color() const override {return xtd::forms::theme_colors::current_theme().text_box();}
      
      drawing::color default_fore_color() const override {return xtd::forms::theme_colors::current_theme().text_box_text();}
      
      drawing::size default_size() const override {return {100, 21};}

      virtual bool multiline() const {return multiline_;}
      virtual text_box& multiline(bool value);
      
      virtual char32_t password_char() const {return password_char_;}
      virtual text_box& password_char(char32_t value);
      
      using text_box_base::selection_length;
      size_t selection_length() const override;

      using text_box_base::selection_start;
      size_t selection_start() const override;
      
      const std::string& text() const override;
      control& text(const std::string& text) override;
      
      virtual bool use_system_password_char() const {return use_system_password_char_;}
      virtual text_box& use_system_password_char(bool value);
      
      event<text_box, event_handler<control&>> accepts_return_changed;

      void append_text(const std::string& value) override;
      
      void select(size_t start, size_t length) override;

    protected:
      forms::create_params create_params() const override;
      
      drawing::size measure_control() const override;
      
      virtual void on_accepts_return_changed(const event_args& e) {if (can_raise_events()) accepts_return_changed(*this, e);}

      void on_handle_created(const event_args& e) override;
      
      void on_text_changed(const event_args& e) override;
      
      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      void wnd_proc(message& message) override;

      /// @cond
      void wm_key_char(message& message);
      void wm_set_text(message& message);
      /// @endcond

      bool accepts_return_ = false;
      xtd::forms::border_style border_style_ = xtd::forms::border_style::fixed_single;
      xtd::forms::character_casing character_casing_ = xtd::forms::character_casing::normal;
      bool multiline_ = false;
      char32_t password_char_ = 0;
      bool use_system_password_char_ = false;
    };
  }
}
