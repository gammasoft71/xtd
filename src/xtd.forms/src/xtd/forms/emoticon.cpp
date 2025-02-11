#include "../../../include/xtd/forms/emoticon.hpp"

using namespace xtd;
using namespace xtd::forms;

struct emoticon::data {
  xtd::string name;
  std::vector<char32> codepoints;
};

const emoticon emoticon::empty() {
  return emoticon();
}

emoticon::emoticon() : data_(xtd::new_sptr<data>()) {
}

emoticon::emoticon(const xtd::string& name, std::initializer_list<char32> codepoints) : data_(xtd::new_sptr<data>()) {
  data_->name = name;
  data_->codepoints = codepoints;
}

emoticon::emoticon(const xtd::string& name, const std::vector<char32>& codepoints) : data_(xtd::new_sptr<data>()) {
  data_->name = name;
  data_->codepoints = codepoints;
}

emoticon::emoticon(const xtd::string& name, char32 codepoint) : data_(xtd::new_sptr<data>()) {
  data_->name = name;
  data_->codepoints = {codepoint};
}

emoticon::emoticon(std::initializer_list<char32> codepoints) : data_(xtd::new_sptr<data>()) {
  data_->codepoints = codepoints;
}

emoticon::emoticon(const std::vector<char32>& codepoints) : data_(xtd::new_sptr<data>()) {
  data_->codepoints = codepoints;
}

emoticon::emoticon(char32 codepoint) : data_(xtd::new_sptr<data>()) {
  data_->codepoints = {codepoint};
}

emoticon::emoticon(const emoticon& other) : data_(xtd::new_sptr<data>()) {
  *data_ = *other.data_;
}

emoticon& emoticon::operator =(const emoticon& other) {
  *data_ = *other.data_;
  return *this;
}

const xtd::string& emoticon::name() const noexcept {
  return data_->name;
}

const std::vector<char32>& emoticon::codepoints() const noexcept {
  return data_->codepoints;
}

bool emoticon::equals(const object& obj) const noexcept {
  return is<emoticon>(obj) && equals(static_cast<const emoticon&>(obj));
}

bool emoticon::equals(const emoticon& other) const noexcept {
  return data_->name == other.data_->name && data_->codepoints == other.data_->codepoints;
}

xtd::size emoticon::get_hash_code() const noexcept {
  auto result = hash_code {};
  result.add(data_->name);
  for (const auto& codepoint : data_->codepoints)
    result.add(codepoint);
  return result.to_hash_code();
}

xtd::string emoticon::to_string() const noexcept {
  /// @todo Replace string with string_builder when implemented.
  auto result = std::string {};
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
  data_ = xtd::new_sptr<data>();
}

void emoticon::name_(const string& name) {
  data_->name = name;
}

std::vector<char32>& emoticon::codepoints_() {
  return data_->codepoints;
}

void emoticon::codepoints_(std::vector<char32>&& codepoints) {
  data_->codepoints = std::move(codepoints);
}
