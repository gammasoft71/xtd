#include "../../../include/xtd/globalization/culture_info.hpp"
#include "../../../include/xtd/collections/generic/dictionary.hpp"
#include "../../../include/xtd/collections/generic/list.hpp"
#include "../../../include/xtd/call_once.hpp"
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
  for (const auto& [n, c] : cultures_) {
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
  auto locale = !current_culture_.has_value() ? std::locale {xtd::native::culture_info::current_locale_name()} : std::locale {};
  if (!current_culture_.has_value()) current_culture_ = culture_info {locale};
  else if (locale.name() != "C") current_culture_ = culture_info {locale};
  return current_culture_.value();
}

void culture_info::current_culture(const culture_info& value) {
  if (current_culture_.has_value() && current_culture_ == value) return;
  current_culture_ = value;
  std::locale::global(value.locale());
}

culture_info culture_info::invariant_culture() noexcept {
  return cultures_[""];
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
  for (const auto& [name, culture] : cultures_)
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
  data_->locale = std::locale {is_system_locale_available(to_locale_name(name)) ? to_locale_name(name) : "C"};
  data_->name = std::move(name);
  data_->native_name = std::move(native_name);
}

void culture_info::fill_from_name(const string& name) {
  auto lower_name = name.to_lower();
  if (!cultures_.contains_key(lower_name)) throw_helper::throws(exception_case::culture_not_found);
  self_ = cultures_[lower_name];
}

bool culture_info::is_system_locale_available(const string& name) noexcept {
  static auto system_locale_names = array<string> {};
  call_once_ {
    auto native_system_locale_names = native::culture_info::system_locale_names();
    system_locale_names = array<string>(native_system_locale_names.begin(), native_system_locale_names.end());
  };
  return system_locale_names.contains(name);
}

string culture_info::to_cldr_name(const string& name) {
  if (string::is_empty(name)) return "";
  if (name == "C" || name == "POSIX") return "en-US";
  static const dictionary<string, string> locale_to_cldr_fixups = {{"ar_ar", "ar"}, {"az_az", "az-Latn-AZ"}, {"bs_ba", "bs-Latn-BA"}, {"en_en", "en"}, {"eo_eo", "eo"}, {"ff_bf", "ff-Latn-BF"}, {"ff_cm", "ff-Latn-CM"}, {"ff_gh", "ff-Latn-GH"}, {"ff_gm", "ff-Latn-GM"}, {"ff_gn", "ff-Latn-GN"}, {"ff_gw", "ff-Latn-GW"}, {"ff_lr", "ff-Latn-LR"}, {"ff_mr", "ff-Latn-MR"}, {"ff_ne", "ff-Latn-NE"}, {"ff_ng", "ff-Latn-NG"}, {"ff_sl", "ff-Latn-SL"}, {"ff_sn", "ff-Latn-SN"}, {"ia_ia", "ia"}, {"id_id", "id"}, {"kok_in", "kok-Deva-IN"}, {"ks_in", "ks-Arab-IN"}, {"mni_in", "mni-Beng-IN"}, {"pa_pk", "pa-Arab-PK"}, {"pa_in", "pa-Guru-IN"}, {"sat_in", "sat-Deva-IN"}, {"sd_pk", "sd-Arab-PK"}, {"sd_in", "sd-Deva-IN"}, {"shi_ma", "shi-Latn-MA"}, {"sr_xk", "sr-Latn-XK"}, {"sr_rs", "sr-Cyrl-RS"}, {"sr_me", "sr-Latn-ME"}, {"sr_ba", "sr-Latn-BA"}, {"su_id", "su-Latn-ID"}, {"ur_in", "ur-Arab-IN"}, {"ur_pk", "ur-Arab-PK"}, {"uz_uz", "uz-Latn-UZ"}, {"uz_af", "uz-Arab-AF"}, {"vai_lr", "vai-Latn-LR"}, {"zh_cn", "zh-Hans-CN"}, {"zh_sg", "zh-Hans-SG"}, {"zh_hk", "zh-Hant-HK"}, {"zh_tw", "zh-Hant-TW"}, {"zh_mo", "zh-Hant-MO"}};
  auto cldr_name = name.replace(".UTF-8", "");
  return locale_to_cldr_fixups.contains_key(cldr_name.to_lower()) ? locale_to_cldr_fixups[cldr_name.to_lower()] : cldr_name.replace("_", "-");
}

string culture_info::to_locale_name(const string& name) {
  if (string::is_empty(name) || name == "C" || name == "POSIX") return name;
  static const auto cldr_to_locale_fixups = dictionary<string, string> {{"ar", "ar_AR.UTF-8"}, {"en", "en_EN.UTF-8"}, {"eo", "eo_EN.UTF-8"}, {"ia", "ia_IA.UTF-8"}, {"id", "ia_ID.UTF-8"}};
  if (cldr_to_locale_fixups.contains_key(name.to_lower())) return cldr_to_locale_fixups[name.to_lower()];
  static const array<string> unsupported_scripts = {"-Adlm", "-Arab", "-Aran", "-Beng", "-Bopo", "-Cyrl", "-Deva", "-Ethi", "-Grek", "-Guru", "-Hans", "-Hant", "-Hebr", "-Latn", "-Kana", "-Mtei", "-Olck", "-Orya", "-Rohg", "-Telu", "-Tfng", "-Thai", "-Vaii", "-POSIX"};
  auto locale_name = name;
  for (const auto& unsupported_script : unsupported_scripts) {
    if (!locale_name.contains(unsupported_script)) continue;
    locale_name = locale_name.replace(unsupported_script, "");
    break;
  }
  locale_name = locale_name.replace("-", "_");
  auto index = locale_name.last_index_of("_");
  if (index != npos && char_object::is_digit(locale_name, index + 1)) {
    locale_name = locale_name.remove(index);
    locale_name += "_" + locale_name.to_upper();
  }
  if (!string::is_empty(locale_name)) locale_name += ".UTF-8";
  return locale_name;
}
