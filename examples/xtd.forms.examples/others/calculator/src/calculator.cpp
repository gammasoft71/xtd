#include <xtd/xtd>

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
    static auto main() {
      application::run(form_main());
    }
    
    form_main() {
      text("Calculator");
      back_color(drawing::color::from_argb(44, 44, 47));
      fore_color(drawing::color::white);
      font(drawing::font(font_family::generic_sans_serif(), 15));
      auto_size_mode(forms::auto_size_mode::grow_and_shrink);
      auto_size(true);
      maximize_box(false);
      form_border_style(forms::form_border_style::fixed_3d);
      key_press += key_press_event_handler(*this, &form_main::form_main_key_press);
      
      result.bounds({0, 0, 240, 60});
      result.font(drawing::font(font(), font().size() * 2));
      result.parent(*this);
      result.text_align(content_alignment::middle_right);
      result.text("0");
      
      button_clear.parent(*this);
      button_clear.back_color(drawing::color::from_argb(64, 64, 64));
      button_clear.flat_appearance(flat_button_appearance().mouse_down_back_color(drawing::color::from_argb(102, 102, 102))
        .mouse_over_back_color(drawing::color::from_argb(64, 64, 64))
        .border_color(drawing::color::from_argb(44, 44, 47))
        .border_radius(0)
        .border_size(0));
      button_clear.flat_style(forms::flat_style::flat);
      button_clear.location({0, 60});
      button_clear.text("C");
      button_clear.size({60, 50});
      button_clear.click += event_handler(*this, &form_main::button_clear_click);
      
      button_plus_minus.parent(*this);
      button_plus_minus.back_color(drawing::color::from_argb(64, 64, 64));
      button_plus_minus.flat_appearance(flat_button_appearance().mouse_down_back_color(drawing::color::from_argb(102, 102, 102))
        .mouse_over_back_color(drawing::color::from_argb(64, 64, 64))
        .border_color(drawing::color::from_argb(44, 44, 47))
        .border_radius(0)
        .border_size(0));
      button_plus_minus.flat_style(forms::flat_style::flat);
      button_plus_minus.location({61, 60});
      button_plus_minus.text("+/-");
      button_plus_minus.size({60, 50});
      button_plus_minus.click += event_handler(*this, &form_main::button_plus_minus_click);
      
      button_percent.parent(*this);
      button_percent.back_color(drawing::color::from_argb(64, 64, 64));
      button_percent.flat_appearance(flat_button_appearance().mouse_down_back_color(drawing::color::from_argb(102, 102, 102))
        .mouse_over_back_color(drawing::color::from_argb(64, 64, 64))
        .border_color(drawing::color::from_argb(44, 44, 47))
        .border_radius(0)
        .border_size(0));
      button_percent.flat_style(forms::flat_style::flat);
      button_percent.location({122, 60});
      button_percent.text("%");
      button_percent.size({60, 50});
      button_percent.click += event_handler(*this, &form_main::button_percent_click);
      
      button_decimal.parent(*this);
      button_decimal.back_color(drawing::color::from_argb(102, 102, 102));
      button_decimal.flat_appearance(flat_button_appearance().mouse_down_back_color(drawing::color::from_argb(144, 144, 144))
        .mouse_over_back_color(drawing::color::from_argb(102, 102, 102))
        .border_color(drawing::color::from_argb(44, 44, 47))
        .border_radius(0)
        .border_size(0));
      button_decimal.flat_style(forms::flat_style::flat);
      button_decimal.location({122, 264});
      button_decimal.text(".");
      button_decimal.size({60, 50});
      button_decimal.click += event_handler(*this, &form_main::button_number_click);
      
      list<point> button_number_locations = {{0, 264}, {0, 213}, {61, 213}, {122, 213}, {0, 162}, {61, 162}, {122, 162}, {0, 111}, {61, 111}, {122, 111}};
      for (int i = 0; i < 10; i++) {
        button_numbers[i].parent(*this);
        button_numbers[i].back_color(drawing::color::from_argb(102, 102, 102));
        button_numbers[i].flat_appearance(flat_button_appearance().mouse_down_back_color(drawing::color::from_argb(144, 144, 144))
          .mouse_over_back_color(drawing::color::from_argb(102, 102, 102))
          .border_color(drawing::color::from_argb(44, 44, 47))
          .border_radius(0)
          .border_size(0));
        button_numbers[i].flat_style(forms::flat_style::flat);
        button_numbers[i].text(string::format("{}", i));
        button_numbers[i].location(button_number_locations[i]);
        button_numbers[i].size({60, 50});
        button_numbers[i].click += event_handler(*this, &form_main::button_number_click);
      }
      button_numbers[0].width(121);
      
      list button_operator_texts = {"÷", "x", "-", "+", "="};
      list<point> button_operator_locations = {{183, 60}, {183, 111}, {183, 162}, {183, 213}, {183, 264}};
      for (int i = 0; i < 5; i++) {
        button_operators[i].parent(*this);
        button_operators[i].back_color(drawing::color::from_argb(255, 159, 11));
        button_operators[i].flat_appearance(flat_button_appearance().mouse_down_back_color(drawing::color::from_argb(234, 138, 0))
          .mouse_over_back_color(drawing::color::from_argb(255, 159, 11))
          .border_color(drawing::color::from_argb(44, 44, 47))
          .border_radius(0)
          .border_size(0));
        button_operators[i].flat_style(forms::flat_style::flat);
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
        case '/' : button_operators[as<int>(operators::divide)].perform_click(); e.handled(true); break;
        case '*' : button_operators[as<int>(operators::multiply)].perform_click(); e.handled(true); break;
        case '-' : button_operators[as<int>(operators::subtract)].perform_click(); e.handled(true); break;
        case '+' : button_operators[as<int>(operators::add)].perform_click(); e.handled(true); break;
        case '=' : button_operators[as<int>(operators::equal)].perform_click(); e.handled(true); break;
        case 13 : button_operators[as<int>(operators::equal)].perform_click(); e.handled(true); break;
        case 127 : back_space_key_press(sender, e); e.handled(true); break;
      }
    }
    
    void back_space_key_press(object& sender, const event_args& e) {
      if (result.text().length() > 0) result.text(as<string>(result.text()).remove(result.text().length() - 1));
      if (result.text().length() == 0 || result.text() == "-") button_clear_click(sender, e);
    }
    
    void button_clear_click(object& sender, const event_args& e) {
      result.text("0");
      first_operand.reset();
      second_operand.reset();
      operation = operators::none;
    }
    
    void button_percent_click(object& sender, const event_args& e) {
      result.text(string::format("{}", parse<double>(result.text()) / 100));
    }
    
    void button_plus_minus_click(object& sender, const event_args& e) {
      if (result.text() != "0" && result.text() != "0.") result.text(string::format("{}", -parse<double>(result.text())));
    }
    
    void button_number_click(object& sender, const event_args& e) {
      if ((as<control>(sender).handle() == button_decimal.handle() && as<string>(result.text()).contains(".")) || (result.text() == "0" && as<control>(sender).handle() == button_numbers[0].handle())) return;
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
          case operators::divide: result.text(string::format("{}", first_operand.value() / second_operand.value())); break;
          case operators::multiply: result.text(string::format("{}", first_operand.value() * second_operand.value())); break;
          case operators::subtract: result.text(string::format("{}", first_operand.value() - second_operand.value())); break;
          case operators::add: result.text(string::format("{}", first_operand.value() + second_operand.value())); break;
          default: break;
        }
        first_operand = parse<double>(result.text());
      }
      operation = dictionary<string, operators> {{"÷", operators::divide}, {"x", operators::multiply}, {"-", operators::subtract}, {"+", operators::add}, {"=", operation}} [as<control>(sender).text()];
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
    fixed_array<button, 10> button_numbers;
    fixed_array<button, 5> button_operators;
    optional<double> first_operand;
    optional<double> second_operand;
    operators operation = operators::none;
  };
}

startup_(calculator::form_main::main);
