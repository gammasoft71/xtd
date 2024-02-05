#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/message_box>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace custom_event_example {
  class custom_event_args : public event_args {
  public:
    explicit custom_event_args(const std::any& tag) noexcept : tag_ {tag} {}
    
    std::any tag() const noexcept {return tag_;}
    
  private:
    std::any tag_;
  };
  
  using custom_event_handler = generic_event_handler<const custom_event_args&>;
  
  class form1 : public form {
  public:
    form1() {
      text("Form custom event example");
      
      button1.click += [&] {
        static auto counter = 0;
        custom_event.invoke(*this, custom_event_args {++counter});
      };
      
      custom_event += [&](object& sender, const custom_event_args& e) {
        message_box::show(*this, ustring::format("Receive custom_event event ({})", any_cast<int>(e.tag())), "Custom event");
      };
    }
    
    event<form1, custom_event_handler> custom_event;
    
  private:
    button button1 = button::create(*this, "Send event", {10, 10}, {100, 25});
  };
}

auto main()->int {
  application::run(custom_event_example::form1 {});
}
