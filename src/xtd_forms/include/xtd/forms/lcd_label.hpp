#include "control.hpp"
#include "lcd_style.hpp"
#include "nine_segment_display.hpp"
#include "seven_segment_display.hpp"
#include "fourteen_segment_display.hpp"
#include "sixteen_segment_display.hpp"

namespace xtd {
  namespace forms {
    class lcd_label : public control {
      class idigit {
      public:
        ~idigit() = default;

        virtual wchar_t get_character() const = 0;
        virtual ustring get_valid_characters() const = 0;
        virtual int32_t get_thickness() const = 0;

        virtual void set_background_digit_transparency(double value) = 0;
        virtual void set_character(wchar_t value) = 0;
        virtual void set_segment_style(forms::segment_style value) = 0;
        virtual void set_show_background_digit(bool value) = 0;
        virtual void set_thickness(int32_t value) = 0;
      };

      class seven_segment_display_digit : public seven_segment_display, public idigit {
      public:
        seven_segment_display_digit() = default;

        wchar_t get_character() const override {return character_;}
        ustring get_valid_characters() const override {return "0123456789AaBbCcDdEeFfGgHhIiJjLlNnOoPpQqRrSsTtUuYy=-_°\"'[]| .,:";}
        int32_t get_thickness() const override {return seven_segment_display::thickness();}

        void set_background_digit_transparency(double value) override {seven_segment_display::background_segment_transparency(value);}
        void set_character(wchar_t value) override {
          static std::map<wchar_t, forms::segments> characters {{'0', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f}, {'1', forms::segments::b | forms::segments::c}, {'2', forms::segments::a | forms::segments::b | forms::segments::d | forms::segments::e | forms::segments::g}, {'3', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::g}, {'4', forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g}, {'5', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'6', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'7', forms::segments::a | forms::segments::b | forms::segments::c}, {'8', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'9', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'A', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g}, {'a', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g}, {'B', forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'b', forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'C', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f}, {'c', forms::segments::d | forms::segments::e | forms::segments::g}, {'D', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g}, {'d', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g}, {'E', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'e', forms::segments::a | forms::segments::b | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'F', forms::segments::a | forms::segments::e | forms::segments::f | forms::segments::g}, {'f', forms::segments::a | forms::segments::e | forms::segments::f | forms::segments::g}, {'G', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f}, {'g', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'H', forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g}, {'h', forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g}, {'I', forms::segments::b | forms::segments::c}, {'i', forms::segments::c}, {'J', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e}, {'j', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e}, {'L', forms::segments::d | forms::segments::e | forms::segments::f}, {'l', forms::segments::d | forms::segments::e}, {'N', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f}, {'n', forms::segments::c | forms::segments::e | forms::segments::g}, {'O', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f}, {'o', forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g}, {'P', forms::segments::a | forms::segments::b | forms::segments::e | forms::segments::f | forms::segments::g}, {'p', forms::segments::a | forms::segments::b | forms::segments::e | forms::segments::f | forms::segments::g}, {'Q', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g}, {'q', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g}, {'R', forms::segments::a | forms::segments::e | forms::segments::f}, {'r', forms::segments::e | forms::segments::g}, {'S', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'s', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'T', forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'t', forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'U', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f}, {'u', forms::segments::c | forms::segments::d | forms::segments::e}, {'Y', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'y', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'=', forms::segments::d | forms::segments::g}, {'-', forms::segments::g}, {'_', forms::segments::d}, {L'°', forms::segments::a | forms::segments::b | forms::segments::f | forms::segments::g}, {'"', forms::segments::b | forms::segments::f}, {'\'', forms::segments::f}, {'[', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f}, {']', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d}, {'|', forms::segments::b | forms::segments::c}, {' ', forms::segments::none}, {'.', forms::segments::dp}, {',', forms::segments::dp}, {':', forms::segments::pc}};
          if (character_ != value) {
            if (characters.find(value) == characters.end()) throw std::invalid_argument(strings::format("Only characters : \"{}\" are valid", get_valid_characters()));
            character_ = value;
            seven_segment_display::value(characters[value]);
          }
        }
        void set_segment_style(forms::segment_style value) override {seven_segment_display::segment_style(value);}
        void set_show_background_digit(bool value) override {seven_segment_display::show_background_segment(value);}
        void set_thickness(int32_t value) override {seven_segment_display::thickness(value);}

      private:
        wchar_t character_ = ' ';
      };

