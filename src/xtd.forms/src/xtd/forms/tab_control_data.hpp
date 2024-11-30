#include "../../../include/xtd/forms/tab_control.hpp"
#include "../../../include/xtd/forms/tab_page.hpp"

struct xtd::forms::tab_control::data {
  tab_alignment alignment = tab_alignment::top;
  forms::image_list image_list;
  size_t selected_index = npos;
  tab_page_collection tab_pages;
  std::vector<xtd::uptr<tab_page>> text_tab_pages;
};
