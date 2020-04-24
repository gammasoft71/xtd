#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Hello world (emoticons)");
      auto_size_mode(forms::auto_size_mode::grow_and_shrink);
      auto_size(true);

      label.parent(*this);
      label.auto_size(true);
      label.font(drawing::font(label.font(), 72));
      label.text(emoticons::waving_hand_sign + ", " + emoticons::earth_globe_americas + emoticons::heavy_exclamation_mark_symbol);
    }
    
  private:
    forms::label label;
  };
}

int main() {
  application::run(examples::form1());
}
