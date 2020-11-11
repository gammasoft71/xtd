#define TRACE
#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Mouse events example");

    click += [&] {
      ctrace << format("click") << endl;
    };
    
    double_click += [&] {
      ctrace << format("double_click") << endl;
    };
    
    mouse_click += [&](control& sender, const mouse_event_args& e) {
      ctrace << format("mouse_click={{button={}, clicks={}, delta={}, location=[{}], modifier_keys=[{}]}}", e.button(), e.clicks(), e.delta(), e.location(), modifier_keys()) << endl;
    };
    
    mouse_double_click += [&](control& sender, const mouse_event_args& e) {
      ctrace << format("mouse_double_click={{button={}, clicks={}, delta={}, location=[{}], modifier_keys=[{}]}}", e.button(), e.clicks(), e.delta(), e.location(), modifier_keys()) << endl;
    };
    
    mouse_down += [&](control& sender, const mouse_event_args& e) {
      ctrace << format("mouse_down={{button={}, clicks={}, delta={}, location=[{}], modifier_keys=[{}]}}", e.button(), e.clicks(), e.delta(), e.location(), modifier_keys()) << endl;
    };

    mouse_enter += [&] {
      ctrace << format("mouse_enter") << endl;
    };
    
    mouse_horizontal_wheel += [&](control& sender, const mouse_event_args& e) {
      ctrace << format("mouse_horizontal_wheel={{button={}, clicks={}, delta={}, location=[{}]}}", e.button(), e.clicks(), e.delta(), e.location()) << endl;
    };

    mouse_leave += [&] {
      ctrace << format("mouse_leave") << endl;
    };
    
    mouse_move += [&](control& sender, const mouse_event_args& e) {
      ctrace << format("mouse_move={{button={}, clicks={}, delta={}, location=[{}], modifier_keys=[{}]}}", e.button(), e.clicks(), e.delta(), e.location(), modifier_keys()) << endl;
    };
    
    mouse_up += [&](control& sender, const mouse_event_args& e) {
      ctrace << format("mouse_up={{button={}, clicks={}, delta={}, location=[{}], modifier_keys=[{}]}}", e.button(), e.clicks(), e.delta(), e.location(), modifier_keys()) << endl;
    };
    
    mouse_wheel += [&](control& sender, const mouse_event_args& e) {
      ctrace << format("mouse_wheel={{button={}, clicks={}, delta={}, location=[{}]}}", e.button(), e.clicks(), e.delta(), e.location()) << endl;
    };
  }
};

int main() {
  trace_form trace;
  application::run(form1());
}
