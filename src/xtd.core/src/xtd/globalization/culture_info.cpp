#include "../../../include/xtd/globalization/culture_info.hpp"
#include "../../../include/xtd/helpers/throw_helper"
#include "../../../include/xtd/io/binary_reader.hpp"
#include "../../../include/xtd/collections/generic/dictionary.hpp"
#include "../../../include/xtd/collections/generic/list.hpp"
#include "../../../include/xtd/call_once.hpp"
#include "../../../include/xtd/environment.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/culture_info>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::globalization;
using namespace xtd::helpers;
using namespace xtd::io;

optional<culture_info> culture_info::current_culture_;

struct culture_info::data {
  xtd::globalization::culture_types culture_types = xtd::globalization::culture_types::specific_cultures;
  optional<date_time_format_info> date_time_format;
  xtd::string display_name = "Invariant Language (Invariant Country)";
  xtd::string english_name = "Invariant Language (Invariant Country)";
  bool is_read_only = false;
  xtd::size keyboard_layout_id = 127;
  xtd::size lcid = 127;
  std::locale locale = std::locale {""};
  xtd::string name;
  xtd::string native_name = "Invariant Language (Invariant Country)";
  optional<number_format_info> number_format;
  xtd::string parent_name;
  xtd::string three_letter_iso_language_name = "ivl";
  xtd::string three_letter_windows_language_name = "IVL";
  xtd::string two_letter_iso_language_name = "iv";
  bool use_user_override = false;
};

culture_info::culture_info() : data_ {new_ptr<data>()} {
}

culture_info::culture_info(const std::locale& locale) : culture_info() {
  fill_from_name(to_cldr_name(locale.name()));
}

culture_info::culture_info(size culture) : culture_info {culture, false} {
}

culture_info::culture_info(size culture, bool use_user_override) : culture_info() {
  for (const auto& [n, c] : cultures()) {
    //if (string::equals(culture.data_->name, name, string_comparison::ordinal_ignore_case))
    if (c.data_->lcid != culture) continue;
    *data_ = *c.data_;
    data_->use_user_override = use_user_override;
    return;
  }
  throw_helper::throws(exception_case::culture_not_found);
}

culture_info::culture_info(const string& name) : culture_info {name, false} {
}

culture_info::culture_info(const string& name, bool use_user_override) : culture_info() {
  fill_from_name(name);
  data_->use_user_override = use_user_override;
}

globalization::culture_types culture_info::culture_types() const noexcept {
  return data_->culture_types;
}

const date_time_format_info& culture_info::date_time_format() const {
  if (data_->date_time_format == nullopt) data_->date_time_format = date_time_format_info::formats()[data_->name.to_lower()];
  return data_->date_time_format.value();
}

