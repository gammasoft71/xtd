#include <xtd/as>
#include <xtd/console>
#include <xtd/environment>
#include <xtd/event>
#include <xtd/event_handler>
#include <xtd/string>

class control : public xtd::object {
public:
  control() = default;
  
  auto text() const -> const xtd::string& {return text_;}
  auto text(const xtd::string& text) -> void {
    if (text_ != text) {
      text_ = text;
      on_text_changed(xtd::event_args::empty);
    }
  }
  
  xtd::event<control, xtd::event_handler> text_changed;
  
protected:
  auto on_text_changed(const xtd::event_args& e) -> void {text_changed(*this, e);}
  
private:
  xtd::string text_;
};

class button : public control {
public:
  button() = default;
  
  xtd::event<button, xtd::event_handler> click;
  
  auto perform_click() -> void {on_click(xtd::event_args::empty);}
  
protected:
  virtual auto on_click(const xtd::event_args& e) -> void {click(*this, e);}
};

auto main() -> int {
  auto button1 = button {};
  
  button1.text_changed += delegate_(xtd::object & sender, const xtd::event_args & e)  {
    xtd::console::out << "text_changed [text=" << xtd::as<control>(sender).text() << "]" << xtd::environment::new_line;
  };
  
  button1.click += delegate_  {
    xtd::console::out << "click on button1" << xtd::environment::new_line;
  };
  
  button1.text("button1");
  
  // click simulation
  button1.perform_click();
}

// This code produces the following output :
//
// text_changed [text=button1]
// click on button1
