#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/message_box>

using namespace xtd;
using namespace xtd::forms;

namespace custom_event_example {
  class custom_event_args : public event_args {
  public:
    explicit custom_event_args(const any_object& tag) noexcept : tag_ {tag} {}
    
    any_object tag() const noexcept {return tag_;}
    
  private:
    any_object tag_;
  };
  
  using custom_event_handler = generic_event_handler<const custom_event_args&>;
  
  class form1 : public form {
  public:
    form1() {
      text("Form custom event example");
      
      button1.click += delegate_ {
        static auto counter = 0;
        custom_event.invoke(*this, custom_event_args {++counter});
      };
      
      custom_event += delegate_(object& sender, const custom_event_args& e) {
        message_box::show(*this, string::format("Receive custom_event event ({})", as<int>(e.tag())), "Custom event");
      };
    }
    
    event<form1, custom_event_handler> custom_event;
    
  private:
    button button1 = button::create(*this, "Send event", {10, 10}, {100, 25});
  };
}

auto main() -> int {
  application::run(custom_event_example::form1 {});
}
