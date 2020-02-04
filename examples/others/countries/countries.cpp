#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class main_form : public form {
  public:
    static void main() {
      application::run(main_form());
    }

    main_form() {
      text("Countries example").client_size({560, 180});
      auto name = [](const country& c) {return strings::format("{} ({})", c.text_flag(), c.name());};
      button_france.text(name(countries::france())).tag(countries::france()).parent(*this).location({10, 10}).size({100, 25}).click += {*this, &main_form::on_button_click};
      button_canada.text(name(countries::canada())).tag(countries::canada()).parent(*this).location({120, 10}).size({100, 25}).click += {*this, &main_form::on_button_click};
      button_egypt.text(name(countries::egypt())).tag(countries::egypt()).parent(*this).location({230, 10}).size({100, 25}).click += {*this, &main_form::on_button_click};
      button_japan.text(name(countries::japan())).tag(countries::japan()).parent(*this).location({340, 10}).size({100, 25}).click += {*this, &main_form::on_button_click};
      button_australia.text(name(countries::australia())).tag(countries::australia()).parent(*this).location({450, 10}).size({100, 25}).click += {*this, &main_form::on_button_click};
      informations.border_style(border_style::fixed_3d).text(strings::format("Name: {0}Text flag: {0}Alpha code: {0}Numeric code:", '\n')).parent(*this).location({10, 45}).size({540, 125});
    }
    
  private:
    void on_button_click(control& sender, const event_args& e) {
      auto c = std::any_cast<country>(sender.tag());
      informations.text(strings::format("Name: {1}{0}Text flag: {2}{0}Alpha code: {3} ({4}){0}Numeric code: {5:D3}", '\n', c.name(), c.text_flag(), c.alpha_2_code(), c.alpha_3_code(), c.numeric_code()));
    }
    
    button button_france, button_canada, button_egypt, button_japan, button_australia;
    label informations;
  };
}

startup_(examples::main_form);
