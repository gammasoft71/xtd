#include "../../../include/xtd/forms/tab_control.hpp"
#include "../../../include/xtd/forms/tab_page.hpp"

struct xtd::forms::tab_control::data {
  data(tab_control& control) : control {control} {}
  tab_control& control;
  tab_alignment alignment = tab_alignment::top;
  forms::image_list image_list;
  xtd::usize selected_index = npos;
  tab_page_collection tab_pages;
  xtd::collections::generic::list<xtd::sptr<tab_page>> text_tab_pages;
  
  auto on_tab_pages_item_added(xtd::usize index, tab_page_ref& item) -> void {
    control.controls().insert(index, item.get());
  }
  
  auto on_tab_pages_item_removed(xtd::usize index, tab_page_ref& item) -> void {
    control.controls().remove_at(index);
  }

  auto on_tab_pages_text_added(xtd::usize index, const string& text, const string& name) -> void {
    auto item = xtd::new_sptr<tab_page>();
    item->text(text);
    item->name(name);
    if (index == control.tab_pages().npos) {
      control.tab_pages().add(*item);
      text_tab_pages.add(item);
    } else {
      control.tab_pages().insert(index, *item);
      text_tab_pages.insert(index, item);
    }
  }

  auto on_tab_pages_text_inserted(xtd::usize pos, const string& text, const string& name) -> void {
    auto item = xtd::new_sptr<tab_page>();
    item->text(text);
    item->name(name);
    control.tab_pages().insert(pos, *item);
    if (pos == control.tab_pages().npos) text_tab_pages.add(item);
    else text_tab_pages.insert(pos, item);
  }
};
