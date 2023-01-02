#include "../../../include/xtd/forms/menu.h"

struct xtd::forms::menu::data {
  intptr handle = 0;
  std::optional<std::reference_wrapper<menu>> context_menu;
  menu_item_collection menu_items;
  std::shared_ptr<menu_item> mdi_list_item;
  std::optional<std::reference_wrapper<menu>> main_menu;
  xtd::ustring name;
  std::optional<std::reference_wrapper<menu>> parent;
  std::any tag;
};
