#include "../../../include/xtd/forms/find_box.hpp"

using namespace xtd;
using namespace xtd::forms;

xtd::uptr<find_dialog> find_box::dialog_;

void find_box::show_find_box(const iwin32_window& owner, find_event_handler find_next, const string& find_string, const string& title, bool match_case, search_direction search_direction, bool whole_word) {
  if (dialog_) return;
  dialog_ = xtd::new_uptr<find_dialog>();
  dialog_->title(title).find_string(find_string).match_case(match_case).search_direction(search_direction).whole_word(whole_word);
  dialog_->show(owner);
  dialog_->find_next += find_next;
  dialog_->dialog_closed += [] {
    dialog_.reset();
  };
}
