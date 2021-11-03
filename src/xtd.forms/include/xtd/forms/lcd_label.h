/// @file
/// @brief Contains xtd::forms::lcd_label control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <codecvt>
#include <xtd/argument_out_of_range_exception.h>
#include <xtd/convert_string.h>
#include <xtd/as.h>
#include <xtd/interface.h>
#include "control.h"
#include "dot_matrix_display.h"
#include "lcd_style.h"
#include "nine_segment_display.h"
#include "seven_segment_display.h"
#include "fourteen_segment_display.h"
#include "sixteen_segment_display.h"

namespace xtd {
  namespace forms {
    /// @brief Represents a lcd label.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of lcd_label control.
    /// @include lcd_label.cpp
    /// @par Examples
    /// The following code example demonstrate the use of lcd_label control.
    /// @include lcd_label2.cpp
    class lcd_label : public control {
      class idigit interface_ {
      public:
        virtual wchar_t get_character() const = 0;
        virtual xtd::ustring get_valid_characters() const = 0;
        virtual int32_t get_thickness() const = 0;

        virtual void set_back_digit_color(const xtd::drawing::color& value) = 0;
        virtual void set_back_digit_opacity(double value) = 0;
        virtual void set_character(wchar_t value) = 0;
        virtual void set_segment_style(forms::segment_style value) = 0;
        virtual void set_dot_matrix_style(forms::dot_matrix_style value) = 0;
        virtual void set_show_back_digit(bool value) = 0;
        virtual void set_thickness(int32_t value) = 0;
      };

      class dot_matrix_display_digit : public dot_matrix_display, public idigit {
      public:
        dot_matrix_display_digit() = default;
        
        wchar_t get_character() const override;
        xtd::ustring get_valid_characters() const override;
        int32_t get_thickness() const override;
        
        void set_back_digit_color(const xtd::drawing::color& value) override;
        void set_back_digit_opacity(double value) override;
        void set_character(wchar_t value) override;
        void set_segment_style(forms::segment_style value) override;
        void set_dot_matrix_style(forms::dot_matrix_style value) override;
        void set_show_back_digit(bool value) override;
        void set_thickness(int32_t value) override;
        
      private:
        wchar_t character_ = ' ';
      };

      class fourteen_segment_display_digit : public fourteen_segment_display, public idigit {
      public:
        fourteen_segment_display_digit() = default;
        
        wchar_t get_character() const override;
        xtd::ustring get_valid_characters() const override;
        int32_t get_thickness() const override;
        
        void set_back_digit_color(const xtd::drawing::color& value) override;
        void set_back_digit_opacity(double value) override;
        void set_character(wchar_t value) override;
        void set_segment_style(forms::segment_style value) override;
        void set_dot_matrix_style(forms::dot_matrix_style value) override;
        void set_show_back_digit(bool value) override;
        void set_thickness(int32_t value) override;
        
      private:
        wchar_t character_ = ' ';
      };

      class nine_segment_display_digit : public nine_segment_display, public idigit {
      public:
        nine_segment_display_digit() = default;
        
        wchar_t get_character() const override;
        xtd::ustring get_valid_characters() const override;
        int32_t get_thickness() const override;
        
        void set_back_digit_color(const xtd::drawing::color& value) override;
        void set_back_digit_opacity(double value) override;
        void set_character(wchar_t value) override;
        void set_segment_style(forms::segment_style value) override;
        void set_dot_matrix_style(forms::dot_matrix_style value) override;
        void set_show_back_digit(bool value) override;
        void set_thickness(int32_t value) override;
        
      private:
        wchar_t character_ = ' ';
      };

      class seven_segment_display_digit : public seven_segment_display, public idigit {
      public:
        seven_segment_display_digit() = default;

        wchar_t get_character() const override;
        xtd::ustring get_valid_characters() const override;
        int32_t get_thickness() const override;

        void set_back_digit_color(const xtd::drawing::color& value) override;
        void set_back_digit_opacity(double value) override;
        void set_character(wchar_t value) override;
        void set_segment_style(forms::segment_style value) override;
        void set_dot_matrix_style(forms::dot_matrix_style value) override;
        void set_show_back_digit(bool value) override;
        void set_thickness(int32_t value) override;

      private:
        wchar_t character_ = ' ';
      };

      class sixteen_segment_display_digit : public sixteen_segment_display, public idigit {
      public:
        sixteen_segment_display_digit() = default;
        
        wchar_t get_character() const override;
        xtd::ustring get_valid_characters() const override;
        int32_t get_thickness() const override;
        
        void set_back_digit_color(const xtd::drawing::color& value) override;
        void set_back_digit_opacity(double value) override;
        void set_character(wchar_t value) override;
        void set_segment_style(forms::segment_style value) override;
        void set_dot_matrix_style(forms::dot_matrix_style value) override;
        void set_show_back_digit(bool value) override;
        void set_thickness(int32_t value) override;
        
      private:
        wchar_t character_ = ' ';
      };

    public:
      /// @brief Initialise a new lcd_label class.
      lcd_label();
      
