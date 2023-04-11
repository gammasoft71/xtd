#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

namespace hello_world_emoticons_example {
  class main_form : public form {
  public:
    main_form() {
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

auto main()->int {
  application::run(hello_world_emoticons_example::main_form());
}
