#include <xtd/forms/application>
#include <xtd/forms/button_images>
#include <xtd/forms/choice>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/tab_control>
#include <xtd/forms/tab_page>
#include <xtd/startup>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::forms;

class labels_form : public form {
  using label_ptr_t = shared_ptr<label>;
  using labels_t = vector<label_ptr_t>;
  
public:
  static auto main() {
    application::run(labels_form());
  }
  
  labels_form() {
    text("labels tests - system");
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
    
    create_labels(tab_page_system, flat_style::system);
    create_labels(tab_page_standard, flat_style::standard);
    create_labels(tab_page_flat, flat_style::flat);
    create_labels(tab_page_popup, flat_style::popup);
    
    style_sheet_choice.parent(*this);
    style_sheet_choice.dock(dock_style::bottom);
    style_sheet_choice.items({"GNOME (dark)", "GNOME (light)", "KDE (dark)", "KDE (light)", "macOS (dark)", "macOS (light)", "Windows (dark)", "Windows (light)", "default"});
    style_sheet_choice.selected_index_changed += [&] {
      application::style_sheet(application::get_style_sheet_from_name(style_sheet_choice.selected_item().value()));
      text(ustring::format("Labels tests - {}", style_sheet_choice.selected_item().value()));
    };
    style_sheet_choice.selected_item(style_sheets::style_sheet::system_style_sheet().theme().name());
  }
  
private:
  void create_labels(const control& parent_control, forms::flat_style style) {
    label_ptr_t label_ptr;
    int label_number = 0;
    
    // Text only labels
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->flat_style(style).text(ustring::format("Label {}", ++label_number)).parent(parent_control).location({10, 10});
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->flat_style(style).text(ustring::format("Label {}", ++label_number)).parent(parent_control).location({120, 10}).enabled(false);
    
    // Image only labels
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->image(button_images::from_name("xtd")).flat_style(style).parent(parent_control).location({230, 10});
    ++label_number;
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->image(button_images::from_name("xtd")).flat_style(style).parent(parent_control).location({340, 10}).enabled(false);
    ++label_number;
    
    // Image and text labels
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->image(button_images::from_name("xtd")).flat_style(style).text(ustring::format("Label {}", ++label_number)).parent(parent_control).location({450, 10});
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->image(button_images::from_name("xtd")).flat_style(style).text(ustring::format("Label {}", ++label_number)).parent(parent_control).location({560, 10}).enabled(false);
    
    // Fore Color
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->flat_style(style).text(ustring::format("Label {}", ++label_number)).parent(parent_control).location({10, 50}).fore_color(color::dodger_blue);
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->flat_style(style).text(ustring::format("Label {}", ++label_number)).parent(parent_control).location({120, 50}).enabled(false).fore_color(color::dodger_blue);
    
    // Back Color
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->flat_style(style).text(ustring::format("Label {}", ++label_number)).parent(parent_control).location({230, 50}).back_color(color::dodger_blue);
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->flat_style(style).text(ustring::format("Label {}", ++label_number)).parent(parent_control).location({340, 50}).enabled(false).back_color(color::dodger_blue);
    
    // Text align labels
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->border_style(xtd::forms::border_style::solid).text_align(content_alignment::top_left).flat_style(style).text(ustring::format("Label {}", ++label_number)).parent(parent_control).location({10, 90}).size({100, 50});
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->border_style(xtd::forms::border_style::solid).text_align(content_alignment::top_center).flat_style(style).text(ustring::format("Label {}", ++label_number)).parent(parent_control).location({120, 90}).size({100, 50});
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->border_style(xtd::forms::border_style::solid).text_align(content_alignment::top_right).flat_style(style).text(ustring::format("Label {}", ++label_number)).parent(parent_control).location({230, 90}).size({100, 50});
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->border_style(xtd::forms::border_style::solid).text_align(content_alignment::middle_left).flat_style(style).text(ustring::format("Label {}", ++label_number)).parent(parent_control).location({340, 90}).size({100, 50});
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->border_style(xtd::forms::border_style::solid).text_align(content_alignment::middle_center).flat_style(style).text(ustring::format("Label {}", ++label_number)).parent(parent_control).location({450, 90}).size({100, 50});
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->border_style(xtd::forms::border_style::solid).text_align(content_alignment::middle_right).flat_style(style).text(ustring::format("Label {}", ++label_number)).parent(parent_control).location({560, 90}).size({100, 50});
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->border_style(xtd::forms::border_style::solid).text_align(content_alignment::bottom_left).flat_style(style).text(ustring::format("Label {}", ++label_number)).parent(parent_control).location({670, 90}).size({100, 50});
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->border_style(xtd::forms::border_style::solid).text_align(content_alignment::bottom_center).flat_style(style).text(ustring::format("Label {}", ++label_number)).parent(parent_control).location({780, 90}).size({100, 50});
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->border_style(xtd::forms::border_style::solid).text_align(content_alignment::bottom_right).flat_style(style).text(ustring::format("Label {}", ++label_number)).parent(parent_control).location({890, 90}).size({100, 50});
    
    // Image align labels
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->border_style(xtd::forms::border_style::solid).image_align(content_alignment::top_left).image(button_images::from_name("xtd")).flat_style(style).parent(parent_control).location({10, 155}).size({100, 50});
    ++label_number;
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->border_style(xtd::forms::border_style::solid).image_align(content_alignment::top_center).image(button_images::from_name("xtd")).flat_style(style).parent(parent_control).location({120, 155}).size({100, 50});
    ++label_number;
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->border_style(xtd::forms::border_style::solid).image_align(content_alignment::top_right).image(button_images::from_name("xtd")).flat_style(style).parent(parent_control).location({230, 155}).size({100, 50});
    ++label_number;
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->border_style(xtd::forms::border_style::solid).image_align(content_alignment::middle_left).image(button_images::from_name("xtd")).flat_style(style).parent(parent_control).location({340, 155}).size({100, 50});
    ++label_number;
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->border_style(xtd::forms::border_style::solid).image_align(content_alignment::middle_center).image(button_images::from_name("xtd")).flat_style(style).parent(parent_control).location({450, 155}).size({100, 50});
    ++label_number;
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->border_style(xtd::forms::border_style::solid).image_align(content_alignment::middle_right).image(button_images::from_name("xtd")).flat_style(style).parent(parent_control).location({560, 155}).size({100, 50});
    ++label_number;
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->border_style(xtd::forms::border_style::solid).image_align(content_alignment::bottom_left).image(button_images::from_name("xtd")).flat_style(style).parent(parent_control).location({670, 155}).size({100, 50});
    ++label_number;
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->border_style(xtd::forms::border_style::solid).image_align(content_alignment::bottom_center).image(button_images::from_name("xtd")).flat_style(style).parent(parent_control).location({780, 155}).size({100, 50});
    ++label_number;
    
    label_ptr = make_shared<label>();
    labels.push_back(label_ptr);
    label_ptr->border_style(xtd::forms::border_style::solid).image_align(content_alignment::bottom_right).image(button_images::from_name("xtd")).flat_style(style).parent(parent_control).location({890, 155}).size({100, 50});
    ++label_number;
  }
  
  forms::tab_control tab_control;
  forms::tab_page tab_page_system;
  forms::tab_page tab_page_standard;
  forms::tab_page tab_page_flat;
  forms::tab_page tab_page_popup;
  
  choice style_sheet_choice;
  
  labels_t labels;
};

startup_(labels_form::main);
