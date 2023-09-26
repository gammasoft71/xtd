#include "../../../include/xtd/forms/find_event_args"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

struct find_event_args::data {
  ustring find_string;
  bool match_case = false;
  forms::search_direction search_direction = forms::search_direction::down;
  bool whole_word = false;
};

find_event_args::find_event_args() : data_(make_shared<data>()) {
}

find_event_args::find_event_args(const xtd::ustring& find_string, bool match_case, xtd::forms::search_direction search_direction, bool whole_word) : data_(make_shared<data>()) {
  data_->find_string = find_string;
  data_->match_case = match_case;
  data_->search_direction = search_direction;
  data_->whole_word = whole_word;
}

find_event_args::find_event_args(const find_event_args& other) : data_(make_shared<data>()) {
  *data_ = *other.data_;
}

find_event_args& find_event_args::operator =(const find_event_args& other) {
  *data_ = *other.data_;
  return *this;
}

const xtd::ustring& find_event_args::find_string() const noexcept {
  return data_->find_string;
}

bool find_event_args::match_case() const noexcept {
  return data_->match_case;
}

xtd::forms::search_direction find_event_args::search_direction() const noexcept {
  return data_->search_direction;
}

bool find_event_args::whole_word() const noexcept {
  return data_->whole_word;
}
