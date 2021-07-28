#include <array>
#include <xtd/xtd>

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
    static void main() {
      application::run(form_main());
    }
    
    form_main() {
      text("Calculator");
      back_color(drawing::color::from_argb(44, 44, 47));
      fore_color(drawing::color::white);
      font(xtd::drawing::font(xtd::drawing::font_family::generic_sans_serif(), 15));
      auto_size_mode(forms::auto_size_mode::grow_and_shrink);
      auto_size(true);
      key_press += key_press_event_handler(*this, &form_main::form_main_key_press);
      
      result.bounds({0, 0, 240, 60});
      result.font(xtd::drawing::font(font(), font().size() * 2));
      result.parent(*this);
      result.text_align(content_alignment::middle_right);
      result.text("0");
      
      button_clear.parent(*this);
      button_clear.back_color(drawing::color::from_argb(64, 64, 64));
      button_clear.flat_appearance().mouse_down_back_color(drawing::color::from_argb(102, 102, 102));
      button_clear.flat_appearance().mouse_over_back_color(drawing::color::from_argb(64, 64, 64));
      button_clear.flat_appearance().border_color(drawing::color::from_argb(44, 44, 47));
      button_clear.flat_style(xtd::forms::flat_style::flat);
      button_clear.location({0, 60});
      button_clear.text("C");
      button_clear.size({60, 50});
      button_clear.click += event_handler(*this, &form_main::button_clear_click);
      
      button_plus_minus.parent(*this);
      button_plus_minus.back_color(drawing::color::from_argb(64, 64, 64));
      button_plus_minus.flat_appearance().mouse_down_back_color(drawing::color::from_argb(102, 102, 102));
      button_plus_minus.flat_appearance().mouse_over_back_color(drawing::color::from_argb(64, 64, 64));
      button_plus_minus.flat_appearance().border_color(drawing::color::from_argb(44, 44, 47));
      button_plus_minus.flat_style(xtd::forms::flat_style::flat);
      button_plus_minus.location({60, 60});
      //button_plus_minus.text("±");
      button_plus_minus.text("+/-");
      button_plus_minus.size({60, 50});
      button_plus_minus.click += event_handler(*this, &form_main::button_plus_minus_click);
      
      button_percent.parent(*this);
      button_percent.back_color(drawing::color::from_argb(64, 64, 64));
      button_percent.flat_appearance().mouse_down_back_color(drawing::color::from_argb(102, 102, 102));
      button_percent.flat_appearance().mouse_over_back_color(drawing::color::from_argb(64, 64, 64));
      button_percent.flat_appearance().border_color(drawing::color::from_argb(44, 44, 47));
      button_percent.flat_style(xtd::forms::flat_style::flat);
      button_percent.location({120, 60});
      button_percent.text("%");
      button_percent.size({60, 50});
      button_percent.click += event_handler(*this, &form_main::button_percent_click);
      
      button_decimal.parent(*this);
      button_decimal.back_color(drawing::color::from_argb(102, 102, 102));
      button_decimal.flat_appearance().mouse_down_back_color(drawing::color::from_argb(144, 144, 144));
      button_decimal.flat_appearance().mouse_over_back_color(drawing::color::from_argb(102, 102, 102));
      button_decimal.flat_appearance().border_color(drawing::color::from_argb(44, 44, 47));
      button_decimal.flat_style(xtd::forms::flat_style::flat);
      button_decimal.location({120, 260});
      button_decimal.text(".");
      button_decimal.size({60, 50});
      button_decimal.click += event_handler(*this, &form_main::button_number_click);
      
      vector<xtd::drawing::point> button_number_locations = {{0, 260}, {0, 210}, {60, 210}, {120, 210}, {0, 160}, {60, 160}, {120, 160}, {0, 110}, {60, 110}, {120, 110}};
      for (int i = 0; i < 10; i++) {
        button_numbers[i].parent(*this);
        button_numbers[i].back_color(drawing::color::from_argb(102, 102, 102));
        button_numbers[i].flat_appearance().mouse_down_back_color(drawing::color::from_argb(144, 144, 144));
        button_numbers[i].flat_appearance().mouse_over_back_color(drawing::color::from_argb(102, 102, 102));
        button_numbers[i].flat_appearance().border_color(drawing::color::from_argb(44, 44, 47));
        button_numbers[i].flat_style(xtd::forms::flat_style::flat);
        button_numbers[i].text(ustring::format("{}", i));
        button_numbers[i].location(button_number_locations[i]);
        button_numbers[i].size({60, 50});
        button_numbers[i].click += event_handler(*this, &form_main::button_number_click);
      }
      button_numbers[0].width(120);
      
      vector button_operator_texts = {"÷", "x", "-", "+", "="};
      vector<xtd::drawing::point> button_operator_locations = {{180, 60}, {180, 110}, {180, 160}, {180, 210}, {180, 260}};
      for (int i = 0; i < 5; i++) {
        button_operators[i].parent(*this);
        button_operators[i].back_color(drawing::color::from_argb(255, 159, 11));
        button_operators[i].flat_appearance().mouse_down_back_color(drawing::color::from_argb(234, 138, 0));
        button_operators[i].flat_appearance().mouse_over_back_color(drawing::color::from_argb(255, 159, 11));
        button_operators[i].flat_appearance().border_color(drawing::color::from_argb(44, 44, 47));
        button_operators[i].flat_style(xtd::forms::flat_style::flat);
        button_operators[i].text(button_operator_texts[i]);
        button_operators[i].location(button_operator_locations[i]);
        button_operators[i].size({60, 50});
        button_operators[i].click += event_handler(*this, &form_main::button_operator_click);
      }
    }
    
    void form_main_key_press(object& sender, key_press_event_args& e) {
      if (e.key_char() >= '0' && e.key_char() <= '9') {
        button_numbers[e.key_char() - '0'].perform_click();
        e.handled(true);
        return;
      }
      switch (e.key_char()) {
        case 'c' : button_clear.perform_click(); e.handled(true); break;
        case 'C' : button_clear.perform_click(); e.handled(true); break;
        case '%' : button_percent.perform_click(); e.handled(true); break;
        case ',' : button_decimal.perform_click(); e.handled(true); break;
        case '.' : button_decimal.perform_click(); e.handled(true); break;
        case '/' : button_operators[static_cast<int>(operators::divide)].perform_click(); e.handled(true); break;
        case '*' : button_operators[static_cast<int>(operators::multiply)].perform_click(); e.handled(true); break;
        case '-' : button_operators[static_cast<int>(operators::subtract)].perform_click(); e.handled(true); break;
        case '+' : button_operators[static_cast<int>(operators::add)].perform_click(); e.handled(true); break;
        case '=' : button_operators[static_cast<int>(operators::equal)].perform_click(); e.handled(true); break;
        case 13 : button_operators[static_cast<int>(operators::equal)].perform_click(); e.handled(true); break;
        case 127 : back_space_key_press(sender, e); e.handled(true); break;
      }
    }
    
    void back_space_key_press(object& sender, const event_args& e) {
      if (result.text().length() > 0) result.text(result.text().remove(, result.text().length() - 1));
      if (result.text().length() == 0 || result.text() == "-") button_clear_click(sender, e);
    }
    
    void button_clear_click(object& sender, const event_args& e) {
      result.text("0");
      first_operand.reset();
      second_operand.reset();
      operation = operators::none;
    }
    
    void button_percent_click(object& sender, const event_args& e) {
      result.text(ustring::format("{}", parse<double>(result.text()) / 100));
    }
    
    void button_plus_minus_click(object& sender, const event_args& e) {
      if (result.text() != "0" && result.text() != "0.") result.text(ustring::format("{}", -parse<double>(result.text())));
    }
    
    void button_number_click(object& sender, const event_args& e) {
      if ((as<control>(sender).handle() == button_decimal.handle() && result.text().contains(".")) || (result.text() == "0" && as<control>(sender).handle() == button_numbers[0].handle())) return;
      if ((first_operand.has_value() && first_operand == parse<double>(result.text())) || (result.text() == "0" && as<control>(sender).handle() != button_decimal.handle())) result.text("");
      if (second_operand.has_value()) second_operand.reset();
      result.text(result.text() + as<control>(sender).text());
    }
    
    void button_operator_click(object& sender, const event_args& e) {
      if (!first_operand.has_value()) first_operand = parse<double>(result.text());
      else {
        if (!second_operand.has_value()) second_operand = parse<double>(result.text());
        switch (operation) {
          case operators::none: break;
          case operators::divide: result.text(ustring::format("{}", first_operand.value() / second_operand.value())); break;
          case operators::multiply: result.text(ustring::format("{}", first_operand.value() * second_operand.value())); break;
          case operators::subtract: result.text(ustring::format("{}", first_operand.value() - second_operand.value())); break;
          case operators::add: result.text(ustring::format("{}", first_operand.value() + second_operand.value())); break;
          default: break;
        }
        first_operand = parse<double>(result.text());
      }
      operation = map<string, operators> {{"÷", operators::divide}, {"x", operators::multiply}, {"-", operators::subtract}, {"+", operators::add}, {"=", operation}}[as<control>(sender).text()];
      if (as<control>(sender).text() != "=") {
        if (second_operand.has_value()) first_operand.reset();
        second_operand.reset();
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
    optional<double> first_operand;
    optional<double> second_operand;
    operators operation = operators::none;
  };
}

startup_(calculator::form_main);