      class nine_segment_display_digit : public nine_segment_display, public idigit {
      public:
        nine_segment_display_digit() = default;
        
        wchar_t get_character() const override {return character_;}
        ustring get_valid_characters() const override {return "0123456789AaBbCcDdEeFfGgHhIiJjLlNnOoPpQqRrSsTtUuYy=-_°\"'[]| .,:";}
        int32_t get_thickness() const override {return nine_segment_display::thickness();}

        void set_background_digit_transparency(double value) override {nine_segment_display::background_segment_transparency(value);}
        void set_character(wchar_t value) override {
          static std::map<wchar_t, forms::segments> characters {{'0', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f}, {'1', forms::segments::b | forms::segments::c}, {'2', forms::segments::a | forms::segments::b | forms::segments::d | forms::segments::i}, {'3', forms::segments::a | forms::segments::g | forms::segments::h | forms::segments::i}, {'4', forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g}, {'5', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'6', forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g | forms::segments::h}, {'7', forms::segments::a | forms::segments::e | forms::segments::h}, {'8', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'9', forms::segments::a | forms::segments::b | forms::segments::f | forms::segments::g | forms::segments::i}, {'A', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g}, {'a', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g}, {'B', forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'b', forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'C', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f}, {'c', forms::segments::d | forms::segments::e | forms::segments::g}, {'D', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g}, {'d', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g}, {'E', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'e', forms::segments::a | forms::segments::b | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'F', forms::segments::a | forms::segments::e | forms::segments::f | forms::segments::g}, {'f', forms::segments::a | forms::segments::e | forms::segments::f | forms::segments::g}, {'G', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f}, {'g', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'H', forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g}, {'h', forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g}, {'I', forms::segments::b | forms::segments::c}, {'i', forms::segments::c}, {'J', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e}, {'j', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e}, {'L', forms::segments::d | forms::segments::e | forms::segments::f}, {'l', forms::segments::d | forms::segments::e}, {'N', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f}, {'n', forms::segments::c | forms::segments::e | forms::segments::g}, {'O', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f}, {'o', forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g}, {'P', forms::segments::a | forms::segments::b | forms::segments::e | forms::segments::f | forms::segments::g}, {'p', forms::segments::a | forms::segments::b | forms::segments::e | forms::segments::f | forms::segments::g}, {'Q', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g}, {'q', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g}, {'R', forms::segments::a | forms::segments::e | forms::segments::f}, {'r', forms::segments::e | forms::segments::g}, {'S', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'s', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'T', forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'t', forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g}, {'U', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f}, {'u', forms::segments::c | forms::segments::d | forms::segments::e}, {'Y', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'y', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g}, {'=', forms::segments::d | forms::segments::g}, {'-', forms::segments::g}, {'_', forms::segments::d}, {L'°', forms::segments::a | forms::segments::b | forms::segments::f | forms::segments::g}, {'"', forms::segments::b | forms::segments::f}, {'\'', forms::segments::f}, {'[', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f}, {']', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d}, {'|', forms::segments::b | forms::segments::c}, {' ', forms::segments::none}, {'.', forms::segments::dp}, {',', forms::segments::dp}, {':', forms::segments::pc}};
          if (character_ != value) {
            if (characters.find(value) == characters.end()) throw std::invalid_argument(strings::format("Only characters : \"{}\" are valid", get_valid_characters()));
            character_ = value;
            nine_segment_display::value(characters[value]);
          }
        }
        void set_segment_style(forms::segment_style value) override {nine_segment_display::segment_style(value);}
        void set_show_background_digit(bool value) override {nine_segment_display::show_background_segment(value);}
        void set_thickness(int32_t value) override {seven_segment_display::thickness(value);}

      private:
        wchar_t character_ = ' ';
      };

      class fourteen_segment_display_digit : public fourteen_segment_display, public idigit {
      public:
        fourteen_segment_display_digit() = default;
        
        wchar_t get_character() const override {return character_;}
        ustring get_valid_characters() const override {return "0123456789AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz=+-*\\_°\"'[]()| .,:";}
        int32_t get_thickness() const override {return fourteen_segment_display::thickness();}
        
