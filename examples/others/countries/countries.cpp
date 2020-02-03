#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class main_form : public form {
  public:
    static void main() {
      application::run(main_form());
    }

    main_form() {
      auto name = [](const country& c) {return strings::format("{} {}", c.text_flag(), c.name());};
      text("Countries example").client_size({560, 180});
      button_france.text(name(countries::france())).tag(countries::france()).parent(*this).location({10, 10}).size({100, 25}).click += {*this, &main_form::on_button_click};
      button_belgium.text(name(countries::belgium())).tag(countries::belgium()).parent(*this).location({120, 10}).size({100, 25}).click += {*this, &main_form::on_button_click};
      button_italy.text(name(countries::italy())).tag(countries::italy()).parent(*this).location({230, 10}).size({100, 25}).click += {*this, &main_form::on_button_click};
      button_spain.text(name(countries::spain())).tag(countries::spain()).parent(*this).location({340, 10}).size({100, 25}).click += {*this, &main_form::on_button_click};
      button_germany.text(name(countries::germany())).tag(countries::germany()).parent(*this).location({450, 10}).size({100, 25}).click += {*this, &main_form::on_button_click};
      informations.border_style(border_style::fixed_3d).text("Name: \nFlag: \nAlpha code: \nNumeric code: \n").parent(*this).location({10, 45}).size({540, 125});
    }
    
  private:
    void on_button_click(control& sender, const event_args& e) {
      country c = any_cast<country>(sender.tag());
      informations.text(strings::format("Name: {}\nFlag: {}\nAlpha code: {} ({})\nNumeric code: {:D3}\n", c.name(), c.text_flag(), c.alpha_2_code(), c.alpha_3_code(), c.numeric_code()));
    }
    
    button button_france;
    button button_belgium;
    button button_italy;
    button button_spain;
    button button_germany;
    label informations;
  };
}

startup_(examples::main_form);
