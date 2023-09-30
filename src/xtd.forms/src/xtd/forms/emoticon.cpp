#include "../../../include/xtd/forms/emoticon.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

struct emoticon::data {
  xtd::ustring name;
  vector<char32> codepoints;
};

const emoticon emoticon::empty() {
  return emoticon();
}

emoticon::emoticon() : data_(make_shared<data>()) {
}

emoticon::emoticon(const xtd::ustring& name, initializer_list<char32> codepoints) : data_(make_shared<data>()) {
  data_->name = name;
  data_->codepoints = codepoints;
}

emoticon::emoticon(const xtd::ustring& name, const vector<char32>& codepoints) : data_(make_shared<data>()) {
  data_->name = name;
  data_->codepoints = codepoints;
}

emoticon::emoticon(const xtd::ustring& name, char32 codepoint) : data_(make_shared<data>()) {
  data_->name = name;
  data_->codepoints = {codepoint};
}

emoticon::emoticon(initializer_list<char32> codepoints) : data_(make_shared<data>()) {
  data_->codepoints = codepoints;
}

emoticon::emoticon(const vector<char32>& codepoints) : data_(make_shared<data>()) {
  data_->codepoints = codepoints;
}

emoticon::emoticon(char32 codepoint) : data_(make_shared<data>()) {
  data_->codepoints = {codepoint};
}

emoticon::emoticon(const emoticon& other) : data_(make_shared<data>()) {
  *data_ = *other.data_;
}

emoticon& emoticon::operator =(const emoticon& other) {
  *data_ = *other.data_;
  return *this;
}

const xtd::ustring& emoticon::name() const noexcept {
  return data_->name;
}

const vector<char32>& emoticon::codepoints() const noexcept {
  return data_->codepoints;
}

bool emoticon::equals(const emoticon& value) const noexcept {
  return data_->name == value.data_->name && data_->codepoints == value.data_->codepoints;
}

xtd::ustring emoticon::to_string() const noexcept {
  /// @todo Replace string with string_builder when implemented.
  auto result = string {};
  for (auto codepoint : data_->codepoints) {
    if (codepoint < 0x80)
      result.push_back(static_cast<char>(codepoint));
    else  if (codepoint < 0x800) {
      result.push_back(static_cast<char>((codepoint >> 6) | 0xc0));
      result.push_back(static_cast<char>((codepoint & 0x3f) | 0x80));
    } else if (codepoint < 0x10000) {
      result.push_back(static_cast<char>((codepoint >> 12) | 0xe0));
      result.push_back(static_cast<char>(((codepoint >> 6) & 0x3f) | 0x80));
      result.push_back(static_cast<char>((codepoint & 0x3f) | 0x80));
    } else {
      result.push_back(static_cast<char>((codepoint >> 18) | 0xf0));
      result.push_back(static_cast<char>(((codepoint >> 12) & 0x3f) | 0x80));
      result.push_back(static_cast<char>(((codepoint >> 6) & 0x3f) | 0x80));
      result.push_back(static_cast<char>((codepoint & 0x3f) | 0x80));
    }
  }
  return result;
}

void emoticon::create_data() {
  data_ = make_shared<data>();
}

void emoticon::name_(const ustring& name) {
  data_->name = name;
}

vector<char32>& emoticon::codepoints_() {
  return data_->codepoints;
}

void emoticon::codepoints_(vector<char32>&& codepoints) {
  data_->codepoints = std::move(codepoints);
}
