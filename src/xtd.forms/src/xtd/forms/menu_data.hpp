#include "../../../include/xtd/forms/menu.hpp"

struct xtd::forms::menu::data {
  intptr handle = 0;
  std::optional<std::reference_wrapper<menu>> context_menu;
  menu_item_collection menu_items;
  xtd::sptr<menu_item> mdi_list_item;
  std::optional<std::reference_wrapper<menu>> main_menu;
  xtd::string name;
  std::optional<std::reference_wrapper<menu>> parent;
  std::any tag;
};
