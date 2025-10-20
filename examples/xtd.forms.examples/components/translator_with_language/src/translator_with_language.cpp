#include <xtd/xtd>

using namespace xtd::globalization;

class form1 : public form {
public:
  form1() {
    text("Translator example"_t);
    client_size({500, 300});
    controls().add_range({open_button, close_button, text_label});
    menu(main_menu1);

    open_button.location({10, 10});
    close_button.location({100, 10});
    text_label.location({10, 50});
    text_label.auto_size(true);
    
    en_us_menu_item.tag("en-US");
    ar_ma_menu_item.tag("ar-MA");
    es_es_menu_item.tag("es-ES");
    fr_fr_menu_item.tag("fr-BE");
    ru_ru_menu_item.tag("ru-RU");

    translator::language("fr-BE");
    update_texts();
  }
  
private:
  void on_menu_click(object& sender, const event_args& e) {
    translator::language(as<string>(as<menu_item>(sender).tag()));
    update_texts();
  }
  
  void update_texts() {
    console::write_line(environment::get_folder_path(environment::special_folder::application_resources));
    language_menu_item.text("&Languages"_t);
    open_button.text("Open"_t);
    close_button.text("Close"_t);
    text_label.text("The quick brown fox jumps over the lazy dog."_t);
  }
  
  menu_item en_us_menu_item {culture_info {"en-US"}.native_name(), event_handler {*this, &form1::on_menu_click}, menu_item_kind::radio};
  menu_item ar_ma_menu_item {culture_info {"ar-MA"}.native_name(), event_handler {*this, &form1::on_menu_click}, menu_item_kind::radio};
  menu_item es_es_menu_item {culture_info {"es-ES"}.native_name(), event_handler {*this, &form1::on_menu_click}, menu_item_kind::radio};
  menu_item fr_fr_menu_item {culture_info {"fr-BE"}.native_name(), event_handler {*this, &form1::on_menu_click}, menu_item_kind::radio, true};
  menu_item ru_ru_menu_item {culture_info {"ru-RU"}.native_name(), event_handler {*this, &form1::on_menu_click}, menu_item_kind::radio};
  menu_item language_menu_item {"&Languages"_t, {en_us_menu_item, ar_ma_menu_item, es_es_menu_item, fr_fr_menu_item, ru_ru_menu_item}};
  main_menu main_menu1 {language_menu_item};
  
  button open_button;
  button close_button;
  label text_label;
};

auto main() -> int {
  application::run(form1 {});
}