date_time_format_info& culture_info::date_time_format() {
  if (data_->date_time_format == nullopt) data_->date_time_format = date_time_format_info::formats()[data_->name.to_lower()];
  return data_->date_time_format.value();
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

bool culture_info::is_neutral_culture() const noexcept {
  return enum_object<globalization::culture_types>(culture_types()).has_flag(xtd::globalization::culture_types::neutral_cultures);
}

bool culture_info::is_read_only() const noexcept {
  return data_->is_read_only;
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

const xtd::globalization::number_format_info& culture_info::number_format() const {
  if (data_->number_format == nullopt) data_->number_format = number_format_info::formats()[data_->name.to_lower()];
  return data_->number_format.value();
}

xtd::globalization::number_format_info& culture_info::number_format() {
  if (data_->number_format == nullopt) data_->number_format = number_format_info::formats()[data_->name.to_lower()];
  return data_->number_format.value();
}

culture_info culture_info::parent() const noexcept {
  return culture_info {data_->parent_name};
}

const string& culture_info::three_letter_iso_language_name() const noexcept {
  return data_->three_letter_iso_language_name;
}

const string& culture_info::three_letter_windows_language_name() const noexcept {
  return data_->three_letter_windows_language_name;
}

const string& culture_info::two_letter_iso_language_name() const noexcept {
  return data_->two_letter_iso_language_name;
}

bool culture_info::use_user_override() const noexcept {
  return data_->use_user_override;
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
  return cultures()[""];
}

culture_info culture_info::clone() const noexcept {
  auto result = culture_info {};
  *result.data_ = *data_;
  return result;
}

bool culture_info::equals(const object& obj) const noexcept {
  return is<culture_info>(obj) && equals(static_cast<const culture_info&>(obj));
}

bool culture_info::equals(const culture_info& obj) const noexcept {
  return data_->name == obj.data_->name;;
}

xtd::size culture_info::get_hash_code() const noexcept {
  return xtd::hash_code::combine(data_->name);
}

xtd::string culture_info::to_string() const noexcept {
  return data_->name;
}

culture_info culture_info::get_culture_info(const xtd::string& name) {
  auto culture = culture_info {name};
  culture.data_->is_read_only = true;
  return culture;
}

culture_info culture_info::get_culture_info(const xtd::string& name, bool predefined_only) {
  if (predefined_only || cultures().contains_key(name)) return culture_info(name);
  auto culture = culture_info {""};
  culture.data_->name = name;
  culture.data_->is_read_only = true;
  return culture;
}

culture_info culture_info::get_culture_info(const xtd::string& name, const xtd::string& alt_name) {
  auto alt_culture = culture_info {alt_name};
  auto culture = culture_info {name};
  culture.data_->is_read_only = true;
  //*culture.data_->compare_info = *alt_culture.data_->compare_info;
  //*culture.data_->text_info = *alt_culture.data_->text_info;
  return culture;
}

culture_info culture_info::get_culture_info(xtd::size culture) {
  return culture_info {culture};
}

array<culture_info> culture_info::get_cultures(xtd::globalization::culture_types types) {
  auto result = list<culture_info> {};
  for (const auto& [name, culture] : cultures())
    if (enum_object<globalization::culture_types>(culture.culture_types()).has_flag(types) || types == xtd::globalization::culture_types::all_cultures)
      result.add(culture.clone());
  result.sort({[](auto v1, auto v2) {return v1.name() < v2.name() ? -1 : v1.name() > v2.name() ? 1 : 0;}});
  return result;
}

array<std::locale> culture_info::get_system_locales() noexcept {
  static auto result = list<std::locale> {};
  call_once_ {
    for (auto system_locale_name : native::culture_info::system_locale_names())
      result.add(std::locale {system_locale_name});
    result.sort({[](auto v1, auto v2) {return v1.name() < v2.name() ? -1 : v1.name() > v2.name() ? 1 : 0;}});
  };
  return result;
}

void culture_info::initialize_all_cultures() noexcept {
  [[maybe_unused]] auto ci = culture_info {"en-US"};
  [[maybe_unused]] auto dtf = ci.date_time_format();
  [[maybe_unused]] auto nf = ci.number_format();
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

culture_info::culture_info(globalization::culture_types culture_types, string&& display_name, string&& english_name, size keyboard_layout_id, size lcid, string&& name, string&& native_name, string&& parent_name, string&& three_letter_iso_language_name, string&& three_letter_windows_language_name, string&& two_letter_iso_language_name) : culture_info() {
  data_->culture_types = culture_types;
  data_->display_name = std::move(display_name);
  data_->english_name = std::move(english_name);
  data_->keyboard_layout_id = keyboard_layout_id;
  data_->lcid = lcid;
  data_->locale = std::locale {is_system_locale_available(to_locale_name(name)) ? to_locale_name(name) : "C"};
  data_->name = std::move(name);
  data_->native_name = std::move(native_name);
  data_->parent_name = std::move(parent_name);
  data_->three_letter_iso_language_name = std::move(three_letter_iso_language_name);
  data_->three_letter_windows_language_name = std::move(three_letter_windows_language_name);
  data_->two_letter_iso_language_name = std::move(two_letter_iso_language_name);
  data_->is_read_only = true;
}

void culture_info::fill_from_name(const string& name) {
  auto lower_name = name.to_lower();
  if (!cultures().contains_key(lower_name)) throw_helper::throws(exception_case::culture_not_found);
  *data_ = *cultures()[lower_name].data_;
  data_->is_read_only = false;
}

dictionary<string, culture_info>& culture_info::cultures() {
  static auto cultures = dictionary<string, culture_info> {{"", {}}, {"en-us", {globalization::culture_types::specific_cultures, "English (United States)", "English (United States)", 1033, 1033, "en-US", "English (United States)", "en", "eng", "ENU", "en"}}};
  call_once_ {
    auto culture_bin = path::combine({environment::get_folder_path(environment::special_folder::xtd_install), "share", "xtd", "data", "cultures.bin"});
    if (!file::exists(culture_bin)) return;
    auto br = binary_reader {culture_bin};
    if (br.read_bytes(8) != array<byte> {'X', 'T', 'D', 0, 'C', 'U', 'L', 'T'}) throw_helper::throws(exception_case::format, "The file does not contain the signature 'XTD/0_CULT'.");
    if (br.read_int32() > 1) throw_helper::throws(exception_case::format, "The file version is not supported");
    auto count = br.read_int32();
    for (auto i = 0; i < count; ++i) {
      auto key = br.read_string();
      cultures[key] = culture_info {as<xtd::globalization::culture_types>(br.read_int32()), br.read_string(), br.read_string(), as<size>(br.read_int32()), as<size>(br.read_int32()), br.read_string(), br.read_string(), br.read_string(), br.read_string(), br.read_string(), br.read_string()};
    }
  };
  return cultures;
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
  if (name == "C" || name == "C.UTF-8" || name == "POSIX" || name == "POSIX.UTF-8") return "en-US";
  static const dictionary<string, string> locale_to_cldr_fixups = {{"ar_ar", "ar"}, {"az_az", "az-Latn-AZ"}, {"bs_ba", "bs-Latn-BA"}, {"en_en", "en"}, {"eo_eo", "eo"}, {"ff_bf", "ff-Latn-BF"}, {"ff_cm", "ff-Latn-CM"}, {"ff_gh", "ff-Latn-GH"}, {"ff_gm", "ff-Latn-GM"}, {"ff_gn", "ff-Latn-GN"}, {"ff_gw", "ff-Latn-GW"}, {"ff_lr", "ff-Latn-LR"}, {"ff_mr", "ff-Latn-MR"}, {"ff_ne", "ff-Latn-NE"}, {"ff_ng", "ff-Latn-NG"}, {"ff_sl", "ff-Latn-SL"}, {"ff_sn", "ff-Latn-SN"}, {"ia_ia", "ia"}, {"id_id", "id"}, {"kok_in", "kok-Deva-IN"}, {"ks_in", "ks-Arab-IN"}, {"mni_in", "mni-Beng-IN"}, {"pa_pk", "pa-Arab-PK"}, {"pa_in", "pa-Guru-IN"}, {"sat_in", "sat-Deva-IN"}, {"sd_pk", "sd-Arab-PK"}, {"sd_in", "sd-Deva-IN"}, {"shi_ma", "shi-Latn-MA"}, {"sr_xk", "sr-Latn-XK"}, {"sr_rs", "sr-Cyrl-RS"}, {"sr_me", "sr-Latn-ME"}, {"sr_ba", "sr-Latn-BA"}, {"su_id", "su-Latn-ID"}, {"ur_in", "ur-Arab-IN"}, {"ur_pk", "ur-Arab-PK"}, {"uz_uz", "uz-Latn-UZ"}, {"uz_af", "uz-Arab-AF"}, {"vai_lr", "vai-Latn-LR"}, {"zh_cn", "zh-Hans-CN"}, {"zh_sg", "zh-Hans-SG"}, {"zh_hk", "zh-Hant-HK"}, {"zh_tw", "zh-Hant-TW"}, {"zh_mo", "zh-Hant-MO"}};
  auto cldr_name = name.replace(".UTF-8", "");
  return locale_to_cldr_fixups.contains_key(cldr_name.to_lower()) ? locale_to_cldr_fixups[cldr_name.to_lower()] : cldr_name.replace("_", "-");
}

string culture_info::to_locale_name(const string& name) {
  if (string::is_empty(name) || name == "C" || name == "POSIX") return name;
  if (name == "C.UTF-8") return "C";
  if (name == "POSIX.UTF-8") return "POSIX";
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
