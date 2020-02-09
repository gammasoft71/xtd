#define _(text) text
#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

int main() {
  auto main_form = control::create<form>("Test Gui");
  main_form->auto_size(true);
  
  auto emoticons_list_box = control::create<list_box>(*main_form, "", {10, 10}, {150, 250});
  for (const auto& emoticon : emoticons::get_emoticons())
    emoticons_list_box->items().push_back({strings::format("{} {}", emoticon, emoticon.name()), emoticon});

  auto emoticon_label = control::create<label>(*main_form, "", {160, 30});
  emoticon_label->auto_size(true).font({main_form->font(), 128});
  emoticon_label->text(emoticon("test", {0x21AA}).to_string());

  emoticons_list_box->selected_value_changed += [&] {
    emoticon_label->text(any_cast<emoticon>(emoticons_list_box->selected_item().tag()).to_string());
  };
  
  application::run(*main_form);
}
