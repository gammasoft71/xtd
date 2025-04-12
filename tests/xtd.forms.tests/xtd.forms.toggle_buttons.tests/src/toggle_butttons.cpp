#include <xtd/forms/application>
#include <xtd/forms/button_images>
#include <xtd/forms/choice>
#include <xtd/forms/form>
#include <xtd/forms/tab_control>
#include <xtd/forms/tab_page>
#include <xtd/forms/toggle_button>
#include <xtd/startup>

using namespace xtd::drawing::drawing_2d;

namespace xtd::forms::tests {
  class toggle_buttons_form : public form {
    using toggle_button_ptr_t = sptr<toggle_button>;
    using buttons_t = list<toggle_button_ptr_t>;
    
  public:
    static auto main() {
      application::run(toggle_buttons_form());
    }
    
    toggle_buttons_form() {
      text("Toggle buttons tests - system");
      padding(10);
      client_size({1100, 600});
      
      tab_control.parent(*this);
      tab_control.dock(dock_style::fill);
      
      tab_page_system.parent(tab_control);
      tab_page_system.text("System");
      
      tab_page_standard.parent(tab_control);
      tab_page_standard.text("Standard");
      
      tab_page_flat.parent(tab_control);
      tab_page_flat.text("Flat");
      
      tab_page_popup.parent(tab_control);
      tab_page_popup.text("Popup");
      
      create_buttons(tab_page_system, flat_style::system);
      create_buttons(tab_page_standard, flat_style::standard);
      create_buttons(tab_page_flat, flat_style::flat);
      create_buttons(tab_page_popup, flat_style::popup);
      
      style_sheet_choice.parent(*this);
      style_sheet_choice.dock(dock_style::bottom);
      style_sheet_choice.items({"GNOME (dark)", "GNOME (light)", "KDE (dark)", "KDE (light)", "macOS (dark)", "macOS (light)", "Windows (dark)", "Windows (light)", "default"});
      style_sheet_choice.selected_index_changed += [&] {
        application::style_sheet(application::get_style_sheet_from_name(style_sheet_choice.selected_item().value()));
        text(string::format("Toggle buttons tests - {}", style_sheet_choice.selected_item().value()));
      };
      style_sheet_choice.selected_item(style_sheets::style_sheet::system_style_sheet().theme().name());
    }
    
  private:
    void create_buttons(const control& parent_control, flat_style style) {
      toggle_button_ptr_t button_ptr;
      int button_number = 0;
      
      // Text only buttons
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->check_state(forms::check_state::checked).flat_style(style).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({10, 10});
      default_buttons.push_back(button_ptr);
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).check_state(forms::check_state::indeterminate).flat_style(style).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({130, 10});
      button_ptr->flat_style(style).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({130, 10});
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->flat_style(style).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({250, 10}).enabled(false);
      
      // Image only buttons
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->check_state(forms::check_state::checked).flat_style(style).image(button_images::from_name("xtd")).parent(parent_control).location({370, 10});
      ++button_number;
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).check_state(forms::check_state::indeterminate).flat_style(style).image(button_images::from_name("xtd")).parent(parent_control).location({490, 10});
      ++button_number;
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->flat_style(style).image(button_images::from_name("xtd")).parent(parent_control).location({610, 10}).enabled(false);
      ++button_number;
      
      // Image and text buttons
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->check_state(forms::check_state::checked).flat_style(style).image(button_images::from_name("xtd")).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({730, 10});
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).check_state(forms::check_state::indeterminate).flat_style(style).image(button_images::from_name("xtd")).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({850, 10});
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->flat_style(style).image(button_images::from_name("xtd")).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({970, 10}).enabled(false);
      
      // Fore Color
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->flat_style(style).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({10, 50}).fore_color(color::dodger_blue);
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({130, 50}).fore_color(color::dodger_blue);
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->flat_style(style).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({250, 50}).enabled(false).fore_color(color::dodger_blue);
      
      // Back Color
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->flat_style(style).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({370, 50}).back_color(color::dodger_blue);
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({490, 50}).back_color(color::dodger_blue);
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->flat_style(style).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({610, 50}).enabled(false).back_color(color::dodger_blue);
      
      // Text align buttons
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).text_align(content_alignment::top_left).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({10, 90}).size({100, 50});
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).text_align(content_alignment::top_center).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({120, 90}).size({100, 50});
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).text_align(content_alignment::top_right).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({230, 90}).size({100, 50});
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).text_align(content_alignment::middle_left).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({340, 90}).size({100, 50});
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).text_align(content_alignment::middle_center).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({450, 90}).size({100, 50});
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).text_align(content_alignment::middle_right).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({560, 90}).size({100, 50});
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).text_align(content_alignment::bottom_left).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({670, 90}).size({100, 50});
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).text_align(content_alignment::bottom_center).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({780, 90}).size({100, 50});
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).text_align(content_alignment::bottom_right).text(string::format("Buttton {}", ++button_number)).parent(parent_control).location({890, 90}).size({100, 50});
      
      // Image align buttons
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).image_align(content_alignment::top_left).image(button_images::from_name("xtd")).parent(parent_control).location({10, 155}).size({100, 50});
      ++button_number;
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).image_align(content_alignment::top_center).image(button_images::from_name("xtd")).parent(parent_control).location({120, 155}).size({100, 50});
      ++button_number;
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).image_align(content_alignment::top_right).image(button_images::from_name("xtd")).parent(parent_control).location({230, 155}).size({100, 50});
      ++button_number;
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).image_align(content_alignment::middle_left).image(button_images::from_name("xtd")).parent(parent_control).location({340, 155}).size({100, 50});
      ++button_number;
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).image_align(content_alignment::middle_center).image(button_images::from_name("xtd")).parent(parent_control).location({450, 155}).size({100, 50});
      ++button_number;
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).image_align(content_alignment::middle_right).image(button_images::from_name("xtd")).parent(parent_control).location({560, 155}).size({100, 50});
      ++button_number;
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).image_align(content_alignment::bottom_left).image(button_images::from_name("xtd")).parent(parent_control).location({670, 155}).size({100, 50});
      ++button_number;
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).image_align(content_alignment::bottom_center).image(button_images::from_name("xtd")).parent(parent_control).location({780, 155}).size({100, 50});
      ++button_number;
      
      button_ptr = xtd::new_sptr<toggle_button>();
      buttons.push_back(button_ptr);
      button_ptr->three_state(true).flat_style(style).image_align(content_alignment::bottom_right).image(button_images::from_name("xtd")).parent(parent_control).location({890, 155}).size({100, 50});
      ++button_number;
    }
    
    forms::tab_control tab_control;
    forms::tab_page tab_page_system;
    forms::tab_page tab_page_standard;
    forms::tab_page tab_page_flat;
    forms::tab_page tab_page_popup;
    
    choice style_sheet_choice;
    
    buttons_t buttons;
    buttons_t default_buttons;
  };
}

startup_(tests::toggle_buttons_form::main);