        void set_background_digit_transparency(double value) override {fourteen_segment_display::background_segment_transparency(value);}
        void set_character(wchar_t value) override {
          static std::map<wchar_t, forms::segments> characters {
            {'0', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f},
            {'1', forms::segments::b | forms::segments::c | forms::segments::j},
            {'2', forms::segments::a | forms::segments::b | forms::segments::d | forms::segments::e | forms::segments::g1 | forms::segments::g2},
            {'3', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::g2},
            {'4', forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'5', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'6', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::e| forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'7', forms::segments::a | forms::segments::l | forms::segments::j},
            {'8', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g1 | segments::g2},
            {'9', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'A', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'a', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g1 | forms::segments::g2},
            {'B', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d  | forms::segments::g2 | forms::segments::i | forms::segments::l},
            {'b', forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::m},
            {'C', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f},
            {'c', forms::segments::d | forms::segments::e | forms::segments::g1 | forms::segments::g2},
            {'D', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d  | forms::segments::i | forms::segments::l},
            {'d', forms::segments::b | forms::segments::c | forms::segments::d | segments::g2 | segments::k},
            {'E', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'e', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g1},
            {'F', forms::segments::a | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'f', forms::segments::a | forms::segments::e | forms::segments::f | forms::segments::g1},
            {'G', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g2},
            {'g', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::h | forms::segments::g2},
            {'H', forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'h', forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'I', forms::segments::a | forms::segments::d | forms::segments::i | forms::segments::l},
            {'i', forms::segments::l},
            {'J', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e},
            {'j', forms::segments::b | forms::segments::c | forms::segments::d},
            {'K', forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::j | forms::segments::m},
            {'k', forms::segments::i | forms::segments::l | forms::segments::j | forms::segments::m},
            {'L', forms::segments::d | forms::segments::e | forms::segments::f},
            {'l', forms::segments::i | forms::segments::l},
            {'M', forms::segments::b| forms::segments::c| forms::segments::e| forms::segments::f| forms::segments::h| forms::segments::j},
            {'m', forms::segments::c| forms::segments::e| forms::segments::g1| forms::segments::g2| forms::segments::l},
            {'N', forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::h | forms::segments::m},
            {'n', forms::segments::e | forms::segments::g1 | forms::segments::m},
            {'O', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f},
            {'o', forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::g1 | forms::segments::g2},
            {'P', forms::segments::a | forms::segments::b | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'p', forms::segments::a | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::j},
            {'Q', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::m},
            {'q', forms::segments::a | forms::segments::b | forms::segments::f | forms::segments::g1 | forms::segments::g2 | forms::segments::m},
            {'R', forms::segments::a | forms::segments::b | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2 | forms::segments::m},
            {'r', forms::segments::e | forms::segments::g},
            {'S', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::g2 | forms::segments::h},
            {'s', forms::segments::a | forms::segments::c | forms::segments::d | forms::segments::g2 | forms::segments::h},
            {'T', forms::segments::a | forms::segments::i | forms::segments::l},
            {'t', forms::segments::d | forms::segments::e | forms::segments::f | forms::segments::g1},
            {'U', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::e | forms::segments::f},
            {'u', forms::segments::c | forms::segments::d | forms::segments::e},
            {'V', forms::segments::e | forms::segments::f | forms::segments::j | forms::segments::k},
            {'v', forms::segments::e | forms::segments::k},
            {'W', forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::k | forms::segments::m},
            {'w', forms::segments::c | forms::segments::e | forms::segments::k | forms::segments::m},
            {'X', forms::segments::h | forms::segments::j | forms::segments::k | forms::segments::m},
            {'x', forms::segments::h | forms::segments::j | forms::segments::k | forms::segments::m},
            {'Y', forms::segments::h | forms::segments::j | forms::segments::l},
            {'y', forms::segments::b | forms::segments::c | forms::segments::d | forms::segments::g2 | forms::segments::i},
            {'Z', forms::segments::a | forms::segments::d | forms::segments::j | forms::segments::k},
            {'z', forms::segments::a | forms::segments::d | forms::segments::j | forms::segments::k},
            {'=', forms::segments::d | forms::segments::g1 | forms::segments::g2},
            {'+', forms::segments::g1 | forms::segments::g2 | forms::segments::i | forms::segments::l},
            {'-', forms::segments::g1 | forms::segments::g2},
            {'*', forms::segments::g1 | forms::segments::g2 | forms::segments::h | forms::segments::i | forms::segments::j | forms::segments::k | forms::segments::l | forms::segments::m},
            {'\\', forms::segments::h | forms::segments::m},
            {'_', forms::segments::d},
            {L'°', forms::segments::a | forms::segments::b | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'"', forms::segments::b | forms::segments::f},
            {'\'', forms::segments::f},
            {'[', forms::segments::a | forms::segments::d | forms::segments::e | forms::segments::f},
            {']', forms::segments::a | forms::segments::b | forms::segments::c | forms::segments::d},
            {'(', forms::segments::j | forms::segments::m},
            {')', forms::segments::h | forms::segments::k},
            {'|', forms::segments::i | forms::segments::l},
            {' ', forms::segments::none},
            {'.', forms::segments::dp},
            {',', forms::segments::k},
            {':', forms::segments::pc}
          };
          if (character_ != value) {
            if (characters.find(value) == characters.end()) throw std::invalid_argument(strings::format("Only characters : \"{}\" are valid", get_valid_characters()));
            character_ = value;
            fourteen_segment_display::value(characters[value]);
          }
        }
        void set_segment_style(forms::segment_style value) override {fourteen_segment_display::segment_style(value);}
        void set_show_background_digit(bool value) override {fourteen_segment_display::show_background_segment(value);}
        void set_thickness(int32_t value) override {seven_segment_display::thickness(value);}
        
