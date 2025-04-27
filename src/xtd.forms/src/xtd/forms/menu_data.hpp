#include "../../../include/xtd/forms/menu.hpp"

struct xtd::forms::menu::data {
  intptr handle = 0;
  std::optional<xtd::ref<menu>> context_menu;
  menu_item_collection menu_items;
  xtd::sptr<menu_item> mdi_list_item;
  std::optional<xtd::ref<menu>> main_menu;
  xtd::string name;
  std::optional<xtd::ref<menu>> parent;
  xtd::any_object tag;
};
