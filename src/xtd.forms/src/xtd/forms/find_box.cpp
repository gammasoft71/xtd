#include "../../../include/xtd/forms/find_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

std::unique_ptr<find_dialog> find_box::dialog_;

void find_box::show_find_box(const iwin32_window& owner, find_event_handler find_next, const ustring& find_string, const ustring& title, bool match_case, search_direction search_direction, bool whole_word) {
  if (dialog_) return;
  dialog_ = make_unique<find_dialog>();
  dialog_->title(title).find_string(find_string).match_case(match_case).search_direction(search_direction).whole_word(whole_word);
  dialog_->show(owner);
  dialog_->find_next += find_next;
  dialog_->dialog_closed += [] {
    dialog_.reset();
  };
}
