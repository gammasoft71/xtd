#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("\"Hello, World!\" with emoticons");
      client_size({300, 300});
      controls().push_back(label);

      label.auto_size(true);
      label.font(drawing::font(label.font(), 48));
      label.location({5, 90});
      label.text(emoticons::waving_hand_sign + ", " + emoticons::earth_globe_americas + emoticons::heavy_exclamation_mark_symbol);
    }
    
  private:
    forms::label label;
  };
}

int main() {
  application::run(examples::form1());
}
