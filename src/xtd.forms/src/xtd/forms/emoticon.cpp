#include "../../../include/xtd/forms/emoticon.h"

using namespace xtd::forms;

const emoticon emoticon::empty() {
  return emoticon();
}

emoticon::emoticon(const xtd::ustring& name, std::initializer_list<char32_t> codepoints) {
  data_->name = name;
  data_->codepoints = codepoints;
}

emoticon::emoticon(const xtd::ustring& name, const std::vector<char32_t>& codepoints) {
  data_->name = name;
  data_->codepoints = codepoints;
}

emoticon::emoticon(const xtd::ustring& name, char32_t codepoint) {
  data_->name = name;
  data_->codepoints = {codepoint};
}

emoticon::emoticon(std::initializer_list<char32_t> codepoints) {
  data_->codepoints = codepoints;
}

emoticon::emoticon(const std::vector<char32_t>& codepoints) {
  data_->codepoints = codepoints;
}

emoticon::emoticon(char32_t codepoint) {
  data_->codepoints = {codepoint};
}

bool emoticon::operator ==(const emoticon& value) const noexcept {
  return data_->name == value.data_->name && data_->codepoints == value.data_->codepoints;
}

bool emoticon::operator !=(const emoticon& value) const noexcept {
  return !operator ==(value);
}

const xtd::ustring& emoticon::name() const noexcept {
  return data_->name;
}

const std::vector<char32_t>& emoticon::codepoints() const noexcept {
  return data_->codepoints;
}

xtd::ustring emoticon::to_string() const noexcept {
  std::string result;
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
