#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

int main() {
  auto main_form = control::create<form>("Emoticons example");
  main_form->client_size({500, 400}).padding(10);
  
  auto emoticon_label = control::create<label>(*main_form);
  emoticon_label->text_align(xtd::forms::content_alignment::middle_center).dock(dock_style::fill).font({main_form->font(), 192});

  auto emoticons_list_box = control::create<list_box>(*main_form);
  emoticons_list_box->dock(dock_style::left).width(200);
  for (const auto& emoticon : emoticons::get_emoticons())
    emoticons_list_box->items().push_back({strings::format("{} {}", emoticon, emoticon.name()), emoticon});
  emoticons_list_box->selected_value_changed += [&] {
    emoticon_label->text(any_cast<emoticon>(emoticons_list_box->selected_item().tag()).to_string());
  };
  emoticons_list_box->selected_index(0);
  
  application::run(*main_form);
}