      private:
        wchar_t character_ = ' ';
      };

      class sixteen_segment_display_digit : public sixteen_segment_display, public idigit {
      public:
        sixteen_segment_display_digit() = default;
        
        wchar_t get_character() const override {return character_;}
        ustring get_valid_characters() const override {return "0123456789AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz=+-*\\_°\"'[]()| .,:";}
        int32_t get_thickness() const override {return sixteen_segment_display::thickness();}
        
        void set_background_digit_transparency(double value) override {sixteen_segment_display::background_segment_transparency(value);}
        void set_character(wchar_t value) override {
          static std::map<wchar_t, forms::segments> characters {
            {'0', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f},
            {'1', forms::segments::b | forms::segments::c | forms::segments::j},
            {'2', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::g1 | forms::segments::g2},
            {'3', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::g2},
            {'4', forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'5', forms::segments::a1 | forms::segments::a2 | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'6', forms::segments::a1 | forms::segments::a2 | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e| forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'7', forms::segments::a1 | forms::segments::a2 | forms::segments::l | forms::segments::j},
            {'8', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f | forms::segments::g1 | segments::g2},
            {'9', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'A', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'a', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::g1 | forms::segments::g2},
            {'B', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d  | forms::segments::g2 | forms::segments::i | forms::segments::l},
            {'b', forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::m},
            {'C', forms::segments::a1 | forms::segments::a2 | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f},
            {'c', forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::g1 | forms::segments::g2},
            {'D', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d  | forms::segments::i | forms::segments::l},
            {'d', forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | segments::g2 | segments::k},
            {'E', forms::segments::a1 | forms::segments::a2 | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'e', forms::segments::a1 | forms::segments::a2 | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f | forms::segments::g1},
            {'F', forms::segments::a1 | forms::segments::a2 | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'f', forms::segments::a1 | forms::segments::a2 | forms::segments::e | forms::segments::f | forms::segments::g1},
            {'G', forms::segments::a1 | forms::segments::a2 | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f | forms::segments::g2},
            {'g', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::h | forms::segments::g2},
            {'H', forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'h', forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'I', forms::segments::a1 | forms::segments::a2 | forms::segments::d1 | forms::segments::d2 | forms::segments::i | forms::segments::l},
            {'i', forms::segments::l},
            {'J', forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e},
            {'j', forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2},
            {'K', forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::j | forms::segments::m},
            {'k', forms::segments::i | forms::segments::l | forms::segments::j | forms::segments::m},
            {'L', forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f},
            {'l', forms::segments::i | forms::segments::l},
            {'M', forms::segments::b| forms::segments::c| forms::segments::e| forms::segments::f| forms::segments::h| forms::segments::j},
            {'m', forms::segments::c| forms::segments::e| forms::segments::g1| forms::segments::g2| forms::segments::l},
            {'N', forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::h | forms::segments::m},
            {'n', forms::segments::e | forms::segments::g1 | forms::segments::m},
            {'O', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f},
            {'o', forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::g1 | forms::segments::g2},
            {'P', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'p', forms::segments::a1 | forms::segments::a2 | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::j},
            {'Q', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f | forms::segments::m},
            {'q', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::f | forms::segments::g1 | forms::segments::g2 | forms::segments::m},
            {'R', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::e | forms::segments::f | forms::segments::g1 | forms::segments::g2 | forms::segments::m},
            {'r', forms::segments::e | forms::segments::g},
            {'S', forms::segments::a1 | forms::segments::a2 | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::g2 | forms::segments::h},
            {'s', forms::segments::a1 | forms::segments::a2 | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::g2 | forms::segments::h},
            {'T', forms::segments::a1 | forms::segments::a2 | forms::segments::i | forms::segments::l},
            {'t', forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f | forms::segments::g1},
            {'U', forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f},
            {'u', forms::segments::c | forms::segments::d1 | forms::segments::d2 | forms::segments::e},
            {'V', forms::segments::e | forms::segments::f | forms::segments::j | forms::segments::k},
            {'v', forms::segments::e | forms::segments::k},
            {'W', forms::segments::b | forms::segments::c | forms::segments::e | forms::segments::f | forms::segments::k | forms::segments::m},
            {'w', forms::segments::c | forms::segments::e | forms::segments::k | forms::segments::m},
            {'X', forms::segments::h | forms::segments::j | forms::segments::k | forms::segments::m},
            {'x', forms::segments::h | forms::segments::j | forms::segments::k | forms::segments::m},
            {'Y', forms::segments::h | forms::segments::j | forms::segments::l},
            {'y', forms::segments::b | forms::segments::c | forms::segments::d2 | forms::segments::g2 | forms::segments::i},
            {'Z', forms::segments::a1 | forms::segments::a2 | forms::segments::d1 | forms::segments::d2 | forms::segments::j | forms::segments::k},
            {'z', forms::segments::g1 | forms::segments::d1 | forms::segments::k},
            {'=', forms::segments::d1 | forms::segments::d2 | forms::segments::g1 | forms::segments::g2},
            {'+', forms::segments::g1 | forms::segments::g2 | forms::segments::i | forms::segments::l},
            {'-', forms::segments::g1 | forms::segments::g2},
            {'*', forms::segments::g1 | forms::segments::g2 | forms::segments::h | forms::segments::i | forms::segments::j | forms::segments::k | forms::segments::l | forms::segments::m},
            {'\\', forms::segments::h | forms::segments::m},
            {'_', forms::segments::d1 | forms::segments::d2},
            {L'°', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::f | forms::segments::g1 | forms::segments::g2},
            {'"', forms::segments::b | forms::segments::f},
            {'\'', forms::segments::f},
            {'[', forms::segments::a1 | forms::segments::a2 | forms::segments::d1 | forms::segments::d2 | forms::segments::e | forms::segments::f},
            {']', forms::segments::a1 | forms::segments::a2 | forms::segments::b | forms::segments::c | forms::segments::d1 | forms::segments::d2},
            {'(', forms::segments::j | forms::segments::m},
            {')', forms::segments::h | forms::segments::k},
            {'|', forms::segments::i | forms::segments::l},
            {' ', forms::segments::none},
            {'.', forms::segments::dp},
            {',', forms::segments::k},
            {':', forms::segments::pc}
          };
          if (character_ != value) {
            if (characters.find(value) == characters.end()) throw std::invalid_argument(strings::format("Only characters : \"{}\" are valid", get_valid_characters()));
            character_ = value;
            sixteen_segment_display::value(characters[value]);
          }
        }
        void set_segment_style(forms::segment_style value) override {sixteen_segment_display::segment_style(value);}
        void set_show_background_digit(bool value) override {sixteen_segment_display::show_background_segment(value);}
        void set_thickness(int32_t value) override {sixteen_segment_display::thickness(value);}
        
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

