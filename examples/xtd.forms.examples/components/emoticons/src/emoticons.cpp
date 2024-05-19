#include <xtd/forms/application>
#include <xtd/forms/emoticons>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/list_box>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

auto main() -> int {
  auto main_form = form::create("Emoticons example");
  main_form.client_size({500, 400}).padding(10);
  
  auto emoticon_label = label::create(main_form, "");
  emoticon_label.text_align(xtd::forms::content_alignment::middle_center).dock(dock_style::fill).font({main_form.font(), 192});
  
  auto emoticons_list_box = list_box::create(main_form, list_box::object_collection {});
  emoticons_list_box.dock(dock_style::left).width(200);
  for (const auto& emoticon : emoticons::get_emoticons())
    emoticons_list_box.items().push_back({ustring::format("{} {}", emoticon, emoticon.name()), emoticon});
  emoticons_list_box.selected_value_changed += [&] {
    emoticon_label.text(as<emoticon>(emoticons_list_box.selected_item().tag()).to_string());
  };
  emoticons_list_box.selected_index(0);
  
  application::run(main_form);
}
