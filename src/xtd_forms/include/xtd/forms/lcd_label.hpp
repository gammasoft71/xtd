#include "control.hpp"
#include "seven_segment_display.hpp"

namespace xtd {
  namespace forms {
    class lcd_label : public control {
      class idigit {
      public:
        ~idigit() = default;
        virtual wchar_t character() const = 0;
        virtual idigit& character(wchar_t value) = 0;
        virtual ustring valid_characters() const = 0;
      };

      class seven_segment_display_digit : public seven_segment_display, idigit {
      public:
        seven_segment_display_digit() = default;
        
        wchar_t character() const override {return character_;}
        idigit& character(wchar_t value) override {
          static std::map<wchar_t, forms::segments> characters {{'0', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f}, {'1', forms::segments::b | forms::segments::c}, {'2', forms::segments::a | forms::segments::b | forms::segments::d | forms::segments::e | forms::segments::g}, {'3', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::g}, {'4', forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g}, {'5', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'6', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'7', forms::segments::a | forms::segments::b | forms::segments::c}, {'8', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'9', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'A', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g}, {'a', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g}, {'B', forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'b', forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'C', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f}, {'c', forms::segments::d | forms::segments::e | forms::segments::g}, {'D', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g}, {'d', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g}, {'E', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'e', forms::segments::a | forms::segments::b | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'F', forms::segments::a | forms::segments::e | forms::segments::f | forms::segments::g}, {'f', forms::segments::a | forms::segments::e | forms::segments::f | forms::segments::g}, {'G', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f}, {'g', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'H', forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g}, {'h', forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g}, {'I', forms::segments::b | forms::segments::c}, {'i', forms::segments::c}, {'J', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e}, {'j', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e}, {'L', forms::segments::d | forms::segments::e | forms::segments::f}, {'l', forms::segments::d | forms::segments::e}, {'N', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f}, {'n', forms::segments::c | forms::segments::e | forms::segments::g}, {'O', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f}, {'o', forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g}, {'P', forms::segments::a | forms::segments::b | forms::segments::e | forms::segments::f | forms::segments::g}, {'p', forms::segments::a | forms::segments::b | forms::segments::e | forms::segments::f | forms::segments::g}, {'Q', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g}, {'q', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g}, {'R', forms::segments::a | forms::segments::e | forms::segments::f}, {'r', forms::segments::e | forms::segments::g}, {'S', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'s', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'T', forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'t', forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'U', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f}, {'u', forms::segments::c | forms::segments::d | forms::segments::e}, {'Y', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'y', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'=', forms::segments::d | forms::segments::g}, {'-', forms::segments::g}, {'_', forms::segments::d}, {L'°', forms::segments::a | forms::segments::b | forms::segments::f | forms::segments::g}, {'"', forms::segments::b | forms::segments::f}, {'\'', forms::segments::f}, {'[', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f}, {']', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d}, {'|', forms::segments::b | forms::segments::c}, {' ', forms::segments::none}, {'.', forms::segments::dp}, {',', forms::segments::dp}, {':', forms::segments::pc}};
          if (character_ != value) {
            if (characters.find(value) == characters.end()) throw std::invalid_argument(strings::format("Only characters : \"{}\" are valid", valid_characters()));
            character_ = value;
            seven_segment_display::value(characters[value]);
          }
          return *this;
        }
        
        ustring valid_characters() const override {return "0123456789AaBbCcDdEeFfGgHhIiJjLlNnOoPpQqRrSsTtUuYy=-_°\"'[]| .,:";}

      private:
        wchar_t character_ = ' ';
      };

    public:
      lcd_label() {
        auto_size_mode_ = forms::auto_size_mode::grow_and_shrink;
        size_ = default_size();
      }
      
      double background_digit_transparency() const {return background_digit_transparency_;}
      lcd_label& background_digit_transparency(double value) {
        if (value < 0.0 && value > 1.0) throw std::invalid_argument("value must be between 0.0 and 1.0.");
        if (background_digit_transparency_ != value) {
          background_digit_transparency_ = value;
          set_digits_params();
        }
        return *this;
      }
      
      bool show_background_digit() const {return show_background_digit_;}
      lcd_label& show_background_digit(bool value) {
        if (show_background_digit_ != value) {
          show_background_digit_ = value;
          set_digits_params();
        }
        return *this;
      }

      uint32_t digit_spacing() const {return digit_spacing_;}
      lcd_label& digit_spacing(uint32_t value) {
        if (digit_spacing_ != value) {
          digit_spacing_ = value;
          set_digits_params();
        }
        return *this;
      }
      
      forms::segment_style segment_style() const {return segment_style_;}
      lcd_label& segment_style(forms::segment_style value) {
        if (segment_style_ != value) {
          segment_style_ = value;
          for (auto& digit : digits_)
            digit->segment_style(value);
        }
        return *this;
      }
      
      using control::text;
      control& text(const ustring& value) override {
        if (text_ != value) {
          if (value.size() < digits_.size())
            digits_.erase(digits_.begin() + value.size(), digits_.end());
          if (value.size() > digits_.size())
            for (size_t index = digits_.size(); index < value.size(); index++) {
              digits_.push_back(control::create<seven_segment_display_digit>(*this));
              digits_[digits_.size() - 1]->click += [this] {on_click(event_args::empty);};
              digits_[digits_.size() - 1]->mouse_down += [this](control& sender, const mouse_event_args& e) {on_mouse_down(mouse_event_args(e.button(), e.location() + drawing::size(sender.location()), e.clicks(), e.delta()));};
              digits_[digits_.size() - 1]->mouse_move += [this](control& sender, const mouse_event_args& e) {on_mouse_move(mouse_event_args(e.button(), e.location() + drawing::size(sender.location()), e.clicks(), e.delta()));};
              digits_[digits_.size() - 1]->mouse_up += [this](control& sender, const mouse_event_args& e) {on_mouse_up(mouse_event_args(e.button(), e.location() + drawing::size(sender.location()), e.clicks(), e.delta()));};
            }
          std::wstring str = value.wstr();
          for (size_t index = 0; index < str.size(); index++)
            digits_[index]->character(str[index]);
          set_digits_params();
          control::text(value);
        }
        return *this;
      }
      
      static ustring valid_characters() {return seven_segment_display_digit().valid_characters();}

    protected:
      drawing::size default_size() const override {return {100, 25};}

      void set_digits_params() {
        int32_t offset_left = 0;
        for (auto& digit : digits_) {
          digit->background_digit_transparency(background_digit_transparency_);
          digit->show_background_digit(show_background_digit_);
          digit->segment_style(segment_style_);
          digit->height(size_.height());
          digit->left(offset_left);
          offset_left += digit->width() - 2 + digit_spacing_;
        }
      }
      
      void on_handle_created(const event_args& e) override {
        control::on_handle_created(e);
        set_digits_params();
      }
      
      void on_size_changed(const event_args& e) override {
        set_digits_params();
        control::on_size_changed(e);
      }
      
      void on_resize(const event_args& e) override {
        set_digits_params();
        control::on_resize(e);
      }

      drawing::size measure_control() const override {
        if (digits_.size() == 0) return {0, size_.height()};
        return drawing::size((digits_[0]->width() - 2 + digit_spacing_) * static_cast<int32_t>(digits_.size()) - digit_spacing_ + 2, size_.height());
      }

    private:
      bool show_background_digit_ = true;
      double background_digit_transparency_ = 0.10;
      uint32_t digit_spacing_ = 4;
      forms::segment_style segment_style_ = forms::segment_style::standard;
      std::vector<std::shared_ptr<seven_segment_display_digit>> digits_;
    };
  }
}