      int32_t digit_spacing() const {return digit_spacing_.value_or(thickness());}
      lcd_label& digit_spacing(int32_t value) {
        if (value < 0) throw std::invalid_argument("value must be positive");
        if (digit_spacing_ != value) {
          digit_spacing_ = value;
          set_digits_params();
        }
        return *this;
      }
      
      forms::lcd_style lcd_style() const {return lcd_style_;}
      lcd_label& lcd_style(forms::lcd_style value) {
        if (lcd_style_ != value) {
          lcd_style_ = value;
          ustring current_text = text();
          text("");
          text(current_text);
        }
        return *this;
      }
      
      forms::segment_style segment_style() const {return segment_style_;}
      lcd_label& segment_style(forms::segment_style value) {
        if (segment_style_ != value) {
          segment_style_ = value;
          for (auto& digit : digits_)
            digit->set_segment_style(value);
        }
        return *this;
      }
      
      int32_t thickness() const {return thickness_.value_or(digits_.size() ? digits_[0]->get_thickness() : 0);}
      lcd_label& thickness(int32_t value) {
        if (thickness_ != value) {
          thickness_ = value;
          set_digits_params();
        }
        return *this;
      }

      using control::text;
      control& text(const ustring& value) override {
        if (text_ != value) {
          std::wstring str = value.wstr();
          if (str.size() < digits_.size())
            digits_.erase(digits_.begin() + value.size(), digits_.end());
          if (str.size() > digits_.size())
            for (size_t index = digits_.size(); index < str.size(); index++) {
              switch (lcd_style_) {
                case lcd_style::seven_segment_display: digits_.push_back(std::make_shared<seven_segment_display_digit>()); break;
                case lcd_style::nine_segment_display: digits_.push_back(std::make_shared<nine_segment_display_digit>()); break;
                case lcd_style::fourteen_segment_display: digits_.push_back(std::make_shared<fourteen_segment_display_digit>()); break;
                case lcd_style::sixteen_segment_display: digits_.push_back(std::make_shared<sixteen_segment_display_digit>()); break;
                default: throw std::invalid_argument("lcd_style invalid");
              }
              dynamic_cast<control*>(digits_[digits_.size() - 1].get())->parent(*this);
              dynamic_cast<control*>(digits_[digits_.size() - 1].get())->click += [this] {on_click(event_args::empty);};
              dynamic_cast<control*>(digits_[digits_.size() - 1].get())->mouse_down += [this](control& sender, const mouse_event_args& e) {on_mouse_down(mouse_event_args(e.button(), e.location() + drawing::size(sender.location()), e.clicks(), e.delta()));};
              dynamic_cast<control*>(digits_[digits_.size() - 1].get())->mouse_move += [this](control& sender, const mouse_event_args& e) {on_mouse_move(mouse_event_args(e.button(), e.location() + drawing::size(sender.location()), e.clicks(), e.delta()));};
              dynamic_cast<control*>(digits_[digits_.size() - 1].get())->mouse_up += [this](control& sender, const mouse_event_args& e) {on_mouse_up(mouse_event_args(e.button(), e.location() + drawing::size(sender.location()), e.clicks(), e.delta()));};
            }
          for (size_t index = 0; index < str.size(); index++)
            digits_[index]->set_character(str[index]);
          set_digits_params();
          control::text(value);
        }
        return *this;
      }
      
