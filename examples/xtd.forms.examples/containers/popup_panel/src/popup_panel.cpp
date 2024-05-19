#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/button_images>
#include <xtd/forms/form>
#include <xtd/forms/list_box>
#include <xtd/forms/popup_panel>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Popup panel example");
    client_size({300, 100});
    controls().push_back_range({button1, popup_panel1});
    
    list_box1.parent(popup_panel1);
    list_box1.dock(dock_style::fill);
    list_box1.items().push_back_range({{"clear", button_images::from_name("weather-clear")}, {"clear night", button_images::from_name("weather-clear-night")}, {"few clouds", button_images::from_name("weather-few-clouds")}, {"few clouds night", button_images::from_name("weather-few-clouds-night")}, {"fog", button_images::from_name("weather-fog")}, {"overcast", button_images::from_name("weather-overcast")}, {"severe alert", button_images::from_name("weather-severe-alert")}, {"showers", button_images::from_name("weather-showers")}, {"showers scattered", button_images::from_name("weather-showers-scattered")}, {"snow", button_images::from_name("weather-snow")}, {"storm", button_images::from_name("weather-storm")}});
    list_box1.selected_index(0);
    list_box1.click += [&] {
      button1.text(list_box1.selected_item().value());
      button1.image(as<image>(list_box1.selected_item().tag()));
      popup_panel1.hide();
    };
    
    button1.location({10, 10});
    button1.size({160, 50});
    button1.image_align(content_alignment::top_center);
    button1.text_align(content_alignment::bottom_center);
    button1.text(list_box1.selected_item().value());
    button1.image(as<image>(list_box1.selected_item().tag()));
    button1.click += [&] {
      popup_panel1.show();
    };
    
    popup_panel1.location(button1.location());
    popup_panel1.width(button1.width());
  }
  
private:
  button button1;
  list_box list_box1;
  popup_panel popup_panel1;
};

auto main() -> int {
  application::run(form1 {});
}

