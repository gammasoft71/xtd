#include "../../../include/xtd/forms/replace_box.hpp"

using namespace xtd;
using namespace xtd::forms;

xtd::uptr<xtd::forms::replace_dialog> replace_box::dialog_;

void replace_box::show_replace_box(const iwin32_window& owner, xtd::forms::find_event_handler find_next, xtd::forms::replace_event_handler replace, xtd::forms::replace_event_handler replace_all, const xtd::string& find_string, const xtd::string& replace_string, const xtd::string& title, bool match_case, bool whole_word) {
  if (dialog_) return;
  dialog_ = xtd::new_uptr<xtd::forms::replace_dialog>();
  dialog_->title(title).find_string(find_string).replace_string(replace_string).match_case(match_case).whole_word(whole_word);
  dialog_->show(owner);
  dialog_->find_next += find_next;
  dialog_->replace += replace;
  dialog_->replace_all += replace_all;
  dialog_->dialog_closed += [] {
    dialog_.reset();
  };
}