      /// @brief Gets background digit color.
      /// @return A xtd::drawing color that represent the background digit color.
      /// @remarks Do not confuse back_digit_color and back_color. Background digit color is the color when digit is off.
      xtd::drawing::color back_digit_color() const;
      /// @brief Sets background digit color.
      /// @param value A xtd::drawing color that represent the background digit color.
      /// @return Current lcd_label.
      /// @remarks Do not confuse back_digit_color and back_color. Background digit color is the color when digit is off.
      lcd_label& back_digit_color(const xtd::drawing::color& value);
      
      /// @brief Gets the background digit opacity.
      /// @return A double-precision value between 0.0 and 1.0 that represent the background digit opacity.
      double back_digit_opacity() const;
      /// @brief Sets the background digit opacity.
      /// @param value A double-precision value between 0.0 and 1.0 that represent the background digit opacity.
      /// @exception xtd::argument_out_of_range_exception if value less than 0.0 or greater than 1.0.
      /// @return Current lcd_label.
      lcd_label& back_digit_opacity(double value);
      
      /// @brief Gets a value indicate if background digits are shown.
      /// @return true if background digits are shown; otherwise false
      bool show_back_digit() const;
      /// @brief Sets a value indicate if background digits are shown.
      /// @param value true if background digits are shown; otherwise false
      /// @return Current lcd_label.
      lcd_label& show_back_digit(bool value);

      /// @brief Gets the digit spacing.
      /// @return A int32_t represent the digit spacing.
      int32_t digit_spacing() const;
      /// @brief Sets the digit spacing.
      /// @param value A int32_t represent the digit spacing.
      /// @return Current lcd_label.
      /// @exception xtd::argument_out_of_range_exception if value less than 0.
      lcd_label& digit_spacing(int32_t value);
      
      /// @brief Gets lcd style.
      /// @return One of xtd::forms::lcd_style values. The default is xtd::forms::lcd_style::seven_segment_display.
      forms::lcd_style lcd_style() const;
      /// @brief Sets lcd style.
      /// @param value One of xtd::forms::lcd_style values. The default is xtd::forms::lcd_style::seven_segment_display.
      /// @return Current lcd_label.
      lcd_label& lcd_style(forms::lcd_style value);
      
      /// @brief Gets segment style.
      /// @return One of xtd::forms::segment_style values. The default is xtd::forms::segment_style::standard.
      forms::segment_style segment_style() const;
      /// @brief Sets segment style.
      /// @param value One of xtd::forms::segment_style values. The default is xtd::forms::segment_style::standard.
      /// @return Current lcd_label.
      lcd_label& segment_style(forms::segment_style value);
      
      /// @brief Gets dot matrix style.
      /// @return One of xtd::forms::dot_matrix_style values. The default is xtd::forms::dot_matrix_style::standard.
      forms::dot_matrix_style dot_matrix_style() const;
      /// @brief Sets dot matrix style.
      /// @param value One of xtd::forms::dot_matrix_style values. The default is xtd::forms::dot_matrix_style::standard.
      /// @return Current lcd_label.
      lcd_label& dot_matrix_style(forms::dot_matrix_style value);

      /// @brief Gets thickness of lcd.
      /// @return A int32_t that represent the lcd thickness.
      int32_t thickness() const;
      /// @brief Sets thickness of lcd.
      /// @param value A int32_t that represent the lcd thickness.
      /// @return Current lcd_label.
      lcd_label& thickness(int32_t value);

      using control::text;
      /// @brief Sets the text associated with this control.
      /// @param text The text associated with this control.
      /// @return Current control.
      control& text(const xtd::ustring& value) override;
      
      /// @brief Gets valid characters.
      /// @return A string that represent valid characters.
      /// @remarks The valid characters are different according to lcd_style.
      xtd::ustring valid_characters();

    protected:
      drawing::size default_size() const override;
      
      void on_back_color_changed(const event_args& e) override;
      
      void on_fore_color_changed(const event_args& e) override;

      void on_handle_created(const event_args& e) override;
      
      void on_size_changed(const event_args& e) override;
      
      void on_resize(const event_args& e) override;

      drawing::size measure_control() const override;

    private:
      void on_digit_click(object& sender, const event_args& e);
      void on_digit_mouse_down(object& sender, const mouse_event_args& e);
      void on_digit_mouse_move(object& sender, const mouse_event_args& e);
      void on_digit_mouse_up(object& sender, const mouse_event_args& e);
      void set_digits_params();

      bool show_back_digit_ = true;
      std::optional<xtd::drawing::color> back_digit_color_;
      double back_digit_opacity_ = 0.95;
      std::optional<int32_t> digit_spacing_;
      forms::lcd_style lcd_style_ = forms::lcd_style::seven_segment_display;
      forms::segment_style segment_style_ = forms::segment_style::standard;
      forms::dot_matrix_style dot_matrix_style_ = forms::dot_matrix_style::standard;
      std::vector<std::shared_ptr<idigit>> digits_;
      std::optional<int32_t> thickness_;
    };
  }
}
