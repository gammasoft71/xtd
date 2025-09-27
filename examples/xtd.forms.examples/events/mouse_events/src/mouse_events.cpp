#define TRACE 1 // Force to trace even if example is builded with -DNTRACE.
#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    text("Mouse events example");
    
    click += delegate_ {
      xtd::diagnostics::trace::write_line("click");
    };
    
    double_click += delegate_ {
      xtd::diagnostics::trace::write_line("double_click");
    };
    
    mouse_click += delegate_(object & sender, const mouse_event_args & e) {
      xtd::diagnostics::trace::write_line("mouse_click={{button={}, clicks={}, delta={}, location=[{}], modifier_keys=[{}]}}", e.button(), e.clicks(), e.delta(), e.location(), modifier_keys());
    };
    
    mouse_double_click += delegate_(object & sender, const mouse_event_args & e) {
      xtd::diagnostics::trace::write_line("mouse_double_click={{button={}, clicks={}, delta={}, location=[{}], modifier_keys=[{}]}}", e.button(), e.clicks(), e.delta(), e.location(), modifier_keys());
    };
    
    mouse_down += delegate_(object & sender, const mouse_event_args & e) {
      xtd::diagnostics::trace::write_line("mouse_down={{button={}, clicks={}, delta={}, location=[{}], modifier_keys=[{}]}}", e.button(), e.clicks(), e.delta(), e.location(), modifier_keys());
    };
    
    mouse_enter += delegate_ {
      xtd::diagnostics::trace::write_line("mouse_enter");
    };
    
    mouse_horizontal_wheel += delegate_(object & sender, const mouse_event_args & e) {
      xtd::diagnostics::trace::write_line("mouse_horizontal_wheel={{button={}, clicks={}, delta={}, location=[{}], modifier_keys=[{}]}}", e.button(), e.clicks(), e.delta(), e.location(), modifier_keys());
    };
    
    mouse_leave += delegate_ {
      xtd::diagnostics::trace::write_line("mouse_leave");
    };
    
    mouse_move += delegate_(object & sender, const mouse_event_args & e) {
      xtd::diagnostics::trace::write_line("mouse_move={{button={}, clicks={}, delta={}, location=[{}], modifier_keys=[{}]}}", e.button(), e.clicks(), e.delta(), e.location(), modifier_keys());
    };
    
    mouse_up += delegate_(object & sender, const mouse_event_args & e) {
      xtd::diagnostics::trace::write_line("mouse_up={{button={}, clicks={}, delta={}, location=[{}], modifier_keys=[{}]}}", e.button(), e.clicks(), e.delta(), e.location(), modifier_keys());
    };
    
    mouse_wheel += delegate_(object & sender, const mouse_event_args & e) {
      xtd::diagnostics::trace::write_line("mouse_wheel={{button={}, clicks={}, delta={}, location=[{}], modifier_keys=[{}]}}", e.button(), e.clicks(), e.delta(), e.location(), modifier_keys());
    };
  }
};

auto main() -> int {
  trace_form trace_form;
  application::run(form1 {});
}
