#include <array>
#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace calculator {
  class form_main : public form {
    enum class operators {
      none = -1,
      divide,
      multiply,
      subtract,
      add,
      equal
    };
    
  public:
    // The main entry point for the application.
    static void main() {
      application::enable_visual_styles();
      application::run(form_main());
    }
    
    form_main() {
      text("Calculator");
      back_color(drawing::color::from_argb(44, 44, 47));
      fore_color(drawing::color::white);
      form_border_style(forms::form_border_style::fixed_dialog);
      maximize_box(false);
      start_position(form_start_position::manual);
      location({300, 200});
      client_size({325, 220});
      //key_preview(true);
      key_press += {*this, &form_main::form_main_key_press};
      
      result.parent(*this);
      result.bounds({5, 5, 315, 60});
      result.font(xtd::drawing::font(xtd::drawing::font_family::generic_monospace().name(), 36, xtd::drawing::font_style::regular));
      result.text_align(content_alignment::middle_right);
      result.text("0");
      
      button_clear.parent(*this);
      button_clear.back_color(drawing::color::from_argb(76, 81, 78));
      button_clear.flat_style(xtd::forms::flat_style::flat);
      button_clear.location({5, 70});
      button_clear.text("AC");
      button_clear.size({75, 25});
      button_clear.click += {*this, &form_main::button_clear_click};
      
      button_plus_minus.parent(*this);
      button_plus_minus.back_color(drawing::color::from_argb(76, 81, 78));
      button_plus_minus.flat_style(xtd::forms::flat_style::flat);
      button_plus_minus.location({85, 70});
      button_plus_minus.text("±");
      button_plus_minus.size({75, 25});
      button_plus_minus.click += {*this, &form_main::button_plus_minus_click};
      
      button_percent.parent(*this);
      button_percent.back_color(drawing::color::from_argb(76, 81, 78));
      button_percent.flat_style(xtd::forms::flat_style::flat);
      button_percent.location({165, 70});
      button_percent.text("%");
      button_percent.size({75, 25});
      button_percent.click += {*this, &form_main::button_percent_click};
      
      button_decimal.parent(*this);
      button_decimal.back_color(drawing::color::from_argb(105, 110, 107));
      button_decimal.flat_style(xtd::forms::flat_style::flat);
      button_decimal.location({165, 190});
      button_decimal.text(",");
      button_decimal.size({75, 25});
      button_decimal.click += {*this, &form_main::button_number_click};
      
      vector<xtd::drawing::point> button_number_locations = {{5, 190}, {5, 160}, {85, 160}, {165, 160}, {5, 130}, {85, 130}, {165, 130}, {5, 100}, {85, 100}, {165, 100}};
      for (int i = 0; i < 10; i++) {
        button_numbers[i].parent(*this);
        button_numbers[i].back_color(drawing::color::from_argb(105, 110, 107));
        button_numbers[i].flat_style(xtd::forms::flat_style::flat);
        button_numbers[i].text(strings::format("{}", i));
        button_numbers[i].location(button_number_locations[i]);
        button_numbers[i].size({75, 25});
        button_numbers[i].click += {*this, &form_main::button_number_click};
      }
      button_numbers[0].width(155);
      
      vector button_operator_texts = {"/", "X", "-", "+", "="};
      vector<xtd::drawing::point> button_operator_locations = {{245, 70}, {245, 100}, {245, 130}, {245, 160}, {245, 190}};
      for (int i = 0; i < 5; i++) {
        button_operators[i].parent(*this);
        button_operators[i].back_color(drawing::color::from_argb(255, 159, 11));
        button_operators[i].flat_style(xtd::forms::flat_style::flat);
        button_operators[i].text(button_operator_texts[i]);
        button_operators[i].location(button_operator_locations[i]);
        button_operators[i].size({75, 25});
        button_operators[i].click += {*this, &form_main::button_operator_click};
      }
    }
    
    void form_main_key_press(control& sender, key_press_event_args& e) {
      if (e.key_char() >= '0' && e.key_char() <= '9') {
        button_number_click(button_numbers[e.key_char() - '0'], e);
        e.handled(true);
        return;
      }
      switch (e.key_char()) {
        case 'c' : button_clear_click(button_clear, e); e.handled(true); break;
        case 'C' : button_clear_click(button_clear, e); e.handled(true); break;
        case '%' : button_percent_click(button_percent, e); e.handled(true); break;
        case ',' : button_number_click(button_percent,e); e.handled(true); break;
        case '.' : button_number_click(button_percent, e); e.handled(true); break;
        case '/' : button_operator_click(button_operators[(int)operators::divide], e); e.handled(true); break;
        case '*' : button_operator_click(button_operators[(int)operators::multiply], e); e.handled(true); break;
        case '-' : button_operator_click(button_operators[(int)operators::subtract], e); e.handled(true); break;
        case '+' : button_operator_click(button_operators[(int)operators::add], e); e.handled(true); break;
        case '=' : button_operator_click(button_operators[(int)operators::equal], e); e.handled(true); break;
        case 13 : button_operator_click(button_operators[(int)operators::equal], e); e.handled(true); break;
        case 127 : back_space_key_press(button_operators[(int)operators::equal], e); e.handled(true); break;
      }
    }
    
    void back_space_key_press(control& sender, const event_args& e) {
      if (result.text().length() > 0)
        result.text(strings::remove(result.text(), result.text().length()-1));
      if (result.text().length() == 0 || result.text() == "-")
        button_clear_click(sender, e);
    }
    
    void button_clear_click(control& sender, const event_args& e) {
      result.text("0");
      first_operand = .0f;
      operation = operators::none;
      reset_result = true;
    }
    
    void button_percent_click(control& sender, const event_args& e) {
      ;
      result.text(strings::replace(strings::format("{}", (parse<double>(strings::replace(result.text(), ',', '.')) / 100)), '.', ','));
    }
    
    void button_plus_minus_click(control& sender, const event_args& e) {
      result.text(strings::replace(strings::format("{}", -parse<double>(strings::replace(result.text(), ',', '.'))), '.', ','));
    }
    
    void button_number_click(control& sender, const event_args& e) {
      if (sender.handle() == button_decimal.handle() && strings::contains(result.text(), ",")) return;
      if (sender.handle() == button_numbers[0].handle() && !strings::contains(result.text(), ",") && parse<double>(result.text()) == 0) return;
      if (reset_result) {
        reset_result = false;
        if (sender.handle() != button_decimal.handle()) result.text("");
      }
      result.text(result.text() + sender.text());
    }
    
    void button_operator_click(control& sender, const event_args& e) {
      reset_result = true;
      if (operation == operators::none) {
        first_operand = parse<double>(strings::replace(result.text(), ',', '.'));
      } else {
        switch (operation) {
          case operators::divide: result.text(strings::replace(strings::format("{}", first_operand / parse<double>(strings::replace(result.text(), ',', '.'))), '.', ',')); break;
          case operators::multiply: result.text(strings::replace(strings::format("{}", first_operand * parse<double>(strings::replace(result.text(), ',', '.'))), '.', ',')); break;
          case operators::subtract: result.text(strings::replace(strings::format("{}", first_operand - parse<double>(strings::replace(result.text(), ',', '.'))), '.', ',')); break;
          case operators::add: result.text(strings::replace(strings::format("{}", first_operand + parse<double>(strings::replace(result.text(), ',', '.'))), '.', ',')); break;
          default: break;
        }
        first_operand = parse<double>(result.text());
      }
      
      switch (sender.text()[0]) {
        case '/': operation = operators::divide; break;
        case 'X': operation = operators::multiply; break;
        case '-': operation = operators::subtract; break;
        case '+': operation = operators::add; break;
        case '=': break;
        default: operation = operators::none; break;
      }
    }
    
  private:
    label result;
    button button_clear;
    button button_plus_minus;
    button button_percent;
    button button_decimal;
    array<button, 10> button_numbers;
    array<button, 5> button_operators;
    double first_operand = .0f;
    bool reset_result = true;
    operators operation = operators::none;
  };
}

startup_(calculator::form_main);
