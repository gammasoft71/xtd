#include "../../../include/xtd/forms/tab_control"
#include "../../../include/xtd/forms/tab_page"

struct xtd::forms::tab_control::data {
  tab_alignment alignment = tab_alignment::top;
  forms::image_list image_list;
  size_t selected_index = npos;
  tab_page_collection tab_pages;
  std::vector<std::unique_ptr<tab_page>> text_tab_pages;
};
