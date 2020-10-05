#define TRACE
#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Mouse events example");

    click += [&] {
      trace::write_line("click");
    };
    
    double_click += [&] {
      trace::write_line("double_click");
    };
    
    mouse_click += [&](control& sender, const mouse_event_args& e) {
      trace::write_line("mouse_click={{button={}, clicks={}, delta={}, location=[{}], modifier_keys=[{}]}}", e.button(), e.clicks(), e.delta(), e.location(), modifier_keys());
    };
    
    mouse_double_click += [&](control& sender, const mouse_event_args& e) {
      trace::write_line("mouse_double_click={{button={}, clicks={}, delta={}, location=[{}], modifier_keys=[{}]}}", e.button(), e.clicks(), e.delta(), e.location(), modifier_keys());
    };
    
    mouse_down += [&](control& sender, const mouse_event_args& e) {
      trace::write_line("mouse_down={{button={}, clicks={}, delta={}, location=[{}], modifier_keys=[{}]}}", e.button(), e.clicks(), e.delta(), e.location(), modifier_keys());
    };

    mouse_enter += [&] {
      trace::write_line("mouse_enter");
    };
    
    mouse_horizontal_wheel += [&](control& sender, const mouse_event_args& e) {
      trace::write_line("mouse_horizontal_wheel={{button={}, clicks={}, delta={}, location=[{}]}}", e.button(), e.clicks(), e.delta(), e.location());
    };

    mouse_leave += [&] {
      trace::write_line("mouse_leave");
    };
    
    mouse_move += [&](control& sender, const mouse_event_args& e) {
      trace::write_line("mouse_move={{button={}, clicks={}, delta={}, location=[{}], modifier_keys=[{}]}}", e.button(), e.clicks(), e.delta(), e.location(), modifier_keys());
    };
    
    mouse_up += [&](control& sender, const mouse_event_args& e) {
      trace::write_line("mouse_up={{button={}, clicks={}, delta={}, location=[{}], modifier_keys=[{}]}}", e.button(), e.clicks(), e.delta(), e.location(), modifier_keys());
    };
    
    mouse_wheel += [&](control& sender, const mouse_event_args& e) {
      trace::write_line("mouse_wheel={{button={}, clicks={}, delta={}, location=[{}]}}", e.button(), e.clicks(), e.delta(), e.location());
    };
  }
};

int main() {
  trace_form trace;
  application::run(form1());
}
