#include "../../../include/xtd/globalization/culture_info.hpp"
#include "../../../include/xtd/collections/generic/list.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/culture_info>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::globalization;
using namespace xtd::helpers;

optional<culture_info> culture_info::current_culture_;

culture_info::culture_info() {
}

culture_info::culture_info(const std::locale& locale) {
  fill_from_name(to_cldr_name(locale.name()));
}

culture_info::culture_info(size culture) {
  for (const auto& c : cultures_) {
    //if (string::equals(culture.data_->name, name, string_comparison::ordinal_ignore_case))
    if (c.data_->lcid != culture) continue;
    self_ = c;
    return;
  }
  throw_helper::throws(exception_case::culture_not_found);
}

culture_info::culture_info(const string& name) {
  fill_from_name(name);
}

globalization::culture_types culture_info::culture_types() const noexcept {
  return data_->culture_types;
}

const string& culture_info::display_name() const noexcept {
  return data_->display_name;
}

const string& culture_info::english_name() const noexcept {
  return data_->english_name;
}

bool culture_info::is_locale_available() const noexcept {
  return data_->locale.name() != "C";
}

xtd::size culture_info::keyboard_layout_id() const noexcept {
  return data_->keyboard_layout_id;
}

xtd::size culture_info::lcid() const noexcept {
  return data_->lcid;
}

const std::locale& culture_info::locale() const noexcept {
  return data_->locale;
}

const string& culture_info::name() const noexcept {
  return data_->name;
}

const string& culture_info::native_name() const noexcept {
  return data_->native_name;
}

culture_info culture_info::current_culture() noexcept {
  auto local_name = !current_culture_.has_value() ? xtd::native::culture_info::current_name() : std::locale {}.name();
  if (local_name == "C" || local_name == "POSIX") local_name = "en_US.utf-8";
  if (!current_culture_.has_value()) current_culture_ = culture_info{};
  current_culture_.value().fill_from_name(to_cldr_name(local_name));
  return current_culture_.value();
}

void culture_info::current_culture(const culture_info& value) {
  if (current_culture_.has_value() && current_culture_ == value) return;
  current_culture_ = value;
  std::locale::global(std::locale {to_locale_name(current_culture_.value().name())});
}

culture_info culture_info::invariant_culture() noexcept {
  return cultures_[0];
}

bool culture_info::equals(const object& obj) const noexcept {
  return is<culture_info>(obj) && equals(static_cast<const culture_info&>(obj));
}

bool culture_info::equals(const culture_info& obj) const noexcept {
  return data_->name == obj.data_->name;;
}

xtd::string culture_info::to_string() const noexcept {
  return data_->name;
}

array<culture_info> culture_info::get_cultures(xtd::globalization::culture_types types) noexcept {
  auto result = list<culture_info> {};
  for (const auto& culture : cultures_)
    if ((culture.culture_types() & types) == types || types == xtd::globalization::culture_types::all_cultures)
      result.add(culture);
  return result;
}

culture_info& culture_info::operator =(std::locale&& locale) {
  data_->locale = std::move(locale);
  return self_;
}
culture_info& culture_info::operator =(const std::locale& locale) {
  data_->locale = locale;
  return self_;
}

culture_info::operator const std::locale& () const noexcept {
  return data_->locale;
}

culture_info::culture_info(globalization::culture_types culture_types, string&& display_name, string&& english_name, size keyboard_layout_id, size lcid, string&& name, string&& native_name) {
  data_->culture_types = culture_types;
  data_->display_name = std::move(display_name);
  data_->english_name = std::move(english_name);
  data_->keyboard_layout_id = keyboard_layout_id;
  data_->lcid = lcid;
  try {
    data_->locale = std::locale {to_locale_name(name)};
  } catch (...) {
    data_->locale = std::locale {"C"};
  }
  data_->name = std::move(name);
  data_->native_name = std::move(native_name);
}

void culture_info::fill_from_name(const string& name) {
  for (const auto& culture : cultures_) {
    //if (string::equals(culture.data_->name, name, string_comparison::ordinal_ignore_case))
    if (culture.data_->name.to_lower() != name.to_lower()) continue;
    self_ = culture;
    return;
  }
  throw_helper::throws(exception_case::culture_not_found);
}

string culture_info::to_cldr_name(const string& name) {
  return name.to_lower().replace(".utf-8", "").replace("_", "-");
}

string culture_info::to_locale_name(const string& name) {
  auto locale_name = name.replace("-", "_");
  if (locale_name.to_lower().ends_with(".utf-8")) locale_name += ".utf-8";
  return locale_name;
}