      ustring valid_characters() {
        switch (lcd_style_) {
          case lcd_style::seven_segment_display: return std::make_shared<seven_segment_display_digit>()->get_valid_characters();
          case lcd_style::nine_segment_display: return std::make_shared<nine_segment_display_digit>()->get_valid_characters();
          case lcd_style::fourteen_segment_display: return std::make_shared<fourteen_segment_display_digit>()->get_valid_characters();
          case lcd_style::sixteen_segment_display: return std::make_shared<sixteen_segment_display_digit>()->get_valid_characters();
          default: throw std::invalid_argument("lcd_style invalid");
        }
      }

    protected:
      drawing::size default_size() const override {return {100, 25};}

      void set_digits_params() {
        int32_t offset_left = 0;
        for (auto& digit : digits_) {
          dynamic_cast<control*>(digit.get())->height(size_.height());
          dynamic_cast<control*>(digit.get())->left(offset_left);
          digit->set_background_digit_transparency(background_digit_transparency_);
          digit->set_show_background_digit(show_background_digit_);
          digit->set_segment_style(segment_style_);
          digit->set_thickness(thickness());
          offset_left += dynamic_cast<control*>(digit.get())->width() - 2 + digit_spacing();
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
        return drawing::size((dynamic_cast<control*>(digits_[0].get())->width() - 2 + digit_spacing()) * static_cast<int32_t>(digits_.size()) - digit_spacing() + 2, size_.height());
      }

    private:
      bool show_background_digit_ = true;
      double background_digit_transparency_ = 0.10;
      std::optional<int32_t> digit_spacing_;
      forms::lcd_style lcd_style_ = forms::lcd_style::seven_segment_display;
      forms::segment_style segment_style_ = forms::segment_style::standard;
      std::vector<std::shared_ptr<idigit>> digits_;
      std::optional<int32_t> thickness_;
    };
  }
}
